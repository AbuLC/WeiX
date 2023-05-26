#include"WeiBusinessBuLC.h"

void WeiBusinessBuLC::loginSucceed()
{
	system("cls");
	cout << "»¶Ó­µÇÂ¼Î¢ÉÌ£¡" << this->accountnum << endl;
	WeiBusiness_now = this->accountnum;
	type_now = 4;
	//µÇÂ¼ÆäËûÆ½Ì¨
	cout << "ÊÇ·ñÍ¬Ê±µÇÂ¼ÆäËûÆ½Ì¨£¿" << endl;
	int n;
	cout << "1¡¢ÊÇ  2¡¢·ñ" << endl;
	cin >> n;
	if (n == 1) {
		if (personcontainer[checkPerson(this->customerId)].showQQid() == 0) {
			cout << "QQÎ´×¢²á" << endl;
		}
		else {
			cout << "QQÒÑµÇÂ¼" << endl;
			QQ_now = weixcontainer[checkAccountNUm(1, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBlogid() == 0) {
			cout << "Î¢²©Î´×¢²á" << endl;
		}
		else {
			cout << "Î¢²©ÒÑµÇÂ¼" << endl;
			WeiBlog_now =weixcontainer[ checkAccountNUm(3, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "Î¢ÐÅÎ´×¢²á" << endl;
		}
		else {
			cout << "Î¢ÐÅÒÑµÇÂ¼" << endl;
			WeChat_now = weixcontainer[checkAccountNUm(2, this->customerId)]->showaccountnum();
		}
	}
	system("pause");
	weiXMeun();

}
void WeiBusinessBuLC::weiXMeun()
{
Start:

	system("cls");
	cout << "¡ª¡ª¡ª¡ª1¡¢²é¿´¸öÈËÐÅÏ¢¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª2¡¢½øÈëºÃÓÑ¹ÜÀí¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª3¡¢½øÈëÈº¹ÜÀí¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª4¡¢ÇÐ»»QQµÇÂ¼¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª5¡¢ÇÐ»»Î¢²©µÇÂ¼¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª6¡¢ÇÐ»»Î¢ÐÅµÇÂ¼¡ª¡ª¡ª¡ª" << endl;
	cout << "¡ª¡ª¡ª¡ª7¡¢ÍË³öµÇÂ¼¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	int select;
	cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º";
	cin >> select;
	switch (select)
	{
	case 1:
		showAllInformation();
		break;
	case 2:
		weixfm->FMmeun(this);
		goto Start;
		break;
	case 3:
		weixgm->GMmeun(this);
		goto Start;
		break;
	case 4:
		type_now = 1;
		if (QQ_now != personcontainer[checkPerson(this->customerId)].showQQid()) {
			cout << "QQÎ´µÇÂ¼£¡" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showQQid() == 0) {
			cout << "QQÎ´×¢²á£¡" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 5:
		type_now = 3;
		if (WeiBlog_now != personcontainer[checkPerson(this->customerId)].showWeiBlogid()) {
			cout << "Î¢²©Î´µÇÂ¼£¡" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBlogid() == 0) {
			cout << "Î¢²©Î´×¢²á£¡" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 6:
		type_now = 2;
		if (WeChat_now != personcontainer[checkPerson(this->customerId)].showWeChatid()) {
			cout << "Î¢ÐÅÎ´µÇÂ¼£¡" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "Î¢ÐÅÎ´×¢²á£¡" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 7:
		type_now = 0;
		QQ_now = 0;
		WeChat_now = 0;
		WeiBlog_now = 0;
		WeiBusiness_now = 0;
		return;
		break;
	default:
		break;
	}
}

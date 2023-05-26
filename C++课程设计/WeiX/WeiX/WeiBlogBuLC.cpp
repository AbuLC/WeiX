#include"WeiBlogBuLC.h"

void WeiBlogBuLC::loginSucceed() {
	system("cls");
	cout << "欢迎登录微博！" << this->accountnum << endl;
	WeiBlog_now = this->accountnum;
	type_now = 3;
	//登录其他平台
	cout << "是否同时登录其他平台？" << endl;
	int n;
	cout << "1、是  2、否" << endl;
	cin >> n;
	if (n == 1) {
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "微信未注册" << endl;
		}
		else {
			cout << "微信已登录" << endl;
			WeChat_now =weixcontainer[ checkAccountNUm(2, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showQQid() == 0) {
			cout << "QQ未注册" << endl;
		}
		else {
			cout << "QQ已登录" << endl;
			QQ_now = weixcontainer[checkAccountNUm(1, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBusinessid() == 0) {
			cout << "微商未注册" << endl;
		}
		else {
			cout << "微商已登录" << endl;
			WeiBusiness_now = weixcontainer[checkAccountNUm(4, this->customerId)]->showaccountnum();
		}
	}
	system("pause");
	weiXMeun();
}
void WeiBlogBuLC::weiXMeun()
{
Start:

	system("cls");
	cout << "————1、查看个人信息————" << endl;
	cout << "————2、进入好友管理————" << endl;
	cout << "————3、进入群管理————" << endl;
	cout << "————4、切换QQ登录————" << endl;
	cout << "————5、切换微商登录————" << endl;
	cout << "————6、切换微信登录————" << endl;
	cout << "————7、退出登录————————" << endl;
	int select;
	cout << "请输入您的选择：";
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
			cout << "QQ未登录！" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showQQid() == 0) {
			cout << "QQ未注册！" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 5:
		type_now = 4;
		if (WeiBusiness_now != personcontainer[checkPerson(this->customerId)].showWeiBusinessid()) {
			cout << "微商未登录！" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBusinessid()==0) {
			cout << "微商未注册！" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 6:
		type_now = 2;
		if (WeChat_now != personcontainer[checkPerson(this->customerId)].showWeChatid()) {
			cout << "微信未登录！" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "微信未注册！" << endl;
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

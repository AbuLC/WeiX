#include"QQBuLC.h"

void QQBuLC::loginSucceed() {
	system("cls");
	cout << "��ӭ��¼QQ��" <<this->accountnum<< endl;
	QQ_now = this->accountnum;
	type_now = 1;
	//��¼����ƽ̨
	cout << "�Ƿ�ͬʱ��¼����ƽ̨��" << endl;
	int n;
	cout << "1����  2����" << endl;
	cin >> n;
	if (n == 1) {
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "΢��δע��" << endl;
		}
		else {
			cout << "΢���ѵ�¼" << endl;
			WeChat_now =weixcontainer[checkAccountNUm(2, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBlogid() == 0) {
			cout << "΢��δע��" << endl;
		}
		else {
			cout << "΢���ѵ�¼" << endl;
			WeiBlog_now = weixcontainer[checkAccountNUm(3, this->customerId)]->showaccountnum();
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBusinessid() == 0) {
			cout << "΢��δע��" << endl;
		}
		else {
			cout << "΢���ѵ�¼" << endl;
			WeiBusiness_now = weixcontainer[checkAccountNUm(4, this->customerId)]->showaccountnum();
		}
	}
	system("pause");
	weiXMeun();
}

void QQBuLC::weiXMeun()
{
Start:

	system("cls");
	cout << "��������1���鿴������Ϣ��������" << endl;
	cout << "��������2��������ѹ���������" << endl;
	cout << "��������3������Ⱥ����������" << endl;
	cout << "��������4���л�΢�ŵ�¼��������" << endl;
	cout << "��������5���л�΢����¼��������" << endl; 
	cout << "��������6���л�΢�̵�¼��������" << endl;
	cout << "��������7���˳���¼����������������" << endl;
	int select;
	cout << "����������ѡ��";
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
	case 4:
		type_now = 2;
		if (WeChat_now != personcontainer[checkPerson(this->customerId)].showWeChatid()) {
			cout << "΢��δ��¼��" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeChatid() == 0) {
			cout << "΢��δע�ᣡ" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 5:
		type_now = 3;
		if (WeiBlog_now != personcontainer[checkPerson(this->customerId)].showWeiBlogid()) {
			cout << "΢��δ��¼��" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBlogid() == 0) {
			cout << "΢��δע�ᣡ" << endl;
			system("pause");
			goto Start;
		}
		return;
		break;
	case 6:
		type_now = 4;
		if (WeiBusiness_now != personcontainer[checkPerson(this->customerId)].showWeiBusinessid()) {
			cout << "΢��δ��¼��" << endl;
			system("pause");
			goto Start;
		}
		if (personcontainer[checkPerson(this->customerId)].showWeiBusinessid()) {
			cout << "΢��δע�ᣡ" << endl;
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

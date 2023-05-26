#include"WeiXBuLC.h"



void WeiXBuLC::setpassword(string str)
{
	this->password = str;
}

void WeiXBuLC::setaccountnum(int acc)
{
	this->accountnum = acc;
}

void WeiXBuLC::setpersonid(string id)
{
	this->customerId = id;
}

void WeiXBuLC::settype(int t)
{
	this->type = t;
}



int WeiXBuLC::showaccountnum()
{
	return this->accountnum;
}

string WeiXBuLC::showcustomerid()
{
	return this->customerId;
}

int WeiXBuLC::showtype()
{
	return this->type;
}



string WeiXBuLC::outpassword()
{
	return password;
}

void WeiXBuLC::showAllInformation()
{
Start:
	system("cls");
	cout << "�˺Ż�����Ϣ��" << endl;
	cout << "�˺ţ�" << accountnum << " " << "�˺�����ʱ�䣺" << time << " " << "�˺����ͣ�";
	switch (this->type)
	{
	case 1:
		cout << "QQ" << endl;
		break;
	case 2:
		cout << "΢��" << endl;
		break;
	case 3:
		cout << "΢��" << endl;
		break;
	case 4:
		cout << "΢��" << endl;
		break;
	default:
		break;
	}
	cout << "���˻�����Ϣ��" << endl;
	personcontainer[checkPerson(this->customerId)].showInformation();
	cout << "��������1���޸ĸ�����Ϣ��������" << endl;
	cout << "��������2���޸����롪������������" << endl;
	cout << "��������3�����ء���������������������" << endl;
	cout << "����������ѡ��";
	int select;
	string s;
	cin >> select;
	switch (select)
	{
	case 1:
		personcontainer[checkPerson(this->customerId)].modifyInformation();
		goto Start;
		break;
	case 2:
		cout << "�����������룺";
		cin >> s;
		password = s;
		cout << "�޸ĳɹ���" << endl;
		system("pause");
		weiXMeun();
		break;
	case 3:
		weiXMeun();
		break;
	default:
		break;
	}

}





WeiXBuLC::WeiXBuLC()
{
	accountnum = 0;
	type = 0;
	wfriend.clear();
	wgroup.clear();
	password = "";
	weixfm = NULL;
	weixgm = NULL;
}
GroupBuLC::GroupBuLC()
{
	gname = "";
	gtype = 0;
	gmanageracc.clear();
	gpersonacc.clear();
}

//�����֤�����û�
int checkPerson(string id) {
	for (int i = 0; i < personcontainer.size(); i++) {
		if (personcontainer[i].showID() == id) {
			return i;
		}
	}
	return -1;
}
//�����֤���˺����Ͳ����˺�
int checkAccountNUm(int type, string id)
{
	for (int i = 0; i < weixcontainer.size(); i++) {
		if (weixcontainer[i]->showcustomerid() == id && weixcontainer[i]->showtype() == type) {
			return i;
		}
	}
	return -1;
}
//���˺Ų�������λ��
int checkIndex(int acc,int type) {
	for (int i = 0; i < weixcontainer.size(); i++) {
		if (weixcontainer[i]->showaccountnum() == acc && type==weixcontainer[i]->showtype()) {
			return i;
		}
	}
	return -1;
}


void GroupManagementBuLC::allGroup(WeiXBuLC* w)
{
	for (int i = 0; i < w->wgroup.size(); i++) {
		cout << i + 1 << "��" << w->wgroup[i] << endl;
	}
}

void GroupManagementBuLC::allPerson(int index)
{
	for (int i = 0; i < groupcontainer[index].gpersonacc.size(); i++) {
		cout << i + 1 << "��" << groupcontainer[index].gpersonacc[i] << endl;
	}
}
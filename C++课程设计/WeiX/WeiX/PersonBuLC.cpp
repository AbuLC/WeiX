#include"PersonBuLC.h"
PersonBuLC::PersonBuLC() {
	location = "";
	name = "";
	Id = "";
	phone = "";
	QQid = 0;
	WeChatid = 0;
	WeiBlogid = 0;
	WeiBusinessid = 0;
}
PersonBuLC::PersonBuLC(const string loc,const string nam, const string id, const string pho,const int qq,const int wechat,const int weiblog,const int weibusiness) {
	this->location = loc;
	this->name = nam;
	this->Id = id;
	this->phone = pho;
	this->QQid = qq;
	this->WeChatid = wechat;
	this->WeiBlogid = weiblog;
	this->WeiBusinessid = weibusiness;
}

PersonBuLC::PersonBuLC(const PersonBuLC& p)
{
	this->location = p.location;
	this->Id = p.Id;
	this->name = p.name;
	this->phone = p.phone;
	this->QQid = p.QQid;
	this->WeChatid = p.WeChatid;
	this->WeiBlogid = p.WeiBlogid;
	this->WeiBusinessid = p.WeiBusinessid;
}

void PersonBuLC::operator=(PersonBuLC& p)
{
	this->location = p.location;
	this->Id = p.Id;
	this->name = p.name;
	this->phone = p.phone;
	this->QQid = p.QQid;
	this->WeChatid = p.WeChatid;
	this->WeiBlogid = p.WeiBlogid;
	this->WeiBusinessid = p.WeiBusinessid;
}

string PersonBuLC::showName()
{
	return this->name;
}

string PersonBuLC::showID()
{
	return this->Id;
}

string PersonBuLC::showPhone()
{
	return this->phone;
}

string PersonBuLC::showlocation()
{
	return this->location;
}

int PersonBuLC::showQQid()
{
	return this->QQid;
}

int PersonBuLC::showWeChatid()
{
	return WeChatid;
}

int PersonBuLC::showWeiBlogid()
{
	return WeiBlogid;
}

int PersonBuLC::showWeiBusinessid()
{
	return WeiBusinessid;
}

void PersonBuLC::showInformation()
{
	cout << "������" << this->name <<" " << "���ڵأ�" << this->location <<" " << "���֤�ţ�" << this->Id <<" " << "�绰��" << this->phone<<endl;
}

void PersonBuLC::setacc(int t, int acc)
{
	switch (t)
	{
	case 1:
		QQid = acc;
		break;
	case 2:
		WeChatid = acc;
		break;
	case 3:
		WeiBlogid = acc;
		break;
	case 4:
		WeiBusinessid = acc;
		break;
	default:
		
		break;
	}
}

void PersonBuLC::modifyInformation()
{
Start:
	system("cls");
	cout << "���������Ϣ��" << endl;
	showInformation();
	cout << "��������1���޸ĸ���������������" << endl;
	cout << "��������2���޸����֤�š�������" << endl;
	cout << "��������3���޸ĵ绰���롪������" << endl;
	cout << "��������4���޸����ڵء�����������" << endl;
	cout << "��������5���˳��޸ġ�������������" << endl;
	cout << "����������ѡ��";
	int select;
	string s;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "�������޸ĺ��������";
		cin >> s;
		this->name = s;
		break;
	case 2:
		cout << "�������޸ĺ�����֤�ţ�";
		cin >> s;
		this->Id = s;
		break;
	case 3:
		cout << "�������޸ĺ�ĵ绰���룺";
		cin >> s;
		this->phone = s;
		break;
	case 4:
		cout << "�������޸ĺ�����ڵأ�";
		cin >> s;
		this->location = s;
		break;
	case 5:
		return;
	default:
		break;
	}
	cout << "�޸ĳɹ���" << endl;
	cout << "��������1�������޸ġ�������" << endl;
	cout << "��������2���˳��޸ġ�������" << endl;
	cout << "����������ѡ��";
	cin >> select;
	switch (select)
	{
	case 1:
		goto Start;
		break;
	case 2:
		return;
	default:
		break;
	}

}



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
	cout << "姓名：" << this->name <<" " << "所在地：" << this->location <<" " << "身份证号：" << this->Id <<" " << "电话：" << this->phone<<endl;
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
	cout << "个体基本信息：" << endl;
	showInformation();
	cout << "————1、修改个人姓名————" << endl;
	cout << "————2、修改身份证号————" << endl;
	cout << "————3、修改电话号码————" << endl;
	cout << "————4、修改所在地——————" << endl;
	cout << "————5、退出修改———————" << endl;
	cout << "请输入您的选择：";
	int select;
	string s;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "请输入修改后的姓名：";
		cin >> s;
		this->name = s;
		break;
	case 2:
		cout << "请输入修改后的身份证号：";
		cin >> s;
		this->Id = s;
		break;
	case 3:
		cout << "请输入修改后的电话号码：";
		cin >> s;
		this->phone = s;
		break;
	case 4:
		cout << "请输入修改后的所在地：";
		cin >> s;
		this->location = s;
		break;
	case 5:
		return;
	default:
		break;
	}
	cout << "修改成功！" << endl;
	cout << "————1、继续修改————" << endl;
	cout << "————2、退出修改————" << endl;
	cout << "请输入您的选择：";
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



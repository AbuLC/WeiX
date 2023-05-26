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
	cout << "账号基本信息：" << endl;
	cout << "账号：" << accountnum << " " << "账号申请时间：" << time << " " << "账号类型：";
	switch (this->type)
	{
	case 1:
		cout << "QQ" << endl;
		break;
	case 2:
		cout << "微信" << endl;
		break;
	case 3:
		cout << "微博" << endl;
		break;
	case 4:
		cout << "微商" << endl;
		break;
	default:
		break;
	}
	cout << "本人基本信息：" << endl;
	personcontainer[checkPerson(this->customerId)].showInformation();
	cout << "————1、修改个人信息————" << endl;
	cout << "————2、修改密码———————" << endl;
	cout << "————3、返回———————————" << endl;
	cout << "请输入您的选择：";
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
		cout << "请输入新密码：";
		cin >> s;
		password = s;
		cout << "修改成功！" << endl;
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

//按身份证查找用户
int checkPerson(string id) {
	for (int i = 0; i < personcontainer.size(); i++) {
		if (personcontainer[i].showID() == id) {
			return i;
		}
	}
	return -1;
}
//按身份证和账号类型查找账号
int checkAccountNUm(int type, string id)
{
	for (int i = 0; i < weixcontainer.size(); i++) {
		if (weixcontainer[i]->showcustomerid() == id && weixcontainer[i]->showtype() == type) {
			return i;
		}
	}
	return -1;
}
//按账号查找所在位置
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
		cout << i + 1 << "、" << w->wgroup[i] << endl;
	}
}

void GroupManagementBuLC::allPerson(int index)
{
	for (int i = 0; i < groupcontainer[index].gpersonacc.size(); i++) {
		cout << i + 1 << "、" << groupcontainer[index].gpersonacc[i] << endl;
	}
}
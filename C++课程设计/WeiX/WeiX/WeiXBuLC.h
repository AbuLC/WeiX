#pragma once
#include<iostream>
#include<vector>
#include"PersonBuLC.h"


//按身份证查找用户
int checkPerson(string id);
//按身份证和账号类型查找账号
int checkAccountNUm(int type, string id);
//按账号查找所在位置
int checkIndex(int acc,int type);
//vector的查找函数
template<typename T>
bool findIn(T acc, vector<T> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == acc) {
			return true;
		}
	}
	return false;
}

class FriendManagementBuLC;
class GroupManagementBuLC;
class WeiXBuLC;
class GroupBuLC;
extern vector<PersonBuLC>personcontainer;
extern vector<WeiXBuLC*>weixcontainer;
extern vector<GroupBuLC>groupcontainer;
extern int QQ_now;
extern int WeChat_now;
extern int WeiBlog_now;
extern int WeiBusiness_now;
extern int type_now;

class WeiXBuLC {
public:
	WeiXBuLC();
	WeiXBuLC(WeiXBuLC& w) {
		time = w.time;
		wfriend = w.wfriend;
		wgroup = w.wgroup;
		password = w.password;
		customerId = w.customerId;
		accountnum = w.accountnum;
		type = w.type;
	}
	//设置密码
	void setpassword(string str);
	//设置账号
	void setaccountnum(int acc);
	//设置本人证件号
	void setpersonid(string id);
	//设置账号类型
	void settype(int t);
	//显示账号
	int showaccountnum();
	//显示本人证件号
	string showcustomerid();
	//显示账号类型
	int showtype();
	//返回密码
	string outpassword();
	//登录成功界面
	virtual void loginSucceed()=0;
	//登录菜单
	virtual void weiXMeun() = 0;
	//显示所有信息
	void showAllInformation();
	~WeiXBuLC()
	{
	}
public:
	
	string time;//账号申请时间
	vector<int>wfriend;//好友列表（存放好友的账号）
	vector<string>wgroup;//群列表（存放群聊名称）
	FriendManagementBuLC* weixfm;
	GroupManagementBuLC* weixgm;
protected:
	string password;
	string customerId;//存放本人身份证号，便于查找个人信息
	int accountnum;//账号
	int type;//账号类型	QQ为1 微信为2 微博为3 微商为4
};
class GroupBuLC {
public:
	GroupBuLC();
public:
	string gname;//群名称
	int gtype;//群类型	QQ为1 微信为2 微博为3 微商为4
	int gowneracc;//群主账号
	vector<int> gmanageracc;//管理员账号
	vector<int> gpersonacc;//所有群成员账号

};

class FriendManagementBuLC
{
public:
	FriendManagementBuLC() {};
	~FriendManagementBuLC() {};
	//好友管理菜单
	virtual void FMmeun(WeiXBuLC* w)=0;
	//添加好友
	virtual void addNewFriend(WeiXBuLC* w)=0;
	//添加本人其他产品好友的账号
	virtual void addNewFriend2(WeiXBuLC* w) = 0;
	//删除好友
	virtual void deleteFriend(WeiXBuLC* w)=0;
	//显示所有好友
	virtual void allFriend(WeiXBuLC* w)=0;
	
};
class GroupManagementBuLC
{
public:
	GroupManagementBuLC() {};
	~GroupManagementBuLC() {};
	void allGroup(WeiXBuLC* w);//查看群列表
	void allPerson(int index);//查看所有群成员
	virtual void GMmeun(WeiXBuLC* w) = 0;//群管理菜单
	virtual void newGroup(WeiXBuLC* w) = 0;//创建群
	virtual void joinGroup(WeiXBuLC* w) = 0;//加入群
	
	virtual void quitGroup(WeiXBuLC* w)=0;//退出群
	virtual void deletePerson(int index, int acc)=0;//踢人
	
	
	virtual void manageGroup(int index, WeiXBuLC* w) = 0;//管理员界面
	//void communication(string wgname);
};



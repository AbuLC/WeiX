#pragma once
#include"WeiXBuLC.h"
#include<fstream>
class JoinApplicationBuLC {
public:
	string gname;
	int applicant;
	JoinApplicationBuLC() {
		gname = "";
		applicant = 0;
	}
	JoinApplicationBuLC(string g, int a) {
		gname = g;
		applicant = a;
	}
};
extern vector<JoinApplicationBuLC> applicationcontainer;
extern void readApplication();
extern void saveApplication();




class QQgmBuLC :public GroupManagementBuLC
{
	virtual void GMmeun(WeiXBuLC* w) ;//群管理界面
	virtual void newGroup(WeiXBuLC* w) ;//创建群
	virtual void joinGroup(WeiXBuLC* w) ;//申请加入群
	virtual void quitGroup(WeiXBuLC* w) ;//退出群
	virtual void deletePerson(int index,int acc) ;//踢人	
	virtual void manageGroup(int index, WeiXBuLC* w) ;//管理员界面
	//QQ专有
	void newSmallGroup(int index, WeiXBuLC* w);//创建子群
	void acceptJoinGroup(int index);//同意加群
};


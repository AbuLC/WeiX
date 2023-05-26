#pragma once
#include"WeiXBuLC.h"

class WBugmBuLC :public GroupManagementBuLC
{
	virtual void GMmeun(WeiXBuLC* w);//群管理界面
	virtual void newGroup(WeiXBuLC* w);//创建群
	virtual void joinGroup(WeiXBuLC* w);//推荐加入群
	virtual void quitGroup(WeiXBuLC* w);//退出群
	virtual void deletePerson(int index, int acc);//踢人	
	virtual void manageGroup(int index, WeiXBuLC* w);//管理员界面
};


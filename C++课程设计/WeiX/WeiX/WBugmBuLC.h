#pragma once
#include"WeiXBuLC.h"

class WBugmBuLC :public GroupManagementBuLC
{
	virtual void GMmeun(WeiXBuLC* w);//Ⱥ�������
	virtual void newGroup(WeiXBuLC* w);//����Ⱥ
	virtual void joinGroup(WeiXBuLC* w);//�Ƽ�����Ⱥ
	virtual void quitGroup(WeiXBuLC* w);//�˳�Ⱥ
	virtual void deletePerson(int index, int acc);//����	
	virtual void manageGroup(int index, WeiXBuLC* w);//����Ա����
};


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
	virtual void GMmeun(WeiXBuLC* w) ;//Ⱥ�������
	virtual void newGroup(WeiXBuLC* w) ;//����Ⱥ
	virtual void joinGroup(WeiXBuLC* w) ;//�������Ⱥ
	virtual void quitGroup(WeiXBuLC* w) ;//�˳�Ⱥ
	virtual void deletePerson(int index,int acc) ;//����	
	virtual void manageGroup(int index, WeiXBuLC* w) ;//����Ա����
	//QQר��
	void newSmallGroup(int index, WeiXBuLC* w);//������Ⱥ
	void acceptJoinGroup(int index);//ͬ���Ⱥ
};


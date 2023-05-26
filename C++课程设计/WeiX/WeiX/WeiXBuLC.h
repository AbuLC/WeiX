#pragma once
#include<iostream>
#include<vector>
#include"PersonBuLC.h"


//�����֤�����û�
int checkPerson(string id);
//�����֤���˺����Ͳ����˺�
int checkAccountNUm(int type, string id);
//���˺Ų�������λ��
int checkIndex(int acc,int type);
//vector�Ĳ��Һ���
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
	//��������
	void setpassword(string str);
	//�����˺�
	void setaccountnum(int acc);
	//���ñ���֤����
	void setpersonid(string id);
	//�����˺�����
	void settype(int t);
	//��ʾ�˺�
	int showaccountnum();
	//��ʾ����֤����
	string showcustomerid();
	//��ʾ�˺�����
	int showtype();
	//��������
	string outpassword();
	//��¼�ɹ�����
	virtual void loginSucceed()=0;
	//��¼�˵�
	virtual void weiXMeun() = 0;
	//��ʾ������Ϣ
	void showAllInformation();
	~WeiXBuLC()
	{
	}
public:
	
	string time;//�˺�����ʱ��
	vector<int>wfriend;//�����б���ź��ѵ��˺ţ�
	vector<string>wgroup;//Ⱥ�б����Ⱥ�����ƣ�
	FriendManagementBuLC* weixfm;
	GroupManagementBuLC* weixgm;
protected:
	string password;
	string customerId;//��ű������֤�ţ����ڲ��Ҹ�����Ϣ
	int accountnum;//�˺�
	int type;//�˺�����	QQΪ1 ΢��Ϊ2 ΢��Ϊ3 ΢��Ϊ4
};
class GroupBuLC {
public:
	GroupBuLC();
public:
	string gname;//Ⱥ����
	int gtype;//Ⱥ����	QQΪ1 ΢��Ϊ2 ΢��Ϊ3 ΢��Ϊ4
	int gowneracc;//Ⱥ���˺�
	vector<int> gmanageracc;//����Ա�˺�
	vector<int> gpersonacc;//����Ⱥ��Ա�˺�

};

class FriendManagementBuLC
{
public:
	FriendManagementBuLC() {};
	~FriendManagementBuLC() {};
	//���ѹ���˵�
	virtual void FMmeun(WeiXBuLC* w)=0;
	//��Ӻ���
	virtual void addNewFriend(WeiXBuLC* w)=0;
	//��ӱ���������Ʒ���ѵ��˺�
	virtual void addNewFriend2(WeiXBuLC* w) = 0;
	//ɾ������
	virtual void deleteFriend(WeiXBuLC* w)=0;
	//��ʾ���к���
	virtual void allFriend(WeiXBuLC* w)=0;
	
};
class GroupManagementBuLC
{
public:
	GroupManagementBuLC() {};
	~GroupManagementBuLC() {};
	void allGroup(WeiXBuLC* w);//�鿴Ⱥ�б�
	void allPerson(int index);//�鿴����Ⱥ��Ա
	virtual void GMmeun(WeiXBuLC* w) = 0;//Ⱥ����˵�
	virtual void newGroup(WeiXBuLC* w) = 0;//����Ⱥ
	virtual void joinGroup(WeiXBuLC* w) = 0;//����Ⱥ
	
	virtual void quitGroup(WeiXBuLC* w)=0;//�˳�Ⱥ
	virtual void deletePerson(int index, int acc)=0;//����
	
	
	virtual void manageGroup(int index, WeiXBuLC* w) = 0;//����Ա����
	//void communication(string wgname);
};



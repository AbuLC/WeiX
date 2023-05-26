#pragma once
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class PersonBuLC {
public:
	//���캯��
	PersonBuLC();
	PersonBuLC(const string loc, const string nam, const string id, const string pho, const int qq, const int wechat, const int weiblog, const int weibusiness);
	PersonBuLC(const PersonBuLC& p);
	void operator=(PersonBuLC& p);
	//������ʵ����
	string showName();
	//�������֤��
	string showID();
	//���ص绰
	string showPhone();
	//�������ڵ�
	string showlocation();
	int showQQid();
	int showWeChatid();
	int showWeiBlogid();
	int showWeiBusinessid();
	//��ʾ������Ϣ
	void showInformation();
	//���ø����˺�
	void setacc(int t, int acc);
	//�޸ĸ�����Ϣ
	void modifyInformation();
private:
	string name;//��ʵ����
	string Id;//���֤��
	string phone;//�绰
	string location;//���ڵ�
	int QQid;
	int WeChatid;
	int WeiBlogid;
	int WeiBusinessid;
};


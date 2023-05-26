#pragma once
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class PersonBuLC {
public:
	//构造函数
	PersonBuLC();
	PersonBuLC(const string loc, const string nam, const string id, const string pho, const int qq, const int wechat, const int weiblog, const int weibusiness);
	PersonBuLC(const PersonBuLC& p);
	void operator=(PersonBuLC& p);
	//返回真实姓名
	string showName();
	//返回身份证号
	string showID();
	//返回电话
	string showPhone();
	//返回所在地
	string showlocation();
	int showQQid();
	int showWeChatid();
	int showWeiBlogid();
	int showWeiBusinessid();
	//显示个人信息
	void showInformation();
	//设置个人账号
	void setacc(int t, int acc);
	//修改个人信息
	void modifyInformation();
private:
	string name;//真实姓名
	string Id;//身份证号
	string phone;//电话
	string location;//所在地
	int QQid;
	int WeChatid;
	int WeiBlogid;
	int WeiBusinessid;
};


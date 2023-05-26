#pragma once
#include "WeiXBuLC.h"
#include"QQfmBuLC.h"
#include"QQgmBuLC.h"
extern vector<JoinApplicationBuLC> applicationcontainer;
extern void readApplication();
extern void saveApplication();
class QQBuLC :public WeiXBuLC
{
public:
	QQBuLC() {
		accountnum = 0;
		type = 1;
		wfriend.clear();
		wgroup.clear();
		password = "";
		weixfm = new QQfmBuLC;
		weixgm = new QQgmBuLC;
	}
	virtual void loginSucceed();
	virtual void weiXMeun();
	
};


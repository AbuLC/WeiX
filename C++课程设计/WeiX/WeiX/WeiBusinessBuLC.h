#pragma once
#include "WeiXBuLC.h"
#include"WBufmBuLC.h"
#include"WBugmBuLC.h"
class WeiBusinessBuLC :public WeiXBuLC
{
public:
	WeiBusinessBuLC() {
		accountnum = 0;
		type = 4;
		wfriend.clear();
		wgroup.clear();
		password = "";
		weixfm = new WBufmBuLC;
		weixgm = new WBugmBuLC;
	}
	virtual void loginSucceed();
	virtual void weiXMeun() ;
	
};


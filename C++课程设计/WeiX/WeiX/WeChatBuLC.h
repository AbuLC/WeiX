#pragma once
#include "WeiXBuLC.h"
#include"WCfmBuLC.h"
#include"WCgmBuLC.h"
class WeChatBuLC :public WeiXBuLC
{
public:
	
	WeChatBuLC() {
		accountnum = 0;
		type = 2;
		wfriend.clear();
		wgroup.clear();
		password = "";
		weixfm = new WCfmBuLC;
		weixgm = new WCgmBuLC;
	}
	virtual void loginSucceed();
	virtual void weiXMeun() ;
	
};


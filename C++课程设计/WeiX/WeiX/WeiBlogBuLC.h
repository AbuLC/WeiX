#pragma once
#include "WeiXBuLC.h"
#include"WBfmBuLC.h"
#include"WBgmBuLC.h"
class WeiBlogBuLC :public WeiXBuLC
{
public:
	WeiBlogBuLC() {
		accountnum = 0;
		type = 3;
		wfriend.clear();
		wgroup.clear();
		password = "";
		weixfm = new WBfmBuLC;
		weixgm = new WBgmBuLC;
	}
	virtual void loginSucceed();
	virtual void weiXMeun() ;
	
};


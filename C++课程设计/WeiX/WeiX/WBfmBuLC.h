#pragma once
#include"WeiXBuLC.h"
class WBfmBuLC :public FriendManagementBuLC
{
	virtual void FMmeun(WeiXBuLC* w);
	virtual void addNewFriend(WeiXBuLC* w);
	virtual void addNewFriend2(WeiXBuLC* w);
	virtual void deleteFriend(WeiXBuLC* w);
	virtual void allFriend(WeiXBuLC* w);
};


#include"QQfmBuLC.h"

void QQfmBuLC::FMmeun(WeiXBuLC* w)
{
Start:

	system("cls");
	allFriend(w);
	cout << endl;
	cout << "————1、添加好友————" << endl;
	cout << "————2、添加其他账号的好友————" << endl;
	cout << "————3、删除好友————" << endl;
	cout << "————4、返回————" << endl;
	int select=0;
	cout << "请输入您的选择：" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		addNewFriend(w);
		return;
		break;
	case 2:
		addNewFriend2(w);
		goto Start;
	case 3:
		deleteFriend(w);
		goto Start;
	case 4:
		return;
	default:
		break;
	}
}
void QQfmBuLC::addNewFriend(WeiXBuLC* w) 
{
	
Start:
	int friendacc;
	cout << "请输入要添加好友的账号：" << endl;
	cin >> friendacc;
	int index=checkIndex(friendacc, 1);
	if (index == -1) {
		cout << "账号输入错误！" << endl;
		system("pause");
		goto Start;
	}
	for (int i = 0; i < w->wfriend.size(); i++) {
		if (w->wfriend[i] == friendacc) {
			cout << "好友已被添加！" << endl;
			system("pause");
			goto Start;
		}
	}
	w->wfriend.push_back(friendacc);
	weixcontainer[index]->wfriend.push_back(w->showaccountnum());
	cout << "好友已添加成功！" << endl;
	system("pause");
}

void QQfmBuLC::addNewFriend2(WeiXBuLC* w)
{
	system("cls");
	int otheracc;//本人其他的账号
	int index;//账号在数组中的位置
	vector<int> newfriend;//新好友数组
	int count=-1;//新好友总数
	//微信好友
	if (personcontainer[checkPerson(w->showcustomerid())].showWeChatid() == 0) {
		cout << "微信尚未注册！" << endl;
	}
	else {
		cout << "来自微信好友：" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeChatid();
		index = checkIndex(otheracc, 2);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//微信好友在数组中的位置
			k = checkIndex(weixcontainer[index]->wfriend[i], 2);
			//判断该好友是否开通QQ账号
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//判断是否已经添加
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "、" << newfriend[count]
						<< "  来自微信好友" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
				
			}
		}
	}
	//微博好友
	if (personcontainer[checkPerson(w->showcustomerid())].showWeiBlogid() == 0) {
		cout << "微博尚未注册！" << endl;
	}
	else {
		cout << "来自微博好友：" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeiBlogid();
		index = checkIndex(otheracc, 3);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//微博好友在数组中的位置
			k = checkIndex(weixcontainer[index]->wfriend[i], 3);
			//判断该好友是否开通QQ账号
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//判断是否已经添加
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "、" << newfriend[count]
						<< "  来自微博好友" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
			}
		}
	}
	//微商好友
	if (personcontainer[checkPerson(w->showcustomerid())].showWeiBusinessid() == 0) {
		cout << "微商尚未注册！" << endl;
	}
	else {
		cout << "来自微商好友：" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeiBusinessid();
		index = checkIndex(otheracc, 4);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//微博好友在数组中的位置
			k = checkIndex(weixcontainer[index]->wfriend[i], 4);
			//判断该好友是否开通QQ账号
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//判断是否已经添加
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "、" << newfriend[count]
						<< "  来自微商好友" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
			}
		}
	}



	cout << endl << "请选择您要添加的好友序号：";
	
	int n,m;
	cin >> n;
	n = n - 1;
	w->wfriend.push_back(newfriend[n]);//本人账号操作
	int j;
	j = checkIndex(newfriend[n], 1);//好友账号操作
	weixcontainer[j]->wfriend.push_back(w->showaccountnum());
	cout << "添加成功！" << endl;
	system("pause");
	return;

}

void QQfmBuLC::deleteFriend(WeiXBuLC* w)
{
	int n;
	cout << "请输入要删除的好友序号：" << endl;
	cin >> n;
	n = n - 1;
	//对好友账号操作
	{
		int index = checkIndex(w->wfriend[n], 1);
		for (vector<int>::iterator it = weixcontainer[index]->wfriend.begin(); it != weixcontainer[index]->wfriend.end(); it++) {
			if (*it == w->showaccountnum()) {
				weixcontainer[index]->wfriend.erase(it);
				break;
			}
		}

	}
	//对本人账号操作
	{
		for (vector<int>::iterator it = w->wfriend.begin(); it != w->wfriend.end(); it++) {
			if (*it == w->wfriend[n]) {
				w->wfriend.erase(it);
				break;
			}
		}
	}
	cout << "删除好友成功！" << endl;
	system("pause");
	return;

}

void QQfmBuLC::allFriend(WeiXBuLC* w)
{
	system("cls");
	cout << w->showaccountnum() << "的好友列表：" << endl;
	for (int i = 0; i < w->wfriend.size(); i++) {
		cout <<i+1<<"、" << w->wfriend[i] <<" " << personcontainer[checkPerson(weixcontainer[checkIndex(w->wfriend[i], 1)]->showcustomerid())].showName() << endl;
	}
	cout << endl;
}

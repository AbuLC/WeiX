#include"WBgmBuLC.h"

void WBgmBuLC::GMmeun(WeiXBuLC* w)
{
Start:
    system("cls");
    int i;
    allGroup(w);
    cout << "————1、推荐好友入群————" << endl;
    cout << "————2、退出群————" << endl;
    cout << "————3、创建群————" << endl;
    cout << "————4、管理群————" << endl;
    cout << "————5、返回————" << endl;
    int select;
    cout << "请输入您的选择：";
    cin >> select;
    switch (select)
    {
    case 1:
        joinGroup(w);
        goto Start;
        break;
    case 2:
        quitGroup(w);
        goto Start;
        break;
    case 3:
        newGroup(w);
        goto Start;
        break;
    case 4:
        cout << "请输入您要管理的群序号：";
        cin >> i;
        int j;//记录群的位置
        for (j = 0; j < groupcontainer.size(); j++) {
            if (groupcontainer[j].gname == w->wgroup[i - 1] && groupcontainer[j].gtype == 3) {
                break;
            }
        }
        if (findIn(w->showaccountnum(), groupcontainer[j].gmanageracc)) {//判断是否为管理员
            manageGroup(j, w);
        }
        else {
            cout << "您不是该群管理员！" << endl;
            system("pause");
            goto Start;
        }
        goto Start;
        break;
    case 5:
        return;
        break;
    default:
        break;
    }
}

void WBgmBuLC::newGroup(WeiXBuLC* w)
{
    system("cls");
Start:
    cout << "请输入您要创建微博群的名称：" << endl;
    string gm;
    cin >> gm;
    bool flag = true;
    for (int i = 0; i < groupcontainer.size(); i++) {
        if (gm == groupcontainer[i].gname && groupcontainer[i].gtype == 3) {
            flag = false;
        }
    }
    if (!flag) {
        cout << "该名称已被使用！" << endl;
        system("pause");
        goto Start;
    }
    GroupBuLC g;
    g.gname = gm;
    g.gtype = 3;
    g.gowneracc = w->showaccountnum();
    g.gmanageracc.push_back(w->showaccountnum());
    g.gpersonacc.push_back(w->showaccountnum());
    groupcontainer.push_back(g);
    w->wgroup.push_back(g.gname);
    cout << gm << " 成功创建！" << endl;
    system("pause");
    return;
}

void WBgmBuLC::joinGroup(WeiXBuLC* w)
{
    system("cls");
    cout << "微博采用推荐制加群" << endl;
    cout << "您的好友：" << endl;
    w->weixfm->allFriend(w);
    cout << "您所在的群：" << endl;
    allGroup(w);
    
    int n, m;
    cout << "输入您要推荐的群：（填序号）" << endl;
    cin >> n;
    n = n - 1;
    cout << "输入您要推荐的好友：（填序号）" << endl;
    cin >> m;
    m = m - 1;
    int j;//群的位置
    for (j = 0; j< groupcontainer.size(); j++) {
        if (groupcontainer[j].gname == w->wgroup[n] && groupcontainer[j].gtype == 3) {
            break;
        }
    }
    groupcontainer[j].gpersonacc.push_back(w->wfriend[m]);
    int k = checkIndex(w->wfriend[m], 3);
    weixcontainer[k]->wgroup.push_back(w->wgroup[n]);
    cout << "推荐成功！" << endl;
    system("pause");
    return;
}



void WBgmBuLC::quitGroup(WeiXBuLC* w)
{
    system("cls");
    allGroup(w);
    int i;
    cout << "请输入您要退群的序号：";
    cin >> i;
    i = i - 1;
    //对群操作
    int j;//记录群的位置
    for (j = 0; j < groupcontainer.size(); j++) {
        if (w->wgroup[i] == groupcontainer[j].gname && groupcontainer[j].gtype == 3) {
            break;
        }
    }
    if (w->showaccountnum() == groupcontainer[j].gowneracc) {
        cout << "您是群主，不能退群！" << endl;
        system("pause");
        return;
    }
    //从管理员删除 
    for (vector<int>::iterator it = groupcontainer[j].gmanageracc.begin(); it != groupcontainer[j].gmanageracc.end(); it++) {
        if (*it == w->showaccountnum()) {
            groupcontainer[j].gmanageracc.erase(it);
            break;
        }
    }

    //从群成员删除   
    for (vector<int>::iterator it = groupcontainer[j].gpersonacc.begin(); it != groupcontainer[j].gpersonacc.end(); it++) {
        if (*it == w->showaccountnum()) {
            groupcontainer[j].gpersonacc.erase(it);
            break;
        }
    }
    //对账号操作
    for (vector<string>::iterator it = w->wgroup.begin(); it != w->wgroup.end(); it++) {
        if (*it == w->wgroup[i]) {
            w->wgroup.erase(it);
            break;
        }
    }
    cout << "退群成功！" << endl;
    system("pause");
    return;
}

void WBgmBuLC::deletePerson(int index, int acc)
{
    if (findIn(acc, groupcontainer[index].gmanageracc)) {
        cout << "不能踢出管理员！" << endl;
        system("pause");
        return;
    }
    else {
        //删除成员        
        for (vector<int>::iterator it = groupcontainer[index].gpersonacc.begin(); it != groupcontainer[index].gpersonacc.end(); it++) {
            if (*it == acc) {
                groupcontainer[index].gpersonacc.erase(it);
                break;
            }
        }
        int k = checkIndex(acc, 3);
        //成员中删除群
        for (vector<string>::iterator it = weixcontainer[k]->wgroup.begin(); it != weixcontainer[k]->wgroup.end(); it++) {
            if (*it == groupcontainer[index].gname) {
                weixcontainer[k]->wgroup.erase(it);
                break;
            }
        }
        cout << "已踢出该成员！" << endl;
        system("pause");
        return;
    }
}

void WBgmBuLC::manageGroup(int index, WeiXBuLC* w)
{
Start:
    system("cls");
    cout << groupcontainer[index].gname << "的群管理界面" << endl;
    cout << "群成员：" << endl;
    allPerson(index);
    cout << "————1、设置管理员————" << endl;
    cout << "————2、踢出成员————" << endl;
    cout << "————3、返回————" << endl;
    int select;
    int j;
    cout << "请输入您的选择：";
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "请输入您选择的群成员序号：";
        cin >> j;
        if (groupcontainer[index].gpersonacc[j - 1] == w->showaccountnum()) {
            cout << "您已经是管理员" << endl;
            system("pause");
        }
        else {
            groupcontainer[index].gmanageracc.push_back(groupcontainer[index].gpersonacc[j - 1]);
            cout << "设置成功！" << endl;
            system("pause");
        }
        goto Start;
        break;
    case 2:
        cout << "请输入您选择的群成员序号：";
        cin >> j;
        deletePerson(index, groupcontainer[index].gpersonacc[j - 1]);
        goto Start;
        break;
    case 3:
        return;
        break;
    default:
        break;
    }
}

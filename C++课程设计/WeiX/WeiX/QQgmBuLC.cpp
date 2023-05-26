#include"QQgmBuLC.h"
void readApplication()
{
    ifstream ifs;
    ifs.open("application.txt", ios::in);
    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    string gn;
    int ap;
    while (ifs >> gn && ifs >> ap) {
        JoinApplicationBuLC j(gn, ap);
        applicationcontainer.push_back(j);
    }
}

void saveApplication()
{
    ofstream ofs;
    ofs.open("application.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件不存在" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < applicationcontainer.size(); i++) {
        ofs << applicationcontainer[i].gname << " " << applicationcontainer[i].applicant << endl;
    }
    ofs.close();
}

void QQgmBuLC::GMmeun(WeiXBuLC* w) {
Start:
    system("cls");
    int i;
    allGroup(w);
    cout << "————1、添加群————" << endl;
    cout << "————2、退出群————" << endl;
    cout << "————3、创建群————" << endl;
    cout << "————4、管理群————" << endl;
    cout << "————5、返回————" << endl;
    int select;
    cout << "请输入您的选择：" ;
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
            if (groupcontainer[j].gname == w->wgroup[i - 1] && groupcontainer[j].gtype == 1) {
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
        saveApplication();
        return;
        break;
    default:
        break;
    }
}

void QQgmBuLC::newGroup(WeiXBuLC* w)
{
    system("cls");
Start:
    cout << "请输入您要创建QQ群的名称：" << endl;
    string gm;
    cin >> gm;
    bool flag=true;
    for (int i = 0; i < groupcontainer.size(); i++) {
        if (gm == groupcontainer[i].gname && groupcontainer[i].gtype == 1) {
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
    g.gtype = 1;
    g.gowneracc = w->showaccountnum();
    g.gmanageracc.push_back(w->showaccountnum());
    g.gpersonacc.push_back(w->showaccountnum());
    groupcontainer.push_back(g);
    w->wgroup.push_back(g.gname);
    cout << gm << " 成功创建！" << endl;
    system("pause");
    return;
}

void QQgmBuLC::joinGroup(WeiXBuLC* w)
{
    system("cls");
    cout << "QQ采取申请制加群" << endl;
    cout << "请输入您要加入的群的名称" << endl;
    string s;
    cin >> s;
    if (findIn(s, w->wgroup)) {
        cout << "该群已加入！" << endl;
        system("pause");
        return;
    }
    int i;
    for (i = 0;i<groupcontainer.size() ; i++) {
        if (s == groupcontainer[i].gname&&groupcontainer[i].gtype==1) {
            break;
        }
    }
    if (i == groupcontainer.size()) {
        cout << "无此群！" << endl;
        system("pause");
        return;
    }
    JoinApplicationBuLC j(s, w->showaccountnum());
    applicationcontainer.push_back(j);
    cout << "已提交申请，请等待管理员审核！" << endl;
    system("pause");
    return;
}



void QQgmBuLC::quitGroup(WeiXBuLC* w)
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
        if (w->wgroup[i] == groupcontainer[j].gname && groupcontainer[j].gtype == 1) {
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

void QQgmBuLC::deletePerson(int index, int acc)
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
        int k = checkIndex(acc, 1);
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



void QQgmBuLC::manageGroup(int index, WeiXBuLC* w)
{
Start:

    system("cls");
    cout << groupcontainer[index].gname << "的群管理界面" << endl;
    cout << "群成员：" << endl;
    allPerson(index);
    cout << "————1、设置管理员————" << endl;
    cout << "————2、踢出成员————" << endl;
    cout << "————3、创建子群————" << endl;
    cout << "————4、审批入群申请————" << endl;
    cout << "————5、返回————" << endl;
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
        newSmallGroup(index, w);
        goto Start;
        break;
    case 4:
        acceptJoinGroup(index);
        goto Start;
        break;
    case 5:
        return;
        break;
    default:
        break;
    }
}

void QQgmBuLC::newSmallGroup(int index, WeiXBuLC* w)
{
    system("cls");
    cout << "该群成员：" << endl;
    allPerson(index);
    int n;
    cout << "请输入要拉入子群的人数：" << endl;
    cin >> n;
    vector<int> v;
    cout << "请输入成员序号："<<endl;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }
    GroupBuLC g;
    g.gname = groupcontainer[index].gname +personcontainer[checkPerson(w->showcustomerid())].showName()+ "子群";
    g.gtype = 1;
    g.gowneracc = w->showaccountnum();
    g.gmanageracc.push_back(w->showaccountnum());
    g.gpersonacc.push_back(w->showaccountnum());
    for (int i = 0; i < n; i++) {
        g.gpersonacc.push_back(groupcontainer[index].gpersonacc[v[i] - 1]);
    }
    w->wgroup.push_back(g.gname);
    for (int i = 0; i < n; i++) {
        int k = checkIndex(groupcontainer[index].gpersonacc[v[i] - 1], 1);
        weixcontainer[k]->wgroup.push_back(g.gname);
    }
    groupcontainer.push_back(g);
    cout << "子群创建成功！" << endl;
    system("pause");
}

void QQgmBuLC::acceptJoinGroup( int index)
{
    for (int i = 0; i < applicationcontainer.size(); i++) {
        if (applicationcontainer[i].gname == groupcontainer[index].gname) {
            cout << "申请人：" << applicationcontainer[i].applicant << endl;
        }
    }
    int acc;
    cout << "请输入同意入群的申请人账号：";
    cin >> acc;
    groupcontainer[index].gpersonacc.push_back(acc);
    int k = checkIndex(acc, 1);
    weixcontainer[k]->wgroup.push_back(groupcontainer[index].gname);
    
    for (vector<JoinApplicationBuLC>::iterator it = applicationcontainer.begin(); it != applicationcontainer.end(); it++) {
        if (it->gname == groupcontainer[index].gname && it->applicant == weixcontainer[k]->showaccountnum()) {
            applicationcontainer.erase(it);
            break;
        }
    }
        
        
    
    
}

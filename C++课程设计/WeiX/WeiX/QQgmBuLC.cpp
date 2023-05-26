#include"QQgmBuLC.h"
void readApplication()
{
    ifstream ifs;
    ifs.open("application.txt", ios::in);
    //�ļ����������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
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
        cout << "�ļ�������" << endl;
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
    cout << "��������1�����Ⱥ��������" << endl;
    cout << "��������2���˳�Ⱥ��������" << endl;
    cout << "��������3������Ⱥ��������" << endl;
    cout << "��������4������Ⱥ��������" << endl;
    cout << "��������5�����ء�������" << endl;
    int select;
    cout << "����������ѡ��" ;
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
        cout << "��������Ҫ�����Ⱥ��ţ�";
        cin >> i;
        int j;//��¼Ⱥ��λ��
        for (j = 0; j < groupcontainer.size(); j++) {
            if (groupcontainer[j].gname == w->wgroup[i - 1] && groupcontainer[j].gtype == 1) {
                break;
            }
        }
        if (findIn(w->showaccountnum(), groupcontainer[j].gmanageracc)) {//�ж��Ƿ�Ϊ����Ա
            manageGroup(j, w);
        }
        else {
            cout << "�����Ǹ�Ⱥ����Ա��" << endl;
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
    cout << "��������Ҫ����QQȺ�����ƣ�" << endl;
    string gm;
    cin >> gm;
    bool flag=true;
    for (int i = 0; i < groupcontainer.size(); i++) {
        if (gm == groupcontainer[i].gname && groupcontainer[i].gtype == 1) {
            flag = false;
        }
    }
    if (!flag) {
        cout << "�������ѱ�ʹ�ã�" << endl;
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
    cout << gm << " �ɹ�������" << endl;
    system("pause");
    return;
}

void QQgmBuLC::joinGroup(WeiXBuLC* w)
{
    system("cls");
    cout << "QQ��ȡ�����Ƽ�Ⱥ" << endl;
    cout << "��������Ҫ�����Ⱥ������" << endl;
    string s;
    cin >> s;
    if (findIn(s, w->wgroup)) {
        cout << "��Ⱥ�Ѽ��룡" << endl;
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
        cout << "�޴�Ⱥ��" << endl;
        system("pause");
        return;
    }
    JoinApplicationBuLC j(s, w->showaccountnum());
    applicationcontainer.push_back(j);
    cout << "���ύ���룬��ȴ�����Ա��ˣ�" << endl;
    system("pause");
    return;
}



void QQgmBuLC::quitGroup(WeiXBuLC* w)
{
    system("cls");
    allGroup(w);
    int i;
    cout << "��������Ҫ��Ⱥ����ţ�";
    cin >> i;
    i = i - 1;
    //��Ⱥ����
    int j;//��¼Ⱥ��λ��
    for (j = 0; j < groupcontainer.size(); j++) {
        if (w->wgroup[i] == groupcontainer[j].gname && groupcontainer[j].gtype == 1) {
            break;
        }
    }
    if (w->showaccountnum() == groupcontainer[j].gowneracc) {
        cout << "����Ⱥ����������Ⱥ��" << endl;
        system("pause");
        return;
    }
    //�ӹ���Աɾ��   
    for (vector<int>::iterator it = groupcontainer[j].gmanageracc.begin(); it != groupcontainer[j].gmanageracc.end(); it++) {
        if (*it == w->showaccountnum()) {
            groupcontainer[j].gmanageracc.erase(it);
            break;
        }
    }
    //��Ⱥ��Աɾ��   
    for (vector<int>::iterator it = groupcontainer[j].gpersonacc.begin(); it != groupcontainer[j].gpersonacc.end(); it++) {
        if (*it == w->showaccountnum()) {
            groupcontainer[j].gpersonacc.erase(it);
            break;
        }
    }
   
    //���˺Ų���
    for (vector<string>::iterator it = w->wgroup.begin(); it != w->wgroup.end(); it++) {
        if (*it == w->wgroup[i]) {
            w->wgroup.erase(it);
            break;
        }
    }
    
    cout << "��Ⱥ�ɹ���" << endl;
    system("pause");
    return;
}

void QQgmBuLC::deletePerson(int index, int acc)
{
    if (findIn(acc, groupcontainer[index].gmanageracc)) {
        cout << "�����߳�����Ա��" << endl;
        system("pause");
        return;
    }
    else {
        //ɾ����Ա   
        for (vector<int>::iterator it = groupcontainer[index].gpersonacc.begin(); it != groupcontainer[index].gpersonacc.end(); it++) {
            if (*it == acc) {
                groupcontainer[index].gpersonacc.erase(it);
                break;
            }
        }
        int k = checkIndex(acc, 1);
        //��Ա��ɾ��Ⱥ
        for (vector<string>::iterator it = weixcontainer[k]->wgroup.begin(); it != weixcontainer[k]->wgroup.end(); it++) {
            if (*it == groupcontainer[index].gname) {
                weixcontainer[k]->wgroup.erase(it);
                break;
            }
        }
        cout << "���߳��ó�Ա��" << endl;
        system("pause");
        return;
    }
}



void QQgmBuLC::manageGroup(int index, WeiXBuLC* w)
{
Start:

    system("cls");
    cout << groupcontainer[index].gname << "��Ⱥ�������" << endl;
    cout << "Ⱥ��Ա��" << endl;
    allPerson(index);
    cout << "��������1�����ù���Ա��������" << endl;
    cout << "��������2���߳���Ա��������" << endl;
    cout << "��������3��������Ⱥ��������" << endl;
    cout << "��������4��������Ⱥ���롪������" << endl;
    cout << "��������5�����ء�������" << endl;
    int select;
    int j;
    cout << "����������ѡ��";
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "��������ѡ���Ⱥ��Ա��ţ�";
        cin >> j;
        if (groupcontainer[index].gpersonacc[j - 1] == w->showaccountnum()) {
            cout << "���Ѿ��ǹ���Ա" << endl;
            system("pause");
        }
        else {
            groupcontainer[index].gmanageracc.push_back(groupcontainer[index].gpersonacc[j - 1]);
            cout << "���óɹ���" << endl;
            system("pause");
        }
        goto Start;
        break;
    case 2:
        cout << "��������ѡ���Ⱥ��Ա��ţ�";
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
    cout << "��Ⱥ��Ա��" << endl;
    allPerson(index);
    int n;
    cout << "������Ҫ������Ⱥ��������" << endl;
    cin >> n;
    vector<int> v;
    cout << "�������Ա��ţ�"<<endl;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }
    GroupBuLC g;
    g.gname = groupcontainer[index].gname +personcontainer[checkPerson(w->showcustomerid())].showName()+ "��Ⱥ";
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
    cout << "��Ⱥ�����ɹ���" << endl;
    system("pause");
}

void QQgmBuLC::acceptJoinGroup( int index)
{
    for (int i = 0; i < applicationcontainer.size(); i++) {
        if (applicationcontainer[i].gname == groupcontainer[index].gname) {
            cout << "�����ˣ�" << applicationcontainer[i].applicant << endl;
        }
    }
    int acc;
    cout << "������ͬ����Ⱥ���������˺ţ�";
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

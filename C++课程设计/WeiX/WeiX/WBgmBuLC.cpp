#include"WBgmBuLC.h"

void WBgmBuLC::GMmeun(WeiXBuLC* w)
{
Start:
    system("cls");
    int i;
    allGroup(w);
    cout << "��������1���Ƽ�������Ⱥ��������" << endl;
    cout << "��������2���˳�Ⱥ��������" << endl;
    cout << "��������3������Ⱥ��������" << endl;
    cout << "��������4������Ⱥ��������" << endl;
    cout << "��������5�����ء�������" << endl;
    int select;
    cout << "����������ѡ��";
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
            if (groupcontainer[j].gname == w->wgroup[i - 1] && groupcontainer[j].gtype == 3) {
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
    cout << "��������Ҫ����΢��Ⱥ�����ƣ�" << endl;
    string gm;
    cin >> gm;
    bool flag = true;
    for (int i = 0; i < groupcontainer.size(); i++) {
        if (gm == groupcontainer[i].gname && groupcontainer[i].gtype == 3) {
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
    g.gtype = 3;
    g.gowneracc = w->showaccountnum();
    g.gmanageracc.push_back(w->showaccountnum());
    g.gpersonacc.push_back(w->showaccountnum());
    groupcontainer.push_back(g);
    w->wgroup.push_back(g.gname);
    cout << gm << " �ɹ�������" << endl;
    system("pause");
    return;
}

void WBgmBuLC::joinGroup(WeiXBuLC* w)
{
    system("cls");
    cout << "΢�������Ƽ��Ƽ�Ⱥ" << endl;
    cout << "���ĺ��ѣ�" << endl;
    w->weixfm->allFriend(w);
    cout << "�����ڵ�Ⱥ��" << endl;
    allGroup(w);
    
    int n, m;
    cout << "������Ҫ�Ƽ���Ⱥ��������ţ�" << endl;
    cin >> n;
    n = n - 1;
    cout << "������Ҫ�Ƽ��ĺ��ѣ�������ţ�" << endl;
    cin >> m;
    m = m - 1;
    int j;//Ⱥ��λ��
    for (j = 0; j< groupcontainer.size(); j++) {
        if (groupcontainer[j].gname == w->wgroup[n] && groupcontainer[j].gtype == 3) {
            break;
        }
    }
    groupcontainer[j].gpersonacc.push_back(w->wfriend[m]);
    int k = checkIndex(w->wfriend[m], 3);
    weixcontainer[k]->wgroup.push_back(w->wgroup[n]);
    cout << "�Ƽ��ɹ���" << endl;
    system("pause");
    return;
}



void WBgmBuLC::quitGroup(WeiXBuLC* w)
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
        if (w->wgroup[i] == groupcontainer[j].gname && groupcontainer[j].gtype == 3) {
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

void WBgmBuLC::deletePerson(int index, int acc)
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
        int k = checkIndex(acc, 3);
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

void WBgmBuLC::manageGroup(int index, WeiXBuLC* w)
{
Start:
    system("cls");
    cout << groupcontainer[index].gname << "��Ⱥ�������" << endl;
    cout << "Ⱥ��Ա��" << endl;
    allPerson(index);
    cout << "��������1�����ù���Ա��������" << endl;
    cout << "��������2���߳���Ա��������" << endl;
    cout << "��������3�����ء�������" << endl;
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
        return;
        break;
    default:
        break;
    }
}

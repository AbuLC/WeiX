#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctime>
#include"PersonBuLC.h"
#include"WeiXBuLC.h"
#include"QQBuLC.h"
#include"WeChatBuLC.h"
#include"WeiBlogBuLC.h"
#include"WeiBusinessBuLC.h"

using namespace std;

//�����û�
vector<PersonBuLC>personcontainer;
//�����˺�
vector<WeiXBuLC*>weixcontainer;
//����Ⱥ
vector<GroupBuLC>groupcontainer;
vector<JoinApplicationBuLC> applicationcontainer;
void readApplication();
void saveApplication();
//��ǰQQ��¼�˺�
int QQ_now=0;
//��ǰ΢�ŵ�¼�˺�
int WeChat_now=0;
//��ǰ΢����¼�˺�
int WeiBlog_now=0;
//��ǰ΢�̵�¼�˺�
int WeiBusiness_now=0;
//��ǰ��¼�˺�״̬
int type_now=0;


//���ļ���ȡ�û���Ϣ
void readFilePerson(vector<PersonBuLC>& v);
//�����û��ļ���Ϣ
void saveFilePerson(vector<PersonBuLC>& v);
//���ļ���ȡ�˺���Ϣ
void readFileWeiX(vector<WeiXBuLC*>& v);
//�����˺���Ϣ
void saveFileWeiX(vector<WeiXBuLC*>& v);
//���ļ��ж�ȡȺ��Ϣ
void readFileGroup(vector<GroupBuLC>& v);
//����Ⱥ��Ϣ
void saveFileGroup(vector<GroupBuLC>& v);

//������
void meun();

//�û���¼
void login();
//��¼�ض��˺�
void login_weix(int type,int acc);


//ע�����û�
void newWeiX();
//���ո�ָ��ַ���
vector<string> split(string str);
//�����֤�����û�
int checkPerson(string id);
//�˳�����
void weiXExit();

//���ļ���ȡ�û���Ϣ
void readFilePerson(vector<PersonBuLC>& v) {
    ifstream ifs;
    ifs.open("person.txt", ios::in);
    //�ļ����������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }
    string loc, nam, id, pho;
    int qq, wechat, weiblog, weibusiness;
    while (ifs >> nam && ifs >> loc && ifs >> id && ifs >> pho&&ifs>>qq&&ifs>>wechat&&ifs>>weiblog&&ifs>>weibusiness) {
        PersonBuLC p(loc, nam, id, pho,qq,wechat,weiblog,weibusiness);
        v.push_back(p);
    }
    ifs.close();
}
//�����û��ļ���Ϣ
void saveFilePerson(vector<PersonBuLC>& v) {
    ofstream ofs;
    ofs.open("person.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ�������" << endl;
        ofs.close();
        return;
    }
    for (vector<PersonBuLC>::iterator it = v.begin(); it != v.end(); it++) {
        ofs << it->showName() << " " << it->showlocation() << " " << it->showID() << " " << it->showPhone() <<" "<<it->showQQid() <<" "<<it->showWeChatid()<<" "<<it->showWeiBlogid()<<" "<<it->showWeiBusinessid()<< endl;
    }
    ofs.close();
}
//���ļ���ȡ�˺���Ϣ
void readFileWeiX(vector<WeiXBuLC*>& v) {
    ifstream ifs;
    WeiXBuLC* w;
        ifs.open("weix.txt", ios::in);
        //�ļ����������
        if (!ifs.is_open())
        {
            cout << "�ļ�������" << endl;
            ifs.close();
            return;
        }
        string* line = new string;
        vector<string> vl;//���ÿһ�е���Ϣ
        while (getline(ifs, *line)) {
            vl.push_back(*line);
        }
        for (vector<string>::iterator it = vl.begin(); it != vl.end(); it++) {
            vector<string> str;//���水�ո�ֿ����ִ�
            str = split(*it);
            switch (atoi(str[1].c_str())) {
            case 1:
                w = new QQBuLC;
                break;
            case 2:
                w = new WeChatBuLC;
               
                break;
            case 3:
                w = new WeiBlogBuLC;
                break;
            case 4:
                w = new WeiBusinessBuLC;
                break;
            default:
                w = new QQBuLC;
                break;
            }
            w->setaccountnum(atoi(str[0].c_str()));
            w->settype(atoi(str[1].c_str()));
            w->setpersonid(str[2]);
            w->setpassword(str[3]);
            w->time = str[4];
            
            int i = 6;
            for (i = 6; str[i] != "Ⱥ"; i++) {
                w->wfriend.push_back(atoi(str[i].c_str()));
            }
            i = i + 1;
            while (i < str.size()) {
                w->wgroup.push_back(str[i]);
                i++;
            }
            v.push_back(w);
        }
    
   
    ifs.close();
}
//�����˺���Ϣ
void saveFileWeiX(vector<WeiXBuLC*>& v) {
    ofstream ofs;
    ofs.open("weix.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ�������" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        ofs << v[i]->showaccountnum()<< " " << v[i]->showtype() << " " << v[i]->showcustomerid() << " " <<v[i]->outpassword()<<" " << v[i]->time<<" ";
        ofs << "����" << " ";
        if (!v[i]->wfriend.empty()) {
            for (int j = 0; j < v[i]->wfriend.size(); j++) {
                ofs << v[i]->wfriend[j] << " ";
            }
        }
        ofs << "Ⱥ" ;
        if (!v[i]->wgroup.empty()) {
            ofs << " ";
            for (int j = 0; j < v[i]->wgroup.size() - 1; j++) {
                ofs << v[i]->wgroup[j] << " ";
            }
            ofs << v[i]->wgroup[v[i]->wgroup.size() - 1] ;
        }
        ofs << endl;
        
    }
    ofs.close();
}

//���ļ��ж�ȡȺ��Ϣ
void readFileGroup(vector<GroupBuLC>& v) {
    ifstream ifs;
    ifs.open("group.txt", ios::in);
    //�ļ����������
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }
    string *gline=new string;
    vector<string> vl;//���ÿһ�е���Ϣ
    while (getline(ifs, *gline)) {
        vl.push_back(*gline);
    }
    for (int i = 0; i < vl.size(); i++) {
        vector<string> str;//���水�ո�ֿ����ִ�
        str = split(vl[i]);
        GroupBuLC g;
        g.gname = str[0];
        g.gtype = atoi(str[1].c_str());
        g.gowneracc = atoi(str[2].c_str());
        int j = 4;
        while (str[j] != "Ⱥ��Ա") {
            g.gmanageracc.push_back(atoi(str[j].c_str()));
            j++;
        }
        j++;
        while (j < str.size()) {
            g.gpersonacc.push_back(atoi(str[j].c_str()));
            j++;
        }
        v.push_back(g);
    }
    ifs.close();
}
//����Ⱥ��Ϣ
void saveFileGroup(vector<GroupBuLC>& v) {
    ofstream ofs;
    ofs.open("group.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ�������" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        ofs << v[i].gname << " " << v[i].gtype << " " << v[i].gowneracc << " ";
        ofs << "����Ա" << " ";
        for (int j = 0; j < v[i].gmanageracc.size(); j++) {
            ofs << v[i].gmanageracc[j] << " ";
        }
        ofs << "Ⱥ��Ա" << " ";
        for (int j = 0; j < v[i].gpersonacc.size() - 1; j++) {
            ofs << v[i].gpersonacc[j] << " ";
        }
        ofs << v[i].gpersonacc[v[i].gpersonacc.size() - 1] << endl;
    }
    ofs.close();
}




//���ո�ָ��ַ���
vector<string> split(string str) {
    int size = str.size();
    vector<string> ans;
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == ' '){
            ans.push_back(str.substr(j, i - j));
            j = i + 1;
        }
    }
    ans.push_back(str.substr(j, size - j));
    return ans;
}
//ע�����û�
void newWeiX() {
    cout << "��ѡ��Ҫע���ƽ̨��" << endl;
    cout << "1��QQ 2��΢�� 3��΢�� 4��΢��" << endl;
    cout << "�����룺" << endl;
    int n;
    cin >> n;
    WeiXBuLC* w;
    switch (n)
    {
    case 1:
        w = new QQBuLC;
        break;
    case 2:
        w = new WeChatBuLC;
        break;
    case 3:
        w = new WeiBlogBuLC;
        break;
    case 4:
        w = new WeiBusinessBuLC;
        break;
    default:
        w = NULL;
        break;
    }
    int maxacc=0;
    for (int i = 0; i < weixcontainer.size(); i++) {
        if (weixcontainer[i]->showaccountnum() > maxacc) {
            maxacc = weixcontainer[i]->showaccountnum();
        }
    }
    w->setaccountnum(maxacc+ 1);
    w->settype(n);
    string id;
    int index;
    cout << "������������֤�ţ�";
    cin >> id;
    index = checkPerson(id);
    if (index == -1) {
        cout << "��δ���ڴ�ƽ̨ע����˺ţ������Ƹ�����Ϣ" << endl;
        string nam, loc, pho;
        cout << "������������ʵ������";
        cin >> nam;
        cout << "�������������ڵأ�";
        cin >> loc;
        cout << "���������ĵ绰��" ;
        cin >> pho;
        PersonBuLC p(loc,nam,id,pho,0,0,0,0);
        p.setacc(n, w->showaccountnum());
        personcontainer.push_back(p);
        w->setpersonid(id);
        cout << "������Ϣ���Ƴɹ���" << endl;
    }
    else {
        
        switch (n)
        {
        case 1:
            if (personcontainer[index].showQQid() != 0) {
                cout << "QQ�˺���ע�� " << personcontainer[index].showQQid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showWeChatid() != 0) {
                    cout << "��⵽��ע���΢���˺ţ�QQ�˺�����΢���˺Ű�" << endl;
                }
                personcontainer[index].setacc(n, w->showaccountnum());
                w->setpersonid(id);
            }
            break;
        case 2:
            if (personcontainer[index].showWeChatid() != 0) {
                cout << "΢���˺��ѱ�ע�� " << personcontainer[index].showWeChatid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "��⵽ע���QQ�˺ţ�΢���˺�����QQ�˺Ű�" << endl;
                }
                personcontainer[index].setacc(n, w->showaccountnum());
                w->setpersonid(id);
            }
            break;
        case 3:
            if (personcontainer[index].showWeiBlogid() != 0) {
                cout << "΢���˺��ѱ�ע�� " << personcontainer[index].showWeiBlogid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "��ע���QQ�˺ţ�΢���˺���QQ����ID" << endl;
                    w->setaccountnum(personcontainer[index].showQQid());
                    personcontainer[index].setacc(n, w->showaccountnum());
                    w->setpersonid(id);
                }
                else {                 
                    personcontainer[index].setacc(n, w->showaccountnum());
                    w->setpersonid(id);
                }
            }
            break;
        case 4:
            if (personcontainer[index].showWeiBusinessid() != 0) {
                cout << "��ע���΢���˺� " << personcontainer[index].showWeiBusinessid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "��ע���QQ�˺ţ�΢���˺���QQ����ID" << endl;                   
                    w->setaccountnum(personcontainer[index].showQQid());
                    personcontainer[index].setacc(n, w->showaccountnum());
                    w->setpersonid(id);
                }
                else {
                    personcontainer[index].setacc(n, w->showaccountnum());
                    w->setpersonid(id);
                }
            }
            break;
        default:
            break;
        }
    }
    //��ȡ����
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string year, mon, day, t;
    year = to_string(1900 + ltm->tm_year);
    if ((ltm->tm_mon + 1) >=10) {
        mon = to_string(ltm->tm_mon + 1);
    }
    else {
        mon = "0" + to_string(ltm->tm_mon + 1);
    }
    if (ltm->tm_mday >= 10) {
        day = to_string(ltm->tm_mday);
    }
    else {
        day = "0" + to_string(ltm->tm_mday);
    }
    t = year + mon + day;
    w->time = t;
    //��������
SETPASSWORD:
    cout << "���������룺";
    string pass1;
    cin >> pass1;
    cout << "���ٴ��������룺";
    string pass2;
    cin >> pass2;
    if (pass1 != pass2) {
        cout << "�����������������" << endl;
        goto SETPASSWORD;
    }
    else {
        w->setpassword(pass1);
    }
    cout << "ע��ɹ��������µ�¼��" << endl;
    cout << "�˺�Ϊ" << w->showaccountnum()<<endl;
    weixcontainer.push_back(w);
    system("pause");
    login();
    return;
}



//������
void meun() {
    system("cls");
    cout << "����������������������������������������" << endl;
    cout << "������������1����¼����������������" << endl;
    cout << "������������2��ע�ᡪ��������������" << endl;
    cout << "������������3���˳�����������������" << endl;
    cout << "����������ѡ��";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        login();
        break;
    case 2:
        newWeiX();
        break;
    case 3:
        weiXExit();
    default:
        break;
    }
}
//�˳�����
void weiXExit() {
    system("cls");
    saveFilePerson(personcontainer);
    saveFileWeiX(weixcontainer);
    saveFileGroup(groupcontainer);
    cout << "��лʹ�ã�" << endl;
    system(0);
    exit(0);
}
//�û���¼
void login() {
    system("cls");
    int acc;
    string pass;
    int i;
    int n,t;
Account:
    cout << "��ѡ����Ҫ��¼��ƽ̨��" << endl << "1��QQ  2��΢��  3��΢��  4��΢��" << endl;
    cin >> t;
    cout << "�������˺ţ�" << endl;
    cin >> acc;
    for (i = 0; i < weixcontainer.size(); i++) {
        if (weixcontainer[i]->showaccountnum() == acc&&weixcontainer[i]->showtype()==t) {
            goto Password;
        }
     }
     cout << "�˺Ų����ڣ�" << endl;
     cout << "1����������" << endl;
     cout << "2���˳�" << endl;
     cout << "�����룺";
     cin >> n;
     switch (n)
     {
     case 1:
         goto Account;
         break;
     case 2:
         weiXExit();
         break;
     default:
         break;
     }
     system("pause");
    
Password:
    cout << "���룺" << endl;
    cin >> pass;
    if (pass == weixcontainer[i]->outpassword()) {
        login_weix(weixcontainer[i]->showtype(), weixcontainer[i]->showaccountnum());
        return;
    }
    else {
        cout << "�����������" << endl;
        cout << "1��������������" << endl;
        cout << "2�����������˺�" << endl;
        cout << "3���˳�" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            goto Password;
            break;
        case 2:
            goto Account;
            break;
        case 3:
            weiXExit();
            break;
        default:
            break;
        }
    }
}
//��¼�ض��˺�
void login_weix(int type, int acc) {
    for (int i = 0; i < weixcontainer.size(); i++) {
        if (weixcontainer[i]->showaccountnum() == acc && weixcontainer[i]->showtype() == type) {
            weixcontainer[i]->loginSucceed();
            return;
        }
    }
}



int main() {
    readFilePerson(personcontainer);
    readFileWeiX(weixcontainer);
    readFileGroup(groupcontainer);
    readApplication();
    while (1) {
        meun();
        
        while (type_now != 0 && (QQ_now != 0 || WeChat_now != 0 || WeiBlog_now != 0 || WeiBusiness_now != 0)) {
            switch (type_now)
            {
            case 1:
                login_weix(type_now, QQ_now);
                break;
            case 2:
                login_weix(type_now, WeChat_now);
                break;
            case 3:
                login_weix(type_now, WeiBlog_now);
                break;
            case 4:
                login_weix(type_now, WeiBusiness_now);
                break;
            default:
                break;
            }
        }
    }
    
    weiXExit();
    return 0;
}
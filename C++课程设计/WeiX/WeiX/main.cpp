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

//所有用户
vector<PersonBuLC>personcontainer;
//所有账号
vector<WeiXBuLC*>weixcontainer;
//所有群
vector<GroupBuLC>groupcontainer;
vector<JoinApplicationBuLC> applicationcontainer;
void readApplication();
void saveApplication();
//当前QQ登录账号
int QQ_now=0;
//当前微信登录账号
int WeChat_now=0;
//当前微博登录账号
int WeiBlog_now=0;
//当前微商登录账号
int WeiBusiness_now=0;
//当前登录账号状态
int type_now=0;


//从文件读取用户信息
void readFilePerson(vector<PersonBuLC>& v);
//保存用户文件信息
void saveFilePerson(vector<PersonBuLC>& v);
//从文件读取账号信息
void readFileWeiX(vector<WeiXBuLC*>& v);
//保存账号信息
void saveFileWeiX(vector<WeiXBuLC*>& v);
//从文件中读取群信息
void readFileGroup(vector<GroupBuLC>& v);
//保存群信息
void saveFileGroup(vector<GroupBuLC>& v);

//主界面
void meun();

//用户登录
void login();
//登录特定账号
void login_weix(int type,int acc);


//注册新用户
void newWeiX();
//按空格分割字符串
vector<string> split(string str);
//按身份证查找用户
int checkPerson(string id);
//退出函数
void weiXExit();

//从文件读取用户信息
void readFilePerson(vector<PersonBuLC>& v) {
    ifstream ifs;
    ifs.open("person.txt", ios::in);
    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
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
//保存用户文件信息
void saveFilePerson(vector<PersonBuLC>& v) {
    ofstream ofs;
    ofs.open("person.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件不存在" << endl;
        ofs.close();
        return;
    }
    for (vector<PersonBuLC>::iterator it = v.begin(); it != v.end(); it++) {
        ofs << it->showName() << " " << it->showlocation() << " " << it->showID() << " " << it->showPhone() <<" "<<it->showQQid() <<" "<<it->showWeChatid()<<" "<<it->showWeiBlogid()<<" "<<it->showWeiBusinessid()<< endl;
    }
    ofs.close();
}
//从文件读取账号信息
void readFileWeiX(vector<WeiXBuLC*>& v) {
    ifstream ifs;
    WeiXBuLC* w;
        ifs.open("weix.txt", ios::in);
        //文件不存在情况
        if (!ifs.is_open())
        {
            cout << "文件不存在" << endl;
            ifs.close();
            return;
        }
        string* line = new string;
        vector<string> vl;//存放每一行的信息
        while (getline(ifs, *line)) {
            vl.push_back(*line);
        }
        for (vector<string>::iterator it = vl.begin(); it != vl.end(); it++) {
            vector<string> str;//储存按空格分开的字串
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
            for (i = 6; str[i] != "群"; i++) {
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
//保存账号信息
void saveFileWeiX(vector<WeiXBuLC*>& v) {
    ofstream ofs;
    ofs.open("weix.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件不存在" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        ofs << v[i]->showaccountnum()<< " " << v[i]->showtype() << " " << v[i]->showcustomerid() << " " <<v[i]->outpassword()<<" " << v[i]->time<<" ";
        ofs << "好友" << " ";
        if (!v[i]->wfriend.empty()) {
            for (int j = 0; j < v[i]->wfriend.size(); j++) {
                ofs << v[i]->wfriend[j] << " ";
            }
        }
        ofs << "群" ;
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

//从文件中读取群信息
void readFileGroup(vector<GroupBuLC>& v) {
    ifstream ifs;
    ifs.open("group.txt", ios::in);
    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    string *gline=new string;
    vector<string> vl;//存放每一行的信息
    while (getline(ifs, *gline)) {
        vl.push_back(*gline);
    }
    for (int i = 0; i < vl.size(); i++) {
        vector<string> str;//储存按空格分开的字串
        str = split(vl[i]);
        GroupBuLC g;
        g.gname = str[0];
        g.gtype = atoi(str[1].c_str());
        g.gowneracc = atoi(str[2].c_str());
        int j = 4;
        while (str[j] != "群成员") {
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
//保存群信息
void saveFileGroup(vector<GroupBuLC>& v) {
    ofstream ofs;
    ofs.open("group.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件不存在" << endl;
        ofs.close();
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        ofs << v[i].gname << " " << v[i].gtype << " " << v[i].gowneracc << " ";
        ofs << "管理员" << " ";
        for (int j = 0; j < v[i].gmanageracc.size(); j++) {
            ofs << v[i].gmanageracc[j] << " ";
        }
        ofs << "群成员" << " ";
        for (int j = 0; j < v[i].gpersonacc.size() - 1; j++) {
            ofs << v[i].gpersonacc[j] << " ";
        }
        ofs << v[i].gpersonacc[v[i].gpersonacc.size() - 1] << endl;
    }
    ofs.close();
}




//按空格分割字符串
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
//注册新用户
void newWeiX() {
    cout << "请选择要注册的平台：" << endl;
    cout << "1、QQ 2、微信 3、微博 4、微商" << endl;
    cout << "请输入：" << endl;
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
    cout << "请输入个人身份证号：";
    cin >> id;
    index = checkPerson(id);
    if (index == -1) {
        cout << "您未曾在此平台注册过账号，请完善个人信息" << endl;
        string nam, loc, pho;
        cout << "请输入您的真实姓名：";
        cin >> nam;
        cout << "请输入您的所在地：";
        cin >> loc;
        cout << "请输入您的电话：" ;
        cin >> pho;
        PersonBuLC p(loc,nam,id,pho,0,0,0,0);
        p.setacc(n, w->showaccountnum());
        personcontainer.push_back(p);
        w->setpersonid(id);
        cout << "个人信息完善成功！" << endl;
    }
    else {
        
        switch (n)
        {
        case 1:
            if (personcontainer[index].showQQid() != 0) {
                cout << "QQ账号已注册 " << personcontainer[index].showQQid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showWeChatid() != 0) {
                    cout << "检测到已注册过微信账号，QQ账号已与微信账号绑定" << endl;
                }
                personcontainer[index].setacc(n, w->showaccountnum());
                w->setpersonid(id);
            }
            break;
        case 2:
            if (personcontainer[index].showWeChatid() != 0) {
                cout << "微信账号已被注册 " << personcontainer[index].showWeChatid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "检测到注册过QQ账号，微信账号已与QQ账号绑定" << endl;
                }
                personcontainer[index].setacc(n, w->showaccountnum());
                w->setpersonid(id);
            }
            break;
        case 3:
            if (personcontainer[index].showWeiBlogid() != 0) {
                cout << "微博账号已被注册 " << personcontainer[index].showWeiBlogid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "已注册过QQ账号，微博账号与QQ共享ID" << endl;
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
                cout << "已注册过微商账号 " << personcontainer[index].showWeiBusinessid() << endl;
                system("pause");
                meun();
                return;
            }
            else {
                if (personcontainer[index].showQQid() != 0) {
                    cout << "已注册过QQ账号，微商账号与QQ共享ID" << endl;                   
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
    //获取日期
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
    //设置密码
SETPASSWORD:
    cout << "请输入密码：";
    string pass1;
    cin >> pass1;
    cout << "请再次输入密码：";
    string pass2;
    cin >> pass2;
    if (pass1 != pass2) {
        cout << "密码错误！请重新设置" << endl;
        goto SETPASSWORD;
    }
    else {
        w->setpassword(pass1);
    }
    cout << "注册成功！请重新登录！" << endl;
    cout << "账号为" << w->showaccountnum()<<endl;
    weixcontainer.push_back(w);
    system("pause");
    login();
    return;
}



//主界面
void meun() {
    system("cls");
    cout << "————————————————————" << endl;
    cout << "——————1、登录————————" << endl;
    cout << "——————2、注册————————" << endl;
    cout << "——————3、退出————————" << endl;
    cout << "请输入您的选择：";
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
//退出函数
void weiXExit() {
    system("cls");
    saveFilePerson(personcontainer);
    saveFileWeiX(weixcontainer);
    saveFileGroup(groupcontainer);
    cout << "感谢使用！" << endl;
    system(0);
    exit(0);
}
//用户登录
void login() {
    system("cls");
    int acc;
    string pass;
    int i;
    int n,t;
Account:
    cout << "请选择您要登录的平台：" << endl << "1、QQ  2、微信  3、微博  4、微商" << endl;
    cin >> t;
    cout << "请输入账号：" << endl;
    cin >> acc;
    for (i = 0; i < weixcontainer.size(); i++) {
        if (weixcontainer[i]->showaccountnum() == acc&&weixcontainer[i]->showtype()==t) {
            goto Password;
        }
     }
     cout << "账号不存在！" << endl;
     cout << "1、重新输入" << endl;
     cout << "2、退出" << endl;
     cout << "请输入：";
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
    cout << "密码：" << endl;
    cin >> pass;
    if (pass == weixcontainer[i]->outpassword()) {
        login_weix(weixcontainer[i]->showtype(), weixcontainer[i]->showaccountnum());
        return;
    }
    else {
        cout << "密码输入错误！" << endl;
        cout << "1、重新输入密码" << endl;
        cout << "2、重新输入账号" << endl;
        cout << "3、退出" << endl;
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
//登录特定账号
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
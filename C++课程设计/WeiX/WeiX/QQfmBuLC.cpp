#include"QQfmBuLC.h"

void QQfmBuLC::FMmeun(WeiXBuLC* w)
{
Start:

	system("cls");
	allFriend(w);
	cout << endl;
	cout << "��������1����Ӻ��ѡ�������" << endl;
	cout << "��������2����������˺ŵĺ��ѡ�������" << endl;
	cout << "��������3��ɾ�����ѡ�������" << endl;
	cout << "��������4�����ء�������" << endl;
	int select=0;
	cout << "����������ѡ��" << endl;
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
	cout << "������Ҫ��Ӻ��ѵ��˺ţ�" << endl;
	cin >> friendacc;
	int index=checkIndex(friendacc, 1);
	if (index == -1) {
		cout << "�˺��������" << endl;
		system("pause");
		goto Start;
	}
	for (int i = 0; i < w->wfriend.size(); i++) {
		if (w->wfriend[i] == friendacc) {
			cout << "�����ѱ���ӣ�" << endl;
			system("pause");
			goto Start;
		}
	}
	w->wfriend.push_back(friendacc);
	weixcontainer[index]->wfriend.push_back(w->showaccountnum());
	cout << "��������ӳɹ���" << endl;
	system("pause");
}

void QQfmBuLC::addNewFriend2(WeiXBuLC* w)
{
	system("cls");
	int otheracc;//�����������˺�
	int index;//�˺��������е�λ��
	vector<int> newfriend;//�º�������
	int count=-1;//�º�������
	//΢�ź���
	if (personcontainer[checkPerson(w->showcustomerid())].showWeChatid() == 0) {
		cout << "΢����δע�ᣡ" << endl;
	}
	else {
		cout << "����΢�ź��ѣ�" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeChatid();
		index = checkIndex(otheracc, 2);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//΢�ź����������е�λ��
			k = checkIndex(weixcontainer[index]->wfriend[i], 2);
			//�жϸú����Ƿ�ͨQQ�˺�
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//�ж��Ƿ��Ѿ����
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "��" << newfriend[count]
						<< "  ����΢�ź���" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
				
			}
		}
	}
	//΢������
	if (personcontainer[checkPerson(w->showcustomerid())].showWeiBlogid() == 0) {
		cout << "΢����δע�ᣡ" << endl;
	}
	else {
		cout << "����΢�����ѣ�" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeiBlogid();
		index = checkIndex(otheracc, 3);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//΢�������������е�λ��
			k = checkIndex(weixcontainer[index]->wfriend[i], 3);
			//�жϸú����Ƿ�ͨQQ�˺�
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//�ж��Ƿ��Ѿ����
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "��" << newfriend[count]
						<< "  ����΢������" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
			}
		}
	}
	//΢�̺���
	if (personcontainer[checkPerson(w->showcustomerid())].showWeiBusinessid() == 0) {
		cout << "΢����δע�ᣡ" << endl;
	}
	else {
		cout << "����΢�̺��ѣ�" << endl;
		otheracc = personcontainer[checkPerson(w->showcustomerid())].showWeiBusinessid();
		index = checkIndex(otheracc, 4);
		for (int i = 0; i < weixcontainer[index]->wfriend.size(); i++) {
			int k;//΢�������������е�λ��
			k = checkIndex(weixcontainer[index]->wfriend[i], 4);
			//�жϸú����Ƿ�ͨQQ�˺�
			if (personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid() != 0) {
				//�ж��Ƿ��Ѿ����
				if (!findIn(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid(), w->wfriend)) {
					newfriend.push_back(personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showQQid());
					count++;
					cout << count + 1 << "��" << newfriend[count]
						<< "  ����΢�̺���" << weixcontainer[k]->showaccountnum()
						<< personcontainer[checkPerson(weixcontainer[k]->showcustomerid())].showName() << endl;
				}
			}
		}
	}



	cout << endl << "��ѡ����Ҫ��ӵĺ�����ţ�";
	
	int n,m;
	cin >> n;
	n = n - 1;
	w->wfriend.push_back(newfriend[n]);//�����˺Ų���
	int j;
	j = checkIndex(newfriend[n], 1);//�����˺Ų���
	weixcontainer[j]->wfriend.push_back(w->showaccountnum());
	cout << "��ӳɹ���" << endl;
	system("pause");
	return;

}

void QQfmBuLC::deleteFriend(WeiXBuLC* w)
{
	int n;
	cout << "������Ҫɾ���ĺ�����ţ�" << endl;
	cin >> n;
	n = n - 1;
	//�Ժ����˺Ų���
	{
		int index = checkIndex(w->wfriend[n], 1);
		for (vector<int>::iterator it = weixcontainer[index]->wfriend.begin(); it != weixcontainer[index]->wfriend.end(); it++) {
			if (*it == w->showaccountnum()) {
				weixcontainer[index]->wfriend.erase(it);
				break;
			}
		}

	}
	//�Ա����˺Ų���
	{
		for (vector<int>::iterator it = w->wfriend.begin(); it != w->wfriend.end(); it++) {
			if (*it == w->wfriend[n]) {
				w->wfriend.erase(it);
				break;
			}
		}
	}
	cout << "ɾ�����ѳɹ���" << endl;
	system("pause");
	return;

}

void QQfmBuLC::allFriend(WeiXBuLC* w)
{
	system("cls");
	cout << w->showaccountnum() << "�ĺ����б�" << endl;
	for (int i = 0; i < w->wfriend.size(); i++) {
		cout <<i+1<<"��" << w->wfriend[i] <<" " << personcontainer[checkPerson(weixcontainer[checkIndex(w->wfriend[i], 1)]->showcustomerid())].showName() << endl;
	}
	cout << endl;
}

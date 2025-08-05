#include "cRegisterWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[10];
extern userNum;
USER newUser = {0};

int RegisterWin_init(){
	int res = 0;
	CWIN registerwin = {21,2,50,15};
	
	CONTROL title = {LABEL,38,4,"��  ��  ע  ��"};

	CONTROL account = {LABEL,25,7,"�ֻ����룺"};
	CONTROL keyword = {LABEL,25,10,"��֤�룺"};

	CONTROL keyBtn = {BUTTON,60,6,"��ȡ��֤��",10,1};
	CONTROL okBtn = {BUTTON,30,15,"ȷ    ��",8,1};
	CONTROL escBtn = {BUTTON,49,15,"��    ��",8,1};

	CONTROL accEdit = {EDIT,35,6,"",20,1,11,3,1};
	CONTROL keyEdit = {EDIT,35,9,"",20,1,10,3,1};

	addControl(&registerwin,&title);
	addControl(&registerwin,&account);
	addControl(&registerwin,&keyword);
	addControl(&registerwin,&accEdit);
	addControl(&registerwin,&keyBtn);
	addControl(&registerwin,&keyEdit);
	addControl(&registerwin,&okBtn);
	addControl(&registerwin,&escBtn);

	CWIN errorwin = {30,6,30,10};
	CONTROL error1 = {LABEL,35,11,"����ȷ�����˺ź���֤�룡"};

	paintWindow(&registerwin);
	winRun(&registerwin);

	if(registerwin.flag == 4){
		//��֤��
		srand(time(NULL));
		int i = rand() % 900000;
		char code[10];
		sprintf(code, "%d", i);
		gotoxy(35,13);
		cout<<"��֤��Ϊ��"<<code<<endl;
		winRun(&registerwin);
		if(registerwin.flag == 6){
			//ȷ��
			res = RegisterSeed(registerwin.arr[3].context,registerwin.arr[5].context,code);
			if(res == 1){	
				return 2;
			}else if(res == 2){
				return 1;			
			}
		}else if(registerwin.flag == 7){
			//�˳�
			return 0;
		}
	}else if(registerwin.flag == 6){
		//ȷ��
		addControl(&errorwin,&error1);
		paintWindow(&errorwin);
		Sleep(1500);
		return 1;
	}else if(registerwin.flag == 7){
		//�˳�
		return 0;
	}
	return 0;
}

int RegisterSeed(char name[20],char seed[20],char reseed[20]){
	CWIN errorwin = {30,6,30,10};
	CONTROL error1 = {LABEL,35,11,"����ȷ�����˺ź���֤�룡"};
	CONTROL error2 = {LABEL,35,11,"�˺��Ѵ��ڣ�"};

	int p = 123456;
	char pwd[10];
	sprintf(pwd, "%d", p);
		if(strcmp(name,newUser.username) == 0){
			addControl(&errorwin,&error2);
			paintWindow(&errorwin);
			Sleep(2000);
			return 2;
		}else if(strcmp(seed,reseed) == 0 && name[0] == '1' && strlen(name) == 11){
		strcpy(newUser.username,name);
		strcpy(newUser.password,pwd);
		newUser.role = 3;
		arr[userNum++] = newUser;
		return 1;
	}else{
		gotoxy(0,0);
		cout<<strlen(name)<<endl;
		addControl(&errorwin,&error1);
		paintWindow(&errorwin);
		Sleep(2000);
		return 2;
	}
	return 0;
}

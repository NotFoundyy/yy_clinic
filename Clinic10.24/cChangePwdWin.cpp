#include "cChangePwdWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[10];
extern userNum;
extern USER newUser;

int ChangePwdWin_init(){

	CWIN initwin = {21,2,38,19};

	CONTROL title = {LABEL,36,4,"�� �� �� ��"};

	CONTROL phone = {LABEL,26,8,"�ֻ�����"};
	CONTROL pwd = {LABEL,26,11,"ԭ����"};
	CONTROL pwdE = {EDIT,34,10,"",20,1,10,3,1};
	CONTROL Npwd = {LABEL,26,14,"������"};
	CONTROL NpwdE = {EDIT,34,13,"",20,1,10,3,0};
	CONTROL Ypwd = {LABEL,26,17,"ȷ������"};
	CONTROL YpwdE = {EDIT,34,16,"",20,1,10,3,0};
	CONTROL yes = {BUTTON,34,19,"ȷ  ��", 6, 1};
	CONTROL esc = {BUTTON,46,19,"��  ��", 6, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&phone);
	addControl(&initwin,&pwd);
	addControl(&initwin,&pwdE);
	addControl(&initwin,&Npwd);
	addControl(&initwin,&NpwdE);
	addControl(&initwin,&Ypwd);
	addControl(&initwin,&YpwdE);
	addControl(&initwin,&yes);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	cout<<"��ӭ�����û�"<<endl;
		
	winRun(&initwin);
	if(initwin.flag == 8){
		if(strcmp(initwin.arr[5].context,initwin.arr[7].context) == 0 || strcmp(initwin.arr[3].context,newUser.password) == 0){
			strcpy(newUser.password,initwin.arr[5].context);
			return 9;
		}else{
					cout<<"�������벻ƥ�䣬���������룡"<<endl;
					Sleep(1500);
					return 16;
				}
		}else if(initwin.flag == 9){
			return 14;
	}
	return 0;
}
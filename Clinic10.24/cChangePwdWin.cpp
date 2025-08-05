#include "cChangePwdWin.h"

//跨文件使用全局变量
extern USER arr[10];
extern userNum;
extern USER newUser;

int ChangePwdWin_init(){

	CWIN initwin = {21,2,38,19};

	CONTROL title = {LABEL,36,4,"密 码 修 改"};

	CONTROL phone = {LABEL,26,8,"手机号码"};
	CONTROL pwd = {LABEL,26,11,"原密码"};
	CONTROL pwdE = {EDIT,34,10,"",20,1,10,3,1};
	CONTROL Npwd = {LABEL,26,14,"新密码"};
	CONTROL NpwdE = {EDIT,34,13,"",20,1,10,3,0};
	CONTROL Ypwd = {LABEL,26,17,"确认密码"};
	CONTROL YpwdE = {EDIT,34,16,"",20,1,10,3,0};
	CONTROL yes = {BUTTON,34,19,"确  认", 6, 1};
	CONTROL esc = {BUTTON,46,19,"返  回", 6, 1};

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
	cout<<"欢迎您，用户"<<endl;
		
	winRun(&initwin);
	if(initwin.flag == 8){
		if(strcmp(initwin.arr[5].context,initwin.arr[7].context) == 0 || strcmp(initwin.arr[3].context,newUser.password) == 0){
			strcpy(newUser.password,initwin.arr[5].context);
			return 9;
		}else{
					cout<<"两次密码不匹配，请重新输入！"<<endl;
					Sleep(1500);
					return 16;
				}
		}else if(initwin.flag == 9){
			return 14;
	}
	return 0;
}
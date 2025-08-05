#include "cAdminLoginWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int AdminLoginWin_init(){
	int res = 0;
	CWIN loginwin = {21,2,47,16};
	
	CONTROL title = {LABEL,40,4,"用 户 登 录"};

	CONTROL account = {LABEL,30,8,"账    号："};
	CONTROL password = {LABEL,30,11,"密    码："};
	CONTROL role = {LABEL,30,14,"角    色："};

	CONTROL okBtn = {BUTTON,30,16,"登 录",5,1};
	CONTROL escBtn = {BUTTON,54,16,"取 消",5,1};
	CONTROL roleBtn = {BUTTON,40,13,"管 理 员",11,1};

	CONTROL accEdit = {EDIT,40,7,"",20,1,10,3,1};
	CONTROL passEdit = {EDIT,40,10,"",20,1,10,3,0};

	addControl(&loginwin,&title);
	addControl(&loginwin,&account);
	addControl(&loginwin,&password);
	addControl(&loginwin,&role);
	addControl(&loginwin,&accEdit);
	addControl(&loginwin,&passEdit);
	addControl(&loginwin,&roleBtn);
	addControl(&loginwin,&okBtn);
	addControl(&loginwin,&escBtn);

	paintWindow(&loginwin);
	winRun(&loginwin);

	if(loginwin.flag == 7){
		//登录业务
		res = LoginCheck(loginwin.arr[4].context,loginwin.arr[5].context);
		if(res == 1){
			//管理员
			return 4;
		}else if(res == 2){
			//医生
			return 5;
		}else if(res == 3){
			//普通用户
			return 6;
		}else if(res == 4){
			//error
			return 2;
		}
	}else if(loginwin.flag == 8){
		//取消
		return 0;
	}
	return 0;
}

/********************************************************************************
函数名称：LoginCheck
函数作用：  账号密码验证
函数返回值：正确、不正确
函数参数：char name[20]
		  char pwd[20]
 ********************************************************************************/
int LoginCheck(char name[20],char pwd[20]){
	int x;
	int error = 0;
	for(x = 0;x < userNum;x++){
		if(strcmp(name,arr[x].username) == 0){
			if(strcmp(pwd,arr[x].password) == 0){
				switch(arr[x].role){
				case 1: 
					//管理员
					return 1;
					break;
				case 2:
					//医生
					return 2;
					break;
				case 3:
					//用户
					return 3;
					break;
				}
				break;
			}else{
				CWIN errorwin = {30,6,30,10};
				CONTROL error1 = {LABEL,40,11,"账号密码错误！"};
				addControl(&errorwin,&error1);
				paintWindow(&errorwin);
				Sleep(2500);
				return 4;
			}	
		}else{
			error++;
		}
	}
	if(error == userNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,40,11,"查无此账号！"};
		addControl(&errorwin,&error1);
		paintWindow(&errorwin);
		Sleep(2500);
		return 4;
	}
	return 0;
}


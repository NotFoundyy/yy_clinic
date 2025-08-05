#include "cAdminWin.h"
#include "cAdminLoginWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int AdminWin_init(){

	CWIN initwin = {21,2,40,16};

	CONTROL title = {LABEL,37,4,"管 理 员 界 面"};

	CONTROL userM = {BUTTON,23,8,"用户管理", 9, 1};
	CONTROL doctorM = {BUTTON,50,8,"医生管理", 9, 1};
	CONTROL roomM = {BUTTON,23,12,"科室管理", 9, 1};
	CONTROL dataM = {BUTTON,50,12,"数据统计", 9, 1};
	CONTROL esc = {BUTTON,37,16,"退     出", 9, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&roomM);
	addControl(&initwin,&dataM);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	for(int x = 0;x < userNum;x++){
		switch(arr[x].role){
		case 1: 
			//管理员
			cout<<"欢迎您，管理员"<<arr[x].username<<endl;
			break;
		case 2:
			//医生
			cout<<"欢迎您，医生"<<arr[x].username<<endl;
			break;
		case 3:
			//用户
			cout<<"欢迎您，用户"<<arr[x].username<<endl;
			break;
		}
		break;
	}
	winRun(&initwin);
	if(initwin.flag == 1){
		return 10;
	}else if(initwin.flag == 2){
		return 11;
	}else if(initwin.flag == 3){
		return 13;
	}else if(initwin.flag == 4){
		cout<<"没有此功能";
		Sleep(2000);
		return 4;
	}else if(initwin.flag == 5){
		return 0;
	}
	return 0;
}
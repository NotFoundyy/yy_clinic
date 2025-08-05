#include "cUserCenterWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int UserCenterWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"个 人 中 心"};

	CONTROL userM = {BUTTON,23,8,"信息完善", 9, 1};
	CONTROL doctorM = {BUTTON,46,8,"修改密码", 9, 1};
	CONTROL esc = {BUTTON,23,12,"返  回", 9, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&esc);


	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	//用户
	cout<<"欢迎您，用户"<<endl;

	winRun(&initwin);
	if(initwin.flag == 1){
		return 15;
	}else if(initwin.flag == 2){
		return 16;
	}else if(initwin.flag == 3){
		return 6;
	}
	return 0;
}
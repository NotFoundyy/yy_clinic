#include "cUserImproveWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int UserImproveWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"信 息 完 善"};

	CONTROL phone = {LABEL,26,8,"手机号码"};
	CONTROL name = {LABEL,26,11,"姓    名"};
	CONTROL nameE = {EDIT,34,10,"",20,1,10,0,1};
	CONTROL ID = {LABEL,26,14,"身份证号"};
	CONTROL IDE = {EDIT,34,13,"",20,1,18,3,1};
	CONTROL yes = {BUTTON,34,16,"确  认", 6, 1};
	CONTROL esc = {BUTTON,46,16,"返  回", 6, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&phone);
	addControl(&initwin,&name);
	addControl(&initwin,&nameE);
	addControl(&initwin,&ID);
	addControl(&initwin,&IDE);
	addControl(&initwin,&yes);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	cout<<"欢迎您，用户15751390763"<<endl;
	gotoxy(35,8);
	cout<<"15751390763"<<endl;
	winRun(&initwin);
	if(initwin.flag == 6){
		return 15;
	}else if(initwin.flag == 7){
		return 6;
	}
	return 0;
}
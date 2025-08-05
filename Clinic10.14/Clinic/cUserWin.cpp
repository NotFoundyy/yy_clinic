#include "cUserWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int UserWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"用 户 界 面"};

	CONTROL userM = {BUTTON,23,8,"个人中心", 9, 1};
	CONTROL doctorM = {BUTTON,46,8,"预约管理", 9, 1};
	CONTROL roomM = {BUTTON,23,12,"取    号", 9, 1};
	CONTROL dataM = {BUTTON,46,12,"就诊信息", 9, 1};
	CONTROL esc = {BUTTON,36,16,"退     出", 9, 1};

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
	return 0;
}
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
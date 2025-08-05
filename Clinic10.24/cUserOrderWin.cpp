#include "cUserOrderWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int UserOrderWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"预 约 管 理"};

	CONTROL userM = {BUTTON,23,8,"预约门诊", 9, 1};
	CONTROL doctorM = {BUTTON,46,8,"预约疫苗", 9, 1};
	CONTROL esc = {BUTTON,23,12,"返  回", 9, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&esc);


	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
		cout<<"欢迎您，用户"<<endl;
	winRun(&initwin);
	return 0;
}
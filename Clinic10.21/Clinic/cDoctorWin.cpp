#include "cDoctorWin.h"
#include "cDoctorLoginWin.h"

//跨文件使用全局变量
extern USER arr[5];
extern userNum;

int DoctorWin_init(){

	CWIN initwin = {21,2,40,16};

	CONTROL title = {LABEL,35,4,"医 生 界 面"};

	CONTROL usermain = {BUTTON,33,8,"个 人 中 心", 12, 1};
	CONTROL userdoctor = {BUTTON,33,12,"就诊信息查询", 12, 1};
	CONTROL esc = {BUTTON,33,16,"退	  出", 12, 1};


	addControl(&initwin,&title);
	addControl(&initwin,&usermain);
	addControl(&initwin,&userdoctor);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	cout<<"欢迎您，医生"<<endl;
	winRun(&initwin);
	return 0;
}
#include "cDoctorWin.h"
#include "cDoctorLoginWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int DoctorWin_init(){

	CWIN initwin = {21,2,40,16};

	CONTROL title = {LABEL,35,4,"ҽ �� �� ��"};

	CONTROL usermain = {BUTTON,33,8,"�� �� �� ��", 12, 1};
	CONTROL userdoctor = {BUTTON,33,12,"������Ϣ��ѯ", 12, 1};
	CONTROL esc = {BUTTON,33,16,"��	  ��", 12, 1};


	addControl(&initwin,&title);
	addControl(&initwin,&usermain);
	addControl(&initwin,&userdoctor);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
	cout<<"��ӭ����ҽ��"<<endl;
	winRun(&initwin);
	return 0;
}
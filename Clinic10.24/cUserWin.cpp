#include "cUserWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int UserWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"�� �� �� ��"};

	CONTROL userM = {BUTTON,23,8,"��������", 9, 1};
	CONTROL doctorM = {BUTTON,46,8,"ԤԼ����", 9, 1};
	CONTROL roomM = {BUTTON,23,12,"ȡ    ��", 9, 1};
	CONTROL dataM = {BUTTON,46,12,"������Ϣ", 9, 1};
	CONTROL esc = {BUTTON,36,16,"��     ��", 9, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&roomM);
	addControl(&initwin,&dataM);
	addControl(&initwin,&esc);

	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
		cout<<"��ӭ�����û�"<<endl;
	winRun(&initwin);
	if(initwin.flag == 1){
		return 14;
	}else if(initwin.flag == 2){
		cout<<"������";
		Sleep(2000);
		return 6;
	}else if(initwin.flag == 3){
		cout<<"������";
		Sleep(2000);
		return 6;
	}else if(initwin.flag == 4){
		return 18;
	}else if(initwin.flag == 5){
		return 0;
	}
	return 0;
}
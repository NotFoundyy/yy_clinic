#include "cUserOrderWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int UserOrderWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"Ԥ Լ �� ��"};

	CONTROL userM = {BUTTON,23,8,"ԤԼ����", 9, 1};
	CONTROL doctorM = {BUTTON,46,8,"ԤԼ����", 9, 1};
	CONTROL esc = {BUTTON,23,12,"��  ��", 9, 1};

	addControl(&initwin,&title);
	addControl(&initwin,&userM);
	addControl(&initwin,&doctorM);
	addControl(&initwin,&esc);


	paintWindow(&initwin);
	getTime(45,6);
	gotoxy(22,6);
		cout<<"��ӭ�����û�"<<endl;
	winRun(&initwin);
	return 0;
}
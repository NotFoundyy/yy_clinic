#include "cClinic.h"

int clinic_init(){
	int n = 0;

	CWIN initwin = {21,2,50,20};

	CONTROL title = {LABEL,43,4,"�� �� �� ѯ"};

	CONTROL m1= {BUTTON,33,13,"", 5, 1};
	CONTROL m2 = {BUTTON,33,15,"", 5, 1};
	CONTROL m3 = {BUTTON,33,17,"", 5, 1};
	CONTROL esc = {BUTTON,22,20,"�� ��", 5, 1};
	CONTROL up = {BUTTON,55,20,"��һҳ", 6, 1};
	CONTROL down = {BUTTON,64,20,"��һҳ", 6, 1};


	addControl(&initwin,&title);
	addControl(&initwin,&m1);
	addControl(&initwin,&m2);
	addControl(&initwin,&m3);
	addControl(&initwin,&esc);
	addControl(&initwin,&up);
	addControl(&initwin,&down);

	paintWindow(&initwin);

	getTime(55,6);
	paintTable(30,11,10,1,4,3);
	gotoxy(35,12);
	printf("�� ��");
	gotoxy(45,12);
	printf("ID");
	gotoxy(55,12);
	printf("����״̬");

	gotoxy(22,6);
	cout<<"��ӭ�����û�"<<endl;
	gotoxy(46,20);
	winRun(&initwin);
	return 0;
}
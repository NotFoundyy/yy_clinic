#include "cUserImproveWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int UserImproveWin_init(){

	CWIN initwin = {21,2,38,16};

	CONTROL title = {LABEL,36,4,"�� Ϣ �� ��"};

	CONTROL phone = {LABEL,26,8,"�ֻ�����"};
	CONTROL name = {LABEL,26,11,"��    ��"};
	CONTROL nameE = {EDIT,34,10,"",20,1,10,0,1};
	CONTROL ID = {LABEL,26,14,"���֤��"};
	CONTROL IDE = {EDIT,34,13,"",20,1,18,3,1};
	CONTROL yes = {BUTTON,34,16,"ȷ  ��", 6, 1};
	CONTROL esc = {BUTTON,46,16,"��  ��", 6, 1};

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
	cout<<"��ӭ�����û�15751390763"<<endl;
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
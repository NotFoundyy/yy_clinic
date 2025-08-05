#include "cAdminWin.h"
#include "cAdminLoginWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;

int AdminWin_init(){

	CWIN initwin = {21,2,40,16};

	CONTROL title = {LABEL,37,4,"�� �� Ա �� ��"};

	CONTROL userM = {BUTTON,23,8,"�û�����", 9, 1};
	CONTROL doctorM = {BUTTON,50,8,"ҽ������", 9, 1};
	CONTROL roomM = {BUTTON,23,12,"���ҹ���", 9, 1};
	CONTROL dataM = {BUTTON,50,12,"����ͳ��", 9, 1};
	CONTROL esc = {BUTTON,37,16,"��     ��", 9, 1};

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
			//����Ա
			cout<<"��ӭ��������Ա"<<arr[x].username<<endl;
			break;
		case 2:
			//ҽ��
			cout<<"��ӭ����ҽ��"<<arr[x].username<<endl;
			break;
		case 3:
			//�û�
			cout<<"��ӭ�����û�"<<arr[x].username<<endl;
			break;
		}
		break;
	}
	winRun(&initwin);
	if(initwin.flag == 1){
		return 10;
	}else if(initwin.flag == 2){
		return 11;
	}else if(initwin.flag == 3){
		return 13;
	}else if(initwin.flag == 4){
		cout<<"û�д˹���";
		Sleep(2000);
		return 4;
	}else if(initwin.flag == 5){
		return 0;
	}
	return 0;
}
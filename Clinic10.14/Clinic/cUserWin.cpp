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
	return 0;
}
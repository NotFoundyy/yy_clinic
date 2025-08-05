#include "cUserQueryWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern userNum;
extern LIST * accList;

//��ǰҳ
int currentPage = 1;
//��ҳ��
int countPage = 0;
//�����ܸ���
int count = 0;
//��ʼ�±�
int index = 0;

int userQueryWin_init(){
	LIST * node;
	ACC * acc;
	int n = 0;

	CWIN initwin = {21,2,50,20};

	CONTROL title = {LABEL,43,4,"�� �� �� ѯ"};

	CONTROL usermain = {LABEL,22,9,"�������û��˺ţ�"};
	CONTROL userdoctor = {EDIT,38,8,"", 15,1,10,3,1};
	CONTROL query = {BUTTON,58,8,"�� ѯ", 5, 1};
	CONTROL m1= {BUTTON,33,13,"", 5, 1};
	CONTROL m2 = {BUTTON,33,15,"", 5, 1};
	CONTROL m3 = {BUTTON,33,17,"", 5, 1};
	CONTROL esc = {BUTTON,22,20,"�� ��", 5, 1};
	CONTROL up = {BUTTON,55,20,"��һҳ", 6, 1};
	CONTROL down = {BUTTON,64,20,"��һҳ", 6, 1};


	addControl(&initwin,&title);
	addControl(&initwin,&usermain);
	addControl(&initwin,&userdoctor);
	addControl(&initwin,&query);
	addControl(&initwin,&m1);
	addControl(&initwin,&m2);
	addControl(&initwin,&m3);
	addControl(&initwin,&esc);
	addControl(&initwin,&up);
	addControl(&initwin,&down);

	paintWindow(&initwin);

	getTime(55,6);
	paintTable(30,11,15,1,4,2);
	gotoxy(35,12);
	printf("��  ��");
	gotoxy(50,12);
	printf("�� �� �� Ϣ");

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
	count = List_getSize(accList);
		if(count % 3 == 0){
			countPage = count/3;
		}else{
			countPage = count/3 + 1;
		}
		for( x = index;x < index + 3;x++){
			if(x < count){
				node = getByPos(accList,x);
				acc = (ACC *)node->pdata;		
				gotoxy(35,14+2*n);
				printf("%s",acc->accName);
				gotoxy(50,14+2*n);
				printf("%s",acc->role);
				n++;
			}else{
				break;
			}
		}
		gotoxy(46,20);
		printf("%d/%d",currentPage,countPage);
		winRun(&initwin);

	//��ť�߼�
	if(initwin.flag == 9){
		if(currentPage > 1){
			currentPage--;
		}
	}else if(initwin.flag == 10){
			if(currentPage < countPage){
				currentPage++;
			}
	}else if(initwin.flag == 3){
	userQuery(initwin.arr[2].context);
	}
	index = (currentPage - 1) * 3;
	return 10;
}
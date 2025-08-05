#include "cClassQueryWin.h"

//���ļ�ʹ��ȫ�ֱ���
extern USER arr[5];
extern claNum;
extern LIST * claList;

int classQueryWin_init(){
	//��ǰҳ
	int currentPage = 1;
	//��ҳ��
	int countPage = 0;
	//�����ܸ���
	int count = 0;
	//��ʼ�±�
	int index = 0;
	LIST * node;
	CLA * cla;
	int n = 0;

	CWIN initwin = {21,2,50,20};

	CONTROL title = {LABEL,43,4,"�� �� �� ѯ"};

	CONTROL usermain = {LABEL,22,9,"���������ID��"};
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
	paintTable(23,11,15,1,4,3);
	gotoxy(29,12);
	printf("����ID");
	gotoxy(44,12);
	printf("��������");
	gotoxy(62,12);
	printf("���");

	gotoxy(22,6);
	for(int x = 0;x < claNum;x++){
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
	count = List_getSize(claList);
		if(count % 3 == 0){
			countPage = count/3;
		}else{
			countPage = count/3 + 1;
		}
		for( x = index;x < index + 3;x++){
			if(x < count){
				node = getByPos(claList,x);
				cla = (CLA *)node->pdata;		
				gotoxy(29,14+2*n);
				printf("%s",cla->claID);
				gotoxy(44,14+2*n);
				printf("%s",cla->claName);
				gotoxy(62,14+2*n);
				printf("%s",cla->claAsk);
				n++;
			}else{
				break;
			}
		}
		gotoxy(46,20);
		printf("%d/%d",currentPage,countPage);
		winRun(&initwin);

	//��ť�߼�
	if(initwin.flag == 8){
		if(currentPage > 1){
			currentPage--;
		}
	}else if(initwin.flag == 9){
			if(currentPage < countPage){
				currentPage++;
			}
	}else if(initwin.flag == 3){
		int res = claQuery(initwin.arr[2].context);
		if(res == 1){
			return 13;
		}else if(res ==2){
			return 14;
		}
	}else if(initwin.flag == 4 || initwin.flag == 5 || initwin.flag == 6){
		CWIN docwin = {30,6,30,12};
		CONTROL TITLE = {LABEL,44,8,"��Ϣ�޸�"};
		CONTROL ID = {LABEL,32,10,"ҽ��ID��"};
		CONTROL ROLE = {LABEL,32,13,"ҽ��ְλ��"};
		CONTROL YES = {BUTTON,40,16,"ȷ��",4,1};
		CONTROL NO = {BUTTON,48,16,"ȡ��",4,1};
		CONTROL role = {BUTTON,42,12,"",10,1};

		addControl(&docwin,&TITLE);
		addControl(&docwin,&ID);
		addControl(&docwin,&ROLE);
		addControl(&docwin,&YES);
		addControl(&docwin,&NO);
		addControl(&docwin,&role);
		paintWindow(&docwin);
		gotoxy(44,10);
		cout<<cla->claID;
		gotoxy(44,13);
		cout<<cla->claName;
		winRun(&docwin);
	}else if(initwin.flag == 7){
		return 4;
	}
	index = (currentPage - 1) * 3;

	return 13;
}
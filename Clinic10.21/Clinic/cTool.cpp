#include"cTool.h"

extern userNum;
extern docNum;
extern claNum;
extern LIST * accList;
extern USER arr[10];
extern DOC doc[10];
extern CLA cla[10];

/************************************************************************************
�������ƣ�gotoxy
�������ã����ù��λ�ú���
��������ֵ����
����������	int x��x����
					int y��y����
************************************************************************************/
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/************************************************************************************
�������ƣ�paintBorder
�������ã��滭�߿���
��������ֵ����
����������	int height�����ñ߿�߶�
					int width�����ñ߿���
					int x�����ù��x����
					int y�����ù��y����
************************************************************************************/
void paintBorder(int x,int y,int width,int height){
	int i = 0;
	int n = 0;

	gotoxy(x,y);
	//����
	for(printf("��");i <= width;i++){
		printf("��");
	}
	printf("��\n");
	//�м���
	for(n = 0;n <= height;n++){
		i = 0;
		gotoxy(x,y+=1);
		for(printf("��");i <= width;i++){
			printf(" ");
		}
		printf("��\n");
	}
	//β��
	i = 0;
	gotoxy(x,y);
	for(printf("��");i <= width;i++){
		printf("��");
	}
	printf("��\n");
}

/********************************************************************************
�������ƣ�paintTable
�������ã�  ����һ�����
��������ֵ����
����������	startX: ������Ͻǵ�X����
					startY: ������Ͻǵ�Y����
					width: ÿ�еĿ��
					height: ÿ�еĸ߶�
					row: ��������
					col: ��������
 *******************************************************************************/
void paintTable(int startX, int startY, int width, int height, int row, int col) {
	int i=0, j=0, k=0;
	
    // ȷ������������0
    if (row <= 0 || col <= 0) {
        printf("�����������������0��\n");
        return;
    }
	
    // ���Ʊ��Ķ����߿�
	gotoxy(startX,startY);
    for (printf("��"); i < col; i++) {
        for (j = 0; j < width; j++) {
            printf("��");
        }
        if (i < col - 1) {
            printf("��");
        } else {
			printf("��\n");
		}
    }
	
    // ����ÿһ��
    for (i = 0; i < row; i++) {
		gotoxy(startX,startY+=1);
        // ����ÿ�е�����
        for ( j = 0; j < col; j++) {
			printf("��");
            for (k = 0; k < width; k++) {
                printf(" ");
            }
        }
        printf("��\n");
		
        // �����м�ķָ���
		j = 0;
        if (i < row - 1) {
			gotoxy(startX,startY+=1);
            for (printf("��");j < col; j++) {
                for (k = 0; k < width; k++) {
                    printf("��");
                }
                if (j < col - 1) {
                    printf("��");
                } else {
                    printf("��\n");
                }
            }
        }
    }
	
    // ���Ʊ��ĵײ��߿�
	i = 0;
	gotoxy(startX,startY+=1);
    for ( printf("��");i < col; i++) {
        for (j = 0; j < width; j++) {
            printf("��");
        }
        if (i < col - 1) {
            printf("��");
        } else {
            printf("��\n");
        }
    }
}

/********************************************************************************
�������ƣ�getKey
�������ã�  ��������
��������ֵ������ֵ
������������
 ********************************************************************************/
int getKey(){
	int res = 0;
	
	while(1){
		res = getch();
		
		switch(res){
		case 13:
			return KEY_ENTER;	
		case 27:
			return KEY_ESC;
		case 227:	
			res = getch();
			if (res == 72){
				return KEY_UP;
			}else if(res == 80){
				return KEY_DOWN;
			}
			break;
		default:
			return res;
		}
	}
	return res;
}

int getTime(int x,int y) {
	gotoxy(x,y);
    time_t now;
    time(&now); // ��ȡ��ǰʱ��
    struct tm *local = localtime(&now); // ת��Ϊ����ʱ��

    // ��ӡ��ǰ���ں�ʱ��
    printf("ʱ�䣺%d-%02d-%02d\n",
           local->tm_year + 1900, // ��ݴ�1900��ʼ
           local->tm_mon + 1,     // �·ݴ�0��ʼ
           local->tm_mday);      // ��
/*	gotoxy(x+6,y+1);
	printf("%02d:%02d:%02d\n",
           local->tm_hour,        // ʱ
           local->tm_min,         // ��
           local->tm_sec);*/        // ��

    return 0;
}

/********************************************************************************
�������ƣ�Query
�������ã�  �˺�������֤
��������ֵ����ȷ������ȷ
����������char name[20]
 ********************************************************************************/
int userQuery(char name[20]){
	int x;
	int error = 0;
	for(x = 0;x < userNum;x++){
		if(strcmp(name,arr[x].username) == 0){
			CWIN querywin = {30,6,30,10};
			CONTROL query1 = {LABEL,40,7,"��ѯ����Ϣ��"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"�˺ţ�"<<arr[x].username<<endl;
			gotoxy(32,11);
			cout<<"���룺"<<arr[x].password<<endl;
			gotoxy(32,13);
			cout<<"��ɫ��"<<arr[x].role<<endl;
			Sleep(2500);	
		}else{
			error++;
			}	
		}
	if(error==userNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,40,11,"���޴��˺ţ�"};
		addControl(&errorwin,&error1);
		paintWindow(&errorwin);
		Sleep(1500);
	}
	return 0;
}

int docQuery(char name[20]){
	int x;
	int error = 0;
	for(x = 0;x < docNum;x++){
		if(strcmp(name,doc[x].docID) == 0){
			CWIN querywin = {30,6,30,10};
			CONTROL query1 = {LABEL,40,7,"��ѯ����Ϣ��"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"ҽ��ID:"<<doc[x].docID<<endl;
			gotoxy(32,11);
			cout<<"ְλ:"<<doc[x].docRole<<endl;
			Sleep(2500);
		}else{
			error++;
			}	
		}
	if(error==docNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,42,8,"���޴�ҽ����"};
		CONTROL Again = {BUTTON,40,10,"�� �� �� ��",11,1};
		CONTROL New = {BUTTON,40,13,"�� �� ҽ ��",11,1};
		addControl(&errorwin,&error1);
		addControl(&errorwin,&Again);
		addControl(&errorwin,&New);
		paintWindow(&errorwin);
		winRun(&errorwin);
		if(errorwin.flag == 1){
			return 10;
		}else if(errorwin.flag == 2){
			return 11;
		}
	}
	return 0;
}

int claQuery(char ID[20]){
	int x;
	int error = 0;
	for(x = 0;x < claNum;x++){
		if(strcmp(ID,doc[x].docID) == 0){
			CWIN querywin = {30,6,30,10};
			CONTROL query1 = {LABEL,40,7,"��ѯ����Ϣ��"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"����ID:"<<cla[x].claID<<endl;
			gotoxy(32,11);
			cout<<"��������:"<<cla[x].claName<<endl;
			Sleep(2500);
		}else{
			error++;
			}	
		}
	if(error==claNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,42,8,"���޴˿��ң�"};
		CONTROL Again = {BUTTON,40,10,"�� �� �� ��",11,1};
		CONTROL New = {BUTTON,40,13,"�� �� �� ��",11,1};
		addControl(&errorwin,&error1);
		addControl(&errorwin,&Again);
		addControl(&errorwin,&New);
		paintWindow(&errorwin);
		winRun(&errorwin);
		if(errorwin.flag == 1){
			return 10;
		}else if(errorwin.flag == 2){
			return 11;
		}
	}
	return 0;
}

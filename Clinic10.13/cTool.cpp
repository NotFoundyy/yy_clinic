#include"cTool.h"
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


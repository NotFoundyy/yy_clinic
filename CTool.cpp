#include"CTool.h"

/**********
��������gotoxy
�������ܣ�����ƶ�
����ֵ����
����������
int x			�����ʼλ��x��
int y			�����ʼλ��y��
***********/
void CTool::gotoxy(int x, int y) 
{
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}
/**********
��������PointBk
�������ܣ����߿�
����ֵ����
����������
int x			�����ʼλ��x��
int y			�����ʼλ��y��
int width	 �߿��
 int height	�߿��
***********/
void CTool::PointBorder(int x,int y,int width, int height)
{
	int i, j;
	for (i = 0; i <= height; i++)
	{
		gotoxy(x,y+i);
		for (j = 0; j <= width; j++)
		{
			if (i == 0 && j == 0)
			{
				printf("�W");//�T�U�W �Z�] �`
			}
			else if (i == 0 && j == width)
			{
				printf("�Z");
			}
			else if (i == height && j == 0)
			{
				printf("�]");
			}
			else if (i == height && j == width)
			{
				printf("�`");
			}
			else if (i == 0 || i == height)
			{
				printf("�T");
			}
			else if (j == 0||j == width)
			{
				printf("�U");
			}
			else
			{
				printf(" ");
			}			
		}
		printf("\n");
	}
}
/**********
��������paintTable
�������ܣ������
����ֵ����
����������
int x			�����ʼλ��x��
int y			�����ʼλ��y��
int width	 �߿��
 int height	�߿��
 int row	����
 int col	����
***********/
void CTool::PaintTable(int x,int y, int width,int height,int row,int col)//�� �� ���� �� �ȩ� �� ������
{
	int h=0,w=0,r=0,c=0;
	gotoxy(x,y++);
	for(c=1;c<=col;c++)
	{				
		for(w=1;w<=width;w++)
		{
			if(c==1&&w==1)
				printf("��");
			else if(c<col&&w==width)
				printf("��");
			else if(c==col&&w==width)
				printf("��");
			else 
				printf("��");
		}
	}
	for(r=1;r<=row;r++)
	{
		for(h=1;h<=height;h++)
		{
			gotoxy(x,y++);
			for(c=1;c<=col;c++)
			{				
				for(w=1;w<=width;w++)
				{	//�� �� ���� �� �ȩ� �� ������						
					 if(c==1&&w==1&&r==row&&h==height)
						printf("��");
					else if(c<col&&w==width&&r==row&&h==height)
						printf("��");
					else if(c==col&&w==width&&r==row&&h==height)
						printf("��");

					else if(c==1&&w==1&&h==height)
						printf("��");
					else if(c==col&&w==width&&h==height)
						printf("��");
					else if(w==width&&h==height)
						printf("��");

					else if(h==height)
						printf("��");
					else if(w==width||(w==1&&c==1))
						printf("��");
					else 
						printf(" ");
				}							
			}	
			printf("\n");
		}		
	}
}

/**********
��������getKey
�������ܣ���ð���
����ֵ����
������������
***********/
int CTool::getKey()
{
	int res;
	while (1)
	{
		res=getch();
		switch(res)
		{
		case 13:
			return KEY_ENTER;
		case 27:
			return KEY_ESC;
		case 224:
			res=getch();
			if(res==72)
				return KEY_UP;
			else if(res==80)
				return KEY_DOWN;
			else if(res==75)
				return KEY_LEFT;
			else if(res==77)
				return KEY_RIGHT;
		default:
			return res;
		}
	}
	return res;
}

char * CTool::getTime()//��ȡ��ǰʱ��
{
	char * nowtime=new char(30); 
	time_t now =time(NULL);
	struct tm* localTime =localtime(&now);
	sprintf(nowtime,"%04d-%02d-%02d",localTime->tm_year +1900,localTime->tm_mon +1,localTime->tm_mday);
	return nowtime;
}
char * CTool::getTime(int i)//��ȡ��ǰʱ��+i����
{
	char * nowtime=new char(30); 
	time_t now =time(NULL);
	struct tm* localTime =localtime(&now);

	localTime->tm_mday+=i;
	mktime(localTime);


		//localTime->tm_mday+=i;
	sprintf(nowtime,"%04d-%02d-%02d",localTime->tm_year +1900,localTime->tm_mon +1,localTime->tm_mday);
	return nowtime;
}

list <char *>CTool::getChaxun(char * beginData,char * endData)
{
	struct Data{
		int year;
		int month;
		int day;
	};
	Data begin,end;
	sscanf(beginData,"%d-%d-%d", &begin.year,&begin.month,&begin.day);
	sscanf(endData,"%d-%d-%d",&end.year,&end.month,&end.day);
	struct tm beginTm={0},endTm={0};
	beginTm.tm_year=begin.year-1900;
	beginTm.tm_mon=begin.month-1;
	beginTm.tm_mday=begin.day;

	endTm.tm_year =end.year-1900;
	endTm.tm_mon=end.month-1;
	endTm.tm_mday=end.day;

	time_t beginTime =mktime(&beginTm);
	time_t endTime=mktime(&endTm);
	int oneDay=24*60*60;
	list<char *>dates;
	for(time_t nowTime=beginTime;nowTime<=endTime;nowTime+=oneDay)
	{
		struct tm* nowTm = localtime(&nowTime);
		char * dateBuffer =new char[11];
		sprintf(dateBuffer,"%04d-%02d-%02d",nowTm->tm_year+1900,nowTm->tm_mon+1,nowTm->tm_mday);
		dates.push_back(dateBuffer);
	}
	return dates;
}


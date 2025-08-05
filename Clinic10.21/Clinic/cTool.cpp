#include"cTool.h"

extern userNum;
extern docNum;
extern claNum;
extern LIST * accList;
extern USER arr[10];
extern DOC doc[10];
extern CLA cla[10];

/************************************************************************************
函数名称：gotoxy
函数作用：设置光标位置函数
函数返回值：无
函数参数：	int x：x坐标
					int y：y坐标
************************************************************************************/
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/************************************************************************************
函数名称：paintBorder
函数作用：绘画边框函数
函数返回值：无
函数参数：	int height：设置边框高度
					int width：设置边框宽度
					int x：设置光标x坐标
					int y：设置光标y坐标
************************************************************************************/
void paintBorder(int x,int y,int width,int height){
	int i = 0;
	int n = 0;

	gotoxy(x,y);
	//首行
	for(printf("┌");i <= width;i++){
		printf("─");
	}
	printf("┐\n");
	//中间行
	for(n = 0;n <= height;n++){
		i = 0;
		gotoxy(x,y+=1);
		for(printf("│");i <= width;i++){
			printf(" ");
		}
		printf("│\n");
	}
	//尾行
	i = 0;
	gotoxy(x,y);
	for(printf("└");i <= width;i++){
		printf("─");
	}
	printf("┘\n");
}

/********************************************************************************
函数名称：paintTable
函数作用：  绘制一个表格
函数返回值：无
函数参数：	startX: 表格左上角的X坐标
					startY: 表格左上角的Y坐标
					width: 每列的宽度
					height: 每行的高度
					row: 表格的行数
					col: 表格的列数
 *******************************************************************************/
void paintTable(int startX, int startY, int width, int height, int row, int col) {
	int i=0, j=0, k=0;
	
    // 确保行列数大于0
    if (row <= 0 || col <= 0) {
        printf("行数和列数必须大于0。\n");
        return;
    }
	
    // 绘制表格的顶部边框
	gotoxy(startX,startY);
    for (printf("┌"); i < col; i++) {
        for (j = 0; j < width; j++) {
            printf("─");
        }
        if (i < col - 1) {
            printf("┬");
        } else {
			printf("┐\n");
		}
    }
	
    // 绘制每一行
    for (i = 0; i < row; i++) {
		gotoxy(startX,startY+=1);
        // 绘制每行的内容
        for ( j = 0; j < col; j++) {
			printf("│");
            for (k = 0; k < width; k++) {
                printf(" ");
            }
        }
        printf("│\n");
		
        // 绘制行间的分隔线
		j = 0;
        if (i < row - 1) {
			gotoxy(startX,startY+=1);
            for (printf("├");j < col; j++) {
                for (k = 0; k < width; k++) {
                    printf("─");
                }
                if (j < col - 1) {
                    printf("┼");
                } else {
                    printf("┤\n");
                }
            }
        }
    }
	
    // 绘制表格的底部边框
	i = 0;
	gotoxy(startX,startY+=1);
    for ( printf("└");i < col; i++) {
        for (j = 0; j < width; j++) {
            printf("─");
        }
        if (i < col - 1) {
            printf("┴");
        } else {
            printf("┘\n");
        }
    }
}

/********************************************************************************
函数名称：getKey
函数作用：  监听键盘
函数返回值：按键值
函数参数：无
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
    time(&now); // 获取当前时间
    struct tm *local = localtime(&now); // 转换为本地时间

    // 打印当前日期和时间
    printf("时间：%d-%02d-%02d\n",
           local->tm_year + 1900, // 年份从1900开始
           local->tm_mon + 1,     // 月份从0开始
           local->tm_mday);      // 日
/*	gotoxy(x+6,y+1);
	printf("%02d:%02d:%02d\n",
           local->tm_hour,        // 时
           local->tm_min,         // 分
           local->tm_sec);*/        // 秒

    return 0;
}

/********************************************************************************
函数名称：Query
函数作用：  账号密码验证
函数返回值：正确、不正确
函数参数：char name[20]
 ********************************************************************************/
int userQuery(char name[20]){
	int x;
	int error = 0;
	for(x = 0;x < userNum;x++){
		if(strcmp(name,arr[x].username) == 0){
			CWIN querywin = {30,6,30,10};
			CONTROL query1 = {LABEL,40,7,"查询到信息！"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"账号："<<arr[x].username<<endl;
			gotoxy(32,11);
			cout<<"密码："<<arr[x].password<<endl;
			gotoxy(32,13);
			cout<<"角色："<<arr[x].role<<endl;
			Sleep(2500);	
		}else{
			error++;
			}	
		}
	if(error==userNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,40,11,"查无此账号！"};
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
			CONTROL query1 = {LABEL,40,7,"查询到信息！"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"医生ID:"<<doc[x].docID<<endl;
			gotoxy(32,11);
			cout<<"职位:"<<doc[x].docRole<<endl;
			Sleep(2500);
		}else{
			error++;
			}	
		}
	if(error==docNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,42,8,"查无此医生！"};
		CONTROL Again = {BUTTON,40,10,"重 新 输 入",11,1};
		CONTROL New = {BUTTON,40,13,"新 增 医 生",11,1};
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
			CONTROL query1 = {LABEL,40,7,"查询到信息！"};
			addControl(&querywin,&query1);
			paintWindow(&querywin);
			gotoxy(32,9);
			cout<<"科室ID:"<<cla[x].claID<<endl;
			gotoxy(32,11);
			cout<<"科室名称:"<<cla[x].claName<<endl;
			Sleep(2500);
		}else{
			error++;
			}	
		}
	if(error==claNum){
		CWIN errorwin = {30,6,30,10};
		CONTROL error1 = {LABEL,42,8,"查无此科室！"};
		CONTROL Again = {BUTTON,40,10,"重 新 输 入",11,1};
		CONTROL New = {BUTTON,40,13,"新 增 科 室",11,1};
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

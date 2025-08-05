#include"cTool.h"
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


#ifndef CWINDOW_H
#define CWINDOW_H

#include "cData.h"
#include "cButton.h"
#include "cEdit.h"
#include "cLabel.h"

typedef struct window{
	int winX;					//窗口x坐标
	int winY;					//窗口y坐标
	int winWidth;			//窗口宽度 
	int winHeight;			//窗口高度
	CONTROL arr[20];	//窗口控件数组
	int count;					//有效控件个数
	int flag;				      //记录被enter操作过的button下标
}CWIN;

addControl(CWIN *win, CONTROL *con);

void paintWindow(CWIN *win);

winRun(CWIN *win);

SmallWinRun(CWIN *win);


#endif
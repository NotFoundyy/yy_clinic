#ifndef CWINDOW_H
#define CWINDOW_H

#include "cData.h"
#include "cButton.h"
#include "cEdit.h"
#include "cLabel.h"

typedef struct window{
	int winX;					//����x����
	int winY;					//����y����
	int winWidth;			//���ڿ�� 
	int winHeight;			//���ڸ߶�
	CONTROL arr[20];	//���ڿؼ�����
	int count;					//��Ч�ؼ�����
	int flag;				      //��¼��enter��������button�±�
}CWIN;

addControl(CWIN *win, CONTROL *con);

void paintWindow(CWIN *win);

winRun(CWIN *win);

SmallWinRun(CWIN *win);


#endif
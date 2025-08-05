#ifndef CWINDOW_H
#define CWINDOW_H

#include "CTool.h"
#include"CControl.h"
#include "CButton.h"
#include "CEdit.h"
#include "CLabel.h"
#include"CTable.h"
#include"CUser.h"
#include"CAdmin.h"
#include"CDoctor.h"
#include"CJiuzhen.h"
#include"CData.h"
#include<map>

#include<iostream>
using namespace std;


class CWindow
{
public:
	CWindow(int winX,int winY,int winWidth,int winHeight);
	~CWindow();
	void addCon(CControl *con);
	virtual void paintWindow();
	virtual void winRun();
	void escMain();
	virtual int doAction()=0;
protected:
	int winX;
	int winY;
	int winWidth;
	int winHeight;
	CControl * arr[20];
	
	int count;
	int flag;

};
#endif
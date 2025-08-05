#pragma warning(disable:4786)
#include"CMainWin.h"
extern escflag;
CMainwin::CMainwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->title= new CLabel(50,3,0,0,"欢迎来到门诊预约系统",LABEL);
	this->id= new CLabel(80,25,0,0,"学号：omo240822",LABEL);
	this->signinbut=new CButton(50,7,20,2,"注  册",BUTTON);
	this->loginbut=new CButton(50,13,20,2,"登  录",BUTTON);
	this->cancelbut=new CButton(50,19,20,2,"退  出",BUTTON);

	this->addCon(title);
	this->addCon(signinbut);
	this->addCon(loginbut);
	this->addCon(cancelbut);
	this->addCon(id);
}
CMainwin::~CMainwin()
{
	delete this->title;
	delete this->id;
	delete this->signinbut;
	delete this->loginbut;
	delete this->cancelbut;
}
int CMainwin::doAction()
{
	//char buf[20];
	switch(this->flag)
	{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			CWindow::escMain();
			return 0;
	}
	return 0;
}
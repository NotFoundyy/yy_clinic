#pragma warning(disable:4786)
#include"CMainWin.h"
extern escflag;
CMainwin::CMainwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->title= new CLabel(50,3,0,0,"��ӭ��������ԤԼϵͳ",LABEL);
	this->id= new CLabel(80,25,0,0,"ѧ�ţ�omo240822",LABEL);
	this->signinbut=new CButton(50,7,20,2,"ע  ��",BUTTON);
	this->loginbut=new CButton(50,13,20,2,"��  ¼",BUTTON);
	this->cancelbut=new CButton(50,19,20,2,"��  ��",BUTTON);

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
#include"CUserwin.h"
extern char nownser[20];

CUserwin::CUserwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	
	this->grzxbut=new CButton(35,12,20,2,"�� �� �� ��",BUTTON);
	this->yyglbut=new CButton(65,12,20,2,"Ԥ Լ �� ��",BUTTON);
	this->qhbut=new CButton(35,16,20,2,"ȡ  ��",BUTTON);
	this->jzxxbut=new CButton(65,16,20,2,"�� �� �� Ϣ",BUTTON);
	this->cancelbut=new CButton(35,20,20,2,"��  ��",BUTTON);


	this->addCon(grzxbut);
	this->addCon(yyglbut);
	this->addCon(qhbut);
	this->addCon(jzxxbut);
	this->addCon(cancelbut);
}
CUserwin::~CUserwin()
{
	delete this->grzxbut;
	delete this->yyglbut;
	delete this->qhbut;
	delete this->jzxxbut;
	delete this->cancelbut;
}
int CUserwin::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 10;
	case 1:
		return 13;
	case 2:
		return 15;
	case 3:
		return 16;
	case 4:
		return 0;
	}
	return 5;
}
#include"CAdminWin.h"
extern char nownser[20];

CAdminwin::CAdminwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	

	this->yhglbut=new CButton(35,12,20,2,"�� �� �� ��",BUTTON);//0
	this->ysglbut=new CButton(65,12,20,2,"ҽ �� �� ��",BUTTON);
	this->ksglbut=new CButton(35,16,20,2,"�� �� �� ��",BUTTON);
	this->sjtjbut=new CButton(65,16,20,2,"�� �� ͳ ��",BUTTON);
	this->cancelbut=new CButton(35,20,20,2,"��  ��",BUTTON);

	
	this->addCon(yhglbut);
	this->addCon(ysglbut);
	this->addCon(ksglbut);
	this->addCon(sjtjbut);
	this->addCon(cancelbut);




}
CAdminwin::~CAdminwin()
{
	delete this->yhglbut;
	delete this->ysglbut;
	delete this->ksglbut;
	delete this->sjtjbut;
	delete this->cancelbut;
}
int CAdminwin::doAction()
{
	
	switch(this->flag)
	{
	case 0:
		return 6;
	case 1:
		return 7;
	case 2:
		return 8;
	case 4:
			return 0;
	}
	return 3;
}
#include"CUserYymain.h"

CUserYymain::CUserYymain(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->roleButton1=new CButton(35,12,20,2,"Ԥ Լ  �� ��",BUTTON);
	this->roleButton2=new CButton(65,12,20,2,"Ԥ Լ  ���� ",BUTTON);
	this->roleButton3 =new CButton(35,20,20,2,"�� �� ��  �� �� ��",BUTTON);
	this->roleButton4=new CButton(65,20,20,2,"��  ��",BUTTON);

	this->addCon(roleButton1);
	this->addCon(roleButton2);
	this->addCon(roleButton3);	
	this->addCon(roleButton4);	
}
CUserYymain::~CUserYymain()
{
	delete this->roleButton1;
	delete this->roleButton2;
	delete this->roleButton3;
	delete this->roleButton4;
}
int CUserYymain::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 14;
	case 3:
		return 5;
	}
	return 13;
}
#include"CDoctorXl.h"


CDoctorXl::CDoctorXl(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->tip=new CLabel(44,13,0,0,"��ʾ��ҽ��������",LABEL);
	this->rolebut1=new CButton(47,18,25,2,"���� ����",BUTTON);//1
	this->rolebut2=new CButton(47,22,25,2,"���� ҽ��",BUTTON);

	this->addCon(tip);
	this->addCon(rolebut1);
	this->addCon(rolebut2);
}
CDoctorXl::~CDoctorXl()
{
	delete this->tip;
	delete this->rolebut1;
	delete this->rolebut2;
}
int CDoctorXl::doAction()
{
	switch(this->flag)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	}	
	return 2;
}

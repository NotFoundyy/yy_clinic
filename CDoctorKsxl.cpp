#include"CDoctorKsxl.h"


CDoctorKsxl::CDoctorKsxl(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->rolebut1=new CButton(50,19,33,2,"ÑÛ  ¿Æ",BUTTON);
	this->rolebut2=new CButton(50,21,33,2,"±Ç  ¿Æ",BUTTON);
	this->rolebut3=new CButton(50,23,33,2,"¶ù  ¿Æ",BUTTON);

	this->addCon(rolebut1);
	this->addCon(rolebut2);
	this->addCon(rolebut3);

	
}
CDoctorKsxl::~CDoctorKsxl()
{
	delete this->rolebut1;
	delete this->rolebut2;
	delete this->rolebut3;
}
int CDoctorKsxl::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 2;
	}	
	return 0;
}

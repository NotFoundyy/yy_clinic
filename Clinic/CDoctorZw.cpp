#include"CDoctorZw.h"


CDoctorZw::CDoctorZw(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->rolebut1=new CButton(50,22,33,2,"专家",BUTTON);
	this->rolebut2=new CButton(50,24,33,2,"主任医师",BUTTON);
	this->rolebut3=new CButton(50,26,33,2,"副主任医师",BUTTON);
	this->rolebut4=new CButton(50,28,33,2,"主治医师",BUTTON);

	this->addCon(rolebut1);
	this->addCon(rolebut2);
	this->addCon(rolebut3);
	this->addCon(rolebut4);

	
}
CDoctorZw::~CDoctorZw()
{
	delete this->rolebut1;
	delete this->rolebut2;
	delete this->rolebut3;
	delete this->rolebut4;
}
int CDoctorZw::doAction()
{
	switch(this->flag)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	}	
	return 0;
}

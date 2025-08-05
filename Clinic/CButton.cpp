#include"CButton.h"
CButton::CButton(int x,int y,int width,int height,char context[20],int type):
CControl(x,y,width,height,context,type)
{

}

void CButton::show()
{
	CTool::PointBorder(this->x,this->y,this->width,this->height);
	CTool::gotoxy(this->x+((this->width-strlen(this->context))/2)+1,this->y+1);
	cout<<this->context<<endl;
}
CButton::~CButton()
{
	
}
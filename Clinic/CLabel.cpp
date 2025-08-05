#include"CLabel.h"


CLabel::CLabel(int x,int y,int width,int height,char context[20],int type):
CControl(x,y,width,height,context,type)
{

}

void CLabel::show()
{
	CTool::gotoxy(this->x+1,this->y+1);
	cout<<this->context<<endl;
}

CLabel::~CLabel()
{
	
}

#include"CControl.h"
CControl::CControl(int x,int y,int width,int height,char  context[20],int type)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	strcpy(this->context,context);
	this->type=type;
}
void CControl::show()
{
	CTool::PointBorder(this->x,this->y,this->width,this->height);
	CTool::gotoxy(this->x+((this->width-strlen(this->context))/2)+1,this->y+1);
	cout<<this->context<<endl;
}
CControl::~CControl()
{

}
int CControl::getX()
{
	return this->x;
}
void CControl::setX(const int &x)
{
	this->x=x;
}

int CControl::getY()
{
	return this->y;
}
void CControl::setY(const int &y)
{
	this->y=y;
}

int CControl::getWidth()
{
	return this->width;
}
void CControl::setWidth(const int &width)
{
	this->width=width;
}

int CControl::getHeight()
{
	return this->height;
}
void CControl::setHeight(const int &height)
{
	this->height=height;
}

char * CControl::getContext()
{
	return this->context;
}
void CControl::setContext(int index, char ch)
{
	if(index<sizeof(this->context)/sizeof(char)-1)
	{
		if(ch=='\0')
		{
			this->context[index]=ch;
		}
		else 
		{
			this->context[index]=ch;
			this->context[index+1]='\0';
		}
	}
	else if(index==index<sizeof(this->context)/sizeof(char)-1)
	{
		this->context[index]='\0';
	}
}
void CControl::setContext(char *ch)
{
	strcpy(this->context,ch);
}
int CControl::getType()
{
	return this->type;
}
char  CControl::getContext_s()
{
	return this->context[0];
}
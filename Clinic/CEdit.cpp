#include"CEdit.h"
CEdit::CEdit(int x,int y,int width,int height,char * context,int type,int maxlen,int inputtype,int status):
CControl(x,y,width,height,context,type)
{
	this->maxlen=maxlen;
	this->inputtype=inputtype;
	this->status=status;
}
void CEdit::show()
{
	CTool::PointBorder(this->x,this->y,this->width,this->height);
	CTool::gotoxy(this->x+2,this->y+1);
	cout<<this->context<<endl;
}

int CEdit::getMaxlen()
{
	return this->maxlen;
}
void CEdit::setMaxlen(const int &maxlen)
{
	this->maxlen=maxlen;
}

int CEdit::getLnputtype()
{
	return this->inputtype;
}
void CEdit::setLnputtype(const int &lnputtype)
{
	this->inputtype=inputtype;
}

int CEdit::getStatus()
{
	return this->status;
}
void CEdit::setStatus(const int &status)
{
	this->status=status;
}

CEdit::~CEdit()
{
	cout<<"析构函数"<<endl;
}

void CEdit::inputControl(int ikey)
{
	
	int count =strlen(this->context);
	if(count>=this->maxlen)
	{
		if(ikey=='\b')
		{
			if(this->inputtype==4)
			{
				this->setContext(--count,'\0');
				this->setContext(--count,'\0');
				printf("\b \b");
				printf("\b \b");
			}
			else
			{
				this->setContext(--count,'\0');
				printf("\b \b");
			}
		}
	}
	else if(count<this->maxlen)
	{
		if(this->inputtype==0)//无限制
		{
			if(ikey!='\b')
			{
				this->setContext(count,ikey);
				if(this->status==1)
				{
					putch(ikey);
				}
				else 
				{
					putch('*');
				}
			}
		}
		else if(this->inputtype==1)//只能数字
		{
			if(ikey>='0'&&ikey<='9')
			{
				this->setContext(count,ikey);
				if(this->status==1)
				{
					putch(ikey);
				}
				else 
				{
					putch('*');
				}
			}
		}
		else if(this->inputtype==2)
		{
			if((ikey>='a'&&ikey<='z')||(ikey>='A'&&ikey<='Z'))//只能字母
			{
				this->setContext(count,ikey);
				if(this->status==1)
				{
					putch(ikey);
				}
				else 
				{
					putch('*');
				}
			}
		}
		else if(this->inputtype==3)//数字和字母
		{
			if((ikey>='a'&&ikey<='z')||(ikey>='A'&&ikey<='Z')||(ikey>='0'&&ikey<='9'))
			{
				this->setContext(count,ikey);
				if(this->status==1)
				{
					putch(ikey);
				}
				else 
				{
					putch('*');
				}
			}
		}
		else if(this->inputtype==4)//仅中文
		{
			if((unsigned char)ikey>=0XA1&&(unsigned char)ikey<=0XEF)
			{
				char ch2=getch();
				if((unsigned char)ch2>=0XA1&&(unsigned char)ch2<=0XEF)
				{
					this->setContext(count++,ikey);
					this->setContext(count,ch2);
					if(this->status==0)
						cout<<"*"<<endl;//密文
					else if(this->status==1)
					{
						printf("%c%c",ikey,ch2);//明文
					}
				}
			}
		}
		if(ikey=='\b'&&count>0)
		{
			if(this->inputtype==4)
			{
				this->setContext(--count,'\0');
				this->setContext(--count,'\0');
				printf("\b \b");
				printf("\b \b");
			}
			else
			{
				this->setContext(--count,'\0');
				printf("\b \b");
			}
		}
	}	
}
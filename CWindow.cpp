#pragma warning(disable:4786)
#include"CWindow.h"
extern escflag;
extern index;
extern remain;
extern char nownser[20];
extern CUser * denglu;
int fanyetip=0;

CWindow::CWindow(int winX,int winY,int winWidth,int winHeight)
{
	this->winX=winX;
	this->winY=winY;
	this->winWidth=winWidth;
	this->winHeight=winHeight;
	this->count=0;
	memset(this->arr,'0',sizeof(this->arr));
	this->flag=0;
}

CWindow::~CWindow()
{

}
void CWindow::addCon(CControl *con)
{
	if(this->count<sizeof(this->arr)/sizeof(CControl *))
	{
		this->arr[this->count++]=con;
	}
}
void CWindow::escMain()
{
	char buf[20];
	CTool::gotoxy(55,23);
	cout<<"确定退出系统吗"<<endl;
	CTool::gotoxy(60,24);
	cin>>buf;
	if(strcmp(buf,"yes")==0)
		escflag=0;
	remain=1;
	index =0;
}

void CWindow::paintWindow()
{
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();

	if(index!=0&&index!=1&&index!=2)
	{
		CTool::gotoxy(50,4);
		cout<<"欢迎来到门诊预约系统 "<<endl;
		CTool::gotoxy(30,7);
		cout<<"欢迎 "<<nownser<<endl;
		CTool::gotoxy(79,7);
		cout<<"日期： "<<CTool::getTime()<<endl;
	}

	

}

void CWindow::winRun()
{
	
	int rindex=0;
	CEdit * edit=NULL;
	for(int i=0;i<=this->count;i++)
		if(this->arr[i]->getType()==EDIT||this->arr[i]->getType()==BUTTON)
		{
			rindex =i;
			break;
		}
	if(this->arr[rindex]->getType()==EDIT)
		CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
	else if(this->arr[rindex]->getType()==BUTTON)
		CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
	while(1)
	{
		int ikey=CTool::getKey();
		switch(ikey)
		{
		case KEY_UP:
			rindex--;
			if(rindex<0)
				rindex=this->count-1;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
			{
				rindex--;
				if(rindex<0)
					rindex=this->count-1;				
			}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			break;
		case KEY_DOWN:
			rindex++;
			if(rindex>=this->count)
				rindex=0;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
				{
					if(rindex<this->count-1)
						rindex++;
					else 
						rindex=0;
				}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			break;
		case KEY_ESC:
			this->escMain();
			return;
		case KEY_ENTER:
			if(this->arr[rindex]->getType()==BUTTON)
			{
				this->flag=rindex;
				return;
			}
			if(this->arr[rindex]->getType()==EDIT)
			{
				rindex++;
				if(rindex>=this->count)
				rindex=0;
				while(this->arr[rindex]->getType()==LABEL)
				{
					if(rindex<this->count-1)
						rindex++;
					else 
						rindex=0;
				}
				if(this->arr[rindex]->getType()==EDIT)
					CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
				else if(this->arr[rindex]->getType()==BUTTON)
					CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			}
			break;
		default:
			if(this->arr[rindex]->getType()==EDIT)
			{
				edit =(CEdit *)(this->arr[rindex]);
				edit->inputControl(ikey);
			}
			break;
		}
	}
}

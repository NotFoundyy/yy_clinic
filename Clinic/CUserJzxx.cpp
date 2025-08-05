#include"CUserJzxx.h"
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *> dyjiuzhenList;
extern CUser * denglu;
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern printnum;
extern remain;
static int rindex=0;

CUserJzxx::CUserJzxx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(30,14,13,3,"",TABLE,4,6);
	this->shurulab=new CLabel(30,10,0,0,"就诊日期：",LABEL);
	this->timeedit1=new CButton(45,10,20,2,"",BUTTON);//2
	this->timeedit2=new CButton(72,10,20,2,"",BUTTON);
	this->zhilab=new CLabel(67,10,0,0,"至",LABEL);
	this->bianhaolab=new CLabel(34,14,0,0,"编号",LABEL);
	this->jzsjlab=new CLabel(45,14,0,0,"预约时间",LABEL);
	this->jzyylab=new CLabel(58,14,0,0,"预约医院",LABEL);
	this->jzkslab=new CLabel(70,14,0,0,"预约科室",LABEL);
	this->yslab=new CLabel(83,14,0,0,"预约医生",LABEL);
	this->jzztlab=new CLabel(96,14,0,0,"就诊状态",LABEL);
	this->zyfylab=new CLabel(80,27,0,0,"按← →翻页",LABEL);
	this->sxfylab=new CLabel(80,28,0,0,"按↑ ↓选择数据",LABEL);
	
	this->cxbut =new CButton(95,10,10,2,"查  询",BUTTON);//13
	this->cancelbut=new CButton(32,27,10,2,"返  回",BUTTON);
	
	this->addCon(table);
	this->addCon(shurulab);
	this->addCon(timeedit1);
	this->addCon(timeedit2);
	this->addCon(zhilab);
	this->addCon(bianhaolab);
	this->addCon(jzsjlab);

	this->addCon(jzyylab);
	this->addCon(jzkslab);
	this->addCon(yslab);
	this->addCon(jzztlab);
	this->addCon(zyfylab);
	this->addCon(sxfylab);
	this->addCon(cxbut);
	this->addCon(cancelbut);

}
CUserJzxx::~CUserJzxx()
{
	delete this->table;
	delete this->shurulab;
	delete this->timeedit1;
	delete this->timeedit2;
	delete this->zhilab;
	delete this->bianhaolab;
	delete this->jzsjlab;
	delete this->jzyylab;
	delete this->jzkslab;
	delete this->yslab;
	delete this->jzztlab;
	delete this->zyfylab;
	delete this->sxfylab;
	delete this->cxbut;
	delete this->cancelbut;
}
int CUserJzxx::doAction()
{
	
	if(this->flag==13)
	{
		list<char *> timelist;
		list<char *>::iterator timeit;
		list<CJiuzhen *> ::iterator it;
		timelist=CTool::getChaxun(this->timeedit1->getContext(),this->timeedit2->getContext());
		dyjiuzhenList.erase(dyjiuzhenList.begin(),dyjiuzhenList.end());
		for(it=jiuzhenList.begin();it!=jiuzhenList.end();it++)//将在区间内的信息添加到容器内
		{
			for(timeit=timelist.begin();timeit!=timelist.end();timeit++)
			{				
				if(strcmp((*it)->getJztime(),(*timeit))==0)
				{
					dyjiuzhenList.push_back(*it);					
				}
			}
		}
		return 16;
	}
	else if(this->flag==14)
	{
		this->timeedit1->setContext(" ");
		this->timeedit2->setContext(" ");
		dyjiuzhenList.erase(dyjiuzhenList.begin(),dyjiuzhenList.end());
		return 5;
	}
	else if(this->flag==2)
	{
		CButton *arr[10]={0};
		int esc=1,count=0;
		for(int i=0;i<7;i++)
		{
			arr[i]=new CButton(45,12+i*2,18,2,CTool::getTime(i),BUTTON);//绘制7天的按钮
			arr[i]->show();
			count++;
		}
		CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
		while(esc)//判断选中的哪个按钮
		{
			int ikey=CTool::getKey();
			switch(ikey)
			{
			case KEY_UP:
				rindex--;
				if(rindex<0)
					rindex=count-1;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_DOWN:
				rindex++;
				if(rindex>=count)
					rindex=0;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_ESC:
				return 16;
			case KEY_ENTER:
					esc=0;
					break;

			}
		}
		this->timeedit1->setContext(arr[rindex]->getContext());
		return 16;
	}
	else if(this->flag==3)
	{
		CButton *arr[10]={0};//绘制选中的按钮以后的日期
		int esc=1,count=0,x=rindex,xunhuan=7-rindex;
		for(int i=0;i<xunhuan;i++)
		{
			
			arr[i]=new CButton(72,12+i*2,18,2,CTool::getTime(x),BUTTON);
			arr[i]->show();
			count++;
			x++;
		}
		rindex=0;;
		CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
		
		while(esc)
		{
			int ikey=CTool::getKey();
			switch(ikey)
			{
			case KEY_UP:
				rindex--;
				if(rindex<0)
					rindex=count-1;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_DOWN:
				rindex++;
				if(rindex>=count)
					rindex=0;				
				CTool::gotoxy(arr[rindex]->getX()+arr[rindex]->getWidth()/2,arr[rindex]->getY()+1);
				break;
			case KEY_ESC:
				return 16;
			case KEY_ENTER:
					esc=0;
					break;
			}
		}
		this->timeedit2->setContext(arr[rindex]->getContext());
		return 16;
	}
	return 16;
}

	
void CUserJzxx::paintWindow()
{
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();

	CTool::gotoxy(50,4);
	cout<<"欢迎来到门诊预约系统 "<<endl;
	CTool::gotoxy(30,7);
	cout<<"欢迎 "<<denglu->getName()<<endl;
	CTool::gotoxy(79,7);
	cout<<"日期： "<<CTool::getTime()<<endl;

	CTable::showJiuzhendata(36,14,13,3);
	

	if(fanyetip==1)//打印翻页提示
	{
		CTool::gotoxy(55,27);
		cout<<"已经是第一页了"<<endl;
	}
	else if(fanyetip==2)
	{
		CTool::gotoxy(55,27);
		cout<<"已经是末尾页了"<<endl;
	}

	fanyetip=0;
}

void CUserJzxx::winRun()
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
			case KEY_LEFT:	
			
					if(userPage<=1)
					{
						fanyetip=1;			
					}
					else 
					{
						userPage--;
						fanyetip=0;
					}
				remain=1;
			
				return ;
			case KEY_RIGHT:
				
					
					if(userPage>=pageCount)
					{
						fanyetip=2;		
					}
					else
					{
						userPage++;
						fanyetip=0;
					}
				remain=1;
				
				return ;
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
#include"CDoctorJjxx.h"
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>::iterator jiuzhenit;
extern int userPage;
extern int pageCount;
extern int fanyetip;
extern char nownser[20];//记录登录用户
extern int remain;
extern printnum;
CDoctorJjxx::CDoctorJjxx(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{

	this->table =new CTable(31,12,20,3,"",TABLE,4,3);
	this->bianhaolab=new CLabel(40,12,0,0,"编号",LABEL);
	this->jzIDlab=new CLabel(55,12,0,0,"就诊用户ID",LABEL);
	this->zhuangtailab=new CLabel(78,12,0,0,"状态",LABEL);
	this->zyfylab=new CLabel(80,27,0,0,"按← →翻页",LABEL);
	this->sxfylab=new CLabel(80,28,0,0,"按↑ ↓选择数据",LABEL);
	this->cancelbut=new CButton(32,27,10,2,"返  回",BUTTON);//6

	this->rolebut1=new CButton(29,15,-1,-1,"1",BUTTON);//7
	this->rolebut2=new CButton(29,18,-1,-1,"1",BUTTON);
	this->rolebut3=new CButton(29,21,-1,-1,"1",BUTTON);

	

	this->addCon(table);
	this->addCon(bianhaolab);
	this->addCon(jzIDlab);
	this->addCon(zhuangtailab);
	this->addCon(zyfylab);
	this->addCon(sxfylab);
	this->addCon(cancelbut);
	this->addCon(rolebut1);
	this->addCon(rolebut2);
	this->addCon(rolebut3);



}
CDoctorJjxx::~CDoctorJjxx()
{
	delete this->table;
	delete this->bianhaolab;
	delete this->jzIDlab;
	delete this->zhuangtailab;
	delete this->zyfylab;
	delete this->sxfylab;
	delete this->cancelbut;
	delete this->rolebut1;
	delete this->rolebut2;
	delete this->rolebut3;
}
int CDoctorJjxx::doAction()
{	
	int i=0;
	jiuzhenit=jiuzhenList.begin();
	switch(this->flag)
	{
	case 7://将迭代器指到要更改信息的位置
		advance(jiuzhenit,((userPage-1)*3+2));
		return 18;
	case 8:
		advance(jiuzhenit,((userPage-1)*3+2));
		return 18;
	case 9:
		advance(jiuzhenit,((userPage-1)*3+2));
		return 18;
	case 6:
		return 4;
	}
	return 17;
}

void CDoctorJjxx::paintWindow()
{
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<7;i++)
		this->arr[i]->show();
	
	CTool::gotoxy(50,4);
	cout<<"欢迎来到门诊预约系统 "<<endl;
	CTool::gotoxy(30,7);
	cout<<"欢迎 "<<nownser<<endl;
	CTool::gotoxy(79,7);
	cout<<"日期： "<< CTool::getTime()<<endl;


	CTable::showDoctorCx(31,12,20,3);
	

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


void CDoctorJjxx::winRun()
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
				rindex=6+printnum;
			while(this->arr[rindex]->getType()==LABEL||this->arr[rindex]->getType()==TABLE)
			{
				rindex--;
				if(rindex<0)
					rindex=6+printnum;				
			}
			if(this->arr[rindex]->getType()==EDIT)
				CTool::gotoxy(this->arr[rindex]->getX()+2+strlen(this->arr[rindex]->getContext()),this->arr[rindex]->getY()+1);
			else if(this->arr[rindex]->getType()==BUTTON)
			{
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
				
			}
			break;
		case KEY_DOWN:
			rindex++;
			if(rindex>6+printnum)
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
			{
				CTool::gotoxy(this->arr[rindex]->getX()+this->arr[rindex]->getWidth()/2,this->arr[rindex]->getY()+1);
			}
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


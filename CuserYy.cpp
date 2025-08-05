#include"CUserYy.h"
extern char nownser[20];
extern map<string ,list<CDoctor *> > keshi_ysMap;
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>quhaoList;
extern CUser * denglu;
CUserYy::CUserYy(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->xzyylab=new CLabel(40,9,0,0,"选择医院",LABEL);
	this->xzkslab=new CLabel(40,12,0,0,"选择科室",LABEL);
	this->xzyslab=new CLabel(40,15,0,0,"选择医生",LABEL);
	this->xzsjlab=new CLabel(40,18,0,0,"选择时间",LABEL);
	this->mslab=new CLabel(40,21,0,0,"描述",LABEL);

	this->xzyyedit=new CLabel(50,9,0,0,"省立医院",LABEL);
	this->xzksedit=new CButton(50,12,33,2,"",BUTTON);//6
	this->xzysedit=new CButton(50,15,33,2,"",BUTTON);//7
	this->xzsjedit1=new CButton(50,18,18,2,"      ↓",BUTTON);//8
	this->xzsjedit2=new CButton(69,18,14,2,"      ↓",BUTTON);//9
	this->msedit=new CEdit(50,21,33,2,"",EDIT,18,4,1);

	this->okButton=new CButton(37,27,10,2,"确  定",BUTTON); //11
	this->cancelButton=new CButton(75,27,10,2,"返  回",BUTTON);

	this->quhao=3;

	this->addCon(xzyylab);
	this->addCon(xzkslab);
	this->addCon(xzyslab);
	this->addCon(xzsjlab);
	this->addCon(mslab);
	this->addCon(xzyyedit);
	this->addCon(xzksedit);
	this->addCon(xzysedit);
	this->addCon(xzsjedit1);
	this->addCon(xzsjedit2);
	this->addCon(msedit);
	this->addCon(okButton);
	this->addCon(cancelButton);
}
CUserYy::~CUserYy()
{
	delete this->xzyylab;
	delete this->xzkslab;
	delete this->xzyslab;
	delete this->xzsjlab;
	delete this->mslab;
	delete this->xzyyedit;
	delete this->xzksedit;
	delete this->xzysedit;
	delete this->xzsjedit1;
	delete this->xzsjedit2;
	delete this->msedit;
	delete this->okButton;
	delete this->cancelButton;
}
int CUserYy::doAction()
{
	
	if(this->flag==6)
	{
		CButton *arr[5]={0};
		CButton *but1=new CButton(50,14,33,2,"眼科",BUTTON);
		CButton *but2=new CButton(50,16,33,2,"鼻科",BUTTON);
		CButton *but3=new CButton(50,18,33,2,"儿科",BUTTON);
		int esc=1;
		int count=3;
		int flag=0;
		int rindex=0;
		but1->show();
		but2->show();
		but3->show();
		arr[0]=but1;
		arr[1]=but2;
		arr[2]=but3;
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
				break;
			case KEY_ENTER:
					flag=rindex;
					esc=0;
					break;
			}

		}
			if(flag==0)//根据返回值判断选中内容
				this->xzksedit->setContext("眼科");
			else if(flag==1)
				this->xzksedit->setContext("鼻科");
			else if(flag==2)
				this->xzksedit->setContext("儿科");
			this->xzysedit->setContext(0,'\0');
			return 14;
	}

	else if(this->flag==7)
	{
		CTable::keshi_ys();
		CButton *arr[10]={0};
		int rindex=0,esc=1,count=0;
		map<string, list<CDoctor *> >::iterator mapit =keshi_ysMap.begin();

		list<CDoctor *>::iterator listit;
		if(strcmp(this->xzksedit->getContext(),"眼科")==0)
		{
			mapit=keshi_ysMap.find("眼科");//科室相符 将医生添加到容器内
			listit=mapit->second.begin();
			for(int i=0;listit!=mapit->second.end();listit++,i++)
			{
				arr[i]=new CButton(50,17+i*2,33,2,(*listit)->getName(),BUTTON);//根据容器绘制按钮
				arr[i]->show();
				count++;
			}
		}
		else if(strcmp(this->xzksedit->getContext(),"鼻科")==0)
		{
			mapit=keshi_ysMap.find("鼻科");
			listit=mapit->second.begin();
			
			for(int i=0;listit!=mapit->second.end();listit++,i++)
			{
				arr[i]=new CButton(50,17+i*2,33,2,(*listit)->getName(),BUTTON);
				arr[i]->show();
				count++;
			}
		}
		else if(strcmp(this->xzksedit->getContext(),"儿科")==0)
		{
			mapit=keshi_ysMap.find("儿科");
			listit=mapit->second.begin();
			
			for(int i=0;listit!=mapit->second.end();listit++,i++)
			{
				arr[i]=new CButton(50,17+i*2,33,2,(*listit)->getName(),BUTTON);
				arr[i]->show();			
				count++;
			}
		}
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
				break;
			case KEY_ENTER:
					flag=rindex;
					esc=0;
					break;
			}
		}
		this->xzysedit->setContext(arr[flag]->getContext());			
	}


	else if(this->flag==8)
	{
		CButton *arr[10]={0};
		int rindex=0,esc=1,count=0;
		for(int i=0;i<7;i++)
			{
				arr[i]=new CButton(50,20+i*2,18,2,CTool::getTime(i),BUTTON);
				arr[i]->show();
				count++;
			}
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
				break;
			case KEY_ENTER:
					//flag=rindex;
					esc=0;
					break;
			}
		}
		this->xzsjedit1->setContext(arr[rindex]->getContext());
	}

	else if(this->flag==9)
	{
		list<CJiuzhen *>::iterator it;
		int time1=0,time2=0;
		CButton *arr[10]={0};
		int rindex=0,esc=1;
		for(it=jiuzhenList.begin();it!=jiuzhenList.end();it++)
		{			
			if((strcmp((*it)->getDoctor(),this->xzysedit->getContext())==0)&&(strcmp((*it)->getJztime(),this->xzsjedit1->getContext())==0))
			{	
				if(strcmp((*it)->getHour(),"09:00~10:00")==0)
					time1++;
				else if(strcmp((*it)->getHour(),"10:00~11:00")==0)
					time2++;
			}	
		}
		if(time1==2)
		{
			arr[0]=new CButton(69,20,14,2,"09:00~10:00",BUTTON);
			arr[1]=new CButton(69,20,14,2,"10:00~11:00",BUTTON);
		}
		else 
		{
			arr[0]=new CButton(69,20,14,2,"09:00~10:00",BUTTON);
			arr[1]=new CButton(69,22,14,2,"10:00~11:00",BUTTON);
		}
		if(time1!=2)
			arr[0]->show();
		if(time2!=2)
			arr[1]->show();
		time1=0;
		time2=0;
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
				break;
			case KEY_ENTER:
					flag=rindex;
					esc=0;
					break;
			}
		}
		this->xzsjedit2->setContext(arr[rindex]->getContext());
	}
	else if(this->flag==11)
	{
		quhaoList.push_front(new CJiuzhen(this->quhao++,CTool::getTime(),this->xzsjedit1->getContext(),this->xzsjedit2->getContext(),"省立医院",this->xzksedit->getContext(),this->xzysedit->getContext(),"未就诊",denglu->getID(),this->msedit->getContext(),"10"));
		this->xzksedit->setContext(0,'\0');
		this->xzysedit->setContext(0,'\0');
		this->xzsjedit1->setContext(0,'\0');
		this->xzsjedit2->setContext(0,'\0');
		this->msedit->setContext(0,'\0');
		return 13;
		
	}
	else if(this->flag==12)
	{
		this->xzksedit->setContext(0,'\0');
		this->xzysedit->setContext(0,'\0');
		this->xzsjedit1->setContext(0,'\0');
		this->xzsjedit2->setContext(0,'\0');
		this->msedit->setContext(0,'\0');
		return 13;
	}
	return 14;
}

#include"CUserQhxg.h"
extern list<CJiuzhen *> jiuzhenList;
extern list<CJiuzhen *>::iterator jzit;
extern list<CJiuzhen *>quhaoList;
CUserQhxg::CUserQhxg(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->tip1lab=new CLabel(35,12,0,0,"提示",LABEL);
	this->tip2lab=new CLabel(53,16,0,0,"当前正在排队人数   人！！！",LABEL);

	this->qhbut=new CButton(44,22,12,2,"取号",BUTTON);//2
	this->qxqhbut=new CButton(60,22,12,2,"取消预约",BUTTON);//3
	this->cancelbut=new CButton(76,22,12,2,"取消",BUTTON);

	this->addCon(tip1lab);
	this->addCon(tip2lab);
	this->addCon(qhbut);
	this->addCon(qxqhbut);
	this->addCon(cancelbut);
	

	
}
CUserQhxg::~CUserQhxg()
{
	delete this->tip1lab;
	delete this->tip2lab;
	delete this->qhbut;
	delete this->qxqhbut;
	delete this->cancelbut;
}
int CUserQhxg::doAction()
{
	switch(this->flag)
	{
	case 2://取号
		jiuzhenList.push_front(*jzit);
		(*jzit)->setZhuangtai("等待就诊");
		quhaoList.erase(jzit);
		break;
	case 3:
		if(strcmp(CTool::getTime(),(*jzit)->getJztime())==0)//时间不足24小时不允许取消预约
		{
			CTool::gotoxy(63,25);
			cout<<"取消失败"<<endl;
			getch();
		}
		else 
			(*jzit)->setZhuangtai("已取消");
	}
	return 0;
}

void CUserQhxg::paintWindow()
{
	
	
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	
	for(int i=0;i<this->count;i++)
		this->arr[i]->show();
	CTool::gotoxy(71,17);
	cout<<jiuzhenList.size()<<endl;

}
#include"CDoctorJzjl.h"
extern list<CJiuzhen *>::iterator jiuzhenit;
extern CUser * denglu;
CDoctorJzjl::CDoctorJzjl(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{


	this->IDlab=new CLabel(40,10,0,0,"�û�ID",LABEL);
	this->yymslab=new CLabel(40,15,0,0,"ԤԼ����",LABEL);
	this->jzmslab=new CLabel(40,20,0,0,"��������",LABEL);

	this->IDedit=new CLabel(55,10,0,0,"�û�ID",LABEL);
	this->yymsedit=new CLabel(55,15,0,0,"�û�ID",LABEL);
	this->jzmsedit=new CEdit(55,20,33,2,"",EDIT,11,4,1);

	this->okbut=new CButton(40,27,10,2,"ȷ  ��",BUTTON);//6
	this->cancelbut=new CButton(62,27,10,2,"��  ��",BUTTON);
	
	this->tip=new CLabel(50,23,0,0,"",LABEL);

	this->addCon(IDlab);
	this->addCon(yymslab);
	this->addCon(jzmslab);
	this->addCon(IDedit);
	this->addCon(yymsedit);
	this->addCon(jzmsedit);
	this->addCon(okbut);
	this->addCon(cancelbut);
	this->addCon(tip);

	

}
CDoctorJzjl::~CDoctorJzjl()
{
	delete this->IDlab;
	delete this->yymslab;
	delete this->jzmslab;
	delete this->IDedit;
	delete this->yymsedit;
	delete this->jzmsedit;
	delete this->okbut;
	delete this->cancelbut;
	delete this->tip;
}
int CDoctorJzjl::doAction()
{
	
	switch(this->flag)
	{
	case 6:
		if(strlen(this->jzmsedit->getContext())==0)
		{
			this->tip->setContext("������Ϣ����Ϊ��");
			return 18;
		}
		else
		{
			(*jiuzhenit)->setYymiaoshu(this->jzmsedit->getContext());
			(*jiuzhenit)->setZhuangtai("�Ѿ���");
			this->jzmsedit->setContext(0,'\0');
		}
		return 17;
	}
	return 17;
}

void CDoctorJzjl::paintWindow()
{
	this->IDedit->setContext((*jiuzhenit)->getUserid());
	this->yymsedit->setContext((*jiuzhenit)->getYymiaoshu());
	int i;
	CTool::PointBorder(this->winX,this->winY,this->winWidth,this->winHeight);
	for(i=0;i<this->count;i++)
		this->arr[i]->show();
	CTool::gotoxy(50,4);
	cout<<"��ӭ��������ԤԼϵͳ "<<endl;
	CTool::gotoxy(30,7);
	cout<<"��ӭ "<<denglu->getName()<<endl;
	CTool::gotoxy(79,7);
	cout<<"���ڣ� "<<CTool::getTime()<<endl;

}


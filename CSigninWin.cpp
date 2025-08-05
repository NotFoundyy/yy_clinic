#include"CSigninwin.h"
#pragma warning(disable:4786)
extern map<string ,CUser *> userMap;


CSigninwin::CSigninwin(int winX,int winY,int winWidth,int winHeight):CWindow(winX,winY,winWidth,winHeight)
{
	this->title=new CLabel(55,3,0,0,"注册界面",LABEL);
	this->idnumlab=new CLabel(36,7,0,0,"手机号码",LABEL);
	this->authcodelab=new CLabel(36,12,0,0,"验证码",LABEL);
	this->messagelab1=new CLabel(55,16,0,0,"",LABEL);
	this->messagelab2=new CLabel(68,16,0,0,"",LABEL);

	this->idnumedit=new CEdit(47,7,33,2,"",EDIT,11,3,1);
	this-> authcodeedit=new CEdit(47,12,33,2,"",EDIT,6,3,0);

	this->authcodebut = new CButton(85,12,12,2,"获取验证码",BUTTON);//7
	this->okbut = new CButton(35,20,10,2,"确  定",BUTTON);
	this->cancelbut = new CButton(75,20,10,2,"返  回",BUTTON);


	this->addCon(title);
	this->addCon(idnumlab);
	this->addCon(authcodelab);
	this->addCon(messagelab1);
	this->addCon(messagelab2);
	this->addCon(idnumedit);
	this->addCon(authcodeedit);
	this->addCon(authcodebut);
	this->addCon(okbut);
	this->addCon(cancelbut);

	
}
CSigninwin::~CSigninwin()
{
	delete this->title;
	delete this->idnumlab;
	delete this->authcodelab;
	delete this->messagelab1;
	delete this->messagelab2;
	delete this->idnumedit;
	delete this->authcodeedit;
	delete this->authcodebut;
	delete this->okbut;
	delete this->cancelbut;
}

int CSigninwin::doAction()
{
	int i=0,num=0;
	char buf[20];
	srand(time(NULL));
	switch(this->flag)
	{
	case 7:

		strcpy(buf,"验证码信息为");
		messagelab1->setContext(buf);
		while(num<100000)//判断有没有6位数
			num=num*10+(rand()%10);
		sprintf(buf,"%d",num);
		messagelab2->setContext(buf);
		return 1;
	case 8:
		return Signincheck();
	case 9:
		this->idnumedit->setContext(0,'\0');
		this->authcodeedit->setContext(0,'\0');
		this->messagelab1->setContext(0,'\0');
		return 0;
	}
	return 1;
}

int CSigninwin::Signincheck()
{
	int i=0,flag=0;
	map<string,CUser *>::iterator it;
	for(it=userMap.begin();it!=userMap.end();it++,i++)
		if(strcmp(it->second->getID(),this->idnumedit->getContext())==0)
			break;
	if(i<userMap.size())
	{
		this->messagelab1->setContext("手机号存在");
		this->messagelab2->setContext(0,'\0');
		flag=1;
		
	}
	else if(strcmp(this->authcodeedit->getContext(),this->messagelab2->getContext())==0
		&&strlen(this->idnumedit->getContext())==11&&(this->idnumedit->getContext_s())=='1')
	{
		
		userMap.insert(make_pair(this->idnumedit->getContext(),new CUser(this->idnumedit->getContext(),"00","未实名","123456",3)));
		//CData::WriteUserFile();
		flag=2;
		this->messagelab1->setContext(0,'\0');
		this->messagelab2->setContext(0,'\0');
	}
	else
	{
		this->messagelab1->setContext("注册失败");
		this->messagelab2->setContext(0,'\0');
		flag=1;
	}
	
	this->idnumedit->setContext(0,'\0');
	this->authcodeedit->setContext(0,'\0');
	return flag;
}





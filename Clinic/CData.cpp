#include"CData.h"
#pragma warning(disable:4786)
extern map<string ,CUser *> userMap;//�洢�û���Ϣ
extern map<string ,CDoctor *> doctorMap;//�洢ҽ����Ϣ
extern map<string ,CAdmin *> adminMap;//�洢����Ա��Ϣ
extern map<string ,CKeshi *> keshiMap;//�洢������Ϣ
extern list<CJiuzhen *> jiuzhenList;
CData::CData()
{
	
}
CData::~CData()
{
	
}


void CData::WriteUserFile()
{
	char buf[100]={0};
	map<string ,CUser *>::iterator it;
	fstream file;
	file.open("./data/user.txt",fstream::out);
	
	//�ж��Ƿ��
	if(file.is_open())
	{
		for(it=userMap.begin();it!=userMap.end();it++)
		{
			//׷��
			
			sprintf(buf,"%s %s %s %s %d\n",it->second->getID(),it->second->getIDnum(),it->second->getName(),it->second->getMima(),it->second->getRole());
			file<<buf;
		}
	}
	

	file.close();	
}
void CData::ReadUserFile()
{
	char resbuf[100]={0};
	char id[15]={0};
	char idnum[20]={0};
	char name[20]={0};
	char mima[20]={0};
	char role[2]={0};

	
	fstream file;
	file.open("./data/user.txt",fstream::in);
	//�ж��Ƿ��
	if(file.is_open())
	{
		//�ж��Ƿ񵽴��ļ�ĩβ
		while(file.peek()!=EOF)
		{
			//��������ʼ��
			memset(resbuf,'0',sizeof(resbuf));
			//��ȡһ��
			file.getline(resbuf,sizeof(resbuf));
			sscanf(resbuf,"%s %s %s %s %s",id,idnum,name,mima,role);
			CUser * puser =new CUser(id,idnum,name,mima,atoi(role));
			userMap.insert(make_pair(puser->getID(),puser));
		}
	}else{
		cout<<"�ļ���ʧ��"<<endl;
	}
	file.close();
}

void CData::WriteDoctorFile()
{
	char buf[100]={0};
	map<string ,CDoctor *>::iterator it;
	fstream file;
	file.open("./data/doctor.txt",fstream::out);
	
	//�ж��Ƿ��
	if(file.is_open())
	{
		for(it=doctorMap.begin();it!=doctorMap.end();it++)
		{
			//׷��
			
			sprintf(buf,"%s %s %s %s %s %s %s %d\n",it->second->getID(),it->second->getName(),it->second->getMima(),it->second->getSsks(),it->second->getSsyy(),it->second->getZhiwei(),it->second->getJj(),it->second->getRole());
			file<<buf;
		}
	}
	file.close();	
}

void CData::ReadDoctorFile()
{
	char resbuf[100]={0};
	char id[15]={0};
	char name[20]={0};
	char mima[20]={0};
	char zhiwei[20]={0};
	char ssks[20]={0};
	char ssyy[20]={0};
	char jj[20]={0};
	char role[2]={0};

	
	fstream file;
	file.open("./data/doctor.txt",fstream::in);
	//�ж��Ƿ��
	if(file.is_open())
	{
		//�ж��Ƿ񵽴��ļ�ĩβ
		while(file.peek()!=EOF)
		{
			//��������ʼ��
			memset(resbuf,'0',sizeof(resbuf));
			//��ȡһ��
			file.getline(resbuf,sizeof(resbuf));
			sscanf(resbuf,"%s %s %s %s %s %s %s %s",id,name,mima,zhiwei,ssks,ssyy,jj,role);
			CDoctor * puser =new CDoctor(id,name,mima,zhiwei,ssks,ssyy,jj,atoi(role));
			doctorMap.insert(make_pair(puser->getID(),puser));
		}
	}else{
		cout<<"�ļ���ʧ��"<<endl;
	}
	file.close();
}

void CData::WriteAdminFile()
{
	char buf[100]={0};
	map<string ,CAdmin *>::iterator it;
	fstream file;
	file.open("./data/admin.txt",fstream::out);
	
	//�ж��Ƿ��
	if(file.is_open())
	{
		for(it=adminMap.begin();it!=adminMap.end();it++)
		{
			//׷��
			
			sprintf(buf,"%s %s %s %s %d\n",it->second->getID(),it->second->getIDnum(),it->second->getName(),it->second->getMima(),it->second->getRole());
			file<<buf;
		}
	}
	file.close();	
}

void CData::ReadAdminFile()
{
	char resbuf[100]={0};
	char id[15]={0};
	char idnum[20]={0};
	char name[20]={0};
	char mima[20]={0};
	char role[2]={0};

	
	fstream file;
	file.open("./data/admin.txt",fstream::in);
	//�ж��Ƿ��
	if(file.is_open())
	{
		//�ж��Ƿ񵽴��ļ�ĩβ
		while(file.peek()!=EOF)
		{
			//��������ʼ��
			memset(resbuf,'0',sizeof(resbuf));
			//��ȡһ��
			file.getline(resbuf,sizeof(resbuf));
			sscanf(resbuf,"%s %s %s %s %s",id,idnum,name,mima,role);
			CAdmin * puser =new CAdmin(id,idnum,name,mima,atoi(role));
			adminMap.insert(make_pair(puser->getID(),puser));
		}
	}else{
		cout<<"�ļ���ʧ��"<<endl;
	}
	file.close();
}

void CData::WriteKeshiFile()
{
	char buf[100]={0};
	map<string ,CKeshi *>::iterator it;
	fstream file;
	file.open("./data/keshi.txt",fstream::out);
	
	//�ж��Ƿ��
	if(file.is_open())
	{
		for(it=keshiMap.begin();it!=keshiMap.end();it++)
		{
			//׷��
			
			sprintf(buf,"%s %s %s\n",it->second->getID(),it->second->getName(),it->second->getXinxi());
			file<<buf;
		}
	}
	file.close();	
}

void CData::ReaKeshiFile()
{
	char resbuf[100]={0};
	char id[15]={0};
	char name[20]={0};
	char xinxi[20]={0};

	fstream file;
	file.open("./data/doctor.txt",fstream::in);
	//�ж��Ƿ��
	if(file.is_open())
	{
		//�ж��Ƿ񵽴��ļ�ĩβ
		while(file.peek()!=EOF)
		{
			//��������ʼ��
			memset(resbuf,'0',sizeof(resbuf));
			//��ȡһ��
			file.getline(resbuf,sizeof(resbuf));
			sscanf(resbuf,"%s %s %s ",id,name,xinxi);
			CKeshi * puser =new CKeshi(id,name,xinxi);
			keshiMap.insert(make_pair(puser->getName(),puser));
		}
	}else{
		cout<<"�ļ���ʧ��"<<endl;
	}
	file.close();
}

void CData::WriteJiuzhenFile()
{
	char buf[100]={0};
	list<CJiuzhen *>::iterator it;
	fstream file;
	file.open("./data/jiuzhen.txt",fstream::out);
	
	//�ж��Ƿ��
	if(file.is_open())
	{
		for(it=jiuzhenList.begin();it!=jiuzhenList.end();it++)
		{
			//׷��		
			sprintf(buf,"%d %s %s %s %s %s %s %s %s %s %s\n",
			(*it)->getID(),(*it)->getYytime(),(*it)->getJztime(),(*it)->getHour(),(*it)->getYiyuan(),(*it)->getKeshi(),(*it)->getDoctor(),(*it)->getZhuangtai(),(*it)->getUserid(),(*it)->getYymiaoshu(),(*it)->getJzmiaoshu());
			file<<buf;
		}
	}
	file.close();	
}

void CData::ReadJiuzhenFile()
{
	char resbuf[100]={0};
	char id[15]={0};
	char yytime[20]={0};
	char jztime[20]={0};
	char hour[20]={0};
	char yiyuan[20]={0};
	char keshi[20]={0};
	char doctor[20]={0};
	char zhuangtai[20]={0};
	char userid[20]={0};
	char yymiaoshu[20]={0};
	char jzmiaoshu[20]={0};

	fstream file;
	file.open("./data/jiuzhen.txt",fstream::in);
	//�ж��Ƿ��
	if(file.is_open())
	{
		//�ж��Ƿ񵽴��ļ�ĩβ
		while(file.peek()!=EOF)
		{
			//��������ʼ��
			memset(resbuf,'0',sizeof(resbuf));
			//��ȡһ��
			file.getline(resbuf,sizeof(resbuf));
			sscanf(resbuf,"%s %s %s %s %s %s %s %s %s %s %s ",id,yytime,jztime,hour,yiyuan,keshi,doctor,zhuangtai,userid,yymiaoshu,jzmiaoshu);
			CJiuzhen * puser =new CJiuzhen(atoi(id),yytime,jztime,hour,yiyuan,keshi,doctor,zhuangtai,userid,yymiaoshu,jzmiaoshu);
			jiuzhenList.push_back(puser);
		}
	}else{
		cout<<"�ļ���ʧ��"<<endl;
	}
	file.close();
}
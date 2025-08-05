#include"CDoctor.h"

CDoctor::CDoctor()
{
	memset(this->id,'0',sizeof(this->id));
	memset(this->name,'0',sizeof(this->name));
	memset(this->mima,'0',sizeof(this->mima));
	memset(this->zhiwei,'0',sizeof(this->zhiwei));
	memset(this->ssks,'0',sizeof(this->ssks));
	memset(this->ssyy,'0',sizeof(this->ssyy));
	memset(this->jj,'0',sizeof(this->jj));
	this->role=2;
}
CDoctor::CDoctor(char * id,char *name,char* mima,char *zhiwei,char *ssks,char *ssyy,char *jj,int role)
{
	strcpy(this->id,id);
	strcpy(this->name,name);
	strcpy(this->mima,mima);
	strcpy(this->zhiwei,zhiwei);
	strcpy(this->ssks,ssks);
	strcpy(this->ssyy,ssyy);
	strcpy(this->jj,jj);
	this->role=role;
}
CDoctor::~CDoctor()
{
	
}
char * CDoctor::getID()
{
	return this->id;
}
void CDoctor::setID(char * id)
{
	strcpy(this->id,id);
}

char * CDoctor::getMima()
{
	return this->mima;
}
void CDoctor::setMima(char * mima)
{
	strcpy(this->mima,mima);
}

int CDoctor::getRole()
{
	return this->role;
}
void CDoctor::setRole(int role)
{
	this->role=role;
}

char * CDoctor::getName()
{
	return this->name;
}
void CDoctor::setName(char * name)
{
	strcpy(this->name,name);
}

char * CDoctor::getSsks()
{
	return this->ssks;
}
void CDoctor::setSsks(char * ssks)
{
	strcpy(this->ssks,ssks);
}
char * CDoctor::getSsyy()
{
	return this->ssyy;
}
void CDoctor::setSsyy(char * ssyy)
{
	strcpy(this->ssyy,ssyy);
}
char * CDoctor::getZhiwei()
{
	return this->zhiwei;
}
void CDoctor::setZhiwei(char * zhiwei)
{
	strcpy(this->zhiwei,zhiwei);
}
char * CDoctor::getJj()
{
	return this->jj;
}
void CDoctor::setJj(char * jj)
{
	strcpy(this->jj,jj);
}



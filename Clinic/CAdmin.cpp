#include"CAdmin.h"

CAdmin::CAdmin()
{
	
}
CAdmin::CAdmin(char * id,char *mima,int role)
{
	strcpy(this->id,id);
	strcpy(this->mima,mima);
	this->role=role;
	memset(this->name,'0',sizeof(this->name));
	memset(this->idnum,'0',sizeof(this->idnum));
}
CAdmin::CAdmin(char * id,char *idnum,char* name,char *mima,int role)
{
	strcpy(this->id,id);
	strcpy(this->idnum,idnum);
	strcpy(this->name,name);
	strcpy(this->mima,mima);
	this->role=role;
}
CAdmin::~CAdmin()
{

}
char * CAdmin::getID()
{
	return this->id;
}
void CAdmin::setID(char * id)
{
	strcpy(this->id,id);
}

char * CAdmin::getMima()
{
	return this->mima;
}
void CAdmin::setMima(char * mima)
{
	strcpy(this->mima,mima);
}

int CAdmin::getRole()
{
	return this->role;
}
void CAdmin::setRole(int role)
{
	this->role=role;
}

char * CAdmin::getName()
{
	return this->name;
}
void CAdmin::setName(char * name)
{
	strcpy(this->name,name);
}

char * CAdmin::getIDnum()
{
	return this->idnum;
}
void CAdmin::setIDnum(char * idnum)
{
	strcpy(this->idnum,idnum);
}

#include "CUser.h"

CUser::CUser()
{
	
}
CUser::CUser(char * id,char *idnum,char* name,char *mima,int role)
{
	strcpy(this->id,id);
	strcpy(this->idnum,idnum);
	strcpy(this->name,name);
	strcpy(this->mima,mima);
	this->role=role;
}
CUser::~CUser()
{
	
}
char * CUser::getID()
{
	return this->id;
}
void CUser::setID(char * id)
{
	strcpy(this->id,id);
}

char * CUser::getMima()
{
	return this->mima;
}
void CUser::setMima(char * mima)
{
	strcpy(this->mima,mima);
}

int CUser::getRole()
{
	return this->role;
}
void CUser::setRole(int role)
{
	this->role=role;
}

char * CUser::getName()
{
	return this->name;
}
void CUser::setName(char * name)
{
	strcpy(this->name,name);
}

char * CUser::getIDnum()
{
	return this->idnum;
}
void CUser::setIDnum(char * idnum)
{
	strcpy(this->idnum,idnum);
}

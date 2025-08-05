#include "CKeshi.h"

CKeshi::CKeshi()
{
	memset(this->name,'0',sizeof(this->name));
}
CKeshi::CKeshi(char *id,char* name,char * xinxi)
{
	strcpy(this->id,id);
	strcpy(this->name,name);
	strcpy(this->xinxi,xinxi);
}
CKeshi::~CKeshi()
{
	
}

char * CKeshi::getID()
{
	return this->id;
}
void CKeshi::setID(char * id)
{
	strcpy(this->id,id);
}
char * CKeshi::getName()
{
	return this->name;
}
void CKeshi::setName(char * name)
{
	strcpy(this->name,name);
}
char * CKeshi::getXinxi()
{
	return this->xinxi;
}
void CKeshi::setXinxi(char * xinxi)
{
	strcpy(this->xinxi,xinxi);
}

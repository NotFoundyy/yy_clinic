#ifndef CKESHI_H
#define CKESHI_H

#include<string>

class CKeshi
{
public:
	CKeshi();
	CKeshi(char *id,char* name,char * xinxi);
	~CKeshi();

	char * getID();
	void setID(char * id);
	char * getName();
	void setName(char * name);
	char * getXinxi();
	void setXinxi(char * xinxi);

private:
	char id[20];
	char name[20];
	char xinxi[20];
};
#endif
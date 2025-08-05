#ifndef CUSER_H
#define CUSER_H

#include<string>

class CUser
{
public:
	CUser();
	CUser(char * id,char *idnum,char* name,char *mima,int role);
	~CUser();

	char * getID();
	void setID(char * id);
	char * getMima();
	void setMima(char * mima);
	int getRole();
	void setRole(int role);
	char * getName();
	void setName(char * name);
	char * getIDnum();
	void setIDnum(char * name);
private:
	char id[15];
	char idnum[20];
	char name[20];
	char mima[20];
	int role;//1管理员2医生3用户	
};
#endif
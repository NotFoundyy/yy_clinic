#ifndef CDOCTOR_H
#define CDOCTOR_H

#include<string>

class CDoctor
{
public:
	CDoctor();
	CDoctor(char * id,char *name,char* mima,char *zhiwei,char *ssks,char *ssyy,char *jj,int role);
	~CDoctor();

	char * getID();
	void setID(char * id);
	char * getName();
	void setName(char * name);
	char * getMima();
	void setMima(char * mima);
	char * getSsks();
	void setSsks(char * ssks);
	char * getSsyy();
	void setSsyy(char * ssyy);
	char * getZhiwei();
	void setZhiwei(char * zhiwei);
	char * getJj();
	void setJj(char * jj);
	int getRole();
	void setRole(int role);

private:
	char id[15];
	char name[20];
	char mima[20];
	char zhiwei[20];
	char ssks[20];
	char ssyy[20];
	char jj[20];
	int role;//1管理员2医生3用户	
};
#endif
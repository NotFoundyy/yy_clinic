#ifndef CEDIT_H
#define CEDIT_H

#include"CTool.h"
#include"CControl.h"

#include <iostream>
using namespace std;

class CEdit:public CControl
{
public:
	
	CEdit(int x,int y,int width,int height,char * context,int type,int maxlen,int inputtype,int status);
	void inputControl(int ikey);

	int getMaxlen();
	void setMaxlen(const int &maxlen);

	int getLnputtype();
	void setLnputtype(const int &lnputtype);

	int getStatus();
	void setStatus(const int &status);

	~CEdit();
	void show();
private:

	int maxlen;
	int inputtype;
	int status;
};

#endif
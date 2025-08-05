#ifndef CCONTROL_H
#define CCONTROL_H

#include <iostream>
#include"CTool.h"
#include<list>
#include<string>
using namespace std;

#define LABEL 1
#define BUTTON 2
#define EDIT 3
#define TABLE 4

class CControl
{
public:
	CControl(int x,int y,int width,int height,char  context[20],int type);
	~CControl();

	int getX();
	void setX(const int &x);

	int getY();
	void setY(const int &y);

	int getWidth();
	void setWidth(const int &width);

	int getHeight();
	void setHeight(const int &height);

	char * getContext();
	char  getContext_s();
	void setContext(int index,char ch);
	void setContext(char *ch);

	int getType();

	virtual void show()=0;
protected:
	int x;
	int y;
	int width;
	int height;
	char context[30];
	int type;
};

#endif
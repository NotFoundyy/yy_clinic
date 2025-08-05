#ifndef CLABEL_H
#define CLABEL_H

#include"CTool.h"
#include"CControl.h"

#include <iostream>
#include<string>
using namespace std;

class CLabel:public CControl
{
public:
	
	CLabel(int x,int y,int width,int height,char context[20],int type);
	~CLabel();
	void show();
private:

};


#endif
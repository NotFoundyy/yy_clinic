#ifndef CBUTTON_H
#define CBUTTON_H
#include"CTool.h"
#include"CControl.h"

#include <iostream>
#include<string>
using namespace std;

class CButton:public CControl
{
public:
	
	CButton(int x,int y,int w,int h,char  context[20],int type);
	~CButton();
	void show();
private:

};

#endif
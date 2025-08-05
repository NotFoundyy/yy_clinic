#ifndef CTABLE_H
#define CTABLE_H
#include"CTool.h"
#include"CControl.h"
#include"CUser.h"
#include"CDoctor.h"
#include"CKeshi.h"
#include"CJiuzhen.h"

#include <iostream>
#include<string>
using namespace std;

class CTable:public CControl
{
public:	
	CTable(int x,int y,int width,int height,char * context,int type,int row,int col);
	~CTable();
	void show();
	static void showUserdata(int x,int y,int width,int height,map<string ,CUser *> userMap);
	static void showDocterdata(int x,int y,int width,int height,map<string ,CDoctor *> userMap);
	static void showKeshidata(int x,int y,int width,int height,map<string ,CKeshi *> userMap);
	static void keshi_ys();
	static void showJiuzhendata(int x,int y,int width,int height);
	static void showQuhaodata(int x,int y,int width,int height);
	static void showDoctorCx(int x,int y,int width,int height);
private:
	int row;
	int col;
};

#endif
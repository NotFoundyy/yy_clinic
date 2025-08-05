#ifndef CTOOL_H
#define CTOOL_H
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#include<ctime>
#include<map>
#include<list>

using namespace std;


#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class CTool
{
public:
	static void gotoxy(int x, int y) ;
	static void PointBorder(int x,int y,int width, int height);
	static void PaintTable(int x,int y, int width,int height,int row,int col);
	static int getKey();
	static char * getTime();
	static char * getTime(int i);
	static list <char *>CTool::getChaxun(char * begin,char * end);

};
#endif
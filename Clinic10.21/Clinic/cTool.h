#ifndef CTOOL_H
#define CTOOL_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "cWindow.h"
#include "cAdminLoginWin.h"
#include "cLoginWin.h"
#include "cFile.h"
#include "cData.h"
#include "cList.h"

using namespace std;

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_DOWN 80
#define KEY_UP 72

int getKey();
int getTime(int x,int y);
void gotoxy(int x, int y);
int userQuery(char name[20]);
int docQuery(char name[20]);
int claQuery(char ID[20]);
void paintBorder(int x,int y,int width,int height);
void paintTable(int startX, int startY, int width, int height, int row, int col);

#endif
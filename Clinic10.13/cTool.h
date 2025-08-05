#ifndef CTOOL_H
#define CTOOL_H

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_DOWN 80
#define KEY_UP 72

int getKey();
void gotoxy(int x, int y);
void paintBorder(int x,int y,int width,int height);
void paintTable(int startX, int startY, int width, int height, int row, int col);

#endif
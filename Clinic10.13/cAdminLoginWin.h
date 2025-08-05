#ifndef CADMINLOGINWIN_H
#define CADMINLOGINWIN_H

#include "cWindow.h"
#include "cData.h"
#include <string.h>
#include <windows.h>

int AdminLoginWin_init();

int LoginCheck(char name[20],char pwd[20]);

#endif
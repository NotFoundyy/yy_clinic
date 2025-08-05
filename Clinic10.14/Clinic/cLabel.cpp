#include "cLabel.h"

void showLabel(CONTROL lab){
	gotoxy(lab.x,lab.y);
	printf("%s",lab.context);
}
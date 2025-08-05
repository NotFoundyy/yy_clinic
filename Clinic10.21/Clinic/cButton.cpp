#include "cButton.h"

void showButton(CONTROL btn){
	paintBorder(btn.x,btn.y,btn.width,btn.height);
	gotoxy(btn.x+2,btn.y+1);
	printf("%s",btn.context);
}
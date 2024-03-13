#pragma once
#include <winbgim.h>
//#include "define.h"

/*-------------------Prototype------------------*/
//display text on screen

//tao button
void button(int x1, int y1, int x2, int y2, std::string s, int text_color, int box_color);


/*-------------------Function------------------*/
void button(int x1, int y1, int x2, int y2, std::string s, int text_color, int box_color){
	int tmp = (x2 - x1 - s.size()) / 2;
	setfillstyle(EMPTY_FILL, box_color);
	bar(x1, y1, x2, y2);
	setcolor(text_color);
	setbkcolor(box_color);
	outtextxy(x1 + tmp-25, y1 + (y2 - y1) / 2 - 8, (char*)s.c_str());
}

#pragma once

//#include <winbgim.h>
//#include "define.h"

/*-------------------Prototype------------------*/
//display text on screen

//tao button
//void button(int x1, int y1, int x2, int y2, std::string s, int text_color, int box_color);
//
//
///*-------------------Function------------------*/
//void button(int x1, int y1, int x2, int y2, std::string s, int text_color, int box_color) {
//	int tmp = (x2 - x1 - s.size()) / 2;
//	setfillstyle(EMPTY_FILL, box_color);
//	bar(x1, y1, x2, y2);
//	setcolor(text_color);
//	setbkcolor(box_color);
//	outtextxy(x1 + tmp - 25, y1 + (y2 - y1) / 2 - 8, (char*)s.c_str());

char gMasach[30];
char gMathe[30];

//struct box {
//	int left, top;
//	bool check;
//
//	void display();
//};

struct button {
	int left;
	int right;
	int top;
	int bottom;
	int bgcolor;
	int rad;

	char* title;
	int fontsize;
	int txtcolor;

	button(int left, int top, int right, int bottom, int bgcolor, int rad);
	void setTitle(char* title, int txtcolor, int fontsize);
	void display();
};


button::button(int left, int top, int right, int bottom, int bgcolor, int rad) {
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
	this->bgcolor = bgcolor;
	this->rad = rad;
}

void button::setTitle(char* title, int txtcolor, int fontsize) {
	this->title = title;
	this->txtcolor = txtcolor;
	this->fontsize = fontsize;
}

void rndConnerRect(int left, int top, int right, int bottom, int rad)
{
	line(left + rad, top, right - rad, top);
	line(left + rad, bottom, right - rad, bottom);
	line(left, top + rad, left, bottom - rad);
	line(right, top + rad, right, bottom - rad);
	arc(left + rad, top + rad, 90, 180, rad);
	arc(left + rad, bottom - rad, -180, -90, rad);
	arc(right - rad, top + rad, 0, 90, rad);
	arc(right - rad, bottom - rad, -90, 0, rad);
}

void barWithTxt(int left, int top, int right, int bottom, int fontsize, char* txt, int align, int fillstyle)
{
	settextstyle(BOLD_FONT, HORIZ_DIR, fontsize);
	int text_w = textwidth(txt);
	int text_h = textheight(txt);
	int bar_w = right - left;
	int bar_h = bottom - top;
	int x;
	if (align == 0) 						// align left, can trai
	{
		x = left;
	}
	else if (align == 1)
	{
		x = left + (bar_w - text_w) / 2; 	// align center, can giua
	}
	else
	{
		x = left + bar_w - text_w; 			// align right, can phai
	}
	int y = top + (bar_h - text_h) / 2;
	if (fillstyle != 0)
	{
		setfillstyle(fillstyle, getbkcolor());
		bar(left, top, right, bottom);
	}
	outtextxy(x, y, txt);
}

void button::display()	
{
	setfillstyle(1, bgcolor);
	setbkcolor(bgcolor);
	setcolor(bgcolor);
	rndConnerRect(left, top, right, bottom, rad);
	floodfill(left + rad * 3, top + rad * 3, bgcolor);
	setcolor(txtcolor);
	barWithTxt(left, top, right, bottom, fontsize, title, 1, 0);
	//outtextxy(left - 25, top + (bottom - top) / 2 - 8, title);
}




#pragma once
#pragma warning( disable : 4996 )
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
void dialog(std::string massage, int color);

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

void tao_button(int left, int top, int right, int bottom, std::string s, int text_color, int box_color)
{
	int tmp = (right - left - s.size()) / 2;
	setfillstyle(SOLID_FILL, box_color);
	bar(left, top, right, bottom);
	setcolor(text_color);
	setbkcolor(box_color);
	outtextxy(left + tmp - 25, top + (bottom - top) / 2 - 8, (char*)s.c_str());
}

//hien thi con tro
void displayCur(std::string s, int left, int top, int right, int bottom) {
	s[s.size() - 1] = '|';
	delay(50);
	outtextxy(left + 10, top + 10, (char*)s.c_str());
	s[s.size() - 1] = ' ';
	delay(50);
	outtextxy(left + 10, top + 10, (char*)s.c_str());
}

//nhap 
void Input(int left, int top, int right, int bottom, std::string& s, char c) {
	char tmp = s[s.size() - 1];
	s[s.size() - 1] = c;
	s.push_back(tmp);
	setfillstyle(SOLID_FILL, CYAN);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	outtextxy(left + 10, top + 10, (char*)s.c_str());
}

//xoa
void Delete(int left, int top, int right, int bottom, std::string& s) {
	if (s.size() == 1) return;
	setfillstyle(SOLID_FILL, CYAN);
	bar(left + 1, top + 1, right - 1, bottom);
	char tmp = s[s.size() - 1];
	s.pop_back();
	s[s.size() - 1] = tmp;
	outtextxy(left + 10, top + 10, (char*)s.c_str());
}

//nhap chuoi
void InputString(int left, int top, int right, int bottom, std::string& s) {
	setfillstyle(SOLID_FILL, CYAN);
	setcolor(CYAN);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	s += '|';
	outtextxy(left + 10, top + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(15);
		delay(50);
		outtextxy(left + 10, top + 10, (char*)s.c_str());
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || (int)c == 32)
			{
				Input(left, top, right, bottom, s, c);
			}
			else if (c == 8) // backspace
			{
				Delete(left, top, right, bottom, s);
			}
			else if (c == 13 && s != "|") // enter
			{
				s.pop_back();
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("NHAP THANH CONG", WHITE);
				break;
			}
			else if (c == 27) {
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				s = "";
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("HUY NHAP", RED);
				break;
			}
		}
		else displayCur(s, left, top, right, bottom);
	}
}

void InputNumber(int left, int top, int right, int bottom, std::string& s) {
	setfillstyle(SOLID_FILL, CYAN);
	setcolor(CYAN);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	s += '|';
	outtextxy(left + 10, top + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(15);
		outtextxy(left + 10, top + 10, (char*)s.c_str());
		if (kbhit())
		{
			c = getch();
			if (c >= '0' && c <= '9')
			{
				Input(left, top, right, bottom, s, c);
			}
			else if (c == 8) // backspace
			{
				Delete(left, top, right, bottom, s);
			}
			else if (c == 13 && s != "|") // enter
			{
				s.pop_back();
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("NHAP THANH CONG", WHITE);
				break;
			}
			else if (c == 27) {
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				s = "";
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("HUY NHAP", RED);
				break;
			}
		}
		else displayCur(s, left, top, right, bottom);
	}
}

void InputMa(int left, int top, int right, int bottom, std::string& s) {
	setfillstyle(SOLID_FILL, CYAN);
	setcolor(CYAN);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	s += '|';
	outtextxy(left + 10, top + 10, (char*)s.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(15);
		delay(50);
		outtextxy(left + 10, top + 10, (char*)s.c_str());
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_')
			{
				Input(left, top, right, bottom, s, c);
			}
			else if (c == 8) // backspace
			{
				Delete(left, top, right, bottom, s);
			}
			else if (c == 13 && s != "|") // enter
			{
				s.pop_back();
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("NHAP THANH CONG", WHITE);
				break;
			}
			else if (c == 27) {
				tao_button(left + 10, top + 10, right, bottom, "", BLACK, CYAN);
				s = "";
				outtextxy(left + 10, top + 10, (char*)s.c_str());
				dialog("HUY NHAP", RED);
				break;
			}
		}
		else displayCur(s, left, top, right, bottom);
	}
}

void dialog(std::string massage, int color) {
	setcolor(color);
	outtextxy(750, 30, (char*)massage.c_str());
	//bar(750, 30, 850, 30);
	delay(900);
	setfillstyle(SOLID_FILL, 3);
	bar(750, 20, 1200, 55);
}
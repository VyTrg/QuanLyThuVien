#pragma once
//#include "graphics.h"
//#pragma comment(lib, "graphics.lib")
//#include <iostream>

using namespace std;
//void tao_button(int x1, int y1, int x2, int y2, string s, int text_color, int box_color);
bool check_dung_nhap = false;

//void tao_button(int x1, int y1, int x2, int y2, string s, int text_color, int box_color)
//{
//	int tmp = (x2 - x1 - s.size()) / 2;
//	setfillstyle(SOLID_FILL, box_color);
//	bar(x1, y1, x2, y2);
//	setcolor(text_color);
//	setbkcolor(box_color);
//	outtextxy(x1 + tmp - 25, y1 + (y2 - y1) / 2 - 8, (char*)s.c_str());
//}

void HienThiConTro(string s, int x1, int y1, int x2, int y2)
{
	s[s.size() - 1] = '|';
	delay(50);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
	s[s.size() - 1] = ' ';
	delay(50);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}

void lay_them_kitu(int x1, int y1, int x2, int y2, string& s, char c)
{
	char tmp = s[s.size() - 1];
	s[s.size() - 1] = c;
	s.push_back(tmp);
	setfillstyle(SOLID_FILL, 7);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}

void xoa_1_kitu(int x1, int y1, int x2, int y2, string& s)
{
	if (s.size() == 1) return;
	setfillstyle(SOLID_FILL, 7);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	char tmp = s[s.size() - 1];
	s.pop_back();
	s[s.size() - 1] = tmp;
	outtextxy(x1 + 10, y1 + 10, (char*)s.c_str());
}

void in_number(int x, int y, float n)
{
	int t = n;
	char tmp[100];
	if (n - t == 0)
	{
		snprintf(tmp, 100, "%.*f", 0, n);
	}
	else
	{
		snprintf(tmp, 100, "%.*f", 3, n);
	}
	outtextxy(x, y, tmp);
}

void Nhap_string(int x1, int y1, int x2, int y2, string& ten)
{
	setfillstyle(SOLID_FILL, 7);
	setbkcolor(7);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	setcolor(WHITE);
	ten += '|';
	outtextxy(x1 + 10, y1 + 10, (char*)ten.c_str());
	char c;
	while (kbhit()) char a = getch();
	while (1)
	{
		setcolor(0);
		outtextxy(x1 + 10, y1 + 10, (char*)ten.c_str());
		if (GetAsyncKeyState(VK_DELETE))
		{
			check_dung_nhap = true;
			break;
		}
		if (kbhit())
		{
			c = getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || (int)c == 32)
			{
				lay_them_kitu(x1, y1, x2, y2, ten, c);
			}
			else if (c == 8) // backspace
			{
				xoa_1_kitu(x1, y1, x2, y2, ten);
			}
			else if (ten == "|") // enter
			{
				setbkcolor(3);
				outtextxy(1150, 420, (char*)"KHONG DUOC TRONG");
				delay(1000);
				setfillstyle(SOLID_FILL, 3);
				bar(1150, 420, 1350, 440);
				setbkcolor(7);
			}
			else if (c == 13 && ten != "|") // enter
			{
				ten.pop_back();
				tao_button(x1, y1, x2, y2, "", 0, 7);
				outtextxy(x1 + 10, y1 + 10, (char*)ten.c_str());
				break;
			}
			else if (c == 27) {
				tao_button(x1 + 10, y1 + 10, x2, y2, "", BLACK, 7);
				ten = "";
				setbkcolor(3);
				outtextxy(x1 + 10, y1 + 10, (char*)ten.c_str());
				outtextxy(1150, 420,(char*)"HUY NHAP");
				delay(1000);
				setfillstyle(SOLID_FILL, 3);
				bar(1150, 420, 1350, 440);
				break;
			}
		}
		else HienThiConTro(ten, x1, y1, x2, y2);
	}
}


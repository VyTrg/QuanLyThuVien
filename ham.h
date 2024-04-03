#pragma once
#define M 10

/*-------------------Prototype------------------*/
//sinh ma sach tu dong
std::string MaSach(std::string tensach);

//sinh so tu dong
std::string sotudong();

//nhap 
void Input(int left, int top, int right, int bottom, std::string s);

//hien con tro nhap
void displayCur(int left, int top, int right, int bottom, std::string s);

//xoa
//void Delete(int left, int top, int right, int bottom, std::string s);

/*-------------------Function------------------*/
std::string MaSach(std::string tensach) {
	std::string ms = "";

	bool check = true;
	int length = tensach.size();
	for (int i = 0; i < length; ++i) {
		if (tensach[i] == ' ')
			check = true;
		else if (tensach[i] != ' ' && check == true) {
			ms.push_back(toupper(tensach[i]));
			check = false;
		}
	}
	ms = ms + "-" + sotudong();
	return ms;
}

std::string sotudong() {
	int a[M];
	std::string ma = "";
	srand(time(NULL));
	for (int i = 0; i < M; ++i) {
		a[i] = i + 1;
	}
	for (int i = 0; i < 2; i++) {
		int j = rand() % (M - i) + i; //j tu i den M-1
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	for (int i = 0; i < 2; i++) {
		ma += std::to_string(a[i]);
	}
	return ma;
}

void copyCharArr(char exsitArr[], char newArr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		newArr[i] = exsitArr[i];
	}
}
void copyCharArr(std::string exsitStr, char newArr[], int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		newArr[i] = '\00';
	}
	for (int i = 0; i < n; i++)
	{
		newArr[i] = exsitStr[i];
	}
}

//string to integer
int StringToInt(std::string s)
{
	int num = 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
		num = num * 10 + (int(s[i]) - 48);
	return num;
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
	setfillstyle(1, 15);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	outtextxy(left + 10, top + 10, (char*)s.c_str());
}

//xoa
void Delete(int left, int top, int right, int bottom, std::string& s) {
	if (s.size() == 1) return;
	setfillstyle(1, 15);
	bar(left + 1, top + 1, right - 1, bottom);
	char tmp = s[s.size() - 1];
	s.pop_back();
	s[s.size() - 1] = tmp;
	outtextxy(left + 10, top + 10, (char*)s.c_str());
}

//nhap chuoi
void InputString(int left, int top, int right, int bottom, std::string& s) {
	setfillstyle(1, 15);
	setcolor(0);
	bar(left + 1, top + 1, right - 1, bottom - 1);
	s += '|';
	outtextxy(left + 10, top + 10, (char*)s.c_str());
	char c;
	while (_kbhit()) char a = _getch();
	while (1)
	{
		setcolor(0);
		outtextxy(left + 10, top + 10, (char*)s.c_str());
		if (_kbhit())
		{
			c = _getch();
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || (int)c == 32)
			{
				Input(left, top, right, bottom, s, c);
			}
			else if (c == 8) // backspace
			{
				Delete(left, top, right, bottom, s);
			}
			//else if (c == 13) // enter
			//{
			//	s.pop_back();
			//	//tao_button(x1, y1, x2, y2, "", 0, 6);
			//	outtextxy(left + 10, top + 10, (char*)s.c_str());
			//	break;
			//}
		}
		else displayCur(s, left, top, right, bottom);
	}
}
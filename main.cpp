//#pragma once

#include <iostream>
#include <string.h>
#include <winbgim.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream> // thao tac file
//#include <graphics.h>

#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"
//#include "ThongTin.h"
#include "file_dms.h"
#include "mylib.h"
//#include "menu.h"
//#include "define.h"

/*-------------------Prototype------------------*/
//void Event();

//nhap danh mach sach
void NhapDms(Nodedms &First);


int main(int argc, char *argv[])
{	
	Nodedms First_dms = NULL;
//	ReadFile(First_dms);
//	Run_ThongTin();
//	while(1){
//		delay(0.0001);
//		if(ismouseclick(WM_LBUTTONDOWN)){
//			int x, y;
//            getmouseclick(WM_LBUTTONDOWN, x, y);
//            if(x >= 20 && x <= 20 + 50 && y >= 20 && y <= 20 + 50){
//            	menu();
//			}
//        }
//	}
//	 now, you can run project
//	initwindow(500, 500);			// init window graphics
//	setbkcolor(0);					// set background
//   	cleardevice();
//	setcolor(14);					// set text color
//	outtextxy(100, 50, "Graphics in Dev-C++");// print text in window graphics
//	
//	while(!kbhit()) delay(1);		// pause screen	
	NhapDms(First_dms);	
	return 0;
}

/*-------------------Function------------------*/
void NhapDms(Nodedms &First){
	
	std::string str;
	int n;
	
	std::cout << "Nhap ma sach";
	std::getline(std::cin, str);
	First->sach.masach = str;
	
	std::cout << "Nhap trang thai";
	std::cin >> n;
	First->sach.trangthai = n;
	
	std::cout << "Nhap vi tri";
	std::getline(std::cin, str);
	First->sach.vitri = str;
	
//	WriteFile(First);
}

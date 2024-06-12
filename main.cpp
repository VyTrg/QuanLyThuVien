

#include <iostream>
#include <string.h>
#include <Windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <fstream> // thao tac file
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <cstring>
#include <ctime>
#include <sstream>


#include "define.h"
#include "graphic.h"
#include "dohoa.h"
#include "ham.h"
#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"
#include "menu.h"
#include "dohoa_dausach.h"
#include "dohoa_docgia.h"
//#include "ThongTin.h"
//#include "mylib.h"
#include "muontra.h"
#include "dms.h"


int main(int argc, char* argv[])
{

	initwindow(w, h, "Quan ly thu vien", 0, 0, 0, 1);
	int n;
	DS_DauSach list;
	list.n = 0;
	//Nodedms node = NULL;
	//string s;
	setfillstyle(3, 3);
	setcolor(15);// mau khung
	setbkcolor(3);
	cleardevice();
	menu();
	TREE_DG DG;
	KhoiTao(DG);
	Read_info(DG);
	ReadDSDS(list);
	int chucnang = 0;

	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int x, y;
			getmouseclick(WM_LBUTTONDOWN, x, y);

			bool DauSach = x >= 470 && x <= 900 && y >= 140 && y <= 200;
			if (DauSach) {
				setcolor(15);// mau khung
				setbkcolor(3);
				cleardevice();
				settextstyle(BOLD_FONT, HORIZ_DIR, 1);
				//setcolor(14);
				In_DauSach();

				quickSort1(list, 0, list.n - 1);
				InDanhSachDauSach(list, 0, 10, 1);
				DisPlay_DSDS(list);
			}
			bool DanhMucSach = x >= 470 && x <= 900 && y >= 250 && y <= 310;
			if (DanhMucSach) {
				setcolor(15);// mau khung
				setbkcolor(3);
				chucnang = 1;
				cleardevice();
				settextstyle(BOLD_FONT, HORIZ_DIR, 1);
				displayDms(list);
			}

			bool MuonTra = x >= 470 && x <= 900 && y >= 360 && y <= 420;
			if (MuonTra) {
				setcolor(15);// mau khung
				setbkcolor(3);
				cleardevice();
				settextstyle(BOLD_FONT, HORIZ_DIR, 1);
				displayMuonTra(list, DG);
			}
		}
	}
	

}

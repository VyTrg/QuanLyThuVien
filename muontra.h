//#pragma once
/*-------------------Prototype------------------*/
//hien thi man hinh muon
void displayMuon(Nodemt &node);

//hien thi man hinh muon tra
void displayMuonTra(Nodemt &node);

//bang muon sach
void tableMuonSach();

//bang sach dang muon
void tableMuon();

/*-------------------Function------------------*/
void displayMuon(Nodemt& node) {
	std::string strMasach = " ";
	std::string strMathe = " ";
	//char gMasach[30] ;
begin:
	//setbkcolor(CYAN);
	//cleardevice();

	//THE DOC GIA
	setfillstyle(1, 15);
	setbkcolor(15);
	setcolor(15);
	rndConnerRect(5, 80, 595, 650, 5);
	floodfill(350, 340, 15);

	setcolor(0);
	setbkcolor(9);


	setbkcolor(15);
	char s1[] = "NHAP MA THE ";
	barWithTxt(15, 10, 100, 230, 2, s1, 0, 0);
	rndConnerRect(150, 100, 580, 140, 5);
	char s6[] = "DOC GIA ";
	char s7[] = "MA THE ";
	char s8[] = "PHAI ";
	char s9[] = "TRANG THAI THE ";
	barWithTxt(15, 10, 100, 330, 2, s6, 0, 0);
	barWithTxt(15, 10, 100, 430, 2, s7, 0, 0);
	barWithTxt(15, 10, 100, 530, 2, s8, 0, 0);
	barWithTxt(15, 10, 100, 630, 2, s9, 0, 0);
	tableMuon();

	//MUON SACH
	//(left, top, right, bottom)
	setfillstyle(1, 15);
	setbkcolor(15);
	setcolor(15);
	rndConnerRect(600, 80, w - 15, 580, 5);
	floodfill(650, 100, 15);

	setcolor(0);
	setbkcolor(9);

	setbkcolor(15);
	
	char s2[] = { "NHAP MA SACH" };
	char s3[] = { "HOAC TEN SACH" };
	barWithTxt(610, 10, 845, 200, 1, s2, 0, 0);
	barWithTxt(610, 10, 845, 250, 1, s3, 0, 0);
	rndConnerRect(760, 100, 1200, 140, 5);
	
	char s4[] = "TIM";
	barWithTxt(1220, 10, 1280, 230, 2, s4, 0, 0);
	
	char s5[] = "MUON SACH";
	button btnMuonSach(820, 610, 950, 670, WHITE, 8);//muon sach
	btnMuonSach.setTitle(s5, BLACK, 2);
	btnMuonSach.display();
	
	tableMuonSach();
	
	copyCharArr(strMasach, gMasach, strMasach.length(), 30);
	copyCharArr(strMathe, gMathe, strMathe.length(), 30);
	
	int	currentCur = 770;
	char ch;

	barWithTxt(770, 105, 1200, 130, 2, gMasach, 0, 1);
	barWithTxt(160, 110, 550, 130, 2, gMathe, 0, 1);

	//trang muon sach
	int trangMuonSach = 0;
	int tongtrangMT = 0;
	std::string trgMuonSach = std::to_string(trangMuonSach) + "/" + std::to_string(tongtrangMT);

	do {
		/*if (ismouseclick(WM_MOUSEMOVE))
		{
			int pos_x, pos_y;
			getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
			bool btnMuonSachhold = (pos_x >= btnMuonSach.left && pos_x <= btnMuonSach.right && pos_y >= btnMuonSach.top && pos_y <= btnMuonSach.bottom);
			if (btnMuonSachhold) {
				btnMuonSach.bgcolor = BLACK;
				btnMuonSach.txtcolor = WHITE;
			}
			else {
				btnMuonSach.bgcolor = WHITE;
				btnMuonSach.txtcolor = BLACK;
			}
		}*/
		if (_kbhit()) {
			ch = _getch();
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == ' ') {
				if (currentCur == 770) {
					strMasach.push_back(ch);
				}
				else if (currentCur == 160) {
					strMathe.push_back(ch);
				}
			}
			else if (ch == BACKSPACE) {
				if (currentCur == 770 && strMasach.length() > 1)
				{
					strMasach.pop_back();
					
				}
				else if (currentCur == 160 && strMathe.length() > 1) {
					strMathe.pop_back();
				}
			}
			if (currentCur == 770) {
				copyCharArr(strMasach, gMasach, strMasach.length(), 30);
				setcolor(0);
				setfillstyle(1, 15);
				barWithTxt(770, 105, 1200, 130, 2, gMasach, 0, 1);
			}
			else if (currentCur == 160) {
				copyCharArr(strMathe, gMathe, strMathe.length(), 30);
				setcolor(0);
				setfillstyle(1, 15);
				barWithTxt(160, 110, 550, 130, 2, gMathe, 0, 1);
			}
		}
		if (!_kbhit()) {
			delay(100);
			if (!_kbhit()) {
				if (currentCur == 770)
				{
					setcolor(0);
					line(770 + textwidth(gMasach), 105, 770 + textwidth(gMasach), 130);
					setcolor(15);
					delay(80);
					line(770 + textwidth(gMasach), 105, 770 + textwidth(gMasach), 130);
					setcolor(0);
				}
				else if (currentCur == 160) {
					setcolor(0);
					line(160 + textwidth(gMathe), 110, 160 + textwidth(gMathe), 130);
					setcolor(15);			
					delay(80);				
					line(160 + textwidth(gMathe), 110, 160 + textwidth(gMathe), 130);
					setcolor(0);
				}
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
			bool nhapMasach = pos_x >= 770 && pos_y <= 1200 && pos_y >= 105 && pos_y <= 130;
			bool nhapMathe = pos_x >= 160 && pos_y <= 550 && pos_y >= 110 && pos_y <= 130;
			if (nhapMasach) {
				currentCur = 770;
			}
			else if (nhapMathe) {
				currentCur = 160;
			}
			bool tim = pos_x >= 1220 && pos_x <= 1280 && pos_y >= 10 && pos_y <= 230;
			if (tim) {
				
				Nodemt mt = node;
				int x, y = 180;
				while (mt != NULL) {
					x = 620;
					y += 40;
					std::string ten = "Anh hung xa dieu";
					std::string vitri = "ngan 1 ke 1";
					setfillstyle(0, 15);
					settextstyle(10, 0, 1);//(font, direction, size)
					setcolor(0);
					int a = 620;
					outtextxy(x, y, (char*)mt->muontra.masach.c_str());
					x += 120;
					outtextxy(x, y, (char*)ten.c_str());
					x += 220;
					outtextxy(x, y, (char*)std::to_string(mt->muontra.trangthai).c_str());
					x += 140;
					outtextxy(x, y, (char*)vitri.c_str());
					mt = mt->next;
				}
			}
		}
	} while (1);
}


void displayMuonTra(Nodemt& node) {
	setbkcolor(CYAN);
	cleardevice();


	//(left, top, right, bottom)
	button btnMenu(10, 10, 250, 50, WHITE, 8);//menu
	button btnMuon(400, 10, 640, 50, WHITE, 8);//muon
	button btnTra(790, 10, 1030, 50, WHITE, 8);//tra
	char s1[10] = "< MENU";
	char s2[10] = "MUON";
	char s3[10] = "TRA";
	btnMenu.setTitle(s1, BLACK, 3);
	btnMuon.setTitle(s2, BLACK, 3);
	btnTra.setTitle(s3, BLACK, 3);

	do {
		delay(10);
		btnMenu.display();
		btnMuon.display();
		btnTra.display();
		
		if (ismouseclick(WM_MOUSEMOVE))
		{
			int pos_x, pos_y;
			getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
			bool btnMenuhold = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonhold = (pos_x >= btnMuon.left && pos_x <= btnMuon.right && pos_y >= btnMuon.top && pos_y <= btnMuon.bottom);
			bool btnTrahold = (pos_x >= btnTra.left && pos_x <= btnTra.right && pos_y >= btnTra.top && pos_y <= btnTra.bottom);
			if (btnMenuhold) {
				btnMenu.bgcolor = BLACK;
				btnMenu.txtcolor = WHITE;
			}
			else {
				btnMenu.bgcolor = WHITE;
				btnMenu.txtcolor = BLACK;
			}
			if (btnMuonhold) {
				btnMuon.bgcolor = BLACK;
				btnMuon.txtcolor = WHITE;
			}
			else {
				btnMuon.bgcolor = WHITE;
				btnMuon.txtcolor = BLACK;
			}
			if (btnTrahold) {
				btnTra.bgcolor = BLACK;
				btnTra.txtcolor = WHITE;
			}
			else {
				btnTra.bgcolor = WHITE;
				btnTra.txtcolor = BLACK;
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
			/*std::cout << "click\n";
			std::cout << pos_x << " " << pos_y << std::endl*/;
			bool btnMenuclick = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonclick = (pos_x >= btnMuon.left && pos_x <= btnMuon.right && pos_y >= btnMuon.top && pos_y <= btnMuon.bottom);
			bool btnTraclick = (pos_x >= btnTra.left && pos_x <= btnTra.right && pos_y >= btnTra.top && pos_y <= btnTra.bottom);
			if (btnMuonclick) {
				btnMuon.bgcolor = BLACK;
				btnMuon.txtcolor = WHITE;
				displayMuon(node);
			}
			if (btnMenuclick) {

			}
			if (btnMenuclick) {

			}
		}
	} while (1);
}

void tableMuonSach() {
	setfillstyle(1, 15);

	setcolor(0);
	char MuonSach[4][15] = { "MA SACH", "TEN SACH", "TRANG THAI", "VI TRI" };
	line(610, 150, 1230, 150);
	line(610, 150, 610, 530);
	line(1230, 150, 1230, 530);
	line(610, 530, 1230, 530);
	line(610, 200, 1230, 200);
	
	
	int a = 620;
	outtextxy(a, 170, MuonSach[0]);
	a += textwidth(MuonSach[0]) + 80;
	outtextxy(a, 170, MuonSach[1]);
	a += textwidth(MuonSach[1]) + 80;
	outtextxy(a, 170, MuonSach[2]);
	a += textwidth(MuonSach[2]) + 30;
	outtextxy(a, 170, MuonSach[3]);
	
	line(730, 150, 730, 530);
	line(950, 150, 950, 530);
	line(1090, 150, 1090, 530);
}

void tableMuon() {
	//setfillstyle(1, 15);
	settextstyle(10, 0, 2);
	setcolor(0);
	char s[] = "SACH DANG MUON";
	outtextxy(200, 380, s);
	char Muon[4][15] = { "MA SACH", "TEN SACH", "NGAY MUON", "TRANG THAI"};
	line(15, 420, 580, 420);
	line(15, 420, 15, 620);
	line(580, 420, 580, 620);
	line(15, 620, 580, 620);
	line(15, 470, 580, 470);
	int a = 25;
	outtextxy(a, 430, Muon[0]);
	a += textwidth(Muon[0]) + 30;
	outtextxy(a, 430, Muon[1]);
	a += textwidth(Muon[1]) + 80;
	outtextxy(a, 430, Muon[2]);
	a += textwidth(Muon[2]) + 30;
	outtextxy(a, 430, Muon[3]);
	line(120, 420, 120, 620);
	line(300, 420, 300, 620);
	line(440, 420, 440, 620);
	//line(950, 150, 950, 530);
	//line(1090, 150, 1090, 530);
	char s1[] = "NHAN CHUOT PHAI VAO MA SACH DE MUON/ TRA";
	outtextxy(50, 630, s1);
}
void cfMuon() {

}

void cfTra() {

}
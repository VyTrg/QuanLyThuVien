//#pragma once
/*-------------------Prototype------------------*/
//hien thi man hinh muon
void displayMuon(Nodemt &node, TREE_DG& DG);

//hien thi man hinh muon tra
void displayMuonTra(Nodemt &node, TREE_DG &DG);

//bang muon sach
void tableMuonSach();

//hien thi muon sach
void scrMuonSach();

//hien thi doc gia
void scrDocGia();

//bang sach dang muon
void tableMuon();

//thong bao
void dialog(std::string massage, int color);

/*-------------------Function------------------*/
void displayMuon(Nodemt& node, TREE_DG& DG) {
//begin:
	std::string strMathe;
	std::string strMasach;
	//
	scrMuonSach();
	button TimMuonSach(1200, 100, 1260, 140, CYAN, 1);
	TimMuonSach.setTitle((char*)"TIM", WHITE, 1);
	
	//
	scrDocGia();
	//setcolor(15);
	button TimDG(600, 100, 660, 140, CYAN, 1);
	TimDG.setTitle((char*)"TIM", WHITE, 1);

	std::string mathe;

	TREE_DG tim = NULL;
	TimDG.display();
	TimMuonSach.display();
	while(1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
				int pos_x, pos_y;
				getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
				bool NhapMaThe = pos_x >= 160 && pos_x <= 550 && pos_y >= 100 && pos_y <= 140;
				bool NhapTenSach = pos_x >= 880 && pos_x <= 1180 && pos_y >= 100 && pos_y <= 140;
				bool TimMaThe = pos_x >= 600 && pos_x <= 660 && pos_y >= 100 && pos_y <= 140;
				bool TimTenSach = pos_x >= 1200 && pos_x <= 1260 && pos_y >= 100 && pos_y <= 140;
				if (NhapMaThe) {
					strMathe = "";
					InputString(160, 100, 550, 140, strMathe);
				}
				if (NhapTenSach) {
					strMasach = "";
					InputString(880, 100, 1180, 140, strMasach);
				}
				if (TimMaThe) {
					tim = Find_DG(DG, strMathe);
					if (tim == NULL) {
						dialog("KHONG TIM THAY DOC GIA, VUI LONG NHAP LAI", RED);
					}
					else{
						setcolor(WHITE);
						std::string hoten = ChuanHoaChuoi(tim->docgia.ho) + " " + ChuanHoaChuoi(tim->docgia.ten);
						outtextxy(250, 160, (char*)hoten.c_str());
						outtextxy(250, 210, (char*)tim->docgia.MATHE.c_str());
						outtextxy(250, 260, (char*)ChuanHoaChuoi(tim->docgia.phai).c_str());
						if (tim->docgia.trangThai == 0) {
							outtextxy(250, 310, (char*)"DANG HOAT DONG");
						}
						else {
							setcolor(LIGHTRED);
							outtextxy(250, 310, (char*)"BI KHOA");
						}
					}
				}
		}

	} 
}


void displayMuonTra(Nodemt& node, TREE_DG& DG) {
	setbkcolor(CYAN);
	cleardevice();


	//(left, top, right, bottom)
	button btnMenu(10, 10, 250, 50, WHITE, 1);//menu
	button btnMuonTra(400, 10, 640, 50, WHITE, 1);//muon
	//tra
	char s1[10] = "< MENU";
	char s2[15] = "MUON / TRA";
	btnMenu.setTitle(s1, BLACK, 3);
	btnMuonTra.setTitle(s2, BLACK, 3);

	do {
		delay(10);
		btnMenu.display();
		btnMuonTra.display();
		
		
		if (ismouseclick(WM_MOUSEMOVE))
		{
			int pos_x, pos_y;
			getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
			bool btnMenuhold = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonhold = (pos_x >= btnMuonTra.left && pos_x <= btnMuonTra.right && pos_y >= btnMuonTra.top && pos_y <= btnMuonTra.bottom);
			
			if (btnMenuhold) {
				btnMenu.bgcolor = BLACK;
				btnMenu.txtcolor = WHITE;
			}
			else {
				btnMenu.bgcolor = WHITE;
				btnMenu.txtcolor = BLACK;
			}
			if (btnMuonhold) {
				btnMuonTra.bgcolor = BLACK;
				btnMuonTra.txtcolor = WHITE;
			}
			else {
				btnMuonTra.bgcolor = WHITE;
				btnMuonTra.txtcolor = BLACK;
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
			/*std::cout << "click\n";
			std::cout << pos_x << " " << pos_y << std::endl*/;
			bool btnMenuclick = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonclick = (pos_x >= btnMuonTra.left && pos_x <= btnMuonTra.right && pos_y >= btnMuonTra.top && pos_y <= btnMuonTra.bottom);
			
			if (btnMuonclick) {
				btnMuonTra.bgcolor = BLACK;
				btnMuonTra.txtcolor = WHITE;
				displayMuon(node, DG);
			}
			if (btnMenuclick) {

			}
			if (btnMenuclick) {

			}
		}
	} while (1);
}

void tableMuonSach() {
	/*setfillstyle(1, 15);

	setcolor(0);*/
	//setcolor(15);// mau khung
	//setbkcolor(3);
	char MuonSach[4][15] = { "MA SACH", "TRANG THAI", "VI TRI" };
	line(760, 150, 1230, 150);
	line(760, 150, 760, 620);
	line(1230, 150, 1230, 620);
	line(760, 620, 1230, 620);
	line(760, 200, 1230, 200);
	
	
	int a = 770;
	outtextxy(a, 170, MuonSach[0]);
	a += textwidth(MuonSach[0]) + 80;
	outtextxy(a, 170, MuonSach[1]);
	a += textwidth(MuonSach[1]) + 80;
	outtextxy(a, 170, MuonSach[2]);
	
	
	line(900, 150, 900, 620);
	line(1090, 150, 1090, 620);
}

void tableMuon() {
	//setfillstyle(1, 15);
	setcolor(15);// mau khung
	setbkcolor(3);
	char s[] = "SACH DANG MUON";
	outtextxy(200, 380, s);
	char Muon[4][15] = { "MA SACH", "TEN SACH", "NGAY MUON", "TRANG THAI"};
	line(15, 420, 710, 420);
	line(15, 420, 15, 620);
	line(710, 420, 710, 620);
	line(15, 620, 710, 620);
	line(15, 470, 710, 470);
	int a = 25;
	outtextxy(a, 430, Muon[0]);
	a += textwidth(Muon[0]) + 30;
	outtextxy(a, 430, Muon[1]);
	a += textwidth(Muon[1]) + 140;
	outtextxy(a, 430, Muon[2]);
	a += textwidth(Muon[2]) + 50;
	outtextxy(a, 430, Muon[3]);
	line(120, 420, 120, 620);
	line(350, 420, 350, 620);
	line(500, 420, 500, 620);
	//line(950, 150, 950, 530);
	//line(1090, 150, 1090, 530);
	char s1[] = "NHAN CHUOT PHAI VAO MA SACH DE MUON/ TRA";
	outtextxy(50, 630, s1);
}

void scrMuonSach() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(15, 110, (char*)"NHAP MA THE");
	outtextxy(15, 160, (char*)"DOC GIA ");
	outtextxy(15, 210, (char*)"MA THE ");
	outtextxy(15, 260, (char*)"PHAI ");
	outtextxy(15, 310, (char*)"TRANG THAI THE ");
	
	setcolor(15);
	rndConnerRect(880, 100, 1180, 140, 1);//nhap ma sach
	tableMuon();

}

void scrDocGia() {
	//MUON SACH
	//(left, top, right, bottom)
	//setcolor(15);// mau khung
	setbkcolor(3);
	outtextxy(720, 110, (char*)"NHAP TEN SACH");
	

	//setcolor(15);// mau khung
	rndConnerRect(160, 100, 550, 140, 1);//nhap ma the
	tableMuonSach();

}

void cfMuon() {

}

void cfTra() {

}


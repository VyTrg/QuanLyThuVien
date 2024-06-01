//#pragma once
/*-------------------Prototype------------------*/
//hien thi man hinh muon
void displayMuon(DS_DauSach& DSDS, TREE_DG& DG);

//hien thi man hinh muon tra
void displayMuonTra(DS_DauSach &DSDS, TREE_DG &DG);

//bang muon sach
void tableMuonSach();

//hien thi muon sach
void scrMuonSach();

//hien thi doc gia
void scrDocGia();

//bang sach dang muon
void tableMuon();

//thong bao


//in sach dang muon
void in_muon(Nodemt node);

//xoa man hinh
void xoa_scr() {
	setfillstyle(SOLID_FILL, 3);
	bar(0, 60, w, h);
}

/*-------------------Function------------------*/

//bool KiemTraDG(TREE_DG dg) {//0: hoat dong, 1: bi khoa
//	//if(dg->docgia.muon <= 0 && )
//}

void xoa_sach() {
	for (int i = 210; i <= 360; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(765, i, 895, i + 40);
		bar(905, i, 1085, i + 40);
		bar(1095, i, 1225, i + 40);
		//bar(545, i, 705, i + 40);
	}
	setfillstyle(SOLID_FILL, CYAN);
	bar(920, 405, 1050, 440);
}
void in_sach(Nodedms node, int j, int so_trang, int pos_trang, int sl) {
	if (node != NULL && DemMuon(node) > 0) {
		std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
		Nodedms in = position(node, j);
		//std::string trangthai;
		for (int i = 210; i <= 360; i += 40) {
			setbkcolor(CYAN);
			setcolor(WHITE);
			if (in != NULL) {
				if (in->sach.trangthai != 0) {
					setcolor(RED);
				}
				else
					setcolor(WHITE);
				//if (in->sach.trangthai == 0) {
					barWithTxt(765, i, 895, i + 40, 1, (char*)in->sach.masach.c_str(), 0, 0);
					barWithTxt(905, i, 1085, i + 40, 1, (char*)trangthai[in->sach.trangthai].c_str(), 0, 0);
					barWithTxt(1095, i, 1225, i + 40, 1, (char*)in->sach.vitri.c_str(), 0, 0);
					
				//}
				in = in->next;
			}
			if (j == sl || j == so_trang * 4) break;
		}
		outtextxy(930, 410, (char*)to_string(pos_trang).c_str());
		outtextxy(960, 410, (char*)"/");
		outtextxy(990, 410, (char*)to_string(so_trang).c_str());
	}
	else if (DemMuon(node) == 0) {
		dialog("HET MA SACH CO THE MUON", WHITE);
	}
}


void scr_muon() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(720, 450, w, h);
	outtextxy(750, 460, (char*)"MA SACH");
	outtextxy(750, 500, (char*)"tEN SACH");
	outtextxy(750, 540, (char*)"NGAY MUON");
}

void scr_xoaMT() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(720, 450, w, h);
}

void scr_tra() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(720, 450, w, h);
	outtextxy(750, 460, (char*)"TRA SACH");
}

void xoa_dg() {
	setfillstyle(SOLID_FILL, CYAN);
	bar(220, 150, 600, 340);
}
void xoa_inmuon() {
	for (int i = 475; i <= 585; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(20, i, 118, i + 40);
		bar(125, i, 385, i + 40);
		bar(395, i, 535, i + 40);
		bar(545, i, 705, i + 40);
	}
}
void in_muon(Nodemt node, DS_DauSach list){
	if (node != NULL) {
		//std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
		//Nodedms in = position(node, j);
		//std::string trangthai;
		for (int i = 475; i <= 580; i += 40) {
			setbkcolor(3);
			setcolor(15);
			if (node != NULL) {
				barWithTxt(20, i, 115, i + 40, 1, (char*)node->muontra.masach.c_str(), 0, 0);
				std::string isbn = node->muontra.masach.substr(0, 5);
				std::string tensach = list.data[Search_ISBN(list, isbn)]->tensach;
				barWithTxt(125, i, 385, i + 40, 1, (char*)tensach.c_str(), 0, 0);
				barWithTxt(395, i, 535, i + 40, 1, (char*)DinhDangNgay(node->muontra.ngaymuon).c_str(), 0, 0);
				barWithTxt(545, i, 705, i + 40, 1, (char*)std::to_string(TinhNgay(node->muontra.ngaymuon, node->muontra.ngaytra)).c_str(), 0, 0);
				node = node->next;
			}
		}
	}
}


void displayMuon(DS_DauSach& DSDS, TREE_DG& DG) {
//begin:
	
	//
	scrMuonSach();
	button TimMuonSach(1200, 100, 1260, 140, CYAN, 1);
	TimMuonSach.setTitle((char*)"TIM", WHITE, 1);
	
	//
	scrDocGia();
	//setcolor(15);
	button TimDG(600, 100, 660, 140, CYAN, 1);
	TimDG.setTitle((char*)"TIM", WHITE, 1);

	
	TimDG.display();
	TimMuonSach.display();
	//while(1) {
	//	if (ismouseclick(WM_LBUTTONDOWN)) {
	//			int pos_x, pos_y;
	//			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
	//			bool NhapMaThe = pos_x >= 160 && pos_x <= 550 && pos_y >= 100 && pos_y <= 140;
	//			bool NhapTenSach = pos_x >= 880 && pos_x <= 1180 && pos_y >= 100 && pos_y <= 140;
	//			bool TimMaThe = pos_x >= 600 && pos_x <= 660 && pos_y >= 100 && pos_y <= 140;
	//			bool TimTenSach = pos_x >= 1200 && pos_x <= 1260 && pos_y >= 100 && pos_y <= 140;
	//			if (NhapMaThe) {
	//				xoa_inmuon();
	//				xoa_dg();
	//				strMathe = "";
	//				InputString(160, 100, 550, 140, strMathe);
	//			}
	//			if (NhapTenSach) {
	//				strMasach = "";
	//				InputString(880, 100, 1180, 140, strMasach);
	//			}
	//			if (TimMaThe && strMathe != "") {
	//				tim = Find_DG(DG, strMathe);               
	//				if (tim == NULL) {
	//					dialog("KHONG TIM THAY DOC GIA, VUI LONG NHAP LAI", RED);
	//				}
	//				else{
	//					setcolor(WHITE);
	//					std::string hoten = ChuanHoaChuoi(tim->docgia.ho) + " " + ChuanHoaChuoi(tim->docgia.ten);
	//					outtextxy(250, 160, (char*)hoten.c_str());
	//					outtextxy(250, 210, (char*)tim->docgia.MATHE.c_str());
	//					outtextxy(250, 260, (char*)ChuanHoaChuoi(tim->docgia.phai).c_str());
	//					if (tim->docgia.trangThai == 0) {
	//						outtextxy(250, 310, (char*)"DANG HOAT DONG");
	//					}
	//					else if(tim->docgia.trangThai == 1){
	//						setcolor(RED);
	//						outtextxy(250, 310, (char*)"BI KHOA");
	//					}
	//					if (tim->docgia.node != NULL && tim->docgia.muon > 0) {
	//						in_muon(tim->docgia.node, DSDS);
	//					}
	//					else {
	//						dialog("DOC GIA CHUA MUON", WHITE);
	//					}
	//				}
	//				//strMathe = "";
	//			}
	//	}

	//} 
}

void xoa_indg() {
	for (int i = 160; i <= 550; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(45, i, 135, i + 40);
		bar(145, i, 365, i + 40);
		bar(375, i, 515, i + 40);
		//bar(545, i, 705, i + 40);
	}
}

void in_docgia(TREE_DG tim) {
	xoa_dg();
	setbkcolor(3);
	setcolor(15);
	std::string hoten = ChuanHoaChuoi(tim->docgia.ho) + " " + ChuanHoaChuoi(tim->docgia.ten);
	outtextxy(250, 160, (char*)hoten.c_str());
	outtextxy(250, 210, (char*)tim->docgia.MATHE.c_str());
	outtextxy(250, 260, (char*)ChuanHoaChuoi(tim->docgia.phai).c_str());
	if (tim->docgia.trangThai == 1) {
		outtextxy(250, 310, (char*)"DANG HOAT DONG");
	}
	else if (tim->docgia.trangThai == 0) {
		setcolor(RED);
		outtextxy(250, 310, (char*)"BI KHOA");
	}
}

void in_dg(NODE_DG** nodes, int j, int pos_trang, int so_trang, int sl) {
	std::string trangthai[2] = {"BI KHOA", "DANG HOAT DONG"};
	for (int i = 160; i <= 550; i += 40)
	{
		setbkcolor(3);
		setcolor(15);
		barWithTxt(45, i, 135, i + 40, 1, (char*)nodes[j]->docgia.MATHE.c_str(), 0, 0);
		std::string hoten = nodes[j]->docgia.ho + " " + nodes[j]->docgia.ten;
		barWithTxt(145, i, 365, i + 40, 1, (char*)hoten.c_str(), 0, 0);
		barWithTxt(375, i, 515, i + 40, 1, (char*)trangthai[nodes[j]->docgia.trangThai].c_str(), 0, 0);
		j++;
		if (j == sl || j == so_trang * 10) break;
	}
	outtextxy(240, 620, (char*)std::to_string(pos_trang).c_str());
	outtextxy(280, 620, (char*)"/");
	outtextxy(320, 620, (char*)to_string(so_trang).c_str());
}

void xoa_insach() {
	for (int i = 160; i <= 550; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(695, i, 785, i + 40);
		bar(795, i, 1035, i + 40);
		bar(1045, i, 1225, i + 40);
		//bar(545, i, 705, i + 40);
	}
}

void in_dausach(DS_DauSach DSDS, int j, int pos_trang, int so_trang, int sl) {
	for (int i = 160; i <= 550; i += 40)
	{
		setbkcolor(3);
		setcolor(15);
		barWithTxt(695, i, 785, i + 40, 1, (char*)DSDS.data[j]->ISBN.c_str(), 0, 0);
		barWithTxt(795, i, 1035, i + 40, 1, (char*)DSDS.data[j]->tensach.c_str(), 0, 0);
		int k = DSDS.data[j]->soluong - DSDS.data[j]->soluotmuon;
		barWithTxt(1045, i, 1225, i + 40, 1, (char*)std::to_string(k).c_str(), 0, 0);
		j++;
		if (j == sl || j == so_trang * 10) break;
	}
	outtextxy(900, 620, (char*)to_string(pos_trang).c_str());
	outtextxy(940, 620, (char*)"/");
	outtextxy(980, 620, (char*)to_string(so_trang).c_str());
}

void displayTraCuu(DS_DauSach DSDS, TREE_DG DG) {
	button btnTruocDG(40, 620, 140, 660, WHITE, 1);
	btnTruocDG.setTitle((char*)"TRUOC", BLACK, 3);
	btnTruocDG.display();
	button btnSauDG(420, 620, 520, 660, WHITE, 1);
	btnSauDG.setTitle((char*)"SAU", BLACK, 3);
	btnSauDG.display();

	button btnTruocSach(690, 620, 790, 660, WHITE, 1);
	btnTruocSach.setTitle((char*)"TRUOC", BLACK, 3);
	btnTruocSach.display();
	button btnSauSach(1130, 620, 1230, 660, WHITE, 1);
	btnSauSach.setTitle((char*)"SAU", BLACK, 3);
	btnSauSach.display();

	setbkcolor(CYAN);
	setcolor(WHITE);

	outtextxy(220, 70, (char*)"DOC GIA");
	outtextxy(900, 70, (char*)"SACH");
	//table doc gia
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(50, 120, (char*)"MA THE");
	outtextxy(150, 120, (char*)"HO TEN");
	outtextxy(380, 120, (char*)"TRANG THAI");

	line(40, 110, 520, 110);
	line(40, 110, 40, 580);
	line(520, 110, 520, 580);
	line(40, 580, 520, 580);
	line(40, 150, 520, 150);
	line(140, 110, 140, 580);
	line(370, 110, 370, 580);
	
	//table sach
	outtextxy(700, 120, (char*)"ISBN");
	outtextxy(800, 120, (char*)"HO TEN");
	outtextxy(1050, 120, (char*)"SO LUONG MUON");
	line(690, 110, 1230, 110);
	line(690, 110, 690, 580);
	line(1230, 110, 1230, 580);
	line(690, 580, 1230, 580);
	line(690, 150, 1230, 150);
	line(790, 110, 790, 580);
	line(1040, 110, 1040, 580);
	
}


void displayMuonTra(DS_DauSach &DSDS, TREE_DG& DG) {
	setbkcolor(CYAN);
	cleardevice();
	//khai bao
	int chon = 1;/* 1: muon/tra
	* 2: tra cuu
	*/
	/*bool muon = false;
	bool tra = false;*/
	std::string strMathe = "";
	std::string strMasach = "";
	std::string mathe = "";
	int check = -1;

	int j = 0;
	int so_trang = 0;
	int pos_trang = 1;
	int dem;

	int j_sach = 0;
	int so_trangsach = 0;
	int pos_trangsach = 1;
	int dem_sach;

	int j_dg = 0;
	int so_trangdg = 0;
	int pos_trangdg = 1;
	int dem_dg;

	TREE_DG tim = NULL;
	bool clicktra[3] = { false };
	bool clickmuon[4] = { false };

	std::string masach_xoa = "";

	MuonTra muon;

	button btnTruocMuon(760, 410, 810, 440, WHITE, 1);
	btnTruocMuon.setTitle((char*)"<<", BLACK, 3);
	button btnSauMuon(1180, 410, 1230, 440, WHITE, 1);
	btnSauMuon.setTitle((char*)">>", BLACK, 3);

	//(left, top, right, bottom)
	button btnTra(1150, 500, 1230, 540, WHITE, 1);
	btnTra.setTitle((char*)"TRA", BLACK, 3);
	button btnMuon(1150, 540, 1230, 580, WHITE, 1);
	btnMuon.setTitle((char*)"MUON", BLACK, 3);

	button btnMenu(10, 10, 250, 50, WHITE, 1);//menu
	button btnMuonTra(300, 10, 450, 50, WHITE, 1);//muon
	button btnTraCuu(500, 10, 650, 50, WHITE, 1);
	//tra
	char s1[10] = "< MENU";
	char s2[15] = "MUON/TRA";
	char s3[14] = "TRA CUU";
	btnMenu.setTitle(s1, BLACK, 3);
	btnMuonTra.setTitle(s2, BLACK, 3);
	btnTraCuu.setTitle(s3, BLACK, 3);
	

	do {
		delay(10);
		btnMenu.display();
		btnMuonTra.display();
		btnTraCuu.display();
		
		
		/*if (ismouseclick(WM_MOUSEMOVE))
		{
			int pos_x, pos_y;
			getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
			bool btnMenuhold = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonhold = (pos_x >= btnMuonTra.left && pos_x <= btnMuonTra.right && pos_y >= btnMuonTra.top && pos_y <= btnMuonTra.bottom);
			bool btnTraCuuhold = (pos_x >= btnTraCuu.left && pos_x <= btnTraCuu.right && pos_y >= btnTraCuu.top && pos_y <= btnTraCuu.bottom);

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
			if (btnTraCuuhold) {
				btnTraCuu.bgcolor = BLACK;
				btnTraCuu.txtcolor = WHITE;
			}	  
			else { 
				btnTraCuu.bgcolor = WHITE;
				btnTraCuu.txtcolor = BLACK;
			}
			
		}*/
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
			/*std::cout << "click\n";
			std::cout << pos_x << " " << pos_y << std::endl*/;
			bool btnMenuclick = (pos_x >= btnMenu.left && pos_x <= btnMenu.right && pos_y >= btnMenu.top && pos_y <= btnMenu.bottom);
			bool btnMuonclick = (pos_x >= btnMuonTra.left && pos_x <= btnMuonTra.right && pos_y >= btnMuonTra.top && pos_y <= btnMuonTra.bottom);
			bool btnTraCuuclick = (pos_x >= btnTraCuu.left && pos_x <= btnTraCuu.right && pos_y >= btnTraCuu.top && pos_y <= btnTraCuu.bottom);
			if (btnMuonclick) {
				xoa_scr();
				btnMuonTra.bgcolor = BLACK;
				btnMuonTra.txtcolor = WHITE;
				btnTraCuu.bgcolor = WHITE;
				btnTraCuu.txtcolor = BLACK;
				btnMenu.bgcolor = WHITE;
				btnMenu.txtcolor = BLACK;
				btnTruocMuon.display();
				btnSauMuon.display();
				chon = 1;
				displayMuon(DSDS, DG);
				if (tim != NULL) {
					setcolor(WHITE);
					setbkcolor(CYAN);
					outtextxy(170, 110, (char*)tim->docgia.MATHE.c_str());
					in_docgia(tim);
					if (tim->docgia.node != NULL && tim->docgia.muon > 0) {
						in_muon(tim->docgia.node, DSDS);
					}
					else {
						dialog("DOC GIA CHUA MUON SACH", WHITE);
					}
				}
				if (check != -1) {
					setcolor(WHITE);
					setbkcolor(CYAN);
					outtextxy(890, 110, (char*)DSDS.data[check]->ISBN.c_str());
					strMasach = "";
					j = 0;
					pos_trang = 1;
					dem = DemMuon(DSDS.data[check]->First);
					if (dem % 4 == 0 && dem != 0) so_trang = dem / 4;
					else so_trang = (dem / 4) + 1;
					in_sach(DSDS.data[check]->First, j, so_trang, pos_trang, dem);
				}
			}
			if (btnTraCuuclick) {
				xoa_scr();
				btnTraCuu.bgcolor = BLACK;
				btnTraCuu.txtcolor = WHITE;
				btnMuonTra.bgcolor = WHITE;
				btnMuonTra.txtcolor = BLACK;
				btnMenu.bgcolor = WHITE;
				btnMenu.txtcolor = BLACK;
				chon = 2;
				displayTraCuu(DSDS, DG);

				NODE_DG** nodes = new NODE_DG * [nDG];
				int sl = 0;
				DuyetLNR(DG, nodes, sl);
				if (sl % 10 == 0 && sl != 0) so_trangdg = sl / 10;
				else so_trangdg = (sl / 10) + 1;
				in_dg(nodes, j_dg, pos_trangdg, so_trangdg, sl);
				
				if (DSDS.n % 4 == 0 && DSDS.n != 0) so_trangsach = DSDS.n / 10;
				else so_trangsach = (DSDS.n / 10) + 1;
				in_dausach(DSDS, j_sach, pos_trangsach, so_trangsach, DSDS.n);
				
			}
			if (btnMenuclick) {

			}
			setcolor(WHITE);
			setbkcolor(CYAN);
			bool NhapMaThe = pos_x >= 160 && pos_x <= 550 && pos_y >= 100 && pos_y <= 140;
			bool TimMaThe = pos_x >= 600 && pos_x <= 660 && pos_y >= 100 && pos_y <= 140;
			
			if (NhapMaThe && chon == 1) {
				xoa_inmuon();
				xoa_dg();
				//strMathe = "";
				strMathe = "";
				InputString(160, 100, 550, 140, strMathe);
			}
			if (TimMaThe && strMathe != "" && chon == 1) {
				tim = Find_DG(DG, strMathe);
				if (tim == NULL) {
					dialog("KHONG TIM THAY DOC GIA, VUI LONG NHAP LAI", RED);
				}
				else {
					/*setbkcolor(3);
					setcolor(15);
					std::string hoten = ChuanHoaChuoi(tim->docgia.ho) + " " + ChuanHoaChuoi(tim->docgia.ten);
					outtextxy(250, 160, (char*)hoten.c_str());
					outtextxy(250, 210, (char*)tim->docgia.MATHE.c_str());
					outtextxy(250, 260, (char*)ChuanHoaChuoi(tim->docgia.phai).c_str());
					if (tim->docgia.trangThai == 0) {
						outtextxy(250, 310, (char*)"DANG HOAT DONG");
					}
					else if (tim->docgia.trangThai == 1) {
						setcolor(RED);
						outtextxy(250, 310, (char*)"BI KHOA");
					}*/
					in_docgia(tim);
					if (tim->docgia.node != NULL && tim->docgia.muon > 0) {
						in_muon(tim->docgia.node, DSDS);
					}
					else {
						dialog("DOC GIA CHUA MUON SACH", WHITE);
					}
				}
				
			}

			bool NhapISBN = pos_x >= 880 && pos_x <= 1180 && pos_y >= 100 && pos_y <= 140;
			bool TimTenSach = pos_x >= 1200 && pos_x <= 1260 && pos_y >= 100 && pos_y <= 140;
			if (NhapISBN && chon == 1) {
				xoa_sach();
				/*strMasach = "";*/
				InputString(880, 100, 1180, 140, strMasach);
			}
			if (TimTenSach && strMasach != "" && chon == 1) {
				//dialog("NHAN", WHITE);
				check = Search_ISBN(DSDS, ChuanHoaChuoi(strMasach));
				if (check != -1) {
					strMasach = "";
					j = 0;
					pos_trang = 1;
					dem = DemMuon(DSDS.data[check]->First);
					if (dem % 4 == 0 && dem != 0) so_trang = dem / 4;
					else so_trang = (dem / 4) + 1;
					in_sach(DSDS.data[check]->First, j, so_trang, pos_trang, dem);
				}
				else {
					dialog("KHONG TIM THAY SACH", RED);
				}
			}
			
			//muon sach
			Nodedms chon_muon = NULL;
			int t = 0;
			if (chon == 1 && check != -1) {
				int k = 0;
				for (int i = 210; i <= 360; i += 40) {
					clickmuon[k] = pos_x >= 765 && pos_x <= 895 && pos_y >= i && pos_y <= (i + 40);
					++k;
				}
				for (int i = 0; i < 4; ++i) {
					if (clickmuon[i]) {
						chon_muon = position(DSDS.data[check]->First, i);
						if (chon_muon->sach.trangthai == 0 && tim->docgia.trangThai == 1 && tim->docgia.muon < 3 && KiemTraTrung(tim->docgia.node, chon_muon->sach.masach) && KiemTraQuaHan(tim->docgia.node)) {
							scr_muon();
							btnMuon.display();
						}
						else if (!KiemTraQuaHan(tim->docgia.node)) {
							setbkcolor(CYAN);
							setcolor(WHITE);
							dialog("DOC GIA KHONG DU DIEU KIEN MUON", WHITE);
						}
						else if (!KiemTraTrung(tim->docgia.node, chon_muon->sach.masach)) {
							setbkcolor(CYAN);
							setcolor(WHITE);
							dialog("KHONG MUON DUOC", WHITE);
							chon_muon = NULL;
						}
						else if (chon_muon->sach.trangthai != 0) {
							setbkcolor(CYAN);
							setcolor(WHITE);
							dialog("KHONG MUON DUOC", WHITE);
							chon_muon = NULL;
						}
						else if (tim->docgia.trangThai == 0 || tim->docgia.muon >= 3) {
							setbkcolor(CYAN);
							setcolor(WHITE);
							dialog("DOC GIA KHONG DU DIEU KIEN MUON", WHITE);
						}
						//muon = true;
						//tra = false;
						
						
					}
				}
			}
			//MuonTra mt;
			if (chon_muon != NULL && tim->docgia.trangThai == 1 && tim->docgia.muon < 3 && KiemTraTrung(tim->docgia.node, chon_muon->sach.masach) && KiemTraQuaHan(tim->docgia.node)) {
				setbkcolor(CYAN);
				setcolor(WHITE);
				
				muon.masach = chon_muon->sach.masach;
				outtextxy(900, 460, (char*)chon_muon->sach.masach.c_str());
				outtextxy(900, 500, (char*)DSDS.data[check]->tensach.c_str());
				time_t n = time(0);
				tm* ltm = localtime(&n);
				Ngay now;
				now.nam = 1900 + ltm->tm_year;
				now.thang = 1 + ltm->tm_mon;
				now.ngay = ltm->tm_mday;
				muon.ngaymuon = now;
				muon.ngaytra.nam = 0;
				muon.ngaytra.thang = 0;
				muon.ngaytra.ngay = 0;
				muon.trangthai = 0;
				outtextxy(900, 540, (char*)DinhDangNgay(now).c_str());
				
			}
			/*else if (chon_muon != NULL && chon_muon->sach.trangthai == 0 && tim != NULL && tim->docgia.trangThai == 1) {
				setbkcolor(CYAN);
				setcolor(WHITE);
				dialog("DOC GIA KHONG DU DIEU KIEN MUON", WHITE);
			}*/
			bool cfnMuon = pos_x >= 1150 && pos_x <= 1230 && pos_y >= 540 && pos_y <= 580;
			if (cfnMuon) {
				//chon_muon->sach.trangthai = 1;
				InsertLast_NodeMuonTra(tim->docgia.node, muon);
				xoa_inmuon();
				in_muon(tim->docgia.node, DSDS);
				tim->docgia.muon++;
				//Xoa_MSMT(tim->docgia.node, ChuanHoaChuoi(masach_xoa));
				//tim->docgia.muon--;
				//Tra_sach(DSDS, masach_xoa);
				dialog("MUON THANH CONG", WHITE);
				Muon_sach(DSDS, muon.masach);
				xoa_sach();
				j = 0;
				pos_trang = 1;
				dem = DemMuon(DSDS.data[check]->First);
				if (dem % 4 == 0 && dem != 0) so_trang = dem / 4;
				else so_trang = (dem / 4) + 1;
				in_sach(DSDS.data[check]->First, j, so_trang, pos_trang, dem);
				//xoa_inmuon();
				in_muon(tim->docgia.node, DSDS);
				//masach_xoa = "";
				chon_muon = NULL;
				delay(10);
				scr_xoaMT();
			}
			/*else if (cfnMuon && tim->docgia.muon > 3) {
				dialog("KHONG THE MUON", WHITE);
			}*/
			/*bool cfnMuon = pos_x >= 1150 && pos_x <= 1230 && pos_y >= 500 && pos_y <= 540;
			if (cfnMuon && muon == true && tra == false) {
				MuonTra mt;
				mt.masach = chon_muon->sach.masach;
				Ngay now;
				time_t n = time(0);
				tm* ltm = localtime(&n);
				now.nam = 1900 + ltm->tm_year;
				now.thang = 1 + ltm->tm_mon;
				now.ngay = ltm->tm_mday;
				mt.ngaymuon = now;
				mt.ngaytra.nam = 0;
				mt.ngaytra.thang = 0;
				mt.ngaytra.ngay = 0;
				mt.trangthai = 0;
				chon_muon->sach.trangthai = 1;
				InsertLast_NodeMuonTra(tim->docgia.node, mt);
				in_muon(tim->docgia.node, DSDS);
			}*/

			//tra sach
			Nodemt chon_tra = NULL;
			if (chon == 1 && tim != NULL) {
				int h = 0;
				for (int i = 475; i <= 580; i += 40) {
					clicktra[h] = pos_x >= 20 && pos_x <= 115 && pos_y >= i && pos_y <= (i + 40);
					++h;
				}
				for (int i = 0; i < 3; ++i) {
					if (clicktra[i]) {
						chon_tra = position_mt(tim->docgia.node, i);
						scr_tra();
						btnTra.display();
						masach_xoa = chon_tra->muontra.masach;
						//muon = false;
						//tra = true;
					}
				}
			}
			if (chon_tra != NULL) {
				setbkcolor(CYAN);
				setcolor(WHITE);
				outtextxy(900, 460, (char*)chon_tra->muontra.masach.c_str());
			}
			bool cfnTra = pos_x >= 1150 && pos_x <= 1230 && pos_y >= 500 && pos_y <= 540;
			if (cfnTra) {
				Xoa_MSMT(tim->docgia.node, ChuanHoaChuoi(masach_xoa));
				//tim->docgia.trangThai = 1;
				tim->docgia.muon--;
				in_docgia(tim);
				Tra_sach(DSDS, masach_xoa);
				dialog("TRA THANH CONG", WHITE);
				xoa_inmuon();
				Tra_sach(DSDS, masach_xoa);
				in_muon(tim->docgia.node, DSDS);
				chon_tra = NULL;
				masach_xoa = "";
				delay(10);
				scr_xoaMT();
			}
			
			bool TruocDausachClick = pos_x >= 690 && pos_x <= 790 && pos_y >= 620 && pos_y <= 660;
			bool SauDausachClick = pos_x >= 1130 && pos_x <= 1230 && pos_y >= 620 && pos_y <= 660;
			if (pos_trangsach > 1) {
				if (TruocDausachClick && chon == 2) {
					xoa_insach();
					pos_trangsach--;
					j_sach = (pos_trangsach - 1) * 10;
					if (DSDS.n % 10 == 0 && DSDS.n != 0) so_trangsach = DSDS.n / 10;
					else so_trangsach = (DSDS.n / 10) + 1;
					in_dausach(DSDS, j_sach, pos_trangsach, so_trangsach, DSDS.n);
				}
			}
			if ( pos_trangsach < so_trangsach) {
				if (SauDausachClick && chon == 2) {
					xoa_insach();
					pos_trangsach++;
					j_sach = (pos_trangsach - 1) * 10;
					if (DSDS.n % 10 == 0 && DSDS.n != 0) so_trangsach = DSDS.n / 10;
					else so_trangsach = (DSDS.n / 10) + 1;
					in_dausach(DSDS, j_sach, pos_trangsach, so_trangsach, DSDS.n);
				}
			}

			bool TruocDgClick = pos_x >= 40 && pos_x <= 140 && pos_y >= 620 && pos_y <= 660;
			bool SauDgClick = pos_x >= 420 && pos_x <= 520 && pos_y >= 620 && pos_y <= 660;
			if (pos_trangdg > 1) {
				if (TruocDgClick && chon == 2) {
					xoa_dg();
					pos_trangdg--;
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(DG, nodes, sl);
					j_dg = (pos_trangdg - 1) * 10;
					if (sl % 10 == 0 && sl != 0) so_trangdg = sl / 10;
					else so_trangdg = (sl / 10) + 1;
					in_dg(nodes, j_dg, pos_trangdg, so_trangdg, sl);
				}
			}
			if (pos_trangdg < so_trangdg) {
				if (SauDgClick && chon == 2) {
					xoa_dg();
					pos_trangdg++;
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(DG, nodes, sl);
					j_dg = (pos_trangdg - 1) * 10;
					if (sl % 10 == 0 && sl != 0) so_trangdg = sl / 10;
					else so_trangdg = (sl / 10) + 1;
					in_dg(nodes, j_dg, pos_trangdg, so_trangdg, sl);
				}
			}

			bool TruocMuonClick = pos_x >= 760 && pos_x <= 810 && pos_y >= 410 && pos_y <= 440;
			bool SauMuonClick = pos_x >= 1180 && pos_x <= 1230 && pos_y >= 410 && pos_y <= 440;
			if (pos_trang > 1 && chon == 1) {
				if (TruocMuonClick) {
					xoa_sach();
					pos_trang--;
					j = (pos_trang - 1) * 4;
					dem = DemMuon(DSDS.data[check]->First);
					if (dem % 4 == 0 && dem != 0) so_trang = dem / 4;
					else so_trang = (dem / 4) + 1;;
					in_sach(DSDS.data[check]->First, j, so_trang, pos_trang, dem);
				}
			}
			if (pos_trang < so_trang) {
				if (SauMuonClick && chon == 1) {
					xoa_sach();
					pos_trang++;
					j = (pos_trang - 1) * 4;
					dem = DemMuon(DSDS.data[check]->First);
					if (dem % 4 == 0 && dem != 0) so_trang = dem / 4;
					else so_trang = (dem / 4) + 1;;
					in_sach(DSDS.data[check]->First, j, so_trang, pos_trang, dem);
				}
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
	line(760, 150, 760, 400);
	line(1230, 150, 1230, 400);
	line(760, 400, 1230, 400);
	line(760, 200, 1230, 200);
	
	
	int a = 770;
	outtextxy(a, 170, MuonSach[0]);
	a += textwidth(MuonSach[0]) + 80;
	outtextxy(a, 170, MuonSach[1]);
	a += textwidth(MuonSach[1]) + 80;
	outtextxy(a, 170, MuonSach[2]);
	
	
	line(900, 150, 900, 400);
	line(1090, 150, 1090, 400);
}

void tableMuon() {
	//setfillstyle(1, 15);
	setcolor(15);// mau khung
	setbkcolor(3);
	char s[] = "SACH DANG MUON";
	outtextxy(200, 380, s);
	char Muon[4][15] = { "MA SACH", "TEN SACH", "NGAY MUON", "SO NGAY MUON"};
	line(15, 420, 710, 420);
	line(15, 420, 15, 620);
	line(710, 420, 710, 620);
	line(15, 620, 710, 620);
	line(15, 470, 710, 470);
	int a = 25;
	outtextxy(a, 430, Muon[0]);
	a += textwidth(Muon[0]) + 30;
	outtextxy(a, 430, Muon[1]);
	a += textwidth(Muon[1]) + 160;
	outtextxy(a, 430, Muon[2]);
	a += textwidth(Muon[2]) + 50;
	outtextxy(a, 430, Muon[3]);
	line(120, 420, 120, 620);
	line(390, 420, 390, 620);
	line(540, 420, 540, 620);
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
	rndConnerRect(160, 100, 550, 140, 1);//nhap ma sach
	tableMuon();

}

void scrDocGia() {
	//MUON SACH
	//(left, top, right, bottom)
	//setcolor(15);// mau khung
	setbkcolor(3);
	outtextxy(720, 110, (char*)"NHAP ISBN");
	

	//setcolor(15);// mau khung
	
	rndConnerRect(880, 100, 1180, 140, 1);//nhap sach
	tableMuonSach();

}



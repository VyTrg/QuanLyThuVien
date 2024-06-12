

void tableDms();
void scr_xoa() {
	setfillstyle(SOLID_FILL, 3);
	bar(770, 370, w, h);
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(900, 370, (char*)"XOA DANH MUC SACH");
	outtextxy(780, 410, (char*)"MA SACH ");
	rndConnerRect(900, 400, 1180, 440, 1);
	button btnXoa(1130, 480, 1180, 520, WHITE, 1);
	btnXoa.setTitle((char*)"XOA", BLACK, 2);
	btnXoa.display();
}
void scr_sua() {
	setfillstyle(SOLID_FILL, 3);
	bar(770, 370, w, h);
	setcolor(15);// mau khung
	setbkcolor(3);
	outtextxy(900, 370, (char*)"SUA DANH MUC SACH");
	outtextxy(780, 410, (char*)"MA SACH ");
	rndConnerRect(930, 400, 1180, 440, 1);
	outtextxy(780, 460, (char*)"TRANG THAI ");
	rndConnerRect(930, 450, 1180, 490, 1);
	outtextxy(1200, 460, (char*)"< >");
	outtextxy(780, 510, (char*)"VI TRI ");
	rndConnerRect(930, 500, 1180, 540, 1);
}



void table_xemdms() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(15, 75, (char*)"TEN SACH");
	rndConnerRect(120, 70, 450, 110, 1);
	outtextxy(20, 150, (char*)"MA SACH");
	outtextxy(150, 150, (char*)"TRANG THAI");
	outtextxy(330, 150, (char*)"VI TRI");

	line(10, 130, 450, 130);
	line(10, 130, 10, 580);
	line(450, 130, 450, 580);
	line(10, 580, 450, 580);
	line(10, 180, 450, 180);
	line(140, 130, 140, 580);
	line(320, 130, 320, 580);
}

void table_themdms() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(600, 75, (char*)"SO LUONG");
	rndConnerRect(700, 70, 1030, 110, 1);
	outtextxy(600, 150, (char*)"MA SACH");
	outtextxy(730, 150, (char*)"TRANG THAI");
	outtextxy(910, 150, (char*)"VI TRI");

	line(590, 130, 1030, 130);
	line(590, 130, 590, 580);
	line(1030, 130, 1030, 580);
	line(590, 580, 1030, 580);
	line(590, 180, 1030, 180);
	line(720, 130, 720, 580);
	line(860, 130, 860, 580);
}

void table_dmsthem() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(800, 420, (char*)"MA SACH");
	outtextxy(900, 420, (char*)"TRANG THAI");
	outtextxy(1100, 420, (char*)"VI TRI");

	line(780, 410, 1200, 410);
	line(780, 410, 780, 620);
	line(1200, 410, 1200, 620);
	line(780, 620, 1200, 620);
	line(780, 450, 1200, 450);
	line(890, 410, 890, 620);
	line(1050, 410, 1050, 620);
	//line(10, 130, 10, 580);
	//line(450, 130, 450, 580);
	//line(10, 580, 450, 580);
	//line(10, 180, 450, 180);
	//line(140, 130, 140, 580);
	//line(320, 130, 320, 580);
}

void scr_them() {
	setfillstyle(SOLID_FILL, 3);
	bar(770, 370, w, h);
	setcolor(15);// mau khung
	setbkcolor(3);
	outtextxy(780, 370, (char*)"THEM DANH MUC SACH");
	rndConnerRect(1000, 370, 1100, 400, 1);
	table_dmsthem();
	/*table_xemdms();
	table_themdms();*/
}

void scr_xem() {
	setfillstyle(SOLID_FILL, 3);
	bar(0, 60, w, h);
	tableDms();
	//outtextxy(870, 370, (char*)"THEM DANH MUC SACH");
	//outtextxy(755, 410, (char*)"TEN SACH");
	//rndConnerRect(870, 400, 1200, 430, 1);
	//outtextxy(755, 460, (char*)"MA SACH ");
	//outtextxy(755, 510, (char*)"TRANG THAI ");
	//outtextxy(755, 560, (char*)"VI TRI");
	//outtextxy(900, 560, (char*)"NGAN");
	//outtextxy(1050, 560, (char*)"KE");
	//rndConnerRect(970, 560, 1030, 590, 1);//ngan
	//rndConnerRect(1100, 560, 1160, 590, 1);//ke
}

//void scr_them() {
//	setfillstyle(SOLID_FILL, 3);
//	bar(0, 60, w, h);
//	setbkcolor(CYAN);
//}


void xoa_dms() {
	for (int i = 145; i <= 290; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(785, i, 890, i + 40);
		bar(893, i, 1042, i + 40);
		bar(1055, i, 1195, i + 40);
	}
}

void xoa_dmsthem() {
	for (int i = 455; i <= 610; i += 40) {
		setfillstyle(SOLID_FILL, CYAN);
		//outtextxy(785, i, (char*)"");
		bar(785, i, 890, i + 40);
		bar(893, i, 1042, i + 40);
		bar(1055, i, 1195, i + 40);
	}
	bar(920, 630, 1050, 660);
}

void xoa_ds() {
	for (int i = 125; i <= 580; i += 40)
	{
		setfillstyle(1, CYAN);
		bar(15, i, 248, i + 50);
		bar(255, i, 330, i + 50);
		bar(345, i, 450, i + 50);
		bar(465, i, 585, i + 50);
		bar(595, i, 660, i + 50);
		bar(675, i, 740, i + 50);
	}
}

void in_dms_muonthem(Nodedms node, int j, int so_trang, int pos_trang,  int sl) {
	//Nodedms node = them;
	if (node != NULL) {
		std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
		Nodedms in = position(node, j);
		//std::string trangthai;
		for (int i = 455; i <= 610; i += 40) {
			setbkcolor(3);
			setcolor(15);
			if (in != NULL) {
				barWithTxt(785, i, 885, i + 40, 1, (char*)in->sach.masach.c_str(), 0, 0);
				barWithTxt(895, i, 1045, i + 40, 1, (char*)trangthai[in->sach.trangthai].c_str(), 0, 0);
				barWithTxt(1055, i, 1195, i + 40, 1, (char*)in->sach.vitri.c_str(), 0, 0);
				in = in->next;
			}
			if (j == sl || j == so_trang * 4) break;
		}
		outtextxy(930, 630, (char*)to_string(pos_trang).c_str());
		outtextxy(960, 630, (char*)"/");
		outtextxy(990, 630, (char*)to_string(so_trang).c_str());
	}
}

void in_dmsthem(Nodedms node) {
	if (node != NULL) {
		std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
		//Nodedms in = position(node, j);
		//std::string trangthai;
		for (int i = 185; i <= 570; i += 40) {
			setbkcolor(3);
			setcolor(15);
			if (node != NULL) {
				barWithTxt(15, i, 70, i + 40, 1, (char*)node->sach.masach.c_str(), 0, 0);
				barWithTxt(145, i, 315, i + 40, 1, (char*)trangthai[node->sach.trangthai].c_str(), 0, 0);
				barWithTxt(325, i, 445, i + 40, 1, (char*)node->sach.vitri.c_str(), 0, 0);
				node = node->next;
			}
			//if (j == sl || j == so_trang * 4) break;
		}
		/*outtextxy(930, 330, (char*)to_string(pos_trang).c_str());
		outtextxy(960, 330, (char*)"/");
		outtextxy(990, 330, (char*)to_string(so_trang).c_str());*/
	}
}

void in_dms(Nodedms node, int j, int so_trang, int pos_trang, int sl) {
	if (node != NULL) {
		std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
		Nodedms in = position(node, j);
		//std::string trangthai;
		for (int i = 145; i <= 290; i += 40) {
			setbkcolor(3);
			setcolor(15);
			if (in != NULL) {
				barWithTxt(785, i, 885, i + 40, 1, (char*)in->sach.masach.c_str(), 0, 0);
				barWithTxt(895, i, 1040, i + 40, 1, (char*)trangthai[in->sach.trangthai].c_str(), 0, 0);
				barWithTxt(1055, i, 1190, i + 40, 1, (char*)in->sach.vitri.c_str(), 0, 0);
				in = in->next;
			}
			if (j == sl || j == so_trang * 4) break;
		}
		outtextxy(930, 330, (char*)to_string(pos_trang).c_str());
		outtextxy(960, 330, (char*)"/");
		outtextxy(990, 330, (char*)to_string(so_trang).c_str());
	}
}

void in_dsds(DS_DauSach& DSDS, int j, int pos_trang, int so_trang, int sl)
{
	//settextstyle(0, 0, 2);
	//int j = 0;
	for (int i = 120; i <= 580; i += 40)
	{
		setbkcolor(3);
		setcolor(15);
		barWithTxt(15, i, 230, i + 40, 1, (char*)DSDS.data[j]->tensach.c_str(), 0, 0);
		barWithTxt(255, i, 330, i + 40, 1, (char*)DSDS.data[j]->ISBN.c_str(), 0, 0);
		barWithTxt(345, i, 450, i + 40, 1, (char*)DSDS.data[j]->tacgia.c_str(), 0, 0);
		barWithTxt(465 , i, 580, i + 40, 1, (char*)DSDS.data[j]->theloai.c_str(), 0, 0);
		barWithTxt(595, i, 660, i + 40, 1, (char*)std::to_string(DSDS.data[j]->sotrang).c_str(), 0, 0);
		barWithTxt(675, i, 740, i + 40, 1, (char*)std::to_string(DSDS.data[j]->nxb).c_str(), 0, 0);
		j++;
		if (j == sl || j == so_trang * 12) break;
	}
	outtextxy(375, 630, (char*)to_string(pos_trang).c_str());
	outtextxy(395, 630, (char*)"/");
	outtextxy(415, 630, (char*)to_string(so_trang).c_str());
}

//void butn() {
//	button btnMenu(10, 10, 250, 50, WHITE, 1);
//	btnMenu.setTitle((char*)"< MENU", BLACK, 3);
//	btnMenu.display();
//}

void tableDausach() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(50, 80, (char*)"DAU SACH");
	outtextxy(270, 80, (char*)"ISBN");
	outtextxy(360, 80, (char*)"TAC GIA");
	outtextxy(480, 80, (char*)"THE LOAI");
	outtextxy(600, 80, (char*)"SO TR");
	outtextxy(700, 80, (char*)"NXB");

	line(10, 70, 750, 70);
	line(10, 70, 10, 620);
	line(750, 70, 750, 620);
	line(10, 620, 750, 620);
	line(250, 70, 250, 620);
	line(340, 70, 340, 620);
	line(460, 70, 460, 620);
	line(590, 70, 590, 620);
	line(670, 70, 670, 620);
	line(10, 120, 750, 120);
}


void tableDms() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(800, 70, (char*)"TEN SACH ");
	setcolor(15);
	rndConnerRect(900, 60, 1180, 100, 1);
	outtextxy(800, 120, (char*)"MA SACH");
	outtextxy(900, 120, (char*)"TRANG THAI");
	outtextxy(1100,	120, (char*)"VI TRI");

	line(780, 110, 1200, 110);
	line(780, 110, 780, 320);
	line(1200, 110, 1200, 320);
	line(780, 320, 1200, 320);
	line(780, 140, 1200, 140);
	line(890, 110, 890, 320);
	line(1050, 110, 1050, 320);
}

void displayDms(DS_DauSach& DSDS){
	//khoi tao
	
	bool clickdms[4] = {false};
	bool clicktensach[12] = {false};
	std::string tensach_xem = "";
	std::string tensach_them = "";
	std::string masach_xoa = "";
	std::string masach_sua = "";
	std::string trangthai_sua = "";
	std::string vitri_sua = "";
	std::string trangthai[3] = { "MUON DUOC", "DA MUON", "DA THANH LY" };
	std::string soluong_them = "";
	//int sl = 0;
	int j = 0;
	int so_trang;
	int pos_trang = 1;
	if (DSDS.n % 12 == 0 && DSDS.n != 0) so_trang = DSDS.n / 12;
	else so_trang = (DSDS.n / 12) + 1;

	//int sl_dms = 0;
	int j_dms = 0;
	int so_trangdms = 1;
	int pos_trangdms = 1;
	int dem;
	//
	int j_them = 0;
	int so_trangthem = 1;
	int pos_trangthem = 1;
	int dem_them;

	Nodedms them = NULL;
	int n = 0;
	Nodedms them_xem = NULL;

	//
	setbkcolor(CYAN);
	cleardevice();
	//nut quay ve menu
	button btnMenu(10, 10, 250, 50, WHITE, 1);
	btnMenu.setTitle((char*)"< MENU", BLACK, 3);
	btnMenu.display();
	//nut huy thao tac
	button btnHuy(1220, 10, 1250, 50, WHITE, 1);
	btnHuy.setTitle((char*)"X", BLACK, 3);
	//btnHuy.display();
	//nut chuc nang xoa
	button btnXoa(290, 10, 410, 50, WHITE, 1);
	btnXoa.setTitle((char*)"XOA", BLACK, 3);
	btnXoa.display();
	//nut chuc nang sua
	button btnSua(450, 10, 570, 50, WHITE, 1);
	btnSua.setTitle((char*)"SUA", BLACK, 3);
	btnSua.display();
	//nut chuc nang them
	button btnThem(610, 10, 730, 50, WHITE, 1);
	btnThem.setTitle((char*)"THEM", BLACK, 3);
	btnThem.display();
	//nut xem dms sach xoa-sua
	button btnTruocDms_xem(780, 330, 870, 360, WHITE, 1);
	btnTruocDms_xem.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDms_xem(1110, 330, 1200, 360, WHITE, 1);
	btnSauDms_xem.setTitle((char*)"SAU >", BLACK, 2);
	button btnTruocDS_xem(15, 630, 105, 670, WHITE, 1);
	btnTruocDS_xem.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDS_xem(660, 630, 750, 670, WHITE, 1);
	btnSauDS_xem.setTitle((char*)"SAU >", BLACK, 2);
	//nut xac nhan sua
	button btnSuadms(1150, 620, 1200, 660, WHITE, 1);
	btnSuadms.setTitle((char*)"SUA", BLACK, 2);
	//nut xac nhan them
	/*button btnThemdms(1100, 70, 1200, 110, WHITE, 1);
	btnThemdms.setTitle((char*)"THEM", BLACK, 2);*/
	button btnThemdms(1140, 370, 1200, 400, WHITE, 1);
	btnThemdms.setTitle((char*)"THEM", BLACK, 2);
	//nut xem dau sach them
	button btnTruocDms_xemThem(780, 330, 870, 360, WHITE, 1);
	btnTruocDms_xemThem.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDms_xemThem(1110, 330, 1200, 360, WHITE, 1);
	btnSauDms_xemThem.setTitle((char*)"SAU >", BLACK, 2);
	//nut xem dms them
	button btnTruocDms_Them(780, 630, 870, 670, WHITE, 1);
	btnTruocDms_Them.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDms_Them(1110, 630, 1200, 670, WHITE, 1);
	btnSauDms_Them.setTitle((char*)"SAU >", BLACK, 2);

	int chon = 1;
	/*sua 1
	xoa 2
	them 3*/
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);

	Sach s;
	int check = -1;
	
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);

			//chuyen man hinh chuc nang trong dms
			bool xoaClick = pos_x >= 290 && pos_x <= 410 && pos_y >= 10 && pos_y <= 50;
			bool suaClick = pos_x >= 450 && pos_x <= 570 && pos_y >= 10 && pos_y <= 50;
			bool themClick = pos_x >= 610 && pos_x <= 730 && pos_y >= 10 && pos_y <= 50;
			bool menuClick = pos_x >= 10 && pos_x <= 250 && pos_y >= 10 && pos_y <= 50;
			if (menuClick) {
				setfillstyle(3, 3);
				setcolor(15);// mau khung
				setbkcolor(3);
				cleardevice();
				menu();
				return;
				//chon = 0;
				
			}
			
			if (xoaClick) {
				xoa_dms();
				scr_xem();
				scr_xoa();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				tableDausach();
				xoa_ds();
				in_dsds(DSDS, j, pos_trang, so_trang, DSDS.n);
				chon = 2;
				btnTruocDS_xem.display();
				btnSauDS_xem.display();

			}
			if (suaClick) {
				xoa_dms();
				scr_xem();
				scr_sua();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				tableDausach();
				xoa_ds();
				in_dsds(DSDS, j, pos_trang, so_trang, DSDS.n);
				chon = 1;
				btnTruocDS_xem.display();
				btnSauDS_xem.display();
				btnSuadms.display();
			}
			if (themClick) {
				xoa_dms();
				scr_xem();
				scr_xoa();
				tableDausach();
				xoa_ds();
				in_dsds(DSDS, j, pos_trang, so_trang, DSDS.n);
				//xoa_ds();
				//xoa_dms();
				scr_them();
				chon = 3;
				btnTruocDS_xem.display();
				btnSauDS_xem.display();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				btnThemdms.display();
				btnTruocDms_Them.display();
				btnSauDms_Them.display();
				//btnThemdms.display();
				//n = 0;
			}

			//chon list ten sach

			if (chon == 1 || chon == 2 || chon == 3) {
				int k = 0;
				for (int i = 120; i <= 580; i += 40) {
					clicktensach[k] = pos_x >= 15 && pos_x <= 230 && pos_y >= i && pos_y <= (i + 40);
					++k;
				}
				for (int i = 0; i < 12; ++i) {
					if (clicktensach[i]) {
						check = i;
						break;
					}
				}
			}
		//begin:
			if (check != -1 && (chon == 1 || chon == 2 || chon == 3)) {
				setfillstyle(1, CYAN);
				bar(905, 65, 1180, 100);
				xoa_dms();
				setcolor(15);// mau khung
				setbkcolor(3);
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				outtextxy(910, 70, (char*)DSDS.data[check + (pos_trang - 1) * 12]->tensach.c_str());
				dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
				if (dem % 4 == 0 && dem != 0) so_trangdms = dem / 4;
				else so_trangdms = (dem / 4) + 1;
				in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First,j_dms,so_trangdms, pos_trangdms, dem);
			}

			//chuc nang
			/*bool tensach_xemclick = pos_x >= 900 && pos_x <= 1180 && pos_y >= 60 && pos_y <= 90;
			if (tensach_xemclick) {

				xoa_dms();
				InputString(900, 60, 1180, 90, tensach_xem);
				if (tensach_xem != "") {
					check = Search(DSDS, ChuanHoaChuoi(tensach_xem));
					if (check == -1)
						dialog("KHONG TIM THAY SACH, NHAP LAI", RED);
					else {
						Nodedms t = Tim_Dms(DSDS.data[check]->First, tensach_xem);
						in_dms(t);
						tensach_xem = "";
					}
				}
			}*/
			


			//chon dms trong list
			/*bool masach_xoaClick = pos_x >= 900 && pos_x <= 1180 && pos_y >= 400 && pos_y <= 440;
			if (masach_xoaClick && chon == 2) {
				InputMa(900, 400, 1180, 440, masach_xoa);
			}*/
		
			Nodedms chon_dms = NULL;
			if (chon == 1 || chon == 2 || chon == 3) {
				int h = 0;
				for (int i = 145; i <= 290; i += 40) {
					clickdms[h] = pos_x >= 785 && pos_x <= 885 && pos_y >= i && pos_y <= (i + 40);
					++h;
				}
				for (int i = 0; i < 4; ++i) {
					if (clickdms[i]) {
						chon_dms = position(DSDS.data[check + (pos_trang - 1) * 12]->First, i + (pos_trangdms - 1) * 4);
					}
				}
			}
			//Nodedms* sua_dms = &chon_dms;

			//xoa dms
			if (chon_dms != NULL && chon == 2) {
				if (chon_dms->sach.trangthai != 0) {
					dialog("KHONG XOA DUOC", RED);
				}
				else {
					masach_xoa = chon_dms->sach.masach;
					//setcolor(WHITE);
					outtextxy(910, 410, (char*)masach_xoa.c_str());
				}
			}
			bool masach_xoacfn = pos_x >= 1130 && pos_x <= 1180 && pos_y >= 480 && pos_y <= 520;
			if (masach_xoacfn && chon == 2) {
				Xoa_MSDMS(DSDS.data[check + (pos_trang - 1) * 12]->First, ChuanHoaChuoi(masach_xoa));
				dialog("XOA THANH CONG", RED);
				DSDS.data[check]->soluong--;
				xoa_dms();
				j_dms = 0;
				dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
				if (dem % 4 == 0 && dem != 0) so_trangdms = dem / 4;
				else so_trangdms = (dem / 4) + 1;
				//so_trangdms = 1;
				pos_trangdms = 1;
				in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First, j_dms, so_trangdms, pos_trangdms, dem);
				//setcolor(CYAN);
				//bar(910, 410, 1180, 440);
				masach_xoa = "";
				//setcolor(WHITE);
			}

			/*bool masach_xoacfn = pos_x >= 1130 && pos_x <= 1180 && pos_y >= 480 && pos_y <= 520;
			if (masach_xoacfn && chon == 2) {
				if (masach_xoa != "") {
					check = Search_ISBN(DSDS, TachMa(ChuanHoaChuoi(masach_xoa)));
					if (check == -1)
						dialog("KHONG TIM THAY MA SACH, NHAP LAI", RED);
					else {
						int cothexoa = Xoa_MSDMS(DSDS.data[check]->First, ChuanHoaChuoi(masach_xoa));
						if (cothexoa == 0) {
							dialog("XOA THANH CONG", RED);
							DSDS.data[check]->soluong--;
							xoa_dms();
							in_dms(DSDS.data[check]->First);
							setcolor(WHITE);
							outtextxy(910, 70, (char*)DSDS.data[check]->tensach.c_str());
							masach_xoa = "";
						}
						else if (cothexoa == 1)
							dialog("KHONG XOA DUOC", RED);
					}
				}
			}*/

			//hieu chinh dms
			if (chon_dms != NULL && chon == 1) {
				if (chon_dms->sach.trangthai == 2 ) {
					dialog("KHONG THE HIEU CHINH", RED);
				}
				else {
					outtextxy(940, 410,(char*)chon_dms->sach.masach.c_str());
					trangthai_sua = trangthai[chon_dms->sach.trangthai];
					vitri_sua = chon_dms->sach.vitri;
					//outtextxy(940, 460, (char*)trangthai_sua.c_str());
					setfillstyle(1, CYAN);
					bar(935, 455, 1180, 490);
					bar(935, 505, 1180, 540);
					char ch = 1;
					setcolor(WHITE);
					//while (kbhit()) char a = getch();
					while (1) {
						
						setcolor(WHITE);
						outtextxy(940, 460, (char*)trangthai[chon_dms->sach.trangthai].c_str());
						if (kbhit()) {
							ch = getch();
							if (ch == 13)
								break;
							if (ch == 75) {
								if (chon_dms->sach.trangthai > 0) {
									chon_dms->sach.trangthai--;
									setfillstyle(SOLID_FILL, 3);
									bar(934, 455, 1180, 490);
								}
							}
							if (ch == 77) {
								if (chon_dms->sach.trangthai < 2) {
									chon_dms->sach.trangthai++;
									setfillstyle(SOLID_FILL, 3);
									bar(934, 455, 1180, 490);
								}
							}
						}
					}
					//InputString(930, 450, 1180, 490, trangthai_sua);
					InputString(930, 500, 1180, 540, vitri_sua);
					chon_dms->sach.vitri = vitri_sua;
				}
				
			}

			bool suadmsClick = pos_x >= 1150 && pos_x <= 1200 && pos_y >= 620 && pos_y <= 660;
			if (suadmsClick && chon == 1) {
				
				//HieuChinhDMS(DSDS.data[check + (pos_trang - 1) * 12]->First, chon_dms);
				xoa_dms();
				dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
				j_dms = 0;
				so_trangdms = 1;
				pos_trangdms = 1;
				in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First, j_dms, so_trangdms, pos_trangdms, dem);
				delay(100);
				scr_sua();
				btnSuadms.display();
			}
			//them danh muc sach
			//bool tensachClick_them = pos_x >= 120 && pos_x <= 450 && pos_y >= 70 && pos_y <= 110;
			//bool soluonClick_them = pos_x >= 700 && pos_x <= 800 && pos_y >= 70 && pos_y <= 100;
			//if (tensachClick_them && chon == 3) {
			//	setcolor(15);// mau khung
			//	setbkcolor(3);
			//	InputString(125, 75, 450, 110, tensach_them);
			//	if (tensach_them != "") {
			//		check = Search(DSDS, ChuanHoaChuoi(tensach_them));
			//		if (check != -1) {
			//			//outtextxy(120, 70, (char*)DSDS.data[check]->tensach.c_str());
			//			in_dmsthem(DSDS.data[check]->First);
			//		}
			//		else {
			//			dialog("KHONG TIM THAY SACH", RED);
			//		}
			//	}
			//	//char ch = 1;
			//	//std::string goiy = "";
			//	////while (kbhit()) char a = getch();
			//	//while (1) {
			//	//	if (kbhit()) {
			//	//		ch = getch();
			//	//		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || (int)ch == 32) {
			//	//			goiy += ch;
			//	//			for (int i = 0; i < DSDS.n; ++i) {
			//	//				if ((goiY(goiy, DSDS.data[i]->tensach) != -1)) {
			//	//					outtextxy(200 + i * 20, 100 + i * 20, (char*)DSDS.data[i]->tensach.c_str());
			//	//				}
			//	//			}
			//	//		}
			//	//	}
			//	//}
			//}
			//
			//if (soluonClick_them && chon == 3) {
			//	InputNumber(700, 71, 1030, 85, soluong_them);
			//	if (check != -1 && soluong_them != "" && soluong_them != "0") {
			//		Sach s;
			//		int so_luong = StringToInt(soluong_them);
			//		int n = DSDS.data[check]->soluong;
			//		while (so_luong--) {
			//			s.masach = MaSach(DSDS, check, n);
			//			s.trangthai = 0;
			//			s.vitri = DSDS.data[check]->First->sach.vitri;
			//			InsertLast_NodeDMSach(them, s);
			//		}
			//		in_dms_muonthem(them);
			//	}
			//}
			////Nodedms them1 = them;
			//bool themCfn = pos_x >= 1100 && pos_x <= 1200 && pos_y >= 70 && pos_y <= 110;
			//if (themCfn && chon == 3) {
			//	Nodedms t = DSDS.data[check]->First;
			//	while (them != NULL && t != NULL) {
			//		//if (them->sach.masach > t->sach.masach) {
			//			//InsertAfter_NodeDMSach(t, them->sach);
			//			InsertLast_NodeDMSach(DSDS.data[check]->First, them->sach);
			//			them = them->next;

			//		//}
			//		//else
			//			//t = t->next;
			//	}
			//	dialog("THEM THANH CONG", WHITE);
			//	DSDS.data[check]->soluong = n;
			//	in_dmsthem(DSDS.data[check]->First);
			//	tensach_them = "";
			//	soluong_them = "";
			//}
			bool soluongClick = pos_x >= 1000 && pos_x <= 1100 && pos_y >= 370 && pos_y <= 400;
			if (soluongClick && chon == 3 && check != -1) {
				InputNumber(1000, 370, 1100, 400, soluong_them);
				if (soluong_them != "0") {
					Sach s;
					int so_luong = StringToInt(soluong_them);
					int n = DSDS.data[check + (pos_trang - 1) * 12]->soluong;
					while (so_luong--) {
						s.masach = MaSach(DSDS, check, n);
						s.trangthai = 0;
						s.vitri = DSDS.data[check + (pos_trang - 1) * 12]->First->sach.vitri;
						InsertLast_NodeDMSach(them, s);
					}
					j_them = 0;
					dem_them = DemDMS(them);
					pos_trangthem = 1;
					if (dem_them % 4 == 0 && dem_them != 0) so_trangthem = dem_them / 4;
					else so_trangthem = (dem_them / 4) + 1;
					in_dms_muonthem(them, j_them, so_trangthem, pos_trangthem, dem_them);
				}

			}
			bool themCfn = pos_x >= 1140 && pos_x <= 1200 && pos_y >= 370 && pos_y <= 400;
			if (themCfn && chon == 3 && check != -1) {
				Nodedms t = DSDS.data[check + (pos_trang - 1) * 12]->First;
					while (them != NULL && t != NULL) {
						//if (them->sach.masach > t->sach.masach) {
							//InsertAfter_NodeDMSach(t, them->sach);
							InsertLast_NodeDMSach(DSDS.data[check + (pos_trang - 1) * 12]->First, them->sach);
							them = them->next;

						//}
						//else
							//t = t->next;
					}
					dialog("THEM THANH CONG", WHITE);
					DSDS.data[check + (pos_trang - 1) * 12]->soluong = n;
					xoa_dms();
					dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
					if (dem % 4 == 0 && dem != 0) so_trangdms = dem / 4;
					else so_trangdms = (dem / 4) + 1;
					j_dms = 0;
					pos_trangdms = 1;
					in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First, j_dms, so_trangdms, pos_trangdms, dem);
					tensach_them = "";
					soluong_them = "";
					xoa_dmsthem();
					//DeleteAll_Dms(them_xem);
			}

			//xem trang truoc - sau cua dau sach
			bool truocDSclick = pos_x >= 15 && pos_x <= 105 && pos_y >= 630 && pos_y <= 670;
			bool sauDSclick = pos_x >= 660 && pos_x <= 750 && pos_y >= 630 && pos_y <= 670;
			if (pos_trang > 1 && (chon == 1 || chon == 2 || chon == 3)) {
				if (truocDSclick) {
					xoa_ds();
					pos_trang--;
					j = (pos_trang - 1) * 12;
					in_dsds(DSDS, j, pos_trang, so_trang, DSDS.n);
				}
			}
			if (pos_trang < so_trang) {
				if (sauDSclick && (chon == 1 || chon == 2 || chon == 3)) {
					xoa_ds();
					pos_trang++;
					j = (pos_trang - 1) * 12;
					in_dsds(DSDS, j, pos_trang, so_trang, DSDS.n);
				}
			}

			//xem trang truoc - sau cua danh muc sach
			bool truocDMSclick = pos_x >= 780 && pos_x <= 870 && pos_y >= 330 && pos_y <= 360;
			bool sauDMSclick = pos_x >= 1110 && pos_x <= 1200 && pos_y >= 330 && pos_y <= 360;
			if (pos_trangdms > 1) {
				if (truocDMSclick && (chon == 1 || chon == 2 || chon == 3)) {
					xoa_dms();
					pos_trangdms--;
					j_dms = (pos_trangdms - 1) * 4;
					dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
					if (dem % 4 == 0 && dem != 0) so_trangdms = dem / 4;
					else so_trangdms = (dem / 4) + 1;
					in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First, j_dms, so_trangdms, pos_trangdms, dem);
				}
			}
			if (pos_trangdms < so_trangdms) {
				if (sauDMSclick && (chon == 1 || chon == 2 || chon == 3)) {
					xoa_dms();
					pos_trangdms++;
					j_dms = (pos_trangdms - 1) * 4;
					dem = DemDMS(DSDS.data[check + (pos_trang - 1) * 12]->First);
					if (dem % 4 == 0 && dem != 0) so_trangdms = dem / 4;
					else so_trangdms = (dem / 4) + 1;
					in_dms(DSDS.data[check + (pos_trang - 1) * 12]->First, j_dms, so_trangdms, pos_trangdms, dem);
				}
			}
			//xem truoc sau them dms
			bool truocThemclick = pos_x >= 780 && pos_x <= 870 && pos_y >= 630 && pos_y <= 670;
			bool sauThemclick = pos_x >= 1110 && pos_x <= 1200 && pos_y >= 630 && pos_y <= 670;
			if (pos_trangthem > 1) {
				if (truocThemclick && chon == 3) {
					xoa_dmsthem();
					pos_trangthem--;
					j_them = (pos_trangthem - 1) * 4;
					dem_them = DemDMS(them);
					if (dem_them % 4 == 0 && dem_them != 0) so_trangthem = dem_them / 4;
					else so_trangthem = (dem_them / 4) + 1;
					in_dms_muonthem(them, j_them, so_trangthem, pos_trangthem, dem_them);
				}
			}
			if (pos_trangthem < so_trangthem) {
				if (sauThemclick && chon == 3) {
					xoa_dmsthem();
					pos_trangthem++;
					j_them = (pos_trangthem - 1) * 4;
					dem_them = DemDMS(them);
					if (dem_them % 4 == 0 && dem_them != 0) so_trangthem = dem_them / 4;
					else so_trangthem = (dem_them / 4) + 1;
					in_dms_muonthem(them, j_them, so_trangthem, pos_trangthem, dem_them);
				}
			}

			clearmouseclick(WM_LBUTTONDOWN);
			
			
		}
		
	}
	
	_getch();
}
//void scr_them(DS_DauSach& DSDS, Nodedms& node);
//void scr_xem(DS_DauSach& DSDS, Nodedms& node);
//void scr_sua(DS_DauSach& DSDS, Nodedms& node);

void tableDms();
void tableDms_suaxoa();

void scr_xoa() {
	setfillstyle(SOLID_FILL, 3);
	bar(0, 60, w, h);
}

void scr_sua() {
	setfillstyle(SOLID_FILL, 3);
	bar(0, 60, w, h);
	setbkcolor(CYAN);
	setcolor(WHITE);
	/*outtextxy(w / 2 - 100, 100, (char*)"SUA DANH MUC SACH");
	outtextxy(300, 220, (char*)"MA SACH ");
	rndConnerRect(450, 200, 900, 250, 1);*/
	tableDms_suaxoa();
}

void scr_xemthem() {
	setfillstyle(SOLID_FILL, 3);
	bar(0, 60, w, h);
	tableDms();
	outtextxy(870, 370, (char*)"THEM DANH MUC SACH");
	outtextxy(755, 410, (char*)"TEN SACH");
	rndConnerRect(870, 400, 1200, 430, 1);
	outtextxy(755, 460, (char*)"MA SACH ");
	outtextxy(755, 510, (char*)"TRANG THAI ");
	outtextxy(755, 560, (char*)"VI TRI");
	outtextxy(900, 560, (char*)"NGAN");
	outtextxy(1050, 560, (char*)"KE");
	rndConnerRect(970, 560, 1030, 590, 1);//ngan
	rndConnerRect(1100, 560, 1160, 590, 1);//ke
}

//void scr_them() {
//	setfillstyle(SOLID_FILL, 3);
//	bar(0, 60, w, h);
//	setbkcolor(CYAN);
//	setcolor(WHITE);
//	outtextxy(w / 2 - 100, 100, (char*)"THEM DANH MUC SACH");
//	outtextxy(300, 160, (char*)"TEN SACH ");
//	rndConnerRect(450, 150, 900, 200, 1);
//	//tao_button(450, 150, 900, 200, "", 0, 15);
//	outtextxy(300, 260, (char*)"MA SACH ");
//	outtextxy(300, 360, (char*)"TRANG THAI ");
//	outtextxy(300, 460, (char*)"VI TRI ");
//}

void in_themdms(DS_DauSach& DSDS, int check, std::string tensach) {
	Sach s;
	std::string masach = MaSach(tensach);
	s.masach = masach;
	int trangthai = 0;
	s.trangthai = 0;
	int ngan = rand() % (20 - 1 + 1) + 1;
	int ke = rand() % (20 - 1 + 1) + 1;
	std::string vitri = "NGAN " + std::to_string(ngan) + " KE " + std::to_string(ke);
	s.vitri = vitri;
	outtextxy(500, 260, (char*)masach.c_str());
	std::string tt;
	if (trangthai == 0)
		tt = "MUON DUOC";
	if (trangthai == 1)
		tt = "DA MUON";
	if (trangthai == 2)
		tt = "THANH LY";
	outtextxy(500, 360, (char*)tt.c_str());
	outtextxy(500, 460, (char*)vitri.c_str());
	InsertLast_NodeDMSach(DSDS.data[check]->First, s);
}

void xoa_dms() {
	for (int i = 145; i <= 290; i += 40) {
		setfillstyle(SOLID_FILL, 3);
		bar(785, i, 880, i + 40);
		bar(895, i, 1040, i + 40);
		bar(1055, i, 1190, i + 40);
	}
}

void in_dms(Nodedms node) {
	Nodedms in = node;
	std::string trangthai;
	for (int i = 140; i <= 290; i += 40) {
		setbkcolor(3);
		setcolor(15);
		if (in != NULL) {
			barWithTxt(785, i, 840, i + 40, 1, (char*)in->sach.masach.c_str(), 0, 0);
			if (in->sach.trangthai == 0)
				trangthai = "MUON DUOC";
			else if (in->sach.trangthai == 1)
				trangthai = "DA DUOC";
			else if (in->sach.trangthai == 2)
				trangthai = "THANH LY";
			barWithTxt(895, i, 1040, i + 40, 1, (char*)trangthai.c_str(), 0, 0);
			barWithTxt(1055, i, 1190, i + 40, 1, (char*)in->sach.vitri.c_str(), 0, 0);
			in = in->next;
		}
		else {
			setfillstyle(SOLID_FILL, 3);
			bar(785, i, 880, i + 40);
			bar(895, i, 1040, i + 40);
			bar(1055, i, 1190, i + 40);
		}
	}
}

void in_dsds(DS_DauSach& DSDS)
{
	//settextstyle(0, 0, 2);
	int j = 0;
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
		//if (nodes[j]->docgia.trangThai) outtextxy(670, i, (char*)"Dang hoat dong");
		//else outtextxy(670, i, (char*)"Bi khoa");
		j++;
		//if (j == sl || j == so_trang * 10) break;
	}
	/*outtextxy(430, 680, (char*)to_string(pos_trang).c_str());
	outtextxy(440, 680, (char*)"/");
	outtextxy(450, 680, (char*)to_string(so_trang).c_str());*/
}

void butn() {
	button btnMenu(10, 10, 250, 50, WHITE, 1);
	btnMenu.setTitle((char*)"< MENU", BLACK, 3);
	btnMenu.display();
}

void tableDausach(DS_DauSach& DSDS) {
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

void tableDms_suaxoa() {
	setcolor(15);// mau khung
	setbkcolor(3);
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	outtextxy(20, 120, (char*)"TEN SACH ");
	//setcolor(15);
	rndConnerRect(150, 100, 500, 140, 1);
	outtextxy(30, 180, (char*)"MA SACH");
	outtextxy(150, 180, (char*)"TRANG THAI");
	outtextxy(330, 180, (char*)"VI TRI");

	line(20, 170, 450, 170);
	line(20, 170, 20, 620);
	line(450, 170, 450, 620);
	line(20, 620, 450, 620);
	line(20, 220, 450, 220);
	line(120, 170, 120, 620);
	line(280, 170, 280, 620);
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

void displayDms(DS_DauSach& DSDS, Nodedms& node){
	
	setbkcolor(CYAN);
	cleardevice();
	//butn();
	std::string tensach_xem = "";
	std::string tensach_them = "";
	std::string ngan_them = "";
	std::string ke_them = "";
	button btnMenu(10, 10, 250, 50, WHITE, 1);
	btnMenu.setTitle((char*)"< MENU", BLACK, 3);
	btnMenu.display();
	button btnXemThem(290, 10, 430, 50, WHITE, 1);
	btnXemThem.setTitle((char*)"THEM DMS", BLACK, 3);
	btnXemThem.display();
	/*button btnThem(390, 10, 450, 50, WHITE, 1);
	btnThem.setTitle((char*)"THEM", BLACK, 3);
	btnThem.display();*/
	button btnSua(490, 10, 550, 50, WHITE, 1);
	btnSua.setTitle((char*)"SUA", BLACK, 3);
	btnSua.display();
	button btnXoa(590, 10, 650, 50, WHITE, 1);
	btnXoa.setTitle((char*)"XOA", BLACK, 3);
	btnXoa.display();
	button btnTruocDms_xem(780, 330, 870, 360, WHITE, 1);
	btnTruocDms_xem.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDms_xem(1110, 330, 1200, 360, WHITE, 1);
	btnSauDms_xem.setTitle((char*)"SAU >", BLACK, 2);
	button btnThemdms(1150, 620, 1200, 660, WHITE, 1);
	btnThemdms.setTitle((char*)"THEM", BLACK, 2);
	button btnHuyThemdms(760, 620, 810, 660, WHITE, 1);
	btnHuyThemdms.setTitle((char*)"HUY", BLACK, 2);

	Sach s;
	int check;
	
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);

			//chuyen man hinh chuc nang trong dms
			bool xemthemClick = pos_x >= 290 && pos_x <= 430 && pos_y >= 10 && pos_y <= 50;
			//bool themClick = pos_x >= 390 && pos_x <= 450 && pos_y >= 10 && pos_y <= 50;
			bool suaClick = pos_x >= 490 && pos_x <= 550 && pos_y >= 10 && pos_y <= 50;
			bool xoaClick = pos_x >= 590 && pos_x <= 650 && pos_y >= 10 && pos_y <= 50;
			if (xemthemClick) {
				scr_xemthem();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				btnThemdms.display();
				btnHuyThemdms.display();
				tableDausach(DSDS);
				in_dsds(DSDS);
			}
			/*if (themClick) {
				scr_them();
			}*/
			if (suaClick) {
				scr_sua();
			}
			if (xoaClick) {
				scr_xoa();
			}

			//man hinh them/xem dms
			bool tensach_xemclick = pos_x >= 900 && pos_x <= 1180 && pos_y >= 60 && pos_y <= 90;
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
			}

			bool tensach_themclick = pos_x >= 870 && pos_x <= 1200 && pos_y >= 400 && pos_y <= 430;
			if (tensach_themclick) {
				//xoa_dms();
				InputString(880, 400, 1200, 430, tensach_them);
				if (tensach_them != "") {
					check = Search(DSDS, ChuanHoaChuoi(tensach_them));
					if (check == -1)
						dialog("KHONG TIM THAY SACH, NHAP LAI", RED);
					else {
						s.masach = MaSach(tensach_them);
						s.trangthai = 0;
						outtextxy(900, 460, (char*)s.masach.c_str());
						outtextxy(900, 510, (char*)"MUON DUOC");

					}
				}
			}

			bool ngan_themclick = pos_x >= 970 && pos_x <= 1030 && pos_y >= 560 && pos_y <= 590;
			bool ke_themclick = pos_x >= 1100 && pos_x <= 1160 && pos_y >= 560 && pos_y <= 590;
			if (ngan_themclick) {
				InputNumber(980, 560, 1030, 590, ngan_them);
				s.vitri = "NGAN " + ngan_them;
			}
			if (ke_themclick) {
				InputNumber(1110, 560, 1160, 590, ke_them);
				s.vitri += " KE " + ke_them;
				
			}

			bool xacnhanThemdms = pos_x >= 1150 && pos_x <= 1200 && pos_y >= 620 && pos_y <= 660;
			bool xacnhanHuydms = pos_x >= 760 && pos_x <= 810 && pos_y >= 620 && pos_y <= 660;
			if (xacnhanThemdms) {
				InsertLast_NodeDMSach(DSDS.data[check]->First, s);
				dialog("THEM THANH CONG", WHITE);
				outtextxy(910, 70, (char*)DSDS.data[check]->tensach.c_str());
				xoa_dms();
				in_dms(DSDS.data[check]->First);
				tensach_them = "";
			}
			if (xacnhanHuydms) {
				setfillstyle(SOLID_FILL, 3);
				bar(880, 404, 1200, 430);
				tensach_them = "";
				ngan_them = "";
				ke_them = "";
				dialog("HUY NHAP", RED);
			}
			//man hinh xoa/sua dms
			clearmouseclick(WM_LBUTTONDOWN);
		}
	}
	
	
	_getch();
}
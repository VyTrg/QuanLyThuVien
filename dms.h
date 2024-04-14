//void scr_them(DS_DauSach& DSDS, Nodedms& node);
//void scr_xem(DS_DauSach& DSDS, Nodedms& node);
//void scr_sua(DS_DauSach& DSDS, Nodedms& node);

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
	outtextxy(780, 510, (char*)"VI TRI ");
	rndConnerRect(930, 500, 1180, 540, 1);
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
		setfillstyle(1, CYAN);
		outtextxy(785, i, (char*)"");
		bar(785, i, 890, i + 40);
		bar(893, i, 1042, i + 40);
		bar(1055, i, 1195, i + 40);
	}
}

void in_dms(Nodedms node) {
	Nodedms in = node;
	std::string trangthai;
	for (int i = 145; i <= 290; i += 40) {
		setbkcolor(3);
		setcolor(15);
		if (in != NULL) {
			//outtextxy(785, i, (char*)in->sach.masach.c_str());
			barWithTxt(785, i, 885, i + 40, 1, (char*)in->sach.masach.c_str(), 0, 0);
			if (in->sach.trangthai == 0)
				trangthai = "MUON DUOC";
			else if (in->sach.trangthai == 1)
				trangthai = "DA MUON";
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
			bar(1055, i, 1195, i + 40);
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
	//
	bool clickdms[4] = {false};

	setbkcolor(CYAN);
	cleardevice();
	//butn();
	std::string tensach_xem = "";
	std::string tensach_them = "";
	std::string masach_xoa = "";
	button btnMenu(10, 10, 250, 50, WHITE, 1);
	btnMenu.setTitle((char*)"< MENU", BLACK, 3);
	btnMenu.display();
	button btnXoa(290, 10, 410, 50, WHITE, 1);
	btnXoa.setTitle((char*)"XOA", BLACK, 3);
	btnXoa.display();
	button btnSua(450, 10, 570, 50, WHITE, 1);
	btnSua.setTitle((char*)"SUA", BLACK, 3);
	btnSua.display();
	button btnTruocDms_xem(780, 330, 870, 360, WHITE, 1);
	btnTruocDms_xem.setTitle((char*)"< TRUOC", BLACK, 2);
	button btnSauDms_xem(1110, 330, 1200, 360, WHITE, 1);
	btnSauDms_xem.setTitle((char*)"SAU >", BLACK, 2);
	button btnThemdms(1150, 620, 1200, 660, WHITE, 1);
	int chon;
	/*sua 1
	xoa 2
	them 3*/


	Sach s;
	int check;
	
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);

			//chuyen man hinh chuc nang trong dms
			bool xoaClick = pos_x >= 290 && pos_x <= 410 && pos_y >= 10 && pos_y <= 50;
			bool suaClick = pos_x >= 450 && pos_x <= 570 && pos_y >= 10 && pos_y <= 50;
			if (xoaClick) {
				scr_xem();
				scr_xoa();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				tableDausach(DSDS);
				in_dsds(DSDS);
				chon = 2;
			}
			if (suaClick) {
				scr_xem();
				scr_sua();
				btnSauDms_xem.display();
				btnTruocDms_xem.display();
				tableDausach(DSDS);
				chon = 1;
				in_dsds(DSDS);
			}


			//chuc nang
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
			
			bool masach_xoaClick = pos_x >= 900 && pos_x <= 1180 && pos_y >= 400 && pos_y <= 440;
			if (masach_xoaClick && chon == 2) {
				InputMa(900, 400, 1180, 440, masach_xoa);
			}
			int j = 0;
			for (int i = 145; i <= 290; i += 40) {
				clickdms[j] = pos_x >= 785 && pos_x <= 885 && pos_y >= i && pos_y <= (i + 40);
				++j;
			}

			for (int i = 0; i < 4; ++i) {
				if (clickdms[i]) {
					masach_xoa = DSDS.data[check]->First[i].sach.masach;
					//clearmouseclick(WM_LBUTTONDOWN);
				}
			}
			outtextxy(910, 410, (char*)masach_xoa.c_str());
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

			clearmouseclick(WM_LBUTTONDOWN);
		}
	}
	
	_getch();
}
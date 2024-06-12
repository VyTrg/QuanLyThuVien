#pragma once
using namespace std;

//int w = GetSystemMetrics(SM_CXSCREEN);
//int h = GetSystemMetrics(SM_CYSCREEN);

void reset_hienthiDG()
{
	setfillstyle(SOLID_FILL, 3);
	bar(65, 220, 800, 640);
	//rectangle(430, 680, 440, 695);
	setcolor(15);
	rectangle(65, 220, 800, 640);
	line(65, 220, 800, 220);
	line(180, 220, 180, 640);
	line(400, 220, 400, 640);
	line(530, 220, 530, 640);
	line(650, 220, 650, 640);
}

void reset_hienthiDG_quahan()
{
	setfillstyle(SOLID_FILL, 3);
	bar(50, 200, 1450, 700);
	setcolor(15);
	rectangle(50, 200, 1450, 700);
	line(50, 200, 1450, 200);
	line(150, 200, 150, 700);
	line(400, 200, 400, 700);
	line(530, 200, 530, 700);
	line(650, 200, 650, 700);
	line(1050, 200, 1050, 700);
	line(1300, 200, 1300, 700);
}

void reset_sc()
{
	setfillstyle(SOLID_FILL, 3);
	bar(0, 100, w, h);
}

void xoa_thong_bao()
{
	setfillstyle(SOLID_FILL, 3);
	bar(1150, 420, 1500, 440);
}

void thong_bao(string s, int txtcolor)
{
	setbkcolor(3);
	setcolor(txtcolor);
	outtextxy(1150, 420, (char*)s.c_str());
}

void header()
{
	tao_button(10, 10, 110, 60, "< MENU", 0, 15);
	tao_button(400, 10, 1000, 60, "DANH SACH DOC GIA", 0, 15);

	tao_button(1200, 20, 1300, 50, "TAT CA", 0, LIGHTRED);
	tao_button(1350, 20, 1450, 50, "QUA HAN", BLACK, WHITE);
	tao_button(1480, 0, 1536, 30, "   X", 15, RED);

	setbkcolor(3);
	setcolor(YELLOW);

	outtextxy(320, 750, (char*)"Click chuot phai de chon doc gia can xoa");
	outtextxy(320, 770, (char*)"Click chuot trai de chon doc gia can sua");

	rectangle(300, 740, 600, 800);
}

void infoDG()
{
	tao_button(150, 100, 225, 130, "TEN", 0, LIGHTRED);
	tao_button(235, 100, 300, 130, "MATHE", 0, 15);

	tao_button(65, 670, 200, 705, "< Trang truoc", 0, 15);
	tao_button(700, 670, 800, 705, "Trang sau >", 0, 15);

	setbkcolor(3);
	setcolor(15);

	outtextxy(35, 105, (char*)"Sap xep theo");
	outtextxy(105, 190, (char*)"MA THE");
	outtextxy(280, 190, (char*)"Ho");
	outtextxy(455, 190, (char*)"Ten");
	outtextxy(565, 190, (char*)"Phai");
	outtextxy(700, 190, (char*)"Hoat dong");

	rectangle(65, 170, 800, 640);
	line(65, 220, 800, 220);
	line(180, 170, 180, 640);
	line(400, 170, 400, 640);
	line(530, 170, 530, 640);
	line(650, 170, 650, 640);
}

void NhapDG_info()
{
	outtextxy(1200, 135, (char*)"THEM DOC GIA");

	rectangle(950, 120, 1500, 400);
	line(950, 170, 1500, 170);

	outtextxy(1100, 200, (char*)"HO");
	outtextxy(1100, 250, (char*)"TEN");
	outtextxy(1100, 300, (char*)"PHAI");

	tao_button(1150, 195, 1350, 225, "", 0, 15);
	tao_button(1150, 245, 1350, 275, "", 0, 15);
	tao_button(1150, 295, 1350, 325, "", 0, 15);

	tao_button(1200, 350, 1300, 380, "THEM", 0, 15);
}

void HieuChinhDG()
{
	tao_button(1200, 465, 1400, 495, "", 0, 15);
	tao_button(1200, 525, 1400, 555, "", 0, 15);

	tao_button(1200, 575, 1400, 605, "", 0, 15);
	tao_button(1200, 625, 1400, 655, "", 0, 15);
	tao_button(1200, 675, 1400, 705, "", 0, 15);

	tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
	tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);

	tao_button(1420, 465, 1480, 495, "XOA", 0, 15);
	tao_button(1250, 770, 1350, 800, "SUA", 0, 15);

	setbkcolor(3);
	setcolor(15);

	outtextxy(1000, 470, (char*)"XOA DOC GIA (Theo MA THE)");
	outtextxy(1000, 530, (char*)"SUA DOC GIA (Theo MA THE)");

	outtextxy(1150, 580, (char*)"HO");
	outtextxy(1150, 630, (char*)"TEN");
	outtextxy(1150, 680, (char*)"PHAI");
	outtextxy(1100, 730, (char*)"TRANG THAI");

	rectangle(950, 450, 1500, 810);
	line(950, 510, 1500, 510);
}

void info_quahan()
{
	tao_button(50, 720, 170, 755, "< Trang truoc", 0, 15);
	tao_button(1350, 720, 1450, 755, "Trang sau >", 0, 15);

	setbkcolor(3);
	setcolor(15);

	rectangle(50, 150, 1450, 700);
	line(50, 200, 1450, 200);
	line(150, 150, 150, 700);
	line(400, 150, 400, 700);
	line(530, 150, 530, 700);
	line(650, 150, 650, 700);
	line(1050, 150, 1050, 700);
	line(1300, 150, 1300, 700);

	outtextxy(75, 170, (char*)"MA THE");
	outtextxy(250, 170, (char*)"Ho");
	outtextxy(450, 170, (char*)"Ten");
	outtextxy(560, 170, (char*)"MA SACH");
	outtextxy(800, 170, (char*)"Ten Sach");
	outtextxy(1150, 170, (char*)"Ngay muon");
	outtextxy(1320, 170, (char*)"So ngay qua han");
}

void in_docgia_quahan(HienThi* ht, int sl, int so_trang_qh, int pos_trang_qh, int j)
{
	
	for (int i = 220; i < 700; i += 40)
	{
		setbkcolor(3);
		setcolor(15);
		outtextxy(80, i, (char*)ht[j].maThe.c_str());
		outtextxy(180, i, (char*)ht[j].ho.c_str());
		outtextxy(430, i, (char*)ht[j].ten.c_str());
		outtextxy(550, i, (char*)ht[j].maSach.c_str());
		outtextxy(700, i, (char*)"Nhat ki trong tu");
		string day = DinhDangNgay(ht[j].ngayMuon);
		outtextxy(1145, i, (char*)day.c_str());
		outtextxy(1360, i, (char*)to_string(ht[j].han).c_str());
		j++;
		if (j == sl || j == pos_trang_qh * 12) break;
	}
	outtextxy(690, 730, (char*)to_string(pos_trang_qh).c_str());
	outtextxy(702, 730, (char*)"/");
	outtextxy(710, 730, (char*)to_string(so_trang_qh).c_str());
}

void in_docgia(NODE_DG** nodes, int sl, int so_trang, int pos_trang, int j)
{
	sl = nDG;
	for (int i = 240; i <= 600; i += 40)
	{
		setbkcolor(3);
		setcolor(15);
		outtextxy(105, i, (char*)nodes[j]->docgia.MATHE.c_str());
		outtextxy(220, i, (char*)nodes[j]->docgia.ho.c_str());
		outtextxy(440, i, (char*)nodes[j]->docgia.ten.c_str());
		outtextxy(570, i, (char*)nodes[j]->docgia.phai.c_str());
		if (nodes[j]->docgia.trangThai) outtextxy(670, i, (char*)"Dang hoat dong");
		else outtextxy(670, i, (char*)"Bi khoa");
		j++;
		if (j == sl || j == so_trang * 10) break;
	}
	outtextxy(430, 680, (char*)to_string(pos_trang).c_str());
	outtextxy(442, 680, (char*)"/");
	outtextxy(450, 680, (char*)to_string(so_trang).c_str());
}

void in_ds_dg(TREE_DG t, int& pos_trang, int & type_check)
{
	if (nDG == 0)
	{
		outtextxy(300, 730, (char*)"DANH SACH DOC GIA TRONG!");
		delay(1000);
		setfillstyle(SOLID_FILL, 3);
		bar(300, 730, 600, 750);
	}
	else {
		type_check = 1;
		pos_trang = 1;
		NODE_DG** nodes = new NODE_DG * [nDG];
		int sl = 0;
		DuyetLNR(t, nodes, sl);
		xep_noi_botten(nodes, sl);
		int j = 0;
		int so_trang = 0;
		if (nDG % 10 == 0 && nDG != 0) so_trang = nDG / 10;
		else so_trang = (nDG / 10) + 1;
		in_docgia(nodes, sl, so_trang, pos_trang, j);
		delete[] nodes;
		nodes = nullptr;
	}
}

void in_ds_dgmoithem(TREE_DG t,string MATHE, int& pos_trang, int& type_check)
{
	if (nDG == 0)
	{
		outtextxy(300, 730, (char*)"DANH SACH DOC GIA TRONG!");
		delay(1000);
		setfillstyle(SOLID_FILL, 3);
		bar(300, 730, 600, 750);
	}
	else {
		type_check = 1;
		NODE_DG** nodes = new NODE_DG * [nDG];
		int sl = 0;
		DuyetLNR(t, nodes, sl);
		xep_noi_botten(nodes, sl);
		int j = 0;
		while (t != NULL && t->docgia.MATHE.compare(MATHE) !=0 )
		{
			if (t->docgia.MATHE.compare(MATHE) < 0)
			{
				t = t->pLeft;
			}
			else t = t->pRight;
		}
		int k = 0;
		for (int i = 0; i < nDG; i++) {
			if (nodes[i]->docgia.MATHE.compare(MATHE) == 0) {
				k = i;
			}
		}
		int so_trang = 0;
		if (nDG % 10 == 0 && nDG != 0) so_trang = nDG / 10;
		else so_trang = (nDG / 10) + 1;
		pos_trang = k / 10 + 1;
		k = (k / 10) * 10;
		in_docgia(nodes, sl, so_trang, pos_trang, k);
		delete[] nodes;
		nodes = nullptr;
	}
}

DocGia lay_MATHE_click(TREE_DG t, int index)
{
	NODE_DG** nodes = new NODE_DG * [nDG];
	int sl = 0;
	DuyetLNR(t, nodes, sl);
	xep_noi_botten(nodes, sl);
	return nodes[index]->docgia;
}

void main_sc(TREE_DG &t, int& pos_trang, int& pos_trang_qh)
{
	setbkcolor(3);
	cleardevice();
	header();
	infoDG();
	NhapDG_info();
	HieuChinhDG();
	int type_check = 1;
	int check = 1;
	in_ds_dg(t, pos_trang, type_check);
	DocGia dg, dg_sua, dg_xoa;

	//bool clicktendg[10] = { false };
	int checkclick = -1;
	int so_trang = 0;
	if (nDG % 10 == 0 && nDG != 0) so_trang = nDG / 10;
	else so_trang = (nDG / 10) + 1;
	
	int so_trang_qh = 0;
	if (soSachMuon % 12 == 0 && soSachMuon != 0) so_trang_qh = soSachMuon / 12;
	else so_trang_qh = (soSachMuon / 12) + 1;

	bool check_nhap[10] = { false };

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
			bool ho = pos_x >= 1150 && pos_x <= 1350 && pos_y >= 195 && pos_y <= 225;
			bool ten = pos_x >= 1150 && pos_x <= 1350 && pos_y >= 245 && pos_y <= 275;
			bool phai = pos_x >= 1150 && pos_x <= 1350 && pos_y >= 295 && pos_y <= 325;

			bool them = pos_x >= 1200 && pos_x <= 1300 && pos_y >= 350 && pos_y <= 380;

			bool nhap_xoa = pos_x >= 1150 && pos_x <= 1350 && pos_y >= 465 && pos_y <= 495;
			bool nhap_sua = pos_x >= 1150 && pos_x <= 1350 && pos_y >= 525 && pos_y <= 555;

			bool hoS = pos_x >= 1200 && pos_x <= 1400 && pos_y >= 575 && pos_y <= 605;
			bool tenS = pos_x >= 1200 && pos_x <= 1400 && pos_y >= 625 && pos_y <= 655;
			bool phaiS = pos_x >= 1200 && pos_x <= 1400 && pos_y >= 675 && pos_y <= 705;
			bool hoatdong = pos_x >= 1200 && pos_x <= 1310 && pos_y >= 725 && pos_y <= 755;
			bool khoa = pos_x >= 1330 && pos_x <= 1400 && pos_y >= 725 && pos_y <= 755;
			
			bool sxten = pos_x >= 150 && pos_x <= 225 && pos_y >= 100 && pos_y <= 130;
			bool sxma = pos_x >= 235 && pos_x <= 300 && pos_y >= 100 && pos_y <= 130;

			bool prev = pos_x >= 65 && pos_x <= 200 && pos_y >= 670 && pos_y <= 705;
			bool next = pos_x >= 700 && pos_x <= 800 && pos_y >= 670 && pos_y <= 705;

			bool xoa = pos_x >= 1420 && pos_x <= 1480 && pos_y >= 465 && pos_y <= 495;
			bool sua = pos_x >= 1250 && pos_x <= 1350 && pos_y >= 770 && pos_y <= 800;
			
			bool tatca = pos_x >= 1200 && pos_x <= 1300 && pos_y >= 20 && pos_y <= 50;
			bool quahan = pos_x >= 1350 && pos_x <= 1450 && pos_y >= 20 && pos_y <= 50;

			bool x = pos_x >= 1480 && pos_x <= 1536 && pos_y >= 0 && pos_y <= 30;
			
			bool prev_quahan = pos_x >= 50 && pos_x <= 170 && pos_y >= 720 && pos_y <= 755;
			bool next_quahan = pos_x >= 1350 && pos_x <= 1450 && pos_y >= 720 && pos_y <= 755;

			bool chuot = pos_x >= 65 && pos_x <= 800 && pos_y >= 220 && pos_y <= 640;

			if (tatca) {
				reset_sc();
				tao_button(1200, 20, 1300, 50, "TAT CA", 0, LIGHTRED);
				tao_button(1350, 20, 1450, 50, "QUA HAN", BLACK, WHITE);
				check = 1;
				infoDG();
				NhapDG_info();
				HieuChinhDG();
				in_ds_dg(t, pos_trang, type_check);
			}

			if (quahan) {
				tao_button(1200, 20, 1300, 50, "TAT CA", 0, 15);
				tao_button(1350, 20, 1450, 50, "QUA HAN", BLACK, LIGHTRED);
				reset_sc();
				check = 2;
				info_quahan();
				pos_trang_qh = 1;
				HienThi* ht = new HienThi[soSachMuon];
				int sl = 0;
				DuyetHT(t, (ht), sl);
				xep_noi_botngay(ht, sl);
				int j = (pos_trang_qh - 1) * 12;
				in_docgia_quahan(ht, sl, so_trang_qh, pos_trang_qh, j);
				delete[] ht;
				ht = nullptr;
			}

			string str;

			if (ho && check == 1) {
				Nhap_string(1150, 195, 1350, 225, str);
				if (str != "") {
					dg.ho = chuanhoa_name(str);
					check_nhap[0] = 1;
				}
				if (check_nhap[1] == 0) {
					str = "";
					Nhap_string(1150, 245, 1350, 275, str);
					if (str != "") {
						dg.ten = chuanhoa_name(str);
						check_nhap[1] = 1;
					}
				}
				if (check_nhap[2] == 0) {
					str = "";
					Nhap_string(1150, 295, 1350, 325, str);
					if (str != "") {
						dg.phai = chuanhoa_name(str);
						check_nhap[2] = 1;
					}
				}
			}
			if (ten && check == 1) {
				Nhap_string(1150, 245, 1350, 275, str);
				if (str != "") {
					dg.ten = chuanhoa_name(str);
					check_nhap[1] = 1;
				}
				if (check_nhap[2] == 0) {
					str = "";
					Nhap_string(1150, 295, 1350, 325, str);
					if (str != "") {
						dg.phai = chuanhoa_name(str);
						check_nhap[2] = 1;
					}
				}
			}
			if (phai && check == 1) {
				Nhap_string(1150, 295, 1350, 325, str);
				if (str != "") {
					dg.phai = chuanhoa_name(str);
					check_nhap[2] = 1;
				}
			}
			if (them && (!check_nhap[0] || !check_nhap[1] || !check_nhap[2])) {
				setbkcolor(3);
				setcolor(RED);
				outtextxy(1150, 420, (char*)"YEU CAU NHAP DU THONG TIN!");
				delay(1000);
				xoa_thong_bao();
			}
			if (them && check_nhap[0] && check_nhap[1] && check_nhap[2] && check == 1) {

				tao_button(1200, 350, 1300, 380, "THEM", 0, LIGHTRED);
				delay(300);
				tao_button(1200, 350, 1300, 380, "THEM", 0, 15);
				
				dg.MATHE = RandomMT(t);
				dg.trangThai = 1;
				dg.muon = 0;
				
				InsertDGtoTree(t, dg);
				cap_nhap_AVL(t);
				if (nDG % 10 == 0 && nDG != 0) so_trang = nDG / 10;
				else so_trang = (nDG / 10) + 1;
				reset_hienthiDG(); 
				string s = "THAO TAC THANH CONG";
				thong_bao(s, 15);
				in_ds_dgmoithem(t, dg.MATHE, pos_trang, type_check);
				delay(1000);
				xoa_thong_bao();
				check_nhap[0] = check_nhap[1] = check_nhap[2] = 0;
				tao_button(1150, 195, 1350, 225, "", 0, 15);
				tao_button(1150, 245, 1350, 275, "", 0, 15);
				tao_button(1150, 295, 1350, 325, "", 0, 15);
			}
			if (nhap_xoa && check == 1) {
				Nhap_string(1200, 465, 1400, 495, str);
				if (str != "") dg_xoa.MATHE = str;
				bool k = Tim_DG(t, dg_xoa.MATHE);
				if (!k) {
					string s = "KHONG TIM THAY DOC GIA!";
					thong_bao(s, 15);
					delay(1000);
					xoa_thong_bao();
					tao_button(1200, 465, 1400, 495, "", 0, 15);
				}
				check_nhap[7] = 1;
			}
			if (xoa && check_nhap[7] && check == 1) {
				tao_button(1420, 465, 1480, 495, "XOA", 0, LIGHTRED);
				delay(300);
				tao_button(1420, 465, 1480, 495, "XOA", 0, 15);
				if (dg_xoa.muon == 0) {
					t = Deleted_DG(t, dg_xoa.MATHE);
					cap_nhap_AVL(t);
					if (nDG % 10 == 0 && nDG != 0) so_trang = nDG / 10;
					else so_trang = (nDG / 10) + 1;
					string s = "THAO TAC THANH CONG";
					thong_bao(s, 15);
					reset_hienthiDG();
					in_ds_dg(t, pos_trang, type_check);
					delay(1000);
					xoa_thong_bao();
					tao_button(1200, 465, 1400, 495, "", 0, 15);
					if (dg_sua.MATHE.compare(dg_xoa.MATHE) == 0) {
						tao_button(1200, 525, 1400, 555, "", 0, 15);
						tao_button(1200, 575, 1400, 605, "", 0, 15);
						tao_button(1200, 625, 1400, 655, "", 0, 15);
						tao_button(1200, 675, 1400, 705, "", 0, 15);
						tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
						tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);
					}
					check_nhap[7] = 0;
				}
				else {
					string s = "DOC GIA DANG MUON SACH, KHONG THE XOA!";
					thong_bao(s, 15);
					delay(1500);
					xoa_thong_bao();
					tao_button(1200, 465, 1400, 495, "", 0, 15);
				}
			}
			/*if (check == 1 && type_check == 1) {
				int k = 0;
				for (int i = 220; i <= 640; i += 40) {
					clicktendg[k] = pos_x >= 65 && pos_x <= 800 && pos_y >= i && pos_y <= (i + 40);
					++k;
				}
				for (int i = 0; i < 10; ++i) {
					if (clicktendg[i] && check == 1) {
						checkclick = i;
						dg_sua.MATHE = lay_MATHE_click(t, checkclick + (pos_trang - 1) * 10);
						tao_button(1200, 525, 1400, 555, (char*)dg_sua.MATHE.c_str(), 0, 15);
						check_nhap[3] = 1;
						break;
					}
				}
			}*/
			if (chuot && check == 1 && type_check == 1) {
				checkclick = (pos_y - 220) / 40;
				dg_sua = lay_MATHE_click(t, checkclick + (pos_trang - 1) * 10);
				tao_button(1200, 525, 1400, 555, (char*)dg_sua.MATHE.c_str(), 0, 15);
				tao_button(1200, 575, 1400, 605, "", 0, 15);
				tao_button(1200, 625, 1400, 655, "", 0, 15);
				tao_button(1200, 675, 1400, 705, "", 0, 15);
				tao_button(1200, 575, 1300, 605, (char*)dg_sua.ho.c_str(), 0, 15);
				tao_button(1200, 625, 1300, 655, (char*)dg_sua.ten.c_str(), 0, 15);
				tao_button(1200, 675, 1300, 705, (char*)dg_sua.phai.c_str(), 0, 15);
				tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
				tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);
				if (dg_sua.trangThai) tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, LIGHTRED);
				else tao_button(1330, 725, 1400, 755, "KHOA", 0, LIGHTRED);
				for (int i = 3; i < 7; i++) check_nhap[i] = 1;
			}
			if (nhap_sua && check == 1) {
				Nhap_string(1200, 525, 1400, 555, str);
				if (str != "") dg_sua.MATHE = str;
				bool k = Tim_DG(t, dg_sua.MATHE);
				if (k) {
					dg_sua = Tim(t, str);
					tao_button(1200, 525, 1400, 555, (char*)dg_sua.MATHE.c_str(), 0, 15);
					tao_button(1200, 575, 1400, 605, "", 0, 15);
					tao_button(1200, 625, 1400, 655, "", 0, 15);
					tao_button(1200, 575, 1300, 605, (char*)dg_sua.ho.c_str(), 0, 15);
					tao_button(1200, 625, 1300, 655, (char*)dg_sua.ten.c_str(), 0, 15);
					tao_button(1200, 675, 1300, 705, (char*)dg_sua.phai.c_str(), 0, 15);
					tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
					tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);
					if (dg_sua.trangThai) tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, LIGHTRED);
					else tao_button(1330, 725, 1400, 755, "KHOA", 0, LIGHTRED);
					for (int i = 3; i < 7; i++) check_nhap[i] = 1;
					string s = "TIM THAY DOC GIA!";
					thong_bao(s, 15);
					delay(1000);
					xoa_thong_bao();
					tao_button(1200, 675, 1400, 705, "", 0, 15);
					//check_nhap[3] = 1;
				}
				else {
					string s = "KHONG TIM THAY DOC GIA!";
					thong_bao(s, 15);
					delay(1000);
					xoa_thong_bao();
					tao_button(1200, 525, 1400, 555, "", 0, 15);
				}
			}
			if (hoS && check_nhap[3] && check == 1) {
				str = dg_sua.ho;
				Nhap_string(1200, 575, 1400, 605, str);
				if (str != "") {
					dg_sua.ho = chuanhoa_name(str);
					check_nhap[4] = 1;
				}
			}
			if (tenS && check_nhap[3] && check == 1) {
				str = dg_sua.ten;
				if (check_nhap[5] == 0) {
					Nhap_string(1200, 625, 1400, 655, str);
					if (str != "") {
						dg_sua.ten = chuanhoa_name(str);
						check_nhap[5] = 1;
					}
				}
			}
			if (phaiS && check_nhap[3] && check == 1) {
				str = dg_sua.phai;
				if (check_nhap[6] == 0) {
					Nhap_string(1200, 675, 1400, 705, str);
					if (str != "") {
						dg_sua.phai = chuanhoa_name(str);
						check_nhap[6] = 1;
					}
				}
			}
			if (hoatdong && check_nhap[3] && check == 1) {
				tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, LIGHTRED);
				tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);
				dg.trangThai = 1;
				check_nhap[7] = 1;
			}
			if (khoa && check_nhap[3] && check == 1) {
				tao_button(1330, 725, 1400, 755, "KHOA", 0, LIGHTRED);
				tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
				dg.trangThai = 0;
				check_nhap[8] = 1;
			}
			if (sua && check_nhap[3] && check_nhap[4] && check_nhap[5] && check_nhap[6] && check_nhap[8] && check == 1) {
				tao_button(1250, 770, 1350, 800, "SUA", 0, LIGHTRED);
				delay(300);
				tao_button(1250, 770, 1350, 800, "SUA", 0, 15);
				TREE_DG temp = Find_DG(t, dg_sua.MATHE);
				temp->docgia.ho = dg_sua.ho;
				temp->docgia.ten = dg_sua.ten;
				temp->docgia.phai = dg_sua.phai;
				temp->docgia.trangThai = dg.trangThai;
				reset_hienthiDG();
				string s = "THAO TAC THANH CONG";
				thong_bao(s, 15);
				in_ds_dg(t, pos_trang, type_check);
				tao_button(1200, 525, 1400, 555, "", 0, 15);
				tao_button(1200, 575, 1400, 605, "", 0, 15);
				tao_button(1200, 625, 1400, 655, "", 0, 15);
				tao_button(1200, 675, 1400, 705, "", 0, 15);
				tao_button(1200, 725, 1310, 755, "HOAT DONG", 0, 15);
				tao_button(1330, 725, 1400, 755, "KHOA", 0, 15);
				delay(1000);
				xoa_thong_bao();
				check_nhap[3] = 0;
			}
			if (sxten && check == 1) {
				reset_hienthiDG();
				tao_button(150, 100, 225, 130, "TEN", 0, LIGHTRED);
				tao_button(235, 100, 300, 130, "MATHE", 0, 15);
				in_ds_dg(t, pos_trang, type_check);
			}
			if (pos_trang > 1 && type_check == 1 && check == 1) {
				if (prev) {
					tao_button(65, 670, 200, 705, "< Trang truoc", 0, LIGHTRED);
					delay(300);
					tao_button(65, 670, 200, 705, "< Trang truoc", 0, 15);
					pos_trang--;
					reset_hienthiDG();
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(t, nodes, sl);
					xep_noi_botten(nodes, sl);
					int j = (pos_trang - 1) * 10;
					in_docgia(nodes, sl, so_trang, pos_trang, j);
					delete[] nodes;
					nodes = nullptr;
				}
			}
			if (pos_trang < so_trang && type_check == 1 && check == 1) {
				if (next) {
					tao_button(700, 670, 800, 705, "Trang sau >", 0, LIGHTRED);
					delay(300);
					tao_button(700, 670, 800, 705, "Trang sau >", 0, 15);
					pos_trang++;
					reset_hienthiDG();
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(t, nodes, sl);
					xep_noi_botten(nodes, sl);
					int j = (pos_trang - 1) * 10;
					in_docgia(nodes, sl, so_trang, pos_trang, j);
					delete[] nodes;
					nodes = nullptr;
				}
			}
			if (sxma && check == 1) {
				type_check = 2;
				pos_trang = 1;
				reset_hienthiDG();
				tao_button(150, 100, 225, 130, "TEN", 0, 15);
				tao_button(235, 100, 300, 130, "MATHE", 0, LIGHTRED);
				NODE_DG** nodes = new NODE_DG * [nDG];
				int sl = 0;
				DuyetLNR(t, nodes, sl);
				xep_noi_botMATHE(nodes, sl);
				int j = (pos_trang - 1) * 10;
				in_docgia(nodes, sl, so_trang, pos_trang, j);
				delete[] nodes;
				nodes = nullptr;
			}
			if (pos_trang > 1 && type_check == 2 && check == 1) {
				if (prev) {
					tao_button(65, 670, 200, 705, "< Trang truoc", 0, LIGHTRED);
					delay(300);
					tao_button(65, 670, 200, 705, "< Trang truoc", 0, 15);
					pos_trang--;
					reset_hienthiDG();
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(t, nodes, sl);
					xep_noi_botMATHE(nodes, sl);
					int j = (pos_trang - 1) * 10;
					in_docgia(nodes, sl, so_trang, pos_trang, j);
					delete[] nodes;
					nodes = nullptr;
				}
			}
			if (pos_trang < so_trang && type_check == 2 && check == 1) {
				if (next) {
					tao_button(700, 670, 800, 705, "Trang sau >", 0, LIGHTRED);
					delay(300);
					tao_button(700, 670, 800, 705, "Trang sau >", 0, 15);
					pos_trang++;
					reset_hienthiDG();
					NODE_DG** nodes = new NODE_DG * [nDG];
					int sl = 0;
					DuyetLNR(t, nodes, sl);
					xep_noi_botMATHE(nodes, sl);
					int j = (pos_trang - 1) * 10;
					in_docgia(nodes, sl, so_trang, pos_trang, j);
					delete[] nodes;
					nodes = nullptr;
				}
			}
			if (pos_trang_qh > 1 && check == 2) {
				if (prev_quahan) {
					tao_button(50, 720, 170, 755, "< Trang truoc", 0, LIGHTRED);
					delay(300);
					tao_button(50, 720, 170, 755, "< Trang truoc", 0, 15);
					pos_trang_qh--;
					reset_hienthiDG_quahan();
					HienThi* ht = new HienThi[soSachMuon];
					int sl = 0;
					DuyetHT(t, (ht), sl);
					xep_noi_botngay(ht, sl);
					int j = (pos_trang_qh - 1) * 12;
					in_docgia_quahan(ht, sl, so_trang_qh, pos_trang_qh, j);
					delete[] ht;
					ht = nullptr;
				}
			}
			if (pos_trang_qh < so_trang_qh && check == 2) {
				if (next_quahan) {
					tao_button(1350, 720, 1450, 755, "Trang sau >", 0, LIGHTRED);
					delay(300);
					tao_button(1350, 720, 1450, 755, "Trang sau >", 0, 15);
					pos_trang_qh++;
					reset_hienthiDG_quahan();
					HienThi* ht = new HienThi[soSachMuon];
					int sl = 0;
					DuyetHT(t, (ht), sl);
					xep_noi_botngay(ht, sl);
					int j = (pos_trang_qh - 1) * 12;
					in_docgia_quahan(ht, sl, so_trang_qh, pos_trang_qh, j);
					delete[] ht;
					ht = nullptr;
				}
			}
			if (x) return;
		}
		if (ismouseclick(WM_RBUTTONDOWN)) {
			int pos_x1, pos_y1;
			getmouseclick(WM_RBUTTONDOWN, pos_x1, pos_y1);

			string str;

			if (check == 1 && type_check == 1) {
				if (pos_x1 >= 65 && pos_x1 <= 800 && pos_y1 >= 220 && pos_y1 <= 640) {
					checkclick = (pos_y1 - 220) / 40;
					dg_xoa = lay_MATHE_click(t, checkclick + (pos_trang - 1) * 10);
					tao_button(1200, 465, 1400, 495, (char*)dg_xoa.MATHE.c_str(), 0, 15);
					check_nhap[7] = 1;
					//break;
				}
			}
		}
	}
}
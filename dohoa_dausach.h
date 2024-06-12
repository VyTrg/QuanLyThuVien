#pragma once
//#include "cautrucdanhmucsach.h"
//#include "cautrucdausach.h"
//#include "muontra.h"
using namespace std;

void In_DauSach() {

	outtextxy(30, 115, (char*)"ISBN");
	rectangle(10, 100, 100, 140);
	rectangle(10, 140, 100, 600);

	outtextxy(150, 115, (char*)"TEN SACH");
	rectangle(100, 100, 300, 140);
	rectangle(100, 140, 300, 600);

	outtextxy(310, 115, (char*)"SO TRANG");
	rectangle(300, 100, 400, 140);
	rectangle(300, 140, 400, 600);

	outtextxy(450, 115, (char*)"TAC GIA");
	rectangle(400, 100, 550, 140);
	rectangle(400, 140, 550, 600);

	outtextxy(570, 115, (char*)"NXB");
	rectangle(550, 100, 620, 140);
	rectangle(550, 140, 620, 600);

	outtextxy(670, 115, (char*)"THE LOAI");
	rectangle(620, 100, 780, 140);
	rectangle(620, 140, 780, 600);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	outtextxy(450, 5, (char*)"DANH SACH DAU SACH");

	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(250, 55, (char*)"Tim dau sach");

	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	outtextxy(970, 110, (char*)"THONG TIN SACH");
	rectangle(800, 100, 1350, 150);


	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	outtextxy(810, 170, (char*)"ISBN");
	outtextxy(810, 230, (char*)"Tensach");
	outtextxy(810, 290, (char*)"Sotrang");
	outtextxy(810, 350, (char*)"Tacgia");
	outtextxy(810, 410, (char*)"NXB");
	outtextxy(810, 470, (char*)"Theloai");

	rectangle(900, 160, 1300, 200);// ISBN

	rectangle(900, 220, 1300, 260);// TENSACH 

	rectangle(900, 280, 1300, 320);// SOTRANG 

	rectangle(900, 340, 1300, 380);//TACGIA

	rectangle(900, 400, 1300, 440);//NXB

	rectangle(900, 460, 1300, 500);//THELOAI

	rectangle(800, 150, 1350, 550);

	rectangle(500, 50, 900, 80);

	button DrawMenu(10, 10, 130, 40, 15, 8);// l - t - r - b - cl - rad
	char S1[10] = "< MENU";
	DrawMenu.setTitle(S1, 1, 2);
	DrawMenu.display();

	button DrawTrang(10, 620, 150, 650, 15, 1);
	char S3[20] = "<Trang truoc";
	DrawTrang.setTitle(S3, 1, 1);
	DrawTrang.display();

	button DrawTrangsau(640, 620, 780, 650, 15, 1);
	char S4[15] = "Trang sau>";
	DrawTrangsau.setTitle(S4, 1, 1);
	DrawTrangsau.display();

	button DrawThem(900, 510, 1050, 540, 10, 1);
	char S11[20] = "THEM";
	DrawThem.setTitle(S11, 4, 1);
	DrawThem.display();

	button DrawHieuchinh(1150, 510, 1300, 540, 10, 1);
	char S12[20] = "HIEU CHINH";
	DrawHieuchinh.setTitle(S12, 4, 1);
	DrawHieuchinh.display();

	button DrawTOP10(1000, 50, 1200, 90, 10, 1);
	char S16[20] = "TOP 10 SACH";
	DrawTOP10.setTitle(S16, 4, 1);
	DrawTOP10.display();

	button DrawTHELOAI(10, 50, 150, 90, 10, 1);
	char S21[20] = "THE LOAI";
	DrawTHELOAI.setTitle(S21, 4, 1);
	DrawTHELOAI.display();

}

void In_TheoTheLoai() {

	outtextxy(30, 115, (char*)"ISBN");
	rectangle(10, 100, 100, 140);
	rectangle(10, 140, 100, 600);

	outtextxy(150, 115, (char*)"TEN SACH");
	rectangle(100, 100, 300, 140);
	rectangle(100, 140, 300, 600);

	outtextxy(310, 115, (char*)"SO TRANG");
	rectangle(300, 100, 400, 140);
	rectangle(300, 140, 400, 600);

	outtextxy(450, 115, (char*)"TAC GIA");
	rectangle(400, 100, 550, 140);
	rectangle(400, 140, 550, 600);

	outtextxy(570, 115, (char*)"NXB");
	rectangle(550, 100, 620, 140);
	rectangle(550, 140, 620, 600);

	outtextxy(670, 115, (char*)"THE LOAI");
	rectangle(620, 100, 780, 140);
	rectangle(620, 140, 780, 600);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(14);
	outtextxy(200, 30, (char*)"IN THEO THE LOAI");

	button DrawLui(10, 650, 150, 700, 15, 1);
	char S23[20] = "<";
	DrawLui.setTitle(S23, 1, 1);
	DrawLui.display();

	button DrawToi(640, 650, 780, 700, 15, 1);
	char S24[15] = ">";
	DrawToi.setTitle(S24, 1, 1);
	DrawToi.display();

	button DrawThoat(1100, 650, 1300, 700, 10, 1);
	char S21[20] = "THOAT";
	DrawThoat.setTitle(S21, 4, 4);
	DrawThoat.display();

}


void  In_DauSach_Top10() {
	outtextxy(30, 115, (char*)"ISBN");
	rectangle(10, 100, 100, 140);
	rectangle(10, 140, 100, 600);

	outtextxy(150, 115, (char*)"TEN SACH");
	rectangle(100, 100, 300, 140);
	rectangle(100, 140, 300, 600);

	outtextxy(310, 115, (char*)"SO TRANG");
	rectangle(300, 100, 400, 140);
	rectangle(300, 140, 400, 600);

	outtextxy(450, 115, (char*)"TAC GIA");
	rectangle(400, 100, 550, 140);
	rectangle(400, 140, 550, 600);

	outtextxy(570, 115, (char*)"NXB");
	rectangle(550, 100, 620, 140);
	rectangle(550, 140, 620, 600);

	outtextxy(670, 115, (char*)"THE LOAI");
	rectangle(620, 100, 780, 140);
	rectangle(620, 140, 780, 600);

	outtextxy(790, 115, (char*)"SO LUOT MUON");
	rectangle(780, 100, 1000, 140);
	rectangle(780, 140, 1000, 600);

	settextstyle(BOLD_FONT, HORIZ_DIR, 5);
	setcolor(14);
	outtextxy(220, 20, (char*)"TOP 10 SACH CO LUOT MUON NHIEU NHAT");

	button DrawThoat(1100, 650, 1300, 700, 10, 1);
	char S21[20] = "THOAT";
	DrawThoat.setTitle(S21, 4, 4);
	DrawThoat.display();


}


void InDanhSachDauSach(DS_DauSach& DSDS, int startIndex, int soLuongSach, int pos_trang) {
	setcolor(15);
	setbkcolor(3);

	if (DSDS.data == nullptr || DSDS.n == 0 || startIndex >= DSDS.n) {
		return;
	}

	int endIndex = min(startIndex + soLuongSach, DSDS.n);

	for (int j = startIndex; j < endIndex; j++) {
		if (DSDS.data[j] == nullptr) {
			return;
		}
		setbkcolor(3);
		setcolor(15);
		barWithTxt(20, 150 + (j - startIndex) * 40, 90, 185 + (j - startIndex) * 40, 1, (char*)DSDS.data[j]->ISBN.c_str(), 0, 0);
		barWithTxt(110, 150 + (j - startIndex) * 40, 290, 185 + (j - startIndex) * 40, 1, (char*)DSDS.data[j]->tensach.c_str(), 0, 0);
		barWithTxt(310, 150 + (j - startIndex) * 40, 390, 185 + (j - startIndex) * 40, 1, (char*)std::to_string(DSDS.data[j]->sotrang).c_str(), 0, 0);
		barWithTxt(410, 150 + (j - startIndex) * 40, 540, 185 + (j - startIndex) * 40, 1, (char*)DSDS.data[j]->tacgia.c_str(), 0, 0);
		barWithTxt(560, 150 + (j - startIndex) * 40, 610, 185 + (j - startIndex) * 40, 1, (char*)std::to_string(DSDS.data[j]->nxb).c_str(), 0, 0);
		barWithTxt(630, 150 + (j - startIndex) * 40, 770, 185 + (j - startIndex) * 40, 1, (char*)DSDS.data[j]->theloai.c_str(), 0, 0);
	}

}


void XoaDanhSachCu(DS_DauSach& DSDS) {
	setbkcolor(3);
	setcolor(15);
	for (int j = 0; j < DSDS.n; j++) {
		setfillstyle(SOLID_FILL, 3);
		bar(20, 150 + j * 40, 770, 185 + j * 40);

	}
}

void CapNhatThongTinSach(DS_DauSach& DSDS, int index, int trangHienTai, int soSachTrenTrang) {

	DauSach ds;
	std::string tenSachMoi = "";
	std::string soTrangMoistr = "";
	int soTrangMoi = 0;
	std::string tacGiaMoi = "";
	std::string nxbMoistr = "";
	int nxbMoi = 0;
	std::string theLoaiMoi = "";
	bool coCapNhat = false;
	while (!coCapNhat) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);

			if (pos_x >= 900 && pos_x <= 1300 && pos_y >= 220 && pos_y <= 260) {
				InputString(910, 220, 1300, 260, tenSachMoi);
			}

			if (pos_x >= 900 && pos_x <= 1300 && pos_y >= 280 && pos_y <= 320) {
				InputNumBer(910, 280, 1300, 320, soTrangMoistr);
				soTrangMoi = stoi(soTrangMoistr);
			}

			if (pos_x >= 900 && pos_x <= 1300 && pos_y >= 340 && pos_y <= 380) {
				InputString(910, 340, 1300, 380, tacGiaMoi);
			}

			if (pos_x >= 900 && pos_x <= 1300 && pos_y >= 400 && pos_y <= 440) {
				InputNumBer(910, 400, 1300, 440, nxbMoistr);
				nxbMoi = stoi(nxbMoistr);
			}

			if (pos_x >= 900 && pos_x <= 1300 && pos_y >= 460 && pos_y <= 500) {
				InputString(910, 460, 1300, 500, theLoaiMoi);
			}

			bool HieuChinh = pos_x >= 1150 && pos_x <= 1300 && pos_y >= 510 && pos_y <= 540;
			if (HieuChinh) {
				if (!tenSachMoi.empty()) {
					DSDS.data[index]->tensach = tenSachMoi;
				}

				if (soTrangMoi != 0) {
					DSDS.data[index]->sotrang = soTrangMoi;
				}

				if (!tacGiaMoi.empty()) {
					DSDS.data[index]->tacgia = tacGiaMoi;
				}

				if (nxbMoi != 0) {
					DSDS.data[index]->nxb = nxbMoi;
				}

				if (!theLoaiMoi.empty()) {
					DSDS.data[index]->theloai = theLoaiMoi;
				}

				coCapNhat = true;
				clearmouseclick(WM_LBUTTONDOWN);
				quickSort1(DSDS, 0, DSDS.n - 1);
				dialog("CAP NHAT THANH CONG", 15);
				XoaDanhSachCu(DSDS);
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, 0, 10, 1);
			}
		}
	}
}



void InThongTinSach(DS_DauSach& DSDS, int pos_x, int pos_y, int trangHienTai) {
	DauSach ds;
	int soLuongSach = 10;
	int startIndex = (trangHienTai - 1) * soLuongSach;
	int endIndex = startIndex + soLuongSach;

	if (pos_x < 780 && pos_y < 600) {
		int index = startIndex + (pos_y - 150) / 40;

		if (index >= startIndex && index < endIndex) {
			cleardevice();
			setbkcolor(3);
			setcolor(15);
			In_DauSach();
			InDanhSachDauSach(DSDS, startIndex, soLuongSach, 1);
			barWithTxt(920, 160, 1300, 200, 1, (char*)DSDS.data[index]->ISBN.c_str(), 0, 0);
			barWithTxt(920, 220, 1300, 260, 1, (char*)DSDS.data[index]->tensach.c_str(), 0, 0);
			barWithTxt(920, 280, 1300, 320, 1, (char*)std::to_string(DSDS.data[index]->sotrang).c_str(), 0, 0);
			barWithTxt(920, 340, 1300, 380, 1, (char*)DSDS.data[index]->tacgia.c_str(), 0, 0);
			barWithTxt(920, 400, 1300, 440, 1, (char*)std::to_string(DSDS.data[index]->nxb).c_str(), 0, 0);
			barWithTxt(920, 460, 1300, 500, 1, (char*)DSDS.data[index]->theloai.c_str(), 0, 0);

			CapNhatThongTinSach(DSDS, index, trangHienTai, 10);
			ds.soluong = 0;
			ds.soluotmuon = 0;
		}
	}
}



void DisPlay_DSDS(DS_DauSach& DSDS) {
	int trangHienTai = 1;
	int soSachTrenTrang = 10;
	DauSach ds;
	int check;
	string Nhap_Ten;
	string Nhap_Trang;
	string Nhap_TG;
	string Nhap_Nam;
	string Nhap_Loai;
	string Nhap_ISBN;
	Nodedms node = NULL;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			int pos_x, pos_y;
			getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);


			bool Nhap_TenSach = pos_x >= 900 && pos_x <= 1300 && pos_y >= 220 && pos_y <= 260;
			if (Nhap_TenSach) {
				Nhap_Ten = "";
				InputString(910, 220, 1300, 260, Nhap_Ten);
				//ChuanHoaString(Nhap_Ten); 
				int index = Search(DSDS, Nhap_Ten);
				if (Nhap_Ten.empty()) {
					dialog("KHONG DUOC BO TRONG", 4);
				}
				else {
					if (index == -1) {
						dialog("NHAP THANH CONG", 15);
						ds.tensach = Nhap_Ten;
					}
					else {

						dialog("TEN SACH BI TRUNG: NHAP LAI", 4);
					}
				}
				string ISBN = randomString();
				settextstyle(BOLD_FONT, HORIZ_DIR, 2);
				setcolor(0);
				outtextxy(910, 170, (char*)ISBN.c_str());
				ds.ISBN = ISBN;
			}

			bool Nhap_SoTrang = pos_x >= 900 && pos_x <= 1300 && pos_y >= 280 && pos_y <= 320;
			if (Nhap_SoTrang) {
				Nhap_Trang = "";

				InputNumBer(910, 280, 1300, 320, Nhap_Trang);
				if (!Nhap_Trang.empty()) {
					int soTrang = stoi(Nhap_Trang);
					ds.sotrang = soTrang;
				}
				else {
					dialog("KHONG DUOC BO TRONG", 4);
				}
			}

			bool Nhap_TacGia = pos_x >= 900 && pos_x <= 1300 && pos_y >= 340 && pos_y <= 380;
			if (Nhap_TacGia) {
				Nhap_TG = "";

				InputString(910, 340, 1300, 380, Nhap_TG);
				ds.tacgia = Nhap_TG;
				if (Nhap_TG.empty()) {
					dialog("KHONG DUOC BO TRONG", 4);

				}
				else {
					dialog("NHAP THANH CONG", 15);
				}
			}

			bool Nhap_NXB = pos_x >= 900 && pos_x <= 1300 && pos_y >= 400 && pos_y <= 440;
			if (Nhap_NXB) {
				Nhap_Nam = "";
				int Year = 2025;
				InputNumBer(910, 400, 1300, 440, Nhap_Nam);
				if (!Nhap_Nam.empty()) {
					int soNxb = stoi(Nhap_Nam);
					ds.nxb = soNxb;
					if (soNxb < Year) {
						dialog("NAM NHAP VAO HOP LE", 15);
						delay(150);
					}
					else {
						dialog("* NHAP LAI: BE HON NAM HIEN TAI * ", 4);
					}
				}
				else {
					dialog("KHONG DUOC BO TRONG", 4);
				}
			}

			bool Nhap_TheLoai = pos_x >= 900 && pos_x <= 1300 && pos_y >= 460 && pos_y <= 500;
			if (Nhap_TheLoai) {
				Nhap_Loai = "";
				InputString(910, 460, 1300, 500, Nhap_Loai);
				ds.theloai = Nhap_Loai;
				if (Nhap_Loai.empty()) {
					dialog("KHONG DUOC BO TRONG", 4);

				}
				else {
					dialog("NHAP THANH CONG", 15);
				}
			}

			bool Them_click = pos_x >= 900 && pos_x <= 1050 && pos_y >= 510 && pos_y <= 540;
			if (Them_click) {
				settextstyle(BOLD_FONT, HORIZ_DIR, 3);
				setcolor(4);
				outtextxy(930, 560, (char*)"Ban chac chan muon them ?");

				button DrawCo(940, 600, 1040, 650, 15, 8);// l - t - r - b - cl - rad
				char S13[10] = "CO";
				DrawCo.setTitle(S13, 1, 1);
				DrawCo.display();

				button DrawKhong(1160, 600, 1260, 650, 15, 8);// l - t - r - b - cl - rad
				char S14[10] = "KHONG";
				DrawKhong.setTitle(S14, 1, 1);
				DrawKhong.display();
			}

			bool Co_click = pos_x >= 940 && pos_x <= 1040 && pos_y >= 600 && pos_y <= 650;
			if (Co_click) {
				setfillstyle(SOLID_FILL, 3);
				bar(900, 551, 1300, 660);
				ds.soluong = 0;
				ds.soluotmuon = 0;
				InsertDauSach_TenSach(DSDS, ds);
				WriteDSDS(DSDS);
				int trangSauThem = (DSDS.n + 1) / 10 + ((DSDS.n + 1) % 10 != 0);// cong them cuon sach moi them vao
				XoaDanhSachCu(DSDS);
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, (trangSauThem - 1) * 10, 10, trangSauThem);

			}

			bool Khong_click = pos_x >= 1160 && pos_x <= 1260 && pos_y >= 600 && pos_y <= 650;
			if (Khong_click) {
				setfillstyle(SOLID_FILL, 3);
				bar(900, 551, 1300, 660);
				setbkcolor(3);
				setcolor(15);
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, 0, 10, 1);
			}

			bool TrangTruoc = pos_x >= 10 && pos_x <= 150 && pos_y >= 620 && pos_y <= 650 && trangHienTai > 1;
			if (TrangTruoc) {
				trangHienTai--;
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, (trangHienTai - 1) * soSachTrenTrang, soSachTrenTrang, 2);

			}
			bool TrangSau = pos_x >= 640 && pos_x <= 780 && pos_y >= 620 && pos_y <= 650 && trangHienTai < 2;
			if (TrangSau) {
				trangHienTai++;
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, (trangHienTai - 1) * soSachTrenTrang, soSachTrenTrang, 2);
			}

			InThongTinSach(DSDS, pos_x, pos_y, trangHienTai);

			// TIM KIEM SACH  

			bool TimKiem = pos_x >= 500 && pos_x <= 900 && pos_y >= 50 && pos_y <= 80;
			if (TimKiem) {
				Nhap_Ten = "";
				InputString(500, 50, 900, 80, Nhap_Ten);
				ds.tensach = Nhap_Ten;
				if (Nhap_Ten.find_first_not_of(' ') == std::string::npos || Nhap_Ten.empty()) {
					dialog("KHONG DUOC BO TRONG", 4);
				}
				else {
					dialog("NHAP THANH CONG", 15);
				}

				int index = Search(DSDS, ds.tensach);

				if (index == -1) {
					dialog("KHONG TIM THAY SACH", 4);
				}
				else {
					cleardevice();
					setbkcolor(3);
					setcolor(15);
					//In_DauSach_TimKiem();
					In_DauSach();
					InDanhSachDauSach(DSDS, 0, 10, 1);
					settextstyle(BOLD_FONT, HORIZ_DIR, 3);
					setcolor(11);
					barWithTxt(920, 160, 1300, 200, 1, (char*)DSDS.data[index]->ISBN.c_str(), 0, 0);
					barWithTxt(920, 220, 1300, 260, 1, (char*)DSDS.data[index]->tensach.c_str(), 0, 0);
					barWithTxt(920, 280, 1300, 320, 1, (char*)std::to_string(DSDS.data[index]->sotrang).c_str(), 0, 0);
					barWithTxt(920, 340, 1300, 380, 1, (char*)DSDS.data[index]->tacgia.c_str(), 0, 0);
					barWithTxt(920, 400, 1300, 440, 1, (char*)std::to_string(DSDS.data[index]->nxb).c_str(), 0, 0);
					barWithTxt(920, 460, 1300, 500, 1, (char*)DSDS.data[index]->theloai.c_str(), 0, 0);
					Nodedms temp = DSDS.data[index]->First;
					int y_offset = 570;
					while (temp != NULL) {
						settextstyle(BOLD_FONT, HORIZ_DIR, 3);
						setcolor(15);
						outtextxy(810, 560, (char*)"MaSach");
						outtextxy(1050, 560, (char*)"TrangThai");
						settextstyle(BOLD_FONT, HORIZ_DIR, 3);
						setcolor(11);
						barWithTxt(920, y_offset, 1000, y_offset + 10, 1, (char*)temp->sach.masach.c_str(), 0, 0);
						barWithTxt(1200, y_offset, 1400, y_offset + 10, 1, (char*)std::to_string(temp->sach.trangthai).c_str(), 0, 0);
						temp = temp->next;
						y_offset += 20;
					}

				}
			}
			// XOA SACH THEO ISBN
			bool ISBN = pos_x >= 900 && pos_x <= 1300 && pos_y >= 160 && pos_y <= 200;
			if (ISBN) {

				Nhap_ISBN = "";
				InputString(910, 160, 1300, 200, Nhap_ISBN);
				bool found = false;

				for (int i = 0; i < DSDS.n; i++) {
					if (DSDS.data[i]->ISBN == Nhap_ISBN) {
						found = true;
						if (DSDS.data[i]->soluotmuon > 0) {
							dialog("SACH CO DOC GIA MUON KHONG THE XOA", 4);
							delay(200);
							cleardevice();
							setbkcolor(3);
							setcolor(15);
							In_DauSach();
							InDanhSachDauSach(DSDS, 0, 10, 1);
						}
						else {

							DeleteSach_ISBN(DSDS, Nhap_ISBN);
							WriteDSDS(DSDS);
							dialog("XOA THANH CONG", 15);
							cleardevice();
							In_DauSach();
							InDanhSachDauSach(DSDS, 0, 10, 1);

						}
						break;
					}
				}

				if (!found) {
					dialog("ISBN KHONG HOP LE", 15);
				}
				In_DauSach();
				InDanhSachDauSach(DSDS, 0, 10, 1);
			}


			bool Top10 = pos_x >= 1000 && pos_x <= 1200 && pos_y >= 50 && pos_y <= 90;
			if (Top10) {
				DS_DauSach DSDS;
				ReadDSDS(DSDS);
				TopSach topsach(DSDS);
				cleardevice();
				In_DauSach_Top10();
				setcolor(15);
				setbkcolor(3);
				int startY = 160;
				int rowHeight = 40;
				for (int i = 0; i < 10; i++) {
					int indexDS = topsach.list[i].indexDS;
					DauSach* ds = DSDS.data[indexDS];
					int yPos = startY + i * rowHeight;
					barWithTxt(20, yPos - 5, 90, yPos + 35, 1, (char*)ds->ISBN.c_str(), 0, 0);
					barWithTxt(110, yPos - 5, 290, yPos + 35, 1, (char*)ds->tensach.c_str(), 0, 0);
					barWithTxt(310, yPos - 5, 390, yPos + 35, 1, (char*)std::to_string(ds->sotrang).c_str(), 0, 0);
					barWithTxt(410, yPos - 5, 540, yPos + 35, 1, (char*)ds->tacgia.c_str(), 0, 0);
					barWithTxt(560, yPos - 5, 610, yPos + 35, 1, (char*)std::to_string(ds->nxb).c_str(), 0, 0);
					barWithTxt(630, yPos - 5, 770, yPos + 35, 1, (char*)ds->theloai.c_str(), 0, 0);
					barWithTxt(800, yPos - 5, 1000, yPos + 35, 1, (char*)std::to_string(topsach.list[i].slm).c_str(), 0, 0);
				}
			}

			bool Xeptheotheloai = pos_x >= 10 && pos_x <= 150 && pos_y >= 50 && pos_y <= 90;
			if (Xeptheotheloai) {

				cleardevice();
				In_TheoTheLoai();
				sort_Theotheloai(DSDS);
				InDanhSachDauSach(DSDS, 0, 10, 1);
			}

			bool Lui = pos_x >= 10 && pos_x <= 150 && pos_y >= 650 && pos_y <= 700;
			if (Lui) {
				trangHienTai--;
				cleardevice();
				In_TheoTheLoai();
				InDanhSachDauSach(DSDS, (trangHienTai - 1) * soSachTrenTrang, soSachTrenTrang, 2);
			}
			bool Toi = pos_x >= 640 && pos_x <= 780 && pos_y >= 650 && pos_y <= 700;
			if (Toi) {
				trangHienTai++;
				cleardevice();
				In_TheoTheLoai();
				InDanhSachDauSach(DSDS, (trangHienTai - 1) * soSachTrenTrang, soSachTrenTrang, 2);
			}

			bool Thoat = pos_x >= 1100 && pos_x <= 1300 && pos_y >= 650 && pos_y <= 700;
			if (Thoat) {
				cleardevice();
				In_DauSach();
				InDanhSachDauSach(DSDS, 0, 10, 1);
			}

			bool Menu = pos_x >= 10 && pos_x <= 130 && pos_y >= 10 && pos_y <= 40;
			if (Menu) {
				cleardevice();
				//menu();
			}


		}
	}
}
















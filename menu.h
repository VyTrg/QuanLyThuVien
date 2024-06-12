#pragma once
void menu() {
	settextstyle(BOLD_FONT, HORIZ_DIR, 8);
	setcolor(14);
	outtextxy(300, 20, (char*)"QUAN LY THU VIEN");


	button DrawDauSach(470, 140, 900, 200, 10, 1);
	char S44[20] = "DAU SACH";
	DrawDauSach.setTitle(S44, 4, 5);
	DrawDauSach.display();

	button DrawDanhMucSach(470, 250, 900, 310, 10, 1);
	char S55[20] = "DANH MUC SACH";
	DrawDanhMucSach.setTitle(S55, 4, 5);
	DrawDanhMucSach.display();

	button DrawMuonTra(470, 360, 900, 420, 10, 1);
	char S66[20] = "MUON TRA";
	DrawMuonTra.setTitle(S66, 4, 5);
	DrawMuonTra.display();

	button DrawDocGia(470, 470, 900, 530, 10, 1);
	char S77[20] = "DOC GIA";
	DrawDocGia.setTitle(S77, 4, 5);
	DrawDocGia.display();

}

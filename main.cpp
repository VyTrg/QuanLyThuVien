

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
#include "ham.h"
#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"
//#include "ThongTin.h"
//#include "mylib.h"
//#include "menu.h"
#include "muontra.h"
#include "dms.h"

//void Nhap(TREE_DG& DG, DS_DauSach &DSDS) {
//	DocGia dg;
//	dg.MATHE = RandomMT(DG);
//	/*std::cin.ignore();*/
//	std::cout << "Ho:"; getline(std::cin, dg.ho);
//	std::cout << "Ten:"; std::cin >> dg.ten;
//	std::cout << "Phai:"; std::cin >> dg.phai;
//	std::cout << "Trang thai the:"; std::cin >> dg.trangThai;
//	if (dg.trangThai == 0) {
//		dg.muon = DemMT(dg.node);
//	}
//	int check;
//	std::string tensach;
//	std::string masach;
//	MuonTra mt;
//	if (dg.trangThai == 1) {
//		std::cout << "So sach muon (<= 3 cuon/doc gia): "; std::cin >> dg.muon;
//		for (int i = 0; i < dg.muon; ++i) {
//			std::cin.ignore();
//			do {
//				std::cout << "Nhap ten sach muon muon: "; getline(std::cin, tensach);
//				check = Search(DSDS, tensach);
//			} while (check == -1);
//			std::cout << "Cac ma sach co the muon\n";
//			Nodedms hienthi = *DSDS.data[check]->First;
//			while (hienthi != NULL) {
//				if (hienthi->sach.trangthai == 0) {
//					std::cout << hienthi->sach.masach << std::endl;
//				}
//				hienthi = hienthi->next;
//			}
//			Nodedms muon_muon = NULL;
//			do {
//				std::cout << "Nhap ma sach muon muon: "; std::cin >> masach;
//				muon_muon = Tim_MSDMS(*DSDS.data[check]->First, masach);
//			} while (muon_muon == NULL);
//			*DSDS.data[check]->First->sach.trangthai = 1;
//			mt.masach = muon_muon->sach.masach;
//			mt.trangthai = 0;
//			std::cout << "Da muon: " << mt.masach << std::endl;
//			std::cout << "Nhap ngay muon: "; std::cin >> mt.ngaymuon.ngay;
//			std::cout << "Nhap thang muon: "; std::cin >> mt.ngaymuon.thang;
//			std::cout << "Nhap nam muon: "; std::cin >> mt.ngaymuon.nam;
//			std::cin.ignore();
//			mt.ngaytra.ngay = 0;
//			mt.ngaytra.thang = 0;
//			mt.ngaytra.nam = 0;
//			InsertLast_NodeMuonTra(dg.node, mt);
//		}
//	}
//	std::cout << "Da muon thanh cong\n";
//	std::cout << DSDS.data[check]->First->sach.masach << std::endl;
//	std::cout << DSDS.data[check]->First->sach.trangthai << std::endl;
//	std::cout << DSDS.data[check]->First->sach.vitri << std::endl;
//	InsertDGtoTree(DG, dg);
//}

int main()
{
	/*TREE_DG temp;
	KhoiTao(temp);
	Read_info(temp);
	displayMuonTra();*/
	/*DS_DauSach list;
	list.n = 0;
	DauSach ds;
	ReadDSDS(list);*/

	/*TREE_DG DG;
	KhoiTao(DG);
	for (int i = 0; i < 5; ++i) {
		Nhap(DG, list);
	}
	int sl = 5;
	Write_info(DG, 5);*/
	/*TREE_DG temp;
	KhoiTao(temp);
	Read_info(temp);
	DuyetLNR(temp);*/

	//DuyetLNR(DG);
	/*int sl = 1;
	Write_info(DG, 1);
	TREE_DG temp;
	KhoiTao(temp);
	Read_info(temp);
	DuyetLNR(temp);
	*/
	initwindow(w, h);
	DS_DauSach list;
	list.n = 0;
	DauSach ds;
	ReadDSDS(list);
	TREE_DG tree;
	KhoiTao(tree);
	Read_info(tree);
	//displayDms(list);
	displayMuonTra(list, tree);
	return 0;
}



//#pragma once

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


#include "ham.h"
#include "define.h"
#include "graphic.h"
#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"
//#include "ThongTin.h"
//#include "mylib.h"
//#include "menu.h"
#include "muontra.h"
#include "dms.h"

/*-------------------Prototype------------------*/
//xu ly danh muc sach
void danhmucsach();

//nhap danh mach sach
void NhapDms(Nodedms& node);

//xuat danh muc sach
void XuatDms(Nodedms& node);

//xu ly muon tra
void muontra();

//nhap muon tra
void NhapMt(Nodemt& node, MuonTra& mt);

//xuat muon tra
void XuatMt();

//tim cac ma sach
void TimCacMaSach(Nodemt node);

//tinh ngay
//void date();



int main(int argc, char* argv[])
{
	
	initwindow(w, h, "Quan ly thu vien", 0, 0, 0, 1);
	
	//	danhmucsach();	
	//scr_muontra();
	//	Run_ThongTin();
	Nodedms node = NULL;
	DS_DauSach list;
	list.n = 0;
	DauSach ds;
	ReadDSDS(list, node);
	displayDms(list, node);

	/*Nodemt node = NULL;
	TREE_DG DG = NULL;
	Read_info(DG);
	ReadFileMT(node);
	displayMuonTra(node, DG);*/

	/*DS_DauSach list;
	list.n = 0;
	DauSach ds;
	ReadDSDS(list);
	LietKe(list);*/
	/*int n = 0, luachon;
	DS_DauSach list;
	Nodedms node = NULL;
	DauSach dausach;
	list.n = 0;
	string ten;
	do
	{
		InMenu();
		cin >> luachon;
		switch (luachon) {
		case 0:
			break;
		case 1:
		{
			NhapList(list, 1);
			break;
		}

		case 2:
		{
			sort_Theotheloai(list);
			LietKe(list);
			break;
		}


		case 3: {
			WriteDSDS(list);
			break;
		}

		case 4: {
			ReadDSDS(list);
			LietKe(list);
			break;
		}
		case 5: {
			cout << "Nhap thong tin cho dau sach moi:" << endl;

			if (NhapSach(list, dausach) == 1)
				InsertDauSach(list, dausach);
			sort_Theotheloai(list);
			LietKe(list);
			break;
		}

		case 6: {
			cout << "Tim kiem sach."; cin.ignore();
			getline(cin, ten);
			cout << "Thog tin tra cuu duoc: \n";
			ShowSach(list, ten);
			break;
		}
		case 7: {
			SuaThongTinSach(list);
			break;
		}

		case 8: {
			LietKe(list);
			cout << "Nhap ISBN cua sach muon xoa: ";
			string ISBN;
			cin.ignore();
			getline(cin, ISBN);
			DeleteSach_ISBN(list, ISBN);
			LietKe(list);
			break;
		}

		case 9: {
			
			cout << "Thoat chuong trinh.\n";
			return 0;
		}
		default: {
			cout << "Lua chon khong hop le. Vui long chon lai.\n";
			break;
		}
		}

	} while (true);
	system("PAUSE");
	return 0;*/


	return 0;
}

/*-------------------Function------------------*/
void NhapDms(Nodedms& node) {
	Sach sach;
	std::string str;
	int n;

	std::cin.ignore();
	std::cout << "Nhap dau sach ";
	std::getline(std::cin, str);
	//str = MaSach(str);
	sach.masach = str;

	std::cout << "Nhap trang thai ";
	std::cin >> n;
	sach.trangthai = n;

	std::cin.ignore();
	std::cout << "Nhap vi tri ";
	std::getline(std::cin, str);

	sach.vitri = str;

	//	if(node == NULL)
	//		InsertFirst_NodeDMSach(node, sach);
	//	else
	InsertLast_NodeDMSach(node, sach);
	//	std::cout << node->sach.masach << " " << node->sach.trangthai;

}

void XuatDms(Nodedms& node) {
	ReadFileDMS(node);
	std::cout << "Da ghi du lieu tu file\n";
	int cnt = 0;
	Nodedms temp = node;
	while (temp != NULL) {
		std::cout << "=======" << cnt + 1 << "======\n";
		std::cout << "Ma sach:" << temp->sach.masach << std::endl;
		std::cout << "Trang thai:" << temp->sach.trangthai << std::endl;
		std::cout << "Vi tri:" << temp->sach.vitri << std::endl;
		temp = temp->next;
		++cnt;
	}
}

void danhmucsach() {
	Nodedms node = NULL;
	Sach s;
	int chon;
	int sl = 0;
	while (1) {
		//		system("cls");
		std::cout << "============Menu=============\n";
		std::cout << "1. Nhap dms\n";
		std::cout << "2. Xuat dms tu trong file\n";
		std::cout << "3. Luu dms vao file\n";
		
		std::cout << "0. Thoat\n";
		std::cout << "Lua chon: "; std::cin >> chon;
		if (chon == 1) {
			NhapDms(node);
		}
		else if (chon == 2) {
			XuatDms(node);
			//			system("pause");
		}
		else if (chon == 3) {
			WriteFileDMS(node);
			//			Sleep(600);
		}
		
		else if (chon == 0)
			break;

	}
}

void muontra() {
	Nodemt node = NULL;
	MuonTra mt;
	int chon;

	while (1) {
		//		system("cls");
		std::cout << "============Menu=============\n";
		std::cout << "1. Nhap mt\n";
		std::cout << "2. Xuat mt tu trong file\n";
		std::cout << "3. Luu mt vao file\n";
		std::cout << "4. Tim cac ma sach\n";
		std::cout << "0. Thoat\n";
		std::cout << "Lua chon: "; std::cin >> chon;
		//		std::cin.ignore();
		if (chon == 1) {
			NhapMt(node, mt);
		}
		else if (chon == 2) {
			XuatMt();
			//			Sleep(300);
		}
		else if (chon == 3) {
			WriteFileMT(node);
			//			Sleep(600);
		}
		else if (chon == 4) {
			TimCacMaSach(node);
		}
		else if (chon == 0)
			break;

	}
}

void NhapMt(Nodemt& node, MuonTra& mt) {

	std::string str;
	int n;

	std::cin.ignore();
	std::cout << "Nhap dau sach ";
	std::getline(std::cin, str);
	//str = MaSach(str);
	mt.masach = str;

	std::cout << "Nhap ngay muon ";
	std::cin >> n;
	mt.ngaymuon.ngay = n;
	std::cin >> n;
	mt.ngaymuon.thang = n;
	std::cin >> n;
	mt.ngaymuon.nam = n;

	std::cout << "Nhap ngay tra ";
	std::cin >> n;
	mt.ngaytra.ngay = n;
	std::cin >> n;
	mt.ngaytra.thang = n;
	std::cin >> n;
	mt.ngaytra.nam = n;

	std::cout << "Trang thai ";
	std::cin >> n;
	mt.trangthai = n;

	InsertLast_NodeMuonTra(node, mt);
}

void XuatMt() {
	Nodemt node = NULL;
	ReadFileMT(node);
	int cnt = 0;
	Nodemt temp = node;
	while (temp != NULL) {
		std::cout << "=======" << cnt + 1 << "======\n";
		std::cout << "Ma sach:" << temp->muontra.masach << std::endl;
		std::cout << "Ngay muon:" << temp->muontra.ngaymuon.ngay << "/" << temp->muontra.ngaymuon.thang << "/" << temp->muontra.ngaymuon.nam << std::endl;
		std::cout << "Ngay tra:" << temp->muontra.ngaytra.ngay << "/" << temp->muontra.ngaytra.thang << "/" << temp->muontra.ngaytra.nam << std::endl;
		std::cout << "Trang thai:" << temp->muontra.trangthai << std::endl;
		temp = temp->next;
		++cnt;
	}
}

void TimCacMaSach(Nodemt node) {
	ReadFileMT(node);
	//Nodemt temp = node;
	//int cnt = 0;
	std::string tensach;
	std::cin.ignore();  
	std::cout << "Nhap ten sach can tim: ";   getline(std::cin, tensach);
	Nodemt tmp = Tim_Mt(node, tensach);
	int cnt = 0;
	if (tmp != NULL)
		while (tmp != NULL) {
			std::cout << "=======" << cnt + 1 << "======\n";
			std::cout << "Ma sach:" << tmp->muontra.masach << std::endl;
			std::cout << "Ngay muon:" << tmp->muontra.ngaymuon.ngay << "/" << tmp->muontra.ngaymuon.thang << "/" << tmp->muontra.ngaymuon.nam << std::endl;
			std::cout << "Ngay tra:" << tmp->muontra.ngaytra.ngay << "/" << tmp->muontra.ngaytra.thang << "/" << tmp->muontra.ngaytra.nam << std::endl;
			std::cout << "Trang thai:" << tmp->muontra.trangthai << std::endl;
			tmp = tmp->next;
			++cnt;
		}
	else {
		
		std::cout << "Khong tim thay/ sach khong ton tai\n";
	}
}
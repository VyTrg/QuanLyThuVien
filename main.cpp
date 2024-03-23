#include <iostream>
#include <string>
#include <winbgim.h>
#include <windows.h>

#include "mylib.h"
#include <stdio.h>

#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"

using namespace std;

void menu(TREE_DG &t) {
	while (true) {
		system("cls");
		cout << "--------------NEMU--------------\n";
		cout << "1. Nhap du lieu DG\n";
		cout << "2. Xuat du lieu DG theo Ma The\n";
		cout << "3. Hieu chinh thong tin DG\n";
		cout << "4. Xoa DG\n";
		cout << "5. Xuat du lieu DG theo ten\n";
		cout << "6. Lay du lieu tu file\n";
		cout << "7. Cap nhap cay AVL\n";
//		cout << "8. 	";
//		cout << "9. 	";
		cout << "10. Luu du lieu\n";
		cout << "0. EXIT\n";
		cout << "--------------------------------\n";
		int option;
		
		cout << "Nhap lua chon: ";
		cin >> option;
		if (option < 0 || option > 10) {
			cout << "Lua chon khong hop le!";
			Sleep(600);
		}
		else if (option == 1) { //Nhap doc gia
			
			int tmp;
			string str;
			
			DocGia dg;
			
			
			dg.MATHE = RandomMT(t);
			
			
//			cin.ignore(265, '\n');
//			cout << "Nhap ho: ";
//			getline(cin, str);
//			dg.ho = str;
//			
//			cout << "Nhap ten: ";
//			getline(cin, str);
//			dg.ten = str;
//			
//			cout << "Nhap phai: ";
//			getline(cin, str);
//			dg.phai = str;
//			
//			dg.trangThai = 1;
//			
//			InsertDGtoTree(t,dg);
//			
//			cout << endl;
			system("pause");
		}
		else if (option == 2) { //Xuat doc gia
			
			if (t == NULL) {
				cout << "Khong co thong tin doc gia!";
			}
			else {
				system("cls");
				cout << "In danh sach doc gia theo ma the\n";
				Duyet_LNR(t);
			}

			cout << endl;
			system("pause");
		}
		else if (option == 3) { //Hieu chinh doc gia
			string str;
			cout << "Nhap ma tha can hieu chinh: ";
			cin.ignore(265, '\n');
			getline(cin, str);
			TREE_DG temp = Find_DG(t, str);
			if(temp == NULL) {
				cout << "Khong tim thay doc gia!";
				Sleep(600);
			}
			else {
				
				cout << "Nhap ho: ";
				getline(cin, str);
				temp->docgia.ho = str;
			
				cout << "Nhap ten: ";
				getline(cin, str);
				temp->docgia.ten = str;
			
				cout << "Nhap phai: ";
				getline(cin, str);
				temp->docgia.phai = str;
				
				cout << "Da cap nhap doc gia!";
				Sleep(600);
			}
		}
		else if (option == 4) { //Xoa doc gia
			string str;
			cout << "Nhap MA THE can xoa: ";
			cin.ignore(265, '\n');
			getline(cin, str);
			if (IsDeleted_DG(t, str) == 1) {
				cout << "Da xoa doc gia";
				Sleep(600);
			}
			else {
				cout << "Khong tim thay doc gia!";
				Sleep(600);
			} 
		}
		else if (option == 5) {
			int sl;
			string arr[MAX];
			
			DuyetTen(t, arr, sl);

			BubbleSort(arr, sl);
			
			system("cls");
			cout << "In danh sach doc gia theo ten\n";

			for (int i = 0; i < sl; i++) {
				Find_TenDG(t, arr[i]);
			}
			
			system("pause");
		}
		else if (option == 6) {
			Read_info(t);
			cout << "Da lay du lieu tu file!";
			Sleep(600);
		}
		else if (option == 7) {
			cap_nhap_AVL(t);
		}
//		else if (option == 8) {
//			
//		}
//		else if (option == 9) {
//			
//		}
		else if (option == 10) {
//			int k = countDG(t);
			Write_info(t, nDG);
			
		}
		else if (option == 0) {
			FreeMemory(t);
			break;
		}
	}
}

int main()
{
	
// now, you can run project
//	initwindow(300, 300);			// init window graphics
//	setbkcolor(1);					// set background
//   	cleardevice();
//	setcolor(14);					// set text color
//	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
//	
//	while(!kbhit()) delay(1);		// pause screen	
//	return 0;
	TREE_DG DG;
	KhoiTao(DG);
	menu(DG);
	return 0;
}

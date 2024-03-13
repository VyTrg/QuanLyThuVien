#include <iostream>
#include <string.h>
#include <winbgim.h>

#include "mylib.h"

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
		cout << "2. Xuat du lieu DG\n";
		cout << "3. Them DG\n";
		cout << "4. Xoa DG\n";
		cout << "5. Hieu chinh thong tin DG\n";
//		cout << "6. 	";
//		cout << "7. 	";
//		cout << "8. 	";
//		cout << "9. 	";
//		cout << "10. 	";
		cout << "0. EXIT\n";
		cout << "--------------------------------\n";
		int option;
		cout << "Nhap lua chon: ";
		cin >> option;
		if (option < 0 || option > 10) {
			cout << "Lua chon khong hop le";
			system("pause");
		}
		else if (option == 1) { //Nhap doc gia
			
			cout << "Nhap thong tin du lieu doc gia\n";
			
			RandomMT(t);
			
			int tmp;
			string str;
			
			cin.ignore(265, '\n');
			cout << "Nhap ho: ";
			getline(cin, str);
			t->docgia.ho = str;
			
			cin.ignore(265, '\n');
			cout << "Nhap ten: ";
			getline(cin, str);
			t->docgia.ten = str;
			
			cin.ignore(265, '\n');
			cout << "Gioi tinh: ";
			getline(cin, str);
			t->docgia.phai = str;
			
			nDG++;
		}
//		else if (option == 2) { //Xuat doc gia
//			system("cls");
//			Duyet_LNR(t);
//		}
//		else if (option == 3) { //Them doc gia
//			cout << "Nhap thong tin doc gia can them\n";
//			
//			int tmp;
//			string str;
//			
//			RandomMT(t);
//			
//			cin.ignore(265, '\n');
//			cout << "Nhap ho: \n";
//			getline(cin, str);
//			t->docgia.ho = str;
//			
//			cout << "Nhap ten: ";
//			getline(cin, str);
//			t->docgia.ten = str;
//			
//			cout << "Gioi tinh: ";
//			getline(cin, str);
//			t->docgia.phai = str;
//			
//			nDG++;
//		}
//		else if (option == 4) { //Xoa doc gia
//			string str;
//			cout << "Nhap MA THE can xoa: ";
//			getline(cin, str);
//			if (IsDeleted_DG(t, str) == 1) cout << "Da xoa doc gia";
//			else cout << "Khong tim thay doc gia!"; 
//		}
//		else if (option == 5) {
//			cout << "Phan tu co 2 nhanh ";
//			NodeCo2Nhanh(t);
//			cout << endl;
//			system("pause");
//		}
//		else if (option == 6) {
//			
//		}
//		else if (option == 7) {
//			
//		}
//		else if (option == 8) {
//			
//		}
//		else if (option == 9) {
//			
//		}
//		else if (option == 10) {
//			
//		}
		else break;
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

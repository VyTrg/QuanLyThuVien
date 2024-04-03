//#pragma once

#include <iostream>
#include <string>
//#include <winbgim.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <conio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
//#include <graphics.h>
#include<sstream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include "graphic.h"
#include "cautrucdanhmucsach.h"
#include "cautrucdausach.h"
//#include "cautrucmuontra.h"
//#include "cautructhedocgia.h"
//#include "ThongTin.h"
//#include "mylib.h"
//#include "menu.h"
//#include "define.h"


/*-------------------Prototype------------------*/


int main(int argc, char* argv[])
{	//w-h
	//initwindow(1900,1000, "Quan ly thu vien", 0, 0, 0, 1);
	//initwindow(600, 600, "Quan ly thu vien");
	//button DrawMenu(10, 10, 250, 50, 14, 8);// l - t - r - b - cl - rad
	//char S1[10] = "< MENU";
	//DrawMenu.setTitle(S1, 1, 3);
	//DrawMenu.display();
	//

	//button DrawNhap(100, 100, 200, 10, 14, 8);
	//char S2[20] = "Nhap ten sach";
	//DrawNhap.setTitle(S2, 1, 3);
	//DrawNhap.display();

	//button Clear();
	//char S3[10] = "CLEAR";
	//Clear.setTitle(S3, 1, 3);
	//Clear.display();





	

	int n = 0, luachon;
	DS_DauSach list;
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
			  			  // Thực hiện nhập thông tin cho đầu sách mới
			  			  cout << "Nhap thong tin cho dau sach moi:" << endl;

			  			  // code để nhập thông tin cho đối tượng newDauSach


			  			  // Thêm đầu sách mới vào danh sách
			  			 // AddDauSach(list, dausach);
						  if (NhapSach(list, dausach) == 1)
						  InsertDauSach(list, dausach);
						  sort_Theotheloai(list);
			  			  LietKe(list);
			  			  break;
			  		  }

		case 6: {
			cout << "Tim kiem sach."; cin.ignore();
			getline(cin,ten);
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
			// Thêm trường hợp 9 để thoát khỏi vòng lặp
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
	return 0;


}

/*-------------------Function------------------*/


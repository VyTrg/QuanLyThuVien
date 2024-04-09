//#pragma once
//#ifndef CAUTRUCDAUSACH_H_INCLUDED
//#define CAUTRUCDAUSACH_H_INCLUDED

#pragma once

//#include "cautrucdanhmucsach.h"
//#include "cautrucmuontra.h"
//#include "cautructhedocgia.h"

#include<string>
#define Max_DS_DauSach 100

using namespace std;
//using std::to_string;

struct DauSach;
struct DS_DauSach;
struct NodeDMSach;
typedef struct NodeDMSach* Nodedms;


struct DauSach
{
	string ISBN;
	string tensach;
	int sotrang;
	string tacgia;
	int nxb;
	string theloai;
	//DauSach() : sotrang(0), nxb(0) {} 

	Nodedms First = NULL;//con tro danh muc sach

	int soluotmuon = 0; 	// so luot muon sach
	int soluong = 0;	// so luong sach cua dau sach

};
typedef struct DauSach dausach;



struct DS_DauSach
{
	int n = 0;
	DauSach* data[Max_DS_DauSach];
};
typedef struct DS_DauSach ds_dausach;


string randomString();
// sinh ngau  nhien ISBN
//int StringToInt(string s);
// string to int
void InMenu();
// ham in menu
//int NhapSach(DS_DauSach& DSDS, DauSach& dausach);
// ham nhap sach
void NhapList(DS_DauSach& DSDS, int flag);
// ham nhap danh sach
void LietKe(DS_DauSach& DSDS);
// ham xuat danh sach
void WriteDSDS(DS_DauSach& DSDS);
// ham ghi file
void InsertLastDauSach(DS_DauSach& DSDS, DauSach dausach);
//them vao cuoi su dung cho doc file
int InsertDauSach(DS_DauSach& DSDS, DauSach& dausach);
void ReadDSDS(DS_DauSach& DSDS, Nodedms& node);
// ham doc file
int Search(DS_DauSach& DSDS, string x);
// ham tim kiem ten sach 
void ShowSach(DS_DauSach& DSDS, string ten);
// in ra thong tin cua sach vua tim kiem 
void bubbleSort(DauSach* arr[], int size);
// sap xep theo ten sach
void swap(DauSach*& a, DauSach*& b);
// doi cho 2 dau sach
int partition(DS_DauSach& DSDS, int low, int high);

void quickSort(DS_DauSach& DSDS, int low, int high);
// sap xep theo the loai
void Delete_Item(DS_DauSach& DSDS, int i);
void DeleteSach_ISBN(DS_DauSach& DSDS, string ISBN);

int Empty(DS_DauSach& DSDS) {
	return DSDS.n == 0;
}

// Sinh so tu dong 

string randomString()
{
	string str = "AAAAAA";

	
	srand(time(0));

	
	str[0] = rand() % 26 + 65; 
	str[1] = rand() % 26 + 65;
	str[2] = rand() % 26 + 65;

	
	str[3] = rand() % 10 + 48; 
	str[4] = rand() % 10 + 48;
	str[5] = rand() % 10 + 48;

	return str;
}


// ham in menu
void InMenu() {
	cout << "=================== MENU ======================\n";
	cout << "1. NHap danh sach tu ban phim\n";
	cout << "2. Hien thi thong tin sach(Da duoc sap xep)\n";
	cout << "3. Luu file\n";
	cout << "4. Doc file\n";
	cout << "5. Sua thong tin sach\n";
	cout << "6. In thong tin theo ten sach \n";
	cout << "7. Hieu chinh thong tin sach\n";
	cout << "8. Xoa sach theo ISBN\n";
	cout << "0. Thoat khoi lua chon cua ban : ";
}

// Nhap sach
int NhapSach(DS_DauSach& DSDS, DauSach& dausach) {
	string s;
	int tmp;
	while (1) {
		dausach.ISBN = randomString();
		cout << "ISBN " << dausach.ISBN << endl;
		//
		cin.ignore();
		cout << "TenSach: "; getline(cin, s); dausach.tensach = s;

		cout << "SoTrang "; cin >> tmp; dausach.sotrang = tmp;
		cin.ignore();
		cout << "TacGia "; getline(cin, s); dausach.tacgia = s;

		cout << "NamXuatBan: "; cin >> tmp; dausach.nxb = tmp;
		cin.ignore();
		cout << "TheLoai: ";  getline(cin, s); dausach.theloai = s;

		cout << "Nhap so luong sach "; cin >> tmp; dausach.soluong = tmp;
		break;
	}
	return 1;
}
// nhap danh sach
void NhapList(DS_DauSach& DSDS, int flag) {
	DauSach dausach;
	if (flag == 0)// nhap moi tu dau
		while (DSDS.n > 0) {
			delete DSDS.data[DSDS.n - 1];
			DSDS.n--;
		}
	if (NhapSach(DSDS, dausach) == 0) return;
	DSDS.data[DSDS.n] = new DauSach();
	*DSDS.data[DSDS.n] = dausach;
	dausach.First = DSDS.data[DSDS.n]->First;
	Sach s;
	for (int i = 0; i < dausach.soluong; ++i) {
		s.masach = MaSach(dausach.tensach);
		s.trangthai = 0;
		srand(time(NULL));
		int ngan = rand() % (20 - 1 + 1) + 1;
		int ke = rand() % (20 - 1 + 1) + 1;
		std::string vitri = "NGAN " + std::to_string(ngan) + " KE " + std::to_string(ke);
		s.vitri = vitri;
		
		InsertLast_NodeDMSach(DSDS.data[DSDS.n]->First, s);
	}
	DSDS.n++;
	if (DSDS.n == Max_DS_DauSach) cout << "Danh Sach Day";
}

void LietKe(DS_DauSach& DSDS) {
	system("cls");
	cout << "               DANH SACH DAU SACH\n";
	for (int i = 0; i < DSDS.n; i++) {
		cout << "ISBN: " << DSDS.data[i]->ISBN << endl;
		cout << "TenSach :" << DSDS.data[i]->tensach << endl;
		cout << "SoTrang :" << DSDS.data[i]->sotrang << endl;
		cout << "Tacgia :" << DSDS.data[i]->tacgia << endl;
		cout << "NamXuatBan :" << DSDS.data[i]->nxb << endl;
		cout << "Theloai: " << DSDS.data[i]->theloai << endl;
		cout << "So luong sach: " << DSDS.data[i]->soluong << endl;
		cout << "So luong muon: " << DSDS.data[i]->soluotmuon << endl;
		Nodedms temp = DSDS.data[i]->First;
		while (temp != NULL) {
			std::cout << temp->sach.masach << std::endl;
			temp = temp->next;
		}
	}
	cout << endl;
	_getch(); 
}

// xoa sach theo ISBN
void Delete_Item(DS_DauSach& DSDS, int i) {
	delete DSDS.data[i];
	for (int j = i + 1; j < DSDS.n; j++) {
		DSDS.data[i - 1] = DSDS.data[i];
	}
	DSDS.n--;
}


void DeleteSach_ISBN(DS_DauSach& DSDS, string ISBN) {
	bool deleted = false; 
	for (int i = 0; i < DSDS.n; i++) {
		if (DSDS.data[i]->ISBN == ISBN) {
			Delete_Item(DSDS, i);
			deleted = true;
			break; 
		}
	}
	if (!deleted) {
		cout << "Khong tim thay cuon sach voi ISBN nay trong danh sach." << endl;
	}
	else {
		cout << "Da xoa thanh cong." << endl;
	}
	
	cout << "Nhan mot phim bat ky de thoat..." << endl;
	cin.get();
}



//int ExistsDauSach(DS_DauSach &DSDS, char* ISBN){
//	for(int i=0; i<DSDS.n; i++){
//		if(strcmp(DSDS.data[i]->ISBN, ISBN) == 0){ 
//			return i;
//		}
//	}
//	return -1;
//}


// xoa sach
//void Delete_DauSach(DS_DauSach& DSDS, int position) {
//	if (position > DSDS.n || Empty(DSDS) || DSDS.n == 0) {
//		return;
//	}
//	// xoa vi tri cuoi mang 
//	if (position == DSDS.n) {
//		delete DSDS.data[DSDS.n];
//		//tranh tinh trang con tro bi treo
//		DSDS.data[DSDS.n--] = NULL;
//		return;
//	}
//	// cho quan trong
//	delete DSDS.data[position];
//
//	for (int tmp = position; tmp < DSDS.n; tmp++) {
//		DSDS.data[tmp - 1] = DSDS.data[tmp];
//
//		delete DSDS.data[DSDS.n--];
//		// tranh tinh trang con tro bi treo
//		DSDS.data[DSDS.n] = NULL;
//		return;
//	}
//}
//// xoa theo ten sach 
//void Delete_TenSach(DS_DauSach& DSDS, string ts) {
//	for (int i = 0; i < DSDS.n; i++) {
//		if (ts.compare(DSDS.data[i]->tensach) == 0) {
//			Delete_DauSach(DSDS, i);
//		}
//	}
//}

//ghi file 
void WriteDSDS(DS_DauSach& DSDS) {
	ofstream fileDS;
	ofstream fileDMS;
	fileDS.open("DSDS.txt", ios::app);//neu file da ton tai noi dung cua no se duoc cat truoc khi mo file 
	fileDMS.open("dms.txt", ios::app);
	fileDS << DSDS.n << endl;
	for (int i = 0; i < DSDS.n; i++) {
		fileDS << DSDS.data[i]->ISBN << ",";
		fileDS << DSDS.data[i]->tensach << ",";
		fileDS << DSDS.data[i]->sotrang << ",";
		fileDS << DSDS.data[i]->tacgia << ",";
		fileDS << DSDS.data[i]->nxb << ",";
		fileDS << DSDS.data[i]->theloai << ",";
		fileDS << DSDS.data[i]->soluong << ",";
		fileDS << DSDS.data[i]->soluotmuon;
		fileDS << endl;
		while (DSDS.data[i]->First != NULL) {
			fileDMS << DSDS.data[i]->First->sach.masach << ",";
			fileDMS << DSDS.data[i]->First->sach.trangthai << ",";
			fileDMS << DSDS.data[i]->First->sach.vitri;
			DSDS.data[i]->First = DSDS.data[i]->First->next;
			fileDMS << endl;
		}
		//fileout << endl;
	}
	fileDS.close();
	fileDMS.close();
}
// insertlast 
void InsertLastDauSach(DS_DauSach& DSDS, DauSach dausach) {
	// su dung khi doc file 
	if (DSDS.n > Max_DS_DauSach)
		printf("DSDS day \n");
	else {
		*DSDS.data[DSDS.n++] = dausach;
	}
}

//doc file 
void ReadDSDS(DS_DauSach& DSDS, Nodedms& node) {

	while (DSDS.n > 0) {
		delete DSDS.data[DSDS.n - 1];
		DSDS.n--;
	}
	int n;
	string str;
	ifstream fileDS;
	ifstream fileDMS;
	fileDS.open("DSDS.txt", ios::in);
	fileDMS.open("dms.txt", ios::in);
	fileDS >> DSDS.n;
	for (int i = 0; i < DSDS.n; i++) {
		fileDS.ignore();
		DSDS.data[i] = new DauSach;
		DauSach ds;
		getline(fileDS, str, ','); ds.ISBN = str; // xac dinh vi tri n byte ve sau cua doi tuong byte
		getline(fileDS, str, ','); ds.tensach = str;
		getline(fileDS, str, ','); n = StringToInt(str); ds.sotrang = n;
		getline(fileDS, str, ','); ds.tacgia = str;
		getline(fileDS, str, ','); n = StringToInt(str); ds.nxb = n;
		getline(fileDS, str, ','); ds.theloai = str;
		getline(fileDS, str, ','); n = StringToInt(str); ds.soluong = n;
		for (int i = 0; i < ds.soluong; ++i) {
			Sach s;
			getline(fileDMS, str, ','); s.masach = str;
			getline(fileDMS, str, ','); n = StringToInt(str); s.trangthai = n;
			getline(fileDMS, str); s.vitri = str;
			InsertLast_NodeDMSach(node, s);
			InsertLast_NodeDMSach(ds.First, s);
		}
		getline(fileDS, str); n = StringToInt(str); ds.soluotmuon = n;
		//InsertLastDauSach( DSDS,ds);
		*DSDS.data[i] = ds; // noi dung ma con tro dang tro toi truyen vao danh sach 
	}
	//cout << endl;
	fileDS.close();
	fileDMS.close();
}



int Search(DS_DauSach& DSDS, string x)
{
	for (int i = 0; i < DSDS.n; i++)
		if (DSDS.data[i]->tensach == x) return i;
	return -1;
}

void ShowSach(DS_DauSach& DSDS, string ten) {
	int i = Search(DSDS, ten);
	if (i == -1) cout << "Khong co sach trong danh sach.";
	else {
		cout << "ISBN: " << DSDS.data[i]->ISBN << endl;
		cout << "TenSach :" << DSDS.data[i]->tensach << endl;
		cout << "TheLoai :" << DSDS.data[i]->theloai << endl;
		cout << "SoTrang :" << DSDS.data[i]->sotrang << endl;
		cout << "NamXuatBan :" << DSDS.data[i]->nxb;

	}
}



void bubbleSort(DauSach* arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			
			if (arr[j]->tensach > arr[j + 1]->tensach) {
				DauSach* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}



void swap(DauSach*& a, DauSach*& b) {
	DauSach* temp = a;
	a = b;
	b = temp;
}



int partition(DS_DauSach& DSDS, int low, int high) {
	int mid = (low + high) / 2; 
	string pivot = DSDS.data[mid]->theloai;
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (DSDS.data[j]->theloai < pivot || (DSDS.data[j]->theloai == pivot && DSDS.data[j]->tensach < DSDS.data[mid]->tensach)) {
			i++;
			swap(DSDS.data[i], DSDS.data[j]);
		}
	}
	swap(DSDS.data[i + 1], DSDS.data[mid]);
	return (i + 1);
}


void quickSort(DS_DauSach& DSDS, int low, int high) {
	if (low < high) {
		
		int pi = partition(DSDS, low, high);

		
		quickSort(DSDS, low, pi - 1);
		
		quickSort(DSDS, pi + 1, high);
	}
}


void sort_Theotheloai(DS_DauSach& DSDS) {
	
	quickSort(DSDS, 0, DSDS.n - 1);

	
	string str = "";
	int start = 0;

	
	for (int i = 0; i < DSDS.n; i++) {
		
		if (DSDS.data[i]->theloai != str) {
			
			if (i - start >= 2) {
				
				bubbleSort(DSDS.data + start, i - start);
			}
			
			start = i;
			str = DSDS.data[i]->theloai;
		}
	}

	
	if (DSDS.n - start >= 2) {
		bubbleSort(DSDS.data + start, DSDS.n - start);
	}

	
	LietKe(DSDS);
}

// them sach nhièu hơn 1 sach
int InsertDauSach(DS_DauSach& DSDS, DauSach& dausach) {
	int i, k;
	if (DSDS.n == Max_DS_DauSach) return 0;
	for (i = 0; i < DSDS.n && DSDS.data[i]->tensach < dausach.tensach; i++);
	for (k = DSDS.n - 1; k >= i; k--)
		DSDS.data[k + 1] = DSDS.data[k];
	DSDS.data[i] = new DauSach;
	*DSDS.data[i] = dausach; DSDS.n++;
	LietKe(DSDS);
	return 1;

}


void SuaThongTinSach(DS_DauSach& DSDS) {
	string s;
	int tmp;
	
	LietKe(DSDS);

	int index;
	cout << "Nhap vao so index muon sua: ";
	cin >> index;

	
	if (index < 0 || index >= DSDS.n) {
		cout << "Vi tri index ko dung.";
		return;
	}

	
	cout << "Thong tin sach truoc khi sua: " << endl;
	cout << "1. ISBN:(ko dc sua) " << DSDS.data[index]->ISBN << endl;
	cout << "2. TenSach: " << DSDS.data[index]->tensach << endl;
	cout << "3. SoTrang: " << DSDS.data[index]->sotrang << endl;
	cout << "4. TacGia: " << DSDS.data[index]->tacgia << endl;
	cout << "5. NamXuatBan: " << DSDS.data[index]->nxb << endl;
	cout << "6. TheLoai: " << DSDS.data[index]->theloai << endl;

	DauSach dausach;

	
	dausach.ISBN = DSDS.data[index]->ISBN;
	
	int choice;
	cout << "Chon thong tin muon sua (1-6): ";
	cin >> choice;

	
	cin.ignore();

	// nhap thong tin sach moi
	cout << "Nhap thong tin moi cho sach: " << endl;
	// cap nhat thong tin sach dua tren lua chon nguoi dung

	switch (choice) {
		//case 1:
			//DSDS.data[index]->ISBN = dausach.ISBN;
			//break;
	case 2:
		cout << "TenSach: "; getline(cin, s); dausach.tensach = s;
		DSDS.data[index]->tensach = dausach.tensach;

		break;
	case 3:
		cout << "SoTrang "; cin >> tmp; dausach.sotrang = tmp;
		cin.ignore();
		DSDS.data[index]->sotrang = dausach.sotrang;
		break;
	case 4:
		cout << "TacGia "; getline(cin, s); dausach.tacgia = s;
		DSDS.data[index]->tacgia = dausach.tacgia;
		break;
	case 5:
		cout << "NamXuatBan: "; cin >> tmp; dausach.nxb = tmp;
		cin.ignore();
		DSDS.data[index]->nxb = dausach.nxb;
		break;
	case 6:
		cout << "TheLoai: ";  getline(cin, s); dausach.theloai = s;
		DSDS.data[index]->theloai = dausach.theloai;
		break;
	default:
		cout << "Lua chon khong hop le." << endl;
		break;
	}
	cout << "Da sua thong tin thanh cong";
}








//s#endif 
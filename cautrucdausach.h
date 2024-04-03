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
	DauSach() : sotrang(0), nxb(0) {} // Khởi tạo sotrang và nxb thành 0 khi tạo mới một đối tượng DauSach

	//Nodedms* First = NULL;

	int soluotmuon; 	// so luot muon sach
	int soluong;	// so luong sach cua dau sach

};
typedef struct DauSach dausach;



struct DS_DauSach
{
	int n = 0;
	DauSach *data[Max_DS_DauSach];
};
typedef struct DS_DauSach ds_dausach;

string randomString();	
// sinh ngau  nhien ISBN
int StringToInt(string s);  
// string to int
void InMenu();				
// ham in menu
int NhapSach(DS_DauSach& DSDS, DauSach& dausach); 
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
void ReadDSDS(DS_DauSach& DSDS);									
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
// Hàm chia mảng thành hai phần sao cho các phần tử nhỏ hơn phần tử chốt được đặt bên trái,các phần tử lớn hơn được đặt bên phải
void quickSort(DS_DauSach& DSDS, int low, int high);				
// sap xep theo the loai
void Delete_Item(DS_DauSach& DSDS, int i);
void DeleteSach_ISBN(DS_DauSach& DSDS, string ISBN);

int Empty(DS_DauSach& DSDS) {
	return DSDS.n == 0;
}

int StringToInt(string s)
{
	int i;
	// string -> integer
	istringstream(s) >> i;

	return i;

}

// Sinh so tu dong 

string randomString()
{
	string str = "AAAAAA";

	// Thiết lập seed cho hàm rand() dựa trên thời gian hiện tại
	srand(time(0));

	// Sinh ngẫu nhiên các ký tự chữ cái
	str[0] = rand() % 26 + 65; // Random chữ cái hoa từ A đến Z
	str[1] = rand() % 26 + 65;
	str[2] = rand() % 26 + 65;

	// Sinh ngẫu nhiên các chữ số
	str[3] = rand() % 10 + 48; // Random số từ 0 đến 9
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
		cin.ignore();
		cout << "TenSach: "; getline(cin, s); dausach.tensach = s;

		cout << "SoTrang "; cin >> tmp; dausach.sotrang = tmp;
		cin.ignore();
		cout << "TacGia "; getline(cin, s); dausach.tacgia = s;

		cout << "NamXuatBan: "; cin >> tmp; dausach.nxb = tmp;
		cin.ignore();
		cout << "TheLoai: ";  getline(cin, s); dausach.theloai = s;

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
	DSDS.data[DSDS.n] = new DauSach;
	*DSDS.data[DSDS.n] = dausach;
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
	}
	cout << endl;
	_getch(); // Dừng màn hình cho đến khi người dùng ấn một phím bất kỳ
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
	bool deleted = false; // Biến cờ để đánh dấu xem cuốn sách đã được xóa hay không
	for (int i = 0; i < DSDS.n; i++) {
		if (DSDS.data[i]->ISBN == ISBN) {
			Delete_Item(DSDS, i);
			deleted = true;
			break; // Thoát khỏi vòng lặp sau khi xóa để tránh duyệt thêm
		}
	}
	if (!deleted) {
		cout << "Khong tim thay cuon sach voi ISBN nay trong danh sach." << endl;
	}
	else {
		cout << "Da xoa thanh cong." << endl;
	}
	// Dừng chương trình để hiển thị thông báo trước khi kết thúc(ko dung thi no ko hien dong cout ra)
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
	ofstream fileout;
	fileout.open("DSDS.txt", ios::out);//neu file da ton tai noi dung cua no se duoc cat truoc khi mo file 
	for (int i = 0; i < DSDS.n; i++) {
		fileout << DSDS.n;
		fileout << DSDS.data[i]->ISBN << ",";
		fileout << DSDS.data[i]->tensach << ",";
		fileout << DSDS.data[i]->sotrang << ",";
		fileout << DSDS.data[i]->tacgia << ",";
		fileout << DSDS.data[i]->nxb << ",";
		fileout << DSDS.data[i]->theloai;
		fileout << endl;
	}
	fileout.close();
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
void ReadDSDS(DS_DauSach& DSDS) {
	
	while (DSDS.n > 0) {
		delete DSDS.data[DSDS.n-1];
		DSDS.n--;
	}
	int n;
	string str;
	ifstream filein;
	DauSach ds;
	filein.open("DSDS.txt", ios::in);
	filein >> DSDS.n;
	for (int i = 0; i < DSDS.n; i++) {
		filein.ignore();
		DSDS.data[i] = new DauSach;
		getline(filein, str, ','); ds.ISBN = str; // xac dinh vi tri n byte ve sau cua doi tuong byte
		getline(filein, str, ','); ds.tensach = str; 
		getline(filein, str, ','); n = StringToInt(str); ds.sotrang = n; 
		getline(filein, str, ','); ds.tacgia = str; 
		getline(filein, str, ','); n = StringToInt(str); ds.nxb = n;	
		getline(filein, str); ds.theloai = str;	
		 //InsertLastDauSach( DSDS,ds);
		*DSDS.data[i] = ds; // noi dung ma con tro dang tro toi truyen vao danh sach 
	}
	cout << endl;
	filein.close();
}


// tim thong tin sach dua vao ten sach in ra the loai ... 
int Search(DS_DauSach& DSDS, string x)
{
	for (int i = 0; i < DSDS.n; i++) 
		if (DSDS.data[i]->tensach == x) return i;
	return -1;
}
// in ra thong tin sach tim kiem
void ShowSach(DS_DauSach &DSDS, string ten) {
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


// Hàm sắp xếp một mảng các đầu sách theo tiêu chí được chỉ định (ở đây là tên sách) bằng thuật toán bubble sort
void bubbleSort(DauSach* arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			// So sánh hai tên sách và hoán đổi vị trí nếu cần thiết
			if (arr[j]->tensach > arr[j + 1]->tensach) {
				DauSach* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


// Hàm hoán đổi hai đối tượng DauSach
void swap(DauSach*& a, DauSach*& b) {
	DauSach* temp = a;
	a = b;
	b = temp;
}

// Hàm chia mảng thành hai phần sao cho các phần tử nhỏ hơn phần tử chốt được đặt bên trái,các phần tử lớn hơn được đặt bên phải

int partition(DS_DauSach& DSDS, int low, int high) {
	int mid = (low + high) / 2; // Chọn phần tử ở giữa làm pivot
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

// Hàm triển khai thuật toán quicksort
void quickSort(DS_DauSach& DSDS, int low, int high) {
	if (low < high) {
		// Phân chia mảng và nhận chỉ số chốt
		int pi = partition(DSDS, low, high);

		// Sắp xếp các phần từ bên trái của phần tử chốt
		quickSort(DSDS, low, pi - 1);
		// Sắp xếp các phần từ bên phải của phần tử chốt
		quickSort(DSDS, pi + 1, high);
	}
}

// Hàm sắp xếp danh sách đầu sách theo thể loại và tên sách, nếu không cùng thể loại thì sắp xếp tăng dần theo tên sách
void sort_Theotheloai(DS_DauSach& DSDS) {
	// Sắp xếp danh sách đầu sách theo thể loại và tên sách
	quickSort(DSDS, 0, DSDS.n - 1);

	// Biến lưu trữ thể loại trước đó
	string str = "";
	int start = 0;

	// Duyệt qua danh sách đã sắp xếp
	for (int i = 0; i < DSDS.n; i++) {
		// Nếu thể loại của đầu sách hiện tại khác với thể loại trước đó
		if (DSDS.data[i]->theloai != str) {
			// Nếu đã có đủ 2 đầu sách khác thể loại
			if (i - start >= 2) {
				// Sắp xếp tăng dần các đầu sách từ startIdx đến i-1
				bubbleSort(DSDS.data + start, i - start);
			}
			// Lưu vị trí bắt đầu của thể loại mới
			start = i;
			str = DSDS.data[i]->theloai;
		}
	}

	// Nếu danh sách kết thúc với các đầu sách cùng thể loại, sắp xếp chúng
	if (DSDS.n - start >= 2) {
		bubbleSort(DSDS.data + start, DSDS.n - start);
	}

	// In danh sách đã sắp xếp
	LietKe(DSDS);
}

 // them sach nhièu hơn 1 sach
int InsertDauSach(DS_DauSach &DSDS, DauSach &dausach) {
	int i, k;
	if (DSDS.n == Max_DS_DauSach) return 0;
	for (i = 0; i < DSDS.n && DSDS.data[i]->tensach < dausach.tensach ; i++);
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
	// Hiển thị danh sách để sửa
	LietKe(DSDS);

	int index;
	cout << "Nhap vao so index muon sua: ";
	cin >> index;

	// Kiểm tra index có hợp lệ không
	if (index < 0 || index >= DSDS.n) {
		cout << "Vi tri index ko dung.";
		return;
	}

	// Hiển thị thông tin sách trước khi sửa
	cout << "Thong tin sach truoc khi sua: " << endl;
	cout << "1. ISBN:(ko dc sua) " << DSDS.data[index]->ISBN << endl;
	cout << "2. TenSach: " << DSDS.data[index]->tensach << endl;
	cout << "3. SoTrang: " << DSDS.data[index]->sotrang << endl;
	cout << "4. TacGia: " << DSDS.data[index]->tacgia << endl;
	cout << "5. NamXuatBan: " << DSDS.data[index]->nxb << endl;
	cout << "6. TheLoai: " << DSDS.data[index]->theloai << endl;

	DauSach dausach;

	// Giữ nguyên ISBN khi cập nhật thông tin sách
	dausach.ISBN = DSDS.data[index]->ISBN;
	// Hỏi người dùng chọn thông tin nào để sửa
	int choice;
	cout << "Chon thong tin muon sua (1-6): ";
	cin >> choice;

	// Xử lý dấu xuống dòng còn lại trong bộ đệm
	cin.ignore();

	// Nhập thông tin mới cho sách
	cout << "Nhap thong tin moi cho sach: " << endl;
	// Cập nhật thông tin sách dựa trên lựa chọn của người dùng

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
#ifndef CAUTRUCMUONTRA_H_INCLUDED
#define CAUTRUCMUONTRA_H_INCLUDED

#pragma once

//#include "cautrucdanhmucsach.h"
//#include "cautrucdausach.h"
//#include "cautructhedocgia.h"

/*-------------------Prototype-Struct------------------*/
//struct MuonTra;
//struct NodeMuonTra;

/*-------------------Struct------------------*/
struct Ngay{
	int ngay;
	int thang;
	int nam;
	Ngay(){
		ngay = 0;
		thang = 0;
		nam = 0;
	}
};


struct MuonTra{
	std::string masach;
	Ngay ngaymuon;
	Ngay ngaytra;
	int trangthai;
};

struct NodeMuonTra{
	MuonTra muontra;
	NodeMuonTra *next;
	NodeMuonTra *previous;
};

typedef struct NodeMuonTra* Nodemt;

/*trang thai muon tra
 * dangmuon(chua tra) = 0
 * datra = 1
 * matsach = 2
 */
enum TrangThai_MT{
	DangMuon,//0
	DaTra,//1
	MatSach,//2
};


/*-------------------Prototype------------------*/
//tao node muon tra
Nodemt CreateNodeMuonTra(MuonTra mt);

//them vao dau ll muon tra
void InsertFirst_NodeMuonTra(Nodemt &head, MuonTra mt);

//them vao cuoi ll muon tra
void InsertLast_NodeMuonTra(Nodemt &head, MuonTra mt);

//them vao sau node co dia chi p
void Insert_Right(Nodemt &head, MuonTra mt);

//them vao truoc node co dia chi p
void Insert_Left(Nodemt &head, MuonTra mt);

//xoa phan tu dau tien
void Delete_First(Nodemt &head, MuonTra mt);

//xoa phan tu cuoi cung
void Delete_Last(Nodemt &head, MuonTra mt);

//tao file va ghi du lieu vao file
void WriteFileMT(Nodemt node);

//doc du lieu tu file
void ReadFileMT(Nodemt &node);

//dinh danh ngay
std::string DinhDangNgay(Ngay ngay);

//tinh ngay muon tra
int TinhNgay(Ngay muon, Ngay tra);

//tinh nam nhuan
int NamNhuan(int nam);

//tinh ngay
int tinhngay(Ngay ngay);

//int to string
std::string tostring(int n);

///*-------------------Function------------------*/
Nodemt CreateNodeMuonTra(MuonTra mt){
	Nodemt p = new NodeMuonTra;
	p->muontra = mt;
	return p;
}

void InsertFirst_NodeMuonTra(Nodemt &head, MuonTra mt){
	Nodemt newnode = CreateNodeMuonTra(mt);
	newnode->next = head;
	if(head != NULL)
		head->previous = newnode;
	head = newnode;
}

void InsertLast_NodeMuonTra(Nodemt &head, MuonTra mt){
	Nodemt newnode = CreateNodeMuonTra(mt);
	if(head == NULL)
		head = newnode;
	else{
		Nodemt tail = head;
		while(tail->next != NULL)
			tail = tail->next;
		tail->next = newnode;
		newnode->previous = tail;
		tail = newnode;
	}
}

void Insert_Right(Nodemt &head, MuonTra mt){
	
}


void Insert_Left(Nodemt &head, MuonTra mt){
	
}

void Delete_First(Nodemt &head, MuonTra mt){
	if(head == NULL)
		std::cout << "Khong the xoa\n";
	else{
		Nodemt xoa = head;
		head = head->next;
		head->previous = NULL;
		delete xoa;
	}
}

void Delete_Last(Nodemt &head, MuonTra mt){
	if(head == NULL)
		std::cout << "Khong the xoa\n";
	else{
		Nodemt tail = head;
		while(tail->next != NULL)
			tail = tail->next;
		Nodemt xoa = tail;
		tail = tail->previous;
		tail->next = NULL;
		delete xoa;
	}
}

void WriteFileMT(Nodemt node){
	std::ofstream file;
	file.open("mt.txt", std::ios::trunc);
	if(!file)
		std::cout << "Khong tim thay file\n";
	else{
		std::cout << "Dang luu vao file\n";
		Nodemt temp = node;
		while(temp != NULL){
			file << temp->muontra.masach << "," 
			<< temp->muontra.ngaymuon.ngay << " " << temp->muontra.ngaymuon.thang << " " << temp->muontra.ngaymuon.nam
			<< "," << temp->muontra.ngaytra.ngay << " " << temp->muontra.ngaytra.thang << " " << temp->muontra.ngaytra.nam 
			<< "," << temp->muontra.trangthai << std::endl;
			temp = temp->next;
		}
		file.close();
	}
}

void ReadFileMT(Nodemt &node){
	std::ifstream file("mt.txt", std::ios::in);
	std::string str;
	int n;
	MuonTra mt;
	if(file.is_open()){
		while(file.eof() == false){
			//ma sach
			getline(file, str, ',');
			mt.masach = str;
			
			//ngay muon
			getline(file, str, ' ');
			n = StringToInt(str);
			mt.ngaymuon.ngay = n;
			
			getline(file, str, ' ');
			n = StringToInt(str);
			mt.ngaymuon.thang = n;
			
			getline(file, str, ',');
			n = StringToInt(str);
			mt.ngaymuon.nam = n;
			
			//ngay tra
			getline(file, str, ' ');
			n = StringToInt(str);
			mt.ngaytra.ngay = n;
			
			getline(file, str, ' ');
			n = StringToInt(str);
			mt.ngaytra.thang = n;
			
			getline(file, str, ',');
			n = StringToInt(str);
			mt.ngaytra.nam = n;
			
			//trang thai
			getline(file, str, '\n');
			n = StringToInt(str);
			mt.trangthai = n;
			
			InsertLast_NodeMuonTra(node, mt);	
		}
		int cnt = 0;
		Nodemt temp = node;
		while(temp != NULL){
			std::cout << "=======" << cnt + 1 << "======\n";
			std::cout << "Ma sach:" << temp->muontra.masach << std::endl;
			std::cout << "Ngay muon:" << DinhDangNgay(temp->muontra.ngaymuon) << std::endl;
			std::cout << "Ngay tra:" << DinhDangNgay(temp->muontra.ngaytra) << std::endl;
			std::cout << "Trang thai:" << temp->muontra.trangthai << std::endl;
			temp = temp->next;
			++cnt;
		}
	}
	else{
		std::cout << "Khong the doc duoc file.\n";
	}
	file.close();
}

std::string DinhDangNgay(Ngay ngay){
	std::string n = "";
	if(ngay.ngay < 10 && ngay.ngay > 0)
		n = "0" + tostring(ngay.ngay) + '/';
	else
		n = tostring(ngay.ngay) + '/';
		
	if(ngay.thang < 10 && ngay.thang > 0)
		n += "0" + tostring(ngay.thang) + '/';
	else
		n = tostring(ngay.thang) + '/';
	
	n += tostring(ngay.nam);
	return n;
}

int TinhNgay(Ngay muon, Ngay now){
	int t = tinhngay(now);
	int m = tinhngay(muon);
	return (t - m);
}

int NamNhuan(int nam){
	if(nam % 400 == 0 || (nam % 4 == 0 && nam % 4 != 0))
		return 366;
	return 365;
}

int tinhngay(Ngay ngay){
	int ngaynhuan[13] = {0,
                            31,29,31,30,31,30,
                            31,31,30,31,30,31};
    int khongnhuan[13] = {0,
                            31,28,31,30,31,30,
                            31,31,30,31,30,31};
    int t = ngay.ngay;
	for(int i = 1; i < ngay.nam; ++i)
		t += NamNhuan(i);
	if(NamNhuan(ngay.nam) == 365){
		for(int i = 1; i < ngay.thang; ++i)
			t += khongnhuan[i];	
		}
	else if(NamNhuan(ngay.nam) == 366){
		for(int i = 1; i < ngay.thang; ++i)
			t += ngaynhuan[i];
	}
	
	return t;
}

std::string tostring(int n){
    std::ostringstream str;
    str << n;
    std::string s = str.str();
    return s;
}
#endif 

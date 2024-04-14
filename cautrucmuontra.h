#pragma once
//#ifndef CAUTRUCMUONTRA_H_INCLUDED
//#define CAUTRUCMUONTRA_H_INCLUDED

//#pragma once

//#include "cautrucdanhmucsach.h"
//#include "cautrucdausach.h"
//#include "cautructhedocgia.h"

/*-------------------Prototype-Struct------------------*/
//struct MuonTra;
//struct NodeMuonTra;

/*-------------------Struct------------------*/
struct Ngay {
	int ngay;
	int thang;
	int nam;
};

struct MuonTra {
	std::string masach;
	Ngay ngaymuon;
	Ngay ngaytra;
	int trangthai;
};

struct NodeMuonTra {
	MuonTra muontra;
	NodeMuonTra* next;
	NodeMuonTra* previous;
};

typedef struct NodeMuonTra* Nodemt;

/*trang thai muon tra
 * dangmuon(chua tra) = 0
 * datra = 1
 * matsach = 2
 */
enum TrangThai_MT {
	DangMuon,//0
	DaTra,//1
	MatSach,//2
};


/*-------------------Prototype------------------*/
//tao node muon tra
Nodemt CreateNodeMuonTra(MuonTra mt);

//them vao dau ll muon tra
void InsertFirst_NodeMuonTra(Nodemt& head, MuonTra mt);

//them vao cuoi ll muon tra
void InsertLast_NodeMuonTra(Nodemt& head, MuonTra mt);

//them vao sau node co dia chi p
void InsertRight_NodeMuonTra(Nodemt& head, Nodemt p, MuonTra mt);

//them vao truoc node co dia chi p
void InsertLeft_NodeMuonTra(Nodemt& head, Nodemt p, MuonTra mt);

//xoa phan tu dau tien
void DeleteFirst_NodeMuonTra(Nodemt& head, MuonTra mt);

//xoa phan tu cuoi cung
void DeleteLast_NodeMuonTra(Nodemt& head, MuonTra mt);

//tao file va ghi du lieu vao file
//void WriteFileMT(Nodemt &node);

//doc du lieu tu file
//void ReadFileMT(Nodemt& node);

//dinh danh ngay
std::string DinhDangNgay(Ngay ngay);

//tinh ngay muon tra
int TinhNgay(Ngay muon, Ngay tra);

//tinh nam nhuan
int NamNhuan(int nam);

//tinh ngay
int tinhngay(Ngay ngay);

//xoa tat cac cac node
void DeleteAll_Mt(Nodemt& head);

//tim cac ma sach
Nodemt Tim_MSMt(Nodemt node, std::string tensach);

//so sanh 2 chuoi
bool SoSanhChuoi(std::string s, std::string t);//s.size < t.size

//dem danh sach muon tra
int DemMT(Nodemt node);

///*-------------------Function------------------*/
Nodemt CreateNodeMuonTra(MuonTra mt) {
	Nodemt p = new NodeMuonTra();
	p->muontra = mt;
	return p;
}

void InsertFirst_NodeMuonTra(Nodemt& head, MuonTra mt) {
	Nodemt newnode = CreateNodeMuonTra(mt);
	newnode->next = head;
	if (head != NULL)
		head->previous = newnode;
	head = newnode;
}

void InsertLast_NodeMuonTra(Nodemt& head, MuonTra mt) {
	Nodemt newnode = CreateNodeMuonTra(mt);
	if (head == NULL)
		head = newnode;
	else {
		Nodemt tail = head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newnode;
		newnode->previous = tail;
		tail = newnode;
	}
}

void InsertRight_NodeMuonTra(Nodemt& head, Nodemt p, MuonTra mt) {
	if (p == NULL)
		std::cout << "Node p khong ton tai, khong the them\n";
	else {//them newnode vao sau node p, r la node sau node p
		Nodemt newnode = CreateNodeMuonTra(mt);
		Nodemt r = p->next;
		//noi r voi newnode
		r->previous = newnode;
		newnode->next = r;
		//noi p voi newnode
		p->next = newnode;
		newnode->previous = p;
	}
}


void InsertLeft_NodeMuonTra(Nodemt& head, Nodemt p, MuonTra mt) {
	if (p == NULL)
		std::cout << "Node p khong ton tai, khong the them\n";
	else {//them newnode vao truoc node p, r la node truoc node p
		Nodemt newnode = CreateNodeMuonTra(mt);
		Nodemt r = p->previous;
		//noi node r va newnode
		r->next = newnode;
		newnode->previous = r;
		//noi node p va newnode
		newnode->next = p;
		p->previous = newnode;
	}
}

void DeleteFirst_NodeMuonTra(Nodemt& head, MuonTra mt) {
	if (head == NULL)
		std::cout << "Khong the xoa\n";
	else {
		Nodemt xoa = head;
		head = head->next;
		head->previous = NULL;
		delete xoa;
	}
}

void DeleteLast_NodeMuonTra(Nodemt& head, MuonTra mt) {
	if (head == NULL)
		std::cout << "Khong the xoa\n";
	else {
		Nodemt tail = head;
		while (tail->next != NULL)
			tail = tail->next;
		Nodemt xoa = tail;
		tail = tail->previous;
		tail->next = NULL;
		delete xoa;
	}
}

void DeleteAll_Mt(Nodemt& head) {
	Nodemt xoa;
	while (head != NULL) {
		xoa = head;
		head = head->next;
		delete xoa;
	}
}

//void WriteFileMT(Nodemt& node) {
//	std::ofstream file;
//	file.open("mt.txt", std::ios::out);
//	if (!file)
//		std::cout << "khong tim thay file\n";
//	else {
//		std::cout << "dang luu vao file\n";
//		Nodemt temp = node;
//		while (temp != NULL) {
//			file << temp->muontra.masach << ",";
//			file << temp->muontra.ngaymuon.ngay << "," << temp->muontra.ngaymuon.thang << "," << temp->muontra.ngaymuon.nam << ",";
//			file << temp->muontra.ngaytra.ngay << "," << temp->muontra.ngaytra.thang << "," << temp->muontra.ngaytra.nam << ",";
//			file << temp->muontra.trangthai << std::endl;
//			temp = temp->next;
//		}
//		file.close();
//	}
//}

//void ReadFileMT(Nodemt& node) {
//	std::ifstream file("mt.txt", std::ios::in);
//	std::string str;
//	int n;
//	DeleteAll_Mt(node);
//	MuonTra mt;
//	if (file.is_open()) {
//		while (file.eof() == false) {
//
//			//ma sach
//			getline(file, str, ',');
//			mt.masach = str;
//			if (str.empty())
//				break;
//
//			//ngay muon
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaymuon.ngay = n;
//			
//			
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaymuon.thang = n;
//
//			
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaymuon.nam = n;
//
//			//ngay tra
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaytra.ngay = n;
//
//
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaytra.thang = n;
//
//
//			getline(file, str, ',');
//			std::istringstream(str) >> n;
//			mt.ngaytra.nam = n;
//
//			//trang thai
//			getline(file, str);
//			n = StringToInt(str);
//			mt.trangthai = n;
//
//		InsertLast_NodeMuonTra(node, mt);	
//		}
//	}
//	else {
//		std::cout << "Khong the doc duoc file.\n";
//	}
//	file.close();
//}

std::string DinhDangNgay(Ngay ngay) {
	std::string n = "";
	if (ngay.ngay < 10 && ngay.ngay >= 0)
		n = "0" + std::to_string(ngay.ngay) + "/";
	else
		n = std::to_string(ngay.ngay) + "/";

	if (ngay.thang < 10 && ngay.thang >= 0)
		n += "0" + std::to_string(ngay.thang) + "/";
	else
		n = std::to_string(ngay.thang) + "/";

	n += std::to_string(ngay.nam);
	return n;
}

int TinhNgay(Ngay muon, Ngay now) {
	int t = tinhngay(now);
	int m = tinhngay(muon);
	return (t - m);
}

int NamNhuan(int nam) {
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 4 != 0))
		return 366;
	return 365;
}

int tinhngay(Ngay ngay) {
	int ngaynhuan[13] = { 0,
							31,29,31,30,31,30,
							31,31,30,31,30,31 };
	int khongnhuan[13] = { 0,
							31,28,31,30,31,30,
							31,31,30,31,30,31 };
	int t = ngay.ngay;
	for (int i = 1; i < ngay.nam; ++i)
		t += NamNhuan(i);
	if (NamNhuan(ngay.nam) == 365) {
		for (int i = 1; i < ngay.thang; ++i)
			t += khongnhuan[i];
	}
	else if (NamNhuan(ngay.nam) == 366) {
		for (int i = 1; i < ngay.thang; ++i)
			t += ngaynhuan[i];
	}

	return t;
}

Nodemt Tim_MSMt(Nodemt node, std::string masach) {
	//std::string temp = ChuanHoaMa(tensach);
	//Nodemt tmp = node;
	Nodemt tim = NULL;
	MuonTra MT;
	while (node != NULL) {
		if (node->muontra.masach.compare(masach) == 0){
			MT = node->muontra;
			InsertLast_NodeMuonTra(tim, node->muontra);
			break;
		}
		node = node->next;
	}
	return tim;
}

int DemMT(Nodemt node) {
	int n = 0;
	while (node != NULL) {
		node = node->next;
		++n;
	}
	return n;
}


//#endif 
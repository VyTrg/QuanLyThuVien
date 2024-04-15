//#pragma once
//#ifndef CAUTRUCDANHMUCSACH_H_INCLUDED
//#define CAUTRUCDANHMUCSACH_H_INCLUDED

#pragma once

//#include "cautrucdausach.h"
//#include "cautrucmuontra.h"
//#include "cautructhedocgia.h"

#define Max 100000

/*-------------------Prototype-Struct------------------*/
struct Sach;
struct NodeDMSach;

/*-------------------Struct------------------*/
struct Sach {
	std::string masach;
	int trangthai;
	std::string vitri;
};

struct NodeDMSach {
	Sach sach;
	NodeDMSach* next = NULL;
};

typedef struct NodeDMSach* Nodedms;

/*trang thai
 * muonduoc = 0
 * damuon = 1
 * dathanhly = 2
 */
enum TrangThai {
	MuonDuoc,//0
	DaMuon,//1
	DaThanhLy,//2
};

/*-------------------Prototype------------------*/
//tao node sach
Nodedms CreateNodeSach(Sach& sach);
//
////them vao dau danh sach
void InsertFirst_NodeDMSach(Nodedms& node, Sach& sach);
//
////them vao sau danh sach
void InsertAfter_NodeDMSach(Nodedms& node, Sach& sach);
//
////them vao cuoi danh sach
void InsertLast_NodeDMSach(Nodedms& node, Sach& sach);

//xoa phan tu cuoi cung


////lay thong tin sach bang vi tri 
Nodedms GetSach_position(Nodedms node, int position);
//
////lay thong tin sach bang ma sach
//Nodedms GetSach_masach(Nodedms& node, std::string masach);

//tao file va ghi du lieu vao file
//void WriteFileDMS(Nodedms &node);

//doc du lieu tu file
//void ReadFileDMS(Nodedms& node);

//string to integer
//int StringToInt(std::string s);

//xoa tat cac cac node
void DeleteAll_Dms(Nodedms& node);

//check trung
//Nodedms TrungMaSach(Nodedms dms, std::string masach);

//dem so luong dms
int DemDMS(Nodedms node);


/*-------------------Function------------------*/
Nodedms CreateNodeSach(Sach& sach) {
	Nodedms node = new NodeDMSach();
	node->sach = sach;

	return node;
}

void InsertFirst_NodeDMSach(Nodedms& node, Sach& sach) {
	Nodedms newnode = CreateNodeSach(sach);

	if (node == NULL)
		node = newnode;
	else {
		newnode->next = node;
		node = newnode;
	}
}

void InsertAfter_NodeDMSach(Nodedms& node, Sach& sach) {
	Nodedms newnode = CreateNodeSach(sach);

	newnode->next = node->next;
	node->next = newnode;

}

void InsertLast_NodeDMSach(Nodedms& node, Sach& sach) {
	Nodedms newnode = CreateNodeSach(sach);

	if (node == NULL)
		node = newnode;
	else {
		Nodedms temp = node;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

Nodedms GetSach_position(Nodedms node, int position) {
	//Nodedms temp_node = node;
	int i = 0;
	while (node != NULL) {
		if (i == position) break;
		else {
			++i;
			node = node->next;
		}
	}
	return node;
}

//void WriteFileDMS(Nodedms &node) {
//	std::ofstream file;
//	file.open("dms.txt", std::ios::trunc);
//	if (!file)
//		std::cout << "Khong tim thay file\n";
//	else {
//		std::cout << "Dang luu vao file\n";
//		Nodedms temp = node;
//		while (temp->next != NULL) {
//			file << temp->sach.masach << "," << temp->sach.trangthai << "," << temp->sach.vitri << std::endl;
//			temp = temp->next;
//		}
//		//		DeleteAll_Dms(node);
//		file.close();
//	}
//}

//void ReadFileDMS(Nodedms& node) {
//	std::ifstream file("dms.txt", std::ios::in);
//	std::string str;
//	int n;
//	Sach s;
//	DeleteAll_Dms(node);
//	std::string line;
//	if (file.is_open()) {
//		while (!file.eof()) {
//			getline(file, str, ',');
//			s.masach = str;
//
//			getline(file, str, ',');
//			n = StringToInt(str);
//			s.trangthai = n;
//
//			getline(file, str, '\n');
//			s.vitri = str;
//
//		InsertLast_NodeDMSach(node, s);	
//		}
//	}
//	else {
//		std::cout << "Khong the doc duoc file.\n";
//	}
//	file.close();
//}

void DeleteAll_Dms(Nodedms& node) {
	while (node != NULL) {
		Nodedms temp = node;
		node = node->next;
		delete temp;
	}
}


Nodedms Tim_Dms(Nodedms node, std::string tensach) {
	//std::string temp = ChuanHoaMa(tensach);
	//Nodedms tmp = node;
	Nodedms tim = NULL;
	Sach s;
	while (node != NULL) {
		InsertLast_NodeDMSach(tim, node->sach);
		node = node->next;
	}
	return tim;

}

int DemDMS(Nodedms node) {
	int n = 0;
	while (node != NULL) {
		++n;
		node = node->next;
	}
	return n;
}

Nodedms Tim_MSDMS(Nodedms node, std::string masach) {
	//std::string temp = ChuanHoaMa(tensach);
	//Nodemt tmp = node;
	Nodedms tim = NULL;
	Sach s;
	while (node != NULL) {
		if (node->sach.masach.compare(masach) == 0) {
			s = node->sach;
			InsertLast_NodeDMSach(tim, node->sach);
			break;
		}
		node = node->next;
	}
	return tim;
}

void DeleteFirst_NodeDMSach(Nodedms& node) {
	if (node == NULL)
		return;
	/*if (node->next == NULL) {
		delete node;
		return;
	}*/
	Nodedms xoa = node;
	node = node->next;
	delete xoa;
}

void DeleteAfter_NodeDMSach(Nodedms& node) {//xoa sau node p
	if (node == NULL || node->next == NULL)
		return;
	Nodedms xoa = node->next;
	node->next = node->next->next;
	delete xoa;
}

void Xoa_MSDMS(Nodedms& node, std::string masach) {//0: xoa duoc, 1: khong xoa duoc
	if (node->sach.masach == masach) {
		DeleteFirst_NodeDMSach(node);
	}
	else {
		Nodedms tmp = node;
		while (tmp->next->sach.masach != masach)
			tmp = tmp->next;
		DeleteAfter_NodeDMSach(tmp);
	}
		//else
			//return 1;
	
	//return 1;
}

Nodedms position(Nodedms node, int p) {
	int cnt = 0;
	while (node != NULL) {
		if (cnt == p) {
			return node;
		}
		++cnt;
		node = node->next;
	}
}

void HieuChinhDMS(Nodedms& node, std::string masach, Sach s) {
	
}

//Nodedms TrungMaSach(Nodedms dms, std::string masach) {
//	if (dms == NULL || dms->sach.masach.compare(masach) == 0)
//		return dms;
//	return Nodedms(dms->next, masa);
//}
//#endif 
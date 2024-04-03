#pragma once
#ifndef CAUTRUCDANHMUCSACH_H_INCLUDED
#define CAUTRUCDANHMUCSACH_H_INCLUDED

#pragma once

#include "cautrucdausach.h"
#include "cautrucmuontra.h"
#include "cautructhedocgia.h"

#define MAX 100000

/*-------------------Prototype-Struct------------------*/
struct Sach;
struct NodeDMSach;

/*-------------------Struct------------------*/
struct Sach {
	char masach[6];
	int trangthai;
	std::string vitri;
};

struct NodeDMSach {
	Sach sach;
	NodeDMSach* next;
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
void InsertFirst_NodeDMSach(Nodedms& First, Sach& sach);
//
////them vao sau danh sach
void InsertAfter_NodeDMSach(Nodedms& First, Sach& sach);
//
////them vao cuoi danh sach
void InsertLast_NodeDMSach(Nodedms& First, Sach& sach);
//
////lay thong tin sach bang vi tri 
Nodedms GetSach_position(Nodedms& First, int position);
//
////lay thong tin sach bang ma sach
//Nodedms GetSach_masach(Nodedms& First, std::string masach);

//sinh ma the tu dong
//char* SinhMS_tudong(char *masach);


/*-------------------Function------------------*/
//Nodedms CreateNodeSach(Sach& sach) {
//	Nodedms First = new NodeDMSach;
//	First->sach = sach;
//	return First;
//}
//
//void InsertFirst_NodeDMSach(Nodedms& First, Sach& sach) {
//	Nodedms newnode = CreateNodeSach(sach);
//
//	newnode->next = First;
//	First = newnode;
//}
//
//void InsertAfter_NodeDMSach(Nodedms& First, Sach& sach) {
//	Nodedms newnode = CreateNodeSach(sach);
//
//	newnode->next = First->next;
//	First->next = newnode;
//}
//
//void InsertLast_NodeDMSach(Nodedms& First, Sach& sach) {
//	Nodedms newnode = CreateNodeSach(sach);
//
//	if (First == NULL) InsertFirst_NodeDMSach(First, sach);
//	else {
//		Nodedms temp = First;
//		while (temp->next != NULL)
//			temp = temp->next;
//		InsertAfter_NodeDMSach(temp, sach);
//	}
//}
//
//Nodedms GetSach_position(Nodedms& First, int position) {
//	Nodedms node = First;
//	int i = 0;
//	while (node != NULL) {
//		if (i == position) break;
//		else {
//			++i;
//			node = node->next;
//		}
//	}
//	return node;
//}

//char* SinhMS_tudong(char *masach){
//	srand(time(NULL));
//    for (int i = 0; i < MAX; ++i) {
//        masach[i] = i + 1;
//    }
//    for (int i = 0; i < MAX; i++) {
//        int j = rand() % (MAX - i) + i;
//        int tmp = masach[i];
//        masach[i] = masach[j];
//        masach[j] = tmp;
//    }
//	return masach;
//}

#endif 
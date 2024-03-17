#ifndef CAUTRUCMUONTRA_H_INCLUDED
#define CAUTRUCMUONTRA_H_INCLUDED

#pragma once

//#include "cautrucdanhmucsach.h"
//#include "cautrucdausach.h"
//#include "cautructhedocgia.h"

/*-------------------Prototype-Struct------------------*/
struct MuonTra;
struct NodeMuonTra;

/*-------------------Struct------------------*/
struct MuonTra{
	char masach[6];
	std::string ngaymuon;
	std::string ngaytra;
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
void InsertFirst_NodeMuonTra(Nodemt &First, MuonTra mt);

//them vao sau node co dia chi p
void Insert_Right(Nodemt p, Nodemt &Last, MuonTra mt);

//them vao truoc node co dia chi p
void Insert_Left(Nodemt p, Nodemt &First, MuonTra mt);

///*-------------------Function------------------*/
Nodemt CreateNodeMuonTra(MuonTra mt){
	Nodemt p = new NodeMuonTra;
	p->muontra = mt;
	return p;
}

void InsertFirst_NodeMuonTra(Nodemt &First, Nodemt &Last, MuonTra mt){
	Nodemt p = new NodeMuonTra;
	p->muontra = mt;
	p->previous = NULL;
	p->next = First;
	if(First == NULL)
		Last = p;
	else{
		First->previous = p;
		First = p;
	}
}

void Insert_Right(Nodemt p, Nodemt &Last, MuonTra mt){
	Nodemt q = new NodeMuonTra;//q la node can them vao, p truoc p
	Nodemt r = new NodeMuonTra;//r sau q
	if(p == NULL){
		std::cout << "Khong them duoc\n";
	}
	else{
		q->muontra = mt;
		r = p->next;
		//tao lien ket giua r va q
		r->previous = q;
		q->next = r;
		//tao lien ket giua p va q
		q->previous = p;
		p->next = q;
		if(p == Last) Last = q; 
	}
}

void Insert_Left(Nodemt p, Nodemt &First, MuonTra mt){
	
}

#endif 

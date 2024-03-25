#ifndef CAUTRUCDANHMUCSACH_H_INCLUDED
#define CAUTRUCDANHMUCSACH_H_INCLUDED

#pragma once

#include "cautrucdausach.h"
//#include "cautrucmuontra.h"
//#include "cautructhedocgia.h"

#define MAX 100000

/*-------------------Prototype-Struct------------------*/
struct Sach;
struct NodeDMSach;

/*-------------------Struct------------------*/
struct Sach{
	std::string masach;
	int trangthai;
	std::string vitri;
};

struct NodeDMSach{
	Sach sach;
	NodeDMSach *next = NULL;
};

typedef struct NodeDMSach* Nodedms;
/*trang thai
 * muonduoc = 0
 * damuon = 1
 * dathanhly = 2
 */
enum TrangThai{
	MuonDuoc,//0
	DaMuon,//1
	DaThanhLy,//2
};

/*-------------------Prototype------------------*/
//tao node sach
Nodedms CreateNodeSach(Sach &sach);
//
////them vao dau danh sach
void InsertFirst_NodeDMSach(Nodedms &node, Sach &sach);
//
////them vao sau danh sach
void InsertAfter_NodeDMSach(Nodedms &node, Sach &sach);
//
////them vao cuoi danh sach
void InsertLast_NodeDMSach(Nodedms &node, Sach &sach);
//
////lay thong tin sach bang vi tri 
Nodedms GetSach_position(Nodedms &node, int position);
//
////lay thong tin sach bang ma sach
Nodedms GetSach_masach(Nodedms &node, std::string masach);

//sinh ma sach tu dong
std::string MaSach(Nodedms &node, DauSach *DauSach);

//tao file va ghi du lieu vao file
void WriteFileDMS(Nodedms node);

//doc du lieu tu file
void ReadFileDMS(Nodedms &node);

//string to integer
int StringToInt(std::string s);

//xoa tat cac cac node
void DeleteAll_Dms(Nodedms &node);


/*-------------------Function------------------*/
Nodedms CreateNodeSach(Sach &sach){
	Nodedms node = new NodeDMSach;
	node->sach = sach;
	
	return node;
}

void InsertFirst_NodeDMSach(Nodedms &node, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	if(node == NULL)
		node = newnode;
	else{
		newnode->next = node;
		node = newnode;
	}
}

void InsertAfter_NodeDMSach(Nodedms &node, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	newnode->next = node->next;
	node->next = newnode;
	
}

void InsertLast_NodeDMSach(Nodedms &node, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	if(node == NULL)
		node = newnode;
	else{
		Nodedms temp = node;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

Nodedms GetSach_position(Nodedms &node, int position){
	Nodedms temp_node = node;
	int i = 0;
	while(temp_node != NULL){
		if(i == position) break;
		else{
			++i;
			temp_node = temp_node->next;
		}
	}
	return temp_node;
}

std::string MaSach(std::string tensach){
	std::string ms = "";
	
	bool check = true;
	int length = tensach.size();
	for(int i = 0; i <  length; ++i){
		if(tensach[i] == ' ')
			check = true;
		else if(tensach[i] != ' ' && check == true){
			ms.push_back(toupper(tensach[i]));
			check = false;
		}
	}
	return ms;
}

//string to integer
int StringToInt(std::string s) 
{ 
    int num = 0; 
    int n = s.length(); 
    for (int i = 0; i < n; i++) 
        num = num * 10 + (int(s[i]) - 48); 
    return num;
} 

void WriteFileDMS(Nodedms node){
	std::ofstream file;
	file.open("dms.txt", std::ios::trunc);
	if(!file)
		std::cout << "Khong tim thay file\n";
	else{
		std::cout << "Dang luu vao file\n";
		Nodedms temp = node;
		while(temp->next != NULL){
			file << temp->sach.masach << "," << temp->sach.trangthai << "," << temp->sach.vitri << std::endl;
			temp = temp->next;
		}
//		DeleteAll_Dms(node);
		file.close();
	}
}

void ReadFileDMS(Nodedms &node){
	std::ifstream file("dms.txt", std::ios::in);
	std::string str;
	int n;
	Sach s;
	std::string line;
	if(file.is_open()){
		while(!file.eof()){
			getline(file, str, ',');
				s.masach = str;

				getline(file, str, ',');
				n = StringToInt(str);
				s.trangthai = n;

				getline(file, str, '\n');
				s.vitri = str;
			
//				InsertLast_NodeDMSach(node, s);	
		}
	}
	else{
		std::cout << "Khong the doc duoc file.\n";
	}
	file.close();
}

void DeleteAll_Dms(Nodedms &node){
	while(node != NULL){
		Nodedms temp = node;
		node = node->next;
		delete temp;
	}
}
#endif 

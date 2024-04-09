#pragma once
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include "dohoa_docgia.h"


using std::cout;
using std::string;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::ifstream;
using std::max;

int nDG;
string ma = "00000";
int MAX = 10;

struct DocGia
{

	string MATHE;
	string ho;
	string ten;
	string phai;
	int trangThai;
	//0 the bi khoa
	//1 the dang hoat dong
	int muon = 0;

	Nodemt mt = NULL;
};

struct NodeDocGia
{

	DocGia docgia;
	NodeDocGia* pLeft = NULL;
	NodeDocGia* pRight = NULL;

	//    LIST_MT = mt;
};

typedef struct NodeDocGia NODE_DG;
typedef NODE_DG* TREE_DG;


// ===============prototype===========================

void KhoiTao(TREE_DG& t); //khoi tao cay
bool IsEmpty(TREE_DG t); //check rong
//DocGia* Create_DG(); //tao doc gia
void XuatDG(DocGia dg); //in doc gia
//void Duyet_RNL(TREE_DG t); //duyet cay
//void Duyet_LNR(TREE_DG t, DocGia dg); //duyet cay
void DuyetTen(TREE_DG t, string arr[], int& sl); //duyet theo ten
void BubbleSort(string arr[], int sl); //sap xep noi bot
void Find_TenDG(TREE_DG t, string ten); //tim doc gia theo ten
TREE_DG GetNode_DG(DocGia dg); //lay node doc gia
void InsertDGtoTree(TREE_DG& t, DocGia dg); //them doc gia vao cay
int countDG(TREE_DG t); //dem node
TREE_DG checkMT(TREE_DG t, string a); //check trung
string RandomMT(TREE_DG t); //ramdon ma the
TREE_DG FindMin(TREE_DG t); //tìm min
TREE_DG Find_DG(TREE_DG t, string MATHE); //tim doc gia theo mathe
bool IsDeleted_DG(TREE_DG& t, string MT); //check xoa doc gia ton tai
int height(TREE_DG t); //chieu cao cay
bool checkAVL(TREE_DG t); //kiem tra cay AVL
TREE_DG XoayPhai(TREE_DG a); //xoay phai
TREE_DG XoayTrai(TREE_DG a); //xoay trai
TREE_DG cap_nhap_AVL(TREE_DG& t); //cap nhap
void Push_info(TREE_DG t, ofstream& outfile); //them vao file
void Write_info(TREE_DG t, int sl); //ghi file
void Read_info(TREE_DG& t); //doc file
void FreeMemory(TREE_DG t); //giai phong bo nho
//void PrintDG(DocGia dg);


void KhoiTao(TREE_DG& t) {
	t = NULL;
	nDG = 0;
}

bool IsEmpty(TREE_DG t)
{
	return t == NULL;
}

/*ocGia* Create_DG()
{
	DocGia* newNode = new DocGia;
	newNode->MATHE = "";
	newNode->ho = "";
	newNode->ten = "";
	newNode->phai = "";
	newNode->trangThai = -1;

	return newNode;
}*/

void XuatDG(DocGia dg)
{
	cout << "-------------------------------\n";
	cout << "Thong tin doc gia\n";
	cout << "Ma The: " << dg.MATHE << endl;
	cout << "Ho: " << dg.ho << endl;
	cout << "Ten: " << dg.ten << endl;
	cout << "Gioi tinh: " << dg.phai << endl;
	if (dg.trangThai == 1) cout << "Trang thai the: Dang hoat dong";
	else cout << "Trang thai the: Bi khoa";
	cout << endl;

}

//void Duyet_LNR(TREE_DG t)
//{
//	if (t != NULL) {
//		Duyet_LNR(t->pLeft);
//		PrintDG(t->docgia);
//		Duyet_LNR(t->pRight);
//	}
//}

//void Duyet_RNL(TREE_DG t)
//{
//	if (t != NULL) {
//		Duyet_LNR(t->pRight);
//		XuatDG(t->docgia);
//		Duyet_LNR(t->pLeft);
//	}
//}

void DuyetTen(TREE_DG t, string arr[], int& sl)
{
	if (t != NULL)
	{
		DuyetTen(t->pLeft, arr, sl);
		arr[sl++] = t->docgia.ten;
		DuyetTen(t->pRight, arr, sl);
	}
}

void BubbleSort(string arr[], int sl)
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = 0; j < sl - i - 1; j++)
		{
			if (arr[j].compare(arr[j + 1]) > 0)
			{
				string temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Find_TenDG(TREE_DG t, string ten)
{
	if (t != NULL) {
		Find_TenDG(t->pLeft, ten);
		if (ten.compare(t->docgia.ten) == 0) XuatDG(t->docgia);
		else Find_TenDG(t->pRight, ten);
	}
}

TREE_DG GetNode_DG(DocGia dg)
{
	NODE_DG* p = new NODE_DG;
	if (p == NULL) {
		return NULL;
	}
	// khoi tao danh muc sach trong node doc gia
//	initList_MT(p->mt);
	p->docgia = dg;
	p->pLeft = p->pRight = NULL;
	return (p);
}

void InsertDGtoTree(TREE_DG& t, DocGia dg)
{
	/// tang doc gia len 1
	if (t == NULL) {
		t = GetNode_DG(dg);
		++nDG;
	}
	else if (dg.MATHE.compare(t->docgia.MATHE) < 0)
	{
		InsertDGtoTree(t->pLeft, dg);
	}
	else
	{
		InsertDGtoTree(t->pRight, dg);
	}
}

int countDG(TREE_DG t)
{
	int c = 1;             // ban than node duoc dem la 1;
	if (t == NULL)
		return 0;
	else
	{
		c += countDG(t->pLeft);
		c += countDG(t->pRight);
		return c;
	}
}

TREE_DG checkMT(TREE_DG t, string a)
{
	if (t == NULL || t->docgia.MATHE.compare(a) == 0)
		return t;
	else if (t->docgia.MATHE.compare(a) > 0)
		return checkMT(t->pLeft, a);
	else
		return checkMT(t->pRight, a);
}

string RandomMT(TREE_DG t)
{
	srand(time(NULL));
	do
	{
		for (int i = 0; i < 5; i++)
		{
			ma[i] = rand() % (57 - 48 + 1) + 48;
			// random tmp[i] thuoc doan [0, 9]
			// doan [0, 9] co ma ascii tu 48 - 57
		}
	} while (checkMT(t, ma) != NULL);
	return ma;
}

TREE_DG FindMin(TREE_DG t)
{
	while (t->pLeft != NULL) t = t->pLeft;
	return (t);
}

TREE_DG Find_DG(TREE_DG t, string MATHE)
{
	while (t != NULL && t->docgia.MATHE != MATHE)
	{
		if (MATHE < t->docgia.MATHE)
		{
			t = t->pLeft;
		}
		else t = t->pRight;
	}
	return (t);
}

bool IsDeleted_DG(TREE_DG& t, string MT)
{
	if (t == NULL)
		return false;
	else
	{
		if (MT.compare(t->docgia.MATHE) > 0)
			return IsDeleted_DG(t->pRight, MT);
		else if (MT.compare(t->docgia.MATHE) < 0)
			return IsDeleted_DG(t->pLeft, MT);
		else // Wohoo... I found you, Get ready to be deleted
		{
			//case 1: No child
			if (t->pLeft == NULL && t->pRight == NULL)
			{
				delete t; // dangling pointer
				t = NULL;
				nDG--;
			}
			else if (t->pLeft == NULL)// case 2: One child
			{
				NODE_DG* temp = t;
				t = t->pRight;
				delete temp;
				nDG--;
			}
			else if (t->pRight == NULL)
			{
				NODE_DG* temp = t;
				t = t->pLeft;
				delete temp;
				nDG--;
			}// Case 3: 2 children
			else {
				NODE_DG* temp = FindMin(t->pRight);

				// copy du lieu vao .
				t->docgia = temp->docgia;
				//				t->mt = temp->mt;
				return IsDeleted_DG(t->pRight, temp->docgia.MATHE);
			}
			return true;
		}
	}
}

//===============Chuyen cay nhi phan sang cay AVL======================
int height(TREE_DG t)
{
	if (t == NULL) return -1;
	return max(height(t->pLeft), height(t->pRight)) + 1;
}

bool checkAVL(TREE_DG t)
{
	if (t == NULL) return true;
	if (abs(height(t->pLeft) - height(t->pRight)) > 1)
		return false;
	return checkAVL(t->pLeft) && checkAVL(t->pRight);
}

// ===========Xoay trai===================
TREE_DG XoayPhai(TREE_DG a)
{
	NODE_DG* b = a->pLeft;
	NODE_DG* d = b->pRight;
	a->pLeft = d;
	b->pRight = a;
	return b;
}
// ===========Xoay phai===================
TREE_DG XoayTrai(TREE_DG a)
{
	NODE_DG* b = a->pRight;
	NODE_DG* d = b->pLeft;
	a->pRight = d;
	b->pLeft = a;
	return b;
}
TREE_DG cap_nhap_AVL(TREE_DG& t)
{
	if (abs(height(t->pLeft) - height(t->pRight)) > 1)
	{
		if (height(t->pLeft) > height(t->pRight))
		{
			NODE_DG* x = t->pLeft;
			if (height(x->pLeft) >= height(x->pRight))    // Trai - trai
				t = XoayPhai(t);
			else                                        // Trai _ phai
			{
				t->pLeft = XoayTrai(t->pLeft);
				t = XoayPhai(t);
			}
		}
		else
		{
			NODE_DG* x = t->pRight;
			if (height(x->pRight) >= height(x->pLeft))    // Phai- Phai
				t = XoayTrai(t);
			else
			{
				t->pRight = XoayPhai(t->pRight);        // Phai -trai
				t = XoayTrai(t);
			}
		}
	}
	if (t->pLeft != NULL)
		t->pLeft = cap_nhap_AVL(t->pLeft);
	if (t->pRight != NULL)
		t->pRight = cap_nhap_AVL(t->pRight);
	return t;
}

//=======================Tuong tac file================================
void Push_info(TREE_DG t, ofstream& outfile)
{
	if (t != NULL)
	{
		outfile << t->docgia.MATHE << "," << t->docgia.ho << "," << t->docgia.ten
			<< "," << t->docgia.phai << "," << t->docgia.trangThai << endl;
		Push_info(t->pLeft, outfile);
		Push_info(t->pRight, outfile);
	}
}

void Write_info(TREE_DG t, int sl)
{
	ofstream outfile;
	outfile.open("dsdg.txt", ios_base::trunc); // xoa sach va ghi vao file -> do co chuc nang xoa kho ghi noi tiep -> co the gay lap du lieu
	outfile << sl << endl;
	Push_info(t, outfile);
	outfile.close();
}
//==========Lay du lieu tu file=========

void Read_info(TREE_DG& t)
{
	ifstream fileIn;
	fileIn.open("dsdg.txt", ios_base::in);
	if (!fileIn) {
		cout << "dsdg.txt: Open fail!\n";
		return;
	}
	int sl;
	fileIn >> sl;

	for (int i = 0; i < sl; i++)
	{
		fileIn.ignore();
		DocGia dg;
		getline(fileIn, dg.MATHE, ',');
		getline(fileIn, dg.ho, ',');
		getline(fileIn, dg.ten, ',');
		getline(fileIn, dg.phai, ',');
		fileIn >> dg.trangThai;

		InsertDGtoTree(t, dg);

	}
	fileIn.close();
}

void FreeMemory(TREE_DG t)
{
	if (t == NULL) return;
	FreeMemory(t->pLeft);
	FreeMemory(t->pRight);
	delete t;
}
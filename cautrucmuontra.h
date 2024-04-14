#pragma once

using std::cout;
using std::string;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::ifstream;
using std::max;

int nDG;
string ma = "00000";

struct DocGia
{
	string MATHE;
	string ho;
	string ten;
	string phai;
	int trangThai;
	//0 the bi khoa
	//1 the dang hoat dong

	Nodemt node = NULL;
	int muon;//dem muon ma sach
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
DocGia* Create_DG(); //tao doc gia
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
void Push_info(TREE_DG t, ofstream& outfileDG, ofstream& outfileMT); //them vao file
void Write_info(TREE_DG t, int sl); //ghi file
void Read_info(TREE_DG& t); //doc file
void FreeMemory(TREE_DG t); //giai phong bo nho

string chuanhoa_name(string ten)
{
	string name = "";
	for (int i = 0; i < ten.size(); i++)
	{
		if (ten[i] >= 'A' && ten[i] <= 'Z')
			ten[i] += 32;
	}
	for (int i = 0; i < ten.size(); i++)
	{
		if (i != 0 && ten[i] == ' ' && ten[i - 1] != ' ')
			name += ten[i];
		else if (ten[i] >= 'a' && ten[i] <= 'z')
			name += ten[i];
	}
	if (name[name.size() - 1] == ' ') name.pop_back();
	name[0] -= 32;
	for (int i = 1; i < name.size(); i++)
	{
		if (i != name.size() - 1 && name[i] == ' ')
			name[i + 1] -= 32;
	}
	return name;
}

bool kt_chuoi_rong(string s)
{
	if (s.empty() == true) return true;
	bool check = true;
	for (int i = 0; i < s.size(); i++) if (s[i] != ' ') check = false;
	if (check == true) return true;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && s[i] != ' ') return true;
	}
	return false;
}

void KhoiTao(TREE_DG& t) {
	t = NULL;
	nDG = 0;
}

bool IsEmpty(TREE_DG t)
{
	return t == NULL;
}

DocGia* Create_DG()
{
	DocGia* newNode = new DocGia;
	newNode->MATHE = "";
	newNode->ho = "";
	newNode->ten = "";
	newNode->phai = "";
	newNode->trangThai = -1;
	newNode->muon = 0;

	return newNode;
}

void XuatDG(DocGia dg)
{
	cout << dg.MATHE << endl;
	cout << dg.ho << endl;
	cout << dg.ten << endl;
	cout << dg.phai << endl;
	cout << dg.trangThai << endl;
	cout << dg.muon << endl;
	while (dg.node != NULL) {
		std::cout << dg.node->muontra.masach << std::endl;
		std::cout << DinhDangNgay(dg.node->muontra.ngaymuon) << std::endl;
		std::cout << DinhDangNgay(dg.node->muontra.ngaytra) << std::endl;
		std::cout << dg.node->muontra.trangthai;
		dg.node = dg.node->next;
		std::cout << std::endl;
	}
}

void DuyetLNR(TREE_DG t)
{
	if (t != NULL)
	{
		DuyetLNR(t->pLeft);
		//arr[sl++] = t;
		XuatDG(t->docgia);
		DuyetLNR(t->pRight);
	}
}

void xep_noi_botten(NODE_DG** arr, int sl)
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = 0; j < sl - i - 1; j++)
		{
			if (arr[j]->docgia.ten.compare(arr[j + 1]->docgia.ten) > 0)
			{
				NODE_DG* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void xep_noi_botMATHE(NODE_DG** arr, int sl)
{
	for (int i = 0; i < sl - 1; i++)
	{
		for (int j = 0; j < sl - i - 1; j++)
		{
			if (arr[j]->docgia.MATHE.compare(arr[j + 1]->docgia.MATHE) > 0)
			{
				NODE_DG* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

TREE_DG GetNode_DG(DocGia dg)
{
	NODE_DG* p = new NODE_DG;
	if (p == NULL) {
		return NULL;
	}
	// khoi tao danh muc sach trong node doc gia

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

bool check_trung(TREE_DG t, string a)
{
	if (t == NULL)
		return false;
	else if (t->docgia.MATHE.compare(a) > 0)
		return check_trung(t->pLeft, a);
	else if (t->docgia.MATHE.compare(a) < 0)
		return check_trung(t->pRight, a);
	else
		return true;
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

TREE_DG Deleted_DG(TREE_DG& t, string MT)
{
	if (t == NULL)
		return t;
	else if (MT.compare(t->docgia.MATHE) > 0)
		t->pRight = Deleted_DG(t->pRight, MT);
	else if (MT.compare(t->docgia.MATHE) < 0)
		t->pLeft = Deleted_DG(t->pLeft, MT);
	else
	{
		// Wohoo... I found you, Get ready to be deleted

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
			//t->mt = temp->mt;
			t->pRight = Deleted_DG(t->pRight, temp->docgia.MATHE);
		}

	}
	return t;
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
void Push_info(TREE_DG t, ofstream& outfileDG, ofstream& outfileMT)
{
	if (t != NULL)
	{
		t->docgia.muon = DemMT(t->docgia.node);
		outfileDG << t->docgia.MATHE << "," << t->docgia.ho << "," << t->docgia.ten
			<< "," << t->docgia.phai << "," << t->docgia.trangThai << " " << t->docgia.muon << endl;
		while (t->docgia.node != NULL) {
			outfileMT << t->docgia.node->muontra.masach << ",";
			outfileMT << t->docgia.node->muontra.ngaymuon.ngay << " " << t->docgia.node->muontra.ngaymuon.thang << " " << t->docgia.node->muontra.ngaymuon.nam << " ";
			outfileMT << t->docgia.node->muontra.ngaytra.ngay << " " << t->docgia.node->muontra.ngaytra.thang << " " << t->docgia.node->muontra.ngaytra.nam << " ";
			outfileMT << t->docgia.node->muontra.trangthai;
			t->docgia.node = t->docgia.node->next;
			outfileMT << endl;
		}
		Push_info(t->pLeft, outfileDG, outfileMT);
		Push_info(t->pRight, outfileDG, outfileMT);
	}
}

void Write_info(TREE_DG t, int sl)
{
	ofstream outfileDG, outfileMT;
	outfileDG.open("dsdg.txt", ios_base::app);// xoa sach va ghi vao file -> do co chuc nang xoa kho ghi noi tiep -> co the gay lap du lieu
	outfileMT.open("mt.txt", ios_base::app);
	outfileDG << sl << endl;
	Push_info(t, outfileDG, outfileMT);
	outfileDG.close();
	outfileMT.close();
}
//==========Lay du lieu tu file=========

void Read_info(TREE_DG& t)
{
	ifstream fileInDG, fileInMT;
	fileInDG.open("dsdg.txt", ios_base::in);
	fileInMT.open("mt.txt", ios_base::in);
	if (!fileInDG || !fileInMT) {
		cout << "dsdg.txt/ mt.txt: Open fail!\n";
		return;
	}
	int sl;
	fileInDG >> sl;
	string str;
	MuonTra mt;
	int n;
	for (int i = 0; i < sl; i++)
	{
		fileInDG.ignore();
		DocGia dg;
		getline(fileInDG, dg.MATHE, ',');
		getline(fileInDG, dg.ho, ',');
		getline(fileInDG, dg.ten, ',');
		getline(fileInDG, dg.phai, ',');
		fileInDG >> dg.trangThai;
		fileInDG >> dg.muon;
		for (int i = 0; i < dg.muon; ++i) {
			//ma sach
			getline(fileInMT, str, ',');
			mt.masach = str;

			//ngay muon
			fileInMT >> n;
			mt.ngaymuon.ngay = n;


			fileInMT >> n;
			mt.ngaymuon.thang = n;


			fileInMT >> n;
			mt.ngaymuon.nam = n;

			//ngay tra
			fileInMT >> n;
			mt.ngaytra.ngay = n;


			fileInMT >> n;
			mt.ngaytra.thang = n;


			fileInMT >> n;
			mt.ngaytra.nam = n;

			//trang thai
			fileInMT >> n;
			mt.trangthai = n;

			InsertLast_NodeMuonTra(dg.node, mt);
		}
		InsertDGtoTree(t, dg);

	}
	fileInDG.close();
	fileInMT.close();
}

void FreeMemory(TREE_DG t)
{
	if (t == NULL) return;
	FreeMemory(t->pLeft);
	FreeMemory(t->pRight);
	delete t;
}

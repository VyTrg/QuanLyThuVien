#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::string;

int nDG;

struct DocGia{
	
	string MATHE;
	string ho;
	string ten;
	string phai;
	int trangThai;
	
//	DS_MuonTra mt;
};

struct NodeDocGia
{
    DocGia docgia;
    NodeDocGia *pLeft = NULL;
    NodeDocGia *pRight = NULL;
    
//    LIST_MT = mt;
};

typedef struct NodeDocGia NODE_DG;
typedef NODE_DG* TREE_DG;

struct QuaHan
{
	int MATHE;
	int songayquahan;
};

void KhoiTao(TREE_DG &t) {
	nDG = 0;
	t = NULL;
}

bool IsEmpty(TREE_DG t)
{
	return t == NULL;
}

void Duyet_LNR(TREE_DG t)
{
	if (t != NULL) {
		Duyet_LNR(t->pLeft);
		cout << "Thong tin doc gia";
		cout << "Ma The: " << t->docgia.MATHE;
		cout << "Ho: " << t->docgia.ho;
		cout << "Ten: " << t->docgia.ten;
		cout << "Gioi tinh: " << t->docgia.phai;
		Duyet_LNR(t->pRight);
	}
}

TREE_DG GetNode_DG(DocGia dg)
{
	NODE_DG *p = new NODE_DG;
	if (p == NULL) {
		return NULL;
	}
	// khoi tao danh muc sach trong node doc gia
//	initList_MT(p->mt);
	p->docgia = dg;
	p->pLeft = p->pRight = NULL;
	return (p);
}

void InsertDGtoTree(TREE_DG &t, DocGia dg)
{
	/// tang doc gia len 1
	if (t == NULL) {
		t = GetNode_DG(dg);
		++nDG;
	}
	else if (t->docgia.MATHE > dg.MATHE)
	{
		InsertDGtoTree(t->pLeft, dg);
	}
	else if (t->docgia.MATHE < dg.MATHE)
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
    if(t == NULL || t->docgia.MATHE.compare(a) == 0)
        return t;
    else if(t->docgia.MATHE.compare(a) > 0)
        return checkMT(t->pLeft, a);
    else
        return checkMT(t->pRight, a);
}

string RandomMT(TREE_DG t)
{
    srand(time(NULL));
    string tmp = "";
    do
    {
        for(int i = 2; i < 6; i++)
        {
            tmp[i] = rand() % (57 - 48 + 1) + 48; // random ma[i] thuoc doan [0, 9]
        }
    }while(checkMT(t, tmp) != NULL);
    return tmp;
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

bool IsDeleted_DG(TREE_DG &t, string MT)
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

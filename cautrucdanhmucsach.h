struct Sach{
	std::string masach;
	int trangthai;
	std::string vitri;
};

struct NodeDMSach{
	Sach sach;
	NodeDMSach *next;
};

typedef struct NodeDMSach* Nodedms;

//enum TrangThai{
//	MuonDuoc;
//	DaMuon;
//	DaThanhLy;
//};
//
//prototype
/*
them vao dau
them vao sau
them vao cuoi
*/
void InsertFirst_NodeDMSach(Nodedms &First, Sach &sach);
void InsertAfter_NodeDMSach(Nodedms &First, Sach &sach);
void InsertLast_NodeDMSach(Nodedms &First, Sach &sach);


Nodedms CreateNodeSach(Sach &sach);

Nodedms CreateNodeSach(Sach &sach){
	Nodedms First = new NodeDMSach;
	First->sach = sach;
	return First;
}

void InsertFirst_NodeDMSach(Nodedms &First, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	newnode->next = First;
	First = newnode;
}

void InsertAfter_NodeDMSach(Nodedms &First, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	newnode->next = First->next;
	First->next = newnode;
}

void InsertLast_NodeDMSach(Nodedms &First, Sach &sach){
	Nodedms newnode = CreateNodeSach(sach);
	
	if(First == NULL) InsertFirst_NodeDMSach(First, sach);
	else{
		Nodedms temp = First;
		while(temp->next != NULL)
			temp = temp->next;
		InsertAfter_NodeDMSach(temp, sach);
	}	
}

//cau truc danh muc sach 
struct Sach{
	char MASACH[20];
	int trangthai; // 0 cho muon duoc  1 da cho muon  2 da thanh ly
	char vitri[20];
	Sach(){
		Sach(char ms[20], int tt, char vt[30]);
		strcpy(MASACH,ms);
		trangthai=tt;
		strcpy(vitri, vt);
	}
};
// lien ket don
struct NodeSach{
	Sach sach;
	NodeSach *next;
};
// cap phat bo nho moi
NodeSach* CreateNodeSach(Sach &sach){
	NodeSach *node = new NodeSach;
	node->sach = sach;
	return node;
}
//them vao dau danh sach 
void Insert_First(NodeSach* &First, Sach &sach){
	NodeSach *newNode = CreatNodeSach(sach);
	newNode->next = First;
	First = newNode;
}
//them vao sau nut 
void Insert_After(NodeSach* &node, Sach &sach){
	NodeSach *newNode = CreatNodeSach(sach);
	newNode->info = sach;
	newNode->next = node->next;
	node->next = newNode;
}
//them vao cuoi danh sach 
void Insert_Last(NodeSach* &node, Sach &sach){
	if(First == NULL){
		Insert_First(First, sach);
	}
	else{
		NodeSach *last;
		for(last=First; last->next != NULL; last = last->next);
		Insert_After(last,sach);
	}
}
//xoa phan tu dau cua danh sach 
void Delete_First(NodeSach* &First){
	if(First == NULL)
		return 0;
	First = First->next;
}
//xoa phan tu theo ndung 
int Delete_Infor(NodeSach* &First, Sach &sach)
{ 	NodeSach *p;
	p = First;
  if (First==NULL ) return 0;
  while(First !=NULL && First->info ==sach ) {
        Delete_First(First);
  }
  if (First==NULL );
for ( p=First; p->next!=NULL ; )   
  if (p->next->info==sach ) {
		Delete_After(p);
	}
	else p=p->next;
}









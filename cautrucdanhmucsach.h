struct Sach{
	char masach[10];
	int trangthai;
	char vitri[10];
	
	Sach(){
		
	}
	
	Sach(char* ms, int tt, char* vt){
		strcpy(masach, ms);
		trangthai = tt;
		strcpy(vitri, vt);
	}
};

struct Nodesach{
	Sach sach;
	Nodesach *next;
};

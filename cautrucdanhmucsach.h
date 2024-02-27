struct Sach{
	std::string masach;
	int trangthai;
	std::string vitri;
	
	Sach(){
		
	}
	
	Sach(std::string ms, int tt, std::string vt){
		masach = ms;
		trangthai = tt;
		vitri = vt;
	}
};

struct NodeDMSach{
	Sach sach;
	NodeDMSach *next;
};

typedef struct NodeDMSach* dms;





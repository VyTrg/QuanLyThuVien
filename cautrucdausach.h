#define Max_DS_dausach 100
struct Dausach{
	std::string ISBN;
	std::string tensach;
	int sotrang;
	std::string tacgia;
	int nxb;
	std::string theloai;
	
	dms First = NULL;
	
	DauSach(){
		
	}
	
	DauSach(std::string isbn, std::string ten, int st, std::string tg, int xb, std::string tl){
		ISBN = isbn;
		tensach = ten;
		sotrang = st;
		tacgia = tg;
		nxb = xb;
		theloai = tl;
	}
};

struct DS_dausach{
	int n;
	Dausach *DSDS[Max_DS_dausach];
};


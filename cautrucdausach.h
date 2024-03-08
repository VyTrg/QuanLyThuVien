#define Max_DS_DauSach 100
struct DauSach{
	std::string ISBN;
	std::string tensach;
	int sotrang;
	std::string tacgia;
	int nxb;
	std::string theloai;
	
	Nodedms First = NULL;
};

struct DS_DauSach{
	int n = 0;
	DauSach *data[Max_DS_DauSach];
	
};


/*
them vao vi tri thich hop
them vao danh sach
*/

void AddDauSach(DS_DauSach &DSDS, DauSach *DauSach, int position);
void AddDauSach(DS_DauSach &DSDS, DauSach *DauSach);

void AddDauSach(DS_DauSach &DSDS, DauSach *DauSach, int position){
	if(position > DSDS.n){
		std::cout << "Vi tri them khong hop le, khong the them\n";
	}
	else{
				
	}
}

void AddDauSach(DS_DauSach &DSDS, DauSach *DauSach){
	if(DSDS.n > Max_DS_DauSach){
		std::cout << "Danh sach dau sach da day\n";
	}
	else{
	}
}

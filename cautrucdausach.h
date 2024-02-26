
struct Dausach{
	char ISBN[11];
	char tensach[23];
	int sotrang;
	char tacgia[13];
	int nxb;
	char theloai[13];
	
	Nodesach First = NULL;
	
	DauSach(){
		
	}
	
	DauSach(char *isbn, char* ten, int st, char* tg, int xb, char* tl){
		strcpy(ISBN, isbn);
		strcpy(tensach, ten);
		sotrang = st;
		strcpy(tacgia, tg);
		nxb = xb;
		strcpy(theloai, tl);
		First = NULL;
	}
};

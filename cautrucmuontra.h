struct MuonTra{
	char masach[6];
	std::string ngaymuon;
	std::string ngaytra;
	int trangthai;
};

struct NodeMuonTra{
	MuonTra muontra;
	NodeMuonTra *next;
	NodeMuonTra *previous;
};

typedef struct NodeMuonTra* Nodemt;

/*trang thai muon tra
 * dangmuon(chua tra) = 0
 * datra = 1
 * matsach = 2
 */
enum TrangThai_MT{
	DangMuon,//0
	DaTra,//1
	MatSach,//2
};

/*-------------------Prototype------------------*/

/*-------------------Function------------------*/

struct MuonTra{
	std::string masach;
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


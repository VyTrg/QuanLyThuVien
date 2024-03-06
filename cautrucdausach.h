//dau sach danh sach tuyen tinh 
// them vao 
void InsertDauSach
	}(DS_DauSach &DSDS, DauSach *dausach, int position){
	if(position < 0){
		printf("Vi tri them dau sach khong hop le \n");
		return;
	// neu position >= DSDS.n thi Insert vao cuoi danh sach
	for(int i=DSDS.n; i>position; i--){
		DSDS.nodes[i] = DSDS.nodes[i-1];
	}
	DSDS.nodes[position] = dausach;
	DSDS.n++; 
}

}
void InsertLastDauSach(DS_DauSach &DSDS, DauSach *dausach){
	// su dung khi doc file
	if(DSDS.n > MAX_SIZE_DAUSACH)
		printf("DSDS day \n");
	else{
		DSDS.nodes[DSDS.n++] = dausach;
	}
}

// phep loai bo 
void delete_item (DS_DauSach &DSDS, int position)
{
	int j;
	int temp;
	if(position <= 0 || position > DSDS.n)
		printf("Vi tri xoa khong phu hop.");
	else
		if(empty(DSDS))
			printf("Danh sach khong co phan tu.");
		else
		{
			for(j = position;  j< DSDS.n ; j++)
				plist.nodes[j-1] = plist.nodes[j];
				DSDS.n--;
		}
}



/*-------------------Prototype------------------*/

//tao file va ghi du lieu vao file
int WriteFile(Nodedms &First);//danh muc sach

//doc du lieu tu file
int ReadFile(Nodedms &First);

/*-------------------Function------------------*/
int WriteFile(Nodedms &First){
	FILE* file;
	file = fopen("dms.txt", "wb");
	if(file == NULL){
		std::cout << "Loi mo file\n";
		return 0;
	}
	else{
		std::cout << "Ghi file\n";
		for(Nodedms p = First ; p != NULL ; p = p->next)
			fwrite (&p->sach, sizeof (Sach), 1, file);
		fclose (file);
		return 1;
	}
}

int ReadFile(Nodedms &First){
	Nodedms p;  Sach sach ;
	FILE *file = fopen ("dms.txt", "rb");
	if(file == NULL){
		std::cout << "Loi mo file\n";
		return 0;
	}
	std::cout << "Da doc file\n";
	while (First != NULL) {
		p= First ; First = p->next ; delete p;
	}
	while(fread (&sach, sizeof (Sach), 1, file)== 1 ) 
	   InsertLast_NodeDMSach(First , sach); 
	fclose (file);
	return 1;  
}

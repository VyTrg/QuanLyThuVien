#pragma once
#ifndef CAUTRUCDAUSACH_H_INCLUDED
#define CAUTRUCDAUSACH_H_INCLUDED

#pragma once

#include "cautrucdanhmucsach.h"
//#include "cautrucmuontra.h"
//#include "cautructhedocgia.h"

#define Max_DS_DauSach 100
/*-------------------Prototype-Struct------------------*/
struct DauSach;
struct DS_DauSach;
struct NodeDMSach;
typedef struct NodeDMSach* Nodedms;

/*-------------------Struct------------------*/
struct DauSach {
	char ISBN[14];
	std::string tensach;
	int sotrang;
	std::string tacgia;
	int nxb;
	std::string theloai;

	Nodedms* First = NULL;
};

struct DS_DauSach {
	int n;
	DauSach* data[Max_DS_DauSach];

};

/*-------------------Prototype------------------*/

//them vao danh sach theo vi tri
void AddDauSach(DS_DauSach& DSDS, DauSach* DauSach, int position);

//them vao danh sach
void AddDauSach(DS_DauSach& DSDS, DauSach* DauSach);


/*-------------------Function------------------*/

void AddDauSach(DS_DauSach& DSDS, DauSach* DauSach, int position) {
	if (position > DSDS.n) {
		std::cout << "Vi tri them khong hop le, khong the them\n";
	}
	else {

	}
}

void AddDauSach(DS_DauSach& DSDS, DauSach* DauSach) {
	if (DSDS.n > Max_DS_DauSach) {
		std::cout << "Danh sach dau sach da day\n";
	}
	else {
	}
}

#endif 
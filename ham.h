#pragma once
#define M 10
std::string Ma = "000";
/*-------------------Prototype------------------*/
std::string sotudong();
//std::string MaSach(std::string ma);
std::string ChuanHoaMa(std::string tensach);
bool CheckTrung(std::string s, std::string t);
std::string ChuanHoaChuoi(std::string s);
int StringToInt(std::string s);
bool SoSanhChuoi(std::string s, std::string t);

//std::string LaySo(std::string s);
/*-------------------Function------------------*/
std::string ChuanHoaMa(std::string tensach) {
	std::string ma = "";

	bool check = true;
	int length = tensach.size();
	for (int i = 0; i < length; ++i) {
		if (tensach[i] == ' ')
			check = true;
		else if (tensach[i] != ' ' && check == true) {
			ma.push_back(toupper(tensach[i]));
			check = false;
		}
	}
	return ma;
}
//std::string MaSach(DS_DauSach &DSDS, int check) {
//	std::string masach = DSDS.data[check]->ISBN;
//	DSDS.data[check]->soluong++;
//	if (DSDS.data[check]->soluong < 10)
//		masach = masach + "00" + std::to_string(DSDS.data[check]->soluong);
//	else if(DSDS.data[check]->soluong >= 10 && DSDS.data[check]->soluong <= 99)
//		masach = masach + "0" + std::to_string(DSDS.data[check]->soluong);
//	else if(DSDS.data[check]->soluong >= 100)
//		masach = masach + std::to_string(DSDS.data[check]->soluong);
//	return masach;
//}

//std::string sotudong() {
//	int* a = new int[M];
//begin:
//	std::string m = "";
//	srand(time(NULL));
//	for (int i = 0; i < M; ++i) {
//		a[i] = i + 1;
//	}
//	for (int i = 0; i < 2; i++) {
//		int j = rand() % (M - i) + i; //j tu i den M-1
//		int tmp = a[i];
//		a[i] = a[j];
//		a[j] = tmp;
//	}
//	for (int i = 0; i < 2; i++) {
//		m += std::to_string(a[i]);
//	}
//;	delete[] a;
//	if (CheckTrung(Ma, m))
//		goto begin;
//	Ma = m;
//	return m;
//}

//string to integer
int StringToInt(std::string s)
{
	int i;
	// string -> integer
	std::istringstream(s) >> i;

	return i;
}

bool CheckTrung(std::string s, std::string t) {
	if (s.compare(t) == 0)
		return true;
	return false;
}

std::string ChuanHoaChuoi(std::string s) {
	for (int i = 1; i < s.length(); i++)
	{
		if (s[0] == ' ')
		{
			s.erase(0, 1);
			i--;
		}
		else if (s[i - 1] == ' ' && s[i] == ' ')
		{
			s.erase(i - 1, 1);
			i--;
		}
		else if (s[s.length() - 1] == ' ')
		{
			s.erase(s.length() - 1, 1);

		}
	}
	for (char& c : s) {
		c = toupper(c);
	}
	return s;
}

bool SoSanhChuoi(std::string s, std::string t) {//s: masach, t:isbn
	std::string temp = "";
	for (char& c : s) {
		if (c != '_')
			temp += c;
		else
			break;
	}
	//cout << temp << endl;
	if (temp.compare(t) == 0)
		return true;
	return false;
}

std::string TachMa(std::string masach) {
	std::string temp = "";
	for (char& c : masach) {
		if (c != '_')
			temp += c;
		else
			break;
	}
	return temp;
}



//std::string LaySo(std::string s) {
//	std::string so = "";
//	for (int i = s.size() - 1; i >= 0; --i) {
//		if (s[i] != '-')
//			so += s[i];
//		else
//			break;
//	}
//
//}

//bool CheckMaSach(Nodedms dms, std::string n) {
//	Nodedms temp = dms;
//	while (temp != NULL) {
//		if (LaySo(temp->sach.masach).compare(n) == 0) {
//			return false;
//		}
//		temp = temp->next;
//	}
//	return true;
//}
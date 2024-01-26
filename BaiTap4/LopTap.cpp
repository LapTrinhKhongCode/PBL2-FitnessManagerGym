#include "LopTap.h"

string LopTap::Getter_Max() {
	return Max;
}
string LopTap::Getter_TenLop() {
	return TenLop;
}

string LopTap::Getter_MaGVQL() {
	return MaGVQuanLy;
}

void LopTap::Setter_maGVQL(string a) {
	MaGVQuanLy = a;
}
int LopTap::Getter_slhv() {
	return slhv;
}
void LopTap::Setter_slhv(int a) {
	slhv = a;
}
void LopTap::Setter_ThoiGian(string a) {
	ThoiGian = a; 
}
void LopTap::Setter_MaLop(string a) {
	MaLop = a;
}
void LopTap::Setter_Max(string a) {
	Max = a; 
}

float LopTap::Getter_HP1Thang() {
	return HP1Thang;
}
void LopTap::Setter_HP1Thang(float a) {
	HP1Thang = a;
}

void LopTap::DocFile(string FullDong){
	stringstream ss(FullDong);
	//string temp;
	//getline(ss, temp, '|');
	//int spaceIndex = temp.find_last_of(" ");
	getline(ss, MaLop, '|');
	getline(ss, TenLop, '|');
	getline(ss, ThoiGian, '|');
	getline(ss, MaGVQuanLy, '|');
	string temp;
	getline(ss, Max, '|');
	getline(ss, temp, '\0');
	HP1Thang = stof(temp);
	//temp.clear();
}
string LopTap::Getter_MaLT() {
	return MaLop;
}
string LopTap::Getter_ThoiGian() {
	return ThoiGian;
}

void LopTap::ThemLop() {
	cout << "\nNhap ten lop: ";
	rewind(stdin);
	getline(cin, TenLop);
	cout << "\nNhap so luong toi da cua lop: ";
	rewind(stdin);
	getline(cin, Max);
	cout << "\nNhap hoc phi 1 thang: ";
	cin >> HP1Thang;

	//cout << "\nNhap ma giao vien day lop: ";
	//string temp;
	//getline(cin, temp);

	//for (int i = 0; i < slkh; ++i) {
	//	if (DS[i].Getter_MaKH() == a) {
	//		//cout << "\nMa khach hang bi trung lap voi khach hang khac, vui long kiem tra lai...";
	//		return false;
	//	}
	//}
	//return true;

}


void LopTap::XuatLop() {
	cout << setw(14) << TenLop << setw(9) << MaLop << setw(10) << Max 
		<< setw(15) << ThoiGian << setw(15) << MaGVQuanLy << fixed << setprecision(0) << HP1Thang << endl;
}
void LopTap::XoaLop() {
	TenLop.erase();
	ThoiGian.erase();
	MaLop.erase();
	Max.erase();
	MaGVQuanLy.erase();
	delete DanhSachMaKH;
}
void LopTap::SuaLop() {

}

void LopTap::XoaKHtrongLT(string a) {
	for (int i = 0; i < stoi(Max); i++) {
		if (DanhSachMaKH[i] == a ) {
			DanhSachMaKH[i].erase();
		}
	}
}


void LopTap::ThemKHtrongLT(string a) {
	for (int i = 0; i < stoi(Max); i++) {
		if (DanhSachMaKH[i] == a) {
			DanhSachMaKH[i].erase();
		}
	}
}














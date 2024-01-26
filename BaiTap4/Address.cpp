#include "Address.h"


std::string TryCatchStringTenDC(std::string chuoi) {
	std::string test = chuoi;
cannhaplai:
	std::cout << "\nNhap " << test << ": ";
	rewind(stdin);
	getline(std::cin, chuoi);
	stringstream ss(chuoi);
	string word;
	string a;
	while (ss >> word) {
		a += word + ' ';
	}
	chuoi = a;
	chuoi.resize(chuoi.length() - 1);
	if (chuoi[0] < 'A' || chuoi[0] > 'Z') {
		std::cout << "\nVui long nhap lai " << test << " theo dung dinh dang(chu cai dau viet hoa, con lai viet thuong)...\n";
		goto cannhaplai;
	}
	for (int i = 1; i < chuoi.length(); i++) {
		if (chuoi[i] == ' ') {
			return chuoi;
		}
		if (chuoi[i] < 'a' || chuoi[i] > 'z') {
			std::cout << "\nVui long nhap lai " << test << " theo dung dinh dang(chu cai dau viet hoa, con lai viet thuong)...\n";
			goto cannhaplai;
		}
	}
	return chuoi;
}


void Address::Setter_DiaChiCuThe(string a) {
	DiaChiCuThe = a;
}

void Address::Setter_XaPhuongThitran(string b) {
	XaPhuongThitran = b;
}

void Address::Setter_QuanHuyen(string c) {
	QuanHuyen = c;
}
void Address::Setter_TinhTPtw(string d) {
	TinhTPtw = d;
}

string Address::Getter_AllAdress() {
	return DiaChiCuThe + ',' + XaPhuongThitran + ',' + QuanHuyen + ',' + TinhTPtw;
}



void Address::Nhap() {
	TinhTPtw = TryCatchStringTenDC("Tinh/TPtw");
	QuanHuyen = TryCatchStringTenDC("Quan/Huyen");
	XaPhuongThitran = TryCatchStringTenDC("Xa/Phuong/Thitran");
	DiaChiCuThe = TryCatchStringTenDC("Dia Chi Cu The");
}

void Address::Xuat() {
	cout << setw(75) << Getter_AllAdress();
}

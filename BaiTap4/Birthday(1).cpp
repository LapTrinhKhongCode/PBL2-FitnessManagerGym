#include "BirthDay.h"


string TryCatchNgaySinh() {
	//số 0 ở đầu chưa làm
cannhaplai:
	cout << "\nNhap ngay sinh: ";
	string ngay;
	rewind(stdin);
	getline(std::cin, ngay);
	if (ngay[0] <= '0' || ngay[0] > '9') {
		std::cout << "\nVui long nhap lai ngay sinh: ";
		goto cannhaplai;
	}
	for (int i = 1; i < ngay.length(); i++) {
		if (ngay[i] <= '0' || ngay[i] > '9') {
			std::cout << "\nVui long nhap lai ngay sinh: ";
			goto cannhaplai;
		}
	}
	stringstream ss(ngay);
	int ngaysinh;
	ss >> ngaysinh;
	if (31 < ngaysinh || ngaysinh <= 0) {
		std::cout << "\nVui long nhap lai ngay sinh: ";
		goto cannhaplai;
	}
	ss << ngaysinh;
	ngay = ss.str();
	return ngay;
}

string TryCatchThangSinh() {
	//số 0 ở đầu chưa làm
cannhaplai:
	cout << "\nNhap thang sinh: ";
	string thang;
	rewind(stdin);
	getline(std::cin, thang);
	if (thang[0] <= '0' || thang[0] > '9') {
		std::cout << "\nVui long nhap lai thang sinh: ";
		goto cannhaplai;
	}
	for (int i = 1; i < thang.length(); i++) {
		if (thang[i] < '0' || thang[i] > '9') {
			std::cout << "\nVui long nhap lai thang sinh: ";
			goto cannhaplai;
		}
	}
	stringstream ss(thang);
	int thangsinh;
	ss >> thangsinh;
	if (12 < thangsinh || thangsinh <= 0) {
		std::cout << "\nVui long nhap lai thang sinh: ";
		goto cannhaplai;
	}
	ss << thangsinh;
	thang = ss.str();
	return thang;
}

string TryCatchNamSinh() {
	//số 0 ở đầu chưa làm
cannhaplai:
	cout << "\nNhap nam sinh: ";
	string nam;
	rewind(stdin);
	getline(std::cin, nam);
	if (nam[0] < '0' || nam[0] > '9') {
		std::cout << "\nVui long nhap lai nam sinh: ";
		goto cannhaplai;
	}
	for (int i = 1; i < nam.length(); i++) {
		if (nam[i] < '0' || nam[i] > '9') {
			std::cout << "\nVui long nhap lai nam sinh: ";
			goto cannhaplai;
		}
	}
	stringstream ss(nam);
	int namsinh;
	ss >> namsinh;
	if (2023 < namsinh || namsinh <= 0) {
		std::cout << "\nVui long nhap lai nam sinh: ";
		goto cannhaplai;
	}
	ss << namsinh;
	nam = ss.str();
	return nam;
}





void Birthday::Setter_Ngay(string day) {
	Ngay = day;
}
void Birthday::Setter_Thang(string month) {
	Thang = month;
}
void Birthday::Setter_Nam(string year) {
	Nam = year;
}

void Birthday::Nhap() {
	Ngay = TryCatchNgaySinh();
	Thang = TryCatchThangSinh();
	Nam = TryCatchNamSinh();
}


void Birthday::Xuat() {
	cout << Ngay << "/" << Thang << "/" << Nam;
}


string Birthday::Getter_Ngay() {
	return Ngay;
}

string Birthday::Getter_Thang() {
	return Thang;

}

string Birthday::Getter_Nam() {
	return Nam;
}
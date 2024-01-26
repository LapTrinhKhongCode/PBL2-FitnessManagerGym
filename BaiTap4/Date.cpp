#include "Date.h"


string TryCatchNgaySinh() {
	//số 0 ở đầu chưa làm
cannhaplai:
	cout << "\nNhap ngay: ";
	string ngay;
	rewind(stdin);
	getline(std::cin, ngay);
	if (ngay[0] <= '0' || ngay[0] > '9') {
		std::cout << "\nVui long nhap lai ngay : ";
		goto cannhaplai;
	}
	for (int i = 1; i < ngay.length(); i++) {
		if (ngay[i] <= '0' || ngay[i] > '9') {
			std::cout << "\nVui long nhap lai ngay : ";
			goto cannhaplai;
		}
	}
	stringstream ss(ngay);
	int ngaysinh;
	ss >> ngaysinh;
	if (31 < ngaysinh || ngaysinh <= 0) {
		std::cout << "\nVui long nhap lai ngay : ";
		goto cannhaplai;
	}
	ss << ngaysinh;
	ngay = ss.str();
	return ngay;
}

string TryCatchThangSinh() {
	//số 0 ở đầu chưa làm
cannhaplai:
	cout << "\nNhap thang : ";
	string thang;
	rewind(stdin);
	getline(std::cin, thang);
	if (thang[0] <= '0' || thang[0] > '9') {
		std::cout << "\nVui long nhap lai thang : ";
		goto cannhaplai;
	}
	for (int i = 1; i < thang.length(); i++) {
		if (thang[i] < '0' || thang[i] > '9') {
			std::cout << "\nVui long nhap lai thang : ";
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
	cout << "\nNhap nam : ";
	string nam;
	rewind(stdin);
	getline(std::cin, nam);
	if (nam[0] < '0' || nam[0] > '9') {
		std::cout << "\nVui long nhap lai nam : ";
		goto cannhaplai;
	}
	for (int i = 1; i < nam.length(); i++) {
		if (nam[i] < '0' || nam[i] > '9') {
			std::cout << "\nVui long nhap lai nam : ";
			goto cannhaplai;
		}
	}
	stringstream ss(nam);
	int namsinh;
	ss >> namsinh;
	if (2023 < namsinh || namsinh <= 0) {
		std::cout << "\nVui long nhap lai nam : ";
		goto cannhaplai;
	}
	ss << namsinh;
	nam = ss.str();
	return nam;
}





void Date::Setter_Ngay(string day) {
	Ngay = day;
}
void Date::Setter_Thang(string month) {
	Thang = month;
}
void Date::Setter_Nam(string year) {
	Nam = year;
}

void Date::Nhap() {
	Ngay = TryCatchNgaySinh();
	Thang = TryCatchThangSinh();
	cout << "\nNhap Nam: ";
	cin >> Nam;
	//Nam = TryCatchNamSinh();
}


void Date::Xuat() {
	cout << Ngay << "/" << Thang << "/" << Nam;
}


string Date::Getter_Ngay() {
	return Ngay;
}

string Date::Getter_Thang() {
	return Thang;

}

string Date::Getter_Nam() {
	return Nam;
}
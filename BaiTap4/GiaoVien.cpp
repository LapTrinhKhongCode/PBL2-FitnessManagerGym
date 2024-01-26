#include "GiaoVien.h"

void ThongTinGiaoVien::DocFile(string FullDong) {
	stringstream ss(FullDong);
	string temp;
	getline(ss, temp, '|');
	int spaceIndex = temp.find_last_of(" ");

	Ho = temp.substr(0, spaceIndex);
	Ten = temp.substr(spaceIndex + 1);
	temp.clear();
	//cout << "ok";
	getline(ss, temp, '/');
	NgaySinh.Setter_Ngay(temp);
	temp.clear();

	getline(ss, temp, '/');
	NgaySinh.Setter_Thang(temp);
	temp.clear();

	getline(ss, temp, '|');
	NgaySinh.Setter_Nam(temp);
	temp.clear();

	getline(ss, GioiTinh, '|');
	getline(ss, SDT, '|');

	getline(ss, temp, ',');
	temp.erase(temp.begin());
	DiaChi.Setter_DiaChiCuThe(temp);
	temp.clear();

	getline(ss, temp, ',');
	DiaChi.Setter_XaPhuongThitran(temp);
	temp.clear();

	getline(ss, temp, ',');
	DiaChi.Setter_QuanHuyen(temp);
	temp.clear();

	getline(ss, temp, '|');
	temp.erase(temp.end() - 1);
	DiaChi.Setter_TinhTPtw(temp);
	temp.clear();

	getline(ss, Email, '|');	
	getline(ss, MaGiaoVien, '|');
	string temp1;
	getline(ss, temp1, '|');
	Luong1Thang = stof(temp1);
	temp.clear();

	getline(ss, temp, '/');
	NgayBatDau.Setter_Ngay(temp);
	temp.clear();

	getline(ss, temp, '/'); 
	NgayBatDau.Setter_Thang(temp); 
	temp.clear(); 

	getline(ss, temp, '\0'); 
	NgayBatDau.Setter_Nam(temp);  
	temp.clear(); 
}

string ThongTinGiaoVien::Getter_NamBatDau() {
	return NgayBatDau.Getter_Nam();
}
string ThongTinGiaoVien::Getter_ThangBatDau() {
	return NgayBatDau.Getter_Thang();

}

string ThongTinGiaoVien::Getter_AllNgayBatDau() {
	return this->NgayBatDau.Getter_Ngay() + "/" + this->NgayBatDau.Getter_Thang() + "/" + this->NgayBatDau.Getter_Nam();
}

void ThongTinGiaoVien::XuatFile() {
	ofstream file("DANHSACHGIAOVIEN.TXT", ios_base::app);

	if (file.is_open()) {
		//demo
		//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";
		file.close();
	}
	else {
		std::cout << "Khong the mo file.\n";
	}
	file.close();
}
std::string TryCatchStringGV(std::string chuoi) {
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
			i++;
			if (chuoi[i] < 'A' || chuoi[i] > 'Z') {
				std::cout << "\nVui long nhap lai " << test << " theo dung dinh dang(chu cai dau viet hoa, con lai viet thuong)...\n";
				goto cannhaplai;
			}
			i++;
		}
		if (chuoi[i] < 'a' || chuoi[i] > 'z') {
			std::cout << "\nVui long nhap lai " << test << " theo dung dinh dang(chu cai dau viet hoa, con lai viet thuong)...\n";
			goto cannhaplai;
		}
	}
	return chuoi;
}


std::string TryCatchTuoiSoNguyenGV() {
cannhaplai:
	std::cout << "\nNhap tuoi: ";
	std::string tuoi;
	rewind(stdin);
	getline(std::cin, tuoi);
	if (tuoi[0] <= '0' || tuoi[0] > '9') {
		std::cout << "\nVui long nhap lai tuoi: ";
		goto cannhaplai;
	}
	for (int i = 1; i < tuoi.length(); i++) {
		if (tuoi[i] <= '0' || tuoi[i] > '9') {
			std::cout << "\nVui long nhap lai tuoi: ";
			goto cannhaplai;
		}
	}
	return tuoi;
}

std::string TryCatchStringTenGV(std::string chuoi) {
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

void ThongTinGiaoVien::Nhap() {
	Ho = TryCatchStringGV("ho");

	Ten = TryCatchStringTenGV("ten");

	GioiTinh = TryCatchStringGV("gioi tinh");

	NgaySinh.Nhap();

	//DiaChi.Nhap();
	DiaChi.Setter_DiaChiCuThe("Mornachy");
	DiaChi.Setter_TinhTPtw("Da Nang");
	DiaChi.Setter_QuanHuyen("Son Tra");
	DiaChi.Setter_XaPhuongThitran("An Hai Tay");

	cout << "\nNhap Ngay Bat Dau: ";
	NgayBatDau.Nhap();

	/*SDT = "0965264108";
	Email = "dvda06@gmail.com";
	MaGiaoVien = "GV004";*/
	cout << "\nNhap Luong: ";
	cin >> Luong1Thang;
	SDT = "0965264108";
	Email = "dvda06@gmail.com";
	//cout << "\n" << Ho;
	//cout << "\n" << Ten;
	//cout << "\n" << GioiTinh << "\n";
	//NgaySinh.Xuat();
	//cout << "\n" << DiaChi.Getter_AllAdress();
	//cout << "\n" << SDT;
	//cout << "\n" << Email;
	//GoiTap = TryCatchGoiTap();
	//cần tránh SDT,Email trùng nhau
}

void ThongTinGiaoVien::Xuat() {
	//cout << "\n----------------------------------------------------------------------------";

	cout << setw(14) << Ho << setw(9) << Ten;
	NgaySinh.Xuat();
	cout << "     " << setw(12) << GioiTinh << setw(15) << SDT;

	DiaChi.Xuat();
	cout << setw(20) << Email << setw(10) << MaGiaoVien;
	NgayBatDau.Xuat();
	cout << "     " << fixed << setprecision(0) << Luong1Thang << endl;
}

string ThongTinGiaoVien::Getter_SDT() {
	return SDT;
}

string ThongTinGiaoVien::Getter_Email() {
	return Email;
}

string ThongTinGiaoVien::Getter_Name() {
	return Ho +" "+ Ten;
}

string ThongTinGiaoVien::Getter_Ten() {
	return Ten;
}

string ThongTinGiaoVien::Getter_MaGV() {
	return MaGiaoVien;
}

string ThongTinGiaoVien::Getter_GioiTinh() {
	return GioiTinh;
}

string ThongTinGiaoVien::Getter_NgaySinh() {
	return this->NgaySinh.Getter_Ngay() + "/" + this->NgaySinh.Getter_Thang() + "/" + this->NgaySinh.Getter_Nam();
}

string ThongTinGiaoVien::Getter_DiaChi() {
	return this->DiaChi.Getter_AllAdress();
}
void ThongTinGiaoVien::Setter_Ho(string s) {
	Ho = s;
}

void ThongTinGiaoVien::Setter_Ten(string s) {
	Ten = s;
}

void ThongTinGiaoVien::Setter_GioiTinh(string s) {
	GioiTinh = s;
}

void ThongTinGiaoVien::Setter_Email(string s) {
	Email = s;
}

void ThongTinGiaoVien::Setter_SDT(string s) {
	SDT = s;
}

void ThongTinGiaoVien::Setter_MaGiaoVien(string s) {
	MaGiaoVien = s;
}

void ThongTinGiaoVien::Setter_NgaySinh(string a) {
	NgaySinh.Setter_Ngay(a);
}

void ThongTinGiaoVien::Setter_ThangSinh(string a) {
	NgaySinh.Setter_Thang(a);
}

void ThongTinGiaoVien::Setter_NamSinh(string a) {
	NgaySinh.Setter_Nam(a);
}

void ThongTinGiaoVien::Setter_DiaChiCuThe(string a) {
	DiaChi.Setter_DiaChiCuThe(a);
}
void ThongTinGiaoVien::Setter_XaPhuongThitran(string a) {
	DiaChi.Setter_XaPhuongThitran(a);
}
void ThongTinGiaoVien::Setter_QuanHuyen(string a) {
	DiaChi.Setter_QuanHuyen(a);
}
void ThongTinGiaoVien::Setter_TinhTPtw(string a) {
	DiaChi.Setter_TinhTPtw(a);
}

void ThongTinGiaoVien::Xoa() {
	Ho.erase();
	Ten.erase();
	GioiTinh.erase();
	NgaySinh.Setter_Ngay("");
	NgaySinh.Setter_Thang("");
	NgaySinh.Setter_Nam("");
	DiaChi.Setter_XaPhuongThitran("");
	DiaChi.Setter_QuanHuyen("");
	DiaChi.Setter_DiaChiCuThe("");
	DiaChi.Setter_TinhTPtw("");
	SDT.erase();
	Email.erase();
	MaGiaoVien.erase();
}

float ThongTinGiaoVien::Getter_LuongGV() {
	return Luong1Thang;
}

void ThongTinGiaoVien::Setter_LuongGV(float a) {
	Luong1Thang = a;
}

//
//void DanhSachGiaoVien::Setter_SLGV(int) {
//
//}
//void DanhSachGiaoVien::Nhap() {
//
//}
//void DanhSachGiaoVien::DocFile() {
//
//}
//void DanhSachGiaoVien::XuatFile() {
//
//}
//void DanhSachGiaoVien::Xuat() {
//
//}
//bool DanhSachGiaoVien::KiemTraEmailTrungLap(string) {
//
//}
//bool DanhSachGiaoVien::KiemTraSDTTrungLap(string) {
//
//}
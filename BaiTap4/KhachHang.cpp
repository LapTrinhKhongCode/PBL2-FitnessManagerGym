#include "KhachHang.h"

std::string TryCatchString(std::string chuoi) {
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
		if (chuoi[i]==' ') {
			i++;
			if (chuoi[i] < 'A' || chuoi[i] > 'Z' ) {
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


std::string TryCatchTuoiSoNguyen() {
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

std::string TryCatchStringTen(std::string chuoi) {
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

string TryCatchGoiTap() {
cannhaplai:
	cout << "\nNhap goi tap(1 thang/3 thang/6 thang/12 thang): ";
	string goitap;
	rewind(stdin);
	getline(cin, goitap);
	if (goitap == "1 thang"|| goitap == "3 thang"|| goitap == "6 thang"|| goitap == "12 thang") {
		return goitap;
	}
	cout << "\nVui long nhap lai loai goi tap(1 thang/3 thang/6 thang/12 thang)... ";
	goto cannhaplai;
}

string ThongTinKhachHang::Getter_Ten() {
	return Ten;
}
string ThongTinKhachHang::Getter_Name() {
	return Ho + " " + Ten;
}
string ThongTinKhachHang::Getter_MaKH() {
	return MaKhachHang;
}
string ThongTinKhachHang::Getter_SDT() {
	return SDT;
}
string ThongTinKhachHang::Getter_Email() {
	return Email;
}

string ThongTinKhachHang::Getter_LopTap() {
	return LopTap;
}

void ThongTinKhachHang::Nhap() {
	Ho = TryCatchString("ho");

	Ten = TryCatchStringTen("ten");

	GioiTinh = TryCatchString("gioi tinh");

	NgaySinh.Nhap();

	//DiaChi.Nhap();
	//Ho = "Do Van Duc";
	//Ten = "Anh";
	//GioiTinh = "Nam";
	//NgaySinh.Setter_Ngay("25");
	//NgaySinh.Setter_Thang("10");
	//NgaySinh.Setter_Nam("2004");
	DiaChi.Setter_DiaChiCuThe("Mornachy");
	DiaChi.Setter_TinhTPtw("Da Nang");
	DiaChi.Setter_QuanHuyen("Son Tra");
	DiaChi.Setter_XaPhuongThitran("An Hai Tay");
	//SDT = "0965264108";
	//Email = "dvda06@gmail.com";
	//MaKhachHang = "KH013";
	cout << "\nNhap ngay bat dau:";
	//rewind(stdin);
	NgayBatDau.Nhap();
	cout << "\nNhap ngay ket thuc:";
	//rewind(stdin);
	NgayKetThuc.Nhap();
	

	

	//cout << "\n" << Ho;
	//cout << "\n" << Ten;
	//cout << "\n" << GioiTinh<<"\n";
	//NgaySinh.Xuat();
	//cout <<"\n"<< DiaChi.Getter_AllAdress();
	//cout << "\n" << SDT;
	//cout << "\n" << Email;
	//GoiTap = TryCatchGoiTap();
	//cần tránh SDT,Email trùng nhau
}

void ThongTinKhachHang::Setter_Ho(string s) {
	Ho = s;
}
void ThongTinKhachHang::Setter_Ten(string s) {
	Ten = s;
}
void ThongTinKhachHang::Setter_GioiTinh(string s) {
	GioiTinh = s;
}
void ThongTinKhachHang::Setter_Email(string s) {
	Email = s;
}
void ThongTinKhachHang::Setter_SDT(string s) {
	SDT = s;
}
void ThongTinKhachHang::Setter_MaKhachHang(string s) {
	MaKhachHang = s;
}

string ThongTinKhachHang::Getter_AllNgayBatDau() {
	return this->NgayBatDau.Getter_Ngay() + "/" + this->NgayBatDau.Getter_Thang() + "/" + this->NgayBatDau.Getter_Nam();
}

string ThongTinKhachHang::Getter_AllNgayKetThuc() {
	return this->NgayKetThuc.Getter_Ngay() + "/" + this->NgayKetThuc.Getter_Thang() + "/" + this->NgayKetThuc.Getter_Nam();
}

string ThongTinKhachHang::Getter_ThangBatDau() {
	return NgayBatDau.Getter_Thang();
}
string ThongTinKhachHang::Getter_NamBatDau() {
	return NgayBatDau.Getter_Nam();
}
string ThongTinKhachHang::Getter_ThangKetThuc() {
	return NgayKetThuc.Getter_Thang();
}
string ThongTinKhachHang::Getter_NamKetThuc() {
	return NgayKetThuc.Getter_Nam();
}

void ThongTinKhachHang::Xuat() {
	//cout << "\n----------------------------------------------------------------------------";

	cout << setw(14) << Ho << setw(9) << Ten;
	NgaySinh.Xuat();
	cout << "     " << setw(12) << GioiTinh << setw(15) << SDT;

	DiaChi.Xuat();
	cout << setw(20) << Email << setw(10) << MaKhachHang; 
	
	NgayBatDau.Xuat();
	cout << "\t ";
	//cout << setw(15) ;
	NgayKetThuc.Xuat();
	cout << "\t";
	cout << setw(10) << LopTap << endl;
	
	

}

void ThongTinKhachHang::Xoa() {
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
	MaKhachHang.erase();


}



void ThongTinKhachHang::Sua() {

}

void ThongTinKhachHang::XuatFile() {

	//ofstream file("DANHSACHKHACHHANG1.TXT", ios_base::app);

	//if (file.is_open()) {
	//	//demo
	//	//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";

	//	file << this->Getter_Name() << "|" << this->Getter_NgaySinh() << this->Getter_GioiTinh() << "|" <<
	//		this->Getter_SDT() << "|\"" << this->Getter_DiaChi() << "\"|" << this->Getter_Email() << "|" << this->Getter_MaKH();


	//	file.close();
	//}
	//else {
	//	std::cout << "Khong the mo file.\n";
	//}
	//file.close();
}
string ThongTinKhachHang::Getter_NgaySinh() {
	return this->NgaySinh.Getter_Ngay() + "/" + this->NgaySinh.Getter_Thang() + "/" + this->NgaySinh.Getter_Nam();
}



string ThongTinKhachHang::Getter_GioiTinh() {
	return GioiTinh;
}

string ThongTinKhachHang::Getter_DiaChi() {
	return this->DiaChi.Getter_AllAdress();
}

void ThongTinKhachHang::Setter_NgayBatDau(string a) {
	NgayBatDau.Setter_Ngay(a);
}

void ThongTinKhachHang::Setter_ThangBatDau(string a) {
	NgayBatDau.Setter_Thang(a);
}
void ThongTinKhachHang::Setter_NamBatDau(string a) {
	NgayBatDau.Setter_Nam(a);
}


void ThongTinKhachHang::Setter_NgayKetThuc(string a) {
	NgayKetThuc.Setter_Ngay(a);
}

void ThongTinKhachHang::Setter_ThangKetThuc(string a) {
	NgayKetThuc.Setter_Thang(a);
}

void ThongTinKhachHang::Setter_NamKetThuc(string a) {
	NgayKetThuc.Setter_Nam(a);
}


void ThongTinKhachHang::Setter_LopTap(string a) {
	LopTap = a;
}

void ThongTinKhachHang::Setter_NgaySinh(string a) {
	NgaySinh.Setter_Ngay(a);
}

void ThongTinKhachHang::Setter_ThangSinh(string a) {
	NgaySinh.Setter_Thang(a);
}
void ThongTinKhachHang::Setter_NamSinh(string a) {
	NgaySinh.Setter_Nam(a);
}


void ThongTinKhachHang::Setter_DiaChiCuThe(string a) {
	DiaChi.Setter_DiaChiCuThe(a);
}
void ThongTinKhachHang::Setter_XaPhuongThitran(string a) {
	DiaChi.Setter_XaPhuongThitran(a);
}
void ThongTinKhachHang::Setter_QuanHuyen(string a) {
	DiaChi.Setter_QuanHuyen(a);
}
void ThongTinKhachHang::Setter_TinhTPtw(string a) {
	DiaChi.Setter_TinhTPtw(a);
}
void ThongTinKhachHang::DocFile(string FullDong) {
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
		getline(ss, MaKhachHang, '|');

		//temp.clear();
		//cout << "ok";
		getline(ss, temp, '/');
		NgayBatDau.Setter_Ngay(temp);
		temp.clear();

		getline(ss, temp, '/');

		NgayBatDau.Setter_Thang(temp);
		temp.clear();

		getline(ss, temp, '|');
		NgayBatDau.Setter_Nam(temp);
		//cout << "\n" << temp;

		temp.clear();

		getline(ss, temp, '/');
		//cout << "\n" << temp;

		NgayKetThuc.Setter_Ngay(temp);
		temp.clear();

		getline(ss, temp, '/');
		NgayKetThuc.Setter_Thang(temp);
		//cout << "\n" << temp;

		temp.clear();
		//cout << "\n" << temp;

		getline(ss, temp, '|');
		NgayKetThuc.Setter_Nam(temp);
		temp.clear();
		//getline(ss, NgayBatDau, '|');
		//getline(ss, NgayKetThuc, '|');
		getline(ss, LopTap, '\0');

		//getline(ss, GoiTap, '\0');	
}






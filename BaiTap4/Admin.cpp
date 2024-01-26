#include "Admin.h"

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void Admin::GioiThieu() {
	ifstream FileIn;
	FileIn.open("MODAU.TXT");

	while (!FileIn.eof()) {		
		if (_kbhit()) {
			char c;
			FileIn.get(c);	
			textcolor(14);
			cout << c;
		}
		else {
			char c;
			FileIn.get(c);
			Sleep(50);
			textcolor(14);
			cout << c;
		}
	}
	cout << "\n\n";
	textcolor(7);
}


float Admin::TinhTongLuongGiaoVien1Thang() {
	float Luong1thang = 0;
	for (int i = 0; i < slgv; i++) {
		Luong1thang += (DanhSachGV[i].Getter_LuongGV());
	}
	return Luong1thang;
}

float  Admin::TinhTongLuongGiaoVienTheoTime(string a, string b) {
	float Luong = 0;
	for (int i = 0; i < slgv; i++) {
		for (int j = 0; j < sllt; j++) {
			if (DanhSachGV[i].Getter_NamBatDau() == b) {
				if (DanhSachGV[i].Getter_ThangBatDau() <= a)
					Luong += DanhSachGV[j].Getter_LuongGV();
			}
			else if (DanhSachGV[i].Getter_NamBatDau() < b) {
				Luong += DanhSachGV[j].Getter_LuongGV();
				//5/2023 6/2024

			}


		}
	}
	return Luong;
}


float  Admin::TinhTongDoanhThuTheoTime(string a , string b) {

	// 
	float DT = 0;
	for (int i = 0; i < slkh; i++) {
		for (int j = 0; j < sllt; j++) {
			if (DanhSachKH[i].Getter_NamBatDau() == b && DanhSachKH[i].Getter_LopTap() == DanhSachLT[j].Getter_MaLT()) {
				if (DanhSachKH[i].Getter_ThangBatDau() <= a)
				DT += DanhSachLT[j].Getter_HP1Thang();
			}
			else if (DanhSachKH[i].Getter_NamBatDau() < b && DanhSachKH[i].Getter_LopTap() == DanhSachLT[j].Getter_MaLT()) {
				DT += DanhSachLT[j].Getter_HP1Thang();
				//5/2023 6/2024

			}
			
			
		}
	}
	return DT;

}
float Admin::TinhTongDoanhThu1Thang() {
	cout << "\nNhap thang: ";
	string a;
	cin >> a;
	cout << "\nNhap nam: ";
	string b;
	cin >> b;
	float DT1thang = 0;
	for (int i = 0; i < slkh; i++) {
		for (int j = 0; j < sllt; j++) {
			if (DanhSachKH[i].Getter_NamBatDau() == b && DanhSachKH[i].Getter_ThangBatDau() == a 
				&& DanhSachKH[i].Getter_LopTap() == DanhSachLT[j].Getter_MaLT()) {
				DT1thang += DanhSachLT[j].Getter_HP1Thang();
			}
		}
	}
	return DT1thang;
}

bool compareByNameKH(ThongTinKhachHang a, ThongTinKhachHang b) {
	return a.Getter_Ten() < b.Getter_Ten();
}

bool compareByNameGV(ThongTinGiaoVien a, ThongTinGiaoVien b) {
	return a.Getter_Ten() < b.Getter_Ten();
}

// Hàm so sánh theo tuổi
bool compareByMKH(ThongTinKhachHang a, ThongTinKhachHang b) {
	return a.Getter_MaKH() < b.Getter_MaKH();
}

bool compareByMGV(ThongTinGiaoVien a, ThongTinGiaoVien b) {
	return a.Getter_MaGV() < b.Getter_MaGV();
}

void Admin::SapXepKhachHangTheoTen() {
	sort(DanhSachKH, DanhSachKH + slkh, compareByNameKH);
	this->XuatKH();
}

void Admin::SapXepKhachHangTheoMaKH() {
	sort(DanhSachKH, DanhSachKH + slkh, compareByMKH);
	this->XuatKH();
}

void Admin::TimKiemKH() {
	cout << "\nNhap ky tu tim kiem: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	bool check = false;
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaKH " << endl;
	for (int i = 0; i < slkh; i++) {
		if (DanhSachKH[i].Getter_Name().find(a) != string::npos) {
			DanhSachKH[i].Xuat();
			check = true;
		}
		else if (DanhSachKH[i].Getter_MaKH().find(a) != string::npos) {
			DanhSachKH[i].Xuat();
			check = true;
		}
	}
	if (check == false) {
		cout << "Khong tim thay khach hang...";
	}
}

//double Admin::TinhDoanhThu() {
//	double Tong; 
//
//	return Tong;
//}

void Admin::Menu(int p) {
	int luachon;
	do {
	ReturnPoint:
		textcolor(12);
		cout << "\n--------------------Menu--------------------";
		cout << "\n1. Khach Hang";
		cout << "\n2. Giao Vien";
		cout << "\n3. Lop Tap";
		cout << "\n4. Doanh Thu";
		cout << "\n0. Thoat";
		cout << "\n--------------------------------------------\n";
		textcolor(7);
		cout << "\nNhap vao lua chon cua ban: ";
		cin >> luachon;
		system("cls");
		if (luachon == 1) {
		KH:
			this->XuatKH();
			cout << "\n-----------------Khach Hang-----------------";
			//cout << "\n1. Xem Danh Sach";
			cout << "\n2. Them";
			cout << "\n3. Xoa";
			cout << "\n4. Sua";
			cout << "\n5. Tim Kiem";
			cout << "\n6. Sap Xep";
			cout << "\n0. Quay Lai";
			cout << "\n--------------------------------------------\n";
			int luachonkh;
			cin >> luachonkh;
			if (luachonkh == 0) goto ReturnPoint;
			else if (luachonkh == 1) {
				this->XuatKH();
			}
			else if (luachonkh == 2 && p != 2) {
				this->NhapKH();
			}
			else if (luachonkh == 3 && p != 2) {
				cout << "\n---------------Xoa Khach Hang---------------";
				cout << "\n1. Theo Ma Khach Hang";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonxkh;
				cin >> luachonxkh;
				if (luachonxkh == 1) {
					this->XoaKH();
				}
				else if (luachonxkh == 0) {
					goto KH;
				}
			}
			else if (luachonkh == 4 && p != 2) {

				int j = this->SuaKH();
				if (j == -1) {
					goto KH;
				}

				cout << "\n---------------Sua Khach Hang---------------";
				cout << "\n1. Sua Ho";
				cout << "\n2. Sua Ten";
				cout << "\n3. Sua Gioi Tinh ";
				cout << "\n4. Sua Ngay Sinh ";
				cout << "\n5. Sua Dia Chi ";
				cout << "\n6. Sua SDT ";
				cout << "\n7. Sua Email ";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonskh;
				cin >> luachonskh;
				if (luachonskh == 1) {
					string a;
					cout << "\nNhap Ho Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_Ho(a);
					cout << "\nSua Ho Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 2) {
					string a;
					cout << "\nNhap Ten Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_Ten(a);
					cout << "\nSua Ten Thanh Cong...";

					goto KH;
				}
				else if (luachonskh == 3) {
					string a;
					cout << "\nNhap Gioi Tinh Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_GioiTinh(a);
					cout << "\nSua Gioi Tinh Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 4) {
					string a;
					cout << "\nNhap Ngay: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_NgaySinh(a);
					cout << "\nNhap Thang: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_ThangSinh(a);
					cout << "\nNhap Nam: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_NamSinh(a);
					cout << "\nSua Ngay Sinh Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 5) {
					string a;
					cout << "\nNhap Tinh/TPtw: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_TinhTPtw(a);
					cout << "\nNhap Quan/Huyen: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_QuanHuyen(a);
					cout << "\nNhap Xa/Phuong: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_XaPhuongThitran(a);
					cout << "\nNhap DiaChiCuThe: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_DiaChiCuThe(a);
					cout << "\nSua Dia Chi Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 6) {
					string a;
					cout << "\nNhap SDT Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_SDT(a);
					cout << "\nSua SDT Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 7) {
					string a;
					cout << "\nNhap Email Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachKH[j].Setter_Email(a);
					cout << "\nSua Email Thanh Cong...";
					goto KH;
				}
				else if (luachonskh == 0) {
					goto KH;
				}

			}
			else if (luachonkh == 5 && p != 2) {
				cout << "\n-------------Tim Kiem Khach Hang-------------";
				cout << "\n1. Theo Ten";
				cout << "\n2. Theo Ma Khach Hang";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachontkkh;
				cin >> luachontkkh;
				if (luachontkkh == 1) {
					this->TimKiemKH();
				}
				else if (luachontkkh == 2) {
					this->TimKiemKH();
				}
				else if (luachontkkh == 0) {
					goto KH;
				}

			}
			else if (luachonkh == 6) {
				cout << "\n-------------Sap Xep Khach Hang-------------";
				cout << "\n1. Theo Ten";
				cout << "\n2. Theo Ma Khach Hang";
				//cout << "\n3. Theo ";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonsxkh;
				cin >> luachonsxkh;
				if (luachonsxkh == 1) {
					this->SapXepKhachHangTheoTen();
				}
				else if (luachonsxkh == 2) {
					this->SapXepKhachHangTheoMaKH();
				}

			}
			else {
				system("cls");
				cout << "\nVui long nhap lai...";
				goto KH;
			}



		}
		else if (luachon == 2 && p != 2) {
		GV:
			this->XuatGV();
			cout << "\n-----------------Giao Vien-----------------";
			//cout << "\n1. Xem Danh Sach";
			cout << "\n2. Them";
			cout << "\n3. Xoa";
			cout << "\n4. Sua";
			cout << "\n5. Tim Kiem";
			cout << "\n6. Sap Xep";
			cout << "\n0. Quay Lai";
			cout << "\n--------------------------------------------\n";
			int luachongv;
			cin >> luachongv;
			if (luachongv == 0) goto ReturnPoint;
			else if (luachongv == 1) {
				this->XuatGV();
			}
			else if (luachongv == 2) {
				this->NhapGV();
			}
			else if (luachongv == 3) {
				cout << "\n---------------Xoa Giao Vien---------------";
				cout << "\n1. Theo Ma Giao Vien";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonxgv;
				cin >> luachonxgv;
				if (luachonxgv == 1) {
					this->XoaGV();
				}
				else if (luachonxgv == 0) {
					goto GV;
				}
			}
			else if (luachongv == 4) {

				int j = this->SuaGV();
				if (j == -1) {
					goto GV;
				}

				cout << "\n---------------Sua Giao Vien---------------";
				cout << "\n1. Sua Ho";
				cout << "\n2. Sua Ten";
				cout << "\n3. Sua Gioi Tinh ";
				cout << "\n4. Sua Ngay Sinh ";
				cout << "\n5. Sua Dia Chi ";
				cout << "\n6. Sua SDT ";
				cout << "\n7. Sua Email ";
				cout << "\n8. Sua Luong ";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonsgv;
				cin >> luachonsgv;
				if (luachonsgv == 1) {
					string a;
					cout << "\nNhap Ho Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_Ho(a);
					cout << "\nSua Ho Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 2) {
					string a;
					cout << "\nNhap Ten Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_Ten(a);
					cout << "\nSua Ten Thanh Cong...";

					goto GV;
				}
				else if (luachonsgv == 3) {
					string a;
					cout << "\nNhap Gioi Tinh Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_GioiTinh(a);
					cout << "\nSua Gioi Tinh Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 4) {
					string a;
					cout << "\nNhap Ngay: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_NgaySinh(a);
					cout << "\nNhap Thang: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_ThangSinh(a);
					cout << "\nNhap Nam: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_NamSinh(a);
					cout << "\nSua Ngay Sinh Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 5) {
					string a;
					cout << "\nNhap Tinh/TPtw: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_TinhTPtw(a);
					cout << "\nNhap Quan/Huyen: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_QuanHuyen(a);
					cout << "\nNhap Xa/Phuong: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_XaPhuongThitran(a);
					cout << "\nNhap DiaChiCuThe: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_DiaChiCuThe(a);
					cout << "\nSua Dia Chi Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 6) {
					string a;
					cout << "\nNhap SDT Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_SDT(a);
					cout << "\nSua SDT Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 7) {
					string a;
					cout << "\nNhap Email Moi: ";
					rewind(stdin);
					getline(cin, a);
					DanhSachGV[j].Setter_Email(a);
					cout << "\nSua Email Thanh Cong...";
					goto GV;
				}else if(luachonsgv == 8){
					float a;
					cout << "\nNhap Luong Moi: ";
					cin >> a;
					DanhSachGV[j].Setter_LuongGV(a);
					cout << "\nSua Luong Thanh Cong...";
					goto GV;
				}
				else if (luachonsgv == 0) {
					goto GV;
				}

			}
			else if (luachongv == 5) {
				cout << "\n-------------Tim Kiem Giao Vien-------------";
				cout << "\n1. Theo Ten";
				cout << "\n2. Theo Ma Khach Hang";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachontkgv;
				cin >> luachontkgv;
				if (luachontkgv == 1) {
					this->TimKiemGV();
				}
				else if (luachontkgv == 2) {
					this->TimKiemGV();
				}
				else if (luachontkgv == 0) {
					goto GV;
				}

			}
			else if (luachongv == 6) {
				cout << "\n-------------Sap Xep Giao Vien-------------";
				cout << "\n1. Theo Ten";
				cout << "\n2. Theo Ma Giao Vien";
				//cout << "\n3. Theo ";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonsxgv;
				cin >> luachonsxgv;
				if (luachonsxgv == 1) {
					this->SapXepGiaoVienTheoTen();
				}
				else if (luachonsxgv == 2) {
					this->SapXepGiaoVienTheoMaGV();
				}

			}
			else {
				system("cls");
				cout << "\nVui long nhap lai...";
				goto KH;
			}



		}
		else if (luachon == 3) {
		LT:
			this->XuatLT();
			cout << "\n-----------------Lop Tap-----------------";
			//cout << "\n1. Xem Danh Sach";
			cout << "\n2. Them";
			cout << "\n3. Xoa";
			cout << "\n4. Sua";
			cout << "\n5. Tim Kiem";
			cout << "\n6. Chi Tiet";
			cout << "\n0. Quay Lai";
			cout << "\n--------------------------------------------\n";
			int luachonlt;
			cin >> luachonlt;
			if (luachonlt == 0) {
				goto ReturnPoint;
			}
			else if (luachonlt == 1) {
				this->XuatLT();
			}
			else if (luachonlt == 2 && p != 2) {
				this->NhapLT();
				this->XuatLT();
			}
			else if (luachonlt == 3 && p != 2) {
				this->XoaLT();
			}
			else if (luachonlt == 4 && p != 2) {
				this->SuaLT();
				//cần kiểm tra tất cả ràng buộc khi sửa: Max, Time , ... 
			}
			else if (luachonlt == 5) {
				this->TimKiemLT();
			}
			else if (luachonlt == 6) {
				cout << "\n-----------------Chi Tiet-----------------\n";
				//cout << "\n1. Zumba";
				//cout << "\n2. Yoga";
				//cout << "\n3. Bodyfit";
				//cout << "\n0. Quay Lai";
				//cout << "\n--------------------------------------------\n";
				//int luachonct;
				string mlt;
				cout << "\nNhap ma lop tap: ";
				rewind(stdin);
				getline(cin, mlt);
				//cin >> luachonct;
				//if (luachonct == 1) {
				int demslhv = 0;
				cout << "\nGiao Vien: ";
				int x = -1;
				for (int i = 0; i < slgv; i++) {
					for (int j = 0; j < sllt; j++) {
						if (DanhSachLT[j].Getter_MaLT() == mlt) {
							x = j;
						}
					}
					if (DanhSachGV[i].Getter_MaGV().find(DanhSachLT[x].Getter_MaGVQL()) != string::npos) {
						DanhSachGV[i].Xuat();
						//demslhv++;
					}
				}
				if (x == -1) goto LT;
				cout << "\nThoi gian: " << DanhSachLT[x].Getter_ThoiGian();
				/*cout << "\nSo luong toi da: " << DanhSachLT[x].Getter_Max();
				cout << "\nSo luong hien tai: " << demslhv;*/
				cout << "\n-----------------" << mlt << "-----------------\n";
				//int demslhv;
				for (int i = 0; i < slkh; i++) {
					if (DanhSachKH[i].Getter_LopTap() == DanhSachLT[x].Getter_MaLT()) {
						DanhSachKH[i].Xuat();
						demslhv++;
					}
				}

				cout << "\n--------------------------------------------\n";
				cout << "\nSo luong toi da: " << DanhSachLT[x].Getter_Max();
				cout << "\nSo luong hien tai: " << demslhv;
				cout << "\n--------------------------------------------\n";
				cout << "\n1. Them/Chuyen Giao Vien";
				cout << "\n2. Them/Chuyen Khach Hang";
				cout << "\n3. Sua So Luong Toi Da";
				cout << "\n4. Sua Ma Lop";
				cout << "\n5. Sua Thoi Gian";
				cout << "\n6. Xoa Khach Hang";

				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonzb;
				cin >> luachonzb;
				if (luachonzb == 1 && p != 2) {
					this->XuatGV();
					//
					cout << "\nNhap Ma GV muon them/chuyen: ";
					string m;
					rewind(stdin);
					getline(cin, m);
					for (int i = 0; i < slgv; i++) {
						if (DanhSachGV[i].Getter_MaGV() == m) {
							for (int j = 0; j < sllt; j++) {
								if (DanhSachLT[j].Getter_MaGVQL() == m) {
									cout << "\nThao tac nay se doi cho giao vien neu giao vien day lop khac...";
									DanhSachLT[j].Setter_maGVQL(DanhSachLT[x].Getter_MaGVQL());
									DanhSachLT[x].Setter_maGVQL(m);
								}
							}
						}
						//else cout << "\nKhong ton tai ma giao vien...";
					}
				}
				else if (luachonzb == 2 && p != 2) {
					this->XuatKH();
					string m;
					cout << "\nNhap ma KH can them: ";
					rewind(stdin);
					getline(cin, m);
					for (int i = 0; i < slkh; i++) {
						if (DanhSachKH[i].Getter_MaKH() == m && demslhv <= stoi(DanhSachLT[x].Getter_Max())) {
							DanhSachKH[i].Setter_LopTap(DanhSachLT[x].Getter_MaLT());
							cout << "\nDa them thanh cong...";
							//&& DanhSachKH[i].Getter_LopTap() == "XXXXX"
						}
					}
					//DanhSachLT[x].
				}
				else if (luachonzb == 3 && p != 2) {
					string m;
					cout << "\nNhap so luong moi: ";
					rewind(stdin);
					getline(cin, m);
					DanhSachLT[x].Setter_Max(m);
				}
				else if (luachonzb == 4 && p != 2) {
					string m;
					cout << "\nNhap thoi gian moi: ";
					rewind(stdin);
					getline(cin, m);
					DanhSachLT[x].Setter_MaLop(m);
				}
				else if (luachonzb == 5 && p != 2) {
					string m;
					cout << "\nNhap thoi gian moi: ";
					rewind(stdin);
					getline(cin, m);
					DanhSachLT[x].Setter_ThoiGian(m);
				}
				else if (luachonzb == 6 && p != 2) {
					string m;
					cout << "\nNhap ma KH can xoa: ";
					rewind(stdin);
					getline(cin, m);
					for (int i = 0; i < slkh; i++) {
						if (m == DanhSachKH[i].Getter_MaKH()) {
							DanhSachKH[i].Setter_LopTap("XXXXX");
						}
					}
					//DanhSachLT[x].XoaKHtrongLT(m);
				}
				else goto LT;
				//}
				//else goto LT;
			}
		}
		else if (luachon == 4 && p != 2) {
		DT:
			cout << "\n------------------Doanh Thu-----------------";
			cout << "\n1. Thong Ke";
			cout << "\n2. Tong Cong Doanh Thu";
			cout << "\n3. Tong Luong Giao Vien";
			cout << "\n4. Loi Nhuan";
			cout << "\n0. Quay Lai";
			cout << "\n--------------------------------------------\n";
			int luachondt;
			cout << "\nNhap lua chon: ";
			cin >> luachondt;
			if (luachondt == 0) goto ReturnPoint;
			if (luachondt == 1) {
				this->TKeKhachHangTheoGT();
				this->TKeGiaoVienTheoGT();
			}
			else if (luachondt == 2) {
				cout << "\n------------Tong Cong Doanh Thu------------";
				cout << "\n1. 1 thang";
				cout << "\n2. Tich Luy";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int tcdt;
				cout << "\nNhap vao lua chon: ";
				cin >> tcdt;
				if (tcdt == 1) {
					cout << "\nDoanh Thu thang da nhap la: " << fixed << setprecision(0) << this->TinhTongDoanhThu1Thang();
				}
				else if (tcdt == 2) {
					cout << "\nNhap thang: ";
					string a;
					cin >> a;
					cout << "\nNhap nam: ";
					string b;
					cin >> b;
					cout << "\nDoanh Thu tich luy: " << fixed << setprecision(0) << this->TinhTongDoanhThuTheoTime(a, b);
				}
				else goto DT;






			}
			else if (luachondt == 3) {
				cout << "\nTong Luong Giao Vien 1 Thang Hien Tai: " << fixed << setprecision(0) << this->TinhTongLuongGiaoVien1Thang();
			}
			else if (luachondt == 4) {
				//float PhiDuyTri = 1000000;
				cout << "\n------------------Loi Nhuan------------------";
				cout << "\n1. 1 thang";
				cout << "\n2. Tich Luy";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int tcdt;
				cout << "\nNhap vao lua chon: ";
				cin >> tcdt;
				if (tcdt == 1) {
					//cout << "\nPhi duy tri 1 thang: " << fixed << setprecision(0) << PhiDuyTri;
					cout << "\nLoi nhuan thang da nhap la: " << fixed << setprecision(0) << this->TinhTongDoanhThu1Thang() - this->TinhTongLuongGiaoVien1Thang();
				}
				else if (tcdt == 2) {
					cout << "\nNhap thang: ";
					string a;
					cin >> a;
					cout << "\nNhap nam: ";
					string b;
					cin >> b;
					cout << "\nLoi Nhuan tich luy: " << fixed << setprecision(0) << this->TinhTongDoanhThuTheoTime(a, b) - this->TinhTongLuongGiaoVienTheoTime(a, b);
				}
				else goto DT;
			}
			else goto DT;

		}
	} while (luachon != 0);
}




void Admin::NhapGV() {
	DanhSachGV[slgv].Nhap();
	b:
	string temp;
	cout << "\nNhap SDT: ";
	rewind(stdin);
	getline(cin, temp);
	
	if (!KiemTraSDTTrungLapGV(temp)) {
		DanhSachGV[slgv].Setter_SDT(temp);
	}
	else {
		//cout << "\nSDT bi trung lap, vui long kiem tra lai...";
		goto b;
	}

	z:
	string temp1;
	cout << "\nNhap Email: ";
	rewind(stdin);
	getline(cin, temp1);

	if (!KiemTraEmailTrungLapGV(temp1)) {
		DanhSachGV[slgv].Setter_Email(temp1);
	}
	else {
		//cout << "\Email bi trung lap, vui long kiem tra lai...";
		goto z;
	}
	
	string a;
	for (int i = 0; i <= slgv; i++) {
		if (i >= 10) {
			a = "GV0" + to_string(i);
			if (KiemTraMaGV(a)) {
				DanhSachGV[slgv].Setter_MaGiaoVien(a);
			}
		}
		else {
			a = "GV00" + to_string(i);
			if (KiemTraMaGV(a)) {
				DanhSachGV[slgv].Setter_MaGiaoVien(a);
			}
		}

	}

	slgv++;
}

void Admin::XuatGV() {
	textcolor(14);
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaGV " << setw(15) << "Ngay Bat Dau" << setw(10) << "Luong"<< endl;
	textcolor(7);
	for (int i = 0; i < slgv; i++) {
		DanhSachGV[i].Xuat();
	}
}

int Admin::SuaGV() {
	cout << "\nNhap ma giao vien can sua: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	for (int i = 0; i < slgv; i++) {
		if (DanhSachGV[i].Getter_MaGV().find(a) != string::npos) {

			DanhSachGV[i].Xuat();
			return i;
		}
	}
	cout << "\nKhong tim thay giao vien can sua, vui long kiem tra lai...";
	return -1;
}

void Admin::XoaGV() {

	cout << "\nNhap ma giao vien can xoa: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	int demslkhbixoa = 0;
	for (int i = 0; i < slgv; i++) {
		if (DanhSachLT[i].Getter_MaGVQL().find(a) != string::npos) {
			cout << "\n Giao vien ban vua nhap dang quan ly lop sau: ";
			DanhSachLT[i].XuatLop();
			cout << "\nKhong the xoa giao vien dang quan ly lop...";
			return;
		}
	}
	for (int i = 0; i < slgv; i++) {
		if (DanhSachGV[i].Getter_MaGV().find(a) != string::npos) {
			DanhSachGV[i].Xuat();
			DanhSachGV[i].Xoa();
			for (int j = i; j < slgv; j++) {
				DanhSachGV[j] = DanhSachGV[j + 1];
			}

			demslkhbixoa++;
		}
	}
	cout << "\nDa xoa giao vien co ma " << a << "...";
	slgv -= demslkhbixoa;
}

void Admin::TimKiemGV() {
	cout << "\nNhap ky tu tim kiem: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	bool check = false;
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaGV " << endl;
	for (int i = 0; i < slgv; i++) {
		if (DanhSachGV[i].Getter_Name().find(a) != string::npos) {
			DanhSachGV[i].Xuat();
			check = true;
		}
		else if (DanhSachGV[i].Getter_MaGV().find(a) != string::npos) {
			DanhSachGV[i].Xuat();
			check = true;
		}
	}
	if (check == false) {
		cout << "Khong tim thay giao vien...";
	}
}

void Admin::SapXepGiaoVienTheoTen() {
	sort(DanhSachGV, DanhSachGV + slgv, compareByNameGV);
	this->XuatGV();
}

void Admin::SapXepGiaoVienTheoMaGV() {
	sort(DanhSachGV, DanhSachGV + slgv, compareByMGV);
	this->XuatGV();
}
bool Admin::KiemTraMaKH(string a) {
	for (int i = 0; i < slkh; ++i) {
		if (DanhSachKH[i].Getter_MaKH() == a) {
			//cout << "\nMa khach hang bi trung lap voi khach hang khac, vui long kiem tra lai...";
			return false;
		}
	}
	return true;
}

bool Admin::KiemTraMaGV(string a) {

	for (int i = 0; i < slgv; ++i) {
		if (DanhSachGV[i].Getter_MaGV() == a) {
			//cout << "\nMa khach hang bi trung lap voi khach hang khac, vui long kiem tra lai...";
			return false;
		}
	}
	return true;
}

bool Admin::KiemTraEmailTrungLap(string e) {
	for (int i = 0; i < slkh; ++i) {
		if (DanhSachKH[i].Getter_Email() == e) {
			cout << "\nEmail bi trung lap voi 1 email khac, vui long kiem tra lai...";
			return true;
		}
	}
	return false;
}
bool Admin::KiemTraSDTTrungLap(string s) {
	for (int i = 0; i < slkh; ++i) {
		if (DanhSachKH[i].Getter_SDT() == s) {
			cout << "\nSDT bi trung lap voi 1 SDT khac, vui long kiem tra lai...";
			return true;
		}
	}
	return false;
}


bool Admin::KiemTraEmailTrungLapGV(string e) {
	for (int i = 0; i < slgv; ++i) {
		if (DanhSachGV[i].Getter_Email() == e) {
			cout << "\nEmail bi trung lap voi 1 email khac, vui long kiem tra lai...";
			return true;
		}
	}
	return false;
}
bool Admin::KiemTraSDTTrungLapGV(string s) {
	for (int i = 0; i < slgv; ++i) {
		if (DanhSachGV[i].Getter_SDT() == s) {
			cout << "\nSDT bi trung lap voi 1 SDT khac, vui long kiem tra lai...";
			return true;
		}
	}
	return false;
}





void Admin::XuatFile() {

	ofstream file("DANHSACHKHACHHANG.TXT");

	if (file.is_open()) {
		//demo
		//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";
		for (int i = 0; i < slkh; i++) {
			if (i == slkh - 1) {
				file << DanhSachKH[i].Getter_Name() << "|" << DanhSachKH[i].Getter_NgaySinh() << "|" << DanhSachKH[i].Getter_GioiTinh() << "|" <<
					DanhSachKH[i].Getter_SDT() << "|\"" << DanhSachKH[i].Getter_DiaChi() << "\"|" << DanhSachKH[i].Getter_Email() << "|" <<
					DanhSachKH[i].Getter_MaKH() << "|" << DanhSachKH[i].Getter_AllNgayBatDau() << "|" << DanhSachKH[i].Getter_AllNgayKetThuc() << "|" << DanhSachKH[i].Getter_LopTap();
			}
			else {
				file << DanhSachKH[i].Getter_Name() << "|" << DanhSachKH[i].Getter_NgaySinh() << "|" << DanhSachKH[i].Getter_GioiTinh() << "|" <<
					DanhSachKH[i].Getter_SDT() << "|\"" << DanhSachKH[i].Getter_DiaChi() << "\"|" << DanhSachKH[i].Getter_Email() << "|" <<
					DanhSachKH[i].Getter_MaKH() << "|" << DanhSachKH[i].Getter_AllNgayBatDau() << "|" << DanhSachKH[i].Getter_AllNgayKetThuc() << "|" << DanhSachKH[i].Getter_LopTap() << "\n";
			}
		}
	}
	else {
		std::cout << "Khong the mo file.\n";
	}
	file.close();

	ofstream file1("DANHSACHGIAOVIEN.TXT");

	if (file1.is_open()) {
		//demo
		//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";
		for (int i = 0; i < slgv; i++) {
			if (i == slkh - 1) {
				file1 << DanhSachGV[i].Getter_Name() << "|" << DanhSachGV[i].Getter_NgaySinh() << "|" << DanhSachGV[i].Getter_GioiTinh() << "|" <<
					DanhSachGV[i].Getter_SDT() << "|\"" << DanhSachGV[i].Getter_DiaChi() << "\"|" << DanhSachGV[i].Getter_Email() << "|" <<
					DanhSachGV[i].Getter_MaGV() << "|" << fixed << setprecision(0) <<to_string(DanhSachGV[i].Getter_LuongGV()) << "|" <<DanhSachGV[i].Getter_AllNgayBatDau();
			}
			else {
				file1 << DanhSachGV[i].Getter_Name() << "|" << DanhSachGV[i].Getter_NgaySinh() << "|" << DanhSachGV[i].Getter_GioiTinh() << "|" <<
					DanhSachGV[i].Getter_SDT() << "|\"" << DanhSachGV[i].Getter_DiaChi() << "\"|" << DanhSachGV[i].Getter_Email() << "|" <<
					DanhSachGV[i].Getter_MaGV() << "|" << fixed << setprecision(0) << to_string(DanhSachGV[i].Getter_LuongGV()) << "|" << DanhSachGV[i].Getter_AllNgayBatDau() << "\n";
			}
		}
	}
	else {
		std::cout << "Khong the mo file.\n";
	}
	file1.close();


	ofstream file2("LOPTAP.TXT");

	if (file2.is_open()) {
		//demo
		//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";
		for (int i = 0; i < sllt; i++) {
			if (i == sllt - 1) {
				file2 << DanhSachLT[i].Getter_MaLT() << "|" << DanhSachLT[i].Getter_TenLop() << "|" << DanhSachLT[i].Getter_ThoiGian() << "|" <<
					DanhSachLT[i].Getter_MaGVQL() << "|" << DanhSachLT[i].Getter_Max() << "|" << fixed << setprecision(0) << DanhSachLT[i].Getter_HP1Thang();
			}
			else {
				file2 << DanhSachLT[i].Getter_MaLT() << "|" << DanhSachLT[i].Getter_TenLop() << "|" << DanhSachLT[i].Getter_ThoiGian() << "|" <<
					DanhSachLT[i].Getter_MaGVQL() << "|" << DanhSachLT[i].Getter_Max() << "|" << fixed << setprecision(0) << DanhSachLT[i].Getter_HP1Thang() << "\n";
			}
		}
	}
	else {
		std::cout << "Khong the mo file.\n";
	}
	file2.close();


}

void Admin::NhapKH() {
	DanhSachKH[slkh].Nhap();

	
	x:
	string temp2;
	cout << "\nNhap SDT: ";
	rewind(stdin);
	getline(cin, temp2);

	if (!KiemTraSDTTrungLap(temp2)) {
		DanhSachKH[slkh].Setter_SDT(temp2);
	}
	else {
		//cout << "\nSDT bi trung lap, vui long kiem tra lai...";
		goto x;
	}

	z:
	string temp1;
	cout << "\nNhap Email: ";
	rewind(stdin);
	getline(cin, temp1);

	if (!KiemTraEmailTrungLap(temp1)) {
		DanhSachKH[slkh].Setter_Email(temp1);
	}
	else {
		cout << "\Email bi trung lap, vui long kiem tra lai...";
		goto z;
	}



	b:
	cout << "\nNhap Lop Tap: ";
	
	string temp;
	rewind(stdin);
	getline(cin, temp);
	//cout << temp;
	int n;
	int demslhv = 0;
	for (int i = 0; i < slkh; i++) {
		if (DanhSachKH[i].Getter_LopTap() == temp) {
			demslhv++;
		}
	}
	for (int i = 0; i < sllt; i++) {
		if (DanhSachLT[i].Getter_MaLT() == temp) {
			n = i;
		}
	}
	if (temp =="XXXXX") {
		DanhSachKH[slkh].Setter_LopTap(temp);
	}
	else if(KiemTraMaLop(temp) && demslhv <= stoi(DanhSachLT[n].Getter_Max())) {
		DanhSachKH[slkh].Setter_LopTap(temp);
	}
	else {
		cout << "\nKhong tim thay ma lop tap tuong ung hoac lop tap da day...";
		goto b;
	}


	string a;
	for (int i = 0; i < slkh; i++) {
		if (i >= 10) {
			a = "KH0" + to_string(i);
			if (KiemTraMaKH(a)) {
				DanhSachKH[slkh].Setter_MaKhachHang(a);
			}
		}
		else {
			a = "KH00" + to_string(i);
			if (KiemTraMaKH(a)) {
				DanhSachKH[slkh].Setter_MaKhachHang(a);
			}
		}

	}


	slkh++;
}

void Admin::XoaKH() {
	cout << "\nNhap ma khach hang can xoa: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	int demslkhbixoa = 0;



	for (int i = 0; i < slkh; i++) {
		if (DanhSachKH[i].Getter_MaKH().find(a) != string::npos) {
			DanhSachKH[i].Xuat();
			DanhSachKH[i].Xoa();
			for (int j = i; j < slkh; j++) {
				DanhSachKH[j] = DanhSachKH[j + 1];
			}

			demslkhbixoa++;
		}
	}
	cout << "\nDa xoa khach hang co ma " << a << "...";
	slkh -= demslkhbixoa;


}

int Admin::SuaKH() {
	cout << "\nNhap ma khach hang can sua: ";
	string a;
	rewind(stdin);
	getline(cin, a);
	for (int i = 0; i < slkh; i++) {
		if (DanhSachKH[i].Getter_MaKH().find(a) != string::npos) {
			DanhSachKH[i].Xuat();
			return i;
		}
	}
	cout << "\nKhong tim thay ma khach hang can sua, vui long kiem tra lai...";
	return -1;
}

void Admin::SuaLT() {

	cout << "\nNhap Ma Lop Can Sua: ";
	string a;
	cin >> a;
	int x;
	for (int i = 0; i < sllt; i++) {
		if (a == DanhSachLT[i].Getter_MaLT()) {
			x = i;
			break;
		}
	}
	SLT:
	cout << "\n-----------------Sua Lop Tap-----------------";
	cout << "\n1. Ma Lop";
	cout << "\n2. Maximum";
	cout << "\n3. Thoi Gian";
	cout << "\n4. HP 1 Thang";
	cout << "\n0. Quay Lai";
	cout << "\n--------------------------------------------\n";
	int slt;
	cout << "\nNhap lua chon :";
	cin >>slt;
	if (slt == 1) {
		cout << "\nNhap Ma Lop moi: ";
		string temp;
		cin >> temp;
		DanhSachLT[x].Setter_MaLop(temp);
	}
	else if (slt == 2) {
		cout << "\nNhap so luong toi da moi: ";
		string temp;
		cin >> temp;
		DanhSachLT[x].Setter_Max(temp);
	}
	else if (slt == 3) {
		cout << "\nNhap Thoi Gian moi: ";
		string temp;
		cin >> temp;
		DanhSachLT[x].Setter_ThoiGian(temp);
		//Kiểm tra thời gian đã có chưa
	}
	else if (slt == 4) {
		cout << "\nNhap Hp moi: ";
		float a; 
		cin >> a;
		DanhSachLT[x].Setter_HP1Thang(a);
	}
	else goto SLT;



}
void Admin::XuatKH() {
	textcolor(14);
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaKH " << setw(15) << "Ngay Bat Dau" << setw(15) << "Ngay Ket Thuc" << setw(10) << "Lop Tap" << endl;
	textcolor(7);
	for (int i = 0; i < slkh; i++) {
		DanhSachKH[i].Xuat();
	}
}

void Admin::Setter_SLKH(int a) {
	slkh = a;
}

int Admin::PhanQuyenQuanTri() {
	check:
	ifstream file1("TAIKHOAN.TXT");
	int sltk;
	string line1;
	sltk = 0;
	string* DANHSACHTAIKHOAN = new string[10];
	while (getline(file1, line1))
		++sltk;
	//file.ignore();
	file1.close();
	ifstream FileIn1("TAIKHOAN.TXT");
	for (int i = 0; i < sltk; ++i) {
		string FullDong;
		getline(FileIn1, FullDong);
		stringstream ss(FullDong);
		//cout << FullDong<<endl;
		DANHSACHTAIKHOAN[i] = FullDong;
	}

	cout << "\n-----------------------------LOGIN-----------------------------";
	cout << "\nTai Khoan: ";
	string tk;
	cin >> tk;
	cout << "\nMat Khau: ";
	string mk; 
	cin >> mk;
	cout << "\n---------------------------------------------------------------";
	string kiemtra = tk + "|" + mk +"|";
	for (int i = 0; i < sltk; i++) {
		if (kiemtra + "1" == DANHSACHTAIKHOAN[i] ) {
			cout << "\nDang nhap thanh cong..." << endl;
			cout << "\nBan la ADMIN..." << endl;
			return 1;
		}else
		if(kiemtra + "2" == DANHSACHTAIKHOAN[i] ) {
			cout << "\nDang nhap thanh cong..." << endl;
			cout << "\nBan la Giao Vien, ban bi han che 1 so quyen truy cap..." << endl;
			return 2;
		}							
	}	
	textcolor(12);
	cout << "\nSai ten tai khoan hoac mat khau..." << endl;
	textcolor(7);
	goto check;
}

void Admin::DocFile() {
	ifstream file1("DANHSACHKHACHHANG.TXT");

	string line1;
	slkh = 0;

	while (getline(file1, line1))
		++slkh;
	//file.ignore();
	file1.close();
	ifstream FileIn1("DANHSACHKHACHHANG.TXT");
	//FileIn >> slkh;
	//FileIn.ignore();
	//cout << slkh;
	DanhSachKH = new ThongTinKhachHang[100];
	for (int i = 0; i < slkh; ++i) {
		string FullDong;
		getline(FileIn1, FullDong);
		DanhSachKH[i].DocFile(FullDong);
		//i++;
	}
	//Admin A;
	//A.Setter_SLKH(i);
	//cout << A.n;
	FileIn1.close();

	ifstream file2("DANHSACHGIAOVIEN.TXT");

	string line;
	slgv = 0;

	while (getline(file2, line))
		++slgv;
	//file.ignore();
	file2.close();
	ifstream FileIn("DANHSACHGIAOVIEN.TXT");
	//FileIn >> slkh;
	//FileIn.ignore();
	//cout << slkh;
	DanhSachGV = new ThongTinGiaoVien[100];
	for (int i = 0; i < slgv; ++i) {
		string FullDong;
		getline(FileIn, FullDong);
		DanhSachGV[i].DocFile(FullDong);
		//i++;
	}
	//Admin A;
	//A.Setter_SLKH(i);
	//cout << A.n;
	FileIn.close();

	ifstream file3("LOPTAP.TXT");

	string line3;
	sllt = 0;

	while (getline(file3, line3))
		++sllt;
	//file.ignore();
	file3.close();
	ifstream FileIn3("LOPTAP.TXT");
	//FileIn >> slkh;
	//FileIn.ignore();
	//cout << slkh;
	DanhSachLT = new LopTap[100];
	for (int i = 0; i < sllt; ++i) {
		string FullDong;
		getline(FileIn3, FullDong);
		DanhSachLT[i].DocFile(FullDong);
		//i++;
	}
	//Admin A;
	//A.Setter_SLKH(i);
	//cout << A.n;
	FileIn3.close();

	//delete[] DanhSachKH;
	//delete[] DanhSachGV;
}
void Admin::TKeKhachHangTrongLop() {

}

void Admin::TKeKhachHangTheoGT() {
	int nam = 0;
	for (int i = 0; i < slkh; i++) {
		if (DanhSachKH[i].Getter_GioiTinh() == "Nam")
			nam++;
	}
	cout << "So luong khach hang co gioi tinh NAM la: " << nam << endl;
	cout << "So luong khach hang co gioi tinh NU la: " << slkh - nam << endl;
}

void Admin::TKeGiaoVienTheoGT() {
	int nam = 0;
	for (int i = 0; i < slgv; i++) {
		if (DanhSachGV[i].Getter_GioiTinh() == "Nam")
			nam++;
	}
	cout << "So luong giao vien co gioi tinh NAM la: " << nam << endl;
	cout << "So luong giao vien co gioi tinh NU la: " << slgv - nam << endl;
}


bool Admin::KiemTraMaLop(string a) {
	for (int i = 0; i < sllt; ++i) {
		if (DanhSachLT[i].Getter_MaLT() == a) {
			return true;
		}
	}
	return false;
}

bool Admin::KiemTraThoiGianLopTapBiTrung(string a) {
	for (int i = 0; i < sllt; i++) {
		if (DanhSachLT[i].Getter_ThoiGian().find(a) != string::npos) {
			//cout << DanhSachLT[i].Getter_ThoiGian();
			return false;
		}
	}
	return true;
}
//bool kiemTraChuoiConKhongPhanBietHoaThuong(const std::string& chuoi, const std::string& chuoiCon) {
//	std::string chuoiChuyenDoi = chuoi;
//	std::string chuoiConChuyenDoi = chuoiCon;
//
//	std::transform(chuoiChuyenDoi.begin(), chuoiChuyenDoi.end(), chuoiChuyenDoi.begin(), ::tolower);
//	std::transform(chuoiConChuyenDoi.begin(), chuoiConChuyenDoi.end(), chuoiConChuyenDoi.begin(), ::tolower);
//
//	if (chuoiChuyenDoi.find(chuoiConChuyenDoi) != std::string::npos) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

void Admin::NhapLT() {
	DanhSachLT[sllt].ThemLop();
	string temp;


	do {
		cout << "\nNhap ma lop: ";
		rewind(stdin);
		getline(cin, temp);
		if (KiemTraMaLop(temp)) {
			cout << "\nMa lop bi trung lap ... ";
		}
		else break;
	} while (KiemTraMaLop(temp));
	DanhSachLT[sllt].Setter_MaLop(temp);
	temp.clear();
	do {
		cout << "\nNhap thoi gian su dung phong tap cua lop: ";
		rewind(stdin);
		getline(cin, temp);
		if (!KiemTraThoiGianLopTapBiTrung(temp)) {
			cout << "\nThoi gian su dung phong tap bi trung lap ... ";
		}
		else break;
	} while (!KiemTraThoiGianLopTapBiTrung(temp));
	DanhSachLT[sllt].Setter_ThoiGian(temp);

	temp.clear();
	do {
		cout << "\nNhap ma giao vien day lop: ";
		rewind(stdin);
		getline(cin, temp);
		if (KiemTraMaGV(temp)) {
			cout << "\nKhong ton tai ma giao vien ... ";
		}
		else break;
	} while (KiemTraMaGV(temp));
	DanhSachLT[sllt].Setter_maGVQL(temp);

	sllt++;
}
void Admin::XuatLT() {
	textcolor(14);
	cout << left << setw(14) << "Ten Lop " << setw(9) << "Ma Lop " <<
		setw(10) << "Max" << setw(15) << "Thoi Gian " << setw(12) << "MaGVQuanLy "<<"   " << "HP 1 Thang" << endl;
	textcolor(7);
	for (int i = 0; i < sllt; i++) {
		DanhSachLT[i].XuatLop();
	}
}
//int Admin::SuaLT() {
//
//}
void Admin::XoaLT() {
	cout << "\nNhap ma LT can xoa...";
	string a;
	rewind(stdin);
	getline(cin, a);
	int demslkhbixoa = 0;
	for (int i = 0; i < sllt; i++) {
		if (DanhSachLT[i].Getter_MaLT().find(a) != string::npos) {
			DanhSachLT[i].XuatLop();
			DanhSachLT[i].XoaLop();
			for (int j = i; j < sllt; j++) {
				DanhSachLT[j] = DanhSachLT[j + 1];
			}

			demslkhbixoa++;
			cout << "\nDa xoa lop tap co ma " << a << "...";
			for (int j = 0; j < slkh; j++) {
				if (DanhSachKH[j].Getter_LopTap().find(a) != string::npos) {
					DanhSachKH[j].Setter_LopTap("XXXXX");
				}
			}
		}
	}
	sllt -= demslkhbixoa;
}
void Admin::TimKiemLT() {





}
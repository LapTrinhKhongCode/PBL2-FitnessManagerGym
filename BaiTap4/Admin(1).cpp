#include "Admin.h"

//string Admin::Getter_Name() {
//
//}


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


void Admin::Menu() {
	int luachon;
	do {
	ReturnPoint:
		cout << "\n--------------------Menu--------------------";
		cout << "\n1. Khach Hang";
		cout << "\n2. Giao Vien";
		cout << "\n3. Lop Tap";
		cout << "\n0. Thoat";
		cout << "\n--------------------------------------------\n";
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
			else if (luachonkh == 2) {
				this->NhapKH();
			}
			else if (luachonkh == 3) {
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
			else if (luachonkh == 4) {

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
			else if (luachonkh == 5) {
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
		else if (luachon == 2) {
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
			else if (luachonlt == 2) {
				this->NhapLT();
				this->XuatLT();
			}
			else if (luachonlt == 3) {
				this->XoaLT();
			}
			else if (luachonlt == 4) {
				
			}
			else if (luachonlt == 5) {
				this->TimKiemLT();
			}
			else if (luachonlt == 6) {
				cout << "\n-----------------Chi Tiet-----------------\n";
				cout << "\n1. Zumba";
				cout << "\n2. Yoga";
				cout << "\n3. Bodyfit";
				cout << "\n0. Quay Lai";
				cout << "\n--------------------------------------------\n";
				int luachonct;

				cin >> luachonct;
				if (luachonct == 1) {
					int demslhv = 0;
					cout << "\nGiao Vien: ";
					int x =  -1;
					for (int i = 0; i < slgv; i++) {
						for (int j = 0; j < sllt; j++) {
							if (DanhSachLT[j].Getter_TenLop() == "Zumba") {
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
					cout << "\n-----------------Zumba-----------------\n";
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
					if (luachonzb == 1) {
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
					else if (luachonzb == 2) {
						this->XuatKH();
						string m;
						cout << "\nNhap ma KH can them: ";
						rewind(stdin);	
						getline(cin, m);
						for (int i = 0; i < slkh; i++) {
							if (DanhSachKH[i].Getter_MaKH() == m && DanhSachKH[i].Getter_LopTap() == "XXXXX" && demslhv <= stoi(DanhSachLT[x].Getter_Max())) {
								DanhSachKH[i].Setter_LopTap(DanhSachLT[x].Getter_MaLT());
								cout << "\nDa them thanh cong...";
	
							}
						}
						//DanhSachLT[x].
					}
					else if (luachonzb == 3) {
						string m;
						cout << "\nNhap so luong moi: ";
						rewind(stdin);
						getline(cin, m);
						DanhSachLT[x].Setter_Max(m);
					}
					else if (luachonzb == 4) {
						string m;
						cout << "\nNhap thoi gian moi: ";
						rewind(stdin);
						getline(cin, m);
						DanhSachLT[x].Setter_MaLop(m);
					}
					else if (luachonzb == 5) {
						string m;
						cout << "\nNhap thoi gian moi: ";
						rewind(stdin);
						getline(cin, m);
						DanhSachLT[x].Setter_ThoiGian(m);
					}
					else if (luachonzb == 6) {
						string m;
						cout << "\nNhap ma KH can xoa: ";
						rewind(stdin);
						getline(cin, m);
						for (int i = 0; i < slkh;i++) {
							if (m == DanhSachKH[i].Getter_MaKH()) {
								DanhSachKH[i].Setter_LopTap("XXXXX");
							}
						}
						//DanhSachLT[x].XoaKHtrongLT(m);
					}
					else goto LT;
				}
				else if (luachonct == 2) {

				}
				else if (luachonct == 3) {

				}
				else goto LT;
			}
		}
	} while (luachon != 0);
}

void Admin::NhapGV() {
	DanhSachKH[slgv].Nhap();

	string a;
	for (int i = 0; i < slgv; i++) {
		if (i >= 10) {
			a = "KH0" + to_string(i);
			if (KiemTraMaKH(a)) {
				DanhSachGV[slgv].Setter_MaGiaoVien(a);
			}
		}
		else {
			a = "KH00" + to_string(i);
			if (KiemTraMaKH(a)) {
				DanhSachGV[slgv].Setter_MaGiaoVien(a);
			}
		}

	}

	slgv++;
}

void Admin::XuatGV() {
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaGV " <<  endl;
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
			cout << "\nEmail bi trung lap voi khach hang khac, vui long kiem tra lai...";
			return false;
		}
	}
	return true;
}
bool Admin::KiemTraSDTTrungLap(string s) {
	for (int i = 0; i < slkh; ++i) {
		if (DanhSachKH[i].Getter_SDT() == s) {
			cout << "\nSDT bi trung lap voi khach hang khac, vui long kiem tra lai...";
			return false;
		}
	}
	return true;
}

void Admin::XuatFile() {

	ofstream file("DANHSACHKHACHHANG.TXT");

	if (file.is_open()) {
		//demo
		//file << "\nNguyen Van D|01/01/2000|Nam|0123456789|\"123 Duong ABC, Phuong XYZ, Quan 9, TP.HCM\"|nvd@example.com|KH004";
		for(int i = 0 ; i < slkh; i++){
			if (i == slkh - 1) {
				file << DanhSachKH[i].Getter_Name() << "|" << DanhSachKH[i].Getter_NgaySinh()<<"|" << DanhSachKH[i].Getter_GioiTinh() << "|" <<
					DanhSachKH[i].Getter_SDT() << "|\"" << DanhSachKH[i].Getter_DiaChi() << "\"|" << DanhSachKH[i].Getter_Email() << "|" <<
					DanhSachKH[i].Getter_MaKH() ;
			}
			else {
				file << DanhSachKH[i].Getter_Name() << "|" << DanhSachKH[i].Getter_NgaySinh()<<"|" << DanhSachKH[i].Getter_GioiTinh() << "|" <<
						DanhSachKH[i].Getter_SDT() << "|\"" << DanhSachKH[i].Getter_DiaChi() << "\"|" << DanhSachKH[i].Getter_Email() << "|" <<
						DanhSachKH[i].Getter_MaKH()<< "\n";
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
					DanhSachGV[i].Getter_MaGV();
			}
			else {
				file1 << DanhSachGV[i].Getter_Name() << "|" << DanhSachGV[i].Getter_NgaySinh() << "|" << DanhSachGV[i].Getter_GioiTinh() << "|" <<
					DanhSachGV[i].Getter_SDT() << "|\"" << DanhSachGV[i].Getter_DiaChi() << "\"|" << DanhSachGV[i].Getter_Email() << "|" <<
					DanhSachGV[i].Getter_MaGV() << "\n";
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
					DanhSachLT[i].Getter_MaGVQL() << "|" << DanhSachLT[i].Getter_Max();
			}
			else {
				file2 << DanhSachLT[i].Getter_MaLT() << "|" << DanhSachLT[i].Getter_TenLop() << "|" << DanhSachLT[i].Getter_ThoiGian() << "|" <<
					DanhSachLT[i].Getter_MaGVQL() << "|" << DanhSachLT[i].Getter_Max() << "\n";
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


void Admin::XuatKH() {
	cout << left << setw(15) << "\nHo " << setw(9) << "Ten " << setw(15) << "Ngay Sinh" << setw(15) << "Gioi Tinh "
		<< setw(12) << "SDT " << setw(75) << "Dia Chi" << setw(20) << "Email " << setw(10)
		<< "MaKH " << setw(15)<< "Ngay Bat Dau" << setw(15)<<"Ngay Ket Thuc" << setw(10)<<"Lop Tap" << endl;
	for (int i = 0; i < slkh; i++) {
		DanhSachKH[i].Xuat();
	}
}

void Admin::Setter_SLKH(int a) {
	slkh = a;
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
	cout << "So luong khach hang co gioi tinh NU la: " << slkh-nam << endl; 
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
		if (DanhSachLT[i].Getter_MaLT() != a) {
			return false;
		}
	}
	return true;
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
	cout << left << setw(14) << "Ten Lop " << setw(9) << "Ma Lop " <<
		setw(10) << "Max" << setw(15) << "Thoi Gian "<< setw(12) << "MaGVQuanLy " <<  endl;
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
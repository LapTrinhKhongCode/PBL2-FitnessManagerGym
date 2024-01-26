#pragma once
#ifndef KHACHHANG
#define KHACHHANG
#pragma warning (disable:4996)
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
#include<algorithm>
#include"Date.h"
#include"Address.h"
#include"ThongTinCaNhan.h"
using namespace std;




class ThongTinKhachHang : public ThongTinCaNhan
{
private:
	//std::string Ho;
	//std::string Ten;
	//std::string GioiTinh;
	//Birthday NgaySinh;
	////std::string Tuoi;
	//Address DiaChi;
	//string SDT;
	//string Email;
	std::string MaKhachHang;
	Date NgayBatDau;
	int SoThang; //3 tháng
	//
	//11/11/2021 / 11/2/2022
	
	Date NgayKetThuc;
	string LopTap;
	//std::string GoiTap;
public:
	string Getter_SDT();
	string Getter_Email();
	string Getter_Name();
	string Getter_Ten();
	string Getter_MaKH();
	string Getter_LopTap();	
	string Getter_GioiTinh();
	string Getter_NgaySinh();
	string Getter_DiaChi();
	string Getter_AllNgayBatDau();
	string Getter_AllNgayKetThuc();
	string Getter_ThangBatDau();
	string Getter_NamBatDau();
	string Getter_ThangKetThuc();
	string Getter_NamKetThuc();
	void Setter_NgayBatDau(string);
	void Setter_ThangBatDau(string);
	void Setter_NamBatDau(string);
	void Setter_NgayKetThuc(string);
	void Setter_ThangKetThuc(string);
	void Setter_NamKetThuc(string);

	void Setter_LopTap(string);
	void Setter_Ho(string);
	void Setter_Ten(string);
	void Setter_GioiTinh(string);
	void Setter_NgaySinh(string);
	void Setter_ThangSinh(string);
	void Setter_NamSinh(string);
	void Setter_DiaChiCuThe(string);
	void Setter_XaPhuongThitran(string);
	void Setter_QuanHuyen(string);
	void Setter_TinhTPtw(string);
	void Setter_Email(string);
	void Setter_SDT(string);
	void Setter_MaKhachHang(string);
	
	void DocFile(string);
	void XuatFile();
	void Nhap();
	void Xoa();
	void Sua();
	void Xuat();
};
#endif 



//SDT,Email không được trùng
//làm thêm 1 cái: nếu tên khách hàng bị trùng thì đưa ra 2 lựa chọn là tạo mới(nên đổi tên hoặc nếu không đổi tên thì cũng ko sao do tự cấp mã khách hàng khác) hoặc không tạo mới.
//class Admin {
//private:
//	int slkh;
//	ThongTinKhachHang* DanhSach;
//public:
//	Admin() {
//		slkh = 0;
//		//DanhSach = new ThongTinKhachHang[n];
//		DanhSach = NULL;
//	}
//	void Setter_SLKH(int);
//	void Nhap();
//	void DocFile();
//	void XuatFile();
//	void Xuat();
//	bool KiemTraEmailTrungLap(string);
//	bool KiemTraSDTTrungLap(string);
//
//};





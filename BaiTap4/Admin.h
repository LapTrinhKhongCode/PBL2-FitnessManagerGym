#pragma once
#ifndef ADMIN
#define ADMIN
#pragma warning (disable:4996)
//#include "KhachHang.h"
//#include "GiaoVien.h"
#include "LopTap.h"

class Admin
{
private:
	static Admin* instancePtr;

	// 5 mảng động cần quản lý 
	int slkh;
	ThongTinKhachHang* DanhSachKH;
	int slgv;
	ThongTinGiaoVien* DanhSachGV;
	int sllt;
	LopTap* DanhSachLT;
	Admin() {
		slkh = 0;
		//DanhSach = new ThongTinKhachHang[n];
		DanhSachKH = NULL;
		slgv = 0;
		DanhSachGV = NULL;
		sllt = 0;
		DanhSachLT = NULL;
	}


public:
	void setAdmin()
	{
		Admin();
	}
	static Admin* get()
	{
		if (instancePtr == NULL)
		{
			instancePtr = new Admin();
			return instancePtr;
		}
		else
		{
			return instancePtr;
		}
	}

	int PhanQuyenQuanTri();
	void GioiThieu();
	void Setter_SLKH(int);
	//string Getter_Name();
	void NhapKH();
	void XoaKH();
	int SuaKH();
	void TimKiemKH();
	void DocFile();
	void XuatFile();
	void XuatKH();
	bool KiemTraEmailTrungLap(string);
	bool KiemTraSDTTrungLap(string);
	bool KiemTraMaKH(string);
	bool KiemTraEmailTrungLapGV(string);
	bool KiemTraSDTTrungLapGV(string);
	bool KiemTraMaGV(string);
	bool KiemTraMaLop(string);
	bool KiemTraThoiGianLopTapBiTrung(string);
	void NhapGV();
	void XuatGV();
	int SuaGV();
	void XoaGV();
	void TimKiemGV();
	void SapXepGiaoVienTheoTen();
	void SapXepGiaoVienTheoMaGV();

	void SapXepKhachHangTheoTen();
	void SapXepKhachHangTheoMaKH();
	//void SapXepKhachHangTheoGoiTap();


	void TKeKhachHangTheoGT();
	void TKeGiaoVienTheoGT();
	void TKeKhachHangTrongLop();

	float TinhTongLuongGiaoVienTheoTime(string, string);
	float TinhTongDoanhThuTheoTime(string, string);
	float TinhTongDoanhThu1Thang();
	float TinhTongLuongGiaoVien1Thang();

	void Menu(int);
	//void Nhap();
	//void Xuat();

	void NhapLT();
	void XuatLT();
	void SuaLT();
	void XoaLT();
	void TimKiemLT();


	//double TinhDoanhThu();


};
#endif

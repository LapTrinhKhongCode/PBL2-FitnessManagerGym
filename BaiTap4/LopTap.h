#pragma once
#ifndef LOPTAP
#define LOPTAP
#include "KhachHang.h"
#include"GiaoVien.h"


class LopTap
{
private:
	int slhv;
	string TenLop;
	string MaLop;
	string ThoiGian;
	string Max;
	string MaGVQuanLy;//khóa ngoại
	string* DanhSachMaKH;
	float HP1Thang;
public:
		LopTap() {
		slhv = 0; 
		TenLop = "";
		ThoiGian = "";
		Max = "";
		MaGVQuanLy = "";
		DanhSachMaKH = NULL;
	}
	void DocFile(string);
	string Getter_MaLT();
	string Getter_Max();
	string Getter_TenLop();
	string Getter_ThoiGian();
	string Getter_MaGVQL();
	float Getter_HP1Thang();
	void Setter_HP1Thang(float);
	int Getter_slhv();
	void Setter_Max(string);
	void Setter_slhv(int);
	void Setter_maGVQL(string);
	void Setter_ThoiGian(string);
	void Setter_MaLop(string);
	void ThemLop();
	void XoaLop();
	void SuaLop();
	void XuatLop();
	void XoaKHtrongLT(string);
	void ThemKHtrongLT(string);

};
#endif

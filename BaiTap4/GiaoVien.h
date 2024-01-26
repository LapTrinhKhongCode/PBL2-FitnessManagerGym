#ifndef GIAOVIEN
#define GIAOVIEN
#include "KhachHang.h"


class ThongTinGiaoVien : public ThongTinCaNhan
{
private:
	/*std::string Ho;
	std::string Ten;
	std::string GioiTinh;
	Birthday NgaySinh;
	Address DiaChi;
	string SDT;
	string Email;*/
	std::string MaGiaoVien;
	Date NgayBatDau;
	float Luong1Thang;
public:
	string Getter_SDT();
	string Getter_Email();
	string Getter_Name();
	string Getter_Ten();
	string Getter_MaGV();
	string Getter_GioiTinh();
	string Getter_NgaySinh();
	string Getter_DiaChi();
	string Getter_NamBatDau();
	string Getter_ThangBatDau();
	string Getter_AllNgayBatDau();
	float Getter_LuongGV();
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
	void Setter_MaGiaoVien(string);
	void Setter_LuongGV(float);
	//float TinhLuong3ThangGV();

	void DocFile(string);
	void XuatFile();
	void Nhap();
	void Xoa();
	void Sua();
	void Xuat();


};
#endif

//class DanhSachGiaoVien {
//private:
//	int slgv;
//	ThongTinGiaoVien* DanhSachGV;
//public:
//	DanhSachGiaoVien() {
//		slgv = 0;
//		DanhSachGV = NULL;
//	}
//	void Setter_SLGV(int);
//	void Nhap();
//	void DocFile();
//	void XuatFile();
//	void Xuat();
//	bool KiemTraEmailTrungLap(string);
//	bool KiemTraSDTTrungLap(string);
//
//};

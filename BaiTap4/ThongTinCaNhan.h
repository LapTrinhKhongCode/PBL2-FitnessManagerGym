#pragma once
#pragma warning (disable:4996)
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<fstream>
#include"Address.h"
#include"Date.h"
using namespace std;

class ThongTinCaNhan {
protected:
	std::string Ho;
	std::string Ten;
	std::string GioiTinh;
	Date NgaySinh;
	//std::string Tuoi;
	Address DiaChi;
	string SDT;
	string Email;
public:
	virtual string Getter_SDT() = 0;
	virtual string Getter_Email() = 0;
	virtual void DocFile(string) = 0;
	virtual void XuatFile() = 0;
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;

};

#pragma once
#pragma warning (disable:4996)
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<fstream>

using namespace std;



class Address {
private:
	string DiaChiCuThe;
	string XaPhuongThitran;
	string QuanHuyen;
	string TinhTPtw;
public:
	void Setter_DiaChiCuThe(string);
	void Setter_XaPhuongThitran(string);
	void Setter_QuanHuyen(string);
	void Setter_TinhTPtw(string);
	string Getter_AllAdress();
	void Nhap();
	void Xuat();

};


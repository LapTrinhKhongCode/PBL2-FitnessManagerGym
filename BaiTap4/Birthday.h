#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<fstream>
using namespace std;

class Birthday {
private:
	string Ngay;
	string Thang;
	string Nam;
public:
	void Setter_Ngay(string);
	void Setter_Thang(string);
	void Setter_Nam(string);
	string Getter_Ngay();
	string Getter_Thang();
	string Getter_Nam();
	void Nhap();
	void Xuat();
};

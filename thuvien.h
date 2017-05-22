#pragma once
#if !defined(THU_VIEN_H)
#include <string>
#define THU_VIEN_H
#define MAX_ACCOUNTS 5
using namespace std;
typedef struct {
	short ngay, thang, nam;
} date;
typedef struct {
	string Tendangnhap;
	string matkhau;
} S_dangnhap;
typedef struct {
	int sothutu;
	string hovaten;
	date ngaysinh;
	string sodienthoai;
	string email;
	bool giotinh;
	string vaitro;
	int sotaikhoan;
	S_dangnhap taikhoan_matkhau[MAX_ACCOUNTS];
}user;
void dangnhap();
void in();
void indangki();
void dangki();
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);
#endif

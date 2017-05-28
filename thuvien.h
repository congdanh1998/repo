#pragma once
#if !defined(THU_VIEN_H)
#include <string>
#define THU_VIEN_H
#define RONG 204
#define MAX_cot 20
using namespace std;
typedef struct {
	short ngay, thang, nam;
} date;
typedef struct {
	int id;
	string tendangnhap;
	string matkhau;
	int DS_muon[5];
} S_account;
typedef struct {
	int id;
	string hovaten;
	date ngaysinh;
	string mssv;
	string email;
	bool gioitinh;
	string vaitro;
} S_user;
typedef struct {
	int id;
	string tensach;
	string tacgia;
	string theloai;
} S_book;
void dangnhap();
void in();
void indangki();
void dangki();
void manhinhthongbao(string s);
void manhinhlamviec();
void manhinhdocgia(S_account& TAIKHOAN);
void luachonsach(S_account A[],int n,int CSO);
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);
void trasach(S_account A[],int CSO,int N);
#endif
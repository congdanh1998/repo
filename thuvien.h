#pragma once
#if !defined(THU_VIEN_H)
#include <string>
#define THU_VIEN_H
#define RONG 204
#define MAX_cot 20
#define GIA_1_CUON 15000
using namespace std;
typedef struct {
	short ngay, thang, nam;
} date;
typedef struct {
	int id, idu;
	string tendangnhap;
	string matkhau;
	int vaitro[3];
	int DS_muon[5];
	bool khoa;
} S_account;
typedef struct {
	int id;
	string hovaten;
	date ngaysinh;
	string mssv;
	string email;
	bool gioitinh, phat;
} S_user;
typedef struct {
	int id;
	string tensach;
	string tacgia;
	string theloai;
	int conlai;
} S_book;
typedef struct {
	int userid, bookid;
	date day;
} S_Book_Order;
void dangnhap();
void in();
void indangki();
void dangki();
void manhinhthongbao(string s);
void manhinhlamviec();
void sapxepgiam(int a[], int n);
void manhinhdocgia(S_account& TAIKHOAN);
void luachonsach(S_account A[], int n, int CSO);
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);
void trasach(S_account A[], int CSO, int N);
void doimatkhau(S_account A[], int CSO, int N);
void bangtim(S_book A[], int a[], int n, S_account& S, int & flag, bool cp = true, bool MR = true);
void timsach(S_account A[], int CSO, int N);
void inDSmuon(S_account A[], int N);
void them_sach();
void xoasach(S_account A[], int N, int CSO);
void chinhsuasach(S_account A[], int N, int CSO);
void DStre(S_account A[], int N);
void thong_bao(S_account A[], int N, int CSO);
void conv_longlong_money(string& str, int number);
void QLND(S_account A[],int N);
void QLTK(S_account A[],int N);
void them_user();
void xoanguoidung(S_account A[],int &N);
void suanguoidung(S_account A[],int &N);
void themtaikhoan(int N);
void Soataikhoan(S_account AA[],int &NN);
void Khoa_or_mo(S_account AA[],int &N);
#endif
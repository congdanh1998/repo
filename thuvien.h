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
	int id,idu;
	string tendangnhap;
	string matkhau;
	string vaitro;
	int DS_muon[5];
} S_account;
typedef struct {
	int id;
	string hovaten;
	date ngaysinh;
	string mssv;
	string email;
	bool gioitinh;
} S_user;
typedef struct {
	int id;
	string tensach;
	string tacgia;
	string theloai;
	int conlai;
} S_book;
typedef struct {
	int userid,bookid;
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
void luachonsach(S_account A[],int n,int CSO);
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);
void trasach(S_account A[],int CSO,int N);
void doimatkhau(S_account A[], int CSO, int N);
void bangtim(S_book A[],int a[],int n,S_account& S,int & flag,bool cp=true);
void timsach(S_account A[], int CSO, int N);
void manhinhthuthu(S_account& TAIKHOAN);
void inDSmuon(S_account A[], int N);
void them_sach();
void xoasach(S_account A[],int N,int CSO);
#endif
#if !defined(THU_VIEN_H)
#include <string>
#define THU_VIEN_H
using namespace std;
typedef struct{
	short ngay,thang,nam;
}date;
typedef struct user{
	string Tendangnhap;
	string matkhau;
	string hovaten;
	string email;
	date ngaysinh;
	string sodienthoai;
	bool giotinh;
}user;
void dangnhap();
void in();
void indangki();
void dangki();
void xulichuoi(string &s,char a,int &x,int y,int maxlen = 29);
#endif
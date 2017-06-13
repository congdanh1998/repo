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
	int id, idu;//ID cua tai khoan va ID cua nguoi dung so huu tai khoan nay
	string tendangnhap;
	string matkhau;
	int vaitro[3];
	int DS_muon[5];
	bool khoa;
} S_account;
typedef struct {//mang nay de luu thong tin ve mot nguoi dung
	int id;//ID cua nguoi dung,de phan biet voi cac nguoi dung khac
	string hovaten;
	date ngaysinh;
	string mssv;
	string email;
	bool gioitinh, phat;//phat de xem nguoi dung nay co bi phat hay ko, neu bi phat thi cac tai khoan cu nguoi dung nay se khong thuc hien duoc chuc nay cua doc gia
} S_user;
typedef struct {//struct nay de luu thong tin ve sach
	int id;//ID cua sach, de phan biet voi cac sach khac
	string tensach;
	string tacgia;
	string theloai;
	int conlai;//so luong con lai,neu so luong bang 0 thi khong the muon duoc cuon nay nua
} S_book;
typedef struct {//struct nay dung de luu lai thong tinve mot lan muon sach
	int userid, bookid;//ID cua tai khoan muon va ID cua sach muon
	date day;//ngay muon
} S_Book_Order;
void dangnhap();//ham dung de xu li viec dang nhap
void in();//in an hinh chinh
void indangki();//in man hinh dang ki
void dangki();//ham xu li dag ki
void manhinhthongbao(string s);//xuat ra thong bao dang chuoi
void manhinhlamviec();//man hinh sau khi dang nhap thang cong
void sapxepgiam(int a[], int n);//de sap xep ==> de quan li hon
void manhinhdocgia(S_account& TAIKHOAN);//in va thuc hien cac chuc nang cua TAIKHOAN tuong ung voi mang vaitro[]
void luachonsach(S_account A[], int n, int CSO);//ham chon sach de muon
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);//ham de xu li viec nhap mot chuoi
void trasach(S_account A[], int CSO, int N);//xu li viec tra sach cua mot doc gia
void doimatkhau(S_account A[], int CSO, int N);//doi mat khau cho mot tai khoan
void bangtim(S_book A[], int a[], int n, S_account& S, int & flag, bool cp = true, bool MR = true);//tim sach va thuc hien chon sach
void timsach(S_account A[], int CSO, int N);//tim sach xong roi muon sach vua tim duoc
void inDSmuon(S_account A[], int N);//in ra danh sach muon gom ten sach nguoi muon ngay muon ,chuc nang thu thu
void them_sach();//giup thu thu them mot dau sach moi
void xoasach(S_account A[], int N, int CSO);//xoa mot dau sach
void chinhsuasach(S_account A[], int N, int CSO);//chinh sua thong tin ve mot cuon sach
void DStre(S_account A[], int N);//danh sach cac phieu muon sach qua 5 ngay
void thong_bao(S_account A[], int N, int CSO);//xem cac sach da muon,thong bao ve phat tra sach...
void conv_longlong_money(string& str, int number);//doi so thang chuoi co don vi tien o sau
void QLND(S_account A[], int N);//in chuc nang ve quan li nguoi dung
void QLTK(S_account A[], int N);//in chuc nang ve quan li tai khoan
void them_user();//them mot user moi,chuc nang cua QUAN LI
void xoanguoidung(S_account A[], int &N);//xoa mot user va tai khoan cua user do
void suanguoidung(S_account A[], int &N);//sua lai cac thong tin cua mot nguoi dung(co the tim vao xem thong tin voi chuc nang nay)
void themtaikhoan(int N);//them mot tai khoan ung voi mot nguoi dung duoc chon
void Xoataikhoan(S_account AA[], int &NN);//Xoa mot hay mot vai tai khoan khoi he thong
void Khoa_or_mo(S_account AA[], int &N);//Khoa hay mo mot tai khoan duoc chon
void toogle_passwork(S_account AA[], int &N);//reset lai mat khau
string str_to_name(string s);//chuyen "_" thanh " " trong ten
void name_to_str(string& s);//chuyen " " thanh "_" trong ten
#endif

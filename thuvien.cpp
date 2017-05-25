#include <iostream>
#include <iomanip>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include "dohoa.h"
#include "thuvien.h"
//luu dohoa.h o dau thi chi duong dan toi do
using namespace std;
//ham xu li trong man hinh dang nhap
void indangnhap(string TDN, string MK) {
	textcolor(112);
	system("cls");
	cout << "EsC de thoat khoi cua so";
	textcolor(6);
	hinhchunhat(178, 5, 1, 60, 25);
	hinhchunhat(219, 6, 2, 58, 23);
	HCN2(15, 7, 3, 58, 22);
	HCN2(7, 15, 6, 40, 4);
	HCN2(7, 15, 11, 40, 4);
	//in dong de viet
	HCN2(15, 20, 8, 30, 1);
	HCN2(15, 20, 13, 30, 1);
	textcolor(240);
	gotoxy(20, 8);cout << TDN;
	gotoxy(20, 13);for (int i = 1;i <= MK.length();i++) cout << "*";
	textcolor(7 * 16 + 14);
	gotoxy(20, 7);
	cout << "TEN DANG NHAP:";
<<<<<<< HEAD

	gotoxy(20, 12);
	cout << "  MAT KHAU:   ";

	gotoxy(10, 22);
	cout << " DANG NHAP ";

=======

	gotoxy(20, 12);
	cout << "  MAT KHAU:   ";

	gotoxy(10, 22);
	cout << " DANG NHAP ";

>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
	gotoxy(50, 22);
	cout << " tro lai ";
};
void dangnhap() {
	string TDN = "", MK = "";//bien luu ten dang va mat khau
	indangnhap(TDN, MK);

	fstream f;
<<<<<<< HEAD
	string data;//, ignore_str;
	int num_of_accounts=get_F_N("accounts_infor.txt")+1;

	f.open("accounts_infor.txt", ios::in);
	//getline(f, data); stringstream scin(data);
	//scin >> ignore_str; scin >> num_of_accounts;
=======
	string data, ignore_str;
	int num_of_accounts;

	f.open("accounts_infor.txt", ios::in);
	getline(f, data); stringstream scin(data);
	scin >> ignore_str; scin >> num_of_accounts;
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
	S_account* list_accounts = new S_account[num_of_accounts];
	for (int i = 0;i < num_of_accounts;i++) {
		getline(f, data); stringstream scin(data);
		scin >> list_accounts[i].id;
		scin >> list_accounts[i].tendangnhap;
		scin >> list_accounts[i].matkhau;
	}
	f.close();

	int x = 20, xo = 20;//vi tri bat dau nhap ten va mat khau(hoang do)
	int thoat = 1, cv = 1;
	while (thoat) {
		//in ra mui ten de cho nguoi dung biet vi tri dang duoc chon
		textcolor(254);//mau khung chon
		if (cv<3) {
			hinhchunhat(219, 14, cv * 5, 40, 5);//\20 va \21 la hai dau mui ten trong bang ma ASCII
		}
		else if (cv == 3) {
			hinhchunhat(219, 9, 21, 11, 2);
		}
		else {
			hinhchunhat(219, 49, 21, 9, 2);
		}
		//xu li khi nhan phim tren bang phim
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 4; }
		if (cv == 5) { cv = 1; }
		if ((cv == 4) && (c == 13)) { thoat = 0; }//thoat khi chon muc 4
		if (c == 27) { thoat = 0; }//thoat khi go phim Esc
								   //xu li nhap chuoi khi chon muc TEN DANG NHAP
		if ((cv == 1) && (c == 13)) {
			xulichuoi(TDN, 'y', x, 8);
		}
		//xu li nhap chuoi khi chon MAT KHAU(gan tuong tu nhu nhap TDN)
		if ((cv == 2) && (c == 13)) {
			xulichuoi(MK, 'n', xo, 13);
		}
		//xu li kiem tra xem ten dang nhap va mat khau da dung chua
		if ((cv == 3) && (c == 13)) {
			bool bOutOfLoop = false;
			for (int i = 0;i < num_of_accounts && !bOutOfLoop;i++) {
				if ((TDN == list_accounts[i].tendangnhap) && (MK == list_accounts[i].matkhau)) {
					manhinhthongbao("DANG DANG NHAP ...");
					manhinhlamviec();
					thoat = 0;
					bOutOfLoop = true;
				}
			}
			if (bOutOfLoop == false) {
				manhinhthongbao("SAI TEN DANG NHAP HOAC MAT KHAU");
				indangnhap(TDN, MK);
			}
		}
		//xoa cac mui ten o truoc khi chuyen sang muc khac
		textcolor(247);
		if (cv1<3) {
			hinhchunhat(32, 14, cv1 * 5, 40, 5);
			//cout<<"   ";
		}
		else if (cv1 == 3) {
			hinhchunhat(32, 9, 21, 11, 2);
		}
		else {
			hinhchunhat(32, 49, 21, 9, 2);
		}
	}
	delete[] list_accounts; list_accounts = NULL;
}
//ham in ra man hinh chinh
void in() {
	textcolor(255);
	system("cls");
	//char a=219;
	cout << "nhan Enter de chon, EsC de thoat khoi cua so" << endl;
	textcolor(254);
	cout << "      (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)       (_)(_)        " << endl
		<< "      (_)        (_)  (_)     (_)   (_)     (_)  (_)     (_)  (_)      (_)     " << endl
		<< "      (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)    (_)      (_)     " << endl
		<< "      (_)        (_)  (_)     (_)   (_)          (_)   (_)    (_)      (_)     " << endl
		<< "      (_)(_)(_)  (_)  (_)(_)(_)     (_)          (_)     (_)     (_)(_)        " << endl;

	//ve khung
	textcolor(11);
	hinhchunhat(178, 12, 11, 40, 30);//tao hinh chu nhat tu ki tu co ma ASCII 178(bat dau o toa do (10,10) canh 40x30)
	hinhchunhat(219, 13, 12, 38, 28);//tao hinh chu nhat tu ki tu co ma ASCII 219
	HCN2(6, 14, 13, 38, 27);
	HCN2(7, 19, 17, 29, 3);
	HCN2(7, 19, 24, 29, 3);
	HCN2(7, 19, 31, 29, 3);
	//textcolor(14);
	//hinhchunhat(178,18,16,29,4);
	//hinhchunhat(178,18,23,29,4);
	//hinhchunhat(178,18,30,29,4);
	textcolor(121);
	//in noi dung
	gotoxy(28, 18);
	cout << "DANG NHAP";

	gotoxy(28, 25);
	cout << " DANG KI ";

	gotoxy(28, 32);
	cout << " TRO LAI ";

};
//ham xulichuoi chuoi tra ve la s,a='y' khi nhan ten va con lai khi nhan mat khau
//x,y la toa do bat dau doc du lieu tu ban phim
void xulichuoi(string &s, char a, int &x, int y, int maxlen) {
	char ch;
	int M = x + maxlen - s.length(), m = x + 1 - s.length();	//chuoi chi co 30 ki tu la dai nhat
	textcolor(15 * 16);
	gotoxy(x, y);
	do {
		ch = _getch();
		//xu li khi nhan Backspace
		if (ch == 8 && x >= m) {
			gotoxy(x - 1, y);
			cout << " ";
			gotoxy(x - 1, y);
			x--;
			s.erase(s.length() - 1, 1);
		}
		else if ((ch != 13) && (ch != 9) && (ch != 11) && (ch >= 32) && (ch <= 126) && (x <= M)) {
			//chi lay ma ASCII tu 32-126 va khi chuoi nho hon 30 ki tu
			if (a == 'y') {
				cout << ch;
			}
			else {
				cout << "*";
			};
			s = s + ch;
			x++;
			gotoxy(x, y);
		}
	} while ((ch != 13) && (ch != 9) && (ch != 11));
}
void indangki() {//ham in ra man hinh dang ki

	textcolor(255);
	system("cls");
	cout << "EsC de thoat khoi cua so";
	textcolor(6);
	hinhchunhat(178, 5, 1, 60, 57);
	hinhchunhat(219, 6, 2, 58, 55);
	HCN2(3, 7, 3, 58, 54);

	gotoxy(15, 7);
	textcolor(62);
	cout << "HO VA TEN :";
	ToMau(15, 8, "                              ", 255, 62);
	gotoxy(15, 14);
	cout << "NGAY THANG NAM SINH:   ";
	gotoxy(15, 15);
	cout << "ngay:          thang:          nam:          ";
	ToMau(22, 15, "    ", 255, 62);ToMau(37, 15, "    ", 255, 62);ToMau(51, 15, "    ", 255, 62);
	gotoxy(15, 21);
	cout << "Email: ";
	ToMau(15, 22, "                              ", 255, 62);
	gotoxy(15, 28);
	cout << "Ma so sinh vien: ";
	ToMau(15, 29, "                    ", 255, 62);

	gotoxy(45, 28);
	cout << "gioi tinh: ";
	gotoxy(45, 29);
	cout << "Nam:          nu:";
	ToMau(50, 29, " ", 255, 14);ToMau(63, 29, " ", 255, 62);
	gotoxy(10, 31);
	cout << "*THONG TIN TEN NGUOI DUNG VA MAT KHAU";

	HCN2(7, 10, 34, 40, 4);
	textcolor(7 * 16 + 14);
	gotoxy(15, 35);cout << "Ten Dang Nhap:";
	HCN2(7, 10, 41, 40, 4);
	ToMau(15, 36, "                              ", 255, 7 * 16 + 14);
	gotoxy(15, 42);cout << "Mat Khau:";
	HCN2(7, 10, 48, 40, 4);
	ToMau(15, 43, "                              ", 255, 7 * 16 + 14);
	gotoxy(15, 49);cout << "Xac Nhan Lai Mat Khau:";
	ToMau(15, 50, "                              ", 255, 7);
	ToMau(12, 55, " GUI DANG KI ", 126, 7);
	ToMau(40, 55, " TRO LAI ", 126, 7);
}
void nhapngay(int&x, int&y, int&z, string&a, string&b, string&d) {//ham nhap ngay thang nam sinh
	string ng, th, n;//cac chuoi ung voi ngay thang nam
<<<<<<< HEAD
	
=======
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
	int X[3] = { 21,36,50 };//vi tri nhap chuoi(da biet truoc)
	int thoat = 1, cv = 1;
	while (thoat) {
		textcolor(59);
		gotoxy(X[cv - 1], 15);cout << "\20";gotoxy(X[cv - 1] + 5, 15);cout << "\21";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 3; }
		if (cv == 4) { cv = 1; }
<<<<<<< HEAD
		if ((cv == 3) && (c == 13)) { xulichuoi(d, 'y', z, 15, 3 - z + 51); }
		if ((cv == 1) && (c == 13)) { xulichuoi(a, 'y', x, 15, 1 - x + 22); }
		if ((cv == 2) && (c == 13)) { xulichuoi(b, 'y', y, 15, 1 - y + 37); }
=======
		if ((cv == 3) && (c == 13)) { xulichuoi(n, 'y', z, 15, 3 - z + 51);stringstream(n) >> d; }
		if ((cv == 1) && (c == 13)) { xulichuoi(ng, 'y', x, 15, 1 - x + 22);stringstream(ng) >> a; }
		if ((cv == 2) && (c == 13)) { xulichuoi(th, 'y', y, 15, 1 - y + 37);stringstream(th) >> b; }
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
		if (c == 27) { thoat = 0; }
		gotoxy(X[cv1 - 1], 15);cout << " ";gotoxy(X[cv1 - 1] + 5, 15);cout << " ";
	}
};
void GT(bool &X) {//ham nhap gioi tinh
	int thoat = 1, cv = 1;
	int x[2] = { 49,62 };//vi tri hoang do nhap gioi tinh
	while (thoat) {
		textcolor(59);
		gotoxy(x[cv - 1], 29);cout << "\20";gotoxy(x[cv - 1] + 2, 29);cout << "\21";//in con tro danh dau
		char c = _getch();//nhan tin hieu dieu khien
		int cv1 = cv;//luu tin hieu dieu khien cu
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 2; }
		if (cv == 3) { cv = 1; }
		if ((cv == 1) && (c == 13)) { ToMau(50, 29, "x", 240);ToMau(63, 29, " ", 240, 59);X = true; }//danh dau vao o Nam bo danh dau o Nu
		if ((cv == 2) && (c == 13)) { ToMau(50, 29, " ", 240);ToMau(63, 29, "x", 240, 59);X = false; }//danh dau vao o Nu bo danh dau o Nam
		if (c == 27) { thoat = 0; }//thoat khi go EsC
		gotoxy(x[cv1 - 1], 29);cout << " ";gotoxy(x[cv1 - 1] + 2, 29);cout << " ";//xoa vi tri con tro cu
	}
};
void dangki() {
	S_user A_user;//khoi tao 1 user moi
	S_account A_account;

	string ngay, thang, nam;
	A_user.ngaysinh.ngay = A_user.ngaysinh.thang = A_user.ngaysinh.nam = 0;

	string xnmk = "";//bien luu mat khau xac nhan xem co trung voi mat khau da nhap hay ko
	int x1 = 15, x2 = 15, x3 = 15, x4 = 15, x5 = 22, x6 = 37, x7 = 51, x8 = 15, x9 = 15;//hoang do nhap chuoi thong tin cua cac du lieu
	indangki();
	int thoat = 1, cv = 1;//thoat khoi man hinh DANGKI khi thoat=0 | cv dung de dieu khien chuong trinh
	while (thoat) {
		textcolor(59);
		//dong lenh dieu chinh vi tri phu hop cho con tro
		if (cv<5) { gotoxy(12, cv * 7);cout << "\20\20"; }
		else if (cv == 5) { gotoxy(42, 28);cout << "\20\20"; }
		else if (cv <= 8) { hinhchunhat(219, 9, cv * 7 - 9, 40, 5); }
		else if (cv == 9) { hinhchunhat(219, 11, 54, 13, 2); }
		else { hinhchunhat(219, 39, 54, 9, 2); }
		//dieu kieu di chuyen
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 10; }
		if (cv == 11) { cv = 1; }
		//thuc hien cong viec ung voi cv= va khi nhan Enter
		if ((cv == 1) && (c == 13)) { xulichuoi(A_user.hovaten, 'y', x3, 8); }//nhap ten
		if ((cv == 2) && (c == 13)) { nhapngay(x5, x6, x7, ngay, thang, nam); }//nhap ngay thang nam sinh
		if ((cv == 5) && (c == 13)) { GT(A_user.gioitinh); }//nhap gioi tinh
		if ((cv == 3) && (c == 13)) { xulichuoi(A_user.email, 'y', x4, 22); }//nhap email lien lac
		if ((cv == 4) && (c == 13)) { xulichuoi(A_user.mssv, 'y', x8, 29, 19); }//nhap mssv
		if ((cv == 6) && (c == 13)) { xulichuoi(A_account.tendangnhap, 'y', x1, 36); }//nhap ten dang nhap
		if ((cv == 7) && (c == 13)) { xulichuoi(A_account.matkhau, 'n', x2, 43); }//nhap mat khau
		if ((cv == 8) && (c == 13)) { xulichuoi(xnmk, 'n', x9, 50); }//nhap mat khau xac nhan
		if ((cv == 9) && (c == 13)) {//in ra file luu nguoi dung
			//gan va kiem tra xem ngay thang nam co phai la so khong
			int num_ngay = -1, num_thang = -1, num_nam = -1;
			bool no_error_age = true, no_error_date = true, no_error_all = true;
			stringstream scin1(ngay);
			do {
				num_ngay++;
				scin1 >> A_user.ngaysinh.ngay;
			} while (!scin1.fail());
			stringstream scin2(thang);
			do {
				num_thang++;
				scin2 >> A_user.ngaysinh.thang;
			} while (!scin2.fail());
			stringstream scin3(nam);
			do {
				num_nam++;
				scin3 >> A_user.ngaysinh.nam;
			} while (!scin3.fail());
			//
			if (num_ngay != 1 || num_thang != 1 || num_nam != 1) {
				no_error_date = false;
			}
			else {
				if (A_user.ngaysinh.thang == 2 && A_user.ngaysinh.ngay == 29) {
					float ti_le = (float)(2004 - A_user.ngaysinh.nam) / 4;
<<<<<<< HEAD
					if (ti_le != int(ti_le)) no_error_date = false;
				}
				else {
					if ((A_user.ngaysinh.thang == 1 || A_user.ngaysinh.thang == 3 || A_user.ngaysinh.thang == 5 || A_user.ngaysinh.thang == 7 || A_user.ngaysinh.thang == 8
						|| A_user.ngaysinh.thang == 10 || A_user.ngaysinh.thang == 12) && A_user.ngaysinh.ngay > 31) {
						no_error_date = false;
					}
					else {
						if ((A_user.ngaysinh.thang == 4 || A_user.ngaysinh.thang == 6 || A_user.ngaysinh.thang == 9 || A_user.ngaysinh.thang == 11) && A_user.ngaysinh.ngay > 30) {
=======
					if (ti_le != round(ti_le)) no_error_date = false;
				}
				else {
					if ((A_user.ngaysinh.thang == 1 || A_user.ngaysinh.thang == 3 || A_user.ngaysinh.thang == 5 || A_user.ngaysinh.thang == 7 || A_user.ngaysinh.thang == 8
						|| A_user.ngaysinh.thang == 10 || A_user.ngaysinh.thang == 12) && A_user.ngaysinh.ngay != 31) {
						no_error_date = false;
					}
					else {
						if ((A_user.ngaysinh.thang == 4 || A_user.ngaysinh.thang == 6 || A_user.ngaysinh.thang == 9 || A_user.ngaysinh.thang == 11) && A_user.ngaysinh.ngay != 31) {
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
							no_error_date = false;
						}
					}
				}
			}
			//
			if (A_user.hovaten == "" || ngay == "" || thang == "" || nam == "" || A_user.gioitinh == RONG ||
				A_user.email == "" || A_user.mssv == "" || A_account.tendangnhap == "" || A_account.matkhau == "" || xnmk == "") {
				//#define RONG 204        hinh nhu khong chon gi het thi gioi tinh bang 204 hay sao y
				no_error_all = false;
				gotoxy(0, 60);
				cout << "* NHAP THIEU THONG TIN";
			}
			else {
				if (no_error_date == false) {
					no_error_all = false;
					gotoxy(0, 60);
					cout << "* NGAY THANG NAM SINH KHONG HOP LE";
				}
				else {
					if (A_user.ngaysinh.nam < 1867) {
						no_error_age = false;
						gotoxy(0, 60);
						cout << "* BAN QUA LON TUOI DE DANG KI SU DUNG THU VIEN (>150 TUOI)";
					}
					else {
						if (A_user.ngaysinh.nam > 2007) {
							no_error_age = false;
							gotoxy(0, 60);
							cout << "* BAN CHUA DU TUOI DE DANG KI SU DUNG THU VIEN (<15 TUOI)";
						}
					}
				}
			}
			if (A_account.matkhau != xnmk) {
				no_error_all = false;
				gotoxy(0, 61);
				cout << "* XAC NHAN SAI MAT KHAU";
			}
			for (int i = 0;i < A_account.matkhau.length();i++) {
				if (A_account.matkhau.length() < 5 || A_account.matkhau.length() > 15 || ((int)A_account.matkhau[i] < 48) || ((int)A_account.matkhau[i] > 57 && (int)A_account.matkhau[i] < 65) || ((int)A_account.matkhau[i] > 90 && (int)A_account.matkhau[i] < 97) || ((int)A_account.matkhau[i] > 122)) {
					no_error_all = false;
					gotoxy(0, 62);
					cout << "* MAT KHAU PHAI DAI TU 5 DEN 15 KI TU CHI CHUA CHU CAI HOAC SO";
				}
			}
			for (int i = 0;i < A_account.tendangnhap.length();i++) {
<<<<<<< HEAD
				if (A_account.tendangnhap.length() < 5 || A_account.tendangnhap.length() > 20 || ((int)A_account.tendangnhap[i] < 48) || ((int)A_account.tendangnhap[i] > 57 && (int)A_account.tendangnhap[i] < 65) || ((int)A_account.tendangnhap[i] > 90 && (int)A_account.tendangnhap[i] < 97) || ((int)A_account.tendangnhap[i] > 122)) {
=======
				if (A_account.tendangnhap.length() < 5 | A_account.tendangnhap.length() > 20 || ((int)A_account.tendangnhap[i] < 48) || ((int)A_account.tendangnhap[i] > 57 && (int)A_account.tendangnhap[i] < 65) || ((int)A_account.tendangnhap[i] > 90 && (int)A_account.tendangnhap[i] < 97) || ((int)A_account.tendangnhap[i] > 122)) {
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
					no_error_all = false;
					gotoxy(0, 63);
					cout << "* TEN DANG NHAP PHAI DAI TU 5 DEN 20 KI TU CHI CHUA CHU CAI HOAC SO";
				}
			}
			if (no_error_all == true && no_error_date == true && no_error_age == true) {
				fstream f;
<<<<<<< HEAD
	
				A_user.id = get_F_N("users_infor.txt")+1;
=======
				int num_of_users;
				string ignore_str, data;
				f.open("users_infor.txt", ios::in);
				getline(f, data); stringstream scin(data);
				scin >> ignore_str; scin >> num_of_users;
				f.close();

				num_of_users++;
				A_user.id = num_of_users;
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
				A_user.vaitro = "doc_gia";
				string connect;
				stringstream word(A_user.hovaten);
				A_user.hovaten = "";
				int skip_1st = 0;
				word >> connect;
				do {
					if (skip_1st != 0) A_user.hovaten += "_";
					skip_1st++;
					A_user.hovaten += connect;
					word >> connect;
				} while (!word.fail());

				f.open("users_infor.txt", ios::app);
				//outfile.write(reinterpret_cast<char*>(&A_user), sizeof(S_user));//ma hoa thanh nhi phan ma ko bit co tac dung ko(chua thanh thao) co khi cu xai o duoi truoc
				f << setw(5) << left << A_user.id
					<< setw(35) << left << A_user.hovaten;
				if (A_user.ngaysinh.ngay >= 10) f << A_user.ngaysinh.ngay << "/";
				else f << "0" << A_user.ngaysinh.ngay << "/";
				if (A_user.ngaysinh.thang >= 10)f << A_user.ngaysinh.thang << "/";
				else f << "0" << A_user.ngaysinh.thang << "/";
				f << setw(10) << left << A_user.ngaysinh.nam
					<< setw(15) << left << A_user.mssv
					<< setw(35) << left << A_user.email
					<< setw(5) << left << A_user.gioitinh
					<< setw(10) << left << A_user.vaitro << endl;
<<<<<<< HEAD
				
				
				f.close();
				A_account.id = A_user.id;
				
=======
				f.close();
				A_account.id = A_user.id;
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
				f.open("accounts_infor.txt", ios::app);
				f << setw(5) << A_account.id
					<< setw(25) << left << A_account.tendangnhap
					<< setw(20) << left << A_account.matkhau << endl;
<<<<<<< HEAD
			
				f.close();
				thoat = 0;
			}
			else { _getch(); }
=======
				f.close();
				thoat = 0;
			}
			else { _getch();dangki(); }
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
		}
		if (((cv == 10) && (c == 13)) || (c == 27)) { thoat = 0; }//thoat ra man hinh chinh
		textcolor(48);
		//xoa vi tri con tro truoc khi chuyen sang cho khac
		if (cv1<5) { gotoxy(12, cv1 * 7);cout << "  "; }
		else if (cv1 == 5) { gotoxy(42, 28);cout << "  "; }
		else if (cv1 <= 8) { hinhchunhat(32, 9, cv1 * 7 - 9, 40, 5); }
		else if (cv1 == 9) { hinhchunhat(32, 11, 54, 13, 2); }
		else { hinhchunhat(32, 39, 54, 9, 2); }
	}

};
void manhinhthongbao(string s) {
	HCN2(3, 20, 10, 40, 5);
	textcolor(49);
	int a = (40 - s.length()) / 2;
	gotoxy(20 + a, 12);cout << s;
	Sleep(2000);
};
void manhinhlamviec() {
	textcolor(240);
	system("cls");
	resizeConsole(99, 60);
	inbang("Ten Sach", "Con Lai", "Tac Gia");
	hinhchunhat(219, 0, 5, 28, 20);
	ToMau(5, 6, "Thong tin chi tiet", 243, 240);
	ToMau(0, 28, "Cac chuc nang chinh", 15, 240);
	hinhchunhat(219, 0, 29, 50, 15);
	hinhchunhat(219, 52, 29, 45, 15);
	_getch();
};
<<<<<<< HEAD

int get_F_N(string File){
	fstream f;
	string line;
	int num_of_users=-2;
	f.open(File, ios::in);
	while(!f.eof()){getline(f,line);num_of_users++;}
	return num_of_users;
};
=======
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e

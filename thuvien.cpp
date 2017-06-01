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
#include "xulifile.h"
//luu dohoa.h o dau thi chi duong dan toi do
using namespace std;
//ham xu li trong man hinh dang nhap
void manhinhluachon(string s) {
	HCN2(3, 27, 60, 40, 5);
	textcolor(49);
	int a = (40 - s.length()) / 2;
	gotoxy(30 + a, 61);cout << s;
	ToMau(34, 63, "  CO   ", 126, 7);
	ToMau(54, 63, " KHONG ", 126, 7);
};
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

	gotoxy(20, 12);
	cout << "  MAT KHAU:   ";

	gotoxy(10, 22);
	cout << " DANG NHAP ";

	gotoxy(50, 22);
	cout << " TRO LAI ";
};
void dangnhap() {
	string TDN = "", MK = "";//bien luu ten dang va mat khau
	indangnhap(TDN, MK);

	//fstream f;
	string data;//, ignore_str;
	int num_of_accounts = get_F_N("accounts_infor.txt");
	int the_choosen_one = -1;
	//f.open("accounts_infor.txt", ios::in);
	//getline(f, data); stringstream scin(data);
	//scin >> ignore_str; scin >> num_of_accounts;
	S_account* list_accounts = new S_account[num_of_accounts];
	//for (int i = 0;i < num_of_accounts;i++) {
	//	getline(f, data); stringstream scin(data);
	//	scin >> list_accounts[i].id;
	//	scin >> list_accounts[i].tendangnhap;
	//	scin >> list_accounts[i].matkhau;
	//}
	//f.close();
	GetFileAccountsData(list_accounts, num_of_accounts);

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
					the_choosen_one = i;
					thoat = 0;
					bOutOfLoop = true;
					break;
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
	if (the_choosen_one != -1) { manhinhdocgia(list_accounts[the_choosen_one]); }
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
		if ((cv == 3) && (c == 13)) { xulichuoi(d, 'y', z, 15, 3 - z + 51); }
		if ((cv == 1) && (c == 13)) { xulichuoi(a, 'y', x, 15, 1 - x + 22); }
		if ((cv == 2) && (c == 13)) { xulichuoi(b, 'y', y, 15, 1 - y + 37); }
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
					if (ti_le != int(ti_le)) no_error_date = false;
				}
				else {
					if ((A_user.ngaysinh.thang == 1 || A_user.ngaysinh.thang == 3 || A_user.ngaysinh.thang == 5 || A_user.ngaysinh.thang == 7 || A_user.ngaysinh.thang == 8
						|| A_user.ngaysinh.thang == 10 || A_user.ngaysinh.thang == 12) && A_user.ngaysinh.ngay > 31) {
						no_error_date = false;
					}
					else {
						if ((A_user.ngaysinh.thang == 4 || A_user.ngaysinh.thang == 6 || A_user.ngaysinh.thang == 9 || A_user.ngaysinh.thang == 11) && A_user.ngaysinh.ngay > 30) {
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
							cout << "* BAN CHUA DU TUOI DE DANG KI SU DUNG THU VIEN (<10 TUOI)";
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
				if (A_account.tendangnhap.length() < 5 || A_account.tendangnhap.length() > 20 || ((int)A_account.tendangnhap[i] < 48) || ((int)A_account.tendangnhap[i] > 57 && (int)A_account.tendangnhap[i] < 65) || ((int)A_account.tendangnhap[i] > 90 && (int)A_account.tendangnhap[i] < 97) || ((int)A_account.tendangnhap[i] > 122)) {
					no_error_all = false;
					gotoxy(0, 63);
					cout << "* TEN DANG NHAP PHAI DAI TU 5 DEN 20 KI TU CHI CHUA CHU CAI HOAC SO";
				}
			}
			if (no_error_all == true && no_error_date == true && no_error_age == true) {
				fstream f;

				A_user.id = get_F_N("users_infor.txt") + 1;
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


				f.close();
				A_account.id = A_user.id;

				f.open("accounts_infor.txt", ios::app);
				f << setw(5) << A_account.id
					<< setw(25) << left << A_account.tendangnhap
					<< setw(20) << left << A_account.matkhau
					<< left << "0 0 0 0 0" << endl;

				f.close();
				thoat = 0;
				HCN2(15, 0, 60, 60, 6);
				gotoxy(0, 60);textcolor(59);
				cout << "DANG KI THANH CONG";
				Sleep(2000);
			}
			else  _getch();
		}
		if (((cv == 10) && (c == 13)) || (c == 27)) {
			int cv2 = 0, thoat1 = 1;
			while (thoat1) {
				manhinhluachon("Ban muon huy dang ki ?");
				gotoxy(33 + cv2 * 20, 63);
				cout << "\20";
				gotoxy(41 + cv2 * 20, 63);
				cout << "\21";
				char c1 = _getch();
				int cv3 = cv2;
				if (c1 == 'H' || c1 == 'K') { cv2--; }
				if (c1 == 'P' || c1 == 'M') { cv2++; }
				if (cv2 == -1) { cv2 = 1; }
				if (cv2 == 2) { cv2 = 0; }
				if (cv2 == 0 && c1 == 13) { thoat1 = 0;thoat = 0; }
				if ((cv2 == 1 && c1 == 13) || c1 == 27) {
					thoat1 = 0;
					HCN2(15, 27, 60, 40, 5);
				}
			}
		}
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
	HCN2(3, 15, 16, 40, 3);
	textcolor(49);
	int a = (40 - s.length()) / 2;
	gotoxy(15 + a, 17);cout << s;
	Sleep(2000);
};
void manhinhlamviec() {
	textcolor(240);
	system("cls");
	resizeConsole(99, 60);
	inbang("Ten Sach", "The loai", "Tac Gia");
	hinhchunhat(219, 0, 5, 28, 20);
	ToMau(5, 6, "Thong tin nguoi dung", 243, 240);
	ToMau(0, 28, "Cac chuc nang chinh", 15, 240);
	hinhchunhat(219, 0, 29, 50, 17);
	hinhchunhat(219, 52, 29, 45, 17);
};
void manhinhdocgia(S_account& TAIKHOAN) {
	manhinhlamviec();
	S_account * list_account;
	int sotaikhoan = get_F_N("accounts_infor.txt");
	list_account = new S_account[sotaikhoan];
	GetFileAccountsData(list_account, sotaikhoan);
	fstream f;
	f.open("users_infor.txt", ios::in);
	string data, NTNS, GT[2] = { "nu","nam" };
	S_user choosen_user;
	do {
		getline(f, data);
		stringstream scin(data);
		scin >> choosen_user.id;
		if (choosen_user.id == TAIKHOAN.id) {
			scin >> choosen_user.hovaten;
			scin >> NTNS;
			scin >> choosen_user.mssv;
			scin >> choosen_user.email;
			scin >> choosen_user.gioitinh;
			scin >> choosen_user.vaitro;

		}
	} while (choosen_user.id != TAIKHOAN.id);

	for (int i = 0;i < choosen_user.hovaten.length();i++) {
		if (choosen_user.hovaten[i] == '_')	 choosen_user.hovaten[i] = ' ';
	}

	f.close();
	gotoxy(3, 7);cout << "Ho va ten: ";
	gotoxy(3, 8);cout << choosen_user.hovaten;
	gotoxy(3, 12);cout << "Ngay thang nam sinh: ";
	gotoxy(3, 13);cout << NTNS;
	gotoxy(3, 15);cout << "Email: ";
	gotoxy(3, 16);cout << choosen_user.email;
	gotoxy(3, 18);cout << "Gioi tinh: " << GT[choosen_user.gioitinh];
	gotoxy(3, 21);cout << "MSSV: " << choosen_user.mssv;

	gotoxy(15, 31);cout << "    TIM SACH         ";
	gotoxy(15, 33);cout << "    LUA CHON SACH    ";
	gotoxy(15, 35);cout << "    XEM THONG BAO    ";
	gotoxy(15, 37);cout << "    THEM TAI KHOAN   ";
	gotoxy(15, 39);cout << "    DOI MAT KHAU     ";
	gotoxy(15, 41);cout << "    TRA SACH         ";
	gotoxy(15, 43);cout << "    DANG XUAT        ";
	int cv = 1, thoat = 1;
	while (thoat) {
		gotoxy(13, 29 + 2 * cv);
		cout << "\20";
		gotoxy(36, 29 + 2 * cv);
		cout << "\21";

		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 7; }
		if (cv == 8) { cv = 1; }

		if ((cv == 1) && (c == 13)) { timsach(list_account, TAIKHOAN.id - 1, sotaikhoan);}
		if ((cv == 2) && (c == 13)) { luachonsach(list_account, sotaikhoan, TAIKHOAN.id); }
		if ((cv == 5) && (c == 13)) { doimatkhau(list_account, TAIKHOAN.id - 1, sotaikhoan);}
		if ((cv == 6) && (c == 13)) { trasach(list_account, TAIKHOAN.id - 1, sotaikhoan); }

		
		if ((c == 27) || (cv == 7) && (c == 13)) {
			int cv2 = 0, thoat1 = 1;	
			while (thoat1) {
				manhinhluachon("Ban co muon dang xuat ?");
				gotoxy(33 + cv2 * 20, 63);
				cout << "\20";
				gotoxy(41 + cv2 * 20, 63);
				cout << "\21";


				char c1 = _getch();
				int cv3 = cv2;
				if (c1 == 'H' || c1 == 'K') { cv2--; }
				if (c1 == 'P' || c1 == 'M') { cv2++; }
				if (cv2 == -1) { cv2 = 1; }
				if (cv2 == 2) { cv2 = 0; }
				if (cv2 == 0 && c1 == 13) { thoat1 = 0;thoat = 0; }
				if ((cv2 == 1 && c1 == 13) || c1 == 27) {
					thoat1 = 0;
					HCN2(15, 27, 60, 40, 5);

				}
				textcolor(240);
			}
		}



				


		gotoxy(13, 29 + 2 * cv1);
		cout << " ";
		gotoxy(36, 29 + 2 * cv1);
		cout << " ";
	}
	delete[] list_account; list_account = NULL;
};
void inDS(S_book A[], int n) {
	for (int i = 0;i<MAX_cot;i++) {
		gotoxy(31, 8 + i);cout << "                            ";
		gotoxy(60, 8 + i);cout << "            ";
		gotoxy(74, 8 + i);cout << "                      ";
	}
	for (int i = 0;i<n;i++) {
		gotoxy(31, 8 + i);cout << A[i].tensach;
		gotoxy(60, 8 + i);cout << A[i].theloai;
		gotoxy(74, 8 + i);cout << A[i].tacgia;
	}
};
void luachonsach(S_account A[], int n, int CSO) {
	int file_len = get_F_N("books_infor.txt");
	int sotrang = file_len / MAX_cot + 1;
	gotoxy(57, 45);cout << "XAC NHAN";

	gotoxy(80, 45);cout << "HUY BO";

	fstream f;
	f.open("books_infor.txt", ios::in);
	string data;

	S_book list[MAX_cot];
	f.seekg(0);
	for (int i = 0;i<MAX_cot;i++) {
		getline(f, data);stringstream scin(data);
		scin >> list[i].id;
		scin >> list[i].tensach;
		scin >> list[i].tacgia;
		scin >> list[i].theloai;
	}
	inDS(list, MAX_cot);
	int cv = 0, trang = 1, thoat = 1, chon = 0;
	while (A[CSO - 1].DS_muon[chon]>0) chon++; // chi duoc chon 5 cuon sach
	int flag = chon;//danh dau so sach da duoc muon
	while (thoat) {
		textcolor(250);
		gotoxy(31, 8 + cv);cout << list[cv].tensach;
		gotoxy(74, 8 + cv);cout << list[cv].tacgia;
		char c = _getch();
		int cv1 = cv;
		if (c == 'H') { cv--; }
		if (c == 'P') { cv++; }
		if (cv == -1) { cv = 19; }
		if (cv == 20) { cv = 0; }
		textcolor(240);
		if (c == 'K') {
			trang--;
			if (trang == 0) trang = sotrang;
			f.seekg(0, ios::beg);//duoi con tro doc file ve dau file
			for (int i = 0;i<(trang - 1)*MAX_cot;i++) getline(f, data);
			int n = file_len - (trang - 1)*MAX_cot + 2;
			if (n>20) n = 20;
			for (int i = 0;i<n;i++) {
				getline(f, data);stringstream scin(data);
				scin >> list[i].id;
				scin >> list[i].tensach;
				scin >> list[i].tacgia;
				scin >> list[i].theloai;
			}
			for (int i = n;i<MAX_cot;i++) { list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------"; }
			inDS(list, MAX_cot);
		}
		if (c == 'M') {
			trang++;
			if (trang == (sotrang + 1)) trang = 1;
			f.seekg(0, ios::beg);
			for (int i = 0;i<(trang - 1)*MAX_cot;i++) getline(f, data);
			int n = file_len - (trang - 1)*MAX_cot + 2;
			if (n>20) n = 20;
			for (int i = 0;i<n;i++) {
				getline(f, data);stringstream scin(data);
				scin >> list[i].id;
				scin >> list[i].tensach;
				scin >> list[i].tacgia;
				scin >> list[i].theloai;
			}
			for (int i = n;i<MAX_cot;i++) { list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------";list[i].id=0; }
			inDS(list, MAX_cot);
		}
		if (c == 13 && chon <5) { gotoxy(62, 31 + chon);cout << list[cv].tensach;A[CSO - 1].DS_muon[chon] = list[cv].id;chon++; }
		//chon mot cuon sach o hang thu cv
		else if (c == 13 && chon >= 5) { ToMau(60, 43, "chi muon duoc 5 cuon tren 1 lan", 58, 240); }
		if (c == 27) {
			int da_XN = 1, XN = 0;
			while (da_XN) {
				gotoxy(55 + XN * 23, 45);cout << "\20";

				gotoxy(66 + XN * 23, 45);cout << "\21";

			//	gotoxy(64 + XN * 23, 45);cout << "\20";????

				char ch = _getch();
				int XN1 = XN;
				if (ch == 'H' || ch == 'K') { XN--; }
				if (ch == 'P' || ch == 'M') { XN++; }
				if (XN == -1) { XN = 1; }
				if (XN == 2) { XN = 0; }
				if (XN == 0 && ch == 13) {
					ToMau(60, 43, "Da muon xong sach thanh, toan 1000$", 58, 240);
					_getch();da_XN = 0;HCN2(15, 53, 30, 45, 16);
					sapxepgiam(A[CSO-1].DS_muon,5);
					OverWriteAccount(A, n);
				}
				if ((XN == 1 && ch == 13) || ch == 27) {
					da_XN = 0;HCN2(15, 53, 30, 45, 16);
					for (int i = flag;i<chon;i++) A[CSO - 1].DS_muon[i] = 0;
				}
				textcolor(240);


				gotoxy(55 + XN1 * 23, 45);cout << " ";
				gotoxy(66 + XN1 * 23, 45);cout << " ";

				

				thoat = 0;
			}
		};
		gotoxy(31, 8 + cv1);cout << list[cv1].tensach;
		gotoxy(74, 8 + cv1);cout << list[cv1].tacgia;
	}
	f.close();
};

void sapxepgiam(int a[], int n) {
	for (int i = 0;i<n;i++)
		for (int j = i;j<n;j++) {
			if (a[i]<a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
}
void trasach(S_account A[], int CSO, int N) {
	int sosach = get_F_N("books_infor.txt")+1, chon = 0;
	S_book *SACH = new S_book[sosach];
	GetFileBookData(SACH, sosach);
	gotoxy(58, 31);cout << "Chon sach muon tra:";
	for (int i = 0;i<5;i++) {
		if (A[CSO].DS_muon[i] != 0) {
			chon++;
			gotoxy(67, 33 + i);cout << SACH[A[CSO].DS_muon[i] - 1].tensach;//vi so trong mang bat dau tu 0 trong file bat dau tu 1 nen phai tru 1
		}
	}
	int danh_dau[5] = { A[CSO].DS_muon[0],A[CSO].DS_muon[1],A[CSO].DS_muon[2],A[CSO].DS_muon[3],A[CSO].DS_muon[4] };
	gotoxy(67, 39);cout << "Xong";
	char* luachon[2] = { "Chon","Bo chon" };
	int cv = 0, thoat = 1;

	while (thoat) {
		if (cv<chon) {
			if (danh_dau[cv] == 0) {
				ToMau(83, 33 + cv, "x", 240);
			}
			else { ToMau(83, 33 + cv, " ", 240); }
			ToMau(55, 33 + cv, luachon[danh_dau[cv] == 0], 58, 240);
		}
		if (cv == chon) {
			gotoxy(65, 39);cout << "\20";
			gotoxy(72, 39);cout << "\21";
		}
		char c = _getch();
		int cv1 = cv;
		if (c == 'H') { cv--; }
		if (c == 'P') { cv++; }
		if (cv == -1) { cv = chon; }
		if (cv == chon + 1) { cv = 0; }
		if (cv<chon && c == 13) {
			if (danh_dau[cv] != 0) { danh_dau[cv] = 0; }
			else { danh_dau[cv] = A[CSO].DS_muon[cv]; }
		}
		if (cv == chon&&c==13) {
			gotoxy(58, 41);cout << "Xac nhan tra sach ?";
			gotoxy(57, 43);cout << "  co ";
			gotoxy(80, 43);cout << "khong";
			int cv2 = 0, thoat1 = 1;
			while (thoat1) {
				gotoxy(56 + 23 * cv2, 43);cout << "\20";
				gotoxy(62 + 23 * cv2, 43);cout << "\21";
				char c1 = _getch();
				int cv3 = cv2;
				if (c1 == 'H' || c1 == 'K') { cv2--; }
				if (c1 == 'P' || c1 == 'M') { cv2++; }
				if (cv2 == -1) { cv2 = 1; }
				if (cv2 == 2) { cv2 = 0; }
				if (cv2 == 0 && c1 == 13) {
					thoat1 = 0;thoat = 0;
					sapxepgiam(danh_dau, 5);
					for (int i = 0;i<5;i++) A[CSO].DS_muon[i] = danh_dau[i];
					OverWriteAccount(A, N);
					gotoxy(58, 45);cout << "TRA SACH THANH CONG !";
					_getch();HCN2(15, 53, 30, 45, 16);
				}
				if ((cv2 == 1 && c1 == 13) || c1 == 27) {
					thoat1 = 0;
					HCN2(15, 53, 41, 45, 5);
					cv1=cv = chon;
				}
				textcolor(240);
				gotoxy(56 + 23 * cv3, 43);cout << " ";
				gotoxy(62 + 23 * cv3, 43);cout << " ";
			}
		}
		if (cv1<chon) {
			ToMau(55, 33 + cv1, "       ", 240, 240);
		}
		else { 
			textcolor(240);
			gotoxy(65, 39);cout << " ";
			gotoxy(72, 39);cout << " ";
		}
		if (c == 27) { thoat = 0;HCN2(15, 53, 30, 45, 16);}
	}
	delete[]SACH; SACH = NULL;
};

void doimatkhau(S_account A[], int CSO, int N){
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);
	gotoxy(57,32);cout<<"nhap vao mat khau cu";
	ToMau(57,33,"                              ",240,112);
	gotoxy(57,36);cout<<"nhap vao mat khau moi";
	ToMau(57,37,"                              ",240,112);
	gotoxy(57,40);cout<<"xac nhan mat khau moi";
	ToMau(57,41,"                              ",240,112);
	gotoxy(57, 45);cout << "DOI MAT KHAU";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[5]={55,55,55,55,78},cvY[5]={32,36,40,45,45};
	int thoat=1,cv=0;
	string MKC="",MKM="",MKXN="";
	int x1=57,x2=57,x3=57;
	while(thoat){
		textcolor(115);
		gotoxy(cvX[cv],cvY[cv]);cout<<"\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c=='K') { cv--; }
		if (c == 'P' || c=='M') { cv++; }
		if (cv == -1) { cv = 4; }
		if (cv == 5) { cv = 0; }

		if(cv==0 && c==13){xulichuoi(MKC,'n',x1,33);}
		if(cv==1 && c==13){xulichuoi(MKM,'n',x2,37);}
		if(cv==2 && c==13){xulichuoi(MKXN,'n',x3,41);}
		if(cv==3 && c==13){
			if((A[CSO].matkhau==MKC)&&(MKM==MKXN)&&(MKM.length()>=5)){
				ToMau(57,43,"DA THAY DOI MAT KHAU THANG CONG",58,112);
				A[CSO].matkhau=MKM;
				OverWriteAccount(A,N);
				thoat=0;
				_getch();
			}else{ToMau(57,43,"*KIEM TRA LAI THONG TIN!!!",58,112);};
		}
		if((cv==4 && c==13)||c==27){thoat=0;}
		
		textcolor(112);
		gotoxy(cvX[cv1],cvY[cv1]);cout<<"  ";
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void bangtim(S_book A[],int a[],int n,S_account& S,int & flag){
	
	int sotrang = n / MAX_cot + 1;

	S_book list[MAX_cot];
	
	for (int i = 0;i<MAX_cot;i++) {
		if(i<n){
			list[i]=A[a[i]];
		}else {
			list[i].id=0;
			list[i].tacgia="--------";
			list[i].tensach="--------";
			list[i].theloai="--------";
		}
	}
	inDS(list, MAX_cot);
	int cv = 0, thoat = 1, chon = 0,bd=0;
	while (S.DS_muon[chon]>0) chon++; // chi duoc chon 5 cuon sach
	flag = chon;//danh dau so sach da duoc muon
	while (thoat) {
		textcolor(250);
		gotoxy(31, 8 + cv);cout << list[cv].tensach;
		gotoxy(74, 8 + cv);cout << list[cv].tacgia;
		char c = _getch();
		int cv1 = cv;
		if (c == 'H') { cv--; }
		if (c == 'P') { cv++; }
		if (cv == -1) { cv = 19; }
		if (cv == 20) { cv = 0; }
		textcolor(240);
		if (c == 'K') {
			bd-=MAX_cot;
			if (bd < 0) bd = (sotrang-1)*20;
			int k=n-bd;
			if(k>20) k=20;
			for (int i = bd;i<bd+k;i++) {
				list[i-bd]=A[a[i]];
			}
			for (int i = k;i<MAX_cot;i++) { list[i].id=0;list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------"; }
			inDS(list, MAX_cot);
		}
		if (c == 'M') {
			bd+=MAX_cot;
			if (bd > n) bd = 0;
			int k=n-bd;
			if(k>20) k=20;
			for (int i = bd;i<bd+k;i++) {
				list[i-bd]=A[a[i]];
			}
			for (int i = k;i<MAX_cot;i++) { list[i].id=0;list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------"; }
			inDS(list, MAX_cot);
		}
		
		if (c == 13 && chon <5) { gotoxy(62, 35 + chon);cout << list[cv].tensach;S.DS_muon[chon] = list[cv].id;chon++; }
		//chon mot cuon sach o hang thu cv
		else if (c == 13 && chon >= 5) { ToMau(60, 43, "chi muon duoc 5 cuon tren 1 lan", 58, 240); }
		if (c == 27) {
				thoat = 0;
			}
		gotoxy(31, 8 + cv1);cout << list[cv1].tensach;
		gotoxy(74, 8 + cv1);cout << list[cv1].tacgia;
	}
};
void timsach(S_account A[], int CSO, int N){
	int sosach = get_F_N("books_infor.txt")+1, chon = 0,flag=4;
	S_book *SACH = new S_book[sosach];
	int dstim[50],soluong=0;//tam thoi cho la 50
	string fstring="";
	GetFileBookData(SACH, sosach);
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);
	gotoxy(57,32);cout<<"nhap vao tu khoa:";
	ToMau(57,33,"                              ",240,112);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[3]={55,55,78},cvY[3]={32,45,45};
	int thoat=1,cv=0,x1=57;
	while(thoat){
		textcolor(115);
		gotoxy(cvX[cv],cvY[cv]);cout<<"\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c=='K') { cv--; }
		if (c == 'P' || c=='M') { cv++; }
		if (cv == -1) { cv = 2; }
		if (cv == 3) { cv = 0; }

		if((cv==0)&& c==13){
			xulichuoi(fstring,'y',x1,33);
			for(int i=0;i<sosach;i++){
				if((SACH[i].tacgia.find(fstring)!=-1)||(SACH[i].tensach.find(fstring)!=-1)||(SACH[i].theloai.find(fstring)!=-1)){
					dstim[soluong]=SACH[i].id-1;//phai -1 no moi ra dung
					soluong++;
				}
			}
			bangtim(SACH,dstim,soluong,A[CSO],flag);
			soluong=0;//reset la mang tim
		}
		if((cv==1)&& c==13){
			ToMau(60, 43, "Da muon xong sach thanh, toan 1000$", 58, 240);
			_getch();HCN2(15, 53, 30, 45, 16);
			sapxepgiam(A[CSO].DS_muon,5);
			OverWriteAccount(A, N);
			thoat=0;
		}
		if((cv==2 && c==13)||c==27){
			thoat=0;
			for (int i = flag;i<5;i++) A[CSO].DS_muon[i] = 0;
		}
		
		textcolor(112);
		gotoxy(cvX[cv1],cvY[cv1]);cout<<"  ";
	}

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
}
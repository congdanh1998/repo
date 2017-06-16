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
void manhinhluachon(int x, int y, int x_length, string s) {
	HCN2(3, x, y, x_length, 5);
	textcolor(49);
	int a = (x_length - s.length()) / 2;
	gotoxy(x + 3 + a, y + 1);cout << s;
	ToMau(x + 7, y + 3, "  CO   ", 126, 7);
	ToMau(x + 27, y + 3, " KHONG ", 126, 7);
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
	gotoxy(20, 13);for (unsigned int i = 1;i <= MK.length();i++) cout << "*";
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

	string data;//, ignore_str;
	int num_of_accounts = get_F_N("accounts_infor.txt");
	int the_choosen_one = -1;

	S_account* list_accounts = new S_account[num_of_accounts];

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
		HCN2(15, 15, 16, 40, 3);
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
			int check = 0;
			bool bOutOfLoop = false;
			for (int i = 0;i < num_of_accounts && !bOutOfLoop;i++) {
				if ((TDN == list_accounts[i].tendangnhap) && (MK == list_accounts[i].matkhau)) {
					if (list_accounts[i].khoa) {
						manhinhthongbao("DANG DANG NHAP ...");
						Sleep(2000);
						the_choosen_one = i;
						thoat = 0;
						bOutOfLoop = true;
						break;
					}
					else {
						manhinhthongbao("TAI KHOAN NAY DA BI KHOA ,LEU LEU ...");
						check = 1998;
					}
				}
			}
			if (bOutOfLoop == false && check != 1998) {
				manhinhthongbao("SAI TEN DANG NHAP HOAC MAT KHAU");
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
	if (the_choosen_one != -1) {
		manhinhdocgia(list_accounts[the_choosen_one]);
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

	textcolor(121);
	//in noi dung
	gotoxy(28, 18);
	cout << "DANG NHAP";

	gotoxy(28, 25);
	cout << " DANG KI ";

	gotoxy(28, 32);
	cout << "  THOAT  ";

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
		else {
			if ((ch != 13) && (ch != 9) && (ch != 11) && (ch >= 32) && (ch <= 126) && (x <= M)) {
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
	ToMau(15, 8, "                              ", 255, 62);//in dong de nhap van ban
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
	cout << "Nam:          Nu:";
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
void nhapngay(int&x, int&y, int&z, string&a, string&b, string&d, int x1 = 21, int x2 = 36, int x3 = 50, int yo = 15) {//ham nhap ngay thang nam sinh
	string ng, th, n;//cac chuoi ung voi ngay thang nam

	int X[3] = { x1,x2,x3 };//vi tri nhap chuoi(da biet truoc)
	int thoat = 1, cv = 1;
	while (thoat) {
		textcolor(59);
		gotoxy(X[cv - 1], yo);cout << "\20";gotoxy(X[cv - 1] + 5, yo);cout << "\21";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 3; }
		if (cv == 4) { cv = 1; }
		if ((cv == 3) && (c == 13)) { xulichuoi(d, 'y', z, yo, 3 - z + x3 + 1); }
		if ((cv == 1) && (c == 13)) { xulichuoi(a, 'y', x, yo, 1 - x + x1 + 1); }
		if ((cv == 2) && (c == 13)) { xulichuoi(b, 'y', y, yo, 1 - y + x2 + 1); }
		if (c == 27) { thoat = 0; }
		gotoxy(X[cv1 - 1], yo);cout << " ";gotoxy(X[cv1 - 1] + 5, yo);cout << " ";
	}
};
void GT(bool &X, int x1 = 49, int x2 = 62, int y = 29) {//ham nhap gioi tinh
	int thoat = 1, cv = 1;
	int x[2] = { x1,x2 };//vi tri hoang do nhap gioi tinh
	while (thoat) {
		textcolor(59);
		gotoxy(x[cv - 1], y);cout << "\20";gotoxy(x[cv - 1] + 2, y);cout << "\21";//in con tro danh dau
		char c = _getch();//nhan tin hieu dieu khien
		int cv1 = cv;//luu tin hieu dieu khien cu
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 2; }
		if (cv == 3) { cv = 1; }
		if ((cv == 1) && (c == 13)) { ToMau(x1 + 1, y, "x", 240);ToMau(x2 + 1, y, " ", 240, 59);X = true; }//danh dau vao o Nam bo danh dau o Nu
		if ((cv == 2) && (c == 13)) { ToMau(x1 + 1, y, " ", 240);ToMau(x2 + 1, y, "x", 240, 59);X = false; }//danh dau vao o Nu bo danh dau o Nam
		if (c == 27) { thoat = 0; }//thoat khi go EsC
		gotoxy(x[cv1 - 1], y);cout << " ";gotoxy(x[cv1 - 1] + 2, y);cout << " ";//xoa vi tri con tro cu
	}
};
void dangki() {
	S_user A_user;//khoi tao 1 user moi
	S_account A_account;

	string ngay, thang, nam;
	A_user.ngaysinh.ngay = A_user.ngaysinh.thang = A_user.ngaysinh.nam = 0;
	A_user.phat = false;
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
			if (A_user.hovaten == "" || ngay == "" || thang == "" || nam == "" || ((A_user.gioitinh !=1)&&(A_user.gioitinh !=0)) ||
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
			for (unsigned int i = 0;i < A_account.matkhau.length();i++) {
				if (A_account.matkhau.length() < 5 || A_account.matkhau.length() > 15 || ((int)A_account.matkhau[i] < 48) || ((int)A_account.matkhau[i] > 57 && (int)A_account.matkhau[i] < 65) || ((int)A_account.matkhau[i] > 90 && (int)A_account.matkhau[i] < 97) || ((int)A_account.matkhau[i] > 122)) {
					no_error_all = false;
					gotoxy(0, 62);
					cout << "* MAT KHAU PHAI DAI TU 5 DEN 15 KI TU CHI CHUA CHU CAI HOAC SO";
				}
			}
			for (unsigned int i = 0;i < A_account.tendangnhap.length();i++) {
				if (A_account.tendangnhap.length() < 5 || A_account.tendangnhap.length() > 20 || ((int)A_account.tendangnhap[i] < 48) || ((int)A_account.tendangnhap[i] > 57 && (int)A_account.tendangnhap[i] < 65) || ((int)A_account.tendangnhap[i] > 90 && (int)A_account.tendangnhap[i] < 97) || ((int)A_account.tendangnhap[i] > 122)) {
					no_error_all = false;
					gotoxy(0, 63);
					cout << "* TEN DANG NHAP PHAI DAI TU 5 DEN 20 KI TU CHI CHUA CHU CAI HOAC SO";
				}
			}
			if (no_error_all == true && no_error_date == true && no_error_age == true) {
				fstream f;

				A_user.id = get_F_N("users_infor.txt") + 1;
				A_account.id = get_F_N("accounts_infor.txt") + 1;
				A_account.vaitro[0] = 1;
				A_account.vaitro[1] = 0;
				A_account.vaitro[2] = 0;
				
				name_to_str(A_user.hovaten);

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
					<< setw(5) << left << A_user.phat
					<< endl;


				f.close();
				A_account.idu = A_user.id;
				A_account.khoa = 1;
				f.open("accounts_infor.txt", ios::app);
				f << setw(5) << A_account.id
					<< setw(5) << left << A_account.idu
					<< setw(25) << left << A_account.tendangnhap
					<< setw(20) << left << A_account.matkhau
					<< setw(5) << left << A_account.vaitro[0]
					<< setw(5) << left << A_account.vaitro[1]
					<< setw(5) << left << A_account.vaitro[2]
					<< left << "0 0 0 0 0 " <<
					setw(5) << A_account.khoa << endl;

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
				manhinhluachon(27, 60, 40, "Ban muon huy dang ki ?");
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
void manhinhthongbao(string s) {//in ra thong bao voi chuoi nhap san
	HCN2(3, 15, 16, 40, 3);//khung cua thong bao
	textcolor(49);
	int a = (40 - s.length()) / 2;//can le
	gotoxy(15 + a, 17);cout << s;
};
void manhinhlamviec() {
	textcolor(240);
	system("cls");
	resizeConsole(99, 60);
	inbang("Ten Sach", "The loai", "Tac Gia");//in ra bang co ten cot la "ten sach" "the loai" "tac gia"
	hinhchunhat(219, 0, 5, 28, 20);//in ra khung chua thong tin nguoi dung
	ToMau(5, 6, "Thong tin nguoi dung", 243, 240);
	ToMau(0, 28, "Cac chuc nang chinh", 15, 240);
	hinhchunhat(219, 0, 29, 50, 17);//khung chua cac chuc nang chinh
	hinhchunhat(219, 52, 29, 45, 17);//khung thuc hien chuc nang duoc chon
};
void menu(S_account TAIKHOAN, S_user choosen_user) {//in ra cac chuc nang
	textcolor(240 + ((!TAIKHOAN.vaitro[0]) || choosen_user.phat) * 7);//mau xam khi khong co chuc nang doc gia hoac bi phat
	gotoxy(15, 31);cout << "    TIM SACH         ";//1
	gotoxy(15, 32);cout << "    LUA CHON SACH    ";//2
	textcolor(240 + (!TAIKHOAN.vaitro[0]) * 7);
	gotoxy(15, 33);cout << "    XEM THONG BAO    ";//3
	textcolor(240 + ((!TAIKHOAN.vaitro[0]) || choosen_user.phat) * 7);
	gotoxy(15, 34);cout << "    DOI MAT KHAU     ";//4
	gotoxy(15, 35);cout << "    TRA SACH         ";//5
	textcolor(240 + (!TAIKHOAN.vaitro[2]) * 7);//mau xam khi khong co chuc nang thu thu
	gotoxy(15, 36);cout << "    CHINH SUA SACH   ";//6
	gotoxy(15, 37);cout << "    THEM SACH        ";//7
	gotoxy(15, 38);cout << "    XOA SACH         ";//8
	gotoxy(15, 39);cout << "    DANH SACH TRE    ";//9
	gotoxy(15, 40);cout << "    DANH SACH MUON   ";//10
	textcolor(240 + (!TAIKHOAN.vaitro[1]) * 7);//mau xam khi khong co chuc nang quan li
	gotoxy(15, 41);cout << "    QL NGUOI DUNG    ";//11
	gotoxy(15, 42);cout << "    QL TAI KHOAN     ";//12
	textcolor(240);
	gotoxy(15, 43);cout << "    DANG XUAT        ";//13
};
void manhinhdocgia(S_account& TAIKHOAN) {
	manhinhlamviec();
	S_account * list_account;
	int sotaikhoan = get_F_N("accounts_infor.txt");
	list_account = new S_account[(sotaikhoan / MAX_cot + 1)*MAX_cot];//se huu dung ve sau
	GetFileAccountsData(list_account, sotaikhoan);//lay thong tin tat ca tai khoan vao mang list
	fstream f;
	f.open("users_infor.txt", ios::in);
	string data, NTNS, GT[2] = { "nu","nam" };//chuan bi de in ra thong tin nguoi dung
	S_user choosen_user;//nguoi dung so huu tai khoan vua dang nhap
	do {
		getline(f, data);
		stringstream scin(data);
		scin >> choosen_user.id;
		if (choosen_user.id == TAIKHOAN.idu) {
			scin >> choosen_user.hovaten;
			scin >> NTNS;
			scin >> choosen_user.mssv;
			scin >> choosen_user.email;
			scin >> choosen_user.gioitinh;
			scin >> choosen_user.phat;
		}
	} while (choosen_user.id != TAIKHOAN.idu);//chon nguoi dung tuong ung voi tai khoan duoc chon

	f.close();
	gotoxy(3, 7);cout << "Ho va ten: ";
	gotoxy(3, 8);cout << str_to_name(choosen_user.hovaten);
	gotoxy(3, 12);cout << "Ngay thang nam sinh: ";
	gotoxy(3, 13);cout << NTNS;
	gotoxy(3, 15);cout << "Email: ";
	gotoxy(3, 16);cout << choosen_user.email;
	gotoxy(3, 18);cout << "Gioi tinh: " << GT[choosen_user.gioitinh];
	gotoxy(3, 21);cout << "MSSV: " << choosen_user.mssv;//in ra thong tin nguoi dung
	menu(TAIKHOAN, choosen_user);
	int cv = 1, thoat = 1;
	while (thoat) {//bat dau cho chuc nang
		gotoxy(13, 30 + cv);
		cout << "\20";
		gotoxy(36, 30 + cv);
		cout << "\21";

		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 13; }
		if (cv == 14) { cv = 1; }
		//chon chuc nang ung voi cv ,mang vaitro[] de xem tai khoan nay co thuc hien duoc chuc nang da chon hay khong
		if ((cv == 1) && (c == 13) && TAIKHOAN.vaitro[0] && !choosen_user.phat) { timsach(list_account, TAIKHOAN.id - 1, sotaikhoan); }
		if ((cv == 2) && (c == 13) && TAIKHOAN.vaitro[0] && !choosen_user.phat) { luachonsach(list_account, sotaikhoan, TAIKHOAN.id - 1); }
		if ((cv == 3) && (c == 13)) { thong_bao(list_account, sotaikhoan, TAIKHOAN.id - 1); }
		if ((cv == 4) && (c == 13) && !choosen_user.phat) { doimatkhau(list_account, TAIKHOAN.id - 1, sotaikhoan); }
		if ((cv == 5) && (c == 13) && TAIKHOAN.vaitro[0] && !choosen_user.phat) { trasach(list_account, TAIKHOAN.id - 1, sotaikhoan); }
		if ((cv == 6) && (c == 13) && TAIKHOAN.vaitro[2]) { chinhsuasach(list_account, sotaikhoan, TAIKHOAN.id - 1); }
		if ((cv == 7) && (c == 13) && TAIKHOAN.vaitro[2]) { them_sach(); }
		if ((cv == 8) && (c == 13) && TAIKHOAN.vaitro[2]) { xoasach(list_account, sotaikhoan, TAIKHOAN.id - 1); }
		if ((cv == 9) && (c == 13) && TAIKHOAN.vaitro[2]) { DStre(list_account, sotaikhoan); }
		if ((cv == 10) && (c == 13) && TAIKHOAN.vaitro[2]) { inDSmuon(list_account, sotaikhoan); }
		if ((cv == 11) && (c == 13) && TAIKHOAN.vaitro[1]) { QLND(list_account, sotaikhoan);menu(TAIKHOAN, choosen_user); }
		if ((cv == 12) && (c == 13) && TAIKHOAN.vaitro[1]) { QLTK(list_account, sotaikhoan);menu(TAIKHOAN, choosen_user); }
		if ((c == 27) || (cv == 13) && (c == 13)) {
			int cv2 = 0, thoat1 = 1;
			while (thoat1) {//hien man hinh lua chon dang xuat
				manhinhluachon(27, 48, 40, "Ban co muon dang xuat ?");
				gotoxy(33 + cv2 * 20, 51);
				cout << "\20";
				gotoxy(41 + cv2 * 20, 51);
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
					HCN2(15, 27, 48, 40, 5);
				}
				textcolor(240);
			}
		}

		gotoxy(13, 30 + cv1);
		cout << " ";
		gotoxy(36, 30 + cv1);
		cout << " ";
	}
	delete[] list_account; list_account = NULL;
};
void inDS(S_book A[], int n) {
	for (int i = 0;i<MAX_cot;i++) {
		gotoxy(31, 8 + i);cout << "                            ";
		gotoxy(60, 8 + i);cout << "            ";
		gotoxy(74, 8 + i);cout << "                      ";//phai xoa di thong tin cu truoc
	}
	for (int i = 0;i<n;i++) {
		textcolor(240 + (A[i].conlai <= 0) * 12);
		gotoxy(31, 8 + i);cout << A[i].tensach;
		gotoxy(60, 8 + i);cout << A[i].theloai;
		gotoxy(74, 8 + i);cout << A[i].tacgia;
	}//in ra cac thong tin moi
	textcolor(240);
};
void luachonsach(S_account A[], int n, int CSO) {
	int sosach = get_F_N("books_infor.txt"), chon = 0, flag = 4;//flag de danh dau so sach da chon ma chua tra(khoi dong bang 4 truoc)
	S_book *SACH = new S_book[sosach];
	GetFileBookData(SACH, sosach);
	int *a = new int[sosach];
	for (int i = 0;i<sosach;i++) { a[i] = i; }
	gotoxy(58, 31);cout << "DANH SACH MUON :";
	gotoxy(57, 45);cout << "XONG";
	gotoxy(72, 45);cout << "CHON LAI";
	gotoxy(87, 45);cout << "THOAT";
	bangtim(SACH, a, sosach, A[CSO], flag);//flag se bi thay doi trong ham nay(sau nay se co ich)

	int thoat = 1, cv = 1, x1 = 57;
	while (thoat) {
		textcolor(243);
		gotoxy(54 + (cv - 1) * 15, 45);cout << "\20\20";//in ra mui ten cho noi dung can chon
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 3; }
		if (cv == 4) { cv = 1; }
		if ((cv == 1) && c == 13) {
			int check = 0;
			for (int i = flag;i<5;i++) {//chi xet tiep cac sach vua muon(flag de danh dau no do=>co ich)
				if (A[CSO].DS_muon[i] != 0) {
					SACH[A[CSO].DS_muon[i] - 1].conlai--;//khi muon thi so sach con lai giam 1
				};
			}
			fstream f;
			f.open("abc.txt", ios::app);//app la ghi noi len file cu
			time_t baygio = time(0);//tim ngay hien tai 
			struct tm abc;
			localtime_s(&abc, &baygio);
			for (int i = flag;i<5;i++) {//chi ghi tu lan muon nay neu khong co flag thi cac lan muon truoc no cung ghi luon
				if (A[CSO].DS_muon[i] != 0) {
					f << setw(5) << A[CSO].id
						<< setw(5) << A[CSO].DS_muon[i]
						<< setw(5) << abc.tm_mday
						<< setw(5) << abc.tm_mon + 1
						<< setw(5) << abc.tm_year + 1900 << endl;
				}
				else check++;
			}
			f.close();
			sapxepgiam(A[CSO].DS_muon, 5);//sap xep giam --> xu li tien loi
			OverWriteAccount(A, n);//viet lai file Taikhoan do DSmuon bi thay doi
			OverWriteBook(SACH, sosach);//viet lai file sach do conlai bi thay doi

			HCN2(15, 53, 42, 45, 2);//xoa man hinh lam viec(o thu 4)
			if (check != 5 - flag) {
				int giatien = (5 - flag - check) * GIA_1_CUON;
				string str = "";
				conv_longlong_money(str, giatien);//doi so ra gia tien co don vi VND dang sau
				ToMau(55, 43, "Da muon xong sach, thanh toan " + str, 58, 240);//ham to mau thu hai de lam cai nay day
				_getch();
			}
			HCN2(15, 53, 30, 45, 16);

			thoat = 0;
		}
		if (cv == 2 && c == 13) {
			HCN2(15, 53, 32, 45, 12);
			textcolor(240);
			for (int i = flag;i<5;i++) A[CSO].DS_muon[i] = 0;
			bangtim(SACH, a, sosach, A[CSO], flag);
		}
		if (cv == 3 && c == 13 || c == 27) {
			thoat = 0;
			for (int i = flag;i<5;i++) A[CSO].DS_muon[i] = 0;
		}
		gotoxy(54 + (cv1 - 1) * 15, 45);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);//xoa chu o cho inbang

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
	delete[]SACH;SACH = NULL;
};

void sapxepgiam(int a[], int n) {//ham sap xep giam
	for (int i = 0;i<n;i++)//      do trong mang DSmuon cua S_account thi
		for (int j = i;j<n;j++) {//cac phan tu bang 0 tucc la chua muon thi phai nam o sau cung de de kiem soat
			if (a[i]<a[j]) {//    nen can phai sap xep giam
				int t = a[i];//   ham sap xep giam cung can cho nhieu giai thuat khac
				a[i] = a[j];
				a[j] = t;
			}
		}
}
void trasach(S_account A[], int CSO, int N) {
	int sosach = get_F_N("books_infor.txt"), chon = 0, check_blank = 0;
	int sophieu = get_F_N("abc.txt");
	S_book *SACH = new S_book[sosach];
	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	GetFileBookData(SACH, sosach);
	GetfileOrderData(PHIEU, sophieu);
	for (int i = 0;i<5;i++) {
		if (A[CSO].DS_muon[i] == 0) {
			check_blank++;
		}//diem so khoang trong
	}
	if (check_blank == 5) {
		gotoxy(58, 31);cout << "Khong co sach de tra !";
		char c;
		do {
			c = _getch();
		} while (c != 27 && c != 13);
		HCN2(15, 53, 30, 45, 16);textcolor(240);
	}
	else {
		gotoxy(58, 31);cout << "Chon sach muon tra:";
		for (int i = 0;i < 5;i++) {
			if (A[CSO].DS_muon[i] != 0) {
				chon++;
				gotoxy(67, 33 + i);cout << SACH[A[CSO].DS_muon[i] - 1].tensach;//vi so trong mang bat dau tu 0 trong file bat dau tu 1 nen phai tru 1
			}
		}//in ra cac sach da muon
		int danh_dau[5] = { A[CSO].DS_muon[0],A[CSO].DS_muon[1],A[CSO].DS_muon[2],A[CSO].DS_muon[3],A[CSO].DS_muon[4] };
		//phai co mot mang tam de khi co xac nhan cua nguoi dung thi moi thay doi
		gotoxy(67, 39);cout << "Xong";
		char* luachon[2] = { "Chon","Bo chon" };//in ra tinh tranh da chon hay chua khi tro mui ten toi
		int cv = 0, thoat = 1;

		while (thoat) {
			if (cv < chon) {
				if (danh_dau[cv] == 0) {
					ToMau(83, 33 + cv, "x", 240);//danh dau X o cho sach duoc chon
				}
				else { ToMau(83, 33 + cv, " ", 240); }//bo dau X
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
			if (cv < chon && c == 13) {
				if (danh_dau[cv] != 0) { danh_dau[cv] = 0; }
				else { danh_dau[cv] = A[CSO].DS_muon[cv]; }
			}
			if (cv == chon&&c == 13) {//khi chon tra sach
				gotoxy(58, 41);cout << "Xac nhan tra sach ?";
				gotoxy(57, 43);cout << "  co ";//cac lua chon
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
						for (int i = 0;i < 5;i++) {//khi tra sach thi phai sua lai thong tin cua cac phieu muon
							if (A[CSO].DS_muon[i] != 0 && danh_dau[i] == 0) {
								SACH[A[CSO].DS_muon[i] - 1].conlai++;
								for (int j = 0;j < sophieu;j++) {
									if (PHIEU[j].bookid == A[CSO].DS_muon[i] && PHIEU[j].userid == A[CSO].id) {
										for (int k = j + 1;k < sophieu;k++) {//xoa di 1 phieu muon...
											PHIEU[k - 1] = PHIEU[k];
										}
										sophieu--;//...thi giam so luong di 1 
										break;
									}
								}
							};
						}
						sapxepgiam(danh_dau, 5);//de cho thuan loi xu li du lieu
						for (int i = 0;i < 5;i++) A[CSO].DS_muon[i] = danh_dau[i];//gan lai gia tri cho tai khoan
						OverWriteAccount(A, N);//                                   sau khi tra het sach
						OverWriteBook(SACH, sosach);
						OverWriteOrder(PHIEU, sophieu);
						gotoxy(58, 45);cout << "TRA SACH THANH CONG !";
						_getch();HCN2(15, 53, 30, 45, 16);
					}
					if ((cv2 == 1 && c1 == 13) || c1 == 27) {
						thoat1 = 0;
						HCN2(15, 53, 41, 45, 5);
						cv1 = cv = chon;
					}
					textcolor(240);
					gotoxy(56 + 23 * cv3, 43);cout << " ";
					gotoxy(62 + 23 * cv3, 43);cout << " ";
				}
			}
			if (cv1 < chon) {
				ToMau(55, 33 + cv1, "       ", 240, 240);
			}
			else {
				textcolor(240);
				gotoxy(65, 39);cout << " ";
				gotoxy(72, 39);cout << " ";
			}
			if (c == 27) { thoat = 0;HCN2(15, 53, 30, 45, 16);textcolor(240); }
		}
	}
	delete[]SACH; SACH = NULL;
	delete[]PHIEU;PHIEU = NULL;
};

void doimatkhau(S_account A[], int CSO, int N) {
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);//in ra cac dong de thuc hien 
	gotoxy(57, 32);cout << "nhap vao mat khau cu";
	ToMau(57, 33, "                              ", 240, 112);
	gotoxy(57, 36);cout << "nhap vao mat khau moi";
	ToMau(57, 37, "                              ", 240, 112);
	gotoxy(57, 40);cout << "xac nhan mat khau moi";
	ToMau(57, 41, "                              ", 240, 112);
	gotoxy(57, 45);cout << "DOI MAT KHAU";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[5] = { 55,55,55,55,78 }, cvY[5] = { 32,36,40,45,45 };//vi tri cua con tro ung voi moi lua chon
	int thoat = 1, cv = 0;
	string MKC = "", MKM = "", MKXN = "";//cac chuoi mat khau cu,mat khau moi, xac nhan mat khau
	int x1 = 57, x2 = 57, x3 = 57;//vi tri nhap chuoi cua ham xulichuoi
	while (thoat) {
		textcolor(115);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		HCN2(7, 57, 43, 26, 1);
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 4; }
		if (cv == 5) { cv = 0; }

		if (cv == 0 && c == 13) { xulichuoi(MKC, 'n', x1, 33); }//nhap chuoi
		if (cv == 1 && c == 13) { xulichuoi(MKM, 'n', x2, 37); }
		if (cv == 2 && c == 13) { xulichuoi(MKXN, 'n', x3, 41); }
		if (cv == 3 && c == 13) {
			bool no_error_all = true;
			if ((A[CSO].matkhau != MKC) || (MKM != MKXN)) {//kiem tra xem cac mat khau cu moi co giong nhau ko
				no_error_all = false;
			}
			for (unsigned int i = 0;i < MKM.length();i++) {
				if (MKM.length() < 5 || MKM.length() > 15 || ((int)MKM[i] < 48) || ((int)MKM[i] > 57 && (int)MKM[i] < 65) || ((int)MKM[i] > 90 && (int)MKM[i] < 97) || ((int)MKM[i] > 122)) {
					no_error_all = false;
				}
			}//kiem tra xem co su sai lam nao trong mat khau moi ko
			if (no_error_all == true) {
				ToMau(57, 43, "DA THAY DOI MAT KHAU THANG CONG", 58, 112);
				A[CSO].matkhau = MKM;
				OverWriteAccount(A, N);//viet lai file
				thoat = 0;
				_getch();
			}
			else { ToMau(57, 43, "*KIEM TRA LAI THONG TIN!!!", 58, 112); };//nghia la nhap sai roi kiem tra lai thong tin nhap
		}
		if ((cv == 4 && c == 13) || c == 27) { thoat = 0; }

		textcolor(112);
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void bangtim(S_book A[], int a[], int n, S_account& S, int & flag, bool cp, bool MR) {
	int sotrang = n / MAX_cot + 1;			//khi cp=false thi co the chon moi sach
											//khi cp=true thi cac sach da bi muon het hien mau do se ko chon duoc
	S_book list[MAX_cot];					//khi MR=flase thi khi chon xong 5 cuon se thoat khoi bang chon ngay
											//a[i] la mang chua ID cua cac sach se duoc lua chon o day(co the da duoc loc ra tu truoc)
	for (int i = 0;i<MAX_cot;i++) {
		if (i<n) {
			list[i] = A[a[i]];
		}
		else {
			list[i].id = 0;
			list[i].tacgia = "--------";
			list[i].tensach = "--------";
			list[i].theloai = "--------";
		}
	}
	inDS(list, MAX_cot);
	int cv = 0, thoat = 1, chon = 0, bd = 0;//bd la vi tri bat dau
	while (S.DS_muon[chon]>0) chon++; // chi duoc chon 5 cuon sach
	flag = chon;//danh dau so sach da duoc muon
	while (thoat) {
		textcolor(240);
		gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
		textcolor(250);
		if(list[cv].id==0){cv=0;}//neu ko con sach nua thi chuyen co tro ve dau trang
		gotoxy(31, 8 + cv);cout << list[cv].tensach;
		gotoxy(74, 8 + cv);cout << list[cv].tacgia;
		char c = _getch();
		int cv1 = cv;
		if (c == 'H') { cv--; }									//o day ta chia du lieu thanh nhieu trang
		if (c == 'P') { cv++; }									//moi trang bat dau o vi tri la bd
		if (cv == -1) { cv = 19; }								//thuong dai 20 dong nhung trang cuoi co the ngan hon
		if (cv == 20) { cv = 0; }								//nen ta dung bien k de kiem soat so dong
		textcolor(240);
		if (c == 'K') {//nhan qua trai thi lui trang
			bd -= MAX_cot;
			if (bd < 0) bd = (sotrang - 1) * 20;
			int k = n - bd;
			if (k>20) k = 20;
			for (int i = bd;i<bd + k;i++) {
				list[i - bd] = A[a[i]];
			}
			for (int i = k;i<MAX_cot;i++) { list[i].id = 0;list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------"; }
			inDS(list, MAX_cot);
		}
		if (c == 'M') {//nhan qua trai de tien trang
			bd += MAX_cot;
			if (bd > n) bd = 0;
			int k = n - bd;
			if (k>20) k = 20;
			for (int i = bd;i<bd + k;i++) {
				list[i - bd] = A[a[i]];
			}
			for (int i = k;i<MAX_cot;i++) { list[i].id = 0;list[i].tacgia = "------------";list[i].theloai = "--------";list[i].tensach = "------------"; }
			inDS(list, MAX_cot);
		}

		if (c == 13 && chon <5 && (list[cv].conlai>0) && cp) { //khi nhan Enter vao 1 cuon sach
			bool KT=true;
			for(int i=0;(i<5)&&KT;i++){KT=(S.DS_muon[i]!=list[cv].id);}
			if (KT){
				gotoxy(62, 35 + chon);cout << list[cv].tensach; S.DS_muon[chon] = list[cv].id;chon++;
			}else {ToMau(62, 43, "BAN DA MUON CUON NAY ROI  ", 58, 240);} 
		}
		//chon mot cuon sach o hang thu cv
		else if (c == 13 && chon >= 5 && cp) { HCN2(15, 62, 42, 26, 2);ToMau(62, 42, "Tai mot thoi diem chi muon", 58, 240);ToMau(62, 43, " duoc toi da 5 cuon sach !", 58, 240); }
		else if (c == 13 && (list[cv].conlai <= 0) && cp) { HCN2(15, 62, 43, 26, 1); ToMau(62, 43, "Sach nay da bi muon het  !", 58, 240); }
		if (c == 13 && chon <5 && !cp) { 
			bool KT=true;
			for(int i=0;(i<5)&&KT;i++){KT=(S.DS_muon[i]!=list[cv].id);}
			if (KT){
				gotoxy(62, 35 + chon);cout << list[cv].tensach; S.DS_muon[chon] = list[cv].id;chon++;
			}else {ToMau(62, 43, "BAN DA CHON CUON NAY ROI  ", 58, 240);} 
		}else if(c == 13 && chon >= 5 && !cp){HCN2(15, 62, 42, 26, 2);ToMau(62, 42, "Tai mot thoi diem chi chon", 58, 240);ToMau(62, 43, " duoc toi da 5 cuon sach !", 58, 240); }
		//chon mot cuon sach o hang thu cv

		if (c == 27 || (!MR && chon == 5)) {
			thoat = 0;
		}
		if(list[cv1].id==0){cv1=0;}
		textcolor(240 + (list[cv1].conlai <= 0) * 12);
		gotoxy(31, 8 + cv1);cout << list[cv1].tensach;
		gotoxy(74, 8 + cv1);cout << list[cv1].tacgia;
	}
};
void timsach(S_account A[], int CSO, int N) {
	int sosach = get_F_N("books_infor.txt"), chon = 0, flag = 4;
	S_book *SACH = new S_book[sosach];
	int dstim[100], soluong = 0;//tam thoi cho la 100
	string fstring = "";
	GetFileBookData(SACH, sosach);
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);//in giao dien
	gotoxy(57, 32);cout << "nhap vao tu khoa:";
	ToMau(57, 33, "                              ", 240, 112);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[3] = { 55,55,78 }, cvY[3] = { 32,45,45 };
	int thoat = 1, cv = 0, x1 = 57;
	while (thoat) {
		textcolor(115);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 2; }
		if (cv == 3) { cv = 0; }

		if ((cv == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 33);//nhap chuoi can tim
			for (int i = 0;i<sosach;i++) {//tim tat ca cac sach co chuoi vua nhap o trong
				if ((SACH[i].tacgia.find(fstring) != -1) || (SACH[i].tensach.find(fstring) != -1) || (SACH[i].theloai.find(fstring) != -1)) {
					dstim[soluong] = SACH[i].id - 1;//phai -1 no moi ra dung
					soluong++;
				}
			}
			bangtim(SACH, dstim, soluong, A[CSO], flag);
			soluong = 0;//reset la mang tim de sau nay tim tiep
		}
		if ((cv == 1) && c == 13) {//lua chon sau khi muon giong ham luachonsach
			int check = 0;
			for (int i = flag;i<5;i++) {
				if (A[CSO].DS_muon[i] != 0) {
					SACH[A[CSO].DS_muon[i] - 1].conlai--;
				}
			}
			fstream f;
			f.open("abc.txt", ios::app);
			time_t baygio = time(0);
			struct tm abc;
			localtime_s(&abc, &baygio);
			for (int i = flag;i<5;i++) {
				if (A[CSO].DS_muon[i] != 0) {
					f << setw(5) << A[CSO].id
						<< setw(5) << A[CSO].DS_muon[i]
						<< setw(5) << abc.tm_mday
						<< setw(5) << abc.tm_mon + 1
						<< setw(5) << abc.tm_year + 1900 << endl;
				}
				else check++;
			}
			f.close();
			sapxepgiam(A[CSO].DS_muon, 5);
			OverWriteAccount(A, N);
			OverWriteBook(SACH, sosach);

			HCN2(7, 53, 42, 45, 2);
			if (check != 5 - flag) {
				int giatien = (5 - flag - check) * GIA_1_CUON;
				string str = "";
				conv_longlong_money(str, giatien);
				ToMau(55, 43, "Da muon xong sach, thanh toan " + str, 58, 240);
				_getch();
			}
			HCN2(7, 53, 30, 45, 16);

			thoat = 0;
		}
		if ((cv == 2 && c == 13) || c == 27) {
			thoat = 0;
			for (int i = flag;i<5;i++) A[CSO].DS_muon[i] = 0;
		}

		textcolor(112);
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
	delete[]SACH;SACH = NULL;
}
//inDS2 la in ra thong tin cua mot phieu muon gom ten user,ten sach muon va ngay muon
void inDS2(S_book A[], S_user B[], S_Book_Order C[], S_account D[], int pos, int n, bool cp = false) {
	for (int i = 0;i<MAX_cot;i++) {
		gotoxy(31, 8 + i);cout << "                            ";
		gotoxy(60, 8 + i);cout << "            ";
		gotoxy(74, 8 + i);cout << "                      ";
	}
	for (int i = pos;i<n + pos;i++) {
		if (cp) textcolor(B[D[C[i].userid - 1].idu - 1].phat * 12 + 240);//neu cp=true thi phieu da bi phat se co mau do
		gotoxy(31, 8 + i - pos);cout << str_to_name(B[D[C[i].userid - 1].idu - 1].hovaten);
		gotoxy(60, 8 + i - pos);cout << C[i].day.ngay << "/" << C[i].day.thang << "/" << C[i].day.nam;
		gotoxy(74, 8 + i - pos);cout << A[C[i].bookid - 1].tensach;
	}
	textcolor(240);
};
void inDSmuon(S_account A[], int N) {//ham giup thu thu xem danh sach muon
	inbang("nguoi muon", "ngay muon", "ten sach");//in bang moi
	int sosach = get_F_N("books_infor.txt");
	int sophieu = get_F_N("abc.txt");
	int sond = get_F_N("users_infor.txt");
	S_book *SACH = new S_book[sosach];
	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	S_user *ND = new S_user[sond];
	GetFileBookData(SACH, sosach);
	GetfileOrderData(PHIEU, sophieu);
	GetFileUserData(ND, sond);
	int  bd = 0, thoat = 1, sotrang = sophieu / MAX_cot + 1, n;//manh khoe cu duoi hinh thuc moi
	if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
	else { n = MAX_cot; }
	inDS2(SACH, ND, PHIEU, A, bd, n);
	while (thoat) {
		char c = _getch();
		if (c == 'K') {
			bd -= MAX_cot;
			if (bd < 0) bd = (sotrang - 1) * 20;
			if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
			else { n = MAX_cot; }
			inDS2(SACH, ND, PHIEU, A, bd, n);
		}
		if (c == 'M') {
			bd += MAX_cot;
			if (bd > sophieu) bd = 0;
			if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
			else { n = MAX_cot; }
			inDS2(SACH, ND, PHIEU, A, bd, n);
		}
		if (c == 27) thoat = 0;
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);
	textcolor(240);

	delete[]SACH; SACH = NULL;
	delete[]PHIEU;PHIEU = NULL;
	delete[]ND;ND = NULL;
};
void them_sach() {
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);//in ra giao dien
	gotoxy(57, 32);cout << "ten sach";
	ToMau(57, 33, "                              ", 240, 112);
	gotoxy(57, 36);cout << "tac gia";
	ToMau(57, 37, "                              ", 240, 112);
	gotoxy(57, 40);cout << "the loai";
	ToMau(57, 41, "               ", 240, 112);
	gotoxy(75, 40);cout << "so luong";
	ToMau(75, 41, "  ", 240, 112);
	gotoxy(57, 45);cout << "THEM";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[6] = { 55,55,55,73,55,78 }, cvY[6] = { 32,36,40,40,45,45 };//vi tri cua cac lua chon de dua co tro toi
	int thoat = 1, cv = 0;
	string ten = "", tg = "", tt = "", sl = "";//ten sach   tac gia   the loai   so luong
	int x1 = 57, x2 = 57, x3 = 57, x4 = 75;//chuan bi de nhap cac chuoi vao
	while (thoat) {
		textcolor(115);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 5; }
		if (cv == 6) { cv = 0; }

		if (cv == 0 && c == 13) { xulichuoi(ten, 'y', x1, 33, 25); }
		if (cv == 1 && c == 13) { xulichuoi(tg, 'y', x2, 37, 20); }
		if (cv == 2 && c == 13) { xulichuoi(tt, 'y', x3, 41, 14); }
		if (cv == 3 && c == 13) { xulichuoi(sl, 'y', x4, 41, 1); }//nhap du lieu
		if (cv == 4 && c == 13) {//neu chon them thi in ra file
			thoat = 0;
			fstream f;
			int id = get_F_N("books_infor.txt") + 1;
			f.open("books_infor.txt", ios::app);
			f << setw(5) << left << id <<
				setw(25) << left << ten <<
				setw(20) << left << tg <<
				setw(20) << left << tt <<
				setw(5) << right << sl << endl;
			f.close();
		}
		if ((cv == 5 && c == 13) || c == 27) { thoat = 0; }//neu chon huy thi thoat khong them du lieu vao

		textcolor(112);
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
}
void xoasach(S_account A[], int N, int CSO) {
	S_account S = A[CSO];//su dung ham bangtim thi cac co 1 bien taikhoan de xu li
	S.DS_muon[0] = 0;
	S.DS_muon[1] = 0;
	S.DS_muon[2] = 0;
	S.DS_muon[3] = 0;
	S.DS_muon[4] = 0;
	int sosach = get_F_N("books_infor.txt"), chon = 0, flag = 4;
	S_book *SACH = new S_book[sosach];
	int sophieu = get_F_N("abc.txt");
	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	int dstim[100], soluong = 0;//tam thoi cho la 100
	string fstring = "";
	GetFileBookData(SACH, sosach);
	GetfileOrderData(PHIEU, sophieu);
	HCN2(7, 53, 30, 45, 16);
	textcolor(112);
	gotoxy(57, 32);cout << "tim sach de xoa:";
	ToMau(57, 33, "                              ", 240, 112);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[3] = { 55,55,78 }, cvY[3] = { 32,45,45 };
	int thoat = 1, cv = 0, x1 = 57;
	while (thoat) {
		textcolor(115);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 2; }
		if (cv == 3) { cv = 0; }

		if ((cv == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 33);//B1:tim sach can phai xoa
			for (int i = 0;i<sosach;i++) {
				if ((SACH[i].tacgia.find(fstring) != -1) || (SACH[i].tensach.find(fstring) != -1) || (SACH[i].theloai.find(fstring) != -1)) {
					dstim[soluong] = SACH[i].id - 1;//phai -1 no moi ra dung
					soluong++;
				}
			}
			bangtim(SACH, dstim, soluong, S, flag, false);//B2:chon cac sach trong bang vua tim duoc de xoa
			soluong = 0;//reset la mang tim
		}
		if ((cv == 1) && c == 13) {//B3a:xoa cac sach vua chon
			int danh_dau[5] = { S.DS_muon[0],S.DS_muon[1],S.DS_muon[2],S.DS_muon[3],S.DS_muon[4] };
			sapxepgiam(danh_dau, 5);//phai sap xep giam de tranh xoa nhap cac sach chon phia sau
			for (int i = 0;i<5;i++) {
				if (danh_dau[i] != 0) {
					for (int j = danh_dau[i];j<sosach;j++) {
						SACH[j - 1] = SACH[j];
						SACH[j - 1].id--;//giam id cua cac sach co id lon hon sach bi xoa di 1
					}//xoa mot dau sach
					sosach--;
					for (int j = 0;j<sophieu;j++) {
						if (PHIEU[j].bookid == danh_dau[i]) {
							for (int k = j + 1;k<sophieu;k++) {
								PHIEU[k - 1] = PHIEU[k];
							}
							sophieu--;
						}
					}//xoa cac phieu co sach bi xoa
					for (int j = 0;j<sophieu;j++) if (PHIEU[j].bookid>danh_dau[i]) PHIEU[j].bookid--;//giam id cua cac sach co id lon hon sach bi xoa di 1 trong file abc
					for (int j = 0;j<N;j++) {
						for (int k = 0;k<5;k++) {
							if (A[j].DS_muon[k] == danh_dau[i]) { A[j].DS_muon[k] = 0; }
							else if (A[j].DS_muon[k]>danh_dau[i]) { A[j].DS_muon[k]--; }
						}
						sapxepgiam(A[j].DS_muon, 5);
					}//sua lai file accout (xoa cac DSmuon = id sach bi xoa)
				}
			}
			for (int i = flag;i<5;i++) S.DS_muon[i] = 0;
			OverWriteAccount(A, N);
			OverWriteBook(SACH, sosach);
			OverWriteOrder(PHIEU, sophieu);//viet lai cac file bi thay doi
			thoat = 0;
		}
		if ((cv == 2 && c == 13) || c == 27) {//B3b:khong xoa va thoat ra ngoai
			thoat = 0;
			for (int i = flag;i<5;i++) S.DS_muon[i] = 0;
		}

		textcolor(112);
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
	delete[]SACH;SACH = NULL;
	delete[]PHIEU;PHIEU = NULL;
}
void chinhsuasach(S_account A[], int N, int CSO) {
	S_account S = A[CSO];
	S.DS_muon[0] = 1;
	S.DS_muon[1] = 1;
	S.DS_muon[2] = 1;
	S.DS_muon[3] = 1;
	S.DS_muon[4] = 0;//cai nay vao ham bangtim de chi chon lay 1 cuon duy nhat va sua no
	int sosach = get_F_N("books_infor.txt"), chon = 0, flag = 4;
	S_book *SACH = new S_book[sosach];
	int dstim[100], soluong = 0;//tam thoi cho la 100
	string fstring = "";
	GetFileBookData(SACH, sosach);

	HCN2(7, 53, 30, 45, 16);
	textcolor(112);
	gotoxy(57, 30);cout << "tim sach de sua:";
	ToMau(57, 31, "                              ", 240, 112);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[3] = { 55,55,78 }, cvY[3] = { 30,45,45 };
	int thoat = 1, cv = 0, x1 = 57;
	while (thoat) {
		textcolor(115);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 2; }
		if (cv == 3) { cv = 0; }

		if ((cv == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 31);
			for (int i = 0;i<sosach;i++) {
				if ((SACH[i].tacgia.find(fstring) != -1) || (SACH[i].tensach.find(fstring) != -1) || (SACH[i].theloai.find(fstring) != -1)) {
					dstim[soluong] = SACH[i].id - 1;//phai -1 no moi ra dung(do trong mang phan tu dau bat dau tu 0)
					soluong++;
				}
			}
			bangtim(SACH, dstim, soluong, S, flag, false, false);//cho MR=false de thoat sau khi chon
			soluong = 0;//reset la mang tim
			if (S.DS_muon[4] != 0) {
				textcolor(112);//in ra cac thong tin sach de xem hoac sua
				gotoxy(57, 33);cout << "ten sach";
				ToMau(57, 34, "                              ", 240, 112);
				gotoxy(57, 36);cout << "tac gia";
				gotoxy(62, 39);HCN2(7, 53, 39, 45, 1);
				ToMau(57, 37, "                              ", 240, 112);
				gotoxy(57, 40);cout << "the loai";
				ToMau(57, 41, "               ", 240, 112);
				gotoxy(75, 40);cout << "so luong";
				ToMau(75, 41, "  ", 240, 112);
				textcolor(240);
				string A[10] = { "0","1","2","3","4","5","6","7","8","9" };//giup doi so sang chuoi de hon
				string conlai = A[SACH[S.DS_muon[4] - 1].conlai / 10] + A[SACH[S.DS_muon[4] - 1].conlai % 10];//doi so sang chuoi
				gotoxy(57, 34);cout << SACH[S.DS_muon[4] - 1].tensach;
				gotoxy(57, 37);cout << SACH[S.DS_muon[4] - 1].tacgia;
				gotoxy(57, 41);cout << SACH[S.DS_muon[4] - 1].theloai;
				gotoxy(75, 41);cout << conlai;
				int thoat1 = 1, cv2 = 0;
				int cvX1[6] = { 55,55,55,73,55,78 }, cvY1[6] = { 33,36,40,40,45,45 };
				int x1 = 57 + SACH[S.DS_muon[4] - 1].tensach.length(), x2 = 57 + SACH[S.DS_muon[4] - 1].tacgia.length(), x3 = 57 + SACH[S.DS_muon[4] - 1].theloai.length(), x4 = 75 + conlai.length();
				while (thoat1) {
					textcolor(115);
					gotoxy(cvX1[cv2], cvY1[cv2]);cout << "\20\20";
					char c1 = _getch();
					int cv3 = cv2;
					if (c1 == 'H' || c1 == 'K') { cv2--; }
					if (c1 == 'P' || c1 == 'M') { cv2++; }
					if (cv2 == -1) { cv2 = 5; }
					if (cv2 == 6) { cv2 = 0; }
					//nhap vao cac thong tin moi hoac sua lai cung duoc hoac co the de im de xem thong tin sach
					if (cv2 == 0 && c1 == 13) { xulichuoi(SACH[S.DS_muon[4] - 1].tensach, 'y', x1, 34, 25); }
					if (cv2 == 1 && c1 == 13) { xulichuoi(SACH[S.DS_muon[4] - 1].tacgia, 'y', x2, 37, 20); }
					if (cv2 == 2 && c1 == 13) { xulichuoi(SACH[S.DS_muon[4] - 1].theloai, 'y', x3, 41, 14); }
					if (cv2 == 3 && c1 == 13) { xulichuoi(conlai, 'y', x4, 41, 1); }
					if (cv2 == 4 && c1 == 13) {//cv==4 xac nhan luu thay doi vao file
						stringstream(conlai) >> SACH[S.DS_muon[4] - 1].conlai;//sua lai so sach con lai
						OverWriteBook(SACH, sosach);
						thoat1 = 0;
						S.DS_muon[4] = 0;//reset lai de tim tiep
						HCN2(7, 53, 32, 45, 12);
					}
					if ((cv2 == 5 && c1 == 13) || c1 == 27) { thoat1 = 0;S.DS_muon[4] = 0;HCN2(7, 53, 32, 45, 13);}

					textcolor(112);
					gotoxy(cvX1[cv3], cvY1[cv3]);cout << "  ";
				}
			}
		}
		if ((cv == 1) && c == 13) {
			thoat = 0;
		}
		if ((cv == 2 && c == 13) || c == 27) {
			thoat = 0;
		}

		textcolor(112);
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
	delete[]SACH;SACH = NULL;
}
void DStre(S_account A[], int N) {
	inbang("nguoi muon", "ngay muon", "ten sach");
	gotoxy(53, 32);cout << "=============================================";
	gotoxy(53, 33);cout << "*nhan phim Enter vao phieu de phat nguoi dung";
	gotoxy(53, 34);cout << "=============================================";
	gotoxy(53, 35);cout << "     *nhan phim Enter lan nua de bo phat     ";
	gotoxy(53, 36);cout << "=============================================";
	gotoxy(53, 37);cout << "  *phieu co nguoi dung bi phat se co mau do  ";
	gotoxy(53, 38);cout << "=============================================";//huong dan su dung
	int sosach = get_F_N("books_infor.txt");
	int sophieu = get_F_N("abc.txt");
	int sond = get_F_N("users_infor.txt");
	int  bd = 0, thoat = 1, sotrang = sophieu / MAX_cot + 1, n, cv = 0;//cv dieu kieu dong bd dieu khien trang
	S_book *SACH = new S_book[sosach];
	S_Book_Order *PHIEU = new S_Book_Order[sotrang*MAX_cot];
	S_user *ND = new S_user[sond];
	GetFileBookData(SACH, sosach);
	GetfileOrderData(PHIEU, sophieu, false);//chi lay phieu bi tre han nen cp=false
	GetFileUserData(ND, sond);
	for (int i = sophieu;i<sotrang*MAX_cot;i++) {//cac phieu du thi cho cac id=-1
		PHIEU[i].bookid = -1;
		PHIEU[i].userid = -1;
	}
	if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
	else { n = MAX_cot; }
	inDS2(SACH, ND, PHIEU, A, bd, n, true);
	sotrang = sophieu / MAX_cot + 1;
	gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
	if (sophieu == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
	else {
		while (thoat) {
			textcolor(250);//doi mau cua phieu dang duoc chi toi
			if (PHIEU[bd + cv].bookid == -1) { cv = 0; }
			gotoxy(31, 8 + cv);cout << ND[A[PHIEU[cv + bd].userid - 1].idu - 1].hovaten;
			gotoxy(60, 8 + cv);cout << PHIEU[bd + cv].day.ngay << "/" << PHIEU[bd + cv].day.thang << "/" << PHIEU[bd + cv].day.nam;//in ngay(khó)
			gotoxy(74, 8 + cv);cout << SACH[PHIEU[cv + bd].bookid - 1].tensach;
			char c = _getch();
			int cv1 = cv;//cv1 de luu lai vi tri cu de co the tra lai mau ban dau cho doi tuong vua duoc di qua
			if (c == 'H') { cv--; }//dieu khieu dong duoc chon
			if (c == 'P') { cv++; }
			if (cv == -1) { cv = 19; }
			if (cv == 20) { cv = 0; }

			textcolor(240);
			if (c == 'K') {//dieu kien trang duoc chon
				bd -= MAX_cot;
				if (bd < 0) bd = (sotrang - 1) * 20;
				if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
				else { n = MAX_cot; }
				inDS2(SACH, ND, PHIEU, A, bd, n, true);
			}
			if (c == 'M') {
				bd += MAX_cot;
				if (bd > sophieu) bd = 0;
				if (sophieu - bd<MAX_cot) { n = sophieu - bd; }
				else { n = MAX_cot; }
				inDS2(SACH, ND, PHIEU, A, bd, n, true);
			}//chon Enter thi:
			if (c == 13) ND[A[PHIEU[cv + bd].userid - 1].idu - 1].phat = !ND[A[PHIEU[cv + bd].userid - 1].idu - 1].phat;//chon phieu nao thi tat ca cac phieu cua nguoi dung do se bi phat
			if (c == 27) {//EsCde thoat va viet lai file
				thoat = 0;
				OverWriteUser(ND, sond);
			}
			if (PHIEU[bd + cv1].bookid == -1) { cv1 = 0; }
			textcolor(240 + ND[A[PHIEU[cv1 + bd].userid - 1].idu - 1].phat * 12);//tra lai mau cu
			gotoxy(31, 8 + cv1);cout << str_to_name(ND[A[PHIEU[cv1 + bd].userid - 1].idu - 1].hovaten);
			gotoxy(60, 8 + cv1);cout << PHIEU[bd + cv1].day.ngay << "/" << PHIEU[bd + cv1].day.thang << "/" << PHIEU[bd + cv1].day.nam;
			gotoxy(74, 8 + cv1);cout << SACH[PHIEU[cv1 + bd].bookid - 1].tensach;
		}
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);

	HCN2(15, 53, 30, 45, 16);
	textcolor(240);

	delete[]SACH; SACH = NULL;
	delete[]PHIEU;PHIEU = NULL;
	delete[]ND;ND = NULL;
};
void thong_bao(S_account A[], int N, int CSO) {
	int sond = get_F_N("users_infor.txt");
	S_user *ND = new S_user[sond];
	int sosach = get_F_N("books_infor.txt");
	S_book *SACH = new S_book[sosach];
	int sophieu = get_F_N("abc.txt");
	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	time_t baygio = time(0);
	struct tm abc;
	localtime_s(&abc, &baygio);
	int ngay = abc.tm_mday, thang = abc.tm_mon + 1, nam = abc.tm_year + 1900;
	GetFileUserData(ND, sond);
	GetFileBookData(SACH, sosach);
	GetfileOrderData(PHIEU, sophieu);
	if (!ND[A[CSO].idu - 1].phat) {//neu khong bi phat
		gotoxy(53, 32);cout << "=============================================";
		gotoxy(53, 33);cout << "*             CAC SACH DA MUON               ";
		gotoxy(53, 34);cout << "=============================================";
		gotoxy(53, 35);cout << "*Mau VANG la sap het han tra,DO la da tre han";
		gotoxy(53, 36);cout << "=============================================";
		int chon = 0;
		for (int i = 0;i < sophieu;i++) {
			if (A[CSO].id == PHIEU[i].userid) {//chi hien ra cac thong bao
				int chenhlech = songayhientai(nam, thang, ngay) - songayhientai(PHIEU[i].day.nam, PHIEU[i].day.thang, PHIEU[i].day.ngay);
				textcolor(240 + (chenhlech>2) * 6);
				gotoxy(60, 38 + chon);cout << SACH[PHIEU[i].bookid - 1].tensach << " - "
					<< PHIEU[i].day.ngay << "/" << PHIEU[i].day.thang << "/" << PHIEU[i].day.nam;
				chon++;
			}
		}
		char c;
		do {
			c = _getch();
		} while (c != 13 && c != 27);
	}
	else {//da bi phat
		gotoxy(53, 32);cout << "=============================================";
		gotoxy(53, 33);cout << "             *CAC SACH DA MUON               ";
		gotoxy(53, 34);cout << "=============================================";
		gotoxy(53, 35);cout << "*Mau VANG la sap het han tra,DO la da tre han";
		gotoxy(53, 36);cout << "=============================================";
		gotoxy(53, 37);cout << "    *BAN DA NOP TRE HAN MOT VAI CUON SACH    ";
		gotoxy(53, 38);cout << "=============================================";
		gotoxy(57, 45);cout << "TRA SACH";
		gotoxy(80, 45);cout << "THOAT";
		int chon = 0, danh_dau[5], x = 0;
		for (int i = 0;i < sophieu;i++) {
			if (A[CSO].id == PHIEU[i].userid) {
				int chenhlech = songayhientai(nam, thang, ngay) - songayhientai(PHIEU[i].day.nam, PHIEU[i].day.thang, PHIEU[i].day.ngay);
				textcolor(240 + (chenhlech>2) * 6 + (chenhlech>5) * 6);//sach tre han bi in mau do
				gotoxy(60, 39 + chon);cout << SACH[PHIEU[i].bookid - 1].tensach << " - "
					<< PHIEU[i].day.ngay << "/" << PHIEU[i].day.thang << "/" << PHIEU[i].day.nam;
				chon++;
				if (chenhlech>5) {
					danh_dau[x] = i;//danh dau sach tre han de neu chon thi se tra cac sach nay lai
					x++;
				}
			}
		}
		int cv = 1, thoat = 1;
		while (thoat) {
			textcolor(243);
			gotoxy(55 + (cv - 1) * 23, 45);cout << "\20\20";
			char c = _getch();
			int cv1 = cv;
			if (c == 'H' || c == 'K') { cv--; }
			if (c == 'P' || c == 'M') { cv++; }
			if (cv == 0) { cv = 2; }
			if (cv == 3) { cv = 1; }
			if (cv == 1 && c == 13) {//chon thi tra het sach mau do va het bi phat
				for (int i = 0;i<5;i++) {
					for (int j = 0;j<x;j++) {
						if (A[CSO].DS_muon[i] == PHIEU[danh_dau[j]].bookid) {
							SACH[A[CSO].DS_muon[i] - 1].conlai++;
							A[CSO].DS_muon[i] = 0;
						}
					}
				}
				sapxepgiam(A[CSO].DS_muon, 5);
				ND[A[CSO].idu - 1].phat = false;
				for (int i = x - 1;i >= 0;i--) {
					for (int j = danh_dau[i] + 1;j<sophieu;j++) {
						PHIEU[j - 1] = PHIEU[j];
					}
					sophieu--;
				}
				OverWriteAccount(A, N);
				OverWriteBook(SACH, sosach);
				OverWriteOrder(PHIEU, sophieu);
				OverWriteUser(ND, sond);
				gotoxy(53, 37);cout << "    **BAN DA TRA LAI CAC SACH HET HAN NOP    ";
				_getch();
				thoat=0;
			}
			if ((cv == 2 && c == 13) || c == 27) { thoat = 0; }//huy thi thoat ra
			gotoxy(55 + (cv1 - 1) * 23, 45);cout << "  ";
		}
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
	delete[]ND;ND = NULL;
	delete[]SACH; SACH = NULL;
	delete[]PHIEU;PHIEU = NULL;
}
void conv_longlong_money(string& str, int number) {//ham tinh tien $$
	int thuong, sodu;
	do {
		thuong = number / 10;
		sodu = number - thuong * 10;
		switch (sodu) {
		case 0:str = "0" + str;break;
		case 1:str = "1" + str;break;
		case 2:str = "2" + str;break;
		case 3:str = "3" + str;break;
		case 4:str = "4" + str;break;
		case 5:str = "5" + str;break;
		case 6:str = "6" + str;break;
		case 7:str = "7" + str;break;
		case 8:str = "8" + str;break;
		case 9:str = "9" + str;break;
		}
		number = (number - sodu) / 10;
		if ((str.length() % 3 == 0) && thuong != 0) {
			str = "," + str;
		}
	} while (thuong != 0);
	str += " VND";
}
void QLND(S_account A[], int N) {//menu cac chuc nang cua QUAN LI voi nguoi dung
	HCN2(15, 1, 30, 49, 16);
	textcolor(240);
	gotoxy(15, 36);cout << "    CHINH SUA        ";
	gotoxy(15, 37);cout << "    THEM VAO         ";
	gotoxy(15, 38);cout << "    XOA              ";
	gotoxy(15, 39);cout << "    THOAT            ";
	int cv = 1, thoat = 1;
	while (thoat) {
		gotoxy(13, 35 + cv);
		cout << "\20";
		gotoxy(36, 35 + cv);
		cout << "\21";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 4; }
		if (cv == 5) { cv = 1; }
		if ((cv == 1) && (c == 13)) { suanguoidung(A, N); }
		if ((cv == 2) && (c == 13)) { them_user(); }
		if ((cv == 3) && (c == 13)) { xoanguoidung(A, N); }
		if ((c == 27) || (cv == 4) && (c == 13)) {
			thoat = 0;
		}
		gotoxy(13, 35 + cv1);
		cout << " ";
		gotoxy(36, 35 + cv1);
		cout << " ";
	}
};
void QLTK(S_account A[], int N) {//menu cac chuc nang cua quan li voi tai khoan
	HCN2(15, 1, 30, 49, 16);//xoa menu chung
	textcolor(240);
	gotoxy(15, 36);cout << "    THEM VAO         ";
	gotoxy(15, 37);cout << "    XOA              ";
	gotoxy(15, 38);cout << "    KHOA/MO          ";
	gotoxy(15, 39);cout << "    RESET PASSWORD   ";
	gotoxy(15, 40);cout << "    THOAT            ";
	int cv = 1, thoat = 1;
	while (thoat) {
		gotoxy(13, 35 + cv);
		cout << "\20";
		gotoxy(36, 35 + cv);
		cout << "\21";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 5; }
		if (cv == 6) { cv = 1; }
		if ((cv == 1) && (c == 13)) { themtaikhoan(N); }
		if ((cv == 2) && (c == 13)) { Xoataikhoan(A, N); }
		if ((cv == 3) && (c == 13)) { Khoa_or_mo(A, N); }
		if ((cv == 4) && (c == 13)) { toogle_passwork(A, N); }
		if ((c == 27) || (cv == 5) && (c == 13)) {
			thoat = 0;
		}
		gotoxy(13, 35 + cv1);
		cout << " ";
		gotoxy(36, 35 + cv1);
		cout << " ";
	}
};
void inDS3(S_user B[], int pos, int n) {//ham in thong tin user ra bang 
	for (int i = 0;i<MAX_cot;i++) {//    thong tin lay tu 1 mang B in tu vi tri pos va in n phan tu
		gotoxy(31, 8 + i);cout << "                            ";
		gotoxy(60, 8 + i);cout << "            ";
		gotoxy(74, 8 + i);cout << "                      ";
	}
	for (int i = pos;i<n + pos;i++) {
		gotoxy(31, 8 + i - pos);cout << str_to_name(B[i].hovaten);
		gotoxy(60, 8 + i - pos);cout << B[i].mssv;
		gotoxy(74, 8 + i - pos);cout << B[i].email;
	}
	textcolor(240);
};
void them_user() {//them vao 1 user chua co tai khoan
	S_user A_user;
	HCN2(3, 53, 30, 45, 16);
	string ngay, thang, nam;
	A_user.ngaysinh.ngay = A_user.ngaysinh.thang = A_user.ngaysinh.nam = 0;
	A_user.phat = false;
	int x1 = 55, x2 = 55, x3 = 55, x4 = 61, x5 = 77, x6 = 91;
	textcolor(62);//in ra cac dong giao dien (kha giong ham dang ki)
	gotoxy(55, 30);cout << "HO VA TEN :";
	ToMau(55, 31, "                              ", 255, 62);
	gotoxy(55, 34);cout << "NGAY THANG NAM SINH:   ";
	gotoxy(55, 35);cout << "ngay:          thang:          nam:        ";
	ToMau(61, 35, "    ", 255, 62);ToMau(77, 35, "    ", 255, 62);ToMau(91, 35, "    ", 255, 62);
	gotoxy(55, 37);cout << "Email: ";
	ToMau(55, 38, "                              ", 255, 62);
	gotoxy(55, 40);cout << "Ma so sinh vien: ";
	ToMau(55, 41, "                    ", 255, 62);
	gotoxy(78, 40);cout << "gioi tinh: ";
	gotoxy(78, 41);cout << "Nam:          Nu:";
	ToMau(83, 41, " ", 255, 14);ToMau(96, 41, " ", 255, 62);
	gotoxy(57, 45);cout << "THEM MOI";
	gotoxy(80, 45);cout << "HUY BO";
	int cvX[7] = { 53,53,53,53,76,55,78 }, cvY[7] = { 30,34,37,40,40,45,45 };
	int thoat = 1, cv = 0;
	while (thoat) {
		textcolor(63);
		gotoxy(cvX[cv], cvY[cv]);cout << "\20\20";
		char c = _getch();
		int cv1 = cv;
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == -1) { cv = 6; }
		if (cv == 7) { cv = 0; }
		if ((cv == 0) && (c == 13)) { xulichuoi(A_user.hovaten, 'y', x1, 31); }//nhap ten
		if ((cv == 1) && (c == 13)) { nhapngay(x4, x5, x6, ngay, thang, nam, 60, 76, 90, 35); }//nhap ngay thang nam sinh
		if ((cv == 2) && (c == 13)) { xulichuoi(A_user.email, 'y', x2, 38); }//nhap email lien lac
		if ((cv == 3) && (c == 13)) { xulichuoi(A_user.mssv, 'y', x3, 41, 19); }//nhap mssv
		if ((cv == 4) && (c == 13)) { GT(A_user.gioitinh, 82, 95, 41); }//nhap gioi tinh
		if ((cv == 5) && (c == 13)) {
			fstream f;
			stringstream(ngay) >> A_user.ngaysinh.ngay;
			stringstream(thang) >> A_user.ngaysinh.thang;
			stringstream(nam) >> A_user.ngaysinh.nam;
			A_user.id = get_F_N("users_infor.txt") + 1;
			f.open("users_infor.txt", ios::app);
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
				<< setw(5) << left << A_user.phat
				<< endl;
			f.close();
			thoat = 0;
		}
		if ((cv == 6 && c == 13) || c == 27) { thoat = 0; }
		gotoxy(cvX[cv1], cvY[cv1]);cout << "  ";
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void xoataikhoan(S_account A[], int &N, int CSO, S_Book_Order PHIEU[], int &sophieu) {//chua ghi ra file
	for (int j = sophieu - 1;j >= 0;j--) {//khi xoa moi tai khoan thi cung phai thay doi ve cac thong tin phieu muon lien quan toi no
		if (PHIEU[j].userid == A[CSO].id) {
			for (int k = j + 1;k<sophieu;k++) {
				PHIEU[k - 1] = PHIEU[k];
			}
			sophieu--;
		}
	}
	for (int j = 0;j<sophieu;j++) {
		if (PHIEU[j].userid>A[CSO].id) { PHIEU[j].userid--; }//cac tai khoan co ID lon hon tai khoan bi xoa thi se giam
	}//                                                        Id xuong 1 den dam bao luon theo thu tu dem
	for (int i = CSO + 1;i<N;i++) {//gio moi xoa tai khoan
		A[i - 1] = A[i];
		A[i - 1].id--;//giam id
	}
	N--;
};
void xoanguoidung(S_account AA[], int &NN) {
	int N = NN;
	S_account *A = new S_account[(N / MAX_cot + 1)*MAX_cot];
	for (int i = 0;i<N;i++) A[i] = AA[i];
	inbang("ten nguoi dung", "ma so     ", "Email     ");//bang moi de in thong tin ve nguoi dung
	gotoxy(53, 32);cout << "=============================================";
	gotoxy(53, 33);cout << "*     nhan phim Enter vao phieu de xoa       ";
	gotoxy(53, 34);cout << "=============================================";
	gotoxy(53, 35);cout << "     *nhan phim EsC khi da xoa xong          ";
	gotoxy(53, 36);cout << "=============================================";
	gotoxy(53, 37);cout << "    *chon XOA de xoa tat ca User vua chon    ";
	gotoxy(53, 38);cout << "=============================================";
	gotoxy(57, 45);cout << "XOA";
	gotoxy(80, 45);cout << "HUY BO";
	int sophieu = get_F_N("abc.txt");
	int sond = get_F_N("users_infor.txt");
	int  bd = 0, thoat = 1, sotrang = sond / MAX_cot + 1, n, cv = 0;

	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	S_user *ND = new S_user[sotrang*MAX_cot];

	GetfileOrderData(PHIEU, sophieu);
	GetFileUserData(ND, sond);
	for (int i = sond;i<sotrang*MAX_cot;i++) {
		ND[i].id = -1;
	}
	if (sond - bd<MAX_cot) { n = sond - bd; }
	else { n = MAX_cot; }
	inDS3(ND, bd, n);
	sotrang = (sond-1) / MAX_cot + 1;
	gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
	if (sond == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
	else {
		while (thoat) {
			textcolor(250);
			if (ND[bd + cv].id == -1) { cv = 0; }
			gotoxy(31, 8 + cv);cout << str_to_name(ND[bd + cv].hovaten);
			gotoxy(60, 8 + cv);cout << ND[bd + cv].mssv;
			gotoxy(74, 8 + cv);cout << ND[bd + cv].email;
			char c = _getch();
			int cv1 = cv;
			if (c == 'H') { cv--; }
			if (c == 'P') { cv++; }
			if (cv == -1) { cv = 19; }
			if (cv == 20) { cv = 0; }

			textcolor(240);
			if (c == 'K') {
				bd -= MAX_cot;
				if (bd < 0) bd = (sotrang - 1) * 20;
				if (sond - bd<MAX_cot) { n = sond - bd; }
				else { n = MAX_cot; }
				inDS3(ND, bd, n);
			}
			if (c == 'M') {
				bd += MAX_cot;
				if (bd > sond-1) bd = 0;
				if (sond - bd<MAX_cot) { n = sond - bd; }
				else { n = MAX_cot; }
				inDS3(ND, bd, n);
			}
			if (c == 13) {
				for (int i = N - 1;i >= 0;i--) {//xoa cac tai khoan lien quan toi nguoi dung bi xoa
					if (A[i].idu == ND[bd + cv].id) { xoataikhoan(A, N, i, PHIEU, sophieu); }
				}
				for (int i = N - 1;i >= 0;i--) {//giam id ket noi voi nguoi dung di 1
					if (A[i].idu>ND[bd + cv].id) { A[i].idu--; }
				}
				for (int i = bd + cv + 1;i<sond;i++) {//xoa nguoi dung
					ND[i - 1] = ND[i];
					ND[i - 1].id--;
				}
				ND[sond - 1].id = -1;
				sond--;
				if (bd > sond) bd = 0;
				if (sond - bd<MAX_cot) { n = sond - bd; }
				else { n = MAX_cot; }
				inDS3(ND, bd, n);
			};
			if (c == 27) {
				thoat = 0;
				gotoxy(58, 43);cout << "Viet lai file nguoi dung ?";

				int cv2 = 0, thoat1 = 1;
				while (thoat1) {//lua chon xem co viet lai file nguoi dung hay khong
					gotoxy(56 + 23 * cv2, 45);cout << "\20";//nghia la co luu xoa thong tin tren file.txt hay ko
					gotoxy(61 + 27 * cv2, 45);cout << "\21";
					char c1 = _getch();
					int cv3 = cv2;
					if (c1 == 'H' || c1 == 'K') { cv2--; }
					if (c1 == 'P' || c1 == 'M') { cv2++; }
					if (cv2 == -1) { cv2 = 1; }
					if (cv2 == 2) { cv2 = 0; }
					if (cv2 == 0 && c1 == 13) {
						thoat1 = 0;
						OverWriteAccount(A, N);
						if (N<NN) AA[N].id = -1;
						NN = N;
						for (int k = 0;k<NN;k++) AA[k] = A[k];
						OverWriteUser(ND, sond);
						OverWriteOrder(PHIEU, sophieu);
						gotoxy(58, 44);cout << "DA XOA XONG!";
						_getch();
					}
					if ((cv2 == 1 && c1 == 13) || c1 == 27) { thoat1 = 0; }
					gotoxy(56 + 23 * cv3, 45);cout << " ";
					gotoxy(61 + 27 * cv3, 45);cout << " ";
				}
			}
			if (ND[bd + cv1].id == -1) { cv1 = 0; }
			textcolor(240);
			gotoxy(31, 8 + cv1);cout << str_to_name(ND[bd + cv1].hovaten);
			gotoxy(60, 8 + cv1);cout << ND[bd + cv1].mssv;
			gotoxy(74, 8 + cv1);cout << ND[bd + cv1].email;
		}
		HCN2(15, 31, 8, 28, 20);
		HCN2(15, 60, 8, 13, 20);
		HCN2(15, 74, 8, 21, 20);
		delete[]PHIEU;PHIEU = NULL;
		delete[]ND;ND = NULL;
		delete[]A;A = NULL;
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void kaguroo(S_user A[], int N, S_user B[], int &b, string s) {//chuyen cac nguoi dung trong A co xau con lai s qua B
	for (int i = 0;i<N;i++) {
		if ((str_to_name(A[i].hovaten).find(s) != -1) || (A[i].email.find(s) != -1) || (A[i].mssv.find(s) != -1)) {
			B[b] = A[i];
			b++;
		}
	}
};
void suanguoidung(S_account A[], int &N) {
	inbang("ten nguoi dung", "   ma so   ", "   Email    ");
	HCN2(3, 53, 30, 45, 16);
	textcolor(62);
	gotoxy(57, 30);cout << "tim nguoi dung:";
	ToMau(57, 31, "                              ", 240, 62);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int sond = 0, sond1 = get_F_N("users_infor.txt"), bd = 0, sotrang = sond1 / MAX_cot + 1, n;
	S_user *ND = new S_user[sotrang*MAX_cot], *ND1 = new S_user[sotrang*MAX_cot];
	string fstring;
	string A0[10] = { "0","1","2","3","4","5","6","7","8","9" };
	GetFileUserData(ND1, sond1);
	int cvX[3] = { 55,55,78 }, cvY[3] = { 30,45,45 };
	int thoat1 = 1, cvo = 0, x1 = 57;
	while (thoat1) {
		textcolor(63);
		gotoxy(cvX[cvo], cvY[cvo]);cout << "\20\20";
		char c = _getch();
		int cvo1 = cvo;
		if (c == 'H' || c == 'K') { cvo--; }
		if (c == 'P' || c == 'M') { cvo++; }
		if (cvo == -1) { cvo = 2; }
		if (cvo == 3) { cvo = 0; }

		if ((cvo == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 31);
			kaguroo(ND1, sond1, ND, sond, fstring);//loc theo thong tin tim kiem
			sotrang = sond / MAX_cot + 1;//xu li tren mang vua tim duoc
			for (int i = sond;i<sotrang*MAX_cot;i++) {
				ND[i].id = -1;
			}
			if (sond - bd<MAX_cot) { n = sond - bd; }
			else { n = MAX_cot; }
			inDS3(ND, bd, n);
			sotrang = (sond-1) / MAX_cot + 1;
			gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
			if (sond == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
			else {
				int thoat = 1, cv = 0;
				while (thoat) {
					textcolor(250);
					if (ND[bd + cv].id == -1) { cv = 0; }
					gotoxy(31, 8 + cv);cout << str_to_name(ND[bd + cv].hovaten);
					gotoxy(60, 8 + cv);cout << ND[bd + cv].mssv;
					gotoxy(74, 8 + cv);cout << ND[bd + cv].email;
					char c = _getch();
					int cv1 = cv;
					if (c == 'H') { cv--; }
					if (c == 'P') { cv++; }
					if (cv == -1) { cv = 19; }
					if (cv == 20) { cv = 0; }

					textcolor(240);
					if (c == 'K') {
						bd -= MAX_cot;
						if (bd < 0) bd = (sotrang - 1) * 20;
						if (sond - bd<MAX_cot) { n = sond - bd; }
						else { n = MAX_cot; }
						inDS3(ND, bd, n);
					}
					if (c == 'M') {
						bd += MAX_cot;
						if (bd > sond-1) bd = 0;
						if (sond - bd<MAX_cot) { n = sond - bd; }
						else { n = MAX_cot; }
						inDS3(ND, bd, n);
					}
					if (c == 13) {
						textcolor(62);//in ra thong tin nguoi dung cu
						gotoxy(55, 32);cout << "HO VA TEN :";
						ToMau(55, 33, "                              ", 255, 62);
						gotoxy(55, 36);cout << "NGAY THANG NAM SINH:   ";
						gotoxy(55, 37);cout << "ngay:          thang:          nam:        ";
						ToMau(61, 37, "    ", 255, 62);ToMau(77, 37, "    ", 255, 62);ToMau(91, 37, "    ", 255, 62);
						gotoxy(55, 39);cout << "Email: ";
						ToMau(55, 40, "                              ", 255, 62);
						gotoxy(55, 42);cout << "Ma so sinh vien: ";
						ToMau(55, 43, "                    ", 255, 62);
						gotoxy(78, 42);cout << "gioi tinh: ";
						gotoxy(78, 43);cout << "Nam:          Nu:";
						ToMau(83, 43, " ", 255, 14);ToMau(96, 43, " ", 255, 62);
						string ngay = A0[ND[bd + cv].ngaysinh.ngay / 10] + A0[ND[bd + cv].ngaysinh.ngay % 10];
						string thang = A0[ND[bd + cv].ngaysinh.thang / 10] + A0[ND[bd + cv].ngaysinh.thang % 10];
						string nam = A0[ND[bd + cv].ngaysinh.nam / 1000] + A0[(ND[bd + cv].ngaysinh.nam % 1000) / 100] + A0[(ND[bd + cv].ngaysinh.nam % 100) / 10] + A0[ND[bd + cv].ngaysinh.nam % 10];
						textcolor(240);//chuyen ngay thang nam qua chuoi de de xu li
						gotoxy(55, 33);cout << ND[bd + cv].hovaten;
						gotoxy(55, 40);cout << ND[bd + cv].email;
						gotoxy(55, 43);cout << ND[bd + cv].mssv;
						gotoxy(61, 37);cout << ngay;gotoxy(77, 37);cout << thang;gotoxy(91, 37);cout << nam;
						if (ND[bd + cv].gioitinh) { gotoxy(83, 43);cout << "x"; }
						else { gotoxy(96, 43);cout << "x"; }
						int thoat0 = 1, cv2 = 0;
						int cvX1[7] = { 53,53,53,53,76,55,78 }, cvY1[7] = { 32,36,39,42,42,45,45 };
						int x2 = 55 + ND[bd + cv].hovaten.length(), x3 = 55 + ND[bd + cv].email.length(), x4 = 55 + ND[bd + cv].mssv.length();
						int x5 = 61 + ngay.length(), x6 = 77 + thang.length(), x7 = 91 + nam.length();
						while (thoat0) {
							textcolor(63);
							gotoxy(cvX1[cv2], cvY1[cv2]);cout << "\20\20";
							char c1 = _getch();
							int cv3 = cv2;
							if (c1 == 'H' || c1 == 'K') { cv2--; }
							if (c1 == 'P' || c1 == 'M') { cv2++; }
							if (cv2 == -1) { cv2 = 6; }
							if (cv2 == 7) { cv2 = 0; }

							if ((cv2 == 0) && (c1 == 13)) { xulichuoi(ND[bd + cv].hovaten, 'y', x2, 33); }//nhap ten
							if ((cv2 == 1) && (c1 == 13)) { nhapngay(x5, x6, x7, ngay, thang, nam, 60, 76, 90, 37); }//nhap ngay thang nam sinh
							if ((cv2 == 2) && (c1 == 13)) { xulichuoi(ND[bd + cv].email, 'y', x3, 40); }//nhap email lien lac
							if ((cv2 == 3) && (c1 == 13)) { xulichuoi(ND[bd + cv].mssv, 'y', x4, 43, 19); }//nhap mssv
							if ((cv2 == 4) && (c1 == 13)) { GT(ND[bd + cv].gioitinh, 82, 95, 43); }//nhap gioi tinh
							stringstream(ngay) >> ND[bd + cv].ngaysinh.ngay;
							stringstream(thang) >> ND[bd + cv].ngaysinh.thang;
							stringstream(nam) >> ND[bd + cv].ngaysinh.nam;
							if ((cv2 == 5) && (c1 == 13)) {//neu chon XONG
								thoat0 = 0;
								int j = 0;
								while (j<sond1 && ND1[j].id != ND[bd + cv].id) {
									j++;
								}
								ND1[j] = ND[bd + cv];//sua lai thong tin tren mang chinh
							}
							if ((cv2 == 6) && (c1 == 13)) {//neu chon HUY
								thoat0 = 0;
								int j = 0;
								while (j<sond1 && ND1[j].id != ND[bd + cv].id) {
									j++;
								}
								ND[bd + cv] = ND1[j];//sua lai thong tin da bi thay doi tro ve nhu cu
							}
							textcolor(63);
							gotoxy(cvX1[cv3], cvY1[cv3]);cout << "  ";
						}
					};
					if (c == 27) {
						thoat = 0;
					}
					if (ND[bd + cv1].id == -1) { cv1 = 0; }
					textcolor(240);
					gotoxy(31, 8 + cv1);cout << str_to_name(ND[bd + cv1].hovaten);
					gotoxy(60, 8 + cv1);cout << ND[bd + cv1].mssv;
					gotoxy(74, 8 + cv1);cout << ND[bd + cv1].email;
				}
				sond = 0;
			}
		}
		if ((cvo == 1) && c == 13) {//neu chon xong thi viet lai file
			OverWriteUser(ND1, sond1);
			thoat1 = 0;
		}
		if ((cvo == 2 && c == 13) || c == 27) {//neu khong thi thoat va ko lam gi ca
			thoat1 = 0;
		}

		textcolor(63);
		gotoxy(cvX[cvo1], cvY[cvo1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);
	delete[]ND1;ND1 = NULL;
	delete[]ND;ND = NULL;
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void VT(int X[], int x1 = 66, int x2 = 80, int x3 = 94, int y = 39) {//ham chon vai tro
	int thoat = 1, cv = 1;
	int x[3] = { x1,x2,x3 };//vi tri hoang do chon vai tro
	while (thoat) {
		textcolor(115);
		char a[2] = { ' ','x' };
		gotoxy(x[cv - 1], y);cout << "\20";gotoxy(x[cv - 1] + 2, y);cout << "\21";//in con tro danh dau
		char c = _getch();//nhan tin hieu dieu khien
		int cv1 = cv;//luu tin hieu dieu khien cu
		if (c == 'H' || c == 'K') { cv--; }
		if (c == 'P' || c == 'M') { cv++; }
		if (cv == 0) { cv = 3; }
		if (cv == 4) { cv = 1; }
		textcolor(240);
		if ((cv == 1) && (c == 13)) { X[0] = !X[0];gotoxy(x1 + 1, y);cout << a[X[0]]; }
		if ((cv == 2) && (c == 13)) { X[1] = !X[1];gotoxy(x2 + 1, y);cout << a[X[1]]; }
		if ((cv == 3) && (c == 13)) { X[2] = !X[2];gotoxy(x3 + 1, y);cout << a[X[2]]; }
		if (c == 27) { thoat = 0; }//thoat khi go EsC
		textcolor(112);
		gotoxy(x[cv1 - 1], y);cout << " ";gotoxy(x[cv1 - 1] + 2, y);cout << " ";//xoa vi tri con tro cu
	}
};
void themtaikhoan(int N) {//N la do dai cua file tai khoan truoc khi them
	inbang("ten nguoi dung", "ma so     ", "Email     ");
	int sond = get_F_N("users_infor.txt");
	int  bd = 0, thoat = 1, sotrang = sond / MAX_cot + 1, n, cv = 0;
	S_user *ND = new S_user[sotrang*MAX_cot];
	GetFileUserData(ND, sond);
	for (int i = sond;i<sotrang*MAX_cot;i++) {
		ND[i].id = -1;
	}
	if (sond - bd<MAX_cot) { n = sond - bd; }
	else { n = MAX_cot; }
	inDS3(ND, bd, n);
	sotrang = sond / MAX_cot + 1;
	gotoxy(31, 4);cout << "Chon nguoi dung can them tai khoan:";
	if (sond == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
	else {
		while (thoat) {//xu li chon nguoi dung de them tai khoan cho nguoi dung do
			textcolor(250);
			if (ND[bd + cv].id == -1) { cv = 0; }
			gotoxy(31, 8 + cv);cout << str_to_name(ND[bd + cv].hovaten);
			gotoxy(60, 8 + cv);cout << ND[bd + cv].mssv;
			gotoxy(74, 8 + cv);cout << ND[bd + cv].email;
			char c = _getch();
			int cv1 = cv;
			if (c == 'H') { cv--; }
			if (c == 'P') { cv++; }
			if (cv == -1) { cv = 19; }
			if (cv == 20) { cv = 0; }

			textcolor(240);
			if (c == 'K') {
				bd -= MAX_cot;
				if (bd < 0) bd = (sotrang - 1) * 20;
				if (sond - bd<MAX_cot) { n = sond - bd; }
				else { n = MAX_cot; }
				inDS3(ND, bd, n);
			}
			if (c == 'M') {
				bd += MAX_cot;
				if (bd > sond) bd = 0;
				if (sond - bd<MAX_cot) { n = sond - bd; }
				else { n = MAX_cot; }
				inDS3(ND, bd, n);
			}
			if (c == 13) {//da chon
				HCN2(7, 53, 30, 45, 16);
				textcolor(112);
				gotoxy(57, 32);cout << "Ten Dang Nhap: ";
				ToMau(57, 33, "                              ", 240, 112);
				gotoxy(57, 35);cout << "Mat Khau";
				ToMau(57, 36, "                              ", 240, 112);
				gotoxy(57, 38);cout << "Lua Chon Chuc Nang";
				unsigned char a = 219;
				gotoxy(57, 39);textcolor(112);cout << "DOC GIA:      QUAN LI:      THU THU:    ";
				textcolor(255);gotoxy(67, 39);cout << " ";gotoxy(81, 39);cout << " ";gotoxy(95, 39);cout << " ";
				textcolor(112);
				gotoxy(57, 43);cout << "XONG";
				gotoxy(80, 43);cout << "HUY BO";
				int cvX[5] = { 55,55,55,55,78 }, cvY[5] = { 32,35,38,43,43 };
				int thoat1 = 1, cv2 = 0;
				S_account S;//khoi dong 1 tai khoan moi
				S.id = N + 1;
				S.idu = ND[bd + cv].id;
				S.vaitro[0] = 0;S.vaitro[1] = 0;S.vaitro[2] = 0;
				S.DS_muon[0] = 0;S.DS_muon[1] = 0;S.DS_muon[2] = 0;S.DS_muon[3] = 0;S.DS_muon[4] = 0;
				S.khoa = 1;
				int x1 = 57, x2 = 57, x3 = 57;
				while (thoat1) {
					textcolor(115);
					gotoxy(cvX[cv2], cvY[cv2]);cout << "\20\20";
					char c1 = _getch();
					int cv3 = cv2;
					if (c1 == 'H' || c1 == 'K') { cv2--; }
					if (c1 == 'P' || c1 == 'M') { cv2++; }
					if (cv2 == -1) { cv2 = 4; }
					if (cv2 == 5) { cv2 = 0; }
					if ((cv2 == 0) && (c1 == 13)) { xulichuoi(S.tendangnhap, 'y', x1, 33); }//nhap ten
					if ((cv2 == 1) && (c1 == 13)) { xulichuoi(S.matkhau, 'y', x2, 36); }//nhap mat khau
					if ((cv2 == 2) && (c1 == 13)) { VT(S.vaitro); }//nhap vai tro
					if ((cv2 == 3) && (c1 == 13)) {
						fstream f;
						f.open("accounts_infor.txt", ios::app);
						f << setw(5) << left << S.id
							<< setw(5) << left << S.idu
							<< setw(25) << left << S.tendangnhap
							<< setw(20) << left << S.matkhau
							<< setw(5) << left << S.vaitro[0] <<
							setw(5) << left << S.vaitro[1] <<
							setw(5) << left << S.vaitro[2] <<
							S.DS_muon[0] << " " << S.DS_muon[1] << " "
							<< S.DS_muon[2] << " " << S.DS_muon[3] << " "
							<< S.DS_muon[4] << " "
							<< setw(5) << S.khoa << endl;
						f.close();
						thoat1 = 0;
					}
					if ((cv2 == 4 && c1 == 13) || c1 == 27) { thoat1 = 0; }
					gotoxy(cvX[cv3], cvY[cv3]);cout << "  ";
				}
			};
			if (c == 27) { thoat = 0; }

			if (ND[bd + cv1].id == -1) { cv1 = 0; }
			textcolor(240);
			gotoxy(31, 8 + cv1);cout << str_to_name(ND[bd + cv1].hovaten);
			gotoxy(60, 8 + cv1);cout << ND[bd + cv1].mssv;
			gotoxy(74, 8 + cv1);cout << ND[bd + cv1].email;
		}
		HCN2(15, 31, 8, 28, 20);
		HCN2(15, 60, 8, 13, 20);
		HCN2(15, 74, 8, 21, 20);
		delete[]ND;ND = NULL;
	}
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
}
void inDS4(S_user B[], S_account D[], int pos, int n, bool cp = true) {//in thong tin tai khoan
	for (int i = 0;i<MAX_cot;i++) {//cp==0 thi in ra dau X de danh dau tai khoan do co bi reset matkhau chua
		gotoxy(31, 8 + i);cout << "                            ";
		gotoxy(60, 8 + i);cout << "            ";
		gotoxy(74, 8 + i);cout << "                      ";
	}
	string s[2] = { "khoa"," mo " };//tinh tranh cua tai khoan la khoa hay mo ,giup in ra de hon
	for (int i = pos;i<n + pos;i++) {
		gotoxy(31, 8 + i - pos);cout << D[i].tendangnhap;
		gotoxy(60, 8 + i - pos);cout << s[D[i].khoa] << "       ";
		if (!cp && D[i].matkhau == "dummy") { gotoxy(68, 8 + i - pos);cout << "X"; }
		gotoxy(74, 8 + i - pos);cout << B[D[i].idu - 1].hovaten;
	}
	textcolor(240);
};
void kaguroo2(S_user A[], S_account B[], int N, S_account C[], int &b, string s) {//loc tai khoan thich hon sang mang B
	for (int i = 0;i<N;i++) {
		if ((A[B[i].idu - 1].hovaten.find(s) != -1) || (B[i].tendangnhap.find(s) != -1)) {
			C[b] = B[i];
			b++;
		}
	}
};

void Xoataikhoan(S_account AA[], int &NN) {
	int N = NN;
	S_account *A = new S_account[(N / MAX_cot + 1)*MAX_cot];
	for (int i = 0;i<N;i++) A[i] = AA[i];
	inbang("ten tai khoan", "tinh trang", "ten nguoi dung");
	HCN2(3, 53, 30, 45, 16);
	textcolor(62);
	gotoxy(57, 30);cout << "tim tai khoan:";
	ToMau(57, 31, "                              ", 240, 62);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";
	int sophieu = get_F_N("abc.txt");
	int sond = get_F_N("users_infor.txt"), bd = 0, sotrang = N / MAX_cot + 1, n, N2 = 0;
	S_account *S = new S_account[(N / MAX_cot + 1)*MAX_cot];
	S_user *ND = new S_user[sond];
	S_Book_Order *PHIEU = new S_Book_Order[sophieu];
	string fstring, A2[2] = { "khoa"," mo " };
	GetfileOrderData(PHIEU, sophieu);
	GetFileUserData(ND, sond);
	int cvX[3] = { 55,55,78 }, cvY[3] = { 30,45,45 };
	int thoat1 = 1, cvo = 0, x1 = 57;
	while (thoat1) {
		textcolor(63);
		gotoxy(cvX[cvo], cvY[cvo]);cout << "\20\20";
		char c = _getch();
		int cvo1 = cvo;
		if (c == 'H' || c == 'K') { cvo--; }
		if (c == 'P' || c == 'M') { cvo++; }
		if (cvo == -1) { cvo = 2; }
		if (cvo == 3) { cvo = 0; }

		if ((cvo == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 31);
			kaguroo2(ND, A, N, S, N2, fstring);
			sotrang = N2 / MAX_cot + 1;
			for (int i = N2;i<sotrang*MAX_cot;i++) {
				S[i].id = -1;
			}
			if (N2 - bd<MAX_cot) { n = N2 - bd; }
			else { n = MAX_cot; }
			inDS4(ND, S, bd, n);
			sotrang = (N2-1) / MAX_cot + 1;
			gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
			if (N2 == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
			else {
				int thoat = 1, cv = 0;
				while (thoat) {
					textcolor(250);
					if (S[bd + cv].id == -1) { cv = 0; }
					gotoxy(31, 8 + cv);cout << S[bd + cv].tendangnhap;
					gotoxy(60, 8 + cv);cout << A2[S[bd + cv].khoa];
					gotoxy(74, 8 + cv);cout << str_to_name(ND[S[bd + cv].idu - 1].hovaten);
					char c = _getch();
					int cv1 = cv;
					if (c == 'H') { cv--; }
					if (c == 'P') { cv++; }
					if (cv == -1) { cv = 19; }
					if (cv == 20) { cv = 0; }

					textcolor(240);
					if (c == 'K') {
						bd -= MAX_cot;
						if (bd < 0) bd = (sotrang - 1) * 20;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n);
					}
					if (c == 'M') {
						bd += MAX_cot;
						if (bd > N2-1) bd = 0;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n);
					}
					if (c == 13) {
						xoataikhoan(A, N, S[bd + cv].id - 1, PHIEU, sophieu);
						for (int i = bd + cv + 1;i<N2;i++) { S[i - 1] = S[i];S[i - 1].id--; }
						N2--;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						S[N2].id = -1;
						if (n==0) bd=0;
						sotrang=(N2-1)/MAX_cot +1;
						inDS4(ND, S, bd, n);
					};
					if (c == 27 || N2 == 0) {
						thoat = 0;
					}
					if (S[bd + cv1].id == -1) { cv1 = 0; }
					textcolor(240);
					gotoxy(31, 8 + cv1);cout << S[bd + cv1].tendangnhap;
					gotoxy(60, 8 + cv1);cout << A2[S[bd + cv1].khoa];
					gotoxy(74, 8 + cv1);cout << str_to_name(ND[S[bd + cv1].idu - 1].hovaten);
				}
				N2 = 0;
			}
		}
		gotoxy(58, 41);cout << "Luu Thay doi vao File ?";
		if ((cvo == 1) && c == 13) {
			OverWriteAccount(A, N);
			if (N<NN) AA[N].id = -1;
			NN = N;
			for (int k = 0;k<NN;k++) AA[k] = A[k];
			OverWriteOrder(PHIEU, sophieu);
			thoat1 = 0;
		}
		if ((cvo == 2 && c == 13) || c == 27) {
			thoat1 = 0;
		}

		textcolor(63);
		gotoxy(cvX[cvo1], cvY[cvo1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);
	delete[]ND;ND = NULL;
	delete[]S;S = NULL;
	delete[]PHIEU;PHIEU = NULL;
	delete[]A;A = NULL;
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void Khoa_or_mo(S_account AA[], int &N) {
	S_account *A = new S_account[(N / MAX_cot + 1)*MAX_cot];
	for (int i = 0;i<N;i++) A[i] = AA[i];
	inbang("ten tai khoan", "tinh trang", "ten nguoi dung");
	HCN2(3, 53, 30, 45, 16);
	textcolor(62);
	gotoxy(57, 30);cout << "tim tai khoan:";
	ToMau(57, 31, "                              ", 240, 62);
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";

	int sond = get_F_N("users_infor.txt"), bd = 0, sotrang = N / MAX_cot + 1, n, N2 = 0;
	S_account *S = new S_account[(N / MAX_cot + 1)*MAX_cot];
	S_user *ND = new S_user[sond];

	string fstring, A2[2] = { "khoa"," mo " };

	GetFileUserData(ND, sond);
	int cvX[3] = { 55,55,78 }, cvY[3] = { 30,45,45 };
	int thoat1 = 1, cvo = 0, x1 = 57;
	while (thoat1) {
		textcolor(63);
		gotoxy(cvX[cvo], cvY[cvo]);cout << "\20\20";
		char c = _getch();
		int cvo1 = cvo;
		if (c == 'H' || c == 'K') { cvo--; }
		if (c == 'P' || c == 'M') { cvo++; }
		if (cvo == -1) { cvo = 2; }
		if (cvo == 3) { cvo = 0; }

		if ((cvo == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 31);
			kaguroo2(ND, A, N, S, N2, fstring);
			sotrang = (N2-1) / MAX_cot + 1;
			for (int i = N2;i<sotrang*MAX_cot;i++) {
				S[i].id = -1;
			}
			if (N2 - bd<MAX_cot) { n = N2 - bd; }
			else { n = MAX_cot; }
			inDS4(ND, S, bd, n);
			sotrang = (N2-1) / MAX_cot + 1;
			gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
			if (N2 == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
			else {
				int thoat = 1, cv = 0;
				while (thoat) {
					textcolor(250);
					if (S[bd + cv].id == -1) { cv = 0; }
					gotoxy(31, 8 + cv);cout << S[bd + cv].tendangnhap;
					gotoxy(60, 8 + cv);cout << A2[S[bd + cv].khoa];
					gotoxy(74, 8 + cv);cout << str_to_name(ND[S[bd + cv].idu - 1].hovaten);
					char c = _getch();
					int cv1 = cv;
					if (c == 'H') { cv--; }
					if (c == 'P') { cv++; }
					if (cv == -1) { cv = 19; }
					if (cv == 20) { cv = 0; }

					textcolor(240);
					if (c == 'K') {
						bd -= MAX_cot;
						if (bd < 0) bd = (sotrang - 1) * 20;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n);
					}
					if (c == 'M') {
						bd += MAX_cot;
						if (bd > N2-1) bd = 0;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n);
					}
					if (c == 13) {
						S[bd + cv].khoa = !S[bd + cv].khoa;
						A[S[bd + cv].id - 1].khoa = !A[S[bd + cv].id - 1].khoa;
						textcolor(250);
						gotoxy(60, 8 + cv);cout << A2[S[bd + cv].khoa];
					};
					if (c == 27) {
						thoat = 0;
					}
					if (S[bd + cv1].id == -1) { cv1 = 0; }
					textcolor(240);
					gotoxy(31, 8 + cv1);cout << S[bd + cv1].tendangnhap;
					gotoxy(60, 8 + cv1);cout << A2[S[bd + cv1].khoa];
					gotoxy(74, 8 + cv1);cout << str_to_name(ND[S[bd + cv1].idu - 1].hovaten);
				}
				N2 = 0;
			}
		}
		gotoxy(58, 41);cout << "Luu Thay doi vao File ?";
		if ((cvo == 1) && c == 13) {
			OverWriteAccount(A, N);
			for (int k = 0;k<N;k++) AA[k] = A[k];
			thoat1 = 0;
		}
		if ((cvo == 2 && c == 13) || c == 27) {
			thoat1 = 0;
		}

		textcolor(63);
		gotoxy(cvX[cvo1], cvY[cvo1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);
	delete[]ND;ND = NULL;
	delete[]S;S = NULL;
	delete[]A;A = NULL;
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
void toogle_passwork(S_account AA[], int &N) {//ham reset mat khau
	S_account *A = new S_account[(N / MAX_cot + 1)*MAX_cot];
	for (int i = 0;i<N;i++) A[i] = AA[i];
	inbang("ten tai khoan", "tinh trang", "ten nguoi dung");
	HCN2(3, 53, 30, 45, 16);
	textcolor(62);
	gotoxy(57, 30);cout << "tim tai khoan:";
	ToMau(57, 31, "                              ", 240, 62);
	gotoxy(53, 36);cout << "=============================================";
	gotoxy(53, 37);cout << "   Tai khoan da chon de se duoc danh dau X   ";
	gotoxy(53, 38);cout << "=============================================";
	gotoxy(57, 45);cout << "XONG";
	gotoxy(80, 45);cout << "HUY BO";

	int sond = get_F_N("users_infor.txt"), bd = 0, sotrang = N / MAX_cot + 1, n, N2 = 0;
	S_account *S = new S_account[(N / MAX_cot + 1)*MAX_cot];
	S_user *ND = new S_user[sond];

	string fstring, A2[2] = { "khoa"," mo " };

	GetFileUserData(ND, sond);
	int cvX[3] = { 55,55,78 }, cvY[3] = { 30,45,45 };
	int thoat1 = 1, cvo = 0, x1 = 57;
	while (thoat1) {
		textcolor(63);
		gotoxy(cvX[cvo], cvY[cvo]);cout << "\20\20";
		char c = _getch();
		int cvo1 = cvo;
		if (c == 'H' || c == 'K') { cvo--; }
		if (c == 'P' || c == 'M') { cvo++; }
		if (cvo == -1) { cvo = 2; }
		if (cvo == 3) { cvo = 0; }

		if ((cvo == 0) && c == 13) {
			xulichuoi(fstring, 'y', x1, 31);
			kaguroo2(ND, A, N, S, N2, fstring);
			sotrang = N2 / MAX_cot + 1;
			for (int i = N2;i<sotrang*MAX_cot;i++) {
				S[i].id = -1;
			}
			if (N2 - bd<MAX_cot) { n = N2 - bd; }
			else { n = MAX_cot; }
			inDS4(ND, S, bd, n);
			sotrang = (N2-1) / MAX_cot + 1;
			gotoxy(31, 4);cout << "Nhan phim mui ten <- hoac -> de chuyen trang";
			if (N2 == 0) { gotoxy(60, 8);cout << "dummy";_getch(); }
			else {
				int thoat = 1, cv = 0;
				while (thoat) {
					textcolor(250);
					if (S[bd + cv].id == -1) { cv = 0; }
					gotoxy(31, 8 + cv);cout << S[bd + cv].tendangnhap;
					gotoxy(60, 8 + cv);cout << A2[S[bd + cv].khoa];
					gotoxy(74, 8 + cv);cout << str_to_name(ND[S[bd + cv].idu - 1].hovaten);
					char c = _getch();
					int cv1 = cv;
					if (c == 'H') { cv--; }
					if (c == 'P') { cv++; }
					if (cv == -1) { cv = 19; }
					if (cv == 20) { cv = 0; }

					textcolor(240);
					if (c == 'K') {
						bd -= MAX_cot;
						if (bd < 0) bd = (sotrang - 1) * 20;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n, false);
					}
					if (c == 'M') {
						bd += MAX_cot;
						if (bd > N2-1) bd = 0;
						if (N2 - bd<MAX_cot) { n = N2 - bd; }
						else { n = MAX_cot; }
						if(S[bd].khoa!=0&&S[bd].khoa!=1) bd=0;
						inDS4(ND, S, bd, n, false);
					}
					if (c == 13) {//khi chon mot mat khau de reset thi cho mat khau la mot chuoi khong the trung voi mot mat khau do nguoi dung dat duoc
						if (S[bd + cv].matkhau == "dummy") {//VD dummy co 5 ki tu nen nguoi dung ko the nao dat duoc mot mat khau nhu vay
							S[bd + cv].matkhau = A[S[bd + cv].id - 1].matkhau;//day chi la de dung tam
							textcolor(250);//khi nao co xac nhan thi se chuyen sang 00000000
							gotoxy(68, 8 + cv);cout << " ";
						}
						else {
							S[bd + cv].matkhau = "dummy";
							textcolor(250);
							gotoxy(68, 8 + cv);cout << "X";
						}
					};
					if (c == 27) {
						for (int i = 0;i<N2;i++) {
							if (S[i].matkhau == "dummy") {
								A[S[i].id - 1].matkhau = "00000000";//khi xac nhan thi se chuyen mat khau reset lai thanh 00000000
							}
						}
						thoat = 0;
					}
					if (S[bd + cv1].id == -1) { cv1 = 0; }
					textcolor(240);
					gotoxy(31, 8 + cv1);cout << S[bd + cv1].tendangnhap;
					gotoxy(60, 8 + cv1);cout << A2[S[bd + cv1].khoa];
					gotoxy(74, 8 + cv1);cout << str_to_name(ND[S[bd + cv1].idu - 1].hovaten);
				}
				N2 = 0;
			}
		}
		gotoxy(58, 41);cout << "Luu Thay doi vao File ?";
		if ((cvo == 1) && c == 13) {
			OverWriteAccount(A, N);
			for (int k = 0;k<N;k++) AA[k] = A[k];
			thoat1 = 0;
		}
		if ((cvo == 2 && c == 13) || c == 27) {
			thoat1 = 0;
		}

		textcolor(63);
		gotoxy(cvX[cvo1], cvY[cvo1]);cout << "  ";
	}
	HCN2(15, 31, 8, 28, 20);
	HCN2(15, 60, 8, 13, 20);
	HCN2(15, 74, 8, 21, 20);
	delete[]ND;ND = NULL;
	delete[]S;S = NULL;
	delete[]A;A = NULL;
	HCN2(15, 53, 30, 45, 16);
	textcolor(240);
};
string str_to_name(string s) {
	for (unsigned int i = 0;i < s.length();i++) {
		if (s[i] == '_') s[i] = ' ';
	}
	return s;
}
void name_to_str(string& s) {
	string connect;
	stringstream word(s);
	s = "";
	int skip_1st = 0;
	word >> connect;
	do {
		if (skip_1st != 0) s += "_";
		skip_1st++;
		s += connect;
		word >> connect;
	} while (!word.fail());
}

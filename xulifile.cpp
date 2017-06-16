#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>
#include "thuvien.h"
#include "xulifile.h"
using namespace std;

int get_F_N(string File) {
	fstream f;
	string line;
	int num_of_users = -1;
	f.open(File, ios::in);
	while (!f.eof()) { getline(f, line);num_of_users++; }
	return num_of_users;
};
void GetFileAccountsData(S_account A[], int &N) {
	ifstream f;
	//A=new S_account[N];
	string data;

	f.open("accounts_infor.txt");
	for (int i = 0;i <= N;i++) {
		getline(f, data); stringstream scin(data);
		scin >> A[i].id;
		scin >> A[i].idu;
		scin >> A[i].tendangnhap;
		scin >> A[i].matkhau;
		scin >> A[i].vaitro[0];
		scin >> A[i].vaitro[1];
		scin >> A[i].vaitro[2];
		scin >> A[i].DS_muon[0];
		scin >> A[i].DS_muon[1];
		scin >> A[i].DS_muon[2];
		scin >> A[i].DS_muon[3];
		scin >> A[i].DS_muon[4];
		scin >> A[i].khoa;
	}
	f.close();
};

void OverWriteAccount(S_account A[], int N) {
	ofstream f;

	f.open("accounts_infor.txt");
	for (int i = 0;i<N;i++) {//???????????????
		f << setw(5) << left << A[i].id
			<< setw(5) << left << A[i].idu
			<< setw(25) << left << A[i].tendangnhap
			<< setw(20) << left << A[i].matkhau
			<< setw(5) << left << A[i].vaitro[0] <<
			setw(5) << left << A[i].vaitro[1] <<
			setw(5) << left << A[i].vaitro[2] <<
			A[i].DS_muon[0] << " " << A[i].DS_muon[1] << " "
			<< A[i].DS_muon[2] << " " << A[i].DS_muon[3] << " "
			<< A[i].DS_muon[4] << " " <<
			setw(5) << A[i].khoa << endl;
	};
	f.close();
};
int songayhientai(int year, int month, int day) {//doi so ngay/thang/nam---->so ngay tu 1/1/0000
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}
void GetFileBookData(S_book A[], int N) {
	ifstream f;
	//A=new S_account[N];
	string data;

	f.open("books_infor.txt");
	for (int i = 0;i<N;i++) {
		getline(f, data); stringstream scin(data);
		scin >> A[i].id;
		scin >> A[i].tensach;
		scin >> A[i].tacgia;
		scin >> A[i].theloai;
		scin >> A[i].conlai;
	}
	f.close();
};
void OverWriteBook(S_book A[], int N) {
	ofstream f;
	f.open("books_infor.txt");
	for (int i = 0;i<N;i++) {//???????????????
		f << setw(5) << left << A[i].id <<
			setw(25) << left << A[i].tensach <<
			setw(20) << left << A[i].tacgia <<
			setw(20) << left << A[i].theloai <<
			setw(5) << right << A[i].conlai << endl;
	};
	f.close();
};
void GetfileOrderData(S_Book_Order A[], int &n, bool cp) {//neu cp==false thi chi lay phieu qua han
	ifstream f;
	f.open("abc.txt");
	time_t baygio = time(0);
	struct tm abc;//tim ngay hien tai
	localtime_s(&abc, &baygio);
	int ngay = abc.tm_mday, thang = abc.tm_mon + 1, nam = abc.tm_year + 1900;
	int N = n, j = 0;
	for (int i = 0;i<N;i++) {
		f >> A[j].userid >> A[j].bookid >> A[j].day.ngay >> A[j].day.thang >> A[j].day.nam;
		if (cp) { j++; }
		else if (!cp) {
			int chenhlech = songayhientai(nam, thang, ngay) - songayhientai(A[j].day.nam, A[j].day.thang, A[j].day.ngay);
			if (chenhlech>5) {
				j++;
			}
		}
	}
	f.close();
	n = j;
};
void OverWriteOrder(S_Book_Order A[], int N) {
	ofstream f;
	f.open("abc.txt");
	for (int i = 0;i<N;i++) {
		f << setw(5) << A[i].userid
			<< setw(5) << A[i].bookid
			<< setw(5) << A[i].day.ngay
			<< setw(5) << A[i].day.thang
			<< setw(5) << A[i].day.nam << endl;
	};
	f.close();
};
void GetFileUserData(S_user A[], int N) {
	fstream f;
	f.open("users_infor.txt", ios::in);
	string data, NTNS;

	for (int i = 0;i<N;i++) {
		getline(f, data);
		stringstream scin(data);
		scin >> A[i].id;
		scin >> A[i].hovaten;
		scin >> NTNS;
		scin >> A[i].mssv;
		scin >> A[i].email;
		scin >> A[i].gioitinh;
		scin >> A[i].phat;
		stringstream(NTNS.substr(0, 2)) >> A[i].ngaysinh.ngay;
		stringstream(NTNS.substr(3, 2)) >> A[i].ngaysinh.thang;
		stringstream(NTNS.substr(6, 4)) >> A[i].ngaysinh.nam;
	}
	f.close();
};
void OverWriteUser(S_user A[], int N) {
	ofstream f;
	f.open("users_infor.txt");
	for (int i = 0;i<N;i++) {//???????????????
		name_to_str(A[i].hovaten);
		f << setw(5) << left << A[i].id
			<< setw(35) << left << A[i].hovaten;
		if (A[i].ngaysinh.ngay >= 10) f << A[i].ngaysinh.ngay << "/";
		else f << "0" << A[i].ngaysinh.ngay << "/";
		if (A[i].ngaysinh.thang >= 10)f << A[i].ngaysinh.thang << "/";
		else f << "0" << A[i].ngaysinh.thang << "/";
		f << setw(10) << left << A[i].ngaysinh.nam
			<< setw(15) << left << A[i].mssv
			<< setw(35) << left << A[i].email
			<< setw(5) << left << A[i].gioitinh
			<< setw(5) << left << A[i].phat
			<< endl;
	};
	f.close();
};

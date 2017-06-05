#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
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
	}
	f.close();
};

void OverWriteAccount(S_account A[], int N) {
	ofstream f;

	f.open("accounts_infor.txt");
	for (int i = 0;i<N;i++) {//???????????????
		f << setw(5) << left << A[i].id
			<< setw(5) <<left << A[i].idu
			<< setw(25) << left << A[i].tendangnhap
			<< setw(20) << left << A[i].matkhau 
			<< setw(5) << left << A[i].vaitro[0] <<
			setw(5) << left << A[i].vaitro[1] <<
			setw(5) << left << A[i].vaitro[2] <<
			A[i].DS_muon[0] << " " << A[i].DS_muon[1] << " "
			<< A[i].DS_muon[2] << " " << A[i].DS_muon[3] << " "
			<< A[i].DS_muon[4] << " " << endl;
	};
	f.close();
};

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
void OverWriteBook(S_book A[], int N){
	ofstream f;
	f.open("books_infor.txt");
	for (int i = 0;i<N;i++) {//???????????????
		f << setw(5) << left << A[i].id<<
			 setw(25) << left << A[i].tensach<<
			 setw(20) << left << A[i].tacgia <<
			 setw(20)<<left<<A[i].theloai<<
			 setw(5)<<right<<A[i].conlai<< endl;
	};
	f.close();
};
void GetfileOrderData(S_Book_Order A[],int n){
	ifstream f;
	f.open("abc.txt");
	for (int i=0;i<n;i++){
		f>>A[i].userid>>A[i].bookid>>A[i].day.ngay>>A[i].day.thang>>A[i].day.nam;
	}
	f.close();
};
void OverWriteOrder(S_Book_Order A[], int N){
	ofstream f;
	f.open("abc.txt");
	for (int i = 0;i<N;i++) {
		f<<setw(5)<<A[i].userid
			<<setw(5)<<A[i].bookid
			<<setw(5)<<A[i].day.ngay
			<<setw(5)<<A[i].day.thang
			<<setw(5)<<A[i].day.nam<<endl;
	};
	f.close();
};
void GetFileUserData(S_user A[],int N){
	fstream f;
	f.open("users_infor.txt", ios::in);
	string data, NTNS;
	
	for(int i=0;i<N;i++){
		getline(f, data);
		stringstream scin(data);
		scin >> A[i].id;
		scin >> A[i].hovaten;
		scin >> NTNS;
		scin >> A[i].mssv;
		scin >> A[i].email;
		scin >> A[i].gioitinh;
		stringstream(NTNS.substr(0,2))>> A[i].ngaysinh.ngay;
		stringstream(NTNS.substr(3,2))>> A[i].ngaysinh.thang;
		stringstream(NTNS.substr(6,2))>> A[i].ngaysinh.ngay;
	}
	f.close();
};
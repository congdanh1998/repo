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
		scin >> A[i].tendangnhap;
		scin >> A[i].matkhau;
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
			<< setw(25) << left << A[i].tendangnhap
			<< setw(20) << left << A[i].matkhau <<
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
	}
	f.close();
};

#pragma once
#if !defined(XU_LI_FILE_H)
#define XU_LI_FILE_H
#include <string>
#include "thuvien.h"
	using namespace std;
	int get_F_N(string File);//dem so dong cua 1 file
	void GetFileAccountsData(S_account A[],int & N);//luu het thong tin trong file tai khoan vao mang A voi do dai file la N
	void OverWriteAccount(S_account A[],int N);//viet lai file taikhoan
	void GetFileBookData(S_book A[],int N);//luu het thong tin sach vao mang A[]
	void OverWriteBook(S_book A[], int N);//viet lai file sach
	void GetfileOrderData(S_Book_Order A[],int &n,bool cp = true);//lay thong tin file phieu muon
	void OverWriteOrder(S_Book_Order A[], int N);//viet lai file phieu muon
	void GetFileUserData(S_user A[],int N);//lay thong tin file user
	void OverWriteUser(S_user A[], int N);//viet lai file user
	int songayhientai(int year, int month, int day);//cac tien boi tren mang chi day
#endif

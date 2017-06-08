#pragma once
#if !defined(XU_LI_FILE_H)
#define XU_LI_FILE_H
#include <string>
#include "thuvien.h"
	using namespace std;
	int get_F_N(string File);//dem so dong cua 1 file
	void GetFileAccountsData(S_account A[],int & N);//luu het thong tin trong file tai khoan vao mang A voi do dai file la N
	void OverWriteAccount(S_account A[],int N);
	void GetFileBookData(S_book A[],int N);
	void OverWriteBook(S_book A[], int N);
	void GetfileOrderData(S_Book_Order A[],int &n,bool cp = true);
	void OverWriteOrder(S_Book_Order A[], int N);
	void GetFileUserData(S_user A[],int N);
	void OverWriteUser(S_user A[], int N);
	int songayhientai(int year, int month, int day);//cac tien boi tren mang chi day
#endif

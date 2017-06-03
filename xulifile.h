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
#endif

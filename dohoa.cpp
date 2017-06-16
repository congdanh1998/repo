#include <iostream>
#include <conio.h>
#include <windows.h>
#include "dohoa.h"

using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height) {
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, width, height };
	COORD bufferSize = { 100, 60 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}

// Hàm tô màu.
void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
void ToMau(int x, int y, char *a, int color, int oldcolor) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(oldcolor);
}

void ToMau(int x, int y, string a, int color, int oldcolor) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);//chinh toa do
	textcolor(color);//chon mau
	cout << a;//viet van ban
	textcolor(oldcolor);//tra ve mau cu
}

void hinhchunhat(unsigned char c, int x, int y, int a, int b) {
	gotoxy(x, y);
	int a0 = x, b0 = y;//toa do bat dau
	for (a0;a0 <= x + a;a0++) {
		gotoxy(a0, y);
		cout << c;
	}//duong tren cung

	for (b0;b0 <= y + b;b0++) {
		gotoxy(a0, b0);
		cout << c;
	}//cach ben phai

	for (a0;a0 >= x;a0--) {
		gotoxy(a0, y + b);
		cout << c;
	}//duong duoi cung
	b0--;//thut vao 1 o
	for (b0;b0 >= y;b0--) {
		gotoxy(x, b0);
		cout << c;
	}//cach ben trai
}
void HCN2(int mau, int x, int y, int a, int b) {
	textcolor(mau);
	gotoxy(x, y);
	for (int i = 0;i<b;i++) {
		for (int j = 0;j<a;j++) cout << char(219);
		gotoxy(x, y + i + 1);
	}
}
void ngang(int x, int y, int len) {
	gotoxy(x, y);
	for (int i = 0;i<len;i++) cout << char(196);//196 la ki tu giong "_"
};

void doc(int x, int y, int len) {
	for (int i = 0;i<len;i++) { gotoxy(x, y + i);cout << char(179); }//179la ki tu giong "|"
};
void inbang(string a, string b, string c) {
	int x = (30 - a.length()) / 2, y = (15 - b.length()) / 2, z = (25 - a.length()) / 2;//can le chu
	gotoxy(30, 5);//ve duong o tren cung
	cout << char(218);ngang(31, 5, 28);
	cout << char(194);ngang(60, 5, 13);
	cout << char(194);ngang(74, 5, 23);
	cout << char(191);
	gotoxy(30, 6);cout << char(179);
	gotoxy(59, 6);cout << char(179);
	gotoxy(73, 6);cout << char(179);
	gotoxy(97, 6);cout << char(179);
	gotoxy(30, 7);//ve duong ngang phan cach tieu de va noi dung
	cout << char(195);ngang(31, 7, 28);
	cout << char(197);ngang(60, 7, 13);
	cout << char(197);ngang(74, 7, 23);
	cout << char(180);
	doc(30, 8, 20);//ve cac duong doc
	doc(59, 8, 20);
	doc(73, 8, 20);
	doc(97, 8, 20);
	gotoxy(30, 28);//ve duong ngang duoi cung
	cout << char(192);ngang(31, 28, 28);
	cout << char(193);ngang(60, 28, 13);
	cout << char(193);ngang(74, 28, 23);
	cout << char(217);
	gotoxy(30 + x, 6);cout << a;
	gotoxy(59 + y, 6);cout << b;;
	gotoxy(73 + z, 6);cout << c;//in ra cac chuoi a,b,c o vi tri da can le san
}
/*cout<<" (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)       (_)(_)      "<<endl
<<"	(_)        (_)  (_)     (_)   (_)     (_)  (_)     (_)  (_)      (_)   "<<endl
<<" (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)    (_)      (_)   "<<endl
<<" (_)        (_)  (_)     (_)   (_)          (_)   (_)    (_)      (_)   "<<endl
<<" (_)(_)(_)  (_)  (_)(_)(_)     (_)          (_)     (_)     (_)(_)      "<<endl;*/

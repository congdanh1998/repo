#include <iostream>
#include <conio.h>
#include <windows.h>
#include "dohoa.h"

using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */ 

// Hàm tự viết
void ToMau(int x, int y, char *a, int color,int oldcolor) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(oldcolor);
}

void hinhchunhat(char c,int x,int y,int a,int b){
	gotoxy(x,y);
	int a0=x,b0=y;
	for(a0;a0<=x+a;a0++){
		gotoxy(a0,y);
		cout<<c;
	}
	
	for(b0;b0<=y+b;b0++){
		gotoxy(a0,b0);
		cout<<c;
	}
	
	for(a0;a0>=x;a0--){
		gotoxy(a0,y+b);
		cout<<c;
	}
	b0--;
	for(b0;b0>=y;b0--){
		gotoxy(x,b0);
		cout<<c;
	}
}
void HCN2(int mau,int x,int y,int a,int b){
	textcolor(mau);
	gotoxy(x,y);
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++) cout<<char(219);
		gotoxy(x,y+i+1);
	}
}
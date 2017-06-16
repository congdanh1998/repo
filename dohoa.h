#if !defined(DO_HOA_H)
#include <string>
#define DO_HOA_H
using namespace std;
void resizeConsole(int width, int height);//ham thay doi kich thuoc cosole
void textcolor(int x);//ham to mau chu
void gotoxy(int x, int y);//dua con tro ve toa do (x y)
void hinhchunhat(unsigned char c, int x, int y, int a, int b);//ve hinh chua nhat rong bang cac ki tu c
void HCN2(int mau, int x, int y, int a, int b);//ve hinh chu nhat dac
void ngang(int x, int y, int len);//ke duong thang ngang bat dau tu toa do (x,y) dai len
void doc(int x, int y, int len);//ke duong thang doc bat dau tu toa do (x,y) dai len
void inbang(string a, string b, string c);//in bang voi cac ten cot la a,b,c
void ToMau(int x, int y, char *a, int color, int oldcolor = 7); // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void ToMau(int x, int y, string a, int color, int oldcolor);
#endif

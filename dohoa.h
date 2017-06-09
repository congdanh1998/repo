#if !defined(DO_HOA_H)
#include <string>
#define DO_HOA_H
using namespace std;
void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
void hinhchunhat(char c, int x, int y, int a, int b);
void HCN2(int mau, int x, int y, int a, int b);
void ngang(int x, int y, int len);
void doc(int x, int y, int len);
void inbang(string a, string b, string c);
void ToMau(int x, int y, char *a, int color, int oldcolor = 7); // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void ToMau(int x, int y, string a, int color, int oldcolor);
#endif

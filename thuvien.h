#include <string>
#define THU_VIEN_H
<<<<<<< HEAD
#define RONG 204
=======
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e
using namespace std;
typedef struct {
	short ngay, thang, nam;
} date;
typedef struct {
	int id;
	string tendangnhap;
	string matkhau;
} S_account;
typedef struct {
	int id;
	string hovaten;
	date ngaysinh;
	string mssv;
	string email;
	bool gioitinh;
	string vaitro;
} S_user;
void dangnhap();
void in();
void indangki();
void dangki();
void manhinhthongbao(string s);
void manhinhlamviec();
void xulichuoi(string &s, char a, int &x, int y, int maxlen = 29);
<<<<<<< HEAD
int get_F_N(string File);//dem so dong cua 1 file
#endif
=======
#endif
>>>>>>> f40226975e51e165769440aca02a3ef3c3a2e22e

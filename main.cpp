#include <iostream>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <string>
#include "dohoa.h"
#include "thuvien.h"
//luu dohoa.h o dau thi chi duong dan toi do
using namespace std;


int main()
{
	
	in();
	int thoat=1,cv=1;
	while (thoat){
		
		textcolor(9);
		hinhchunhat(178,18,cv*7+9,29,4);
	//dieu khien
			char c=_getch();
			int cv1=cv;
			if (c=='H'){cv--;}
			if (c=='P'){cv++;}
			if (cv==0) {cv=3;}
			if (cv==4) {cv=1;}
			if ((cv==3)&&(c==13)) {thoat=0;}
			if ((cv==1)&&(c==13)) {dangnhap();in();}
			if ((cv==2)&&(c==13)){dangki();in();}
			if (c==27){thoat=0;}
	
			textcolor(102);
			hinhchunhat(32,18,cv1*7+9,29,4);
	}
	return(0);
}

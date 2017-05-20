#include <iostream>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include "dohoa.h"
#include "thuvien.h"
//luu dohoa.h o dau thi chi duong dan toi do
using namespace std;
//ham xu li trong man hinh dang nhap
void dangnhap(){
	system("cls");
	cout<<"EsC de thoat khoi cua so";
	textcolor(6);
	hinhchunhat(178,5,1,60,25);
	hinhchunhat(219,6,2,58,23);
	HCN2(7,15,6,40,4);
	HCN2(7,15,11,40,4);
	//in dong de viet
	HCN2(15,20,8,30,1);
	HCN2(15,20,13,30,1);
	gotoxy(28,7);
	textcolor(7*16+14);
	cout<<"TEN DANG NHAP:";

	gotoxy(28,12);
	cout<<"  MAT KHAU:   ";

	gotoxy(10,22);
	cout<<" DANG NHAP ";

	gotoxy(50,22);
	cout<<" tro lai ";
	string TDN="",MK="",tst="meoden",tst0="kamehameha";//bien luu ten dang va mat khau
	int x=20,xo=20;//vi tri bat dau nhap ten va mat khau(hoang do)
	int thoat=1,cv=1;
	while (thoat){
		//in ra mui ten de cho nguoi dung biet vi tri dang duoc chon
		textcolor(14);//mau khung chon
		if(cv<3){
			hinhchunhat(219,14,cv*5,40,5);//\20 va \21 la hai dau mui ten trong bang ma ASCII
		}else if(cv==3){
			hinhchunhat(219,9,21,11,2);
		}else{
			hinhchunhat(219,49,21,9,2);
		}
	//xu li khi nhan phim tren bang phim
			char c=_getch();
			int cv1=cv;
			if (c=='H'||c=='K'){cv--;}
			if (c=='P'||c=='M'){cv++;}
			if (cv==0) {cv=4;}
			if (cv==5) {cv=1;}
			if ((cv==4)&&(c==13)) {thoat=0;}//thoat khi chon muc 4
			if (c==27){thoat=0;}//thoat khi go phim Esc
			//xu li nhap chuoi khi chon muc TEN DANG NHAP
			if ((cv==1) &&(c==13)){
				xulichuoi(TDN,'y',x,8);
			}
			//xu li nhap chuoi khi chon MAT KHAU(gan tuong tu nhu nhap TDN)
				if ((cv==2) &&(c==13)){
				xulichuoi(MK,'n',xo,13);
			}
				//xu li kiem tra xem ten dang nhap va mat khau da dung chua
			if ((cv==3) &&(c==13)){
				if((TDN==tst) && (MK==tst0)){
					gotoxy(0,40);
					cout<<"DA DANG NHAP, NHUNG Ko CON CHUC NANG J KHAC NUA";
					getch();
					thoat=0;
				}else{
					gotoxy(0,40);
					cout<<"DANG NHAP LAI";
				     }
				}
		//xoa cac mui ten o truoc khi chuyen sang muc khac
		textcolor(7);
		if(cv1<3){
			hinhchunhat(32,14,cv1*5,40,5);
			cout<<"   ";
		}else if(cv1==3){
			hinhchunhat(32,9,21,11,2);
		}else{
			hinhchunhat(32,49,21,9,2);
		}
	}
}
//ham in ra man hinh chinh
void in(){
	textcolor(255);
	system("cls");
	//char a=219;
	cout<<"nhan Enter de chon,EsC de thoat khoi cua so"<<endl;
	textcolor(254);
	cout<<"      (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)       (_)(_)        "<<endl	
        <<"      (_)        (_)  (_)     (_)   (_)     (_)  (_)     (_)  (_)      (_)     "<<endl
		<<"      (_)        (_)  (_)(_)(_)     (_)(_)(_)    (_)(_)(_)    (_)      (_)     "<<endl
	    <<"      (_)        (_)  (_)     (_)   (_)          (_)   (_)    (_)      (_)     "<<endl
	    <<"      (_)(_)(_)  (_)  (_)(_)(_)     (_)          (_)     (_)     (_)(_)        "<<endl;

	//ve khung
	textcolor(11);
	hinhchunhat(178,12,11,40,30);//tao hinh chu nhat tu ki tu co ma ASCII 178(bat dau o toa do (10,10) canh 40x30)
	hinhchunhat(219,13,12,38,28);//tao hinh chu nhat tu ki tu co ma ASCII 219
	HCN2(6,14,13,38,27);
	HCN2(7,19,17,29,3);
	HCN2(7,19,24,29,3);
	HCN2(7,19,31,29,3);
	//textcolor(14);
	//hinhchunhat(178,18,16,29,4);
	//hinhchunhat(178,18,23,29,4);
	//hinhchunhat(178,18,30,29,4);
	textcolor(121);
	//in noi dung
	gotoxy(28,18);
	cout<<"DANG NHAP";

	gotoxy(28,25);
	cout<<" DANG KI ";

	gotoxy(28,32);
	cout<<" TRO LAI ";

};
//ham xulichuoi chuoi tra ve la s,a='y' khi nhan ten va con lai khi nhan mat khau
//x,y la toa do bat dau doc du lieu tu ban phim
void xulichuoi(string &s,char a,int &x,int y,int maxlen){
	char ch;
	int M=x+maxlen-s.length(),m=x+1-s.length();	//chuoi chi co 30 ki tu la dai nhat
	textcolor(15*16);
	gotoxy(x,y);
	do{
	ch=_getch();
	//xu li khi nhan Backspace
	if (ch==8 && x>=m){
		gotoxy(x-1,y);
		cout<<" ";
		gotoxy(x-1,y);
		x--;
		s.erase(s.length()-1,1);
	}else if((ch!=13)&&(ch!=9)&&(ch!=11)&&(ch>=32)&&(ch<=126)&&(x<=M)){
		//chi lay ma ASCII tu 32-126 va khi chuoi nho hon 30 ki tu
		if(a=='y'){
			cout<<ch;
		}else{
			cout<<"*";
		};
		s=s+ch;
		x++;
		gotoxy(x,y);
	}
	}while((ch!=13)&&(ch!=9)&&(ch!=11));
}
void indangki(){
	textcolor(255);
	system("cls");
	cout<<"EsC de thoat khoi cua so";
	textcolor(6);
	hinhchunhat(178,5,1,60,57);
	hinhchunhat(219,6,2,58,55);
	HCN2(3,7,3,58,54);
	
	
	gotoxy(15,7);
	textcolor(62);
	cout<<"HO VA TEN :";
	ToMau(15,8,"                              ",255,62);
	gotoxy(15,14);
	cout<<"NGAY THANG NAM SINH:   ";
	gotoxy(15,15);
	cout<<"ngay:          thang:          nam:          ";
	ToMau(22,15,"    ",255,62);ToMau(37,15,"    ",255,62);ToMau(51,15,"    ",255,62);
	gotoxy(15,21);
	cout<<"Email: ";
	ToMau(15,22,"                              ",255,62);
	gotoxy(15,28);
	cout<<"so dien thoai: ";
	ToMau(15,29,"                    ",255,62);

	gotoxy(45,28);
	cout<<"gioi tinh: ";
	gotoxy(45,29);
	cout<<"Nam:          nu:";
	ToMau(50,29," ",255,14);ToMau(63,29," ",255,62);
	gotoxy(10,31);
	cout<<"*THONG TIN TEN NGUOI DUNG VA MAT KHAU";
	
	HCN2(7,10,34,40,4);
	textcolor(7*16+14);
	gotoxy(15,35);cout<<"Ten Dang Nhap:";
	HCN2(7,10,41,40,4);
	ToMau(15,36,"                              ",255,7*16+14);
	gotoxy(15,42);cout<<"Mat Khau:";
	HCN2(7,10,48,40,4);
	ToMau(15,43,"                              ",255,7*16+14);
	gotoxy(15,49);cout<<"Xac Nhan Lai Mat Khau:";
	ToMau(15,50,"                              ",255,7);
	ToMau(12,55," GUI DANG KI ",126,7);
	ToMau(40,55," TRO LAI ",126,7);
}
void nhapngay(int&x,int&y,int&z,short&a,short&b,short&d){
	string ng,th,n;
	int X[3]={21,36,50};
	int thoat=1,cv=1;
	while (thoat){
		textcolor(59);
		gotoxy(X[cv-1],15) ;cout<<"\20";gotoxy(X[cv-1]+5,15) ;cout<<"\21";
		char c=_getch();
		int cv1=cv;
		if (c=='H'||c=='K'){cv--;}
		if (c=='P'||c=='M'){cv++;}
		if (cv==0) {cv=3;}
		if (cv==4) {cv=1;}
		if ((cv==3)&&(c==13)) {xulichuoi(n,'y',z,15,3-z+51);stringstream(n)>>d;}
		if ((cv==1)&&(c==13)) {xulichuoi(ng,'y',x,15,1-x+22);stringstream(ng)>>a;}
		if ((cv==2)&&(c==13)) {xulichuoi(th,'y',y,15,1-y+37);stringstream(th)>>b;}
		if (c==27){thoat=0;}
		gotoxy(X[cv1-1],15) ;cout<<" ";gotoxy(X[cv1-1]+5,15) ;cout<<" ";
	}
};
void GT(bool &X){
	int thoat=1,cv=1;
	int x[2]={49,62};
	while (thoat){
		textcolor(59);
		gotoxy(x[cv-1],29) ;cout<<"\20";gotoxy(x[cv-1]+2,29) ;cout<<"\21";
		char c=_getch();
		int cv1=cv;
		if (c=='H'||c=='K'){cv--;}
		if (c=='P'||c=='M'){cv++;}
		if (cv==0) {cv=2;}
		if (cv==3) {cv=1;}
		if ((cv==1)&&(c==13)) {ToMau(50,29,"x",240);ToMau(63,29," ",240,59);X=true;}
		if ((cv==2)&&(c==13)) {ToMau(50,29," ",240);ToMau(63,29,"x",240,59);X=false;}
		if (c==27){thoat=0;}
		gotoxy(x[cv1-1],29) ;cout<<" ";gotoxy(x[cv1-1]+2,29) ;cout<<" ";
	}
};
void dangki(){
	user A={"","","","",{0,0,0},"",true};//khoi tao 1 user moi
	string xnmk="";//bien luu mat khau xac nhan xem co trung voi mat khau da nhap hay ko
	int x1=15,x2=15,x3=15,x4=15,x5=22,x6=37,x7=51,x8=15,x9=15;//hoang do nhap chuoi thong tin cua cac du lieu
	indangki();
	int thoat=1,cv=1;//thoat khoi man hinh DANGKI khi thoat=0 | cv dung de dieu khien chuong trinh
	while(thoat){
		textcolor(59);
		//dong lenh dieu chinh vi tri phu hop cho con tro
		if (cv<5) {gotoxy(12,cv*7);cout<<"\20\20";}
		else if (cv==5){gotoxy(42,28);cout<<"\20\20"; }
		else if (cv<=8){hinhchunhat(219,9,cv*7-9,40,5);}
		else if (cv==9){hinhchunhat(219,11,54,13,2);}
		else {hinhchunhat(219,39,54,9,2);}
		//dieu kieu di chuyen
		char c=_getch();
		int cv1=cv;
		if (c=='H'||c=='K'){cv--;}
		if (c=='P'||c=='M'){cv++;}
		if (cv==0){cv=10;}
		if (cv==11){cv=1;}
		//thuc hien cong viec ung voi cv= va khi nhan Enter
		if ((cv==1) && (c==13)){xulichuoi(A.hovaten,'y',x3,8);}//nhap ten
		if ((cv==2) && (c==13)){nhapngay(x5,x6,x7,A.ngaysinh.ngay,A.ngaysinh.thang,A.ngaysinh.nam);}//nhap ngay than nam sinh
		if ((cv==5) && (c==13)){GT(A.giotinh);}//nhap gioi tinh
		if ((cv==3) && (c==13)){xulichuoi(A.email,'y',x4,22);}//nhap email lien lac
		if ((cv==4) && (c==13)){xulichuoi(A.sodienthoai,'y',x8,29,19);}//nhap so dien thoai
		if ((cv==6) && (c==13)){xulichuoi(A.Tendangnhap,'y',x1,36);}//nhap ten dang nhap
		if ((cv==7) && (c==13)){xulichuoi(A.matkhau,'n',x2,43);}//nhap mat khau
		if ((cv==8) && (c==13)){xulichuoi(xnmk,'n',x9,50);}//nhap mat khau xac nhan
		if ((cv==9) && (c==13)){//in ra file luu nguoi dung
			ofstream outfile;
			outfile.open("user.dat",ios::app|ios::binary);
			outfile.write(reinterpret_cast<char*>(&A), sizeof(user));//ma hoa thanh nhi phan ma ko bit co tac dung ko(chua thanh thao) co khi cu xai o duoi truoc
			/*outfile<<A.giotinh<<endl
			<<A.email<<endl
			<<A.hovaten<<endl
			<<A.matkhau<<endl
			<<A.ngaysinh.ngay<<"  "<<A.ngaysinh.thang<<"  "<<A.ngaysinh.nam<<endl
			<<A.sodienthoai<<endl
			<<A.Tendangnhap<<endl;*/
			outfile.close();
			thoat=0;}
		if (((cv==10) && (c==13))||(c==27)){thoat=0;}//thoat ra man hinh chinh
		textcolor(48);
		//xoa vi tri con tro truoc khi chuyen sang cho khac
		if (cv1<5) {gotoxy(12,cv1*7);cout<<"  ";}
		else if (cv1==5){gotoxy(42,28);cout<<"  "; }
		else if (cv1<=8){hinhchunhat(32,9,cv1*7-9,40,5);}
		else if (cv1==9){hinhchunhat(32,11,54,13,2);}
		else {hinhchunhat(32,39,54,9,2);}
	}
	
};




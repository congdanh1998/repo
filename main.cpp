#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#define MAXL 20000
using namespace std;

struct diem{double x,t;};
int timtrang(string s){
	int m=s.length(),i=m;
	while (s[i]!=' ') {i--;};
	return i;
};

int main() {
	
	string data;
	int lap,k;
	float anpha,a,b;
	struct diem DT[MAXL];
	getline(cin,data);
	getline(cin,data);
	getline(cin,data);
	getline(cin,data);
	stringstream(data.substr(timtrang(data),data.length()))>>lap;
	getline(cin,data);
	stringstream(data.substr(timtrang(data),data.length()))>>anpha;
	getline(cin,data);
	stringstream(data.substr(timtrang(data),data.length()))>>a;
	getline(cin,data);
	stringstream(data.substr(timtrang(data),data.length()))>>b;
	getline(cin,data);
	stringstream(data.substr(timtrang(data),data.length()))>>k;
	getline(cin,data);
	getline(cin,data);
	getline(cin,data);
	int m=0;
	stringstream dt;
	do{
		getline(cin,data);
		if (data.empty()){continue;}
		dt<<data;
		dt>>DT[m].x;
		dt>>DT[m].t;
		//cin>>DT[m].x>>DT[m].t;
		m++;
		dt.clear();
	}while (!cin.eof());
	
	/*cout<<"_________________________________________________________________________________"<<endl
		<<"Output of the validation"<<endl
		<<"_________________________________________________________________________________"<<endl;*/
	
	int N=m/k,S,E;
	for(int i=1;i<=k;i++){
		if (i<k){
			S=(i-1)*N;E=i*N-1;
		} else{
			S=(i-1)*N;E=m-1;
		}
	
		double a1=a,b1=b;
		double ga,gb;
		
		for(int j=0;j<lap;j++){
			ga=0;gb=0;
			for(int l = 0;l<m;l++){
				if (l<S || l>E){
					ga=ga+(a1*DT[l].x+b1-DT[l].t)*DT[l].x;
					gb=gb+(a1*DT[l].x+b1-DT[l].t);
				}
			}
			
			a1=a1-anpha*ga/sqrt(ga*ga+gb*gb);
			b1=b1-anpha*gb/sqrt(ga*ga+gb*gb);
			
		}
		cout<<setw(10)<<fixed<<setprecision(5)<<right<<a1
			<<setw(10)<<fixed<<setprecision(5)<<right<<b1;
	
		double Ermsd=0,Etb=0;
		double e[MAXL];
		
		for (int j=S;j<=E;j++){
			e[j]=(a1*DT[j].x+b1-DT[j].t);
		}
		
		for (int j=S;j<=E;j++){
			
				Ermsd+=e[j]*e[j];
				Etb+=e[j];
		}
		Etb=Etb/double(E-S+1);
		Ermsd=sqrt(Ermsd/double(E-S+1));
		cout<<setw(10)<<fixed<<setprecision(5)<<right<<Ermsd;
		
		double Sigma=0;
		for (int j=S;j<=E;j++){
			Sigma+=(e[j]-Etb)*(e[j]-Etb);
		}
		Sigma=sqrt(Sigma/double(E-S+1));
		double Vmin=Etb-3*Sigma,Vmax=Etb+3*Sigma;
		int Bd[10]={0,0,0,0,0,0,0,0,0,0};
		double V=6*Sigma/10;
		
		for (int j=S;j<=E;j++){
			
				if(e[j]>=Vmin && e[j]<=Vmax){
					if (e[j]>=Vmin && e[j]<Vmin+V){Bd[0]+=1;}
					else if (e[j]<Vmin+2*V){Bd[1]+=1;}
					else if (e[j]<Vmin+3*V){Bd[2]+=1;}
					else if (e[j]<Vmin+4*V){Bd[3]+=1;}
					else if (e[j]<Vmin+5*V){Bd[4]+=1;}
					else if (e[j]<Vmin+6*V){Bd[5]+=1;}
					else if (e[j]<Vmin+7*V){Bd[6]+=1;}
					else if (e[j]<Vmin+8*V){Bd[7]+=1;}
					else if (e[j]<Vmin+9*V){Bd[8]+=1;}
					else if (e[j]<=Vmax){Bd[9]+=1;}
				
			}
		}
		int tong=0;
		for(int j=0;j<10;j++) tong+=Bd[j];
		
		for(int j=0;j<10;j++) cout<<setw(10)<<fixed<<setprecision(5)<<right<<(double)Bd[j]/tong ;
		cout<<endl;

	}
	return 0;
}


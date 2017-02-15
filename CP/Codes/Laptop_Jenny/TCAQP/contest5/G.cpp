#include<bits/stdc++.h>

using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)

int N1,N2,N3,N4;
string S1,S2,S3,S4;

int getsum(int x){
	int r=0;
	if(S4==""){
		r=max(r,N1);
		r=max(r,N2);
		r=max(r,N3);
		if(S1==S2)
			r=max(r,N1+N2+20);
		if(S1==S3)
			r=max(r,N1+N3+20);
		if(S3==S2)
			r=max(r,N3+N2+20);
		return r;
	}
	
	if(S4==S1&&N4==N1)return 0;
	if(S4==S2&&N4==N2)return 0;
	if(S4==S3&&N4==N3)return 0;
	
	if(x==0){
		r=max(r,N4);
		r=max(r,N2);
		r=max(r,N3);
		if(S4==S2)
			r=max(r,N4+N2+20);
		if(S4==S3)
			r=max(r,N4+N3+20);
		if(S3==S2)
			r=max(r,N3+N2+20);
		return r;
	}
	if(x==1){
		r=max(r,N1);
		r=max(r,N4);
		r=max(r,N3);
		if(S1==S4)
			r=max(r,N1+N4+20);
		if(S1==S3)
			r=max(r,N1+N3+20);
		if(S3==S4)
			r=max(r,N3+N4+20);
		return r;
	}
	if(x==2){
		r=max(r,N1);
		r=max(r,N2);
		r=max(r,N4);
		if(S1==S2)
			r=max(r,N1+N2+20);
		if(S1==S4)
			r=max(r,N1+N4+20);
		if(S4==S2)
			r=max(r,N4+N2+20);
		return r;
	}
}

int main(){
	while(scanf("%d",&N1)&&N1!=-1){
		int maxi=0;
		cin>>S1>>N2>>S2>>N3>>S3;
		if(N1>7)N1=0;
		if(N2>7)N2=0;
		if(N3>7)N3=0;
		S4="";
		int act=getsum(0);
		
		FOR(x,0,3){
			FOR(i,0,4){
				FOR(j,1,11){
					if(i==0)S4="espada";
					if(i==1)S4="basto";
					if(i==2)S4="oro";
					if(i==3)S4="copa";
					N4=j;
					if(j>7)N4=0;
					
					maxi=max(maxi,getsum(x));
					
				}
			}
		}
		cout<<maxi-act<<endl;
	}
}

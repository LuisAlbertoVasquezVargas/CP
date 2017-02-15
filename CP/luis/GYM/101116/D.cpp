#include<bits/stdc++.h>
using namespace std;
int T, k, w, l;
int rk[35][5];
int main(){
	int inc=1;
	int lstinc=1;
	rk[0][0]=2;
	rk[0][1]=2;
	for(int i=1;i<=30;i++){
		rk[i][0] = rk[i-1][1]+lstinc;
		rk[i][1] = rk[i][0]+inc;
		lstinc=inc;
		inc*=2; 
	} 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&k);
		scanf("%d",&w);
		scanf("%d",&l);
		if(k==0) printf("%d\n",1);
		else if(k==1){
			if(w+l==2) printf("%d\n",1);
			else printf("%d\n",2);
		} else if(k+1==w) printf("%d\n",1);
		else if(w==0){
			k--;
			int i=1;
			while(l>0){
				l--;
				i++;
				if(i%2==1) k--;
			}
			if(k==-1) printf("%d\n",1);
			else printf("%d\n",rk[k][i]);
		} else {
			while(w>0){
				k--;
				w--;
			}
			int i=0;
			while(l>0) { 
				l--;
				i++;
				if(i%2==1) k--;	
			}	
			if(k==-1) printf("%d\n",1);
			else printf("%d\n",rk[k][i]);
		}
	}
}

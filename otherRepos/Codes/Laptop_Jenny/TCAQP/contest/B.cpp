#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

#define MAXN 1000010

int p[MAXN+5],D[MAXN];

void sieve(){
	for(int i=2;i*i<=MAXN;i++){
		if(!p[i])
			for(int j=i*i;j<=MAXN;j+=i)
				p[j]=i;
	}
}

int fact[MAXN],F;

void primefact(int x){
	F=0;
	while(p[x]>0){
		fact[F++]=p[x];
		x/=p[x];
	}
	fact[F++]=x;
}

void getdiv(int cur,int s,int e){
	
	if(s==e)D[cur]++;	
	else{
		int m;
		for(m =s+1;m<e&&fact[m]==fact[s];m++);
		for(int i=s;i<=m;i++){
			getdiv(cur,m,e);
			cur*=fact[s];
		}
	}
}

int n,x;

int main(){
	sieve();
	while(scanf("%d",&n)==1){
		memset(D,0,sizeof(D));
		for(int i=0;i<n;i++){
			
			scanf("%d",&x);
			
			primefact(x);
			sort(fact,fact+F);
			
			getdiv(1,0,F);
			
		}
		for(int i=1000000;i>=0;i--){
			if(D[i]>=2){printf("%d\n",i);break;}
		}
	}
}

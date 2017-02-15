#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 100
#define INF 1000000000
#define ll long long
using namespace std;

ll memo[N+2][N+2][N+2];
int A[N+2];
int n,m,tc=1;

ll f(int pos, int last ,int ct){
	if(ct>m)return INF;
	if(pos==n){
		if(ct==m)return 0;
		return INF;
	}
	ll &ret=memo[pos][last][ct];
	if(ret!=-1)return ret;
	ret=2*INF;
	if(pos==n-1){
		ret=min(ret, A[pos]-A[last]+ f(pos+1,pos+1,ct+1));
	}
	else{
		//cojo
		ret=min( ret, A[pos]-A[last]+ f(pos+1,pos+1, ct+1)  );
		//sigo
		ret=min( ret, f(pos+1,last ,ct) );
	}
	//cout<<pos<<" "<<last<<" "<<ct<<" "<<ret<<endl;
	return ret;
}



int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);	
		for(int i=0;i<n;++i){
			scanf("%d",&A[i]);
		}
		sort(A,A+n);
		memset(memo,-1,sizeof(memo));
		printf("Case #%d: %lld\n",tc++,f(0,0,0) );
	}
}

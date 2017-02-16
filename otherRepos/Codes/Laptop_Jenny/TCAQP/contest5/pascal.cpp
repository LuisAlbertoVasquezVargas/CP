#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#define pb push_back
#define N 36
#define ll long long
#define INF 1000000000
#define pb push_back
using namespace std;

ll C[N+5][N+5];
vector<ll>adj[N+5];

int main(){
	int maxFila;
	ll k;
	for(int i=0;i<=N;++i){
		C[i][0]=1,C[i][i]=1;
	}
	bool first=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<i;++j){
				C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(!first && C[i][j]>=INF){
				maxFila=i, first=1;
			}
		}
	}
	//fila 0 ->unos	
	//fila 1 ->del 1 al n
	for(int i=1;i<=100000;++i){
		adj[1].pb(i);
	}
	for(int j=2;j<=N;++j){
		adj[j].pb(1);
		for(int i=1;i<adj[j-1].size();++i){
			ll val=adj[j][i-1]+adj[j-1][i];
			if(val<=INF)adj[j].pb(val);
			else break;
		}
	}
	while(scanf("%lld",&k)==1){
		if(k==-1)break;
		bool first=0;
		for(int i=0;i<=N;++i){
			for(int j=0;j<=N;++j){
				if(!first && C[i][j]>=k){
					maxFila=i, first=1;
				}
			}
		}
		ll res=0LL;
		for(int i=1;i<=maxFila/2;++i){
			if(i==1){
				res+=(k-1);
			}
			else{
				int val=upper_bound(adj[i].begin(), adj[i].end(),k)-adj[i].begin();
				res+=(val-1);
			}
		}
		res*=2;
		ll aux=maxFila/2;
		res-=(aux*aux);
		if(maxFila & 1 ){	
		}
		else{
			if(C[maxFila][maxFila/2]>k)res++;
		}
		cout<<res<<endl;
	}
}

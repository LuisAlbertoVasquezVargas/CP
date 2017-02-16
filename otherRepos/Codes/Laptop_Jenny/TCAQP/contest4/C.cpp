#include<bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i=x;i<y;i++)
#define MAXN 224
	

vector<pair<int,pair<int,int> > >E;
vector<int>PW;
int P;
int caso=0;
int N,M,K,a,b,c,T;
int PP[MAXN];

int F(int x){return (x==PP[x])?x:PP[x]=F(PP[x]);}
void U(int x,int y){PP[F(x)]=F(y);}

bool check(int nodo){
	FOR(i,0,PW.size()){
		if(F(PW[i])==F(nodo))return 1;
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&M,&K);
		FOR(i,1,N+5)PP[i]=i;
		E.clear();
		PW.clear();
		FOR(i,0,K)
			scanf("%d",&P),PW.push_back(P);
		FOR(i,0,M){
			scanf("%d%d%d",&a,&b,&c);
			E.push_back(make_pair(c,make_pair(a,b)));
		}
		long long ans=0;
		sort(E.begin(),E.end());
		for(int i=0;i<E.size();i++){
			if(F(E[i].second.first)==F(E[i].second.second))continue;
			if(!check(E[i].second.first)||!check(E[i].second.second)){
				U(E[i].second.first,E[i].second.second);
				ans+=E[i].first;
			}
		}
		printf("Case #%d: %lld\n",++caso,ans);
	}
}

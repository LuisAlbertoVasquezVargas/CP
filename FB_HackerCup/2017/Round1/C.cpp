#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int MAXN=100;
const int INF=(int)1e9;
int G[MAXN][MAXN];
void init(int n){
	REP(i,n)REP(j,n)G[i][j]=(i==j?0:INF);
}
void add(int u,int v,int w){
	w=min(w,G[u][v]);
	G[u][v]=G[v][u]=w;
}
void floyd(int n){
	REP(k,n)REP(i,n)REP(j,n)G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}
const int MAXK=5000;
int S[MAXK],D[MAXK];

ll memo[MAXK][3][MAXN];
bool used[MAXK][3][MAXN];
int K;
ll dp(int pos,int state,int city){
	if(pos==K)return 0;
	if(used[pos][state][city])return memo[pos][state][city];
	used[pos][state][city]=1;
	ll &ans=memo[pos][state][city]=LLONG_MAX/2;
	if(state==0){
		ans=min(ans,(ll)G[city][S[pos]]+dp(pos,1,S[pos]));
	}else if(state==1){
		ans=min(ans,(ll)G[city][D[pos]]+dp(pos+1,0,D[pos]));
		if(pos+1<K)
			ans=min(ans,(ll)G[city][S[pos+1]]+dp(pos,2,S[pos+1]));
	}else{
		ans=min(ans,(ll)G[city][D[pos]]+dp(pos+1,1,D[pos]));
	}
	return ans;
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n,m;
		scanf("%d%d%d",&n,&m,&K);
		init(n);
		REP(i,m){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			add(u,v,w);
		}
		floyd(n);
		REP(i,K)scanf("%d%d",&S[i],&D[i]),S[i]--,D[i]--;
		clr(used,0);
		ll ans=dp(0,0,0);
		if(ans>=INF)ans=-1;
		printf("Case #%d: %d\n",tc+1,(int)ans);
	}
}



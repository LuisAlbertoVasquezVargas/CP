#include<bits/stdc++.h>
using namespace std;

#define clr(T,val) memset(T,val,sizeof(T))
#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< vector<string> > vvs;
typedef long long ll;

const ll INF = (ll)1e14;
const int N = 5000;
vi G[N + 5];
vi C[N + 5];

void add(int u , int v , int w){
	G[u].pb(v);
	C[u].pb(w);
}
void clear(int n){
	REP(i , n) G[i].clear(),C[i].clear();
}
bool used[N + 5][N + 5];
ll memo[N + 5][N + 5];
int n;
ll dp(int u , int jumps){
	if(jumps == 0) return (u == n - 1) ? 0 : INF;
	if(used[u][jumps]) return memo[u][jumps];
	used[u][jumps] = 1;
	ll &ans = memo[u][jumps] = INF;
	REP(i , SZ(G[u])){
		int v = G[u][i];
		int w = C[u][i];
		ans = min(ans,w + dp(v,jumps - 1));
	}
	return ans;
}
vi path;
void rec(int u , int jumps){
	path.pb(u);
	if(jumps == 0) return;
	
	REP(i , SZ(G[u])){
		int v = G[u][i];
		int w = C[u][i];
		if(dp(u,jumps) == w + dp(v,jumps - 1)){
			rec(v,jumps-1);
			return;
		}
	}
}
void impr(vi &v){
	printf("%d\n" , SZ(v));
	REP(i , SZ(v)) printf("%d%c" , ++v[i], (i + 1 == SZ(v) ? 10 : 32));
}
int main(){
	int m , Time;
	while(scanf("%d%d%d" , &n,&m,&Time) == 3){
		clear(n);
		REP(i , m){
			int u , v , w;
			scanf("%d%d%d" , &u,&v,&w);
			u--,v--;
			add(u,v,w);
		}
		clr(used,0);
		int bestJumps = -1;
		for(int jumps = 1 ; jumps < n; ++ jumps){
			if(dp(0,jumps) <= Time){
				bestJumps = jumps;
			}
		}
		assert(bestJumps != -1);
		path.clear();
		rec(0,bestJumps);
		assert(SZ(path) == bestJumps + 1);
		impr(path);
	}
}



#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define pb push_back
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;

const int INF = 1e9;
const int N = 1e7;
vi G[N + 5];
vi bfs(int s,int n){
	vi dist(n,INF);
	queue<int>Q;
	dist[s]=0;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(auto v:G[u]){
			if(dist[v] >= INF){
				dist[v]=dist[u]+1;
				Q.push(v);
			}
		}
	}
	return dist;
}
void add(int u,int v){
	G[u].pb(v);
}
void initGraph(int n){
	REP(i,n) G[i].clear();
}
int f(int x){
	if(x == 0) return 0;
	return 31 - __builtin_clz(x) + __builtin_popcount(x);
}
int main(){
	int n=100;
	cin >> n;
	initGraph(n);
	REP(i,n){
		int mult=2*i;
		int sum=i+1;
		if(mult<n)add(i,mult);
		if(sum<n)add(i,sum);
	}
	vi d=bfs(0,n);
	//REP(i,n)cout<<i<<" "<<d[i]<<" " <<f(i)<<endl;
	REP(i,n){
		//cout<<i<<" "<<d[i]<<" " <<f(i)<<endl;
		assert(d[i] == f(i));
	}
}



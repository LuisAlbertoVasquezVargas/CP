#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=50000;
vi G[MAX_N];
int indeg[MAX_N];
int activated[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear();
	REP(i,n)indeg[i]=0;
	REP(i,n)activated[i]=0;
}
int solve(int s,int n,int &ans){
	activated[s]=1;
	if(indeg[s]!=0)return ans;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		//DEBUG(u);
		ans--;
		for(auto v:G[u]){
			indeg[v]--;
			if(indeg[v]==0&&activated[v])
				Q.push(v);
		}
	}
	return ans;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		initGraph(n);
		REP(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].pb(v);
			indeg[v]++;
		}
		int ans=n;
		REP(i,n){
			int x;
			scanf("%d",&x);
			x--;
			printf("%d\n",n-solve(x,n,ans));
		}
	}
}



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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<ll> vll;

const int MAX_N=200000;
const ll INF=LLONG_MAX/2LL;
vi G[MAX_N];
int A[MAX_N];
ll T[MAX_N],DP[MAX_N],DP2[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear();
}
void add(int u,int v){
	G[u].pb(v);
	G[v].pb(u);
}
void dfs(int u,int p=-1){
	T[u]=A[u];
	DP[u]=-INF;
	DP2[u]=-INF;
	vll vec;
	for(auto v:G[u]){
		if(v==p)continue;
		dfs(v,u);
		T[u]+=T[v];
		DP[u]=max(DP[u],DP[v]);
		vec.pb(DP[v]);
	}
	DP[u]=max(DP[u],T[u]);
	if(SZ(vec)>=2){
		for(int i=0;i<2;++i)
			for(int j=i+1;j<SZ(vec);++j)
				if(vec[i]<vec[j])
					swap(vec[i],vec[j]);
		DP2[u]=vec[0]+vec[1];
	}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		initGraph(n);
		REP(i,n)scanf("%d",&A[i]);
		REP(i,n-1){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			add(u,v);
		}
		dfs(0);
		ll ans=*max_element(DP2,DP2+n);
		if(ans==-INF)puts("Impossible");
		else printf("%I64d\n",ans);
	}
}




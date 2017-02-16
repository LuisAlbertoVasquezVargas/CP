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
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef int ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MAX_N=50000;
const int MAX_K=500;
vi G[MAX_N];
bool used2[MAX_N+1][MAX_K+1];
int memo2[MAX_N+1][MAX_K+1];
int dp2(int u,int k,int p=-1){
	//DEBUG3(u,k,p);
	if(k==0)return 1;
	if(used2[u][k])return memo2[u][k];
	used2[u][k]=1;
	int &ans=memo2[u][k]=0;
	for(auto v:G[u]){
		if(v==p)continue;
		ans+=dp2(v,k-1,u);
	}
	return ans;
}
void initGraph(int n){
	REP(i,n)G[i].clear();
}
ll solve(int u,int K,int p=-1){
	ll ans=dp2(u,K,p);
	//DEBUG3(u,K,dp2(u,K));
	vvll T;
	for(auto v:G[u]){
		if(v==p)continue;
		vll vec;
		for(int L1=0;K-2-L1>=0;L1++)
			vec.pb(dp2(v,L1,u));
		T.pb(vec);
		ans+=solve(v,K,u);
	}
	int n=SZ(T),m=((n==0)?0:SZ(T[0]));
	vvll S(n+1,vll(m));
	REP(j,m)REP(i,n)
		S[i+1][j]=S[i][j]+T[i][j];
	REP(i,n)REP(L1,m){
		int L2=K-2-L1;
		ans+=(S[n][L2]-S[i+1][L2])*T[i][L1];
	}
	return ans;
}
int main(){
	int n,K;
	while(scanf("%d%d",&n,&K)==2){
		initGraph(n);
		REP(i,n-1){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		clr(used2,0);
		cout<<solve(0,K)<<'\n';
	}
}



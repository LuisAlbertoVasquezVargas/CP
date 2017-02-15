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
typedef long double ld;
typedef pair< int , int > pii;
typedef pair<ll,ll>pll;
typedef vector< int > vi;

const int MAX_N=(int)1e5;
int A[MAX_N];
vi G[MAX_N];
void initGraph(int n){
	REP(i,n)G[i].clear();
}
const ll INF=1e16;
ld realLCM(ll a,ll b){
	return (ld)a*((ld)b/(ld)__gcd(a,b));
}
ll LCM(ll a,ll b){
	if(realLCM(a,b)>=INF)return INF;
	return a*(b/__gcd(a,b));
}
pll solve(int u,int p=-1){
	ll lcm=1;
	int children=0;
	ll T=0;
	for(auto v:G[u]){
		if(v==p)continue;
		pll p=solve(v,u);
		T+=p.se;
		lcm=LCM(lcm,p.se);
		children++;
	}
	if(children==0)
		return {A[u],1};
	ll best=INT_MAX;
	for(auto v:G[u]){
		if(v==p)continue;
		pll p=solve(v,u);
		best=min(best,p.fi/lcm);
	}
	return {best*lcm*(ll)children,lcm};
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		REP(i,n)scanf("%d",&A[i]);
		initGraph(n);
		REP(i,n-1){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		ll ans=solve(0).fi;
		REP(i,n)ans-=A[i];
		//DEBUG2(ans.fi,ans.se);
		cout<<-ans<<'\n';
	}
}



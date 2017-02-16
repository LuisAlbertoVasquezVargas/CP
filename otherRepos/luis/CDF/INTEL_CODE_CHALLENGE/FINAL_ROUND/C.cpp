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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector<pii>vpii;
typedef vector<vpii>vvpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll INF=LLONG_MAX;
void gcdext( ll &g , ll &x , ll &y , ll a , ll b ){
	if( b == 0 )
		g = a , x = 1 , y = 0;
	else gcdext( g , y , x , b , a%b ) , y = y - ( a/b )*x;
}
ll solve(ll a,ll b, ll n, ll m,ll mcm){
	if(a==b) return a;
	ll g,X0,Y0;
	gcdext(g,X0,Y0,2*n,2*m);
	if((b-a)%g)return INF;
	ll factor=(b-a)/g;
	ll t=-X0*factor*g/(2*m);
	ll mini=INF,myT=-1;
	for(ll it=t-3;it<=t+3;++it){
		ll cur=2*n*(X0*factor+(2*m*it)/g)+a;
		if(cur>=0){
			if(cur<mini){
				mini=cur;
				myT=it;
			}
		}
	}
	t=myT;
	if(mini==INF)return INF;
	ll nx=2*n*(X0*factor+(2*m*t)/g)+a;
	if(nx>=0&&nx<=mcm)
		return nx;
	return INF;
}
ll mainSolve(ll a,ll b,ll n, ll m){
	ll ans=INF;
	ll mcm=(2*n*2*m)/__gcd(2*n,2*m);
	ans=min(ans,solve(a,b,n,m,mcm));
	ans=min(ans,solve(2*n-a,b,n,m,mcm));
	ans=min(ans,solve(a,2*m-b,n,m,mcm));
	ans=min(ans,solve(2*n-a,2*m-b,n,m,mcm));
	if(ans==INF)ans=-1;
	return ans;
}
int main(){
	int n,m,Q;
	while(scanf("%d%d%d",&n,&m,&Q)==3){
		REP(it,Q){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",mainSolve(x,y,n,m));
		}
	}
}



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
typedef vector<ll>vll;
typedef vector<vll>vvll;

void doit(int posX,ll &r,vvll &T,int m){
	if(!r)return;
	REP(j,m){
		if(r){
			T[posX][j]++;
			r--;
		}
	}
}
void solve(vvll &T,int x,int y){
	ll mini=LLONG_MAX;
	ll maxi=LLONG_MIN;
	for(auto v:T)
		for(auto x:v){
			mini=min(mini,x);
			maxi=max(maxi,x);
		}
	cout<<maxi<<" "<<mini<<" "<<T[x][y]<<'\n';
}
int main(){
	int n,m,x,y;
	ll K;
	while(cin>>n>>m>>K>>x>>y){
		x--,y--;
		if(n==1){
			ll Q=K/m;
			ll r=K%m;
			vvll T(n,vll(m,Q));
			REP(i,r)T[0][i]++;
			solve(T,x,y);
			continue;
		}
		ll Q=K/((2*n-2)*m);
		ll r=K%((2*n-2)*m);
		//DEBUG2(Q,r);
		vvll T(n,vll(m,2LL*Q));
		REP(j,m)T[0][j]=T[n-1][j]=Q;
		//test();
		REP(i,n)
			doit(i,r,T,m);
		
		for(int i=n-2;i>=1;i--)
			doit(i,r,T,m);
		solve(T,x,y);
	}
}



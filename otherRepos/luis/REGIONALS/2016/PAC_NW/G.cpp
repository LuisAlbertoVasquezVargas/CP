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

typedef long long ll;
typedef vector<ll>vll;
typedef pair<ll,ll>pll;
typedef vector<pll> vpll;
typedef pair< int , int > pii;
typedef vector<pii>vpii;
typedef vector< int > vi;

int LIS( vll &a ){
	vll b;
	for( auto x : a ){
		int j = upper_bound( all( b ) , x ) - b.begin();
		//int j = lower_bound( all( b ) , x ) - b.begin();
		// (lower) a < b < c 
		// (upper) a <= b <= c 
		if( j == SZ(b) ) b.pb( x );
		else b[ j ] = x;
	}
	return SZ(b);
}
int main(){
	int n,R,W,H;
	while(scanf("%d%d%d%d",&n,&R,&W,&H)==4){
		vpll v;
		REP(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			ll s=y+(ll)x*R;
			ll t=y-(ll)x*R;
			v.pb({s,t});
		}
		sort(all(v));
		vll vec;
		REP(i,SZ(v))vec.pb(v[i].se);
		printf("%d\n",LIS(vec));
	}
}



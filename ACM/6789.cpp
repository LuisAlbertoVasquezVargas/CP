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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
 
int X[ N + 5 ];
int n;
ll K;
ll f( int t ){
	ll ans = 0;
	REP( i , n ) ans += (upper_bound( X , X + n , X[ i ] + t ) - X) - 1 - i;
	return ans;
}
ll bsearch( int K ){
	int lo = 0 , hi = 1000000009;
	while( hi - lo > 1 ){
		int med = (lo + hi) >> 1;
		if( f( med ) < K ) lo = med;
		else hi = med;
	}
	return lo;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	while( cin >> n >> K ){
		if( !n && !K ) break;
		REP( i , n ) cin >> X[ i ];
		sort( X , X + n );
		ll t = bsearch( K );
		//DEBUG2( K , t );
		//DEBUG( f( t ) );
		K -= f( t );
		int a = -1 , b;
		while( 1 ){
			if( K == 0 ) break;
			a ++;
			int doit = 0;
			if( binary_search( X , X + n , X[ a ] + t + 1 ) ){
				b = lower_bound( X , X + n , X[ a ] + t + 1 ) - X;
				doit = 1;
			}
			if( doit ){
				K --;
			}
		}
		printf( "%d %d\n" , X[ a ] , X[ b ] );
	}
}




#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 17
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int n;
int rmq[ N + 1 ][ 1 << N ] , A[ 1 << N ];
int query( int lo , int hi ){
	int r = 31 - __builtin_clz( hi - lo + 1 );
	return min( rmq[ r ][ lo ] , rmq[ r ][ hi - (1<<r) + 1 ] );
}
void RMQ(){
	REP( i , n ) rmq[ 0 ][ i ] = A[ i ];
	for( int k = 1 ; k <= N ; ++k )
		for( int i = 0 ; i + ( 1 << k ) <= n ; i++ )
			rmq[ k ][ i ] = min( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
}
int main()
{
	int cases , Q , lo , hi ;
	sc( cases );
	REP( tc , cases ){
		printf( "Scenario #%d:\n" , tc + 1 );
		sc( n ) , sc( Q );
		REP( i , n ) sc( A[ i ] );
		RMQ();
		while( Q -- ){
			sc( lo ) , sc( hi );
			lo -- , hi --;
			printf( "%d\n" , query( lo , hi ) );
		}
	}
}



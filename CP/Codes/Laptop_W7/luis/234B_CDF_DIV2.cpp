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

#define N 1000
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

char M[ N + 5 ][ N + 5 ];
int n , m;
int main()
{
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) scanf( "%s" , M[ i ] );
		bool posible = 1;
		vi v;
		REP( i , n ){
			int G , S;
			REP( j , m ) if( M[ i ][ j ] == 'G' ) G = j;
			REP( j , m ) if( M[ i ][ j ] == 'S' ) S = j;
			if( G > S ) {
				posible = 0;
				break;
			}
			v.pb( S - G );
		}
		if( !posible ){
			puts( "-1" );
			continue;
		}
		sort( all( v ) );
		int sz = unique( all( v ) ) - v.begin();
		printf( "%d\n" , sz );
	}
}




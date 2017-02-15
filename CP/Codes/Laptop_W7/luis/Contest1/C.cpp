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

#define N 300005
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

char s[ N ];
int n;
int f(){
	vi cnt( 26 );
	REP( i , n ) cnt[ s[ i ] - 'a' ] = 1;
	return accumulate( all( cnt ) , 0 );
}
int DP[ 30 ][ N ];

int main()
{
	while( scanf( "%s" , s ) == 1 )
	{
		n = strlen( s );
		int ds = f();
		printf( "%d\n" , ds );
		REP( i , 26 ) DP[ i ][ n ] = -1;
		REP( i , 26 ) for( int j = n - 1 ; j >= 0 ; --j ) 
			if( s[ j ] == 'a' + i ) DP[ i ][ j ] = j;
			else DP[ i ][ j ] = DP[ i ][ j + 1 ];
		for( int kk = 1 ; kk <= ds ; ++kk ){
			ll ans = 0 ;
			for( int j = 0 ; j < n ; ++j ){
				int cnt = 0;
				vi v;
				for( int i = 0 ; i < 26 ; ++i )
					if( DP[ i ][ j ] != -1 ){
						v.pb( DP[ i ][ j ] );
						cnt ++;
					}
				if( cnt < kk )
					break;
				v.pb( n );
				sort( all( v ) );
				ans += v[ kk ] - v[ kk - 1 ];
			}
			cout << ans << '\n';
		}
	}
}




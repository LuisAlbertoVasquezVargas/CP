#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define SZ(v) ((int)(v).size())
#define all(v)  v.begin() , v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cerr << #x << " " << x << endl;

#define N 50
#define MOD 10003

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int comb( int n ){
	return (n * (n - 1))>>1;
}
int n , m;
bool used[ N + 5 ][ N + 5 ][ N + 5 ][ 2 * N + 5 ];
int memo[ N + 5 ][ N + 5 ][ N + 5 ][ 2 * N + 5 ];

int dp( int ct0 , int ct1 , int pos  , int cur ){
	//cout << ct0 << " " << ct1 << " " << pos << " " << cur << endl;
	if( pos == m ) return (cur == 0);
	if( used[ ct0 ][ ct1 ][ pos ][ cur ] ) return memo[ ct0 ][ ct1 ][ pos ][ cur ];
	used[ ct0 ][ ct1 ][ pos ][ cur ] = 1;
	int &dev = memo[ ct0 ][ ct1 ][ pos ][ cur ] = dp( ct0 , ct1 , pos + 1 , cur );
	if( cur && ct0 ) {
		dev += ct0 * dp( ct0 - 1 , ct1 + 1 , pos + 1 , cur - 1 );
		dev %= MOD;
	}
	
	if( cur && ct1 ) {
		dev += ct1 * dp( ct0 , ct1 - 1 , pos + 1 , cur - 1 );
		dev %= MOD;
	}
	if( cur - 2 >= 0 ){
		if( ct0 - 2 >= 0 ){
			dev += comb( ct0 ) * dp( ct0 - 2 , ct1 + 2 , pos + 1 , cur - 2 );
			dev %= MOD;
		}	
		if( ct0 && ct1 ){
			dev += ct0 * ct1 * dp( ct0 - 1 , ct1 , pos + 1 , cur - 2 );
			dev %= MOD;
		}
		if( ct1 - 2 >= 0 ){
			dev += comb( ct1 ) * dp( ct0 , ct1 - 2 , pos + 1 , cur - 2 );
			dev %= MOD;
		}
	}
	return dev;
}
int main(){
	freopen( "rooks.in" , "r" , stdin );
	freopen( "rooks.out" , "w" , stdout );
	int K;
	while( scanf( "%d%d%d" , &n , &m , &K ) == 3 ){
		if( K > 2 * n || K > 2 * m ){
			puts( "0" );
			continue;
		}
		clr( used , 0 );
		printf( "%d\n" , dp( n , 0 , 0 , K ) );
	}	
}


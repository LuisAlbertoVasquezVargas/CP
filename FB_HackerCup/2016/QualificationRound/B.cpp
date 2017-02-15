#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; ++i )

#define pb push_back
#define SZ( v ) ((int)(v).size())

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef long long ll;

bool valid( int x , int y , int n ){
	return x >= 0 && x < 2 && y >= 0 && y < n ;
}
int doit( vvi &v , vs s , int dx , int dy ){
	int n = SZ( s[ 0 ] ) , cur = 0 ;
	v = vvi( 2 , vi( n , -1 ) );
	vvi vis( 2 , vi( n ) );
	REP( i , 2 )REP( j , n ){
		if( s[ i ][ j ] == 'X' ) continue;
		if( vis[ i ][ j ] ) continue;
		for( int r = 0 ; ; ++r ){
			int ni = i + r * dx;
			int nj = j + r * dy;
			if( valid( ni , nj , n ) && s[ ni ][ nj ] == '.' ){
				v[ ni ][ nj ] = cur;
				vis[ ni ][ nj ] = 1;
			}else break;
		}
		cur ++;
	}
	return cur;
}
void impr( vvi &T ){
	for( auto v : T ){
		for( auto x : v ) cout << setw( 3 ) << x;
		cout << endl;
	}
}
const int N = 1000;
vi match , vis;
vvi G;
int n , m ;
void init(){
	G.clear();
	G.resize( n );
	match = vi( m , -1 );
	vis = vi( n , 0 );
}
bool dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	for( auto v : G[ u ] ){
		if( match[ v ] == -1 || dfs( match[ v ] ) ){
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}
int bpm(){
	int ans = 0;
	REP( u , n ){
		vis = vi( n );
		ans += dfs( u );
	}
	return ans;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int len;
		cin >> len;
		vector< string > S( 2 );
		REP( k , 2 ) cin >> S[ k ];

		vvi P( 2 , vi( len ) ) , Q = P;
		
		n = doit( P , S , 0 , 1 );
		m = doit( Q , S , 1 , 0 );
		init();
		impr( P );
		impr( Q );
		
		REP( k , 2 ) REP( i , len ){
			if( S[ k ][ i ] == '.' ){
				int u = P[ k ][ i ];
				int v = Q[ k ][ i ];
				G[ u ].pb( v );
			}
		}
		int ans = bpm();
		printf( "%d\n" , ans );
	}
}





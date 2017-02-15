#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define N 5000
#define M 13000000
#define MOD 1000000007LL
#define ALP 26

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int cnt[ M + 5 ];
vector< pair< char , int > > trie[ M ];
int node ;

void init( int doit ){
	node = 1;
	if( doit > 1 ){
		REP( i , 100 ) cnt[ i ] = 0 , trie[ i ].clear();
	}
}
inline int getNode( int u , char c ){
	for( auto o : trie[ u ] )
		if( o.fi == c )return o.se;
	return 0;	
}
void add( string s ){
	int p = 0 ;
	REP( i , SZ( s ) ){
		int v = getNode( p , s[ i ] );
		if( !v ){
			trie[ p ].pb( mp( s[ i ] , node ) );
			p = node++;
		}
		else p = v;
		cnt[ p ] ++;
	}
}
char S[ N + 5 ];
int C[ N + 5 ][ N + 5 ];

int main(){
	for( int i = 0 ; i <= N ; ++i ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++i )
		for( int j = 1 ; j < i ; ++j ){
			C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
			if( C[ i ][ j ] >= MOD ) C[ i ][ j ] -= MOD;
		}
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , Q;
		sc( n ) , sc( Q );
		scanf( "%s" , S );
		string s = string( S );
		init( cases );
		
		REP( i , n ) add( s.substr( i ) );

		vi ans( n + 1 );
		
		for( int i = 1 ; i < node ; ++i ){
			for( int k = 1 ; k <= cnt[ i ] ; ++k ){
				ans[ k ] = ans[ k ] + C[ cnt[ i ] ][ k ];
				if( ans[ k ] >= MOD ) ans[ k ] -= MOD;
			}
		}
		
		REP( i , Q ){
			int x;
			sc( x );
			if( x > n ) puts( "0" );
			else printf( "%d\n" , ans[ x ] );
		}
		
	}
}



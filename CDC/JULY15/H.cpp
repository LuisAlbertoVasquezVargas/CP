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

#define N 18

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int n;
vi G[ N + 5 ];
int DP[ N ][ 1 << N ];
/*
bool used[ N ][ 1 << N ];
int memo[ N ][ 1 << N ];
int dp( int u , int mask ){
	if( used[ u ][ mask ] ) return memo[ u ][ mask ];
	used[ u ][ mask ] = 1;
	int len = SZ( G[ u ] );
	vi SET( len + 1 );
	for( auto v : G[ u ] ){
		if( mask & (1 << v) ) continue;
		int state = dp( v , mask ^ (1 << v) );
		if( state <= len ) SET[ state ] = 1;
	}
	int &dev = memo[ u ][ mask ] = 0;
	while( SET[ dev ] ) dev ++;
	return dev;
}
*/
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		REP( i , N ) G[ i ].clear();
		int m;
		sc( n ) , sc( m );
		REP( it , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		for( int mask = (1 << n) - 1 ; mask >= 0 ; --mask )
			for( int u = 0 ; u < n ; ++u ){
				int len = SZ( G[ u ] );
				vi SET( len + 1 );
				for( auto v : G[ u ] ){
					if( mask & (1 << v) ) continue;
					int state = DP[ v ][ mask ^ (1 << v) ];
					if( state <= len ) SET[ state ] = 1;
				}
				DP[ u ][ mask ] = 0;
				while( SET[ DP[ u ][ mask ] ] ) DP[ u ][ mask ] ++;
			}
		int ans = 0;
		REP( i , n )
			if( !DP[ i ][ (1 << i) ] ) ans ++;
		printf( "%d\n" , ans );
	}
}




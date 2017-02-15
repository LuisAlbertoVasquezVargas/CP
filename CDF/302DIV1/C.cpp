#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 20
#define INF (1LL<<40)

typedef long long ll;
typedef vector< int > vi;

int A[ N + 5 ][ N + 5 ];
bool used[ 1 << N ];
ll memo[ 1 << N ];
int lower_bit[ 1 << N ];
int n , m ;
int groups[ N + 5 ][ N + 5 ];
int ones( int mask ){ return __builtin_popcount( mask );}
ll SUM[ N + 5 ][ N + 5 ] , MAXI[ N + 5 ][ N + 5 ];
ll dp( int mask ){
	if( mask == 0 ) return 0;
	if( used[ mask ] ) return memo[ mask ];
	
	used[ mask ] = 1;
	ll &dev = memo[ mask ] = INF;
	int i = lower_bit[ mask ];
	REP( j , m ){
		dev = min( dev , A[ i ][ j ] + dp( mask ^ (1 << i) ) );
		int inter = (mask & groups[ i ][ j ]);
		dev = min( dev , SUM[ i ][ j ] - MAXI[ i ][ j ] + dp( mask ^ inter ) );
	}
    return dev;
}
char S[ N + 5 ][ N + 5 ];
int main(){
    REP( i , (1 << 20) ) lower_bit[ i ] = 31 - __builtin_clz( i );
    while( sc( n ) == 1 ){
        sc( m );
        REP( i , n ) scanf( "%s" , S[ i ] );
        REP( i , n ) REP( j , m ) sc( A[ i ][ j ] );
    
    	clr( SUM , 0 );
    	clr( MAXI , 0 );
        clr( groups , 0 );
        REP( j , m ){
            REP( i , n ){
                REP( k , n )
                    if( S[ i ][ j ] == S[ k ][ j ] ){
                    	SUM[ i ][ j ] += A[ k ][ j ];
                    	MAXI[ i ][ j ] = max( MAXI[ i ][ j ] , (ll)A[ k ][ j ] );
                    	groups[ i ][ j ] ^= (1 << k);
                    }
             }
        }

        clr( used , 0 );
        printf( "%d\n" , (int)dp( (1 << n) - 1 ) );
    }
}

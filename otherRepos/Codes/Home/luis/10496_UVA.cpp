#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 16
#define INF (1<<29)

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int X[ N ] , Y[ N ] , dist[ N ][ N ];
bool used[ N ][ 1 << N ];
int memo[ N ][ 1 << N ];
int n;
int dp( int u , int mask ){
	if( mask == (1 << n) - 1 ) return dist[ u ][ 0 ];
	if( used[ u ][ mask ] ) return memo[ u ][ mask ];
	used[ u ][ mask ] = 1;
	int &dev = memo[ u ][ mask ] = INF;
	REP( v , n ) if( !(mask & (1<< v)) ) dev = min( dev , dist[ u ][ v ] + dp( v , mask ^ (1<<v) ) );
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int x , y;
		sc( x ) , sc( y );
		sc( X[ 0 ] ) , sc( Y[ 0 ] );
		sc( n );
		REP( i , n ) sc( X[ i + 1 ] ) , sc( Y[ i + 1 ] );
		n ++;
		REP( i , n ) REP( j , n ) dist[ i ][ j ] = abs( X[ i ] - X[ j ] ) + abs( Y[ i ] - Y[ j ] );
		clr( used , 0 );
		printf( "The shortest path has length %d\n" , dp( 0 , 1 ) );
	}
}




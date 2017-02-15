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

#define N 40000
#define LOGN 16

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

char s[ N + 5 ];
int n , gap;
int pos[ N + 5 ] , tmp[ N + 5 ] , sa[ N + 5 ] , lcp[ N + 5 ];

bool sufCmp( int i , int j ){
	if( pos[ i ] != pos[ j ] ) return pos[ i ] < pos[ j ];
	i += gap , j += gap;
	return (i < n && j < n) ? pos[ i ] < pos[ j ] : i > j ;
}
void build(){
	n = strlen( s );
	REP( i , n ) sa[ i ] = i , pos[ i ] = s[ i ];
	for( gap = 1 ; ; gap <<= 1 ){
		sort( sa , sa + n , sufCmp );
		REP( i , n - 1 ) tmp[ i + 1 ] = tmp[ i ] + sufCmp( sa[ i ] , sa[ i + 1 ] );
		REP( i , n ) pos[ sa[ i ] ] = tmp[ i ];
		if( tmp[ n - 1 ] == n - 1 ) break;
	}
	for( int i = 0 , k = 0 ; i < n ; ++i )
		if( pos[ i ] != n - 1 ){
			for( int j = sa[ pos[ i ] + 1 ] ; s[ i + k ] == s[ j + k ] ; ) ++k;
			lcp[ pos[ i ] ] = k;
			if( k ) --k;
		}
}
int rmq1[ LOGN + 1 ][ N + 5 ];
int rmq2[ LOGN + 1 ][ N + 5 ];
void RMQ(){
	REP( i , n ) rmq1[ 0 ][ i ] = lcp[ i ];
	for( int k = 1 ; k <= LOGN ; ++k )
		for( int i = 0 ; i + (1<<k) <= n ; ++i )
			rmq1[ k ][ i ] = min( rmq1[ k - 1 ][ i ] , rmq1[ k - 1 ][ i + (1<<(k-1)) ] );
			
	REP( i , n ) rmq2[ 0 ][ i ] = sa[ i ];
	for( int k = 1 ; k <= LOGN ; ++k )
		for( int i = 0 ; i + (1<<k) <= n ; ++i )
			rmq2[ k ][ i ] = max( rmq2[ k - 1 ][ i ] , rmq2[ k - 1 ][ i + (1<<(k-1)) ] );
}
int query1( int i , int j ){
	int r = 31 - __builtin_clz( j - i + 1 );
	return min( rmq1[ r ][ i ] , rmq1[ r ][ j - ( 1 << r ) + 1 ] );
}
int query2( int i , int j ){
	int r = 31 - __builtin_clz( j - i + 1 );
	return max( rmq2[ r ][ i ] , rmq2[ r ][ j - ( 1 << r ) + 1 ] );
}
pii LCP( int i , int j ){
	return mp( query1( i , j - 1 ) , query2( i , j ) );
}
int main(){
	int m;
	while( sc( m ) == 1 ){
		if( !m ) break;
		scanf( "%s" , s );
		build();
		RMQ();
		if( m == 1 ){
			printf( "%d %d\n" , n , 0 );
			continue;
		}
		pii best( 0 , -1 );
		for( int i = 0 ; i + m - 1 < n ; ++i ){
			pii p = LCP( i , i + m - 1 );
			best = max( best , p );
		}
		if( best.fi == 0 ) {
			puts( "none" );
			continue;
		}
		printf( "%d %d\n" , best.fi , best.se );
	}
}



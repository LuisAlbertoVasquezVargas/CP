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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int INF = INT_MAX/2;
int n , m , sz;
int orig[ N + 5 ] , dest[ N + 5 ] , peso[ N + 5 ];
vi D;
bool relax( int k ){
	int u = orig[ k ] , v = dest[ k ] , w = peso[ k ];
	if( D[ u ] + w < D[ v ] ){
		D[ v ] = D[ u ] + w;
		return 1;
	}
	return 0;
}
bool bellmanFord( int s ){
	D = vi( n , INF );
	D[ s ] = 0;
	REP( it , n - 1 )
		REP( i , m )
			relax( i );
	REP( i , m ) if( relax( i ) ) return 0;
	return 1;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int s , t;
		sc( n ) , sc( s ) , sc( t );
		sc( m );
		REP( i , m ) sc( orig[ i ] ) , sc( dest[ i ] ) , sc( peso[ i ] );
		if( tc ) puts( "" );
		if( !bellmanFord( s ) ){
			puts( "infinity" );
			continue;
		}
		if( D[ t ] >= INF ){
			puts( "infinity" );
			continue;
		}
		printf( "%d\n" , D[ t ] );
	}
}



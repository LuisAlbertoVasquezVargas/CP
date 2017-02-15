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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

struct triple{
	int a , b , c;
	triple(){}
	triple( int a , int b , int c ) : a( a ) , b( b ) , c( c ) {}
};
bool operator < ( const triple &x , const triple &y ){
	if( x.a != y.a ) return x.a < y.a;
	if( x.b != y.b ) return x.b < y.b;
	return x.c < y.c;
}

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vvi T( n );
		
		vi A , B;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			A.pb( x ) , B.pb( x + y - 1 );
		}
		for( int timer = 0 ; timer <= 2005 ; ++timer ){
			vector< triple > ind;
			REP( i , n ){
				if( SZ( T[ i ] ) == 2 ) continue;
				if( A[ i ] <= timer && timer <= B[ i ] ) ind.pb( triple( B[ i ] , SZ( T[ i ] ) , i ) );
			}
			sort( all( ind ) );
			int cur = 0;
			for( auto x : ind ){
				if( cur == K ) break;
				T[ x.c ].pb( timer );
				cur ++;
			}
		}
		
		bool ok = 1;
		REP( i , n ) if( SZ( T[ i ] ) != 2 ) ok = 0;
		if( !ok ){
			puts( "No" );
			continue;
		}
		puts( "Yes" );
		REP( i , n ) printf( "%d %d\n" , T[ i ][ 0 ] , T[ i ][ 1 ] );
	}
}



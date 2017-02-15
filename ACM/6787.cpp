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

#define N 20

typedef long long ll;
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int INF = INT_MAX/2;
int X[ N + 1 ] , Y[ N + 1 ];
bool used[ N ][ 1 << N ];
int memo[ N ][ 1 << N ];
int n , W , H;
int dist( int a , int b ){
	return W * abs( X[ a ] - X[ b ] ) + H * abs( Y[ a ] - Y[ b ] );
}
int dp( int u , int mask ){
	if( __builtin_popcount( mask ) == 1 ) return dist( 0 , u );
	if( used[ u ][ mask ] ) return memo[ u ][ mask ];
	used[ u ][ mask ] = 1;
	
	int &dev = memo[ u ][ mask ] = INF;
	REP( v , n )
		if( v != u && (mask & (1 << v)) ) dev = min( dev , dist( u , v ) + dp( v , mask ^ (1 << u) ) );
	return dev;
}
int CEIL( int a , int b ){
	if( a == 0 ) return 0;
	return (a - 1)/ b + 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int S , D;
		sc( n );
		sc( W ) , sc( H ) , sc( S ) , sc( D );
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			X[ i ] = x , Y[ i ] = y;
		}
		clr( used , 0 );
		int ans = INT_MAX;
		REP( u , n ) ans = min( ans , dist( 0 , u ) + dp( u , (1 << n) - 1 ) );
		ans = (ans/S) + (ll)n * D;
		//ld t = (ld)ans / S + (ld) n * D;
		//ans += n * D;
		
		//DEBUG( t );
		int len = ans;
		ans += 18 * 60 ;
		printf( "%02d:%02d\n" , (ans / 60)%24 , ans % 60 );
	}
}





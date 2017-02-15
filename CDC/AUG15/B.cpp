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

#define N 200000
#define INF (1<<29)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool used[ 2 ][ N + 5 ];
int memo[ 2 ][ N + 5 ];
char S[ 2 ][ N + 5 ];
int n;
int dp( int x , int y ){
	if( y == n - 1 ) return 0;
	if( used[ x ][ y ] ) return memo[ x ][ y ];
	used[ x ][ y ] = 1;
	int &dev = memo[ x ][ y ] = INF;
	if( S[ x ][ y + 1 ] == '.' ) dev = min( dev , dp( x , y + 1 ) );
	if( S[ x ^ 1 ][ y + 1 ] == '.' ) dev = min( dev , 1 + dp( x ^ 1, y + 1 ) );
	if( S[ x ^ 1 ][ y ] == '.' ) dev = min( dev , 1 + dp( x ^ 1, y ) );
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		REP( k , 2 ) scanf( "%s" , S[ k ] );
		n = strlen( S[ 0 ] );
		REP( k , 2 ) REP( i , n ) used[ k ][ i ] = 0;
		for( int i = n - 1 ; i >= 0 ; --i )
			REP( k , 2 ) dp( k , i );
		int ans = INF;
		REP( k , 2 )
			if( S[ k ][ 0 ] == '.' ) ans = min( ans , dp( k , 0 ) );
		if( ans >= INF ){
			puts( "No" );
			continue;
		}
		puts( "Yes" );
		printf( "%d\n" , ans );
	}
}



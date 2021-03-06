#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 10000
#define cte 800
#define M 1600
#define INF (1<<29)

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

int P[ N + 5 ] , W[ N + 5 ] , D[ N + 5 ];
bool used[ N + 5 ][ M + 5 ][ 3 ];
int memo[ N + 5 ][ M + 5 ][ 3 ];
int n;
int dp( int pos , int cur , int turns ){
	if( cur < -205 ) return -INF;
	if( pos == n ) return (cur >= 0) ? 0 : (-INF);
	if( used[ pos ][ cte + cur ][ turns ] ) return memo[ pos ][ cte + cur ][ turns ];
	used[ pos ][ cte + cur ][ turns ] = 1;
	int &dev = memo[ pos ][ cte + cur ][ turns ] = dp( pos + 1 , cur , turns );
	dev = max( dev , P[ pos ] + dp( pos + 1 , cur - W[ pos ] , turns ) );
	if( turns ){
		dev = max( dev , P[ pos ] + dp( pos + 1 , cur - W[ pos ] + D[ pos ] , turns - 1 ) );
	}
	return dev;
}

int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) sc( P[ i ] ) , sc( W[ i ] ) , sc( D[ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , m , 2 ) );
	}
}


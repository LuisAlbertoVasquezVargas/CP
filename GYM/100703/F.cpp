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

#define test() puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 400
#define INF 1000000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

bool used[ N + 1 ][ 210 ][ 210 ];
int memo[ N + 1 ][ 210 ][ 210 ];
int A[ 2 ][ N + 1 ];
int n , m;
int dp( int pos , int cura , int curb ){
	if( cura > m/2 + 1 ) return INF;
	if( curb > m/2 + 1 ) return INF;
	if( pos == n ) {
		if( cura + curb == m ){
			if( abs( cura - curb ) <= 1 ) return 0;
			return INF;
		}
		return INF;
	}
	if( used[ pos ][ cura ][ curb ] ) return memo[ pos ][ cura ][ curb ];
	used[ pos ][ cura ][ curb ] = 1;
	int &dev = memo[ pos ][ cura ][ curb ] = dp( pos + 1 , cura , curb );
	REP( k , 2 )
		dev = min( dev , A[ k ][ pos ] + dp( pos + 1 , cura + (k == 0) , curb + (k == 1) ) );
	return dev;
}


int main(){
	while( sc( m ) == 1 ){
		sc( n );
		REP( k , 2 ) REP( i , n ) sc( A[ k ][ i ] );
		clr( used , 0 );
		printf( "%d\n" , dp( 0 , 0 , 0 ) );
	}
}



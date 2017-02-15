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
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		vi pref( n );
		pref[ 0 ] = A[ 0 ];
		for( int i = 1 ; i < n ; ++i )
			pref[ i ] = pref[ i - 1 ] + A[ i ];
		vi suf( n );
		suf[ n - 1 ] = A[ n - 1 ];
		for( int i = n - 2 ; i >= 0 ; --i )
			suf[ i ] = suf[ i + 1 ] + A[ i ];
		vi DP( n );
		DP[ n - 1 ] = abs( A[ n - 1 ] );
		for( int i = n - 2 ; i >= 0 ; --i )
			DP[ i ] = max( DP[ i + 1 ] + A[ i ] , abs( suf[ i ] ) );
		int ans = DP[ 0 ];
		for( int i = 0 ; i + 1 < n ; ++i )
			ans = max( ans , abs( pref[ i ] ) + DP[ i + 1 ] );
		printf( "%d\n" , ans );
	}
}



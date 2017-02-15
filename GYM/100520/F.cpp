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
typedef vector< vi > vvi;

int main(){
	//freopen( "flights.in" , "r" , stdin );
	//freopen( "flights.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		int m;
		sc( m );
		if( n == 0 && m == 0 ) break;
		vi deg( n );
		vvi G( n ) , C( n );
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			deg[ u ] ++;
			deg[ v ] ++;
			G[ u ].pb( v );
			C[ u ].pb( i );
			
			G[ v ].pb( u );
			C[ v ].pb( i );
		}
		priority_queue< pii > Q;
		vi used( n );
		int cur = m;
		vi ans( m );
		REP( it , n ){
			int u = 0 , maxi = INT_MIN;
			REP( i , n )
				if( !used[ i ] && deg[ i ] > maxi ) u = i , maxi = deg[ i ];
			REP( i , SZ( G[ u ] ) ){
				int v = G[ u ][ i ];
				if( !used[ v ] ){
					ans[ C[ u ][ i ] ] = cur --;
					deg[ v ] --;
				}
			}
			used[ u ] = 1;
		}
		puts( "Yes" );
		REP( i , SZ( ans ) ) printf( "%d%c" , ans[ i ] , (i + 1 == SZ(ans) ? 10 : 32 ) );
	}
}





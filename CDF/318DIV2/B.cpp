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

vi inter( vi &a , vi&b ){//intersection of sorted arrays O(n)
	vi c( min( SZ(a) , SZ(b) ) );
	vi :: iterator it = set_intersection( all( a ) , all( b ) , c.begin() );
	c.resize( it - c.begin() );
	return c;
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vi orig( m ) , dest( m );
		vvi G( n );
		vi deg( n );
		REP( it , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			orig[ it ] = u;
			dest[ it ] = v;
			deg[ u ] ++;
			deg[ v ] ++;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		REP( i , n ) sort( all( G[ i ] ) );
		int ans = INT_MAX;
		REP( it , m ){
			int u , v;
			u = orig[ it ];
			v = dest[ it ];
			vi vec = inter( G[ u ] , G[ v ] );
			
			for( auto x : vec )
				ans = min( ans , deg[ u ] + deg[ v ] + deg[ x ] );
			
		}
		if( ans >= INT_MAX ) puts( "-1" );
		else printf( "%d\n" , ans - 6 );
	}
}



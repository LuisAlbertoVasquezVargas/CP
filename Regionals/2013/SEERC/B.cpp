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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int INF = INT_MAX/2;
vi G[ N + 5 ];

int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		int A , B;
		sc( A ) , sc( B );
		REP( i , n ) G[ i ].clear();
		bool direct = 0;
		
		ll tot = (((ll)n * (ll)(n - 1)) >> 1) - m;
		vvi mat;
		if( tot <= N ){
			mat = vvi( n , vi( n , 1 ) );
		}
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			if( u >= v ) swap( u , v );
			if( u == 0 && v == n - 1 ) direct = 1;
			G[ u ].pb( v );
			G[ v ].pb( u );
			if( tot <= N ){
				mat[ u ][ v ] = 0;
				mat[ v ][ u ] = 0;
			}
		}	
		vi dist( n , INF );
		queue< int > Q;
		Q.push( 0 );
		dist[ 0 ] = 0;
		
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			for( auto v : G[ u ] )
				if( dist[ v ] == INF ){
					dist[ v ] = dist[ u ] + 1;
					Q.push( v );
				}
		}
		ll ans = LLONG_MAX;
		if( dist[ n - 1 ] != INF ){
			ans = min( ans , (ll)dist[ n - 1 ] * A );
		}else{
			ans = min( ans ,(ll) B );
		}
		if( tot <= N ){
			dist = vi( n , INF );
			Q.push( 0 );
			dist[ 0 ] = 0;
		
			while( !Q.empty() ){
				int u = Q.front(); Q.pop();
				REP( v , n ){
					if( mat[ u ][ v ] && dist[ v ] == INF ){
						dist[ v ] = dist[ u ] + 1;
						Q.push( v );
					}
				}
			}
			if( dist[ n - 1 ] != INF ) 
				ans = min( ans , (ll)dist[ n - 1 ] * B );
		}
		if( !direct ) ans = min( ans ,(ll) B );
		else ans = min( ans ,(ll) A );
		printf( "%d\n" , (int)ans );
	}
}




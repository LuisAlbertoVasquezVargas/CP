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
typedef vector< pii > vpii;
typedef vector< int > vi;

int id[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , m;
		sc( n ) , sc( m );
		REP( i , n ) id[ i ] = i;
		vector< pair< int , pair< int , int > > > V;
		REP( i , m ){
			int u , v , w ;
			sc( u ) , sc( v ) , sc( w );
			u -- , v -- ;
			V.pb( mp( w , mp( u , v ) ) );
		}
		sort( all( V ) );
		int ans = 0;
		for( auto e : V ){
			int w = e.fi , u = e.se.fi , v = e.se.se;
			if( Find( u ) == Find( v ) ) continue;
			ans = w;
			Union( u , v );
		}
		
		printf( "%d\n" , ans );
	}
}



#include<bits/stdc++.h>
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
typedef vector< int > vi;

int id[ N + 1 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
struct edg{
	int u , v , w;
	edg(){}
	edg( int u , int v , int w ) : u( u ) , v( v ) , w( w ) {}
};
bool operator < ( const edg &e1 , const edg &e2 ){ return e1.w > e2.w; }
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , m ;
		sc( n ) , sc( m );
		REP( i , n ) id[ i ] = i;
		vector< edg > E;
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v -- ;
			E.pb( edg( u , v , w ) );
		}
		sort( all( E ) );
		ll ans1 = 0 , ans2 = 0;
		for( auto e : E ){
			int u = e.u , v = e.v , w = e.w;
			if( Find( u ) != Find( v ) ){
				Union( u , v );
			}else{
				ans1 += w;
				ans2 = max( ans2 , (ll)w );
			}
		}
		printf( "Case #%d: %lld %lld\n" , tc + 1 , ans1 , ans2 );
	}
}




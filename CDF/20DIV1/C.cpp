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
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const ll INF = (1LL << 61);

vi G[ N + 5 ] ;
vll C[ N + 5 ];
int m , n ;
void add( int u , int v , ll w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
struct Node{
    int id ;
    ll dist;
    Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

vi dijkstra( int s ){
	vll dist( n , INF );
	vi vis( n ) , pa( n , -1 );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        if( vis[ u ] ) continue;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( !vis[ v ] && dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                pa[ v ] = u;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
    if( dist[ n - 1 ] >= INF ) return vi( 1 , -1 );
	int u = n - 1 ;
	vi vec;
	while( 1 ){
		vec.pb( u + 1 );
		if( pa[ u ] == -1 ) break;
		u = pa[ u ];
	}
	reverse( all( vec ) );
	return vec;
}

int main(){
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			add( u , v , w );
			add( v , u , w );
		}
		vi vec = dijkstra( 0 );
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}




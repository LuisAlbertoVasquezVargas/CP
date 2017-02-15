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

#define N 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int INF = (INT_MAX/2);

vi G[ N + 5 ] ;
vi C[ N + 5 ];
void add( int u , int v , int w ){
    G[ u ].pb( v );
    C[ u ].pb( w );
}
struct Node{
    int id ;
    ll dist;
    Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }
int n;
vi dijkstra( int s ){
    vi dist( n , INF );
    vi vis( n );
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
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
    return dist;
}

int main(){
	int m ;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		vi orig , dest , peso;
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			add( u , v , w );
			add( v , u , w );
			orig.pb( u ) , dest.pb( v ) , peso.pb( w );
		}
		vi ds = dijkstra( 0 );
		vi dt = dijkstra( n - 1 );
		
		int ans = 0 , target = ds[ n - 1 ];
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
			REP( k , 2 ){
				if( k ) swap( u , v );
				if( ds[ u ] + w + dt[ v ] == target ) ans += w;
			}
		}
		printf( "%d\n" , (ans << 1) );
	}
}







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
#define M 1000000
#define INF (1e9)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< ll > vll;

int orig[ M + 5 ] , dest[ M + 5 ] , peso[ M + 5 ];

vi G[ N + 5 ] ;
vi C[ N + 5 ];
int m , n ;
void add( int u , int v , int w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
struct Node{
    int id ;
    int dist;
    Node( int id , int dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

vi dijkstra( int s ){
	vi dist( n , INF );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    vi vis( n );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        if( vis[ u ] ) continue;
        vis[ u ] = 1;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            int w = C[ u ][ i ];
            if( !vis[ v ] && dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
	return dist;
}
vi dag[ N + 5 ];
int memo[ N + 5 ];
bool used[ N + 5 ];
int dp( int u ){
	if( u == n - 1 ) return 1;
	if( used[ u ] ) return memo[ u ];
	used[ u ] = 1;
	int &dev = memo[ u ] = 0;
	for( auto v : dag[ u ] )
		dev = min( 2 , dev + dp( v ) );
	return dev;
}
int main(){
	int K;
	while( sc( n ) == 1 ){
		sc( m ) , sc( K );
		REP( i , n ) G[ i ].clear();
		REP( i , K ) {
			int x;
			sc( x );
		}
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			orig[ i ] = u;
			dest[ i ] = v;
			peso[ i ] = w;
			add( u , v , w );
			add( v , u , w );
		}
		vi ds = dijkstra( 0 );
		vi dt = dijkstra( n - 1 );
		REP( i , n ) dag[ i ].clear() , used[ i ] = 0;
		REP( i , m ){
			REP( k , 2 ){
				int u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
				if( k ) swap( u , v );
				if( ds[ u ] + w + dt[ v ] == ds[ n - 1 ] ){
					dag[ u ].pb( v );
				}
			}
		}
		int ans = dp( 0 );
		puts( ans == 2 ? "yes" : "no" );
	}
}


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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 10000
#define M 250000
#define INF 12345678

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

vi G[ N + 5 ] ;
vi C[ N + 5 ];
int n ;
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
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            int w = C[ u ][ i ];
            if( dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
	return dist;
}
int orig[ M + 5 ] , dest[ M + 5 ] , peso[ M + 5 ];

int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			orig[ i ] = u;
			dest[ i ] = v;
			peso[ i ] = w;
			add( u , v , w );
			add( v , u , w );
		}
		int s = 0 , t = n - 1;
		vi dS = dijkstra( s );
		vi dT = dijkstra( t );
		int ans = 0 , d = dS[ t ];
		REP( i , m ){
			int u , v , w;
			REP( k , 2 ){
				u = orig[ i ];
				v = dest[ i ];
				w = peso[ i ];
				if( k ) swap( u , v );
				if( dS[ u ] + w + dT[ v ] == d ){
					ans += w;
				}
			}
		}
		printf( "%d\n" , ans << 1 );
	}
}



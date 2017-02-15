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
#define INF (1LL<<60)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< ll > vll;

vi G[ N + 5 ] ;
vll C[ N + 5 ];
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
int n;
vll dijkstra( int s ){
	vll dist( n , INF );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
	return dist;
}
int A[ N + 5 ];
int main(){
	int len;
	while( sc( len ) == 1 ){
		
		REP( i , len ){
			int x;
			sc( x );
			A[ i ] = x;
		}
		n = 2 * len + 3 ;
		int s = n - 1 , a = s - 1 , b = a - 1;
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( i , len ) add( s , len + i , 0 );
		REP( i , len ) add( len + i , i , A[ i ] );
		REP( i , len - 1 ){
			add( i , i + 1 , 1 );
			add( i + 1 , i , 1 );
		}
		add( a , 0 , 1 );
		add( b , len - 1 , 1 );
		
		add( s , a , 0 );
		add( s , b , 0 );
		
		vll vec = dijkstra( s );
		ll ans = 0;
		REP( i , len ) ans = max( ans , vec[ i ] );
		printf( "%d\n" , (int)ans );
	}
}



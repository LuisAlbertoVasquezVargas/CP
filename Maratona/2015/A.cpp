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
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;

ll INF = (1LL<<58);
vi G[ N + 1 ] , C[ N + 1 ];
void add( int u , int v , int w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}
int n;
struct Node{
    int id , flag;
    ll dist;
    Node( int id , int flag , ll dist ) : id( id ) , flag( flag ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

vvll solve( int s ){
	vvll dist( n , vll( 2 , INF ) );
	priority_queue< Node > Q;
	dist[ s ][ 0 ] = 0;
    Q.push( Node( s , 0 , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id , flag = U.flag;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( dist[ u ][ flag ] + w < dist[ v ][ flag ^ 1 ] ){
                dist[ v ][ flag ^ 1 ] = dist[ u ][ flag ] + w;
                Q.push( Node( v , flag ^ 1 , dist[ v ][ flag ^ 1 ] ) );
            }
        }
    }
	return dist;
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( it , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			add( u , v , w );
			add( v , u , w );
		}
		vvll a = solve( 0 );
		vvll b = solve( n - 1 );
		ll ans = INF;
		REP( flag , 2 ) REP( u , n ) ans = min( ans , a[ u ][ flag ] + b[ u ][ flag ] );
		if( ans >= INF ) ans = -1;
		printf( "%lld\n" , ans );
	}
}



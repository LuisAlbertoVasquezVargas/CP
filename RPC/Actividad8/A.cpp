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

#define INF (12345678)
#define N 20000
#define M 16

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

vi G[ N + 5 ] , C[ N + 5 ];
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
	vi vis( n , 0 );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        if( vis[ u ] ) continue;
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
int adj[ M + 1 ][ M + 1 ];
bool used[ 2 ][ M + 1 ][ 1 << M ];
int memo[ 2 ][ M + 1 ][ 1 << M ];
int T , P;
int dp( int flag , int u , int mask ){
	if( __builtin_popcount( mask ) == 1 ){
		if( flag ) return min( T , adj[ u ][ 0 ] );
		return adj[ u ][ 0 ];
	}
	if( used[ flag ][ u ][ mask ] ) return memo[ flag ][ u ][ mask ];
	used[ flag ][ u ][ mask ] = 1;
	int &dev = memo[ flag ][ u ][ mask ] = INF;
	REP( v , P ){
		if( u != v && (mask & (1 << v)) ){
			dev = min( dev , adj[ u ][ v ] + dp( flag , v , mask ^ (1 << u) ) );
			if( flag )
				dev = min( dev , T + dp( 0 , v , mask ^ (1 << u) ) );
		}
	}
	return dev;
}

int main(){
	int m , limit;
	while( sc( n ) == 1 ){
		sc( P ) , sc( m ) , sc( limit ) , sc( T );
		vi vec;
		REP( i , P ){
			int p , timer;
			sc( p ) , sc( timer );
			limit -= timer;
			vec.pb( p );
		}
		sort( all( vec ) );
		if( vec.front() != 0 ) vec.insert( vec.begin() , 0 );
		P = SZ( vec );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		REP( it , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			add( u , v , w );
			add( v , u , w );
		}
		if( limit < 0 ){
			puts( "impossible" );
			continue;
		}
		
		if( P == 1 ){
			puts( "possible without taxi" );
			continue;
		}
		
		REP( i , P ) REP( j , P ) adj[ i ][ j ] = INF;
		REP( i , P ) adj[ i ][ i ] = 0;
		
		REP( i , P ) {
			vi temp = dijkstra( vec[ i ] );
			REP( j , P ) adj[ i ][ j ] = min( adj[ i ][ j ] , temp[ vec[ j ] ] );
		}
		clr( used , 0 );
		int ans = INF , mask = (1 << P) - 1;
		mask ^= (1 << 0);
		for( int i = 1 ; i < P ; ++i ) {
			ans = min( ans , adj[ 0 ][ i ] + dp( 1 , i , mask ) );
			ans = min( ans , T + dp( 0 , i , mask ) );
		}
		
		if( ans > limit ){
			puts( "impossible" );
			continue;
		}
		
		ans = INF;
		for( int i = 1 ; i < P ; ++i ) 
			ans = min( ans , adj[ 0 ][ i ] + dp( 0 , i , mask ) );
		puts( ans <= limit ? "possible without taxi" : "possible with taxi" );
	}
}





#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1LL<<60)
#define N 300000
#define M 300000

typedef long long ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int , int > pii;

int orig[ M + 5 ] , dest[ M + 5 ] , peso[ M + 5 ];

void add( int u , int v , ll w , int id ,  vvi &G , vvll &C , vvi &I ){
	G[ u ].pb( v );
	C[ u ].pb( w );
	I[ u ].pb( id );
}
struct Node{
    int id ;
    ll dist;
    Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

vll dijkstra( int s , int n , vvi &G , vvll &C ){
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

void prim( int s , int n , vvi &G , vvll &C , vvi &I , ll &ans , vi &vec ){
	//falta visitados , asumiendo aristas son dirigidas :P
	vll d( n , INF );
	vi pa( n , -1 ) , id( n );
	priority_queue< Node > Q;
	d[ s ] = 0;
	Q.push( Node( s , d[ s ] ) );
	
	while( !Q.empty() ){
		Node U = Q.top(); Q.pop();
		int u = U.id;
		REP( i , SZ( G[ u ] ) ){
			int v = G[ u ][ i ];
			ll w = C[ u ][ i ];
			int eti = I[ u ][ i ];
			if( w < d[ v ] ){
				id[ v ] = eti;
				pa[ v ] = u;
				d[ v ] = w;
				Q.push( Node( v , d[ v ] ) );
			}
		}
	}
	
	REP( i , n ){
		if( pa[ i ] == -1 ) continue;
		vec.pb( id[ i ] );
		ans += d[ i ];
	}
	
}


int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		vvi G( n ) , I( n );
		vvll C( n );
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			add( u , v , w , i , G , C , I );
			add( v , u , w , i , G , C , I );
			orig[ i ] = u;
			dest[ i ] = v;
			peso[ i ] = w;
		}
		int s;
		sc( s );
		s --;
		vll d = dijkstra( s , n , G , C );
		I = G = vvi( n );
		C = vvll( n );
        REP( i , m ){
            int u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
            if( d[ u ] + (ll)w == d[ v ] ){
                add( u , v , w , i , G , C , I );
            }else if( d[ v ] + (ll)w == d[ u ] ){
                add( v , u , w , i , G , C , I );
            }
        }
        ll ans = 0;
        vi vec;
		prim( s , n , G , C , I , ans , vec );
		cout << ans << '\n';
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] + 1 , (i + 1 == SZ( vec )) ? 10 : 32 );
	}
}



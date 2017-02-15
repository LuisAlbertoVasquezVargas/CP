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


typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int N = 100000;
const int M = 100000;
const ll INF = LLONG_MAX/2;
struct Node{
	int id ;
	ll dist;
	Node( int id , ll dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }
struct graph{
	vi G[ N + 5 ] ;
	vll C[ N + 5 ];
	int n ;
	graph(){}
	graph( int n ) : n( n ) {}
	void clear(){
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
	}
	void add( int u , int v , ll w ){
		G[ u ].pb( v );
		C[ u ].pb( w );
	}
	vll dijkstra( int s ){
		vll dist( n , INF );
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
}G , GT;

#define VIZ(e,x) (orig[e] == x? dest[e] : orig[e])
struct BCC{
	int n,m,fin;
	int orig[M + 1], dest[M + 1], peso[M + 1],pila[M + 1], top = 0;
	vi E[N + 1];
	int low[N + 1], dfsn[N + 1], timer;
	int ponte[M + 1];
	BCC(){}
	BCC( int n ) : n( n ) , m( 0 ){}
	void add( int u , int v , int w ){
		orig[ m ] = u;
		dest[ m ] = v;
		E[ u ].pb ( m );
		E[ v ].pb ( m );
		m ++;
	}
	void dfsbcc (int u, int p = -1){
		low[u] = dfsn[u] = ++timer;
		for( auto e : E[ u ] ){
			int v = VIZ (e, u);
			if (dfsn[v] == 0){
				pila[top++] = e;
				dfsbcc (v, u);
				low[u] = min (low[u], low[v]);
				if (low[v] == dfsn[v]) ponte[e] = 1;
			}else if (v!=p && dfsn[v] < dfsn[u]){
				low[u] = min (low[u], dfsn[v]);
			}
		}
	}
	void bcc (){
		REP( i , n ) dfsn[ i ] = 0;
		REP( i , m ) ponte[ i ] = 0;
		timer = 0;
		REP( i , n ) if (dfsn[ i ] == 0) dfsbcc( i );
		map< pii , int > mapa;
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ];
			if( u >= v ) swap( u , v );
			mapa[ mp( u , v ) ] ++;
		}
		REP( i , m ){
			int u = orig[ i ] , v = dest[ i ];
			if( u >= v ) swap( u , v );
			if( ponte[ i ] && mapa[ mp( u , v ) ] > 1 ) ponte[ i ] = 0;
		}
	}
};
string tos( ll x ){
	ostringstream out;
	out << x;
	return out.str();
}
string get( ll x ){
	if( x == 0 ) return "YES";
	if( x == -2 ) return "NO";
	return "CAN " + tos( x );
}
int main(){
	int n , m;
	while( sc( n ) == 1 ){
		sc( m );
		int s , t;
		sc( s ) , sc( t );
		s -- , t --;
		G = GT = graph( n );
		vi orig , dest , peso;
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			G.add( u , v , w );
			GT.add( v , u, w );
			orig.pb( u );
			dest.pb( v );
			peso.pb( w );
		}
		vll ds = G.dijkstra( s ) , dt = GT.dijkstra( t );
		BCC g( n );
		ll target = ds[ t ];
		vi x , y , z , id;
		REP( i , m ){
			ll u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
			if( ds[ u ] + w + dt[ v ] == target ){
				g.add( u , v , w );
				x.pb( u ) , y.pb( v ) , z.pb( w );
				id.pb( i ); 
			}
		}
		vll ans( m , -1 );
		g.bcc();
		REP( i , g.m ){
			if( g.ponte[ i ] ){
				ans[ id[ i ] ] = 0;
			}
		}
		REP( i , m ){
			if( ans[ i ] != -1 ) continue;
			ll u = orig[ i ] , v = dest[ i ] , w = peso[ i ];
			ll x = target - 1 - dt[ v ] - ds[ u ];
			if( x <= 0 || (w - x) <= 0 ) ans[ i ] = -2;
			else ans[ i ] = (w - x);
		}
		REP( i , m ) cout << get( ans[ i ] ) << '\n';
	}
}




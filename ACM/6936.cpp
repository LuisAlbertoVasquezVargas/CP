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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define N 1000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Edge{
	int u , v , w , id;
	Edge(){ u = v = w = id = -1; }
	Edge( int u , int v , int w , int id ) : u( u ) , v( v ) , w( w ) , id( id ){}
};
bool operator < ( const Edge &e1 , const Edge &e2 ){
	if( e1.w != e2.w ) return e1.w < e2.w;
	return e1.id < e2.id;
}
int id[ N + 1 ];
int Find( int x ){ return id[ x ] = ((id[ x ] == x) ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
vi G[ N + 1 ] ;
vector< Edge > C[ N + 1 ];
bool vis[ N + 1 ];
vi used;
Edge get_max( const Edge &e1 , const Edge &e2 ){
	if(e1.id < e2.id) return e2;
	return e1;
}
Edge dfs( int u , int target , Edge e ){
	//DEBUG2( u , target );
	vis[ u ] = 1;
	used.pb( u );
	if( u == target ) return e;
	Edge ans = Edge();
	REP( i , SZ(G[ u ]) ){
		int v = G[ u ][ i ] ;
		Edge w = C[ u ][ i ];
		if( !vis[ v ] ) ans = get_max( ans , dfs( v , target , max( e , w ) ) );
	}
	return ans;
}

#define mid ((a + b)>>1)

struct Info{
	int sum;
	Info(){ sum = 0;}
	Info( int val ){
		sum = val;
	}
};
bool operator == ( const Info &L , const Info &R ){
	return L.sum == R.sum;
}
Info operator + ( const Info &L , const Info &R ){
	if( L == Info() && R == Info() ) return Info();
	if( L == Info() ) return R;
	if( R == Info() ) return L;
	Info c;
	c.sum = L.sum + R.sum;
	return c;
}
struct Node {
	Node * l, * r;
	Info info;
	Node ( int val ) : l( NULL ) , r( NULL ) , info( val ) {}
	Node( Node * l , Node * r ) : l( l ) , r( r ){
		if( l ) info = info + (l -> info);
		if( r ) info = info + (r -> info);
	}
};
typedef Node * pNode;// puntero a node

pNode build( int a , int b ) {
	if( a == b ) return new Node( 0 );
	return new Node(
		build( a , mid ),
		build( mid + 1 , b )
	);
}
Info get( pNode t , int a , int b , int lo , int hi ){
	if( lo <= a && b <= hi ) return (t -> info);
	if( lo > b || a > hi ) return Info();
	return get( t->l , a , mid , lo , hi ) + get( t->r , mid + 1 , b , lo , hi );
}

pNode update( pNode t , int a , int b , int pos , int val ) {
	if( a == b ) return new Node( val );
	if( pos <= mid ){
		return new Node( update( t->l , a , mid , pos , val ) , t->r );
	}
	else{
		return new Node( t->l , update( t->r , mid + 1 , b , pos , val ) );
	}
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , m;
		sc( n ) , sc( m );
		
		REP( i , n ) id[ i ] = i;
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		
		vector< Edge > E;
		REP( i , m ){
			int u , v , w;
			sc( u ) , sc( v ) , sc( w );
			u -- , v --;
			if( u > v ) swap( u , v );
			E.pb( Edge( u , v , w , i ) );
		}
		sort( all( E ) );
		vi pesos;
		for( auto e : E ) pesos.pb( e.w );
		/*
		for( auto e : E ) cout << e.u << " " ; cout << endl;
		for( auto e : E ) cout << e.v << " " ; cout << endl;
		for( auto e : E ) cout << e.w << " " ; cout << endl;
		for( auto e : E ) cout << e.id << " " ; cout << endl;
		*/
		pNode p = build( 0 , m - 1 );
		vector< pNode > versions( 1 , p );
		
		for( int i = SZ(E) - 1 ; i >= 0 ; --i ){
			auto &e = E[ i ];
			int u = e.u , v = e.v , w = e.w;
			e.id = i;
			//DEBUG3( u , v , w );
			if( Find( u ) != Find( v ) ){
				Union( u , v );
				G[ u ].pb( v );
				C[ u ].pb( e );
				
				G[ v ].pb( u );
				C[ v ].pb( e );
				
				p = update( p , 0 , m - 1 , i , w );
				//test();
				//cout << "insert " << u << " " << v << endl;
			}else{
				//test();
				Edge edg = dfs( u , v , Edge() );
				int x = edg.u , y = edg.v;
				//REP( U , n ) for( auto V : G[ U ] ) cout << U << " " << V << endl;
				//cout << "erase " << x << " " << y << endl;
				//cout << "insert " << u << " " << v << endl;
				
				int ok = 0;
				REP( k , SZ( G[ x ] ) )
					if( G[ x ][ k ] == y ){
						G[ x ].erase( G[ x ].begin() + k );
						C[ x ].erase( C[ x ].begin() + k );
						ok ++;
						break;
					}
				REP( k , SZ( G[ y ] ) )
					if( G[ y ][ k ] == x ){
						G[ y ].erase( G[ y ].begin() + k );
						C[ y ].erase( C[ y ].begin() + k );
						ok ++;
						break;
					}
					
				G[ u ].pb( v );
				C[ u ].pb( e );
				
				G[ v ].pb( u );
				C[ v ].pb( e );
				p = update( p , 0 , m - 1 , edg.id , 0 );
				p = update( p , 0 , m - 1 , i , w );
				//DEBUG( ok );
				//DEBUG2( Find( u ) , Find( v ) );
				//test();
				//DEBUG3( edg.u , edg.v , edg.id );
				for( auto cur : used ) vis[ cur ] = 0;
				used.clear();
			}
			versions.pb( p );
		}
		reverse( all( versions ) );
		int Q , last;
		sc( Q );
		REP( i , Q ){
			int lo , hi;
			if( i == 0 ){
				sc( lo ) , sc( hi );
				int a = lower_bound( all( pesos ) , lo ) - pesos.begin();
				int b = upper_bound( all( pesos ) , hi ) - pesos.begin();
				b --;
				Info info = get( versions[ a ] , 0 , m - 1 , a , b );
				last = info.sum;
				printf( "%d\n" , last );
			}else{
				int x , y;
				sc( x ) , sc( y );
				lo = x - last;
				hi = y - last;
				//DEBUG2( lo , hi );
				int a = lower_bound( all( pesos ) , lo ) - pesos.begin();
				int b = upper_bound( all( pesos ) , hi ) - pesos.begin();
				b --;
				Info info = get( versions[ a ] , 0 , m - 1 , a , b );
				last = info.sum;
				printf( "%d\n" , last );
			}
		}
	}
}






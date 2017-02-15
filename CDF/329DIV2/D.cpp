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

#define LOGN 18
#define N 200000


typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< ll > vll;

int rmq[ LOGN + 1 ][ N + 5 ];
int depth[ N + 5 ];
bool vis[ N + 5 ];
vi G[ N + 5 ] ;
vll C[ N + 5 ];
ll pa[ N + 5 ];
int timer;
int in[ N + 5 ] , out[ N + 5 ];
vpii adj[ N + 5 ];
vi ind[ N + 5 ];
void dfs( int u , int p = -1 ){
	vis[ u ] = 1;
	in[ u ] = timer ++;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		ll w = C[ u ][ i ];
		if( v != p && !vis[ v ] ){
			rmq[ 0 ][ v ] = u;
			depth[ v ] = depth[ u ] + 1;
			pa[ v ] = w;
			dfs( v , u );
			adj[ u ].pb( mp( in[ v ] , v ) );
		}
	}
	out[ u ] = timer ++;
}
void add( int u , int v , ll w ){
	G[ u ].pb( v );
	C[ u ].pb( w );
}

int LCA( int a , int b ){
	if( depth[ a ] > depth[ b ] ) swap( a , b );
	int dif = depth[ b ] - depth[ a ];
	for( int i = 0 ; i <= LOGN ; ++i ) if( dif & (1<<i) ) b = rmq[ i ][ b ];
	if( a == b ) return a;
	for( int k = LOGN ; k >= 0 ; --k )
		if( rmq[ k ][ a ] != rmq[ k ][ b ] ) a = rmq[ k ][ a ] , b = rmq[ k ][ b ];
	return rmq[ 0 ][ a ];
}


int id[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( depth[ pu ] < depth[ pv ] ) id[ pv ] = pu;
	else id[ pu ] = pv;
} 
int getAnc( int u , int v ){
	for( int k = LOGN ; k >= 0 ; --k ){
		int temp = rmq[ k ][ v ];
		if( temp == -1 ) continue;
		if( in[ temp ] < in[ u ] ) continue;
		if( Find( temp ) == Find( u ) ) continue;
		v = temp;
	}
	return rmq[ 0 ][ v ];
}
ll solve( int u , int v , int lca , ll x ){
	// u ------ lca ------ v;
	while( 1 ){
		if( u == lca ) break;
		if( x == 0 ) return 0;
		int NEXT = Find( u );
		if( in[ NEXT ] <= in[ lca ] && out[ NEXT ] >= out[ lca ] ){
			u = lca;
			break;
		}
		u = NEXT;
		x /= pa[ u ];
		u = rmq[ 0 ][ u ];
	}
	if( x == 0 ) return 0;
	
	int target = in[ v ];
	while( 1 ){
		if( x == 0 ) return 0;
		if( u == v ) return x;
		int NEXT = getAnc( u , v );
		u = NEXT;
		if( u == v ) return x;
		
		int pos = upper_bound( all( ind[ u ] ) , target ) - ind[ u ].begin();
		pos --;
		int temp = adj[ u ][ pos ].se;

		x /= pa[ temp ];
		
		u = temp;
	}
	return x;
}
int main(){
	//ios_base :: sync_with_stdio( 0 );
	int n , Q;
	while( sc( n ) == 1 ){
		sc( Q );
		REP( i , n ) G[ i ].clear() , C[ i ].clear() , adj[ i ].clear() , ind[ i ].clear();
		REP( i , n ) id[ i ] = i;
		vi orig , dest;
		REP( i , n - 1 ){
			int u , v ;
			ll w;
			sc( u ) , sc( v );
			scanf( "%I64d" , &w );
			u -- , v --;
			orig.pb( u );
			dest.pb( v );
			if( w == 1 ) Union( u , v );
			add( u , v , w );
			add( v , u , w );
		}
		clr( rmq , -1 );
		clr( vis , 0 );
		timer = 0;
		dfs( 0 );
		REP( i , n ) sort( all( adj[ i ] ) );
		REP( i , n ) for( auto x : adj[ i ] ) ind[ i ].pb( x.fi );
		REP( i , Q ){
			int op;
			cin >> op;
			if( op == 1 ){
				int u , v;
				ll x;
				sc( u ) , sc( v );
				scanf( "%I64d" , &x );
				u -- , v --;
				int lca = LCA( u , v );
				ll ans = solve( u , v , lca , x );
				printf( "%I64d\n" , ans );
			}else{
				int edg;
				ll w;
				sc( edg );
				scanf( "%I64d" , &w );
				edg --;
				int u = orig[ edg ] , v = dest[ edg ];
				if( in[ u ] >= in[ v ] ) swap( u , v );
				// u ----> v
				pa[ v ] = w;
				if( w == 1 ) Union( u , v );
				//modify( edg , x );
			}
		}
	}
}

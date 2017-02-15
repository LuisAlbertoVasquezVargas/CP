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

#define N 240000
#define M 280000
#define INF INT_MAX

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

vi G[ N + 1 ];
int timer = 0;
int in[ N + 1 ] , out[ N + 1 ];
int X[ N + 1 ] , Y[ N + 1 ];
pii A[ M + 1 ];
int depth[ N + 1 ];
void dfs( int u , int d ){
	depth[ u ] = d;
	in[ u ] = timer ;
	A[ timer ] = mp( X[ u ] , d );
	timer ++;
	for( auto v : G[ u ] )
		dfs( v , d + 1 );
	out[ u ] = timer ;
	A[ timer ] = mp( INF , 0 );
	timer ++;
}

void impr( vpii &v ){
	for( auto x : v ) cout << "( " << x.fi << "-" << x.se << " ) "; 
	cout << endl;
}
void impr( vi &v ){
	REP( i , SZ( v ) ) printf( "%d%c" , v[ i ] , (i + 1 ==  SZ(v)) ? 10 : 32 );
}

#define v1 ((node<<1)+1)
#define v2 (v1+1)
#define med ((a+b)>>1)
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

vpii T[ 4 * M ];
vi R[ 4 * M ];
vi vec;
vi get( vpii &v ){
	vi ans( SZ( v ) );
	ans[ 0 ] = v[ 0 ].se;
	for( int i = 1 ; i < SZ(v) ; ++i )
		ans[ i ] = max( ans[ i - 1 ] , v[ i ].se );
	return ans;
}
vpii pull( vpii &n1 , vpii &n2 ){
	vpii ans( SZ(n1) + SZ(n2) );
	merge( n1.begin() , n1.end() , n2.begin() , n2.end() , ans.begin() );
	return ans;   
}
void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = vpii( 1 , A[ a ] );
		R[ node ] = get( T[ node ] );
		return;
	}      
	build_tree( v1 , a , med );
	build_tree( v2 , med + 1 , b );
	T[ node ] = pull( T[ v1 ] , T[ v2 ] );
	R[ node ] = get( T[ node ] );
}
void get_arrays( int node , int a , int b , int x , int y ){
	if( x > b || a > y ) return;
	if( a >= x && y >= b ){
		vec.push_back( node );
	    return;      
	}
	get_arrays( v1 , a , med , x , y );
	get_arrays( v2 , med + 1 , b , x , y );
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		REP( i , N ) G[ i ].clear();
		REP( i , 4 * M ) T[ i ].clear() , R[ i ].clear();
		REP( i , n ){
			int p , lo , hi ;
			sc( p ) , sc( lo ) , sc( hi );
			if( p != -1 ) G[ p ].pb( i );
			X[ i ] = lo;
			Y[ i ] = hi;
		}
		timer = 0;
		dfs( 0 , 0 );
		int m = timer;
		build_tree( 0 , 0 , m - 1 );
		vi w;
		REP( u , n ){
			int lo = in[ u ] , hi = out[ u ];
			vec.clear();
			get_arrays( 0 , 0 , m - 1 , lo , hi );
			int ans = 0 , target = Y[ u ];
			for( auto ind : vec ){
				int pos = upper_bound( all(T[ ind ]) , mp( target , INT_MAX ) ) - T[ ind ].begin();
				pos --;
				
				if( pos >= 0 )
					ans = max( ans , R[ ind ][ pos ] );
			}
			w.pb( ans - depth[ u ] );
		}
		impr( w );
	}
}






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
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

#define N 100000

struct data{
	vi v;
	data(){}
	data( vi &w , int flag = 0 ){
		v = w;
		if( !flag )sort( all( v ) );
		v.resize( min( SZ( v ) , 10 ) );
	}
};
data operator + ( const data &a , const data &b ){
	vi c( SZ(a.v) + SZ(b.v) );
	merge( all(a.v) , all(b.v) , c.begin() );
	return data( c , 1 );
}
#define mid ((a + b)>>1)

struct Node{
	typedef Node * pNode;
	data val;
	int len;
	Node * l , * r;
	Node(){ val = data() , len = 0; l = r = NULL; }
	Node( vi &v ) : l( NULL ) , r( NULL ) , val( v ) , len( 1 ) {}
	Node( Node * l , Node * r ) : l( l ) , r( r ) , val() , len( 0 ) {
		if( l ){
			val = val + (l->val);
			len = len + (l->len);
		}
		if( r ){
			val = val + (r->val);
			len = len + (r->len);
		}
	}
	
	Node( vvi &A ){		
		pNode p = build( 0 , SZ(A) - 1 , A );
		*(this) = *p;
	}
	pNode build( int a , int b , vvi &A ){
		if( a == b ) return new Node( A[ a ] );
		return new Node( build( a , mid , A ) , build( mid + 1 , b , A ) );
	}
	data get( int lo , int hi ) { 
		return get( this , 0 , len - 1 , lo , hi ); 
	}
	data get( pNode t , int a , int b , int lo , int hi ) {
		if( lo > b || a > hi ) return data();
		if( a >= lo && b <= hi ) return (t -> val);
		return get( (t -> l) , a , mid , lo , hi ) + get( (t -> r) , mid + 1 , b , lo , hi );
	}
	
} st[ N + 5 ];


int chain[ N + 5 ] , tam[ N + 5 ] , h[ N + 5 ] , pa[ N + 5 ];
vi peso[ N + 5 ];
int csz , cola[ N + 5 ];
vi G[ N + 5 ];

data querynodos( int u , int v ) {
	data maxi;
	
	while( chain[ u ] != chain[ v ] ) {
		if( h[ chain[ u ] ] < h[ chain[ v ] ] ) swap( u , v );
		int c = chain[ u ];
		maxi = maxi + st[ c ].get( 0 , h[ u ] - h[ c ] );
		u = pa[ chain[ u ] ];
	}
	if( h[ u ] < h[ v ] ) swap( u , v );
	int c = chain[ u ];
	maxi = maxi + st[ c ].get( h[ v ] - h[ c ] , h[ u ] - h[ c ] );
	
	return maxi;
}
int main(){
	int n , m , Q;
	while( sc( n ) == 1 ){
		sc( m ) , sc( Q );
		REP( i , n ) G[ i ].clear();
		REP( i , n ) peso[ i ].clear();
		
		REP( it , n - 1 ){
			int u , v; 
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		REP( i , m ){
			int x;
			sc( x );
			x --;
			peso[ x ].pb( i );
		}
		REP( i , n ) pa[ i ] = -1;
		csz = 0;
		cola[ csz ++ ] = 0;
		pa[ 0 ] = 0;
		h[ 0 ] = 0;
		REP( i , csz ){
			int u = cola[ i ];
			for( auto v : G[ u ] ) {
				if( pa[ v ] != -1 ) continue;
				cola[ csz++ ] = v;
				pa[ v ] = u;
				h[ v ] = h[ u ] + 1;
			}
		}
		for( int i = csz - 1 ; i >= 0 ; --i ) {
			int u = cola[ i ];
			tam[ u ] = 1;
			for( auto v : G[ u ] ) {
				if( pa[ u ] == v ) continue;
				tam[ u ] += tam[ v ];
			}
		}
		REP( i , n ) chain[ i ] = -1;
		REP( i , csz ) {
			int u = cola[ i ];
			if( chain[ u ] != -1 ) continue;
			chain[ u ] = u;
			int v = u;
			while( 1 ){ 
				int next = -1;
				for( auto v : G[ u ] ) if( pa[ v ] == u )
					if ( next == -1 || tam[ next ] < tam[ v ] ) next = v;
				if( next == -1 ) break;
				chain[ next ] = chain[ u ];
				u = next;
			}
			int len = h[ u ] - h[ v ] + 1;
			vvi a( len );
		
			REP( it , len ) {
				a[ it ] = peso[ u ];
				u = pa[ u ];
			}
			reverse( all( a ) );
			st[ v ] = Node( a );
		}

		REP( it , Q ) {
			int u , v , len;
			sc( u ) , sc( v ) , sc( len );
			u -- , v --;
			data ans = querynodos( u , v );
			vi &vec = ans.v;
			vec.resize( min( SZ( vec ) , len ) );
			printf( "%d" , SZ(vec) );
			REP( i , SZ(vec) ) printf( " %d" , vec[ i ] + 1 );
			puts( "" );
		}
	}
}



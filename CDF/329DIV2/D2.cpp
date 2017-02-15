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

#define N 200000

typedef long long ll;
typedef long double ld;
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef ll tipo;

const ll INF = 2000000000000000000LL;
struct data{
	tipo val;
	data(){ val = 1; }
	data( tipo val ) : val( val ) {}
};
data operator + ( const data &a , const data &b ){
	ld x = a.val , y = b.val;
	if( x * y > INF ) return data( INF );
	return data( a.val * b.val );
}
#define mid ((a + b)>>1)

struct Node{
	typedef Node * pNode;
	data val;
	int len;
	Node * l , * r;
	Node(){ val = data() , len = 0; l = r = NULL; }
	Node( tipo val ) : l( NULL ) , r( NULL ) , val( val ) , len( 1 ) {}
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
	
	Node( vector< tipo > &A ){		
		pNode p = build( 0 , SZ(A) - 1 , A );
		*(this) = *p;
	}
	pNode build( int a , int b , vector< tipo > &A ){
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
	void update( int pos , tipo val ){
		update( this , 0 , len - 1 , pos , val );
	}
	void update( pNode t , int a , int b , int pos , tipo val ){
		if( pos > b || a > pos ) return;
		if( pos <= a && b <= pos ){
			(t -> val) = val;
			return;
		}
		update( (t -> l) , a , mid , pos , val );
		update( (t -> r) , mid + 1 , b , pos , val );
		(t -> val) = ((t -> l) -> val) + ((t -> r) -> val);
	}
} st[ N + 5 ];

int chain[ N + 5 ] , tam[ N + 5 ] , h[ N + 5 ] , pa[ N + 5 ];
ll paW[ N + 5 ];
vi G[ N + 5 ];
vll C[ N + 5 ];
data querynodos( int u , int v ) {
	data S;
	while( chain[ u ] != chain[ v ] ) {
		if( h[ chain[ u ] ] < h[ chain[ v ] ] ) swap( u , v );
		int c = chain[ u ];
		S = S + st[ c ].get( 0 , h[ u ] - h[ c ] );
		u = pa[ chain[ u ] ];
	}
	if( h[ u ] < h[ v ] ) swap( u , v );
	int c = chain[ u ];
	S = S + st[ c ].get( h[ v ] - h[ c ] + 1 , h[ u ] - h[ c ] );// h[ v ] - h[ c ] + (1/0) (for edges/for nodes) 
	return S;
}
void impr( int n ){
	REP( u , n ){
		if( !u ) continue;
		DEBUG2( u + 1 , querynodos( u , pa[ u ] ).val );
	}
}
int main(){
	int n , Q;
	while( sc( n ) == 1 ){
		sc( Q );
		REP( i , n ) G[ i ].clear() , C[ i ].clear();
		
		vi orig(n - 1) , dest(n - 1);
		REP( it , n - 1 ){
			int u , v; 
			sc( u ) , sc( v );
			u -- , v --;
			orig[ it ] = u;
			dest[ it ] = v;
			ll w;
			scanf( "%I64d" , &w );

			G[ u ].pb( v );
			C[ u ].pb( w );
			
			G[ v ].pb( u );
			C[ v ].pb( w );
		}

		REP( i , n ) pa[ i ] = -1;
		
		vi cola;
		cola.pb( 0 );
		pa[ 0 ] = -2;
		paW[ 0 ] = -1;
		h[ 0 ] = 0;
		REP( i , SZ( cola ) ){
			int u = cola[ i ];
			REP( i , SZ( G[ u ] ) ){
				int v = G[ u ][ i ];
				ll w = C[ u ][ i ];
				if( pa[ v ] != -1 ) continue;
				cola.pb( v );
				pa[ v ] = u;
				paW[ v ] = w;
				h[ v ] = h[ u ] + 1;
			}
		}
		for( int i = SZ( cola ) - 1 ; i >= 0 ; --i ) {
			int u = cola[ i ];
			tam[ u ] = 1;
			for( auto v : G[ u ] ) {
				if( pa[ u ] == v ) continue;
				tam[ u ] += tam[ v ];
			}
		}
		REP( i , n ) chain[ i ] = -1;
		REP( i , SZ( cola ) ) {
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
			vector< tipo > a( len );
		
			REP( it , len ) {
				a[ it ] = paW[ u ];
				u = pa[ u ];
			}
			
			reverse( all( a ) );
			st[ v ] = Node( a );
		}
		REP( i , Q ){
			int op;
			sc( op );
			if( op == 1 ){
				int u , v;
				ll x;
				sc( u ) , sc( v );
				scanf( "%I64d" , &x );
				u -- , v --;
				tipo ans = querynodos( u , v ).val;
				printf( "%I64d\n" , x / ans );
			}else{
				int edg;
				ll w;
				sc( edg );
				scanf( "%I64d" , &w );
				edg --;
				int u = orig[ edg ] , v = dest[ edg ];
				if( h[ u ] >= h[ v ] ) swap( u , v );
				
				int c = chain[ v ] , len = st[ c ].len;
				st[ c ].update( h[ v ] - h[ c ] , w );
			}
		}
	}
}



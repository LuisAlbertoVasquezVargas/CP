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

#define mid ((a + b)>>1)

struct Node {
	Node * l, * r;
	int sum;
	Node ( int val ) : l( NULL ) , r( NULL ) , sum( val ) {}
	Node( Node * l , Node * r ) : l( l ) , r( r ) , sum( 0 ){
		if( l ) sum += l -> sum;
		if( r ) sum += r -> sum;
	}
};
typedef Node * pNode;// puntero a node

pNode build( vi &A , int a , int b ) {
	if( a == b ) return new Node( A[ a ] );
	return new Node(
		build( A , a , mid ),
		build( A , mid + 1 , b )
	);
}
int get_sum( pNode t , int a , int b , int lo , int hi ){
	if( lo <= a && b <= hi ) return t -> sum;
	if( lo > b || a > hi ) return 0;
	return get_sum( t->l , a , mid , lo , hi ) + get_sum( t->r , mid + 1 , b , lo , hi );
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
	int n;
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		pNode p = build( A , 0 , n - 1 );
		int Q;
		sc( Q );
		vector< pNode > roots( 1 , p );
		REP( it , Q ){
			int op;
			sc( op );
			if( op == 1 ){
				int lo , hi , K;
				sc( lo ) , sc( hi ) , sc( K );
				lo -- , hi -- , K --;
				printf( "%d\n" , get_sum( roots[ K ] , 0 , n - 1 , lo , hi ) );
			}else{
				int pos , val;
				sc( pos ) , sc( val );
				pos --;
				pNode p = roots.back();
				roots.pb( update( p , 0 , n - 1 , pos , val ) );
			}
		}
	}
}




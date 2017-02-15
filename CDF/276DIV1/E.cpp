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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << " " << z << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

#define mid ((a + b)>>1)

struct Info{
	int maxi , maxL , maxR , sum , len;
	Info(){ maxi = maxL = maxR = sum = len = 0;}
	Info( int val ){
		maxi = val;
		maxL = val;
		maxR = val;
		sum = val;
		len = 1;	
	}
};
bool operator == ( const Info &L , const Info &R ){
	return L.maxi == R.maxi && L.maxL == R.maxL && L.maxR == R.maxR && L.sum == R.sum && L.len == R.len;
}
Info operator + ( const Info &L , const Info &R ){
	if( L == Info() && R == Info() ) return Info();
	if( L == Info() ) return R;
	if( R == Info() ) return L;
	Info c;
	c.maxi = max( L.maxi , R.maxi );
	c.maxi = max( c.maxi , L.maxR + R.maxL );
	c.sum = L.sum + R.sum;
	c.len = L.len + R.len;
	c.maxL = L.maxL;
	c.maxR = R.maxR;
	if( L.sum == L.len ) c.maxL = max( c.maxL , L.sum + R.maxL );
	if( R.sum == R.len ) c.maxR = max( c.maxR , R.sum + L.maxR );
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
int n;
bool f( int L , int R , int W , vector< pNode > &roots , int pos ){
	Info info = get( roots[ pos ] , 0 , n - 1 , L , R );
	return info.maxi >= W;
}
int binary( int L , int R , int W , vector< pNode > &roots ){
	int lo = 0 , hi = n;
	while( hi - lo > 1 ){
		int med = (lo + hi) >> 1;
		if( f( L , R , W , roots , med ) ) hi = med;
		else lo = med;
	}
	return hi;
}
int main(){
	
	while( sc( n ) == 1 ){
		vpii v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( mp( x , i ) );
		}
		sort( all( v ) );
		reverse( all( v ) );
		pNode p = build( 0 , n - 1 );

		vector< pNode > roots( 1 , p );
		REP( i , n ){
			int pos = v[ i ].se , val = v[ i ].fi;
			pNode pp = roots.back();
			roots.pb( update( pp , 0 , n - 1 , pos , 1 ) );
		}
		int Q;
		sc( Q );
		REP( q , Q ){
			int L , R , W;
			sc( L ) , sc( R ) , sc( W );
			L -- , R --;
			int pos = binary( L , R , W , roots );
			printf( "%d\n" , v[ pos - 1 ].fi );
		}
	}
}




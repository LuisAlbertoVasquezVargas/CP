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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< ll > vll;

const int dim = 3;
vll MOD = { 1000000007LL , 1000000009LL , 1000000021LL };
const ll B = 13;
struct Hash{
	ll h[ dim ];
	int len;
	Hash(){
		REP( k , dim ) h[ k ] = 0;
		len = 0;
	}
	Hash( int val ){
		REP( k , dim ) h[ k ] = val;
		len = 1;
	}
};
ll POT[ dim ][ N + 5 ];
ll AC[ dim ][ N + 5 ];

Hash operator + ( const Hash &h1 , const Hash &h2 ){
	Hash h;
	h.len = h1.len + h2.len;
	REP( k , dim )
		h.h[ k ] = (h1.h[ k ] * POT[ k ][ h2.len ] + h2.h[ k ]) % MOD[ k ];
	return h;
}
bool operator == ( const Hash &h1 , const Hash &h2 ){
	if( h1.len != h2.len ) return 0;
	REP( k , dim )
		if( h1.h[ k ] != h2.h[ k ] ) return 0;
	return 1;
}
struct Node{
	Hash h;
	int flag;
	Node * l , * r;
	Node(){ flag = -1;}
	Node( int val ) : l( NULL ) , r( NULL ) , flag( -1 ) , h( val ) {}
	Node( Node * l , Node * r ) : l( l ) , r( r ) , h() , flag( -1 ) {
		if( l ) h = h + (l->h);
		if( r ) h = h + (r->h);
	}
};
typedef Node * pNode;
#define mid ((a + b)>>1)
char S[ N + 5 ];
pNode build( int a , int b ){
	if( a == b ) return new Node( S[ a ] - '0' + 1 );
	return new Node( build( a , mid ) , build( mid + 1 , b ) );
}
Hash getHash( int len , int x ){
	Hash h;
	h.len = len;
	REP( k , dim ) h.h[ k ] = (AC[ k ][ len ] * (ll)x)%MOD[ k ];
	return h;
}
void push( pNode &t ){
	if( !t ) return;
	int &flag = (t -> flag);
	if( flag == -1 ) return;
	Hash &H = (t -> h);
	H = getHash( H.len , flag );
	if( (t -> l) ){
		(t -> l) -> flag = flag;
	}
	if( (t -> r) ){
		(t -> r) -> flag = flag;
	}
	flag = -1;
}
Hash get( pNode t , int a , int b , int lo , int hi ){
	push( t );
	if( lo > b || a > hi ) return Hash();
	if( lo <= a && b <= hi ) return (t -> h);
	return get( (t -> l) , a , mid , lo , hi ) + get( (t -> r) , mid + 1 , b , lo , hi );
}
void update( pNode t , int a , int b , int lo , int hi , int val ){
	push( t );
	if( lo > b || a > hi ) return;
	if( lo <= a && b <= hi ){
		(t -> flag) = val;
		push( t );
		return;
	}
	update( (t -> l) , a , mid , lo , hi , val );
	update( (t -> r) , mid + 1 , b , lo , hi , val );
	(t -> h) = ((t -> l) -> h) + ((t -> r) -> h);
}

int main(){
	REP( k , dim ){
		POT[ k ][ 0 ] = 1;
		for( int i = 1 ; i <= N ; ++i )
			POT[ k ][ i ] = (POT[ k ][ i - 1 ] * B)%MOD[ k ];
		for( int i = 0 ; i <= N ; ++i )
			AC[ k ][ i + 1 ] = (AC[ k ][ i ] + POT[ k ][ i ])%MOD[ k ];
	}

	int n , a , b;
	while( sc( n ) == 1 ){
		sc( a ) , sc( b );
		int m = a + b;
		scanf( "%s" , S );
		pNode t = build( 0 , n - 1 );
		
		Hash h = t->h;
		REP( i , m ){
			int op;
			sc( op );
			if( op == 1 ){
				int L , R , c;
				sc( L ) , sc( R ) , sc( c );
				L -- , R --;
				update( t , 0 , n - 1 , L , R , c + 1 );
			}else{
				int L , R , d;
				sc( L ) , sc( R ) , sc( d );
				L -- , R --;
				if( R - L + 1 == d ){
					puts( "YES" );
					continue;
				}
				Hash h1 = get( t , 0 , n - 1 , L , R - d );
				Hash h2 = get( t , 0 , n - 1 , L + d , R );
				puts( (h1 == h2) ? "YES" : "NO" );
			}
		}
	}
}




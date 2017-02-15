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

#define N 100000
#define MAXN 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define mid ((a + b)>>1)
#define v1 (T[node].L)
#define v2 (T[node].R)
#define LEFT v1 , a , mid
#define RIGHT v2 , mid + 1 , b

struct Node{
	int val , L , R;
	Node(){ val = L = R = -1;}
	Node( int val , int L , int R ) : val( val ) , L( L ) , R( R ) {}
} T[ 4 * N + 5 ];
int A[ N + 5 ];
int NODES;


void build_tree( int node , int a , int b ){
	if( a == b ) {
		T[ node ].val = A[ a ];
		return;
	}
	T[ node ].L = NODES++;
	T[ node ].R = NODES++;
	build_tree( LEFT );
	build_tree( RIGHT );
	T[ node ].val = T[ v1 ].val + T[ v2 ].val;
}

void insert( int node , int a , int b , int ref , int pos , int val ){
	if( a == b ){
		T[ node ].val = val;
		return;
	}
	if( pos <= mid ){
		T[ node ].L = NODES++;
		T[ node ].R = T[ ref ].R;
		insert( LEFT , T[ ref ].L , pos , val );
	}else{
		T[ node ].L = T[ ref ].L;
		T[ node ].R = NODES++;
		insert( RIGHT , T[ ref ].R , pos , val );
	}
}

int get( int node , int a , int b , int ref , int pos , int val ){
	if( a == b ){
		T[ node ].val = val;
		return;
	}
	if( pos <= mid ){
		T[ node ].L = NODES++;
		T[ node ].R = T[ ref ].R;
		get( LEFT , T[ ref ].L , pos , val );
	}else{
		T[ node ].L = T[ ref ].L;
		T[ node ].R = NODES++;
		get( RIGHT , T[ ref ].R , pos , val );
	}
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		NODES = 0;
		//build_tree( 0 , 0 , n - 1 );
		vi LIST( 1 , 0 );
		int Q;
		sc( Q );
		REP( q , Q ){
			int pos , val;
			sc( pos ) , sc( val );
			pos --;
			int ref = LIST.back() , node = NODES;
			LIST.pb( node );
			NODES++;
			insert( node , 0 , n - 1 , ref , pos , val );
			int r = SZ(LIST);
			REP( i , n ) printf( "%d%c" , get( LIST[ r - 1 ] , 0 , LIST[ r - 2 ] , n - 1 , i , i ) , (i + 1 == n ? 10 : 32) );
		}
	}
}




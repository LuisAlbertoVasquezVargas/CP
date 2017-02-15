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

#define N (1<<16)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N ] , K;
struct Node{
	int id , curPoints;
	vi lista;
	Node(){}
	Node( int id , int curPoints , vi lista ) : id( id ) , curPoints( curPoints ) , lista( lista ) {}
}T[ 4 * N ];
Node get( const Node &winner , const Node &losser ){
	Node ans = winner;
	ans.lista.pb( losser.id );
	ans.curPoints -= losser.curPoints;
	ans.curPoints = min( ans.curPoints + K , P[ ans.id ] );
	return ans;
}
Node operator + ( const Node &a , const Node &b ){
	if( a.curPoints == b.curPoints ){
		if( a.id < b.id ) return get( a , b );
		else return get( b , a );
	}
	if( a.curPoints > b.curPoints ) return get( a , b );
	return get( b , a );
}
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b

void build_tree( int node , int a , int b ){
	if( a == b ){
		T[ node ] = Node( a , P[ a ] , vi() );
		return;
	}
	build_tree( LEFT );
	build_tree( RIGHT );
	T[ node ] = T[ v1 ] + T[ v2 ];
}
int main(){
	int cases;
	sc( cases );
	int m , n;
	REP( tc , cases ){
		sc( m );
		sc( K );
		n = (1 << m);
		REP( i , n ) sc( P[ i ] );
		build_tree( 0 , 0 , n - 1 );
		Node ans = T[ 0 ];
		printf( "%d\n" , ans.id + 1 );
		vi &v = ans.lista;
		REP( i , SZ( v ) ) printf( "%d%c" , v[ i ] + 1 , (i + 1 == SZ(v)) ? 10 : 32 );
	}	
}




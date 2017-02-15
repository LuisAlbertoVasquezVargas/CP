#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define SZ(v) ((int)(v).size())
#define all(v)  v.begin() , v.end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define test puts("************test************");
#define DEBUG( x ) cerr << #x << " " << x << endl;

#define N 100000
#define LOGN 18

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll; 
typedef vector< int > vi;
typedef vector< vi > vvi;

struct Node{
	ll w , v;
	vi ind;
	Node(){
		w = v = 0;
		ind = vi();
	}
	Node( ll w , ll v , vi ind ) : w( w ) , v( v ) , ind( ind ) {}
};
bool operator < ( const Node &a , const Node &b ){
	if( a.w != b.w ) return a.w < b.w;
	if( a.v != b.v ) return a.v < b.v;
	return a.ind < b.ind;
}

vector< Node > getSets( vector< Node > &v ){
	int n = SZ( v );
	vector< Node > vec( 1 << n );
	REP( mask , 1 << n )
		REP( i , n ) if( mask & (1 << i) ) {
			vec[ mask ].w += v[ i ].w;
			vec[ mask ].v += v[ i ].v;
			vec[ mask ].ind.pb( v[ i ].ind[ 0 ] );
		}
	return vec;
}

ll rmq[ LOGN + 1 ][ N + 5 ];
int rmqInd[ LOGN + 1 ][ N + 5 ];
ll query( int a , int b , int &id ){ 
	int r = 31 - __builtin_clz( b - a + 1 );
	if( rmq[ r ][ a ] > rmq[ r ][ b - (1<<r) + 1 ] )
		id = rmqInd[ r ][ a ];
	else id = rmqInd[ r ][ b - (1<<r) + 1 ];
	return max( rmq[ r ][ a ] , rmq[ r ][ b - (1<<r) + 1 ] );
}
int getLower( vector< Node > &v , ll x ){
	Node node( x , LLONG_MIN , vi() );
	return lower_bound( all( v ) , node ) - v.begin();
}
int getUpper( vector< Node > &v , ll x ){
	Node node( x , LLONG_MAX , vi() );
	return upper_bound( all( v ) , node ) - v.begin();
}
int main(){
	freopen( "dowry.in" , "r" , stdin );
	freopen( "dowry.out" , "w" , stdout );
	int n;
	ll L , R;
	while( cin >> n >> L >> R ){
		vll w( n ) , v( n );
		REP( i , n ) cin >> w[ i ] >> v[ i ];
		vector< Node > a , b;
		REP( i , n )
			if( i < n/2 ) a.pb( Node( w[ i ] , v[ i ] , vi( 1 , i ) ) );
			else b.pb( Node( w[ i ] , v[ i ] , vi( 1 , i ) ) );
			
		vector< Node > x = getSets( a ) , y = getSets( b );
		sort( all( y ) );
		n = SZ( y );
		REP( i , n ) {
			rmq[ 0 ][ i ] = y[ i ].v;
			rmqInd[ 0 ][ i ] = i;
		}
		for( int k = 1 ; k <= LOGN ; ++k )
			for( int i = 0 ; i + (1<<k) <= n ; ++i ){
				rmq[ k ][ i ] = max( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
				if( rmq[ k - 1 ][ i ] == rmq[ k ][ i ] ) rmqInd[ k ][ i ] = rmqInd[ k - 1 ][ i ];
				else rmqInd[ k ][ i ] = rmqInd[ k - 1 ][ i + (1<<(k - 1)) ];
			}
		ll best = 0;
		vi vec;
		REP( i , SZ( x ) ){
			
			ll nL = L - x[ i ].w;
			ll nR = R - x[ i ].w;
			
			int posa = getLower( y , nL );
			int posb = getUpper( y , nR );
			posb --;
			int id;
			if( posa <= posb && posb < n ) {
				ll cur = x[ i ].v + query( posa , posb , id );
				if( cur > best ){
					best = cur;
					vi temp = x[ i ].ind;
					for( auto x : y[ id ].ind ) temp.pb( x );
					vec = temp;
				}
			}
			
		}
		if( !SZ( vec ) ){
			cout << "0\n";
			continue;
		}
		//cout << best << endl;
		cout << SZ( vec ) << '\n';
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] + 1 , (i + 1 == SZ(vec))? 10 : 32 );
	}	
}


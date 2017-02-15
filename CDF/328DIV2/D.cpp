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

#define N 1000000
#define LOGN 20

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ] ;
int F[ N + 5 ] , T[ N + 5 ];
int rmq[ LOGN + 1 ][ N + 5 ] , depth[ N + 5 ];
void dfs( int u , int p = -1 ){
	T[ u ] = F[ u ];
	for( auto v : G[ u ] ){
		if( v != p ) {
			rmq[ 0 ][ v ] = u;
			depth[ v ] = depth[ u ] + 1;
			dfs( v , u );
			T[ u ] += T[ v ];
		}
	}
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
int cnt;
int valid[ N + 5 ];
void DFS( int u , int p = -1 ){
	cnt ++;
	valid[ u ] = 1;
	if( T[ u ] == 1 && F[ u ] == 1 )
		return;
	for( auto v : G[ u ] )
		if( v != p && T[ v ] )
			DFS( v , u );
}
int n;
const int INF = INT_MAX/2;
int bfs( int s , int &d ){
	queue< int > Q;
	vi dist( n , INF );
	Q.push( s );
	dist[ s ] = 0;

	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		for( auto v : G[ u ] )
			if( valid[ v ] && dist[ v ] == INF ){
				dist[ v ] = dist[ u ] + 1;
				Q.push( v );
			}
	}
	int cur = -1 , maxi = -1;
	REP( i , n )
		if( valid[ i ] && dist[ i ] > maxi ) cur = i , maxi = dist[ i ];
	d = dist[ cur ];
	return cur;
}

int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear();
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		clr( F , 0 );
		vi vec;
		REP( i , m ){
			int u;
			sc( u );
			u --;
			F[ u ] ++;
			vec.pb( u );
		}
		clr( rmq , -1 );
		dfs( 0 );
		for( int k = 1 ; k <= LOGN ; ++k )
			REP( i , n ) if( rmq[ k - 1 ][ i ] != -1 ) rmq[ k ][ i ] = rmq[ k - 1 ][ rmq[ k - 1 ][ i ] ];
		int lca = vec[ 0 ];
		for( int i = 1 ; i < SZ(vec) ; ++i )
			lca = LCA( lca , vec[ i ] );
		cnt = 0;
		clr( valid , 0 );
		DFS( lca , rmq[ 0 ][ lca ] );
		int d;
		int s = bfs( lca , d );
		int t = bfs( s , d );
		printf( "%d\n%d\n" , min(s , t) + 1 , 2 * (cnt - 1) - d );
	}
}





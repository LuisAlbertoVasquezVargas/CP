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

#define N 10000

vi G[ N + 5 ];
int A[ N + 5 ];
set< pii > SET;
vi vec;
int n;
bool T[ 100000 + 1 ];
void dfs( int u , int d ){
	SET.insert( mp( u , d ) );
	T[ d ] = 1;
	vec.pb( d );
	if( d == 1 ) return;
	for( auto v : G[ u ] ){
		int nd = __gcd( d , A[ v ] );
		if( !SET.count( mp( v , nd ) ) ) dfs( v , nd );
	}
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) G[ i ].clear();
		REP( i , n ) sc( A[ i ] );
		
		REP( it , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		SET.clear();
		vec.clear();
		
		REP( i , n )
			if( !SET.count( mp( i , A[ i ] ) ) ) dfs( i , A[ i ] );
		int ans = 0;
		for( auto x : vec ){
			if( T[ x ] ) ans ++ , T[ x ] = 0;
		}
		printf( "%d\n" , ans );
	}
}





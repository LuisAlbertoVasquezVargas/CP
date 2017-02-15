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

#define N 50000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

char S[ N + 5 ];
int vis[ N + 5 ];
vi G[ N + 5 ];
bool valid = 1;
void dfs( int u , char c ){
	vis[ u ] = 1;
	if( S[ u ] == '?' ) S[ u ] = c;
	else {
		if( S[ u ] != c ) valid = 0;
	}
	for( auto v : G[ u ] )
		if( !vis[ v ] ) dfs( v , c );
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , m;
		sc( n ) , sc( m );
		scanf( "%s" , S );
		
		REP( i , n ){
			vis[ i ] = 0;
			G[ i ].clear();
		}
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		for( int i = 0 ; 2 * i <= n ; ++i ){
			int u = i;
			int v = n - 1 - i;
			if( u == v ) continue;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		valid = 1;
		REP( i , n )
			if( S[ i ] != '?' && !vis[ i ] ){
				dfs( i , S[ i ] );
			}
		if( !valid ){
			puts( "0" );
			continue;
		}
		ll ans = 1;
		REP( i , n )
			if( S[ i ] == '?' && !vis[ i ] ){
				dfs( i , 'a' );
				ans = (ans * 26LL) %1000000007LL;
			}
		printf( "%d\n" , (int)ans );
	}
}



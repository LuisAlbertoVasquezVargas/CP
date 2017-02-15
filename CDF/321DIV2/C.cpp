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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int m , ans = 0;
vi G[ N + 5 ];
int vis[ N + 5 ] , A[ N + 5 ];
void dfs( int u , int p , int cnt , int maxi ){
	vis[ u ] = 1;
	int ch = 0;
	for( auto v : G[ u ] ){
		if( !vis[ v ] && v != p ){
			int ncnt = (A[ v ] ? (cnt + 1) : (0) );
			dfs( v , u , ncnt , max( maxi , ncnt ) );
			ch ++;
		}
	}
	if( !ch && maxi <= m ) ans ++;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) sc( A[ i ] );
		REP( i , n ) G[ i ].clear();
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		REP( i , n ) vis[ i ] = 0;
		ans = 0;
		dfs( 0 , -1 , A[ 0 ] , A[ 0 ] );
		printf( "%d\n" , ans );
	}
}




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
typedef vector< int > vi;

vi G[ N + 5 ];
bool vis[ N + 5 ];
bool dp[ N + 5 ] , ans[ N + 5 ];
void dfs( int u , int p ){
	vis[ u ] = 1;
	dp[ u ] = 1;
	ans[ u ] = 1;
	int ch = 0;
	int bad = 0;
	for( auto v : G[ u ] ){
		if( v == p ) continue;
		if( vis[ v ] ) continue;
		ch ++;
		dfs( v , u );
		if( !dp[ v ] ) dp[ u ] = 0;
		
		if( !dp[ v ] ){
			bad ++;
		}
	}
	if( dp[ u ] && ch > 1 ) dp[ u ] = 0;
	
	if( bad > 2 ) ans[ u ] = 0;
}
int n;

int main(){	
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear();
		REP( it , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		clr( vis , 0 );
		
		dfs( 0 , -1 );
		puts( ans[ 0 ] ? "Yes" : "No" ); 
	}
}



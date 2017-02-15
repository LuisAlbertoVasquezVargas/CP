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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi G[ N + 5 ];
int L[ 2 ][ N + 5 ] , used[ N + 5 ];
int timer = 0;
int vis[ N + 5 ];
void dfs( int u , int p ){
	vis[ u ] = 1;
	if( u ){
		int it = 0;
		REP( k , 2 ){
			if( !used[ L[ k ][ p ] ] ){
				used[ L[ k ][ p ] ] = 1;
				L[ it ][ u ] = L[ k ][ p ];
				it ++;
				break;
			}
		}
		if( it == 0 ){
			L[ 0 ][ u ] = L[ 0 ][ p ];
			L[ 1 ][ u ] = timer ++;
		}else{
			L[ it ][ u ] = timer ++;
		}
	}
	for( auto v : G[ u ] )
		if( !vis[ v ] ) {
			dfs( v , u );
		}
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) G[ i ].clear();
		REP( i , n + 5 ) used[ i ] = 0;
		REP( i , n - 1 ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
		}
		timer = 0;
		L[ 0 ][ 0 ] = timer ++;
		L[ 1 ][ 0 ] = timer ++;
		REP( i , n ) vis[ i ] = 0;
		dfs( 0 , -1 );
		
		REP( i , n ) printf( "%d %d\n" , L[ 0 ][ i ] , L[ 1 ][ i ] );
	}
}





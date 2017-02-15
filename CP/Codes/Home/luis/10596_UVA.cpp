#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 200
#define M 10000

typedef vector< int > vi;
typedef long double ld;

int ind[ N + 5 ];
int ans1 = 0;
int orig[ M + 5 ] , dest[ M + 5 ];
int id[ N + 5 ];
int Find( int x ){ return id[ x ] = ( id[ x ] == x ? x : Find( id[ x ] )) ;}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		int m;
		sc( m );
		if( m == 0 ){
			puts( "Not Possible" );
			continue;
		}
		REP( i , N ) id[ i ] = i;
		clr( ind , 0 );
		int src = 0;
		REP( i , m ){
			int u , v ;
			sc( u ) , sc( v );
			ind[ u ] ++ , ind[ v ] ++;
			Union( u , v );
			orig[ i ] = u , dest[ i ] = v;
		}
		bool ok = 1;
		REP( i , n ) if( ind[ i ] & 1 ){
			ok = 0;
			break;
		}
		if( !ok ){
			puts( "Not Possible" );
			continue;
		}
		REP( i , m ){
			if( Find( orig[ i ] ) != Find( orig[ 0 ] ) ) {
				ok = 0;
				break;
			}
			if( Find( dest[ i ] ) != Find( orig[ 0 ] ) ) {
				ok = 0;
				break;
			}
		}
		puts( ok ? "Possible" : "Not Possible" );
	}
}

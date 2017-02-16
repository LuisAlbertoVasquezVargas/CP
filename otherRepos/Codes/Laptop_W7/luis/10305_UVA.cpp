#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define N 100005

typedef vector< int > vi;

int sz;
int vis[ N ] , cola[ N ];
vi E[ N ];
void topsort( int u )
{
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( !vis[ *v ] ) topsort( *v );
	cola[ sz++ ] = u;
}
int main()
{
	int n , m , u , v;
	while( sc( n ) == 1 )
	{
		sc( m );
		if( n == 0 ) break;
		REP( i , m ){
			sc( u ) , sc( v );
			u -- , v --;
			E[ u ].pb( v );
		}
		clr( vis , 0 );
		sz = 0;
		REP( i , n ) if( !vis[ i ] ) topsort( i );
		reverse( cola , cola + sz );
		REP( i , n ) printf( "%d%c" , cola[ i ] + 1 , i + 1 == n ? 10 : 32 );
	}
}

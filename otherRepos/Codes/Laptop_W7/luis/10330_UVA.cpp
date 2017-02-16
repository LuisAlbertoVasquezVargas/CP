#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define MAX_V 256
#define MAX_E 256*256

int E , s , t ;
int cap[ 2*MAX_E ] , to[ 2*MAX_E ] , next[ 2*MAX_E ];
int last[ MAX_V ] ;
bool visited[ MAX_V ];
int dist[ MAX_V ] , q[ MAX_V ] , now[ MAX_V ];
void clear(){
    clr( last , -1 ); 
    E = 0;
}
void add_edge(int u, int v, int uv, int vu = 0 ){
    to[ E ] = v, cap[ E ] = uv, next[ E ] = last[ u ]; last[ u ] = E++;
    to[ E ] = u, cap[ E ] = vu, next[ E ] = last[ v ]; last[ v ] = E++;
}
bool bfs(){
	clr( dist , -1 );
	int head = 0 , tail = 0;
	q[ tail ] = t; ++tail;
	dist[ t ] = 0;
	while( head < tail ){
		int v = q[ head ]; ++head;
		for( int e = last[ v ] ; e != -1 ; e = next[ e ] ){
			if( cap[ e^1 ] > 0 && dist[ to[ e ] ] == -1 ){
				q[ tail ] = to[ e ]; ++tail;
				dist[ to[ e ] ] = dist[ v] + 1;
			}
		}
	}
	return dist[ s ] != -1;
}

int dfs( int v , int f ){
	if( v == t ) return f;
	for( int &e = now[ v ] ; e != -1 ; e = next[ e ] ){
		if( cap[ e ] > 0 && dist[ to[ e ] ] == dist[ v ] - 1 ){
			int ret = dfs( to[ e ] , min( f , cap[ e ] ) );
			if( ret > 0 ){
				cap[ e ] -= ret;
				cap[ e^1 ] += ret;
				return ret;
			}
		}
	}
	return 0;
}

long long max_flow( int source , int sink){
	s = source; t = sink;
	long long f = 0;
	int x;
	while( bfs() ){
		REP( i , MAX_V ) now[i] = last[i];
		while( 1 ){
			x = dfs( s , INT_MAX );
			if( x == 0 ) break;
			f += x;
		}
	}
	return f;
}
int main()
{
	int n , u , v , m , w , a , b;
	while( sc( n ) == 1 ){
		clear();
		REP( i , n ){
			sc( w );
			add_edge( 2*i , 2*i + 1 , w );
		}
		sc( m );
		REP( i , m ){
			sc( u ) , sc( v ) , sc( w );
			u-- , v--;
			add_edge( 2*u + 1 , 2*v , w );
		}
		sc( a ) , sc( b );
		REP( i , a ) sc( v ) , v-- , add_edge( 2*n , 2*v , (1<<29) );
		REP( i , b ) sc( u ) , u-- , add_edge( 2*u + 1 , 2*n + 1 , (1<<29) );
		printf( "%d\n" , max_flow( 2*n , 2*n + 1 ) );
	}
}

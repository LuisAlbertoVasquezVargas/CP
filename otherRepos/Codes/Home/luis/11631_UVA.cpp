#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()

#define N 200005

struct Node
{
	int u , v , w;
	Node(){}
	Node( int u , int v , int w ) : u( u ) , v( v ) , w( w ){}
};
bool operator <( const Node &a , const Node &b ){
	return a.w < b.w;
}
int id[ N ];
int Find( int x ){ return id[ x ] == x ? x : ( id[ x ] = Find( id[ x ] ) );}
int main()
{
	int n , m , x , y , w;
	while( sc( n ) == 1 )
	{
		sc( m );
		if( n == 0 && m == 0 ) break;
		vector< Node > V( m );
		int S = 0;
		REP( i , m ){
			sc( x ) , sc( y ) , sc( w );
			V[ i ] = Node( x , y , w );
			S += w;
		}
		sort( all( V ) );
		REP( i , n ) id[ i ] = i;
		int ans = 0;
		REP( i , m )
			if( Find( V[ i ].u ) != Find( V[ i ].v ) )
			{
				id[ Find( V[ i ].u ) ] = Find( V[ i ].v );
				ans += V[ i ].w;
			}
		printf( "%d\n" , S - ans );
	}
}

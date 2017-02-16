#include <cstdio>
#include<cstring>

#define N 505

int P , n;
int M[ N ][ N ], vis[ N ] , match[ N ];

bool dfs( int u )
{
	if( vis[u] )return 0;
	vis[u] = 1;
	for( int i = n ; i < n + P ; ++i )
		if( M[u][i] && ( match[i] == -1 || dfs( match[i] ) ) )
		{
			match[i] = u;
			return 1;
		}
	return 0;
}
int bpm()
{
	memset( match , -1 , sizeof( match ) );
	int ct = 0;
	for( int i = 0 ; i < n ; ++i )
	{
		memset( vis , 0 , sizeof( vis ) );
		ct += dfs( i );
	}
	return ct;
}
int main()
{
	int tc;
	scanf( "%d" , &tc );
	for( int t = 0 ; t < tc ; ++t )
	{
		scanf( "%d%d" , &P , &n );
		memset( M , 0 , sizeof( M ) );
		for( int i = 0 ; i < P ; ++i )
		{
			int m , x;
			scanf( "%d" , &m );
			for( int j = 0 ; j < m ; ++j ){
				scanf( "%d" , &x ) ; x-- ; 
				M[x][n+i] = 1;
			}
		}
		printf( bpm() == P?"YES\n":"NO\n" );
	}
}

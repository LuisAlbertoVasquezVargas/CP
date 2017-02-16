#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define REP(i,n) for(int i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)

#define N 205

using namespace std;

int P , n;
int M[ N ][ N ], vis[ N ] , match[ N ];

bool dfs( int u )
{
	if( vis[u] )return 0;
	vis[u] = 1;
	for( int i = 0 ; i < n + P ; ++i )
		if( M[u][i] && (match[i] == -1 || dfs( match[i] ) ) )
		{
			match[i] = u;
			return 1;
		}
	return 0;
}
int bpm()
{
	REP( i , N )match[i] = -1;
	REP( i , N )vis[i] = 0;
	int ct = 0;
	REP( i , n ) 
	{
		REP( j , N )vis[j] = 0;
		ct += dfs( i );
	}
	return ct;
}
int main()
{
	int tc;
	sc( tc );
	REP( t , tc )
	{
		sc( P ) , sc( n );
		REP( i , N )
			REP( j , N )M[i][j] = 0;
		REP( i , n )
		{
			int m , x;
			sc( m );
			REP( j , m ){
				sc( x ) ; x-- ;  M[P+i][x] = M[x][P+i] = 1;
			}
		}
		if( n < P )printf("NO\n");
		else printf( bpm() == P?"YES\n":"NO\n" );
	}
}



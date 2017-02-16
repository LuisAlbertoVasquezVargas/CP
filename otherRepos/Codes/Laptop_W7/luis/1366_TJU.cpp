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
#define clr(t,val) memset( t , val , sizeof(t) )
#define vi vector<int>
#define pb push_back

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , s , V;
double GX[ N ] , GY[ N ] , HX[ N ] , HY[ N ];
int vis[ 2*N ] , match[ 2*N ];
vi E[ 2*N ];

bool dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	REP( i , E[ u ].size() )
	{
		int v = E[ u ][ i ];
		if( match[ v ] == -1 || dfs( match[ v ] ) )
		{
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}
int bpm()
{
	clr( match , -1 );
	int cnt = 0;
	REP( i ,  n )
	{
		clr( vis , 0 );
		cnt += dfs( i );
	}
	return cnt;
}
double dist( int i , int j ){
	double dx = GX[ i ] - HX[ j ];
	double dy = GY[ i ] - HY[ j ];
	return dx*dx + dy*dy ;
}
int main()
{
	while( scanf( "%d%d%d%d" , &n , &m , &s , &V ) == 4 )
	{
		REP( i , n ) scanf( "%lf%lf" , &GX[ i ] , &GY[ i ] );
		REP( i , m ) scanf( "%lf%lf" , &HX[ i ] , &HY[ i ] );
		REP( i , n ) E[ i ].clear();
		REP( i , n ) REP( j , m )
			if( dist( i , j ) <= s*V*s*V )
				E[ i ] .pb( j );
		printf( "%d\n" , n - bpm() );
	}
}



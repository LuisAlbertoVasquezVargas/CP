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

#define MAXN 1000000
#define MAXM 2000000

using namespace std;

int n , tc ,x , y , z , m;
int memo[ MAXM + 100 ];
vector< pair< int , int > >v[ MAXN + 100 ];

/*
long long dp( int pos )
{
	if( pos == m + 1 )return 0;
	if( memo[pos] != -1 )return memo[pos];
	long long dev = dp( pos + 1 );
	for(int i = 0 ; i < v[pos].size() ; i++ )
		dev = max( dev ,v[pos][i].second + dp(v[pos][i].first+1) );
	return memo[pos] = dev;
}
*/
int main()
{
	scanf( "%d" , &tc );	
     while( tc-- )
     {
		scanf( "%d" , &n ) ;
		for( int i = 0 ; i < MAXN ; ++i )
			v[i].clear();
		//cost = first , fin  = second
		m = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			scanf( "%d %d %d" , &x , &y , &z ) ;
			v[x].push_back(make_pair(x+y,z));
			m = max( m , x + y );
		}
		memo[ m + 1 ] = 0;
		for( int k = m ; k >= 0 ; --k )
		{
			memo[k] = memo[k+1];
			int nv = v[k].size();
			if( nv == 0 )
				continue;
			for( int i = 0 ; i < nv ; i++ )
				memo[k] = max( memo[k] ,v[k][i].second + memo[v[k][i].first+1] );				
		}
		printf( "%d\n" , memo[0] );
     }
}

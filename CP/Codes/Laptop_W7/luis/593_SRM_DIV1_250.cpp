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
#include <cstring>
#define N 55
#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)

using namespace std;

vi E[ N*N ];
int vis[ N*N ];
int n;
int dfs( int u , int color , int maxi )
{
	vis[ u ] = color;
	for( int i = 0 ; i < E[ u ].size() ; ++i )
	{
		int v = E[ u ][ i ];
		if( vis[ v ] == 0 )
		{
			maxi = max( maxi , dfs( v , color==1?2:1  , 2 ) );
		}
		else if( vis[ v ] == color ) maxi = 3;
	}
	return maxi;
}
class HexagonalBoard {
public:
	int minColors(vector <string> M ) {
		n = M.size();
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j + 1 < n ; ++j )
				if( M[ i ][ j ] == M[ i ][ j + 1 ] && M[ i ][ j ] == 'X' )
				{
					int u = n*i + j , v = n*i + j + 1;
					E[ u ].pb( v ) , E[ v ].pb( u );
				}
		for( int j = 0 ; j < n ; ++j )
			for( int i = 0 ; i + 1 < n ; ++i )
				if( M[ i ][ j ] == M[ i  + 1 ][ j ] && M[ i ][ j ] == 'X' )
				{
					int u = n*i + j , v = n*(i + 1 ) + j;
					E[ u ].pb( v ) , E[ v ].pb( u );
				}
		for( int i = 0 ; i < n ; ++i )
			for( int k = 0 ; i - k -1 >= 0 && k + 1 < n ; ++k )
				if( M[ i - k ][ k ] == M[ i - k - 1 ][ k + 1 ] && M[ i - k ][ k ] == 'X' )
				{
					int u = n*(i - k) + k , v = n*( i - k - 1) + k + 1;
					E[ u ].pb( v ) , E[ v ].pb( u );
				}
		for( int j = 1 ; j < n ; ++j )
			for( int k = 0 ; n - 1 - k - 1 >= 0 && j + k + 1 < n ; ++k )
				if( M[ n - 1 - k ][ j + k ] == M[ n - 1 - k - 1 ][ j + k + 1 ] && M[ n - 1 - k ][ j + k ] == 'X' )
				{
					int u = n*(n - 1 - k) + j + k , v = n*( n - 1 - k - 1 ) + j + k + 1;
					E[ u ].pb( v ) , E[ v ].pb( u );
				}
		int cnt = 0;
		REP( i , n ) REP( j , n ) cnt += M[i][j] == 'X';
		if( cnt <= 1 ) return cnt;
		clr( vis , 0 );
		int maxi = 0;
		REP( i , n*n )
			if( M[ i/n ][ i%n ] == 'X' && vis[ i ] == 0 ) maxi = max( maxi , dfs( i , 1 , 1 ) );
		return maxi;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

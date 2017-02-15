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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vpii vector< pair< int , int > >
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 40005
#define M 16

using namespace std;

int n ,  m;
vpii E[ N ];
int D[ N ] , L[ N ] , vis[ N ] , pa[ N ] , rmq[ N ][ M + 1 ];

void dfs( int u )
{
	vis[ u ] = 1;
	REP( i , E[ u ].size() )
	{
		int v = E[ u ][ i ].fi , w = E[ u ][ i ].se;
		if( !vis[ v ] )
		{
			pa[ v ] = u;
			L[ v ] = L[ u ] + 1 ;
			D[ v ] = D[ u ] + w ;
			dfs( v );
		}
	}
}
void init()
{
	//REP( i , n )E[i].clear();
	//clr( vis , 0 );
	pa[0] = -1;
	clr( rmq , -1 );
}
void RMQ()
{
	REP( i , n ) rmq[ i ][ 0 ] = pa[i];
	for( int k = 1 ; k <= M ; ++k )
		REP( i ,  n ) if( rmq[ i ][ k - 1 ] != -1 )
			rmq[ i ][ k ] = rmq[ rmq[ i ][ k - 1 ] ][ k - 1 ];
}
void doit()
{
	dfs( 0 );
	RMQ();
}
int lca( int x , int y )
{
	if( L[ x ] > L[ y ] ) swap( x , y );
	int dif = L[ y ] - L[ x ];
	REP( k , M + 1 )
		if( ( dif & ( 1 << k ) ) ) y = rmq[ y ][ k ];
	if( x == y )return x;
	for( int k = M ; k >= 0 ; --k )
		if( rmq[ x ][ k ] != rmq[ y ][ k ] )
			x = rmq[ x ][ k ] , y = rmq[ y ][ k ];
	return pa[ x ];
}

char s[4];
int main()
{
	scanf( "%d%d" , &n , &m );
	init();
	REP( i , m )
	{
		int x , y , w;
		scanf( "%d%d%d%s" , &x , &y , &w , s );
		x-- , y--;
		E[ x ].pb( mp( y , w ) );
		E[ y ].pb( mp( x , w ) );
	}
	doit();
	int Q;
	sc( Q );
	while( Q-- )
	{
		int x , y;
		scanf( "%d%d" , &x , &y );
		x-- , y--;
		printf( "%d\n" , D[x]  + D[y] -( D[ lca( x , y ) ]<<1 ) );
	}
}



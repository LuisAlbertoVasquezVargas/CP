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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
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

#define N 505
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

vector< vector< pii > > E;
int memo[ N ];
int s , t;
int dp( int u )
{
	if( u == t )return 0;
	if( E[u].empty() )return -INF;
	int &dev = memo[ u ];
	if( dev == -1 )
	{
		dev = -INF;
		FOR( v, E[u] )
			dev = max( dev , v->se + dp( v->fi ) );
	}
	return dev;
}
int main()
{
	int n ,  m;
	sc( n ) , sc( m );
	E.resize( n );
	REP( i , m )
	{
		int x , y , w ;
		sc( x ) , sc( y ) , sc( w );
		x-- , y--;
		E[x].pb( mp(y,w) );
	}
	clr( memo , -1 );
	sc( s ) , sc( t );
	s-- , t --;
	int ans = dp( s );
	if( ans <= 0 )puts( "No solution" );
	else printf( "%d\n" , ans );
}



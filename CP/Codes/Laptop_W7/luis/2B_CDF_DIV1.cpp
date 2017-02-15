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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int A[N][N][2] , memo[N][N][2];
int g( int x , int t )
{
	int cnt = 0;
	while( x > 0 && x %t == 0 )x/= t , cnt++;
	return cnt;
}
int dp( int x , int y , int t )
{
	if( x == n - 1 && y == n - 1 )return A[x][y][t];
	int &dev = memo[x][y][t];
	if( dev == -1 )
	{
		dev = 1<<30;
		if( x + 1 != n )dev = min( dev , A[x][y][t] + dp( x + 1 , y , t ) );
		if( y + 1 != n )dev = min( dev , A[x][y][t] + dp( x , y + 1 , t ) );
	}
	return dev;
}
string f( int x , int y , int t )
{
	if( x == n - 1 && y == n - 1 )return "";
	int dev , temp = dp( x , y , t ) ;
	dev = 1<<30;
	if( x + 1 != n )
		if( temp == A[x][y][t] + dp( x + 1 , y , t ) )return "D" + f( x + 1 , y , t );
	if( y + 1 != n )
		if( temp == A[x][y][t] + dp( x , y + 1 , t ) )return "R" + f( x , y + 1 , t );
}
int main()
{
	sync
	while( scanf( "%d", &n ) == 1 )
	{
		bool zero = 0;
		int u , v;
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
			{
				int x ;
				scanf( "%d" , &x );
				if( x == 0 )zero = 1 , u = i , v = j;
				A[i][j][0] = g( x , 2 );
				A[i][j][1] = g( x , 5 );
			}
		me( memo , -1 );
		int best = dp( 0 , 0 , 0 ), op = 0;
		if( dp( 0 , 0 , 1 ) < best )
		{
			best = dp( 0 , 0 , 1 );
			op = 1;
		}
		if( best && zero )
			cout << 1 << endl << string( u , 'D' ) + string( v , 'R' ) + string( n - 1 - u , 'D' ) + string( n - 1 - v , 'R' ) << endl;
		else
			cout << best << endl << f( 0 , 0 , op ) << endl;
	}
}

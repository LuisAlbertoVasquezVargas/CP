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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 20

using namespace std;

int n , cnt , it = 0 ,I,C;
int a[N][N];
bool vis[N][N];
int dx[] = { 0 , 1 , 0  , -1};
int dy[] = { 1 , 0 , -1 , 0 };
int f( int u )
{
	if( u == 1 )return 1;
	return 4*(u-1);
}
void dfs( int x , int y , int dir )
{
	if( C == f(I) )return;
	cnt+= a[x][y];
	C ++;
	vis[x][y] = 1;
	for( int k = dir ; k < 4 ; ++k )
	{
		int nx = x + dx[k] , ny = y + dy[k];
		if( nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] )
			dfs( nx , ny , k );
	}
}
int main()
{
	while( cin >> n )
	{
		if( n == 0 )break;
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
				cin >> a[i][j];
		me( vis , 0 );
		cout << "Case " << ++it << ":";
		for( int i = 0 ; i < (n+1)/2 ; ++i )
		{
			I = n - 2*i ;
			C = cnt = 0;
			dfs( i , i , 0 );
			cout << " " << cnt;
		}
		puts("");
	}
}

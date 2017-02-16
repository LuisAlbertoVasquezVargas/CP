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
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);
#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , cnt , maxi;
vector<string>S;
vector< vector< int > >vis;
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
void dfs( int x , int y )
{
	vis[x][y] = 1;
	cnt++;
	for( int k = 0 ; k < 4 ; ++k )
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if( nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && S[nx][ny] == '1' )
			dfs( nx , ny );
	}	
}
int main()
{
	freopen( "blot.in" , "r" , stdin );
	freopen( "blot.out" , "w" , stdout );
	sync
	while( cin >> n >> m )
	{
		S.resize( n );
		vis.resize(n);
		vis = vector< vi >( n , vi( m , 0 ) );
		int comp = 0;
		maxi = 0;
		for( int i = 0 ; i < n ; ++i )cin >> S[i];
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < m ; ++j )
				if( !vis[i][j] && S[i][j] == '1' )
				{
					comp++;
					cnt = 0;
					dfs( i  , j );
					maxi = max( maxi , cnt );
				}
		cout << comp << " " << maxi << endl;
	}
}

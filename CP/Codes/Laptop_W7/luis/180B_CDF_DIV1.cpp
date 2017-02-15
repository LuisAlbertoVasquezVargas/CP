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
#define FOR(it,A) for(typeof A.rbegin() it = A.rbegin(); it!=A.rend(); it++)
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

int n , m , k , x;

map< int , int > M[2];
set< int >S;
void doit()
{
	ll sum[2] = { 0, 0 };
	FOR( i , S )
	{
		for( int j = 0 ; j < 2 ; ++j )
			sum[j] += M[j][*i];
		if( sum[0] > sum[1] )
		{
			puts( "YES" );
			return;
		}
	}
	puts( "NO" );
}
int main()
{
	sync
	while( cin >> n >> m >> k )
	{
		M[0].clear() , M[1].clear();
		S.clear();
		for( int i = 0 ; i < n ; ++i )cin >> x , M[0][x]++,S.insert(x);
		for( int i = 0 ; i < m ; ++i )cin >> x , M[1][x]++,S.insert(x);
		doit();
	}
}

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

int n, m ;
vector< pii > v;

void doit()
{
	vi ans;
	bool solve = 0;
	int temp = 0;
	for( int i = 0 ; i < m ; ++i )
	{
		if( i )temp = temp - 1 + v[i].fi - 1;
		else temp = v[i].fi;
		ans.pb( v[i].se );
		if( temp >= n )
		{
			solve = 1;
			break;
		}	
	}
	if( solve )
	{
		int nv = ans.size();
		cout << nv << endl;
		for( int i = 0  ; i < nv ; ++i )
			cout << ans[i] + 1 << (i == nv -1 ? "\n":" ");
	}else puts("Epic fail");
}
int main()
{
	freopen( "lan.in" , "r" , stdin );
	freopen( "lan.out" , "w" , stdout );
	while( cin >>  n >> m )
	{
		v.resize( m );
		for( int i = 0 ; i < m ; ++i )cin >> v[i].fi , v[i].se = i;
		sort( all( v ) );
		reverse( all( v ) );
		doit();	
	}
}

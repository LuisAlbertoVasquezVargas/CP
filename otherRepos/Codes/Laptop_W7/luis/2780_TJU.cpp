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

bool cmp( pii x , pii y )
{
	return x.fi*y.se < x.se*y.fi;
}
int main()
{
	int tc;
	cin >> tc;
	while( tc -- )
	{
		int n;
		cin >> n;
		vector< pii > v( n );
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i].fi ;
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i].se;
		sort( all( v ) , cmp );
		reverse( all( v ) );
		int t = 0 , ans = 0;
		for( int i = 0 ; i < n ; ++i )
			t+= v[i].se , ans += t*v[i].fi;
		cout << ans << endl;
	}
}

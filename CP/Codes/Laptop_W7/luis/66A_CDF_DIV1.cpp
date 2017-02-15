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

ll x , y , z , k;

int main()
{
	while( cin >> x >> y >> z >> k )
	{
		ll v[] = { x - 1 , y - 1, z - 1 };
		sort( v, v + 3 );
		vll w(3,0);
		if( k <= v[0]*3 )
		{
			for( int i = 0 ; i < 3 ; ++i ) w[i] += k/3;
			k%=3;
			if( k == 2 ) w[0]++ , w[1]++;
			else if( k ) w[0]++;
		}
		else if( k <= v[0] + v[1]*2 )
		{
			for( int i = 0 ; i < 3 ; ++i )w[i] += v[0];
			k -= 3*v[0];
			for( int i = 1 ; i < 3 ; ++i )w[i] += k/2;
			k%=2;
			if( k )w[2]++;
		}
		else if( k <= v[0] + v[1] + v[2] )
		{
			for( int i = 0 ; i < 3 ; ++i )w[i] += v[0];
			k -= 3*v[0];
			for( int i = 1 ; i < 3 ; ++i )w[i] += v[1] - v[0];
			k -= 2*(v[1] - v[0]);
			w[2] += k;
		}
		else
		{
			for( int i = 0 ; i < 3 ; ++i )w[i] += v[i];
		}
		ll ans = 1;
		for( int i = 0 ; i < 3 ; ++i )ans*= w[i]+1;
		cout << ans << endl;
	}
}

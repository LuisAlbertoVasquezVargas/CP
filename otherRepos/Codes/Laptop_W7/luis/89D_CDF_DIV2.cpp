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

#define N 105
#define MOD 100000000
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n[2] , k[2] ;
ll memo[N+N][N+N][N+N][2];

ll dp( int tot0 , int tot1 , int cnt , int last )
{
	if( tot0 + tot1 == n[0] + n[1] )return 1LL;
	ll &dev = memo[tot0][tot1][cnt][last];
	if( dev == -1 )
	{
		dev = 0;
		if( tot0 + 1 <= n[0] && ( ((last==0)?(cnt+1):1) <= k[0]) )
			dev += dp( tot0 + 1 , tot1 , ((last==0)?(cnt+1):1) , 0 ) , dev %= MOD ;
		if( tot1 + 1 <= n[1] && ( ((last==1)?(cnt+1):1) <= k[1]) )
			dev += dp( tot0 , tot1 + 1 , ((last==1)?(cnt+1):1) , 1 ) , dev %= MOD ;
	}
	return dev;
}
int main()
{
	while( cin >> n[0] >> n[1] >> k[0] >> k[1] )
	{
		me( memo , -1 );
		cout << dp( 0 , 0 , 0 , 0 ) << endl;
	}
}

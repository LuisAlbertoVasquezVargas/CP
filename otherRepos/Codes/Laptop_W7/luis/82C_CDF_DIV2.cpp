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
#define M 15
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m ;
int memo[N][M];
int A[M] , B[M] , C[M] , D[M];

int dp( int masa , int pos )
{
	if( pos == m + 1 )return 0;
	int &dev = memo[masa][pos];
	if( dev == -1 )
	{
		dev = dp( masa , pos + 1 );
		if( masa >= C[0] )
			dev = max( dev , D[0] + dp( masa - C[0] , pos ) );
		for( int k = 1 ; (masa - k*C[pos] >= 0) && (k*B[pos]<= A[pos]) ; k++ )
			dev = max( dev , k*D[pos] + dp( masa - k*C[pos] , pos + 1 ) );
	}
	return dev;
}

int main()
{
	sync
	while( cin >> n >> m >> C[0] >> D[0] )
	{
		for( int i = 1 ; i <= m ; ++i )
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		me( memo , -1 );
		cout << dp( n , 1 ) << '\n';
	}
}

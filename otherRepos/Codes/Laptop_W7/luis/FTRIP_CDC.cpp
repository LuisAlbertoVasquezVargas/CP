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

double comb( int num, int numk )
{
    if( numk > num - numk ) numk = num - numk;
    double C = 1.0;
    for( int i = 0 ; i < numk ; ++i ) C = C*(num-i*1.0)/(1.0+i);
    return C;
}
int main()
{
	int tc;
	cin >> tc;
	while( tc-- )		
	{
		int s , n , m , k;
		cin >> s >> n >> m >> k;
		double ans = 0;
		for( int i = max( k , n - 1 - ( s - m ) ) ; i <= min( m - 1 , n - 1 ) ; ++i )
			ans += comb(m-1,i)*comb(s-m,n-i-1);
		ans/=comb(s-1,n-1);
		printf( "%.6lf\n" , ans );
	}
}

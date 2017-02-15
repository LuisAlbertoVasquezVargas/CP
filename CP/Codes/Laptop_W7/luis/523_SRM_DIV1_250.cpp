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


class CountingSeries {
public:
	long long countThem(long long a, long long b, long long c, long long d, long long UP ) {
		ll cnt1 = 0 , cnt2 = 0;
		for( ll k = c ; ; k*=d )
		{
			if( ((k - a)%b == 0) && ((k-a)/b >= 0) && k <= UP )cnt2++;
			if( k <= UP )cnt1++ ;
			if( d == 1 )break;
			if( k > UP/d )break;	
		}	
		return (( a > UP )? 0 : (( UP - a )/ b + 1 ) ) + cnt1 - cnt2;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
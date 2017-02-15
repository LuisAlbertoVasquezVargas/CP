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
#define N 40

using namespace std;

int A[N];
int n , mid;
map< int , ll >M;

ll dp( int mask ,  int len ,  int pos )
{
	if( pos == n )return (len == 0 ? 1 : 0);
	if( len == 0 )return dp( A[pos] , 1 , pos + 1 )<<1LL;
	int hash = ( mask*20 +  len )*40 + pos;
	if( M.count( hash ) )return M[hash];
	ll dev = 0;
	if( len < mid ) dev = dp( (mask<<1)|A[pos], len + 1 , pos + 1 );
	int bit = (mask&(1<<(len-1)))?1:0;
	if( bit == A[pos] )dev += dp(  bit?mask^(1<<(len-1)):mask, len - 1 , pos + 1 );
	return M[hash] = dev;
}
class SPartition {
public:
	long long getCount(string s) {
		n = s.size() , mid = n/2 ;
		for( int i = 0 ; i < n ; ++i ) A[i] = (s[i] == 'o');
		return dp( 0 , 0 ,0 );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
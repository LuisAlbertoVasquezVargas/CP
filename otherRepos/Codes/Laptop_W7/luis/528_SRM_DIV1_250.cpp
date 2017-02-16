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

using namespace std;

vi V;
int n;
int memo[1005][55];
int dp( int c , int pos )
{
	if( pos == n ) return 0;
	int &dev = memo[c][pos];
	if( dev == -1 )
	{
		dev = dp( c , pos + 1 );
		if( V[pos] == 10 )dev = 1 + dp( c , pos + 1 );
		for( int k = 1 ; 10*k <=V[pos] && k <= c ; ++k )
		{
			dev = max( dev , k + ( ((V[pos]-10*k)==10)?1:0) + dp( c - k , pos + 1) );
		}
	}
	return dev;
}
class Cut {
public:
	int getMaximum(vector <int> v, int C ) 
	{
		V =v;
		n = v.size();
		v.pb(0);
		me( memo , -1 );
		return dp( C , 0 );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
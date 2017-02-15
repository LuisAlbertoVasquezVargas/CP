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

string S;
int n;
int memo[55][55][55];
int dp( int pos , int tam , int k )
{
	if( pos == n )return tam;
	int &dev = memo[pos][tam][k];
	if( dev == -1 )
	{
		dev = 0;
		if( S[pos] != ' ' || k == 0 )dev = dp( pos + 1 , tam + 1 , k );
		else dev = min( max( tam , dp( pos + 1 , 0 , k - 1) ) , dp( pos + 1 , tam + 1 , k ) );
	}
	return dev;
}
class SentenceSplitting {
public:
	int split( string s, int K ) {
		S = s;
		n = S.size();
		me( memo , -1 );
		return dp( 0 , 0 , K );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
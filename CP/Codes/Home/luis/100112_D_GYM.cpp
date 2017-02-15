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
#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int x , ns;
string s;
map< pair< int , pii > , int >memo;
int dp( int last , int pos , int dif )
{
	if( pos == ns )
	{
		if( abs( dif + (s[last]=='w'?1:-1) ) <= x )
			return 1;
		return 0;
	}
	pair< int , pii > p = mp( last , mp( pos , dif ) );
	if( memo.count(p) )return memo[p];
	int dev = 0;
	if( abs( dif + (s[last]=='w'?1:-1) ) <= x )
		dev = max( dev , 1 + dp( pos , pos + 1 , dif + (s[last]=='w'?1:-1) ) );
	if( abs( dif + (s[pos]=='w'?1:-1) ) <= x )
		dev = max( dev , 1 + dp( last , pos + 1 , dif + (s[pos]=='w'?1:-1) ) );
	return memo[p] = dev;
}
int main()
{
	while( cin >> x >> s )
	{
		ns = s.size();
		transform( all(s) , s.begin() , ::tolower );
		if( ns == 1 )
		{
			cout << 1 << endl;
			continue;	
		}
		memo.clear();
		cout << dp( 0 , 1 , 0 ) << endl;
	}
}

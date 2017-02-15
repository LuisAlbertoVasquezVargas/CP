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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
string s , t;

int main()
{
	sync
	while( cin >> s >> t )
	{
		if( s == "0" )
		{
			if( s == t ) puts("OK");
			else puts("WRONG_ANSWER");
			continue;
		}
		n = s.size();
		sort( all(s) );
		string temp;
		int zero = 0;
		for( int i = 0 ; i < n ; ++i )
			if( s[i] != '0' ) temp += s[i];
			else zero++;
		string ans = temp.substr(0,1) + string( zero , '0' ) + temp.substr(1);
		if( ans == t ) puts("OK");
		else puts("WRONG_ANSWER");
	}
}

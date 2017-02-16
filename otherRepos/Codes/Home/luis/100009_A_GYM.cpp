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
#define EPS (1e-8)

using namespace std;

string s;

int g( vi &v )
{
	int sum = 0 ;
	for( int i = 0 ; i < 6 ; ++i )
		sum += (i+1)*v[i];
	return 21*4 - sum;
}

bool f( vi &v )
{
	if( g(v) > 31 )return 0;
	bool ok = 0;
	for( int i = 0 ; i < 6 ; ++i )
	{
		if( v[i] > 0 )
		{
			v[i]--;
			ok = ok || f(v);
			v[i]++;
		}
	}
	return !ok;
}
int main()
{
	while( getline( cin , s ) )
	{
		vi v( 6 , 4 );
		int ns = s.size();
		for( int i = 0 ; i < ns ; ++i )
			v[s[i]-'1']--;
		if( (f(v) + ns )%2 )
			cout << s << " B" << endl;
		else cout << s << " A" << endl;
	}
}

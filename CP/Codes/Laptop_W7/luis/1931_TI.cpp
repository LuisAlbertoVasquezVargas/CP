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
int a[N];

int main()
{
	while( scanf( "%d" , &n ) == 1 )
	{
		for( int i = 0 ; i < n ; ++i )sc( a[i] );
		int pos = 0 , best = 0 , ans = 1;
		while( 1 )
		{
			if( pos == n ) break;
			int cnt = (pos!=0?0:-1) , temp = a[pos] , ini = pos;
			while( pos < n && temp <= a[pos] )
				cnt++, pos++;
			if( cnt > best ) best = cnt , ans = ini + 1;
		}
		printf( "%d\n" , ans );
	}
}

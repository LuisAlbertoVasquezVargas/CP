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
#define rall(v)  v.rbegin() , v.rend()
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

int n , a , b ;

int main()
{
	while( cin >> n >> a >> b )
	{
		if( n > 1 && b == 0 && a == n - 1 )puts("-1");
		else
		{
			vi v( n , 1 );
			for( int i = (((n>1)&&(b==0))?2:1) ; i < n ; ++i )
			{
				if( b )
					v[i] = 2*v[i-1],b--;
				else if( a )
					v[i] = v[i-1] + 1,a--;	
				else
					v[i] = v[i-1];	
			}
			for( int i = 0 ; i < n ; ++i )
				cout << v[i] << (i+1==n?"\n":" ");
		}
	}
}

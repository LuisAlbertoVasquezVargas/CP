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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 100005
#define MOD 1000000007

using namespace std;

int primeFact( ll num )
{
	int ans = 0;
	for( ll i = 2 ; i*i <= num ; i++ )
	{
		ll a=0;
		while(num%i==0)
		{
			num/=i;
			a++;
		}
		if( a != 0 ) ans+=a;
	}
	if( num > 1 ) ans++;
	
	return ans;
}
int main()
{
	ll x;
	while( cin >> x )
	{
		if( primeFact( x ) == 2 )
			puts( "MARIAN" );
		else	puts( "ANNE" );
	}
}

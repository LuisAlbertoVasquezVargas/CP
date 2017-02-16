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

using namespace std;

#define ll long long
#define fi first
#define se second

vector < pair <ll, ll> > primeFact( ll num )
{
	vector < pair <ll, ll> > V;
	for( ll i = 2 ; i*i <= num ; i++ )
	{
		ll a=0;
		while(num%i==0)
		{
			num/=i;
			a++;
		}
		if( a != 0 ) V.push_back( make_pair(i, a) );
	}
	if( num > 1 ) V.push_back( make_pair(num, 1) );
	
	return V;
}

class FoxAndGCDLCM {
public:
	long long get(long long G, long long L) {
		if( L%G != 0 ) return -1;
		ll x = L/G;
		vector < pair <ll, ll> >V = primeFact( x );
		int n = V.size();
		vector< ll > num( n  , 1);
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < V[i].se ; ++j )
				num[ i ]*= V[i].fi;
		ll ans = (1LL<<60) ;
		for( int mask = 0 ; mask < (1<<n) ; ++mask )
		{
			ll u = 1 , v = 1;
			for( int i = 0 ; i < n ; ++i )
				if( mask&(1<<i) )
					u *= num[ i ];
				else v *= num[ i ];
			if( u + v < ans )
				ans = u + v ;
		}
		return G*ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

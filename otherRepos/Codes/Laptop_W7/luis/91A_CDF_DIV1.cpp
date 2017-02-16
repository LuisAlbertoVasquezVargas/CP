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
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
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

ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();}
int n;
vll V;

int main()
{
	vector< string >v;
	for( int i = 1 ; i <= 10 ; ++i )
	{
		for( int j = 0 ; j <= i ; ++j )
		{
			string s = string( j , '4' ) + string( i - j , '7' );
			do
				v.pb( s );
			while( next_permutation( all(s) ) );	
		}	
	}
	vll V;
	FOR( o , v )V.pb( toi(*o) );
	sort( all( V ) );
	n =  V.size();
	ll x , y;
	while( cin >> x >> y )
	{
		ll ind = x;
		ll sum = 0;
		while( 1 )
		{
			if( ind > y )break;
			ll num = *lower_bound( all( V ) , ind );
			sum += num*( min( num , y ) - ind + 1 );
			ind = num + 1;
		}
		cout << sum << endl;
	}
}

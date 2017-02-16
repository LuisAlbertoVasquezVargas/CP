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
#define REP(i,n) for(int i = 0;i<n;++i)
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
#define MAXALPHA 29
#define INF (1<<30)
#define EPS (1e-8)

using namespace std;

int main()
{
	sync
	set< string >S;
	string s;
	vector<string>v,w;
	while( getline( cin , s ) )
		v.pb(s) , S.insert( s );
	int nv = v.size();
	for( int i = 0 ; i < nv ; ++i )
	{
		s = v[i];
		int ns = s.size();
		for( int j = 0 ; j + 1 < ns ; ++j )
		{
			string r = s.substr( 0 , j + 1 ), t = s.substr( j + 1 );
			if( S.find( r ) != S.end() && S.find( t ) != S.end() )
				w.push_back( s );
		}
	}
	sort( all(w) );
	w.resize(unique( all(w) ) - w.begin() );
	REP( i , w.size() )
		cout << w[ i ] << endl;
}

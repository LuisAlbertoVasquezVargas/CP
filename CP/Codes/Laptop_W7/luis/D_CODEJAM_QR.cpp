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

#define N 205
#define MOD 1000000007

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

using namespace std;

int cnt[N], type[N] , vis[1<<22];
int k , n  ;
vector< vector< int > >v;
vector< int >sol,temp;


void f( int mask )
{
	if( vis[mask] ) return;
	vis[mask] = 1;
	int sZ = __builtin_popcount( mask );
	if( sZ == n )
	{
		if( sol < temp ) sol = temp;
		return;	
	}
	for( int i = 1 ; i <= n ; ++i )
		if( (mask&(1<<i)) == 0 && cnt[type[i]] > 0 )
		{
			cnt[type[i]]--;
			for( int j = 0 ; j < v[i].size() ; ++j )
				cnt[v[i][j]]++;
			temp.insert(temp.begin(),i);
			f( mask^(1<<i) );
			temp.erase(temp.begin());
			for( int j = 0 ; j < v[i].size() ; ++j )
				cnt[v[i][j]]--;
			cnt[type[i]]++;
		}
}
void init()
{
	me( cnt , 0 );
	me( vis, 0 );
	sol.clear();
	temp.clear();
	v.clear();
	v.resize(n+1);
}
int main()
{
	int tc;
	cin >> tc; 
	for( int t = 0 ; t < tc ; t++ )
	{
		cin >> k >> n;
		init();
		for( int i = 0 ; i < k ; ++i )
		{
			int x ;
			cin >> x;
			cnt[x]++;
		}
		for( int i = 1 ; i <= n ; ++i )
		{
			cin >> type[i];
			int m ;
			cin >>m;
			v[i].resize(m);
			for( int j = 0 ; j < m ; ++j )
				cin >> v[i][j];
		}
		f( 0 );
		if( sol.empty() )cout << "Case #" << t + 1 <<": IMPOSSIBLE\n";
		else
		{
			cout << "Case #" << t + 1 <<":";
			reverse( all(sol) );
			for( int i = 0 ; i < sol.size() ; ++i )
				cout << " " << sol[i];
			cout << endl;
		}
	}
}

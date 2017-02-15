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

int n , x ;
priority_queue< pii >Q;
vector< vi >ans;
void doit()
{
	while( !Q.empty() )
	{
		pii P[3];
		for( int i = 0 ; i < 3 ; ++i )
		{
			if( Q.empty() )return;
			P[i] = Q.top();
			Q.pop();
		}
		for( int i = 0 ; i < 3 ; ++i )
			if( P[i].fi > 1 )Q.push( mp( P[i].fi - 1 , P[i].se ) );
		vi temp(3);
		for( int i = 0 ; i < 3 ; ++i )
			temp[i] = P[i].se;
		sort( rall( temp ) );
		ans.pb( temp );
	}
}
int main()
{
	while( cin >> n )
	{
		map< int , int >M;
		for( int i = 0 ; i < n ; ++i )
			cin >> x , M[x]++;
		Q = priority_queue< pii >();
		ans.clear();
		FOR( o , M )Q.push( mp( o->se , o->fi ) );
		doit();
		cout << ans.size() << endl;
		FOR( o , ans )
			for( int i = 0 ; i < 3 ; ++i )
				cout << (*o)[i] << (i==2?"\n":" ");
	}
}

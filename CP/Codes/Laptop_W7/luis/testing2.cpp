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
#define test puts("test");

#define N 25
#define TIME 100

using namespace std;

int n , best;
int SZ[N] , vis[TIME];
vector< vector< pair< int , int > > > v;
vector< int > sol ;
void in()
{
	v.clear();
	v.resize( n );
	for( int i = 0 ; i < n ; ++i )
	{
		cin >> SZ[i];
		v[i].resize(SZ[i]);
		for( int j = 0 ; j < SZ[i] ; ++j )
			cin >> v[i][j].first >> v[i][j].second;
	}	
}
void out()
{
	for( int i = 0 ; i < n ; ++i )
		for( int j = 0 ; j < SZ[i] ; ++j )
			cout << v[i][j].first << " " << v[i][j].second << char( j + 1 == SZ[i] ? 10 : 32 );	
}
void result()
{
	cout << best << endl;
	int nv = sol.size();
	cout << nv << endl;
	for( int i = 0 ; i < nv ; ++i )
	{
		for( int j = 0 ; j < n ; ++j )
			cout << (((1<<j)&sol[i]) != 0 )<< char( j == n - 1 ? 10 : 32 ) ; 
	}
}
void init()
{
	best = 0;
	me( vis , 0 );
	sol.clear();
}
void f( int pos , int mask )
{
	if( pos == TIME )
	{
		int temp = __builtin_popcount( mask );
		if( temp > best )sol.clear();
		if( temp >= best )sol.push_back(mask);
		best = max( best , temp );
		return;
	}
	f( pos + 1 , mask );
	for( int i = 0 ; i < n ; ++i )
		if( ( mask&(1<<i) ) == 0 )
		{
			if( v[i][0].first != pos )continue;
			bool ok = 1;
			for( int j = 0 ; ok&&(j < SZ[i]) ; ++j )
				for( int k = v[i][j].first ; ok&&(k <= v[i][j].second) ; ++k )
					if( vis[k] )ok = 0 ;
			if( ok )
			{
				for( int j = 0 ; j < SZ[i] ; ++j )
					for( int k = v[i][j].first ; k <= v[i][j].second ; ++k )
						vis[k] = 1;
				f( pos ,  mask^(1<<i) );
				for( int j = 0 ; j < SZ[i] ; ++j )
					for( int k = v[i][j].first ; k <= v[i][j].second ; ++k )
						vis[k] = 0;
			}
		}
}
int main()
{
	while( cin >> n )
	{
		in();
		init();
		f( 0 , 0 );
		//out();
		result();
	}
}

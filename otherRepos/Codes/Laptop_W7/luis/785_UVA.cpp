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

using namespace std;

string s;
vector< string >v;
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };

void doit()
{
	queue< pii >Q;
	int nv = v.size();
	for( int i = 0 ; i < nv ; ++i )
	{
		int ns = v[i].size();
		for( int j = 0 ; j < ns; ++j )
			if( v[i][j] != 'X' && v[i][j] != ' ' && v[i][j] != '_' )
				Q.push( mp( i , j ) );
	}
	while( !Q.empty() )
	{
		pii node = Q.front();
		Q.pop();
		int i = node.fi , j = node.se;
		for( int k = 0 ; k < 4 ; ++k )
		{
			int ni = i + dx[k] , nj = j + dy[k];
			if( ni >= 0 && ni < nv && nj >= 0 && nj < v[ni].size() && v[ni][nj] == ' ' )
			{
				v[ni][nj] = v[i][j];
				Q.push( mp( ni , nj ) );
			}	
		}
	}
	FOR( o , v )cout << *o << endl;
}
int main()
{
	while( getline( cin , s ) )
		v.pb( s );
	doit();
}

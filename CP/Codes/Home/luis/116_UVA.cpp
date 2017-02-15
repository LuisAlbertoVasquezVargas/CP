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

#define MAXN 10
#define MAXM 100

using namespace std;

int n,m,ans,best;
int memo[MAXN][MAXM],a[MAXN][MAXM];
map< pair<int,int>,pair<int,int> >  child ;
int dx[] = { -1 , 0 , 1 };

int dp( int pos1 , int pos2 )
{
	if( pos2 == m - 1 )return a[pos1][pos2];
	if( memo[pos1][pos2] != -1 )return memo[pos1][pos2];
	pair< int , int >p[3];
	for( int k = 0 ; k < 3 ; ++k )
		p[k]	= make_pair( ( a[pos1][pos2] + dp((pos1+dx[k]+n)%n , pos2 + 1 ) ),(pos1+dx[k]+n)%n );
	sort(p,p+3);
	child[make_pair(pos1,pos2)] = make_pair( p[0].second , pos2 + 1 );
	return memo[pos1][pos2] = p[0].first;
}
void rec()
{
	pair<int,int>p = make_pair(best,0);
	vector< int > v;
	while( 1 )
	{
		v.push_back( p.first + 1 );
		if( child.find(p) == child.end() )
			break;
		p = child[p];
	}
	int nv = v.size();
	cout << v[0] ;
	for( int i = 1 ; i < nv ; ++i )
		cout << " " << v[i] ;
	cout << endl;
}
int main()
{
     while( cin >> n >> m )
     {
		child.clear();
          for( int i = 0 ; i < n ; ++i )
          	for( int j = 0 ; j < m ; ++j )
	               cin >> a[i][j];
	     memset( memo, -1 , sizeof( memo ) );
	     ans = INT_MAX;
	     for( int i = 0 ; i < n ; ++i )
			if( dp(i,0) < ans )
			{
				ans = dp(i,0);
				best = i; 
			}
		rec();
		cout << ans << endl;
     }
}

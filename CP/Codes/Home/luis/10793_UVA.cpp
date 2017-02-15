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

#define MAXN 100
#define INF (1<<29)

using namespace std;

int n , m , x , y , w , tc;
int d[MAXN][MAXN];

void init()
{
    for( int i = 0 ; i < n ; ++i )
		d[i][i] = 0;	
    for( int i = 0 ; i < n ; ++i )
        for( int j = 0 ; j < n ; ++j )
            d[i][j] = INF;	
}
void floyd()
{
    for( int k = 0 ; k < n ; ++ k )
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j )
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);	
}
int main()
{
	cin >> tc;
	for( int t = 1 ; t <= tc ; ++t )
     {
		cin >> n >> m;
          init();
          for( int i = 0 ; i < m ; ++i )
          {
			cin >> x >> y >> w ;
			x--;y--;
			d[x][y] = d[y][x] = min( d[x][y] , w);	
		}
		floyd();
		vector< int >p;
		for( int i = 5 ; i < n ; ++i )
		{
			int dist = d[i][0];
			int cnt = 1;
			for( int j = 1; j < 5 ; ++j )
				if( d[i][j] == dist && d[i][j] != INF )
					cnt++;
			if( cnt == 5 )
				p.push_back(i);
		}
		int np = p.size();
		pair< int , int >ans = make_pair(-1,INT_MAX);
		bool ok = 1;
		for( int i = 0 ; i < np ; ++i )
		{
			int maxi = INT_MIN;
			for( int j = 0 ; j < n ; ++j )
				if( p[i] != j )
					maxi = max( maxi , d[p[i]][j] );
			if( ans.second > maxi )
				ans = make_pair( p[i] , maxi );	
			if( maxi == INF )
				ok = 0;
		}
		if( np != 0 && ok )
	          cout << "Map "<< t <<": " << ans.second << endl;
	     else cout << "Map "<< t <<": " << -1 << endl;
     }
}

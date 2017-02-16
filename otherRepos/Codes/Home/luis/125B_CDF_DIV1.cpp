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

#define MAXN 100000

using namespace std;

int n,k;
int vis[2][MAXN+1];
int dist[2][MAXN+1];
string s[2];

void bfs()
{
	memset(vis,0,sizeof(vis));
	memset(dist,-1,sizeof(dist));
	queue< pair<int,int> >q;
	
	q.push(make_pair(0,0));
	vis[0][0] = 1;
	dist[0][0] = 0;
	
	while( !q.empty() )
	{
		pair<int,int> node = q.front();
		q.pop();
		int x = node.first;
		int y = node.second;
		
		for( int i = 0 ; i < 3 ; ++i )
		{
			int nx = ( (i == 2) ? (1 - x) : x );
			int ny = ( (i == 0) ? (y - 1) : ( (i == 1) ? (y + 1) : (y + k) ) );	
			if( ny < 0 )continue;
			if( ny < n&&  s[nx][ny] == 'X' )continue;
			if( ny >= n ) ny = n;						
			if( vis[nx][ny] )continue;			
			if( !(ny > dist[x][y])  )continue;

			q.push(make_pair(nx,ny));
			vis[nx][ny] = 1;
			dist[nx][ny] = dist[x][y] + 1;
			//cout<<nx<<" "<<ny<<" "<<dist[nx][ny]<<endl;			
		}
	}	
}
int main()
{
     while( cin >> n >> k )
     {
		cin >> s[0] >> s[1];
		bfs();	
		if( ( dist[0][n] >= 0 )|| ( dist[0][n] >= 0 ))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
     }
}

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

int n,node,xi,yi,xf,yf;
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int vis[MAXN];
int dist[MAXN];
pair< int , int > N[MAXN];
pair< int , pair< int , int > >P[MAXN];
map< pair< int , int > , int >M;
vector< int > adj[MAXN];

void init()
{
	xi--;yi--;xf--;yf--;
	M.clear();
	node = 0;
	for( int i = 0 ; i < MAXN ; ++i )
		adj[i].clear();	
	memset( vis , 0 , sizeof( vis ) );
	memset( dist , -1 , sizeof( dist ) );	
}
void bfs( pair< int , int > p , pair< int , int > q )
{
	int nodep = M[p];
	int nodeq = M[q];
	
	queue< int >Q;
	Q.push(nodep);
	vis[nodep] = 1;
	dist[nodep] = 0;
	
	while( !Q.empty() )
	{
		int parent = Q.front();
		Q.pop();
		int nv = adj[parent].size();
		for( int k = 0 ; k < nv ; ++k )
		{
			int son = adj[parent][k];
			if( !vis[son] )
			{
				Q.push( son );
				vis[son] = 1;
				dist[son] = dist[parent] + 1;
			}	
		}
	}
	cout << dist[nodeq] << endl;	
}
void deb()
{
	for( int i = 0 ; i < node ; ++i )
		cout << i << " " << N[i].first + 1 << " " << N[i].second + 1 << endl;
	cout << "****" << endl;
	for( int i = 0 ; i < node ; ++i )
	{
		int nv = adj[i].size();
		cout << i << " : ";
		for( int k = 0 ; k < nv ; ++k )
			cout << adj[i][k] << " ";
		cout << endl;	
	}		
	cout << "****" << endl;
}
int main()
{
     while( cin >> xi >> yi >> xf >> yf >> n )
     {
		init();
          for( int i = 0 ; i < n ; ++i )
          {
			cin >> P[i].first >> P[i].second.first >> P[i].second.second ;
			P[i].first --;
			P[i].second.first --;
			P[i].second.second --;
		}
		sort( P , P + n );
		for( int i = 0 ; i < n ; ++i )
		{
			int x = P[i].first;
			int y0 = P[i].second.first;
			int y1 = P[i].second.second;
			if( y0 == y1 )
			{
				pair< int , int > p = make_pair( x , y0 );
				if( M.find(p) == M.end() )
				{
					M[p] = node;
					N[node] = p;
					node++;
				}	
				continue;
			}
			for( int y = y0 ; y < y1 ; ++y )
			{
				pair< int , int > p = make_pair( x , y );
				pair< int , int > q = make_pair( x , y + 1 );
				int ok = 0;
				if( M.find(p) == M.end() )
				{
					M[p] = node;
					N[node] = p;
					node++;
					ok++;
				}
				if( M.find(q) == M.end() )
				{
					M[q] = node;
					N[node] = q;
					node++;
					ok++;
				}
				if( ok == 0 )
					continue;
				int nodep = M[p];
				int nodeq = M[q];
				adj[nodep].push_back(nodeq);
				adj[nodeq].push_back(nodep);
			} 
		}
		for( int i = 0 ; i < node ; ++i )
		{
			pair< int , int > p = N[i];
			int x = p.first;
			int y = p.second;
			for( int k = 0 ; k < 8 ; ++k )
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				pair< int , int > q = make_pair( nx , ny );
				if( M.find(q) == M.end() )
					continue;
				int nodep = M[p];
				int nodeq = M[q];
				adj[nodep].push_back(nodeq);
				adj[nodeq].push_back(nodep);				
			}
		}
//		deb();		
		pair< int , int > p = make_pair( xi , yi );
		pair< int , int > q = make_pair( xf , yf );
		bfs( p , q );
     }
}

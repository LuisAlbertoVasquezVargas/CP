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
#define MAXM 10000

using namespace std;

int n,m,x,y,w,ans,tc;
int parent[MAXN];
int rank[MAXN];
int W[MAXN][MAXN],M[MAXN][MAXN];
struct edge
{
     int u,v,w;
     edge(){};
	edge( int _u , int _v , int _w )
	{
		u = _u;
		v = _v;
		w = _w;	
	}     
};
edge E[MAXM];
void init()
{
	for( int i = 0 ; i < n ; ++i )
	parent[i] = i,rank[i] = 1;
	memset( W, -1 , sizeof(W) );
}
bool cmp( edge e1 , edge e2 )
{
     return e1.w > e2.w;     
}
int Find(int a)
{
	if(parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	
	if(pa != pb)
	{
		if(rank[pa] < rank[pb]) parent[pa] = pb;
		else if(rank[pa] > rank[pb]) parent[pb] = pa;
		else
		{
			parent[pb] = pa;
			rank[pa]++;
		}
	}
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
               cin >> x >> y >> w;
			E[i] = edge(x,y,w);
		}
		sort(E,E+m,cmp);
		ans = INT_MAX;
		for( int i = 0 ; i < m ; ++i )
		{
		//	cout << E[i].u << " " << E[i].v << " " << E[i].w << endl;
			if( Find(E[i].u) != Find(E[i].v)  )
			{
				Union(E[i].u,E[i].v);
				ans =  min( ans , E[i].w );
			}
		}		
		cout << "Case #" << t << ": "<< ans << endl;
     }
}

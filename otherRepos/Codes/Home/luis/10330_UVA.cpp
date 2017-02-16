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

using namespace std;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V], dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }

	bool bfs(){
		fill(dist,dist+MAX_V,-1);
		head = tail = 0;

		q[tail] = t; ++tail;
		dist[t] = 0;

		while(head<tail){
			int v = q[head]; ++head;

			for(int e = last[v];e!=-1;e = next[e]){
				if(cap[e^1]>0 && dist[to[e]]==-1){
					q[tail] = to[e]; ++tail;
					dist[to[e]] = dist[v]+1;
				}
			}
		}

		return dist[s]!=-1;
	}

	int dfs(int v, int f){
		if(v==t) return f;

		for(int &e = now[v];e!=-1;e = next[e]){
			if(cap[e]>0 && dist[to[e]]==dist[v]-1){
				int ret = dfs(to[e],min(f,cap[e]));

				if(ret>0){
					cap[e] -= ret;
					cap[e^1] += ret;
					return ret;
				}
			}
		}

		return 0;
	}

	long long max_flow(int source, int sink){
		s = source; t = sink;
		long long f = 0;
		int x;

		while(bfs()){
			for(int i = 0;i<MAX_V;++i) now[i] = last[i];

			while(true){
				x = dfs(s,INT_MAX);
				if(x==0) break;
				f += x;
			}
		}

		return f;
	}
};

int main()
{
	int n , m , B , D ;
	while( cin >> n )
	{
		vector< int >C(n);
		for( int i = 0 ; i < n ; ++i )
			cin >> C[i];
		cin >> m;
		flow_graph G( 2*(n+1) , 4*(n+1)*(n+1) );
		for( int i = 1 ; i <= n ; ++i )
			G.add_edge( i , n + i , C[i-1] );
		for( int i = 0 ; i < m ; ++i )
		{
			int u , v, w;
			cin >> u >> v >> w;
			G.add_edge( n + u , v , w );
		}
		cin >> B >> D;
		for( int i = 0 ; i < B ; ++i )
		{
			int u;
			cin >> u;
			G.add_edge( 0 , u , (1<<30) );	
		}
		for( int i = 0 ; i < D ; ++i )
		{
			int u ;
			cin >> u;
			G.add_edge( n + u , 2*n + 1 , (1<<30) );
		}
		cout << G.max_flow( 0 , 2*n + 1 ) << endl;
	}
}

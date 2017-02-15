
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
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 100005

using namespace std;

#define MAX_V1 50000
#define MAX_V2 50000
#define MAX_E 150000

int V1,V2,l[MAX_V1],r[MAX_V2];
int E,to[MAX_E],next[MAX_E],last[MAX_V1];
bool visited[MAX_V1];

void init(){
	memset(last,-1,sizeof(int)*V1);
	E = 0;
}
 
void add_edge(int u, int v){
	to[E] = v, next[E] = last[u]; last[u] = E; ++E;
}

bool pairup(int u){
    if (visited[u])  return false;
    visited[u] = true;
    
    for(int e = last[u];e!=-1;e = next[e]){
        int v = to[e];
        
        if(r[v]==-1 || pairup(r[v])){
            l[u] = v;
            r[v] = u;
            return true;
        }
    }
    
    return false;
}

int hopcroft_karp(){
    bool change = true;
    memset(l,-1,sizeof(int)*V1);
    memset(r,-1,sizeof(int)*V2);
    
    while(change){
        change = false;
        memset(visited,false,sizeof(bool)*V1);
        
        for(int i = 0;i<V1;++i)
            if(l[i]==-1) change |= pairup(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i<V1;++i)
        if(l[i]!=-1) ++ret;
    
    return ret;
}
vector< int >adj[ MAX_V1 ];
int vis[ MAX_V1 ] , color[ MAX_V1 ];
void dfs( int node , int col )
{
	vis[ node ] = 1 , color[ node ] = col;
	for( int k = 0 ; k < adj[ node ].size() ; ++k )
	{
		int son = adj[ node ][k] ;
		if( !vis[ son ] )
			dfs( son , col^1 );
	}
}
int main()
{
	int n;
	while( scanf( "%d" , &n ) == 1 )
	{
		for( int i = 0 ; i < n ; ++i )		
			adj[i].clear();
		memset( vis , 0 , sizeof( vis ) );
		memset( color , -1 , sizeof( color ) );
		for( int i = 0 ; i < n ; ++i )
		{
			int u , m , v ;
			scanf( "%d: (%d)" , &u , &m );
			for( int j = 0 ; j < m ; ++j )
			{
				scanf( "%d" , &v );
				adj[ u ].push_back( v );
			}
		}
		for( int i = 0 ; i < n ; ++i )
			if( !vis[i] )
				dfs( i , 0 );
		V1 = V2 = n;
		init();
		for( int i = 0 ; i < n ; ++i )
		{
			if( color[i] == -1 )continue;
			if( color[i] == 0 )
				for( int k = 0 ; k < adj[i].size() ; ++k )
					if( color[ adj[i][k] ] == 1 )
						add_edge( i , adj[i][k] );
		}
		printf( "%d\n" , n - hopcroft_karp() );
	}
}

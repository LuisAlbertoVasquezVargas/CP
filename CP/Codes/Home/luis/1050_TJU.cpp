#include <cstdio>
#include<cstring>
#include<vector>
using  namespace std;

#define N 505

int P , n;
int M[ N ][ N ], vis[ N ] , match[ N ];

struct bipartite_graph{
    int V1,V2,*match;
    vector<int> *L;
    bool *visited;
    
    bipartite_graph(int MAX_V1, int MAX_V2){
        L = new vector<int>[MAX_V1];
        visited = new bool[MAX_V2];
        match = new int[MAX_V2];
    }
    
    void clear(int _V1, int _V2){
        V1 = _V1; V2 = _V2;
        for(int i = 0;i < V1;++i) L[i].clear();
    }
    
    
    
    void add_edge(int v1, int v2){
        L[v1].push_back(v2);
    }
    
    bool dfs(int u){
        for(int i = L[u].size()-1;i >= 0;--i){
            int v = L[u][i];
            if(!visited[v]){
                visited[v] = true;
                if(match[v] == -1 || dfs(match[v])){
                    match[v] = u;
                    return true;
                }
            }
         }
         return false;
    }

    int maximum_matching(){
        int ans = 0;
        fill(match,match + V2,-1);
        
        for(int i = 0;i < V1;++i){
            fill(visited,visited+V2,false);
            ans += dfs(i);
        }
        
        return ans;
    }
};

int main()
{
	int tc;
	scanf( "%d" , &tc );
	for( int t = 0 ; t < tc ; ++t )
	{
		scanf( "%d%d" , &P , &n );
		//memset( M , 0 , sizeof( M ) );
		bipartite_graph G = bipartite_graph(n,P);
		for( int i = 0 ; i < P ; ++i )
		{
			int m , x;
			scanf( "%d" , &m );
			for( int j = 0 ; j < m ; ++j ){
				scanf( "%d" , &x ) ; x-- ; 
				//M[x][P+i] = 1;
				//M[P+i][x] = 1;
				G.add_edge( i , x );
			}
		}
		printf( G.maximum_matching() == P?"YES\n":"NO\n" );
		//printf( "%d\n" , bpm() );
	}
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);	

int n , m , S ,T , U , V ,C ;
struct flow_graph{
    int MAX_V,E,s,t;
    int *cap,*to,*next,*last;
    bool *visited;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], visited = new bool[MAX_V];
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
    
    int dfs(int v, int f){
        if(v==t || f<=0) return f;
        if(visited[v]) return 0;
        visited[v] = true;
        
        for(int e = last[v];e!=-1;e = next[e]){
            int ret = dfs(to[e],min(f,cap[e]));
            
            if(ret>0){
                cap[e] -= ret;
                cap[e^1] += ret;
                return ret;
            }
        }
        
        return 0;
    }
    
    int max_flow(int source, int sink){
        s = source, t = sink;
        int f = 0,x;
        
        while(true){
            fill(visited,visited+MAX_V,false);
            x = dfs(s,INT_MAX);
            if(x==0) break;
            f += x;
        }
        
        return f;
    }
};

int main()
{
	int tc = 1;
	while( cin >> n )
	{
		if( n == 0 )break;
		cin >> S >> T >> m;
		S-- , T--;
		flow_graph G( n , m );
		for( int i = 0 ; i < m ; ++i )
		{
			cin >> U >> V >> C;
			U-- , V--;
			G.add_edge( U , V , C , C );
		}
		cout << "Network " << tc ++ << endl;
		cout << "The bandwidth is " << G.max_flow( S , T ) << "." << endl;
		puts("");
	}
}

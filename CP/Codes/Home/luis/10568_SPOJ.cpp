#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<sstream>
#include<deque>
#include<queue>
using namespace std;
#define ll long long
#define all(v) v.begin() , v.end()
#define eps 1e-8
#define inf (1<<30)
#define so(v) sort( all(v) )
 
int N , E , K;
vector<int> adj[ 505 ];
vector<bool> x[ 505 ];
int color[ 505 ];
bool ok;
 
void dfs(int u){
    if( !ok ) return;
    //color[u] = col;
    vector<int> &v = adj[u];
    for(int i = 0 ; i < v.size() ; i++){
        int vec = v[i];
        if(color[vec] == -1){
            color[vec] = (x[u][i]? 1 - color[u] : color[u]);
            //color[vec] = col;
            dfs( vec );
        }
        else{
            if(x[u][i] && color[u] == color[vec]){ ok = 0 ; return; }
            if(!x[u][i] && color[u] != color[vec] ){ ok = 0 ; return; }
        }
    }
}
 
void doit(){
    int u , v;
    scanf("%d%d%d",&N,&E,&K);
    for(int i = 0 ; i < N ; i++) adj[i].clear() , x[i].clear() ;
    for(int i = 0 ; i < E ; i++){
        scanf("%d%d",&u,&v);
        u--,v--;
        adj[u].push_back( v );
        adj[v].push_back( u );
        x[u].push_back( i < K );
        x[v].push_back( i < K );
    }
    memset( color , -1 , sizeof(color) );
    ok = 1;
    for(int i = 0 ; i < N ; i++)if( color[i] == -1 && ok ){
        color[i] = 0;
        dfs( i );
    }
    puts((ok==1)?"YES":"NO");
}
 
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) doit();
}

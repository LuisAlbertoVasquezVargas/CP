#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

#define MAXN 50010

vector<pair<int,int > >adj[MAXN];
int N,K,a,b,d;

bool vis[MAXN],valid[MAXN];

/*bool dfs(int nodo){
    if(valid[nodo])return 1;
    vis[nodo]=1;
    bool ok=0;
    for(int i=0;i<adj[nodo].size();i++){
        int to=adj[nodo][i].first;
        if(!vis[to]){
            bool val=dfs(to);
            ok = ok || val;
        }
    }
    if(ok)valid[nodo]=1;
    return ok;
}*/

int f(int nodo){
    int sum=0;
    vis[nodo]=1;
    for(int i=0;i<adj[nodo].size();i++){
        int to=adj[nodo][i].first;
        if(!vis[to]&&valid[to]){
            int E=adj[nodo][i].second;
            sum+=2*E+f(to);
        }
    }
    return sum;
}

int getmax(int nodo){
    int maxi=0;
    vis[nodo]=1;
    for(int i=0;i<adj[nodo].size();i++){
        int to=adj[nodo][i].first;
        if(!vis[to]&&valid[to]){
            int E=adj[nodo][i].second;
            maxi=max(maxi,E+getmax(to));
        }
    }
    return maxi;
}

int m;

vector<int>adj1[MAXN];

void dfs(int nodo,int p){
    vis[nodo]=1;
    for(int i=0;i<adj[nodo].size();i++){
        int to=adj[nodo][i].first;
        if(!vis[to]){
            dfs(to,nodo);
            adj1[to].push_back(nodo);
        }
    }
}

void paint(int nodo){
    valid[nodo]=1;
    vis[nodo]=1;
    
    for(int i=0;i<adj1[nodo].size();i++){
        int to=adj1[nodo][i];
        if(!vis[to])paint(to);
    }
}

int main(){
    while(scanf("%d%d",&N,&K)==2){
        memset(valid,0,sizeof(valid));
        K--;
        for(int i=0;i<N;i++)adj[i].clear(),adj1[i].clear();
        for(int i=1;i<N;i++){
            scanf("%d%d%d",&a,&b,&d);
            a--;b--;
            adj[a].push_back(make_pair(b,d));
            adj[b].push_back(make_pair(a,d));
        }
        memset(vis,0,sizeof(vis));
        dfs(K,-1);
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&a);
            a--;
            valid[a]=1;
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++){
            if(valid[i]){
paint(i);
            }
        }
        memset(vis,0,sizeof(vis));
        int total=f(K);
        memset(vis,0,sizeof(vis));
        printf("%d\n",total-getmax(K));
        
    }
}

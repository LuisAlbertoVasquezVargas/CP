#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#define MAXN 50000
#define MAXM 100000
#define LMAXN 25
 
using namespace std;
 
int tc,n,a,b,k,m,q;
long long d;
vector< pair<int,long long> >v[MAXN];
struct edge
{
     int u,v,w;
     edge(){};
     edge(int _u,int _v,int _w)
     {
          u = _u;
          v = _v;
          w = _w;
     }     
};
bool cmp(edge e1,edge e2)
{
     return e1.w < e2.w;     
}
edge E[MAXM];
int P[MAXN][LMAXN];
long long D[MAXN][LMAXN];
int papi[MAXN];
int L[MAXN];
long long dis[MAXN];
bool visited[MAXN];
 
void dfs(int nodo)
{
     visited[nodo] = 1;
     for( int i = 0 ; i < v[nodo].size() ; ++i )
     {
          int son = v[nodo][i].first;
          if(!visited[son])
          {
               papi[son] = nodo;
               L[son] = L[nodo] + 1;
               dis[son] = dis[nodo] + v[nodo][i].second;
               dfs(son);
          }
     }
}
void getPapi()
{
     for( int i = 0 ; i < n ; ++i )
          P[i][0] = papi[i];
     for( int j = 1 ; (1<<j) < n ; ++j )
          for( int i = 0 ; i < n ; ++i )
               if(P[i][j-1]!=-1)
                    P[i][j] = P[P[i][j-1]][j-1];
 
     for( int i = 0 ; i < n ; ++i )
          if(papi[i]!=-1)
               D[i][0] = dis[i]-dis[papi[i]];
          else D[i][0] = dis[i];
     for( int j = 1 ; (1<<j) < n ; ++j )
          for( int i = 0 ; i < n ; ++i )
               if(P[i][j-1]!=-1)
                    D[i][j] = max(D[i][j-1],D[P[i][j-1]][j-1]);
}
int LCA( int p,int q)
{
     if( L[p] > L[q] ) swap(p,q);
     int dif = L[q] - L[p];
     for( int j = 16 ; j >= 0 ; j-- )
          if( dif >= (1<<j) )
          {
               q = P[q][j];
               dif -= (1<<j);
          }
     if( p == q )return p;
     for( int j = 16 ; j >= 0 ; --j )
          if( P[p][j] != P[q][j])
          {
               p = P[p][j];
               q = P[q][j];     
          }
     return papi[p];
}
int find_maxi_lca(int q,int lca)
{
     int dif = L[q] - L[lca];
     long long maxi1 = -1;     
     for( int j = 16 ; j >= 0 ; j-- )
          if( dif >= (1<<j) )
          {
               maxi1 = max(maxi1,D[q][j]);
               q = P[q][j];
               dif -= (1<<j);
          }          
     return maxi1;
}
int query(int p,int q)
{
     int lca = LCA(p,q);
     int maxi1 = find_maxi_lca(p,lca);
     int maxi2 = find_maxi_lca(q,lca);
     return max(maxi1,maxi2);
}
int parent[MAXN];
int rank[MAXN];
 
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
     bool ok = 0;
     while( scanf("%d%d",&n,&m) == 2 )
     {
          if(!ok)
               ok = !ok;
          else
               puts("");          
          for( int i = 0 ; i < n ; ++i )
               v[i].clear(),parent[i] = i,rank[i] = 1;
          memset(P,-1,sizeof(P));
          memset(D,0,sizeof(D));          
          memset(papi,-1,sizeof(papi));
          memset(L,0,sizeof(L));
          memset(dis,0,sizeof(dis));
          memset(visited,0,sizeof(visited));               
          for( int i = 0 ; i < m ; ++i )
          {
               scanf("%d %d %lld",&a,&b,&d);
               a--;b--;
               E[i].u = a;
               E[i].v = b;
               E[i].w = d;
          }
          sort(E,E+m,cmp);
 
          for( int i = 0 ; i < m ; ++i )
          {
               a = E[i].u,b = E[i].v ,d = E[i].w;
               if(Find(a)!=Find(b))
               {
                    v[a].push_back(make_pair(b,d));
                    v[b].push_back(make_pair(a,d));                    
                    Union(a,b);     
               }
          }
          dfs(0);
          getPapi();
          scanf("%d",&q);
          for( int i = 0 ; i < q ; ++i )
          {
               scanf("%d%d",&a,&b);
               a--;b--;
               printf("%d\n",query(a,b));
          }
     }
}

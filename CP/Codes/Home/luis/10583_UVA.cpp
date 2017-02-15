#include<iostream>
#include<vector>
#define MAXN 50000

using namespace std;
vector< int >adj[MAXN];
bool vis[MAXN];
int n,m,cont,it;
void dfs( int i )
{
     if(vis[i])return;
     vis[i] = 1;
     for( int j = 0 ; j < adj[i].size() ; ++j )
          dfs(adj[i][j]);     
}
int main()
{
     it = 0;
     while(1)
     {
          cin >> n >> m;
          if( n == 0 ) break;
          for( int i = 0 ; i < n ; ++i ) 
          {
               adj[i].clear();
               vis[i] = 0;
          }
          for( int i = 0 ; i < m; ++i )
          {
               int x , y ; 
               cin >> x >> y ;
               x--; y--; 
               adj[x].push_back(y);
               adj[y].push_back(x);
          }
          cont = 0;
          for( int i = 0 ; i < n ; ++i )
               if(!vis[i])
               {
                    dfs(i);
                    cont++;
               }
          cout<<"Case "<<++it<<": "<<cont<<endl;               
     }
}

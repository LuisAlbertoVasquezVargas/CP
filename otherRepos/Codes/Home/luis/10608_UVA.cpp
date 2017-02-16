#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAXN 30000

using namespace std;

vector<int>adj[MAXN];
bool vis[MAXN];
int cont,maxi;
void dfs( int i )
{
     if(vis[i])return;
     vis[i] = 1;
     cont++;
     for( int j = 0 ; j < adj[i].size(); ++j )
          dfs(adj[i][j]);
}
int main()
{
     int t ;
     cin >> t ;
     for( int k = 0 ; k < t ; k++ )
     {
          int n,m;
          cin >> n >> m ;
          for( int i = 0 ; i < n ; ++i )adj[i].clear();
          memset(vis,0,n*sizeof(bool));
          for( int i = 0 ; i < m ; ++i )
          {
               int x,y;
               cin>>x>>y;
               x--;y--;
               adj[x].push_back(y);
               adj[y].push_back(x);               
          }
          maxi = -( 1 << 30 );
          for( int i = 0 ; i < n ; ++i )
          {
               cont = 0;
               dfs(i);
               maxi = max( maxi ,cont );
          }
          cout<<maxi<<endl;
     }     
}

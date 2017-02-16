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

using namespace std;
vector<int>adj[100];
int color,cont[2];
bool vis[100],ok,colorn[100];
void dfs(int i,int color)
{
     if(vis[i])
     {
          if(colorn[i]!=color)ok=0;
          return;     
     }
     vis[i] = 1;
     cont[color]++;
     colorn[i] = color;
     int _n = adj[i].size();
     for( int j = 0 ; j < _n ; ++j )
          dfs(adj[i][j],1-color);
}
int main()
{
     int n,m;
     while( cin >> n >> m)
     {
          for( int i = 0 ; i < n ; ++i )
               adj[i].clear();
          memset(vis,0,sizeof(vis));
          memset(colorn,0,sizeof(colorn));          
          for( int i = 0 ; i < m ; ++i )
          {
               int x ,y ;
               cin >> x >> y;
               x--;y--;
               adj[x].push_back(y);
               adj[y].push_back(x);
          }
          int nodes_impares = 0;     
          int s = 0;
          for( int i = 0 ; i <  n ; ++i )
               if(!vis[i])
               {
                    cont[1] = cont[0] = color = 0;
                    ok = 1;
                    dfs(i,color);
                    int _n = cont[1]+cont[0];
                    if(_n%2==0 )continue;
                    else
                    {
                         if(!ok)
                         {
                              s++;     
                         }else 
                         {
                              nodes_impares++;
                         }
                    }
               }
          if(nodes_impares%2 == 1 )
               s++;
          cout<<s<<endl;
     }
}

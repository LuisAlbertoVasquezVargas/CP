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
#define MAXN 100

using namespace std;

int n;
int x[MAXN],y[MAXN];
vector< int >adj[MAXN];
int vis[MAXN];
void dfs(int i )
{
     if(vis[i])return;
     vis[i] = 1;
     for( int j = 0 ; j < adj[i].size(); ++j )
          dfs(adj[i][j]);
}
int main()
{
     while( cin >> n )
     {
          for( int i = 0 ; i < n ; ++i )
               cin >> x[i] >> y[i] ;    
          for( int i = 0 ; i < n ; ++i )
               adj[i].clear();
          memset(vis,0,sizeof(vis));
          for( int i = 0 ; i < n ; ++i )
               for( int j = i + 1 ; j < n ; ++j )
                    if((x[i]==x[j])||(y[i]==y[j]))
                    {
                         adj[i].push_back(j);
                         adj[j].push_back(i);
                    }
          int cont = 0;
          for( int i = 0 ; i < n ; ++i )
               if(!vis[i])
                    dfs(i),cont++;
          cout<<cont-1<<endl;
     }
}

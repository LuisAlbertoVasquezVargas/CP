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

#define MAXN 1000
#define MAXN1 100

using namespace std;

int n,m,u,v,d,nq,cap,src,des;
int price[MAXN];
vector< int > adj[MAXN];
vector< int > dist[MAXN];

struct nodo
{
     int ind , fuel , totalcost;
     nodo(){};
     nodo( int _ind , int _fuel , int _totalcost )
     {
          ind = _ind;
          fuel = _fuel;
          totalcost = _totalcost;
     }     
};
bool operator <(nodo p , nodo q)
{
     return p.totalcost > q.totalcost;     
}
int main()
{
     cin >> n >> m;
     for( int i = 0 ; i < n ; ++i )
          cin >> price[i];
     for( int i = 0 ; i < m ; ++i )
     {
          cin >> u >> v >> d;
          adj[u].push_back(v);
          adj[v].push_back(u);
          dist[u].push_back(d);
          dist[v].push_back(d);
     }
     cin >> nq;
     for( int i = 0 ; i < nq ; ++i )
     {
          cin >> cap >> src >> des;
          bitset<100> visited[n];
          bool ok = 0;
          
          priority_queue <nodo> Q;
          Q.push( nodo( src , 0 , 0) );
          
          while( !Q.empty() )
          {
               nodo q = Q.top();
               Q.pop();
               
               int ind = q.ind;
               int fuel = q.fuel;
               int totalcost = q.totalcost;
               if( visited[ind][fuel] )continue;
               if( ind == des )
               {
                    cout<<totalcost<<endl;
                    ok = 1; 
                    break;     
               }
               visited[ind][fuel] = 1;
               if( fuel < cap )
                    if( !visited[ind][fuel +1] )
                         Q.push( nodo(ind , fuel + 1 , totalcost + price[ind]) );
                         
               for( int i = 0 ; i < adj[ind].size() ; ++i )
                    if( fuel >= dist[ind][i] )
                    {
                         int nind = adj[ind][i];
                         int nfuel = fuel - dist[ind][i];
                         if( !visited[nind][nfuel] )
                              Q.push( nodo(nind , nfuel , totalcost ) );
                    }
          }
          if( !ok ) cout<<"impossible"<<endl;
     }
}

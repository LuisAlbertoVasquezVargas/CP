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
#include <cctype>
 
#define MAXN 1000
 
using namespace std;
 
int n = 0;
pair< int , int > P[MAXN];
vector< int >adj[MAXN];
int memo[MAXN];
int maxi,node;
int parent[MAXN];
int child[MAXN];
 
void init()
{
    memset( memo , -1 , sizeof(memo) );
        memset( parent , -1 , sizeof(parent) );
        memset( child , -1 , sizeof(child) );
        for( int i = 0 ; i < n ; ++i )
                for( int j = 0 ; j < n ; ++j )
                        if( P[i].first < P[j].first && P[i].second > P[j].second )
                                adj[i].push_back(j);
}
int dp( int pos )
{
        int nv = adj[pos].size();
        if( nv == 0 )return 1;
        if( memo[pos] != -1 )return memo[pos];
        int dev = 0,son = -1;
        for( int k = 0 ; k < nv ; ++k )
                if( 1 + dp(adj[pos][k]) > dev )
                {
                        dev = 1 + dp(adj[pos][k]);
                        son = adj[pos][k];      
                }
        parent[son] = pos;
        child[pos] = son;
        return memo[pos] = dev;
}
int main()
{
     while( cin >> P[n].first >> P[n++].second );
     n--;
        init();
        maxi = 0;
        for( int i = 0 ; i < n ; ++i )
                if( maxi < dp(i) )
                {
                        maxi = dp(i);
                        node = i;
                }
        cout << maxi << endl;
        while( node != -1 )
        {
                cout << node  + 1 << endl;
                node = child[node];                             
        }
}

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
 
using namespace std;
 
#define MAXN 100001
   
int tree[MAXN*4];
   
int n, q,c[MAXN];
   
void update( int node , int a , int b , int p , int val )
{
        if( b < p || p < a)     return ;
        if( a == b )
        {
                tree[node] = val;
                return;
        }
        update(2*node+1,a,(a+b)/2,p,val);
        update(2*node+2,(a+b)/2+1,b,p,val);
        tree[node] = min( tree[2*node + 1],tree[2*node+2]);
}
void init( int node , int a , int b )
{
        if( a == b )
        {
                tree[node] = c[a];
                return;
        }
        init(2*node +1 ,a,(a+b)/2);
        init(2*node+2,(a+b)/2+1,b);
        tree[node] = min(tree[2*node+1],tree[2*node+2]);
}
int query( int node , int a , int b , int p , int q )
{
        if( q < a || b < p )return INT_MAX;
        if( a >= p && b <= q )
                return tree[node];
        return min( query(2*node+1,a,(a+b)/2,p,q),query(2*node+2,(a+b)/2+1,b,p,q));    
}
int main()
{
    scanf("%d %d ", &n,&q);
    for(int i = 0 ; i < n ; i++ )
        scanf("%d", &c[i]);
    init(0, 0, n-1);
    char s[100];
    while(q--)
    {
                scanf("%s",s);
                if( s[0] == 'q' )
                {
                        int a1,a2;
                        int ns=strlen(s);
                        for( int j = 0 ; j < ns ; j++ )
                                if( !isdigit(s[j]) ) s[j]=' '; 
                               
                        istringstream in(s);
                        in>>a1>>a2;
                        printf("%d\n",query(0, 0,n-1, a1-1, a2-1));
                }
                else
                {
                        int ns=strlen(s);
                        for( int j = 0 ; j < ns ; j++ )
                                if( !isdigit(s[j]) ) s[j]=' ';
                                       
                        istringstream in(s);
                        vector<int> v;
                        int x;
                        while(in>>x) v.push_back(x-1);
 
                        int nw = v.size();
                        vector<int>w;
                        for(int k = 0 ; k < nw ; k++ )
                                w.push_back(c[v[k]]);
                        for( int k = 1 ; k < nw ; k++)
                        {
                                update(0,0,n-1,v[k-1],w[k]);   
                                c[v[k-1]] = w[k];
                        }
                        update(0,0,n-1,v[nw-1],w[0]);
                        c[v[nw-1]] = w[0];
                }              
        }
}

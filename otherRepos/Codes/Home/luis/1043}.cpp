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

#define MAXN 100000

using namespace std;

struct node
{
	int maxSum,maxSumL,maxSumR,Sum;
	node(){}	
} tree[MAXN*4];
int c[MAXN] , lo , hi , n  , q ;

void init( int node , int a , int b )
{
        if( a == b )
        {
                tree[node].sum = c[a];
                tree[node].maxSum = max( 0 , c[a]);
                tree[node].maxSumL = max( 0 , c[a]);
                tree[node].maxSumR = max( 0 , c[a]);
                return;
        }
        init(2*node +1 ,a,(a+b)/2);
        init(2*node+2,(a+b)/2+1,b);
        tree[node].maxSum = max( max(tree[2*node+1].maxSum , tree[2*node+2].maxSum ), tree[2*node+1].maxSumR , tree[2*node+2].maxSumL );      
	   tree[node].maxSumL = max( tree[2*node + 1].maxSumL , tree[2*node + 1].sum +tree[2*node + 2].maxSumL );
	   tree[node].maxSumR = max( tree[2*node + 2].maxSumR , tree[2*node + 2].sum +tree[2*node + 1].maxSumR );	   
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
}
int query( int node , int a , int b , int p , int q )
{
        if( q < a || b < p )return INT_MIN;
        if( a >= p && b <= q )
                return tree[node].maxSum;
        return max( query(2*node+1,a,(a+b)/2,p,q),query(2*node+2,(a+b)/2+1,b,p,q));    
}
int main()
{
	scanf( "%d" , &n ) ;
	for( int i = 0 ; i < n ; ++i )
		scanf( "%d" , &c[i] );
     init(0, 0, n-1);
	scanf( "%d" , &q );	
	while( q-- )
	{
		scanf( "%d%d" , &lo , &hi );
		lo--;hi--;
     	printf( "%d\n" , query(0, 0,n-1, lo, hi) ) ;        
	{
}

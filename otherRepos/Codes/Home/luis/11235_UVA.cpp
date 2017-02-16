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
#define LOGMAX 21

using namespace std;

int a[MAXN],L[MAXN],R[MAXN],A[MAXN],M[MAXN][LOGMAX];
int n,q,x,y,m,Sz,nL,nR;
map<int,int>MP;

void procced(){
    for(int i=0;i<Sz;i++)M[i][0]=-A[i];
    for(int j=1;(1<<j)<=Sz;j++){
        for(int i=0;i+(1<<j)-1<Sz;i++){
            if(M[i][j-1]<M[i+(1<<(j-1))][j-1]) 
                M[i][j]=M[i][j-1];
            else M[i][j]=M[i+(1<<(j-1))][j-1];
        }
    }    
}
 
int query(int xx,int yy){
    if( yy < xx ) swap( xx , yy );
    int r = yy - xx + 1;
    int k = (30-__builtin_clz(r));
    while( (1<<k) <= r ) k++;
    k--;
    if(  M[xx][k]  < M[yy - (1<<k) + 1 ][ k ]  ) 
        return M[xx][k];
    return M[yy - (1<<k) + 1 ][ k ];
}
int BS( int k )
{
	int lo = 0 ;
	int hi = Sz - 1;	
	//// 11100 caso tipico
	//// 00011 Imposible
	//// 00000 por condiciones del problema no se puede
	//// 11111 caso tricky
	if( L[hi] <= k )
		return hi ;
	while( hi - lo > 1 )
	{
		int med = lo + ( hi - lo )/2;
		if( L[med] <=  k )
			lo = med;
		else hi = med;
	}
	return lo;
}

int f( int a , int b )
{
	int ini = BS(a);
	int fin = BS(b);

	if( a == L[ini] && b == R[fin] )
		return -query(ini,fin);
	else if( a == L[ini] && b != R[fin] )
	{
		if( ini == fin )
			return b - a + 1;
		return max(-query(ini,fin-1),b - L[fin]+1);
	}
	else if( a != L[ini] && b == R[fin] )
	{
		if( ini == fin )
			return b - a + 1;
		return max( R[ini]-a+1, -query(ini+1,fin) );
	}
	else
	{
		if( ini == fin )
			return b - a +1;
		else if( ini + 1 == fin )
			return max(R[ini]-a+1,b - L[fin]+1);
		return max( max( R[ini]-a+1 , b - L[fin]+1 ) , -query(ini+1,fin-1) );
	}
}
int main()
{
     while( cin >> n )
     {
		if( n == 0 ) return 0;
		MP.clear();
		cin >> m;
          
		for( int i = 0 ; i < n ; ++i )
               cin >> a[i], MP[a[i]]++;
          Sz = unique(a,a+n) - a;
          for( int i = 0 ; i < Sz ; ++i )
			A[i] = MP[a[i]];
		procced();
		nL = 0;
		for( int i = 0 ; i < Sz ; ++i )
		{
			L[i] = nL;
			nL += A[i];
			R[i] = nL - 1;
		}
          for( int i = 0 ; i < m ; ++i )
          {
			cin >> x >> y;
			cout << f(x-1,y-1) <<endl;
		}
     }
}

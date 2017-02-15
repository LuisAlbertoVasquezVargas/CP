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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define MAXN 20005

using namespace std;

int n , op , u , v ;
int id[MAXN];

int F(int x) {
	if( x != id[x] && id[x] != -1 )
		return id[x] = F( id[x] );
	return x;
}
void U(int x, int y) {
	int p = F(x) , q = F(y); 
	if( q < p )swap( p ,q );
	id[p] = q;
}
int E( int x ){ return x + 10000; }

int main()
{
	while( sc( n ) == 1 )
	{
		me( id , -1 );
		while( scanf( "%d%d%d" , &op , &u , &v ) == 3 )
		{
			if( op == 0 )break;
			if( op == 1 )
			{
				if( F(u) == F( E(v) ) )
				{
					puts("-1");
					continue;	
				}
				U(u,v);
				U(E(u),E(v));
			}
			else if( op == 2 )
			{
				if( F(u) == F( v ) )
				{
					puts("-1");
					continue;	
				}		
				U(u,E(v));
				U(v,E(u));		
			}
			else if( op == 3 )
			{
				if( F(u) == F(v) )
					puts("1");
				else	puts("0");
			}
			else if( op == 4 )
			{
				if( F(u) == F(E(v)) )
					puts("1");
				else	puts("0");				
			}
		}
	}
}

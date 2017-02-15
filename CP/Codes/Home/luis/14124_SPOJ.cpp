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

#define N 205
#define D 100

using namespace std;

int n;
bool T[N];
int main()
{
	while( sc( n ) == 1 )
	{
		if( n == 0 )break;
		int x , pos;
		me( T , 0 );
		for( int i = 0 ; i < n ; ++i )
			sc( x ) , T[x+D] = 1;
		for( int i = N - 1 ; i >= 0 ; --i )
			if( T[i] )
			{
				pos = i ;
				break;
			}
		for( int i = pos - 1 ; i >= 0 ;  --i )
			if( T[i] )
			{
				printf( "%d\n" , i - D );
				break;	
			}
	}
}

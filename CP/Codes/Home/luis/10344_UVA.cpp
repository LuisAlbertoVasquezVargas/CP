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

#define N 5

using namespace std;

int a[N];
bool ok;
string s = "+-*";

int f( int x ,int y , int t )
{
	if( s[t] == '+' )
		return x + y;
	if( s[t] == '-' )
		return x - y;
	return x * y;
}

void doit()
{
	for( int i = 0 ; i < 3 ; ++i )
		for( int j = 0 ; j < 3 ; ++j )
			for( int k = 0 ; k < 3 ; ++k )
				for( int m = 0 ; m < 3 ; ++m )
				{
					int ans = f( a[0] , a[1] , i );
					ans = f( ans , a[2] , j );
					ans = f( ans , a[3] , k );
					ans = f( ans , a[4] , m );
					if( ans == 23 )
					{
						ok = 1;
						return;
					}
				}	
}
int main()
{
        while( scanf( "%d" , &a[0] ) == 1 )
        {
	        for( int i = 1 ; i < N ; ++i )
		        scanf( "%d" , &a[i] );
		if( a[0] == 0 )
			break;
		sort( a , a + N );
		ok = 0;
		do
		{
			doit();
			if( ok ) break;
		}while( next_permutation(a,a+N) );
		if( ok )
			puts("Possible");
		else 	puts("Impossible");
        }
}

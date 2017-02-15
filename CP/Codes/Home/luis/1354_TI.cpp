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

#define N 20005

using namespace std;

int n, m;
char s[N],a[N];
int F[N];

void init()
{	
	F[0] = -1;
	for( int t = 1 ; t <= n ; ++t )
	{
		int pos = F[t-1];
		while( pos != -1 && s[pos] != s[t-1] )
			pos = F[pos];
		F[t] = 1 + pos;	
	}
}
int main()
{
	while( scanf( "%s" , s ) == 1 )
	{
		m = strlen( s );
		strcpy( a , s );
		reverse( s , s + m );
		if( strcmp( a , s ) == 0 )
		{
			n = strlen( s );
			init();						
			printf( "%s" , s);
			for( int i = m-F[n]-1 ; i >= 0 ; --i )
				printf( "%c" , a[i] );
			puts("");			
			continue;	
		}
		strcat( s , "$" );		
		strcat( s , a );
		n = strlen( s );	
		init();		
		for( int i = 0 ; i < m ; ++i )
			printf( "%c" , a[i] );
		for( int i = m-F[n]-1 ; i >= 0 ; --i )
			printf( "%c" , a[i] );
		puts("");
	}
}

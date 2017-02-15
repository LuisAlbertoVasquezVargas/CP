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

#define N 1000005

using namespace std;

int n;
char s[N];
int F[N];
void init( )
{
	F[0] = -1;
	for( int t = 1 ; t <= n ; ++t )
	{
		int pos = F[t-1];
		while( pos != -1 && s[t-1] != s[pos] )
			pos = F[pos];
		F[t] = 1 + pos;	
	}	
}
int main()
{
	while( scanf( "%s" , s ) == 1 )
	{
		if( s[0] == '.' )break;
		n = strlen(s);
		init();
		printf( "%d\n" , n/(n - F[n]) );
	}
}

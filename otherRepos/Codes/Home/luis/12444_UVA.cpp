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

#define MAXB 32

using namespace std;

int n , tc , x , y ;

void f( int c , int d )
{
	int ans = 0,a = 0,b = 0;
	for( int i = MAXB - 1 ; i >= 0 ; --i )
	{
		bool C = ( ((1<<i)&c) > 0 ), D = ( ((1<<i)&d) > 0 );
		if( C == 0 && D == 0 ) continue;
		if( C == 1 && D == 1 )
		{
			a += (1<<i);
			b += (1<<i);						
			continue;	
		}
		if( C > D )
		{
			puts("-1");
			return;	
		}
		if( ans > 0 )
		{
			ans -=(1<<i);
			a += (1<<i);
		}
		else
		{
			ans += (1<<i);
			b += (1<<i);
		}
	}
	cout << min( a, b ) << " " << max( a , b ) << "\n";
}

int main()
{
	cin >> tc;
        while( tc-- )
        {
		cin >> x >> y;
		f( x , y );
        }
}

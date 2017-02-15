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

#define N 15

using namespace std;

int n;
int a[N];
int memo[N][N];

int dp( int pos , int last )
{
	if( pos == n + 1 )return 0;
	int &dev = memo[pos][last];
	if( dev == -1 )
	{
		dev = dp( pos + 1 , last );
		if( a[pos] > a[last] )
			dev = max( dev , 1 + dp( pos + 1 , pos ) );
	}
	return dev;	
}
int main()
{
	a[0] = 0;
        while( cin >> n )
        {
	        for( int i = 1 ; i <= n ; ++i )
		        cin >> a[i];
		memset( memo , -1 , sizeof( memo ) );
		cout << dp( 1 , 0 ) << endl;
        }
}

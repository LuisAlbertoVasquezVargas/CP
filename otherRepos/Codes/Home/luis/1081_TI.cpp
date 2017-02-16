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

#define N 50

using namespace std;

int n , k;
int memo[N][2];

int dp( int pos , int last )
{
	if( pos == n )return 1;
	int &dev = memo[pos][last];
	if( dev == -1 )
	{
		if( last )
			dev = dp( pos + 1 , 0 );
		else 	dev = dp( pos + 1 , 0 ) + dp( pos + 1 , 1 );
	}
	return dev;	
}
int main()
{
        while( cin >> n >> k )
        {
		memset( memo , -1 , sizeof( memo ) );
		if( dp(0,0) < k )
		{
			puts("-1");
			continue;	
		}
		string ans(n,'0');
		int last = 0 ;
		for( int i = 0 ; i < n ; ++i )
		{
			if( last == 1 )
			{
				last = 0;
				continue;
			}
			if( dp(i+1,0) < k )
				ans[i] = '1' , k -= dp(i+1,0);
			else 	ans[i] = '0' ;
			last = ans[i] - '0';
			if( k == 0 )break;			
		}

		cout << ans << endl;
        }
}

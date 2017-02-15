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
#include <cstring>

using namespace std;

int n , memo[ 1<<21 ];
int dp( int mask )
{
	if( mask == 0 ) return 0;
	int &dev = memo[ mask ];
	if( dev == -1 )
	{
		dev = 0;
		for( int i = 0 ; i < n - 1; ++i )
			if( mask&(1<<i) )
			{
				if( !(mask&(1<<(i+1) )) )
				{
					if( i == n - 2 )
					{
						if( !dp( mask^(1<<i) ) ) return dev = 1;
					}
					else if( !dp( mask^(1<<i)^(1<<(i+1)) ) ) return dev = 1;
				}
			}
		for( int i = 0 ; i + 3 < n ; ++i )
			if( mask&(1<<i) )
			{
				if( mask&(1<<(i+1)) )
				{
					if( mask&(1<<(i+2)) )
					{
						if( (mask&(1<<(i+3))) == 0 )
						{
							if( i + 3 == n - 1 )
							{
								if( !dp( mask^(1<<i) ) ) return dev = 1;
							}
							else if( !dp( mask^(1<<i)^(1<<(i+3)) ) ) return dev = 1;
						}
					}
				}
			}
	}
	return dev;
}
class EllysCheckers {
public:
	string getWinner(string v ) {
		n = v.size();
		int mask = 0;
		for( int i = 0 ; i < n - 1 ; ++i )
			if( v[i] == 'o' ) mask ^=(1<<i);
		memset( memo , -1 , sizeof( memo ) );
		return dp( mask )?"YES":"NO";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

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
#define MAXM 13
#define MAXALPHA 27
#define INF (1<<30)

using namespace std;

int nS, nT ;
string S;
string T[MAXM];
int memo[MAXN][MAXALPHA+1];

int dp( int pos , int lastC )
{
	if( pos == nS )return 0;
	int &dev = memo[pos][lastC];
	if( dev == -1 )
	{
		dev = 1 + dp( pos+1 , lastC );
		bool ok = 0;
		for( int i = 0 ; i < nT ; ++i )
		{
			if( S[pos] == T[i][0] && lastC +'a' == T[i][1] )
			{
				ok = 1;
				break;
			}
			swap( T[i][0] , T[i][1] );
			if( S[pos] == T[i][0] && lastC +'a' == T[i][1] )
			{
				ok = 1;				
				swap( T[i][0] , T[i][1] );
				break;
			}
			swap( T[i][0] , T[i][1] );
		}
		if( !ok )
			dev = min( dev , dp( pos + 1 , S[pos] - 'a' ) );		
	}
	return dev;
}
int main()
{
        while( cin >> S >> nT )
        {
		nS = S.size();
	        for( int i = 0 ; i < nT ; ++i )
		        cin >> T[i];
		memset( memo , -1 , sizeof( memo ) );
		cout << dp(0,27) << "\n";
        }
}

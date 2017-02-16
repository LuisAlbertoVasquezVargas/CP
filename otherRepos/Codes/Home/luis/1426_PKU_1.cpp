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

#define MAXN 100
#define MAXM 200

using namespace std;

int n;
bool ok;
int memo[ MAXN + 1 ][ MAXM ];

int dp( int pos , int mod )
{
	if( pos == MAXN )return 0;
	if( pos != 0 && mod == 0 ) return 1;
	int &ret = memo[pos][mod];
	if( ret == -1 )
		ret = dp( pos + 1 , (mod*10+1)%n ) || dp( pos + 1 , (mod*10)%n );
	return ret;
}
void f( int pos , int mod , string s )
{
	if( ok == 1 )return;
	if( pos != 0 && mod == 0 )
	{
		cout << s << "\n";
		ok = 1;
	}
	else if( dp( pos , mod ) )
	{
		if( dp( pos + 1 , (mod*10+1)%n ) )
			f( pos + 1 , (mod*10+1)%n , s + "1" );
		if( dp( pos + 1 , (mod*10)%n ) )
			f( pos + 1 , (mod*10)%n , s + "0" );
	}
}
void solve()
{
	memset( memo , -1 , sizeof( memo ) );
	dp(0,0);
	ok = 0;
	f(0,0,"");	
}
int main()
{
        while( cin >> n )
        {
		if( n == 0 )return 0;
		solve();
        }
}

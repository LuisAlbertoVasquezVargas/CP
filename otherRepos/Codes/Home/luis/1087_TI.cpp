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

#define MAXN 10000
#define MAXM 50

using namespace std;

int n,m;
int memo[MAXN];
int a[MAXM];

bool dp( int pos )
{
	if( pos == 0 )return 1;
	if( memo[pos] != -1 )return memo[pos];
	bool ok = 0;
	int cnt = 0;
	for( int k = 0 ; k < m ; ++k )
		if( pos - a[k] >= 0 )
			ok  = ok || !( dp( pos - a[k]) ),cnt++;
	if( cnt == 0 )
		return memo[pos] = 1;		
	return memo[pos] = ok;
}
int main()
{
     while( cin >> n >> m )
     {
          for( int i = 0 ; i < m ; ++i )
               cin >> a[i];
          memset( memo , -1 , sizeof( memo ) );
          cout << 2 - dp( n ) << endl ;
     }
}

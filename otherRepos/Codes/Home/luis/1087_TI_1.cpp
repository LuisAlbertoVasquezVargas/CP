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

int n , m;
int v[MAXM];
int memo[MAXN+1];
bool dp( int pos )
{
	if( pos == v[0] )return 0;
	if( pos < v[0] ) return 1;
	if( memo[pos] != -1 )return memo[pos];
	bool ok = 0;
	for( int i = 0 ; i < m ; ++i )
		if( pos - v[i] >= 0 )
			ok |= (!dp(pos-v[i]));
	return memo[pos] = ok;
}
int main()
{
     while( cin >> n >> m )
     {
          for( int i = 0 ; i < m ; ++i )
               cin >> v[i];
          memset( memo , -1 , sizeof( memo ) );
          sort( v , v + m );
          cout << 2 - dp(n) << endl;
     }
}

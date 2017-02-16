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

#define N 10

using namespace std;

string S , T;
int ns , nt;
int a[N];
int memo[N][N];

int dp( int pos1 , int pos2 )
{
	if( pos1 == ns || pos2 == nt )return 0;
	int &dev = memo[pos1][pos2];
	if( dev == -1 )
	{
		if( S[pos1] == T[pos2] )
			dev = 1 + dp( pos1 + 1 , pos2 + 1 );
		else dev = max( dp( pos1 + 1 , pos2 ) , dp( pos1 , pos2 + 1 ) );
	}
	return dev;
}
int main()
{
        while( cin >> S >> T )
        {
		ns = S.size();
		nt = T.size();
		memset( memo , -1 , sizeof( memo ) );
		cout << dp( 0 , 0 ) << endl;
        }
}

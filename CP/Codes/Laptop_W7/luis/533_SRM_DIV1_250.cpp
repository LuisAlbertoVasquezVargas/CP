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

#define all(v)  v.begin() , v.end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define clr(t,val) memset( t , val , sizeof(t) )

#define N 55
#define INF (1<<30)

int n;
int memo[ N ][ N ];
vi W;
int dp( int L , int R )
{
	if( R - L == 1 ) return 0;
	if( R - L == 2 ) return W[ L ]*W[ R ];
	int &dev = memo[ L ][ R ];
	if( dev == -1 )
	{
		dev = 0;
		for( int k = L  + 1 ; k < R ; ++k )
			dev  = max( dev , W[ L ]*W[ R ] + dp( L , k ) + dp( k , R ) );
	}
	return dev;
}
class CasketOfStar {
public:
	int maxEnergy( vi v ) {
		W = v;
		n = v.size();
		clr( memo , -1 );
		return dp( 0 , n - 1 );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

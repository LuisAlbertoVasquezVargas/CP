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
 
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define MAXN 100
#define MOD 1000000007

typedef long long ll;

int memo[ MAXN + 5 ][ MAXN + 5 ];
int n , m , p;

int dp( int pos , int played ){
	if( pos == p ) return played == n;
	int &dev = memo[ pos ][ played ];
	if( dev == -1 ){
		dev = 0;
		dev = ( ( ll ) dp( pos + 1 , played + 1 ) * ( ll )( n - played ) )%MOD;
		if( played >= m ) dev += ( ( ll ) ( played - m ) * ( ll ) dp( pos + 1 , played ) )%MOD;
		if( dev >= MOD ) dev -= MOD;
	}
	return dev;
}
class NoRepeatPlaylist {
public:
	int numPlaylists(int N, int M, int P) {
		clr( memo , -1 );
		n = N , m = M , p = P;
		return dp( 0 , 0 );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

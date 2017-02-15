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
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define INF (1<<30)

typedef vector< int > vi;
typedef long long ll;

class PackingBallsDiv1 {
public:
	int minPacks(int K, int A, int B, int C, int D) {
		vi X( K );
		X[ 0 ] = A;
		for( int i = 1 ; i < K ; ++i ){
			ll x = X[ i - 1 ];
			x = ( x * B + C ) %D + 1;
			X[ i ] = x;
		}
		int ans = 0 , mini = INF , sum = 0;
		vi mod( K );
		REP( i , K ) ans += X[ i ]/K , mod[ X[ i ] % K ]++;
		for( int k = K - 1 ; k >= 0 ; --k ){
			mini = min( mini , k + sum );
			sum += mod[ k ];
		}
		return ans + mini;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

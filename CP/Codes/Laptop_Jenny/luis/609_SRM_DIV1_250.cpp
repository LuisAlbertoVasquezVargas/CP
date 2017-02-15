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

#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)

#define N 100005

class MagicalStringDiv1 {
public:
	int getLongest(string S) {
		int n = S.size() , ans = 0;
		REP( k , n + 1 ){
			int ind = -1 , cnt = 0;
			REP( i , n ) 
				if( cnt == k ) break;
				else{
					if( S[ i ] == '>' ) cnt++ , ind = i;
				}
			if( cnt != k ) continue;
			cnt = 0;
			for( int i = ind + 1 ; i < n ; ++i )
				if( cnt == k ) break;
				else{
					if( S[ i ] == '<' ) cnt++ , ind = i;
				}
			if( cnt == k ) ans = max( ans , 2*k );
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!

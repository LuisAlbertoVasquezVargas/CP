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
#define all( v ) v.begin() , v.end()


class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
		int n = A.size();
		string s = A , t = B;
		sort( all( s ) ) , sort( all( t ) );
		if( s != t ) return -1;
		int ans = n;
		for( int i = n - 1 ; i >= 0 ; i-- )
			if( A[ i ] == B[ ans - 1 ] )
			{
				ans--;
			}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

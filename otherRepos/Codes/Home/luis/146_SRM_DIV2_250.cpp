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

int B[10];
class YahtzeeScore {
public:
	int maxPoints(vector <int> A) {
		for( int i = 0 ; i < 5 ; ++i )
			B[A[i]]++;
		int maxi = 0;
		for( int i = 0 ; i < 7; ++i )
			maxi = max( maxi , i*B[i] );
		return maxi;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

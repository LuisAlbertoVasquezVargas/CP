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


class TheArithmeticProgression {
public:
	double minimumChange(int a, int b, int c) {
		return min( min( abs( 2.0*b - c - a ) , abs( ( c + a )/2.0 - b )  ) , abs( 2.0*b - a - c ) );
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

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

long long a[N];

int main()
{
        while( cin >> a[0] >> a[1] >> a[2] )
        {
		if( a[0] == 0 )return 0;
		sort( a , a + 3 );
		if( a[0]*a[0] + a[1]*a[1] == a[2]*a[2] )
			puts("right");
		else puts("wrong");
        }
}

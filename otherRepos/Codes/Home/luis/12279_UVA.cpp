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

using namespace std;

int n ,tc ,t = 0 ;

int main()
{
	while( cin >> n )
        {
		if( n == 0 )break;
		vector< int >v(n);
	        for( int i = 0 ; i < n ; ++i )
		        cin >> v[i];
		int k = count( v.begin() ,v.end() , 0 );
		cout << "Case " << ++t << ": " << n - 2*k << endl;
        }
}

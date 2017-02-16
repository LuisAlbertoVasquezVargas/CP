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

int n,x,t;
int main()
{
     while( cin >> n )
     {
		if( n == 0 )return 0;
		x = 0;
          for( int i = 0 ; i < n ; ++i )
               cin >> t , x^=t;
          if( x == 0 )
          	cout << "No" << endl;
          else cout << "Yes" << endl;
     }
}

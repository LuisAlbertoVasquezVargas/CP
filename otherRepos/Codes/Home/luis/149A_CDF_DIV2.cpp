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

int x,y,a,b;

int main()
{
     while( cin >> x >> y >> a >> b )
     {
		vector< pair < int , int > >v;
          for( int i = a ; i <= x ; ++i )
			for( int j = b ; j <= y ; ++j )
				if( i > j )v.push_back( make_pair(i,j) );
		int nv = v.size() ;
		sort( v.begin() , v.end() );
		cout << nv << endl; 
		for( int k = 0 ; k < nv ; ++k )
			cout << v[k].first << " " << v[k].second << endl;
     }
}

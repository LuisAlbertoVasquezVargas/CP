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


class Pricing {
public:
	int maxSales( vector <int> v ) 
	{
		int nv = v.size();
		int maxi = 0;
		sort( v.begin() , v.end() );
		for( int i = 0 ; i < nv ; ++i )
			for( int j = i ; j < nv ; ++j )
				for( int k = j ; k < nv ; ++k )
					for( int L = k ; L < nv ; ++L )
					{
						int sum = 0 ;
						for( int t = 0 ; t < nv ; ++t )
							if( v[t] >= v[L] )
								sum += v[L];
							else if( v[t] >= v[k] )
								sum += v[k];
							else if( v[t] >= v[j] )
								sum += v[j];
							else if( v[t] >= v[i] )
								sum += v[i];
						maxi = max( maxi , sum );
					}
			return maxi ;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

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
#define all(v)  v.begin() , v.end()
using namespace std;


class MNS {
public:
	int combos(vector <int> v ) {
		sort( all(v) );
		int Cnt = 0;
		do
		{
			int sum = accumulate( v.begin() , v.begin() + 3 , 0 );
			int cnt = 0;
			int M[3][3];
			for( int i = 0 ; i < 9 ; ++i )
				M[i/3][i%3] = v[i];
			for( int i = 0; i < 3 ; ++i )
			{
				int sum1 = 0;
				for( int j = 0 ; j < 3 ; ++j )
					sum1 += M[i][j];
				cnt += sum1 == sum;
			}
			for( int i = 0; i < 3 ; ++i )
			{
				int sum1 = 0;
				for( int j = 0 ; j < 3 ; ++j )
					sum1 += M[j][i];
				cnt += sum1 == sum;
			}	
			if( cnt == 6 )
				Cnt++;
		}while( next_permutation( all(v) ) );
		return Cnt;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

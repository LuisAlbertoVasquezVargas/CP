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

long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
string f( string t )
{
	int n = t.size() , cnt = 0;
	string s;
	for( int i = n - 1 ; i >= 0 ; --i )
	{
		if( cnt == 3 )
		{
			s = ',' + s;
			cnt = 0;
		}
		s = t[i] + s;
		cnt++;
	}
	return s;
}
class FormatAmt {
public:
	string amount(long long dollars, long long cents) 
	{
		long long T = dollars*100 + cents;
		if( dollars == 0 && cents == 0 )
			return "$0.00";
		if( dollars == 0 && cents < 10 )					
			return "$0.0" + tos(cents);
		if( dollars == 0 )
			return "$0." + tos( cents );
		string s = tos( T );
		int n = s.size();
		string t = s.substr( n - 2 );
		return "$" + f( s.substr(0,n-2) ) + "." + t;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

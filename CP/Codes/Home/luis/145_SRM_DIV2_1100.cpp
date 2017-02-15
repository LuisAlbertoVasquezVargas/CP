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

#define N 100

using namespace std;
int n , m;
long long M[ N ][ N ];
int x[ N ] , y[ N ] , minute[ N ];
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int f( int x )
{
	return min( x , m - x );
}
int find_p()
{
	int best = -1 , pos = -1;
	for( int j = 0 ; j < m ; ++j )
	{
		int sum = 0;
		for( int i = 0 ; i < n ; ++i )
			sum += M[i][j];
		if( sum > best )
		{
			best = sum ;
			pos = j;
		}
	}
	return pos;
}	
class VendingMachine {
public:
	int motorUse(vector <string> P, vector <string> S ) 
	{
		int nS =  S.size();
		n = P.size() ;
		for( int i = 0 ; i < n ; ++i )
		{
			istringstream in(P[i]);
			int j = 0;
			string t;
			while( in >> t )
				M[i][j++] = toi(t);
			m = j;
		}
		int pos = find_p();
		int t = f(pos);
		minute[ 0 ] = 0;
		minute[ nS + 1] = 1<<30;
		for( int i = 0 ; i < nS ; ++i )
		{
			S[i][S[i].find(":")] = 	S[i][S[i].find(",")] = ' ';
			stringstream in( S[i] );
			in >> x[i+1] >> y[i+1] >> minute[i+1];
			if( M[x[i+1]][y[i+1]] == 0 )return -1;
			if( minute[i+1] - minute[i] >= 5 )
			{
				t += f( abs(pos - find_p()) );			
				pos = find_p();
				t += f( abs(pos - y[i+1]) );
				pos = y[i+1];
			}
			else
			{
				t += f( abs(pos - y[i+1]) );
				pos = y[i+1];				
			}
			M[x[i+1]][y[i+1]] = 0;
		}
		t += f( abs(pos - find_p()) );					
		return t;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

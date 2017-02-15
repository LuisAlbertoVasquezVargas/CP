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

#define SIZE 13
string R[SIZE] = { "I" , "IV", "V" , "IX" , "X" , "XL" ,"L" , "XC","C" , "CD" , "D" , "CM" ,"M" };
int P[SIZE] = {     1,     4 ,   5 ,   9,    10 ,  40 ,  50 ,  90 , 100 , 400 , 500 , 900 , 1000 };
int f( string s )
{
	int ns = s.size();
	if( ns == 0 ) return 0;
	if( ns == 1 ){
		for( int i = 12 ; i  >= 0 ; --i )
			if( R[i].size() == 1 && R[i][0] == s[0] ) return P[i];
	}
	for( int i = 12 ; i  >= 0 ; --i )
		if( R[i].size() == 1 ){
			if( R[i][0] == s[0] ) return P[i] + f( s.substr( 1 ) );
		}
		else{
			if( R[i][0] == s[0] && R[i][1] == s[1] ) return P[i] + f( s.substr( 2 ) );
		}
}
bool cmp( string s1 , string s2 )
{
	istringstream in1( s1 ) , in2( s2 );
	string a1 , b1 , a2, b2;
	in1 >> a1 >> b1  ,in2 >> a2 >> b2;
	if( a1 != a2 ) return a1 < a2;
	return f( b1 ) < f( b2 );
}
class KingSort {
public:
	vector <string> getSortedList(vector <string> kings) {
		sort( kings.begin() , kings.end() , cmp );
		return kings;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

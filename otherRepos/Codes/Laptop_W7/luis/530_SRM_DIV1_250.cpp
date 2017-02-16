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

#define vs vector <string>
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>

using namespace std;

int n , m , N , M ;

bool f( int x ,int y , vs &S , vs &T )
{
	for( int i = 0 ; i < N ; ++i )
		for( int j = 0 ; j < M ; ++j )
			if( T[i][j] == '.' && S[x+i][y+j] != '.' )return 0;
	return 1;
}
void doit( int x ,int y , vs &S , vs &T )
{
	for( int i = 0 ; i < N ; ++i )
		for( int j = 0 ; j < M ; ++j )
			if( T[i][j] == '.' )S[x+i][y+j] = 'X';
}
class GogoXCake {
public:
	string solve( vs S, vs T ) 
	{
		n = S.size() , m = S[0].size();
		N = T.size() , M = T[0].size();
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < m ; ++j )
				if(  i + N <= n && j + M <= m && f( i , j , S , T ) )doit( i , j , S , T );
		string s = accumulate( all(S) , string("") );
		return (count(all(s),'X')==(n*m))?"YES":"NO";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
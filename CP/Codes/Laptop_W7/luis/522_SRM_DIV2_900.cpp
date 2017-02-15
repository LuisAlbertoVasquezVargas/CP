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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second

#define N 105
#define MOD 1000000007
#define INF (1e100)
#define EPS (1e-5)

using namespace std;

class CorrectMultiplicationTwo {
public:
	int getMinimum(int a, int b, int c) {
		int ans = a + b + c;
		for( int A = 1 ; A <= a + ans ; ++A )
			for( int B = 1 ; B <= (c + ans)/A ; ++B )	
				ans = min( ans , abs( A - a ) + abs( B - b ) + abs( A*B - c ) );
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

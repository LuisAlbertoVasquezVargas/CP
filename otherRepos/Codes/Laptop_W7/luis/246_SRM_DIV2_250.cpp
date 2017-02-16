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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

using namespace std;

vector <string> f( vector <string> v )
{
	int nv = v.size();
	for( int i = 0 ; i < nv ; ++i )
	{
		int nvv = v[i].size();
		string temp;
		for( int j = 0 ; j < nvv ; ++j )
		{
			if( v[i][j] == ' ' )continue;
			if( isdigit( v[i][j] ) )temp += v[i][j];
			else temp += '.';
		}
		v[i] = temp;
	}
	return v;
}
class CalcTest {
public:
	vector <string> uniform(vector <string> numbers) {
		return f(numbers);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
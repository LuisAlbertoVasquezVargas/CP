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
#define INF (1<<30)
using namespace std;


class BasketsWithApples {
public:
	int removeExcess(vector <int> v ) {
		int nv = v.size();
		map< int , int >M;
		for( int i = 0 ; i < nv ; ++i )
			M[v[i]]++;
		sort( all(v) );
		int best = 0;
		for( int i = 0 ; i < nv ; ++i )
			best = max( best , v[i]*(nv-i) );
		return best;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
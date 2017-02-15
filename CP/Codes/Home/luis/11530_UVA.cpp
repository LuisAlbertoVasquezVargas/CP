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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string S = "abcdefghijklmnopqrstuvwxyz ";
string V = "123123123123123123412312341";
map< char , int >M;
int n;
string s;
int main()
{
	int nS = S.size();
	for( int i = 0 ; i < nS ; ++i )
		M[ S[i] ] = V[i] - '0';
	while( cin >> n )
	{
		getline( cin , s );
		for( int i = 0 ; i < n ; ++i )
		{
			int cnt = 0 ;
			getline( cin , s );
			FOR( o , s )cnt += M[*o];
			cout << "Case #" << i + 1 << ": " << cnt << endl;
		}
	}
}

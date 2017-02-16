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

#define MAXN 100000
#define N 105
using namespace std;

////////////////
string s;
vector<string> ans;
int L , t[N][30];

int f( int x, int last ){
	if( x == s.size() ) return 0;
	int &ret = t[x][last];
	if( ret != -1 ) return ret;
	ret = f( x + 1 , last );
	if( s[x] - 'a' >= last ) ret = max( ret , 1 + f( x + 1 , s[x] - 'a' ) );
	return ret;
}

void g(int x , int last , string sol){
	if( x == s.size() ){
		cout << sol << endl;
		return;
	}
	int r = f( x , last );
	if( r == f( x + 1 , last ) ) g( x + 1 , last , sol );
	if( (s[x] - 'a') >= last && r == 1 + f( x + 1 , s[x] - 'a' ) ) g( x + 1 , (s[x] - 'a') , sol + s[x] );
}

void solve(){
	memset( t , -1 , sizeof(t) );
	L = f( 0 , 0 );
	ans.clear();
	g( 0 , 0 , "" );
}

int main()
{	
	int tc;
	cin >> tc;
	while( tc-- )
	{
		cin >> s;
		solve();
		cout << '\n';
	}
}

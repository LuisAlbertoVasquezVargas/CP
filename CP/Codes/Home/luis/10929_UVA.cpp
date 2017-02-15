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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define N 100005

using namespace std;

string s;

int main()
{
	while( cin >> s )
	{
		if( s == "0" )break;
		int cnt = 0;
		reverse( all(s) );
		for( int i = 0 ; i < s.size() ; ++i )
			cnt = ( 11 + cnt + (s[i]-'0')*(i%2==0?1:10) )%11;
		reverse( all(s) );			
		if( cnt %11 == 0 )
			cout << s << " is a multiple of 11." << endl;
		else	cout << s << " is not a multiple of 11.\n";
	}
}

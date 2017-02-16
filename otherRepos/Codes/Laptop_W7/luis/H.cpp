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
//13

string R[] = { "I" , "IV", "V" , "IX" , "X" , "XL" ,"L" , "XC","C" , "CD" , "D" , "CM" ,"M" };
int P[] = {     1,     4 ,   5 ,   9,    10 ,  40 ,  50 ,  90 , 100 , 400 , 500 , 900 , 1000 };
ll toi( string s ){ istringstream is(s) ; ll x ; is>>x;return x;}
int n;
string cad, S , T;
int f( string s )
{
	int sign = 1;
	int ns = s.size();
	if( s[ns-2] == 'B' )
		return -toi( s.substr( 0 , ns - 2 ) ) + 754;
	return toi( s.substr( 0 , ns - 2 ) ) + 753;
}
string g( int k )
{
	for( int i = 12 ; i >= 0 ; --i )
		if( P[i] == k ) return R[i];
		else if( P[i] < k )return R[i] + g( k - P[i] );
}
int main()
{
	freopen( "roman.in" , "r" , stdin );
	freopen( "roman.out" , "w" , stdout );
	while( cin >> cad )
	{
		int ncad = cad.size();
		for( int i = 0 ; i < ncad ; ++i )
			if( cad[i] == '-' ) cad[i] = ' ';
		istringstream in(cad);
		in >> S >> T;
		int ini = f( S ) , fin = f( T );
		int maxi = 0;
		for( int i = ini ; i <= fin ; ++i )
		{
			string rom = g( i );
			//cout << i << " " << rom << endl;
			maxi = max( maxi , (int)rom.size() );
		}
		cout << maxi << endl;
	}
}

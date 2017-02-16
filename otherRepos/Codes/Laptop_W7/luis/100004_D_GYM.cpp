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

#define N 100005
#define MOD 1000000007

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
#define test puts("test");

using namespace std;

string S;
map< char , char >M;
bool f( string s )
{
	string t = s;
	reverse( all( t ) );
	return t == s;	
}
void doit()
{
	string t = S;
	transform( all( t ) , t.begin() , ::toupper );
	//cout << t << endl;
	for( int i = 0 ; i < t.size() ; ++i )
		t[i] = M[t[i]];
	//cout << t << endl;		
	if( f(t) )
		puts("YES");
	else	puts("NO");
}
int main()
{
	M['A'] = M['B'] = M['C'] = '2'; 
	M['D'] = M['E'] = M['F'] = '3';
	M['G'] = M['H'] = M['I'] = '4';
	M['J'] = M['K'] = M['L'] = '5';
	M['M'] = M['N'] = M['O'] = '6';
	M['P'] = M['Q'] = M['R'] = M['S'] = '7';
	M['T'] = M['U'] = M['V'] = '8';
	M['W'] = M['X'] = M['Y'] = M['Z'] = '9';
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n ; 
	for( int i = 0 ; i < n ; ++i )cin >> S , doit();
}

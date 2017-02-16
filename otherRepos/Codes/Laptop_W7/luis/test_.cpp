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

string I , F ;
int M[] = {0,31,28,31,30,31,30,31,31,30,31,30,31,0};
string f( string s )
{
	int ns = s.size();
	for( int i = 0 ; i < ns ; ++i )
		if( !isdigit( s[i] ) ) s[i] = ' ';
	return s;
}
bool bis( int year )
{
	return ( (year %4 == 0) && (year %100 != 0) )||(year%400==0);
}
int g( int year , int month , int day )
{
	int days = 0;
	for( int a = 1900 ; a < year ; ++a )days += 365 + bis( a );
	for( int m = 1 ; m < month ; ++m )
		if( m == 2 && bis(year) )days += 29 ;
		else days += M[m];
	return days + day;
}
int main()
{
	while( cin >> I >> F ) 
	{
		I = f( I ) ,F = f( F );
		int dia[2] , mes[2] , ano[2];
		istringstream in1(I);
		in1 >> ano[0] >> mes[0] >> dia[0];
		istringstream in2(F);
		in2 >> ano[1] >> mes[1] >> dia[1];
		cout << abs( g( ano[1] , mes[1] , dia[1] ) - g( ano[0] , mes[0] , dia[0] ) ) << endl;
	}
}

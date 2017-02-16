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
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

#define N 100005
#define MOD 1000000007

using namespace std;

ll n , t , m ;
bool ok;
void doit()
{
	cin >> n >> t >> m;
	if( !ok )cout << endl;	
	else	ok^=1;
	vector< pair< pair< ll , ll> , ll > >v( m );

	map< int , int >M;
	for( int i = 0 ; i < m ; ++i )
	{
		ll time ;
		string s;
		cin >> time >> s;
		v[i] = make_pair( make_pair( time , s != "left" ) , i );
	}
	ll c = 0 , C[2] , T = 0 , turn = 0 , i = 0 , j = 0;
	me( C , 0 );
	while( 1 )
	{
		if( c == 0 && C[0] == 0 && C[1] == 0 && T > v[m-1].first.first )break;
		while( i < m && v[i].first.first <= T )
		{
			C[v[i].first.second]++;
			i++;
		}
		c = min( n ,C[turn] );
		if( C[0] > 0 || C[1] > 0 )
		{
			C[turn] -= c;
			T += t;
			turn^=1;
			for( int k = 0 ; k < c ; k++ )M[v[j++].second] = T;
			c = 0;
		}else T++;
	}
	for( int i = 0 ; i < m ; ++i )cout << M[i] << endl;
}	

int main()
{
	ios_base::sync_with_stdio( 0 );
	ok = 1;
	int tc ;
	cin >> tc;
	while( tc-- )
		doit();
}

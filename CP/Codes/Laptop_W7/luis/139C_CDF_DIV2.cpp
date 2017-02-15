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
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , x , y ;
vector< string >S;
int v[N] , w[N] , memo[N][N][2];

/// last = 0 , .     1 , #
int dp( int pos , int cnt ,int last )
{
	if( pos == m )return ((cnt >= x)?0:INF);
	int &dev = memo[pos][cnt][last];
	if( dev == -1 )
	{
		dev = INF;
		int temp = w[pos];
		if( (last == 0) && (cnt + 1 <= y)  )
			dev = min( dev , temp + dp( pos + 1 , cnt + 1 , 0 ) );
		else if( (last == 1) && (cnt >= x && cnt <= y) )
			dev = min( dev , temp + dp( pos + 1 , 1 , 0 ) );
		temp = v[pos];
		if( (last == 1) && (cnt + 1 <= y)  )
			dev = min( dev , temp + dp( pos + 1 , cnt + 1 , 1 ) );
		else if( (last == 0) && (cnt >= x && cnt <= y) )
			dev = min( dev , temp + dp( pos + 1 , 1 , 1 ) );
	}
	return dev;
}
int main()
{
	sync
	while( cin >> n >> m >> x >> y )
	{
		S.resize( n );
		for( int i = 0 ; i < n ; ++i )cin >> S[i];
		me( v , 0 );
		me( w , 0 );
		for( int j = 0 ; j < m ; ++j )
			for( int i = 0 ; i < n ; ++i )
				v[j] += S[i][j] == '.' , w[j] += S[i][j] != '.';
		me( memo , -1 );
		cout << min( dp( 0 , 0 , 0 ) , dp( 0 , 0 , 1 ) ) << endl;
	}
}

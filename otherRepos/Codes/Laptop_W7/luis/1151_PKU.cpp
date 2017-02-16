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
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

pair< double , double > X[ N ] , Y[ N ];
double x[N] , y[N];

bool f( pair< double , double > p , int i )
{
	if( p.fi >= X[i].fi && p.fi <= Y[i].fi && p.se >= X[i].se && p.se <= Y[i].se  )
		return 1;
	return 0;
}
int main()
{
	int n , tc = 0;
	while( scanf( "%d" , &n ) == 1 )
	{
		if( n == 0 )return 0;
		REP( i ,  n )scanf( "%lf%lf%lf%lf" , &X[i].fi , &X[i].se , &Y[i].fi , &Y[i].se );
		int it =  0;
		REP( i , n )
		{
			x[ it ] = X[i].fi;
			y[ it++ ] = X[i].se;
			x[ it ] = Y[i].fi;
			y[ it++ ] = Y[i].se;
		} 
		sort( x , x + it );
		sort( y , y + it );
		int nx = unique( x , x + it ) - x ;
		int ny = unique( y , y + it ) - y ;

		double ans = 0;
		pair< double , double >P[4];
		REP( j , ny - 1 )REP( i , nx - 1 )
		{
			P[0] = mp( x[i] , y[j] );
			P[1] = mp( x[i] , y[j+1] );
			P[2] = mp( x[i+1] , y[j] );
			P[3] = mp( x[i+1] , y[j+1] );
			bool solve = 0;
			REP( k , n )
			{
				int cnt = 0;
				REP( t , 4 )cnt += f( P[t] , k );
				if( cnt == 4 )
				{
					solve = 1;

					break;
				}
			}
			
			if( solve )ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
		}

		printf( "Test case #%d\nTotal explored area: %.2lf\n\n" , ++tc , ans );
	}
}


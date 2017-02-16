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

#define N 10005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , mini , maxi;
int V[ N ] , memo[ N ];

int G( int x )
{
	if( x < mini )return 0;
	if( x > maxi )return 0;
	int &dev = memo[ x ];
	set<int> S;
	if( dev == -1 )
	{
		REP( i , n ) S.insert( G( x - V[i] ) );
		REP( i , x + 5 )
			if( !S.count( i ) )
			{
				dev = i;
				break;
			}
	}
	return dev;
}
int main()
{
	while( sc( n ) == 1 && n )
	{
		clr( memo , -1 );
		mini = INF , maxi = -INF;
		REP( i , n )
		{
			sc( V[i] ) ;
			mini = min( mini , V[i] );
			maxi = max( maxi , V[i] );
		}
		test
		REP( k , 1000 )cout << " " <<  G( k );
		puts("");
		int t;
		sc( t );
		REP( i , t )
		{
			int L , r = 0 , x ;
			sc( L );
			REP( j , L ) sc( x ) , r ^= G( x );
			printf( r?"W":"L" );
		}
		puts("");
	}
}



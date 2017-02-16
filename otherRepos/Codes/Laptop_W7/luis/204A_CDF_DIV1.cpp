#include <bits/stdc++.h>

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

#define N 2005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ 2*N ], B[ 2*N ];

int main()
{
	int n;
	while( sc( n ) == 1 )
	{
		int nint = 0 , ndou , Sum = 0;
		REP( i , 2*n )
			scanf( "%d.%d" , &A[ i ] , &B[ i ] ) , nint += (!B[i]) , Sum += B[ i ];
		ndou = 2*n - nint;
		int ans = INF;
		for( int k = 0 ; k <= ndou ; ++k )
		{
			int dif = abs( ndou - 2*k );
			if( dif <= nint )
				ans = min( ans , abs( 1000*(ndou - k ) - Sum ) );
		}
		printf( "%.3lf\n" , ans/1000.0 );
	}
}



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

#define N 105
#define INF (1<<30)

using namespace std;

int A[N];
int memo[N*N];
int n , m;
int dp( int cur )
{
	if( cur == 0 )return 0;
	if( cur < A[0] ) return INF;
	int &dev = memo[ cur ];
	if( dev == -1 )
	{
		dev = INF;
		REP( i , n )
			dev = min( dev , 1 + dp( cur - A[i] ) );
	}
	return dev;
}

int main()
{
	int tc;
	sc( tc );
	while( tc -- )
	{
		clr( memo , -1 );
		sc( n ) , sc( m );
		REP( i , n ) sc( A[i] );
		sort( A , A + n );
		int ans = INF;
		if( m >= 10000 )
		{
			for( int i = 0 ; i <= 100 ; ++i )
				ans = min( ans , m/A[n-1] - i + dp( i*A[n-1] + m%A[n-1]) );
		}
		else
			ans = min( ans , dp( m ) );
		if( ans >= INF )
			puts( "-1" );
		else printf( "%d\n" , ans );
	}
}



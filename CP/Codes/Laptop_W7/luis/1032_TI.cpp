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

#define N 10004
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ] , last[ N ] , F[ N ];
int n;

void solve()
{
	REP( i , n )
		if( A[i]%n == 0 )
		{
			printf("1\n%d\n" , A[i] );
			return;
		}
	clr( last , -1 );
	F[0] = 0;
	for( int i = 0 ; i < n ; ++i )
		F[ i + 1 ] = ( F[ i ] + A[ i ] )%n;
	REP( i , n + 1 )
		if( last[F[i]] == -1 )
			last[F[i]] = i;
		else
		{
			printf( "%d\n" , i - last[F[i]] );
			for( int j = last[F[i]] + 1 ; j <= i ; ++j )
				printf( "%d\n" , A[j-1] );
			return;
		}
	puts("0");
}
int main()
{
	while( sc( n ) == 1 )
	{
		REP( i , n )sc( A[i] );
		solve();
	}
}



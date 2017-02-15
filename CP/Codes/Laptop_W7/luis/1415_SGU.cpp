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
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , x ;
int A[N];
int memo[N*N];

int dp( int cur )
{
	if( cur == 0 )return 1;
	if( cur < A[0] )return 0;
	int &dev = memo[ cur ];
	if( dev == -1 )
	{
		dev = 0;
		REP( i , n )
			if( cur - A[i] >= 0 )
				dev += dp( cur - A[i] );
	}
	return dev;
}
int main()
{
	sc( n ) , sc( x );
	REP( i , n ) sc( A[i] );
	sort( A , A + n );
	clr( memo , -1 );
	int F = dp( x );
	vi V;
	REP( i , n )
		if( dp( x - A[i] ) == F )V.pb( A[i] );
	int nV = V.size();
	printf( "%d\n" , nV );
	REP( i , nV )
		printf( "%d%s" , V[i] , (i+1==nV?"\n":" ") );
}



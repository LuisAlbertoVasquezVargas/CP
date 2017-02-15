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

#define N 205
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , x ,ford;
int A[N];
//http://ideone.com/GUlMLL
//int memo[N*N][N][N];

int DP[ 10005 ][N];
/*
int dp( int cur , int pos , int ford )
{
	if( pos == n )return cur == 0;
	int &dev = memo[ cur ][ pos ][ ford ];
	if( dev == -1 )
	{
		dev = dp( cur , pos + 1 , ford );
		if( (pos != ford) && cur - A[pos] >= 0 )
			dev += dp( cur - A[pos] , pos + 1 , ford );
	}
	return dev;
}
*/
int main()
{
	sc( n ) , sc( x );
	REP( i , n ) sc( A[i] );
	sort( A , A + n );
	//clr( memo , -1 );
	/*
	for( int ford = 0 ; ford <= n ; ++ford )
		for( int pos = n - 1 ; pos >= 0 ; pos-- )
			for( int cur = 0 ; cur <= 10000 ; cur ++ )
			{
				int &dev = DP[ cur ][ pos ][ ford ] = DP[ cur ][ pos + 1 ][ ford ];
				if( (pos != ford) && cur - A[pos] >= 0 )
					dev += DP[ cur - A[pos] ][ pos + 1 ][ ford ];
			}
	*/
	ford = n;
	for( int cur = 0 ; cur <= 10000 ; ++cur )
		DP[cur][n] = cur == 0;
	for( int pos = n - 1 ; pos >= 0 ; pos-- )
		for( int cur = 0 ; cur <= 10000 ; cur ++ )
		{
			int &dev = DP[ cur ][ pos ] = DP[ cur ][ pos + 1 ];
			if( (pos != ford) && cur - A[pos] >= 0 )
				dev += DP[ cur - A[pos] ][ pos + 1 ];
		}
	int F = DP[ x ][ 0 ];
	//cout << F << endl;
	vi V;
	REP( i , n )
	{
		ford = i;
		for( int cur = 0 ; cur <= 10000 ; ++cur )
			DP[cur][n] = cur == 0;
		for( int pos = n - 1 ; pos >= 0 ; pos-- )
			for( int cur = 0 ; cur <= 10000 ; cur ++ )
			{
				int &dev = DP[ cur ][ pos ] = DP[ cur ][ pos + 1 ];
				if( (pos != ford) && cur - A[pos] >= 0 )
					dev += DP[ cur - A[pos] ][ pos + 1 ];
			}
		if( DP[ x - A[i] ][ 0 ] == F )V.pb( A[i] );	
	}
	int nV = V.size();
	printf( "%d\n" , nV );
	REP( i , nV )
		printf( "%d%s" , V[i] , (i+1==nV?"\n":" ") );
}



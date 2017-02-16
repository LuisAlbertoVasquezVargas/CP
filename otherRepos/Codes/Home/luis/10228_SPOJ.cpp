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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int tc , n , m ;
int DP[ 2 ][ N ], S[ N ][ N ];
/*
int DP[ N ][ N ] , S[ N ][ N ];

int memo[ N ][ N ] , S[ N ][ N ];

int dp( int x , int y )
{
	if( x == n - 1 && y == m - 1 )return 1;
	int &dev = memo[ x ][ y ];
	if( dev == -1 )
	{
		dev = INF;
		if( x + 1 < n ) dev = min( dev , max( 1 , -S[x][y] + dp( x + 1 , y ) ) );
		if( y + 1 < m ) dev = min( dev , max( 1 , -S[x][y] + dp( x , y + 1 ) ) );
	}
	return dev;
}
*/
int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n ) , sc( m );
		REP( i , n )REP( j , m ) sc( S[i][j] );
		//clr( memo , -1 );
		/*
		DP[n-1][m-1] = 1;
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = m - 1 ; j >= 0 ; --j )
			{
				if( i == n - 1 && j == m - 1 ) continue;
				int &dev = DP[i][j] = INF;
				if( i + 1 < n ) dev = min( dev , max( 1 , -S[i][j] + DP[ i + 1 ][ j ] ) );
				if( j + 1 < m ) dev = min( dev , max( 1 , -S[i][j] + DP[ i ][ j + 1 ] ) );
			}
		printf( "%d\n" , DP[0][0] );
		*/
		DP[(n-1)&1][m-1] = 1;
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = m - 1 ; j >= 0 ; --j )
			{
				if( i == n - 1 && j == m - 1 ) continue;
				int &dev = DP[i&1][j] = INF;
				if( i + 1 < n ) dev = min( dev , max( 1 , -S[i][j] + DP[ (i + 1)&1 ][ j ] ) );
				if( j + 1 < m ) dev = min( dev , max( 1 , -S[i][j] + DP[ i&1 ][ j + 1 ] ) );
			}
		printf( "%d\n" , DP[0][0] );
	}
}




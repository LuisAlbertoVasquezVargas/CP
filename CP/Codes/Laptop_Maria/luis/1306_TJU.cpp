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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 4
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , maxi ;
char S[ N + 4 ][ N + 4 ];
/// X  . O
int f()
{
	int cnt = 0;
	REP( i , n )REP( j , n ) cnt += ( S[i][j] == 'O' );
	return cnt;
}
bool val()
{
	REP( i , n )REP( j , n )
		if( S[i][j] == 'O' )
		{
			for( int k = i - 1 ; k >= 0 ; --k )
				if( S[k][j] == 'X' )break;
				else if( S[k][j] == 'O' )return 0;
			for( int k = j - 1 ; k >= 0 ; --k )
				if( S[i][k] == 'X' )break;
				else if( S[i][k] == 'O' )return 0;
			for( int k = i + 1 ; k < n ; ++k )
				if( S[k][j] == 'X' )break;
				else if( S[k][j] == 'O' )return 0;
			for( int k = j + 1 ; k < n ; ++k )
				if( S[i][k] == 'X' )break;
				else if( S[i][k] == 'O' )return 0;
		}
	return 1;
}
void dfs( int x , int y )
{
	if( x == n - 1 && y == n )
	{
		if( val() )maxi = max( maxi , f() );
		return ;
	}
	if( y == n )
	{
		dfs( x + 1 , 0 );
		return;
	}
	if( S[x][y] == '.' )
	{
		dfs( x , y + 1 );
		S[x][y] = 'O';
		dfs( x , y + 1 );
		S[x][y] = '.';		
	}else dfs( x , y + 1 );
}
int main()
{
	while( sc( n ) == 1 && n )
	{
		REP( i , n ) scanf( "%s" , S[i] );
		maxi = 0;
		dfs( 0 , 0 );
		printf( "%d\n" , maxi );
	}
}



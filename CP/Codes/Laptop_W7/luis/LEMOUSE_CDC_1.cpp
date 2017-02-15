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
 
#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
 
using namespace std;
 
int n , m ;
int memo[N][N][3];
char S[N][N];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
 
int dp( int x , int y , int last )
{
	if( x == n - 1 && y == m - 1 )return 0;
	int &dev = memo[x][y][last];
	if( dev == -1 )
	{
		dev = INF;
		int cnt = 0;
		REP( k , 4 )
		{
			if( !last && k == 1 )continue;
			if( last && k == 3 )continue;
			int nx = x + dx[k] , ny = y + dy[k];
			if( nx >= 0 && nx < n && ny >= 0 && ny < m )
				cnt += S[nx][ny] == '1';
		}
		if( x + 1 < n )
			dev = min( dev , cnt + ((last==0&&y&&S[x+1][y-1]=='1')?-1:0) + dp( x + 1 , y , 1 ) );
		if( y + 1 < m )
			dev = min( dev , cnt + ((last==1&&x&&S[x-1][y+1]=='1')?-1:0) + dp( x , y + 1 , 0 ) );
	}
	return dev;
}
 
int main()
{
	int tc;
	scanf( "%d" , &tc );
	while( tc -- )
	{
		scanf( "%d%d" , &n , &m );
		REP( i , n )scanf( "%s" , S[i] );
		me( memo , -1 );
		printf( "%d\n" , dp( 0 , 0 ,0 ) );
	}	
}


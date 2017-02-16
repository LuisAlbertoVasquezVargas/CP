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

int n, m ;
int memo[N][N][3];
string S[N];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

int dp( int x , int y , int last )
{
	if( x == n - 1 && y == m - 1 )return 0;
	int &dev = memo[x][y][last];
	if( dev == -1 )
	{
		dev = INF;
		if( x + 1 < n )
		{
			int cost = 0;
			if( last == 0 )
				REP( k , 4 )
				{
					int nx = x + 1 + dx[k], ny = y + dy[k];
					if( nx == x && ny == y )continue;
					if( nx >= 0 && nx < n && ny >= 0 && ny < m && S[nx][ny] == '1' )cost++;
				}
			else
				REP( k , 4 )
				{
					int nx = x + 1 + dx[k], ny = y + dy[k];
					if( k%2 == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m && S[nx][ny] == '1' )cost++;
				}
			dev = min( dev , cost + dp( x + 1 , y , 0 ) ); 
		}
		if( y + 1 < m )
		{
			int cost = 0;
			if( last == 0 )
				REP( k , 4 )
				{
					int nx = x + dx[k], ny = y + 1 + dy[k]; 
					if( nx == x && ny == y )continue;
					if( k%2 == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m && S[nx][ny] == '1' )cost++;
				}
			else
				REP( k , 4 )
				{
					int nx = x + dx[k], ny = y + 1 + dy[k];
					if( nx == x && ny == y )continue;
					if( nx >= 0 && nx < n && ny >= 0 && ny < m && S[nx][ny] == '1' )cost++;
				}
			dev = min( dev , cost + dp( x , y + 1 , 1 ) ); 
		}
	}
	return dev;
}
int main()
{
	sync
	int tc;
	cin >> tc;
	while( tc -- )
	{
		cin >> n >> m;
		REP( i , n ) cin >> S[i];
		me( memo , -1 );
		int temp = (S[0][0] == '1') + (S[0][1] == '1') + (S[1][0] == '1');
		int ans = dp( 0 , 0 , 0 );
		if( ans >= INF ) ans = 0 , temp = 0;
		cout << temp + ans << endl;
	}
}



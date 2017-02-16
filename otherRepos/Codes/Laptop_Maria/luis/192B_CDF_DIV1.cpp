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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m ;
string S[ N ];
int dist[ N ][ N ];
int dx[] = { 0 ,0  , 1 , -1 };
int dy[] = { 1 , -1 , 0 ,0 };

int main()
{
	sync
	while( cin >> n >> m )
	{
		REP( i , n )cin >> S[i] ;
		REP( i , n )REP( j , m ) dist[i][j] = INF;
		pii s , e;
		int ans = 0;
		queue< pii >Q;
		REP( i , n )REP( j , m )
			if( S[i][j] == 'E' )
			{
				Q.push( mp( i , j ) );
				dist[ i ][ j ] = 0;
				e = mp( i , j );
			}
			else if( S[i][j] == 'S' )
				s = mp( i , j );	
		while( !Q.empty() )
		{
			pii node = Q.front();
			Q.pop();
			int x = node.fi , y = node.se;
			REP( k , 4 )
			{
				int nx = x + dx[k] , ny = y + dy[k];
				if( nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INF && S[nx][ny] != 'T' )
				{
					Q.push( mp( nx , ny ) );
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
		int t = dist[s.fi][s.se];
		REP( i , n )REP( j , m )
			if( S[i][j] >= '1' && S[i][j] <= '9' && dist[i][j] <= t )
				ans += S[i][j] - '0';
		printf( "%d\n" , ans );
	}
}



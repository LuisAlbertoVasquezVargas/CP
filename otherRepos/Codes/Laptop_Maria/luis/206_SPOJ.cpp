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

#define N 200
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tc ;
string S[N];

int dx[] = { 0 , 0  , 1 , -1 };
int dy[] = { 1 , -1 , 0 ,  0 };

int main()
{
	sync
	cin >> tc;
	while( tc -- )
	{
		cin >>n >> m;
		REP( i , n )cin >> S[i];
		vvi D( n , vi(m , INF) );
		queue< pii >Q;
		REP( i , n )REP( j , m )
			if( S[i][j] == '1' )
			{
				Q.push( mp( i , j ) );
				D[i][j] = 0;
			}
		while( !Q.empty() )
		{
			pii node = Q.front();
			Q.pop();
			int x = node.fi , y = node.se;
			REP( k , 4 )
			{
				int nx = x + dx[k] , ny = y + dy[k];
				if( nx >= 0 && nx < n && ny < m && ny >= 0 && D[nx][ny] == INF )
				{
					Q.push( mp( nx , ny ) );
					D[nx][ny] = D[x][y] + 1;					
				}
			}
		}
		REP( i , n )
			REP( j , m )
				printf( "%d%s" , D[i][j] , (j+1==m?"\n":" ") );
	}
}



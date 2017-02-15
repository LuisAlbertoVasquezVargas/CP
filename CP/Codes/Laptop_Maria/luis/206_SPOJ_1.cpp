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

#define N 205
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tc;
int D[ N ][ N ];
char s[ N ][ N ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };

int main()
{
	sc( tc );
	while( tc-- )
	{
		scanf( "%d%d" , &n , &m );
		REP( i , n )scanf( "%s" , s[i] );
		queue< pii >Q;
		REP( i , n )REP( j , m )
		{
			if( s[i][j] == '1')
				Q.push( mp( i , j) ) , D[i][j] = 0;
			else D[i][j] = INF;
		}
		while( !Q.empty() )
		{
			pii node = Q.front();
			Q.pop();
			REP( k , 4 )
			{
				int nx = node.fi + dx[k] , ny = node.se + dy[k];
				if( nx >= 0 && nx < n && ny >= 0 && ny < m && D[nx][ny] == INF )
				{
					Q.push( mp( nx , ny ) );
					D[nx][ny] = D[node.fi][node.se] + 1;
				}
			}
		}
		REP( i , n )REP( j , m ) printf( "%d%s" , D[i][j] ,(j+1==m?"\n":" ") );
	}
}


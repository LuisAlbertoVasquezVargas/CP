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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int H , W , n , cnt ;
vvi vis;
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 ,0 , 0 };
set< pair< pii , pii > >S;
void dfs( int x , int y )
{
	vis[x][y] = 1;
	cnt++;
	for( int k = 0 ; k < 4 ; ++k )
	{
		int nx = x + dx[k] , ny = y + dy[k];
		if( nx >= 0 && nx < W && ny >= 0 && ny < H && !vis[nx][ny]  && !S.count( mp( mp( x , y ) , mp( nx , ny ) ) ) )
			dfs( nx , ny );
	}
}
int main()
{
	while( cin >> W >> H >> n )
	{
		S.clear();
		vis = vvi( W , vi( H , 0 ) );
		REP( i , n )
		{
			int Xi , Yi , Xf , Yf;
			cin >> Xi >> Yi >> Xf >> Yf;
			if( Xi == Xf )
			{
				for( int i = min(Yi,Yf) ; i < max(Yi,Yf) ; ++i )
				{
					S.insert( mp( mp( Xi , i ) , mp( Xi - 1 , i ) ) );
					S.insert( mp( mp( Xi - 1 , i ) , mp( Xi , i ) ) );
				}
			}
			else
			{
				for( int i = min(Xi,Xf) ; i < max(Xi,Xf) ; ++i )
				{
					S.insert( mp( mp( i , Yi - 1 ) , mp( i , Yi ) ) );
					S.insert( mp( mp( i , Yi ) ,  mp( i , Yi - 1 ) ) );
				}
			}
		}
		vi ans;
		REP( i , W )
			REP( j , H )
			{
				if( !vis[i][j] )
				{
					cnt = 0;
					dfs( i , j );
					ans.pb( cnt );
				}
			}
		sort( all( ans ) );
		int nA = ans.size();
		for( int i = 0 ; i < nA ; ++i )
			cout << ans[i] << (i+1==nA?"\n":" ");
	}
}



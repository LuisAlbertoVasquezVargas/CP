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
#define INF (1<<23)
#define EPS (1e-5)

using namespace std;

int n , m;
int dy[] = { 1 , -1 };

int main()
{
	sync
	while( cin >> n >> m )
	{
		vector< string >S(n);
		vvi D( n , vi( m , INF ) );
		REP( i , n ) cin >> S[i];
		int mini = INF;
		queue< pii >Q;
		REP( i , n )REP( j , m )
			if(S[i][j] == '1')
			{
				Q.push( mp(i,j) );
				D[i][j] = 0;
			}
		while( !Q.empty() )
		{
			pii node = Q.front();
			int x = node.fi , y = node.se;
			Q.pop();
			REP( k , 2 )
			{
				int nx = x;
				int ny = (y + dy[k] + m)%m;
				if( D[nx][ny] == INF )
				{
					D[nx][ny] = D[x][y] + 1 ;
					Q.push( mp( nx , ny ) );					
				}
			}
		}
		REP( j , m )
		{
			int sum = 0;
			REP( i , n )
				sum += D[i][j];
			mini = min( mini , sum );
		}
		if( mini >= INF )puts("-1");
		else cout << mini << endl;
	}
}



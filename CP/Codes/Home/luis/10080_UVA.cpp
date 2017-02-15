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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m ;
vi E[ N ];
int match[ N ] , vis[ N ];

bool dfs( int u )
{
	if( vis[ u ] )return 0;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( match[ *v ] == -1 || dfs( match[ *v ] ) )
		{
			match[ *v ] = u;
			return 1;
		}
	return 0;
}

int bpm()
{
	int cnt = 0;
	clr( match , -1 );
	REP( i , n )
		clr( vis , 0 ) , cnt += dfs( i );
	return cnt;
}
pair< double , double >P[ N ] , Q[ N ];

int main()
{
	int time , vel;
	while( scanf( "%d%d%d%d" , &n , &m , &time , &vel ) == 4 )
	{
		double cte = time*vel;
		cte *= cte;
		REP( i , n )scanf( "%lf%lf" , &P[i].fi , &P[i].se );
		REP( i , m )scanf( "%lf%lf" , &Q[i].fi , &Q[i].se );
		REP( i , n )E[i].clear();
		REP( i , n )REP( j , m )
		{
			double dx = P[i].fi - Q[j].fi , dy = P[i].se - Q[j].se;
			double dist = dx*dx + dy*dy;
			if( dist <= cte )
				E[i].pb(j);
		}
		printf( "%d\n" , n - bpm() );
	}
}




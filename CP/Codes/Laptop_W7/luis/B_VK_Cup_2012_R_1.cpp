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

int main()
{
	int n , k;
	while( cin >> n >> k )
	{
		vector< pii > v, w;
		int cost , t;
		REP( i , n )
		{
			cin >> cost >> t;
			if( t == 1 )
				v.pb( mp( cost , i ) );
			else w.pb( mp( cost , i ) );
		}
		sort( rall( v ) );
		sort( rall( w ) );
		int nv = v.size() , nw = w.size();
		double ans = 0;
		vector< vector< pair< pii , int > > > V( k );
		REP( i , nv )
			V[ min( i , k - 1 ) ].pb( mp( mp( v[i].fi , 1 ) ,v[i].se ) );
		if( nv >= k - 1 )
		{
			REP( i , nw )
				V.back().pb( mp( mp( w[i].fi , 2 ) ,w[i].se ) );
		}
		else
		{
			REP( i , nw )
				V[ min( nv + i , k - 1 ) ].pb( mp( mp( w[i].fi , 2 ) ,w[i].se ) ); 
		}
		REP( i , k ) sort( all(V[i] ) );
		REP( i , min( nv , k ) )
			ans -= 0.5*V[i][0].fi.fi;
		REP( i , k )
			REP( j , V[i].size() )
				ans += V[i][j].fi.fi;
		printf( "%.1lf\n" , ans );
		REP( i , k )
		{
			printf( "%d" , V[i].size() );
			REP( j , V[i].size() )
				printf( " %d" , V[i][j].se + 1 );
			puts("");
		}
	}
}



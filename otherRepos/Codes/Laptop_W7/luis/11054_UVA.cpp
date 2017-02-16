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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[ N ];
int n;

int main()
{
	while( sc( n ) == 1 && n )
	{
		REP( i , n ) sc( A[ i ] );
		vector< pii > V , W;
		REP( i , n )
			if( A[ i ] >= 0 ) V.pb( mp( A[ i ] , i ) );
			else W.pb( mp( -A[ i ] , i ) );
		int i = 0 , j = 0 ;
		ll ans = 0;
		while( i < V.size() && j < W.size() )
		{
			if( V[ i ].fi <= W[ j ].fi )
			{
				ans += V[ i ].fi*abs( W[ j ].se - V[ i ].se );
				W[ j ].fi -= V[ i ].fi;
				i++;
			}
			else
			{
				ans += W[ j ].fi*abs( W[ j ].se - V[ i ].se );
				V[ i ].fi -= W[ j ].fi;
				j++;
			}
		}
		printf( "%lld\n" , ans );
	}
}



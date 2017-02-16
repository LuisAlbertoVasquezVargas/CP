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

#define N 505
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , tc;
int id[ N ];
int FIND( int x )
{
	if( id[x] == x )return x;
	return id[x] = FIND( id[x] );
}

int main()
{
	sc( tc );
	while( tc -- )
	{
		sc( n ) , sc( m );
		REP( i , n )id[i] = i;
		vector< pair< int , pii > >P( m );
		REP( i , m )scanf( "%d%d%d" , &P[i].se.fi , &P[i].se.se , &P[i].fi );
		sort( all( P ) );
		int ans = 0;
		REP( i , m )
		{
			int p = FIND( P[i].se.fi ) , q = FIND( P[i].se.se ) , w = P[i].fi;
			if( p != q ) id[p] = q , ans += w;
		}
		printf( "%d\n" , ans );
	}
}
 

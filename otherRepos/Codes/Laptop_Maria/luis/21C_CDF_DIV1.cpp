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

int n;
int A[ N ];
int L[ N ];
int R[ N ];

int main()
{
	while( sc( n ) == 1 )
	{
		REP( i , n ) sc( A[i] );
		REP( i , n ) L[i+1] = L[i] + A[i];
		R[n] = 0;
		for( int i = n - 1 ; i >= 0 ; --i ) R[i] = R[i+1] + A[i];
		int Sum = L[n];
		if( Sum%3 )
		{
			puts( "0" );
			continue;
		}
		Sum/= 3;
		vi v , w;
		REP( i , n )if( L[i+1] ==  Sum ) v.pb( i );
		for( int i = n - 1 ; i >= 0 ; --i ) if( R[i] == Sum ) w.pb(i);
		reverse( all( w ) );
		ll ans = 0;
		FOR( o , v )
			ans += w.end() - lower_bound( all( w ) , *o + 2 );
		cout << ans << '\n';
	}
}



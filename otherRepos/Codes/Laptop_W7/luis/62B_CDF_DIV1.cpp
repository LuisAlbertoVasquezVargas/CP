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
#define IT 100

using namespace std;

int n , k ;

int main()
{
	while( scanf( "%d%d" , &n , &k ) == 2 )
	{
		vi v( n );
		REP( i , n ) sc( v[i] );
		sort( rall( v ) );
		double hi = v[0] , lo = v.back();
		REP( i , IT )
		{
			double med = ( lo + hi )/2;
			double fmed = 0 , hole = 0;
			REP( i , n )
				if( v[i] >= med )fmed += v[i] - med;
				else hole += med - v[i];
			fmed -= (fmed*k)/100.0;
			if( fmed >= hole )
				lo = med;
			else hi = med;
		}
		printf( "%.9lf\n" , lo );
	}
}



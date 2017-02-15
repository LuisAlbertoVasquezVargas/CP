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

#define N 500005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , B ;
int A[ N ];

int f( int x )
{
	ll cnt = 0;
	REP( i , n )
	{
		cnt += (A[i] - 1 )/x + 1;
		if( cnt > B )return 0;
	}
	return 1;
}

int main()
{
	while( sc( n ) == 1 )
	{
		sc( B );
		if( n == -1 )break;
		REP( i , n )sc( A[i] );
		int lo = 1 , hi = *max_element( A , A + n );
		if( f(lo) )
		{
			puts("1");
			continue;
		}
		while( hi - lo > 1 )
		{
			int med = ( lo + hi )/2;
			if( f( med ) )hi = med;
			else lo = med;
		}
		printf( "%d\n" , hi );
	}	
}


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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m;
int A[ N ][ N ] , T[ N ][ N ];

int f( int i , int j , int k )
{
	return T[i][j] - T[i+k][j] - T[i][j+k] + T[i+k][j+k] == k*k;
}
int main()
{
	test
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		if( !n )break;
		REP( i , n )REP( j , m ) sc( A[i][j] );
		me( T , 0 );
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = m - 1 ; j >= 0 ; --j )
				T[i][j] = T[i+1][j] + T[i][j+1] - T[i+1][j+1] + A[i][j];
		int ans = 0;
		REP( i , n )REP( j , m )
		{
			int lo = 1 , hi = min( n - i , m - j );
			if( !f( i , j , lo ) )continue;
			if( f( i , j , hi ) )
			{
				ans = max( ans , hi );
				continue;
			}
			while( hi - lo > 1 )
			{
				int med = ( hi + lo )/2;
				if( f( i , j , med ) )lo = med;
				else hi = med;
			}
			ans = max( ans , lo );
		}
		printf( "%d\n" , ans );
	}
}


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

int n , m ;
int A[ N ][ N ] , T[ N ][ N ];

bool f( int i , int j , int x )
{
	return T[i][j] - T[i+x][j] - T[i][j+x] + T[i+x][j+x] == x*x;
}
int main()
{
	while( scanf( "%d%d" , &n , &m ) == 2 && n )
	{
		REP( i , n )REP( j , m ) sc( A[i][j] );
		REP( i , n ) A[i][m] = 0;
		REP( j , m ) A[n][j] = 0;
		for( int i = n - 1 ; i >= 0 ; --i )
			for( int j = m - 1 ; j >= 0 ; --j )
				T[i][j] = A[i][j] + T[i+1][j] + T[i][j+1] - T[i+1][j+1];
		int maxi = 0;
		REP( i , n )REP( j , m )
		{
			int lo = 0 , hi = min( n - i , m - j );
			if( f( i , j , hi ) )
			{
				maxi = max( maxi , hi );
				continue;
			}
			while( hi - lo > 1 )
			{
				int med = ( lo + hi )/2;
				if( f( i , j , med ) )
					lo = med;
				else hi = med;
			}
			maxi = max( maxi , lo );
		}
		printf( "%d\n" , maxi );
	}
}



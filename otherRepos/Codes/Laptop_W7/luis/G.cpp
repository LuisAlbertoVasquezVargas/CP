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
#define PI acos(-1.0)

using namespace std;

int H[ N ];

int main()
{
	int n , L , D;
	while( sc( n ) == 1 )
	{
		sc( L ) , sc( D );
		REP( i , n ) sc( H[i] );
		int i;
		REP( j , n )if( !H[j] ) i = j;
		double tanR = 0 , tanL = 0 ;
		for( int j = i + 1 ; j < n ;++j )
		{
			double x = H[j] , y = ( j - i )*( L + D );
			tanL = max( tanL , 1.0*x/y );
		}
		for( int j = 0 ; j < i ; ++j )
		{
			int x = H[j] , y = ( i - j )*( L + D );
			tanR = max( tanR , 1.0*x/y );
		}
		printf( "%.2lf\n" , 16.0*60*(1 - ( atan(tanL) + atan(tanR) )/PI ) );
	}
}



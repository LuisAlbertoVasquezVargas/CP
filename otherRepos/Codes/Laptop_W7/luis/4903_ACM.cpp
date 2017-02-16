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
#define EPS (1e-7)
#define PI acos( -1.0 )

using namespace std;

int X[ N ] , Y[ N ];
double A[ N ];
double F( double x , double y )
{
	double ang = atan2( y , x );
	if( ang < 0 ) ang += 2*PI;
	return ang/PI*180.0;
}
int main()
{
	int n , x , y , f , tc = 0;
	while( scanf( "%d%d%d%d" , &n , &x , &y , &f ) == 4 )
	{
		REP( i , n ) scanf( "%d%d" , &X[ i ] , &Y[ i ] );
		REP( i , n ) A[ i ] = F(X[ i ] - x , Y[ i ] - y);
		sort( A , A + n );
		int mini = INF;
		REP( i , n )
		{
			int cnt = 1 , left = A[ i ] + 0.5*f;
			for( int j = i + 1 ; j != i ; ++j )
				if()
			mini = min( cnt , mini );
		}
		printf( "Case %d: %d\n" , ++tc , mini );
	}
}



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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , t , tc ;
bool done[N][6*N];
double memo[N][6*N];

double dp( int cnt , int sum )
{
	if( cnt == 0 )return sum==t;
	if( sum > t )return 0.0;
	if( done[cnt][sum] )return memo[cnt][sum];
	done[cnt][sum] = 1;
	double &dev = memo[cnt][sum] = 0;
	for( int i = 1 ; i <= 6 ; ++i )
		dev += dp( cnt - 1 , sum + i );
	dev /= 6;
	return dev;
}
int main()
{
	sc( tc );
	while( tc-- )
	{
		scanf( "%d%d" , &n , &t );
		me( done , 0 );
		printf( "%.2lf\n" , dp( n , 0 ) );
	}
}


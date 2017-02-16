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

#define N 205
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int tc , n , m ;
int memo[N][N];
char s[N] , t[N] , r[N];

int dp( int x , int y )
{ 
	if( x + y == n + m )return 1;
	int &dev = memo[x][y];
	if( dev == -1 )
	{
		dev = 0;
		if( x < n && s[x] == r[x+y] )dev = max( dev , dp( x + 1 , y ) );
		if( y < m && t[y] == r[x+y] )dev = max( dev , dp( x , y + 1 ) );
	}
	return dev;
}
int main()
{
	sc( tc );
	REP( i , tc )
	{
		scanf( "%s%s%s" , s , t , r );
		n = strlen( s ) , m = strlen( t );
		me( memo , -1 );
		printf( "Data set %d: %s\n" , i + 1 , (dp( 0 ,0 )?"yes":"no") );
	}
}


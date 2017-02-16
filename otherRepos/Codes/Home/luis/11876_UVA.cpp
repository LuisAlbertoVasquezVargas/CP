#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

int T[ N ];

int f( int n ){
	int ans = 1;
	for( int i = 2 ; i * i <= n ; ++i )
		if( n % i == 0 ){
			int cnt = 0;
			while( n % i == 0 ) n /= i , cnt ++;
			ans *= cnt + 1 ;
		}
	if( n > 1 ) ans *= 2;
	return ans;
}

int main()
{
	int n = 64730;
	T[ 0 ] = 1;
	for( int i = 1 ; i < n ; ++i )
		T[ i ] = T[ i - 1 ] + f( T[ i - 1 ] );
	int Q , x , y , tc = 1;
	sc( Q );
	while( Q -- )
	{
		sc( x ) , sc( y );
		printf( "Case %d: %d\n" , tc++ ,  upper_bound( T , T + n , y ) - lower_bound( T , T + n , x ) );
	}
}


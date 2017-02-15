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

#define N 35
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
int X1[ N ], X2[ N ], Y1[ N ] , Y2[ N ];

void solve( int t )
{
	vi X , Y;
	REP( i,  n ) X.pb( X1[ i ] ) , X.pb( X2[ i ] );
	REP( i,  n ) Y.pb( Y1[ i ] ) , Y.pb( Y2[ i ] );
	sort( all( X ) );
	sort( all( Y ) );
	X.resize( unique( all( X ) ) - X.begin() );
	Y.resize( unique( all( Y ) ) - Y.begin() );
	int nX = X.size() , nY = Y.size();
	ll ans = 0;
	REP( i , nX - 1 )REP( j , nY - 1 )
	{
		int minX = X[ i ], maxX = X[ i + 1 ];
		int minY = Y[ j ] , maxY = Y[ j + 1 ];
		int cnt = 0;
		REP( k , n )
			if( X1[ k ] <= minX && maxX <= X2[ k ] && Y1[ k ] <= minY && maxY <= Y2[ k ] )
				cnt++;
		if( cnt == n )
			ans += (maxX - minX)*(maxY - minY);
	}
	cout << "Case " << t << ": " << ans << '\n';
}
int main()
{
	int tc;
	sc( tc );
	REP( t , tc )
	{
		sc( n );
		REP( i , n ) scanf( "%d%d%d%d" , &X1[ i ] , &Y1[ i ] , &X2[ i ] , &Y2[ i ] );
		solve( t + 1 );		
	}
}



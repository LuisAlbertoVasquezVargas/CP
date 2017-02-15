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

#define N 100005
#define MOD 1000000007LL
#define INF (1<<30)
#define EPS (1e-5)
#define cte 333333336LL

using namespace std;

char V[ 10 ];
bool T[ 65 ];

ll pow( ll a , ll b , ll c )
{
	ll ans = 1;
	while( b )
	{
		if( b&1 ) ans = ( ans*a )%c;
		a = ( a*a )%c;
		b >>= 1;
	}
	return ans;
}

ll f( ll n ){
	if( n == 1 ) return 0;
	return ( pow( 10 , n - 2 , MOD )+ (((cte*2)%MOD)*( pow( 10 , n - 2 , MOD ) - 1 + MOD ))%MOD )%MOD;
}
int main()
{
	//cout << f( 4 ) << endl;
	int tc;
	ll n;
	cin >> tc;
	while( tc-- ){
		cin >> n >> V;
		int ans = 0;
		clr( T , 0 );
		for( int i = 0 ; i < 60 ; ++i )
		{
			bool jump = 0;
			for( int j = 1 ; j <= 6 ; ++j )
				if( V[ j - 1 ] == '0' && i%j == 0 ) jump = 1;
			for( int j = 1 ; j <= 6 ; ++j )
				if( V[ j - 1 ] == '1' && i%j != 0 ) jump = 1;
			if( jump )continue;
			T[ i ] = 1;
			ans++;
		}
		int p = 1 , H = 0;
		for( int i = 0 ; i < pow( 10 , n , 60 ) ; ++i ) H += T[ i ];
		int S = (H + (ans*f( n ))%MOD)%MOD;
		printf( "%d\n" , S );
	}
}



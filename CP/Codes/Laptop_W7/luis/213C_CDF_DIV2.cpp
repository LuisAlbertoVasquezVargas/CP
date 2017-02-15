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

#define N 4005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

char s[ N ];
ll a , n;
ll T[ N ];

int main()
{
	while( cin >> a ){
		scanf( "%s" , s );
		n = strlen( s );
		REP( i , n ) T[ i + 1 ] = T[ i ] + s[ i ] - '0';
		vll V;
		for( int i = 1 ; i <= n ; ++i )
			for( int j = i ; j <= n ; ++j )
			{
				ll sum = T[ j ] - T[ i - 1 ];
				V.pb( sum );
			} 
		sort( all( V ) );
		
		int nV = V.size();
		ll cnt = 0;
		/*REP( i , nV )
			cout << V[ i ] << endl;
		*/
		if( a == 0 )
		{
			ll t = upper_bound( all( V ) , 0 ) - lower_bound( all( V ) , 0 );
			cnt = t*( n*( n + 1 ) - t );
			cout << cnt << endl;
			continue;
		}
		REP( i , nV )
			if( V[ i ] > 0 && a%V[ i ] == 0 )
			{
				ll x = a/V[ i ] ;
				cnt += upper_bound( all( V ) , x ) - lower_bound( all( V ) , x );
			}
		cout << cnt << endl;
	}	
} 



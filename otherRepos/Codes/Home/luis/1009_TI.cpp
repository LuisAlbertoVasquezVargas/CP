#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 25
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

ll k ,  n;
ll memo[ N + 5 ][ 4 ];
ll dp( int pos , int zeroes ){
	if( pos == n ) return 1;
	ll &dev = memo[ pos ][ zeroes ];
	if( dev == -1 ){
		dev = 0;
		if( zeroes != 1 ) dev += dp( pos + 1, zeroes + 1 );
		dev += ( k - 1 ) * dp( pos + 1, 0 );
	}
	return dev;
}
int main()
{
	while( cin >> n >> k ){
		if( n == 1 ){
			cout << k << endl;
			continue;
		}
		clr( memo , -1 );
		cout << ( k - 1 )* dp( 1 , 0 ) << endl;
	}
}


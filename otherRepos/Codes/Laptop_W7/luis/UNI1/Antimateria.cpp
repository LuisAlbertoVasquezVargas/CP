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

#define N 1000
#define MOD1 1000000007
#define MOD2 1000000009
#define INF (1<<30)
#define B 1000

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef pair< ull , ull > pull;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int A[ N + 5 ];
ll pow( ll a , ll b , ll c ){
	ll ans = 1;
	while( b ){
		if( b & 1 ) ans = ( ans * a )%c;
		a = ( a * a )%c;
		b >>= 1;
	}
	return ans;
}
int main()
{
	int n;
	while( cin >> n ){
		REP( i , n ) cin >> A[ i ];
		map< pull , int > SZ;
		REP( i , n ){
			ull H1 = 0 , H2 = 0;
			for( int j = i ; j < n ; ++j ){
				H1 = ( H1 * B + A[ j ] )%MOD1;
				H2 = ( H2 * B + A[ j ] )%MOD2;
				SZ[ mp( H1 , H2 ) ] = j - i + 1;
			}
		}
		ull ans = 0;
		FOR( it , SZ ){
			ans = ( ans + pow( 2 , it->se - 1 , MOD1 ) )%MOD1;
			cout << it -> se << endl;
		}
		cout << ans << '\n';
	}
}




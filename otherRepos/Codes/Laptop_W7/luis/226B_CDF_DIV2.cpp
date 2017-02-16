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

#define N 100005
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

int main()
{
	sync
	string s;
	while( cin >> s ){
		int ns = s.size();
		vi v( ns , 0 );
		for( int i = 0 ; i <= ns - 4 ; ++i ){
			if( s[ i ] == 'b' && s[ i + 1 ] == 'e' && s[ i + 2 ] == 'a' && s[ i + 3 ] == 'r' ) v[ i ] = 1;
		}
		/*
		REP( i , ns ) cout << v[ i ] << " ";
		cout << endl;
		*/
		vi AC( ns + 1 );
		REP( i , ns ) AC[ i + 1 ] = AC[ i ] + v[ i ];
		ll ans = 0;
		for( int i = 0 ; i < ns ; ++i )
			for( int j = i + 3 ; j < ns ; ++j )
				ans += ( AC[ j - 2 ] - AC[ i ] > 0 );
		cout << ans << '\n';
	}
}




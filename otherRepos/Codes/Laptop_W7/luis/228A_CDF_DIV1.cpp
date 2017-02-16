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
	int n;
	while( sc( n ) == 1 ){
		vi V( n );
		REP( i , n ) sc( V[ i ] );
		sort( all( V ) );
		int chosen = 0 , ans = 0;
		while( chosen != n ){
			int sz = 0 , lo = 0;
			int nV = V.size();
			vi vis( nV );
			while( lo < nV ){
				int ind = lower_bound( V.begin() + lo , V.end() , sz ) - V.begin();
				if( ind >= nV ) break;
				vis[ ind ] = 1;
				lo = ind + 1;
				sz++;
			}
			chosen += sz;
			vi W;
			REP( i , nV ) if( !vis[ i ] ) W.pb( V[ i ] );
			V = W;
			ans ++;
		}
		printf( "%d\n" , ans );
	}
}




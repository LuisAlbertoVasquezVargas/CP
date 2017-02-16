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

#define N 200005
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

int A[ N ];
int main()
{
	int n;
	while( sc( n ) == 1 ){
		REP( i , n ) sc( A[ i ] );
		ll best0 = 0 , best1 = 0;
		ll cnt0 = 0 , cnt1 = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			if( A[ i ] == 0 ) best0 += cnt1;
			if( A[ i ] == 1 ) cnt1++;
		}
		for( int i = n - 1 ; i >= 0 ; --i )
		{
			if( A[ i ] == 1 ) best1 += cnt0;
			if( A[ i ] == 0 ) cnt0 ++;
		}
		cout << min( best0 , best1 )  << endl;
	}
}




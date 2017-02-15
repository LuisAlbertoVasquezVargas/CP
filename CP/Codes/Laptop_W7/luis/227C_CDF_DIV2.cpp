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

char s[ N ];
int main()
{
	while( scanf( "%s" , s ) == 1 ){
		int n = strlen( s );
		int ans = 1;
		//if( n >= 2 && s[ 0 ] >= s[ 1 ] ) ans = 1;
		for( int i = n - 1 ; i >= 1 ; --i ){
			if( i == 1 ){
				if( s[ 1 ] == '0' ) continue;
				if( s[ 0 ] >= s[ 1 ] ) ans++;
				continue;
			}
			if( s[ i ] != '0' ){
				ans++;
			}else
			{
				int j = i;
				while( j >= 0 && s[ j ] == '0' ) j--;
				int L = i - j + 1;
				if( L > j ) break;
				if( L == j ){
					int u = (s[ 0 ] - '0')*10 + (s[ 1 ] - '0');
					int v = (s[ j ] - '0')*10 + (s[ j + 1 ] - '0');
					if( v > u ) break;
					else{
						ans ++;
						i = j;
					}
				}else ans ++ , i = j;
			}
		}
		printf( "%d\n" , ans );
	}
}




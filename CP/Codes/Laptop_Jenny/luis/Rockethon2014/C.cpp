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

#define N 200000
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
typedef vector< pii > vpii;

string s;
int n , k ;
int P[ N + 5 ] , E[ N + 5 ] , PK; 
int main()
{
	while( sc( n ) == 1 ){
		sc( k );
		REP( i , n ) sc( P[ i ] ) , sc( E[ i ] );
		bool solve = 0;
		ll mini = 1LL<<60;
		REP( mask , 1 << n ){
			ll cost = 0;
			int sz = 0;
			REP( i , n ) 
				if( mask & ( 1 << i ) ) {
					cost += E[ i ];
					if( P[ i ] <= ones( mask ) ) sz ++;
				}else
				{
					if( P[ i ] + 1 < ones( mask ) ) sz++;	
				}
			if( n - sz <= k ) mini = min( mini , cost ) , solve = 1;
		}
		if( !solve ){
			cout << "-1" << endl;
			continue;
		}
		cout << mini << endl;
	}
}


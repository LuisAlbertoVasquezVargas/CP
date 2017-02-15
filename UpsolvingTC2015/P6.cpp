#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;

int main(){
	int n , m;
	while( sc( n ) == 1 ){ 
		sc( m );
		ll mini = LLONG_MAX;
		REP( i , m ){
			int u , d;
			sc( u ) , sc( d );
			ll x = ((ll)n * d) / (ll)(u + d) + 1LL;
			x = min( x , (ll)n );
			mini = min( mini , (ll)u * x - (ll)(n - x) * d );
		}
		cout << mini << '\n';
	}
}

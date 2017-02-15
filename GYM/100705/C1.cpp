#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 14

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int F[ 1 << N ];
int solve( int n ){
	int ans = 0;
	for( int i = 1 ; i < (1 << n) ; ++i )
		for( int j = i + 1 ; j < (1 << n) ; ++j )
			ans += __gcd( F[ i ] , F[ j ] );
	return ans;
}
int main(){
	
	REP( i , (1 << N) ) F[ i ] = __builtin_popcount( i );
	
	for( int i = 1 ; i <= 14 ; ++i ) cout << solve( i ) << endl;
}



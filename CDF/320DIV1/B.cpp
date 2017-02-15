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

#define N 200000
#define M 10

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll POT[ M + 1 ];
vll get( vi &A , int n ){
	vll AC( n + 1 );
	REP( i , n ) AC[ i + 1 ] = AC[ i ] | A[ i ];
	return AC;
}
int main(){
	int n , K , x;
	while( sc( n ) == 1 ){
		sc( K ) , sc( x );
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		POT[ 0 ] = 1;
		for( int i = 1 ; i <= M ; ++i ) POT[ i ] = POT[ i - 1 ] * (ll)x;
		vll a = get( A , n );
		reverse( all( A ) );
		vll b = get( A , n );
		reverse( all( b ) );
		reverse( all( A ) );
		ll ans = a[ 0 ];
		REP( i , n ) ans = max( ans , (POT[ K ] * (ll)A[ i ]) | a[ i ] | b[ i + 1 ] );
		cout << ans << '\n';
	}
}




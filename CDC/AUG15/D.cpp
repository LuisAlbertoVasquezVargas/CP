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

typedef long long ll;
typedef vector< ll > vll;
typedef vector< int > vi;

void add( vll &A , int a , int b ){
	if( a > b ) return;
	A[ a ] ++ , A[ b + 1 ] --;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , H;
		sc( n ) , sc( H );
		vll A( n + 5 ) , AC( A );
		REP( i , n ){
			int lo , hi ;
			sc( lo ) , sc( hi );
			add( A ,  0 , lo - 1 );
			add( A ,  hi + 1 , n - 1 );
		}
		for( int i = 1 ; i <= n ; ++i ) A[ i ] += A[ i - 1 ];
		REP( i , n + 2 ) AC[ i + 1 ] = AC[ i ] + A[ i ];
		
		//REP( i , n + 1 ) DEBUG2( i , A[ i ] );
		ll ans = LLONG_MAX;
		for( int i = 0 ; i + H - 1 < n ; ++i )
			ans = min( ans , AC[ (i + H - 1) + 1  ] - AC[ i ] );
		cout << ans << '\n';
	}
}



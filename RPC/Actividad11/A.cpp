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
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int v1 , d1 , v2 , d2 , tc = 0;
	while( sc( v1 ) == 1 ){
		sc( d1 ) , sc( v2 ) , sc( d2 );
		if( v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0 ) break;
		//(d1/v1 + d2/v2 )/2 = (d1v2 + d2v1)/(2*v1v2)
		ll num = ((ll) d1 * v2 + (ll) d2 * v1);
		ll den = (2LL * v1 * v2);
		ll g = __gcd( num , den );
		num /= g;
		den /= g;
		if( (ll) v1 * d2 > (ll)d1 * v2 ){
			printf( "Case #%d: You owe me a beer!\n" , ++tc );
		}else{
			printf( "Case #%d: No beer for the captain.\n" , ++tc );
		}
		printf( "Avg. arrival time: " );
		if( den == 1 ) cout << num << '\n';
		else cout << num << "/" << den << '\n';
	}
}




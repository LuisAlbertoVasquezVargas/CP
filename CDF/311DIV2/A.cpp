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
typedef pair< int , int > pii;
typedef vector< int > vi;

void impr( vll &a ){
	REP( i , SZ( a ) ) cout << a[ i ] << char((i + 1 == SZ( a )) ? 10 : 32 );
}
int main(){
	ll n;
	while( cin >> n ){
		vll a( 3 ) , b( 3 );
		REP( i , 3 ) cin >> a[ i ] >> b[ i ];
		vll cur = a;
		REP( i , 3 ) n -= a[ i ];
		
		REP( i , 3 ){
			if( !n ) break;
			ll maxi = b[ i ] - a[ i ];
			ll t = min( n , maxi );
			n -= t;
			cur[ i ] += t;
		}
		impr( cur );
	}
}


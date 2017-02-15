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

//2(n - 2^largestbit)

int f( int num ){
	int r = 31 - __builtin_clz( num );
	return 2 * ( num ^ (1 << r) );
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	ll POT[ 10 ];
	POT[ 0 ] = 1;
	for( int i = 1 ; i <= 6 ; ++i )
		POT[ i ] = POT[ i - 1 ] * 10LL; 
	while( cin >> s ){
		if( s == "00e0" ) break;
		int num = ((s[ 0 ] - '0') * 10 + s[ 1 ] - '0') * POT[ s.back() - '0' ];
		printf( "%d\n" , 1 + f( num ) );
	}
}





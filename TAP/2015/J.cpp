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
typedef long double ld;
typedef vector< ld > vld;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool f( vi &v ){
	int n = SZ(v);
	REP( i , n )
		if( v[ i ] >= i + 1 ){
			continue;
		}else return 0;
	return 1;
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi vec;
		REP( i , n ){
			int x;
			sc( x );
			vec.pb( x );
		}
		sort( all( vec ) );
		ll p = (vec[ 0 ] / (n + 1));
		for( auto &x : vec ) x -= (ll)(n + 1) * p;
		puts( f( vec ) ? "N" : "S" );
	}
}



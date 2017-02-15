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
	int cases;
	sc( cases );
	REP( tc , cases ){
		vi vec;
		bool possible = 1;
		REP( i , 3 ){
			int x;
			sc( x );
			vec.pb( x );
			if( x == 0 ) possible = 0;
		}
		if( accumulate( all( vec ) , 0 ) == 180 && possible ) puts( "YES" );
		else puts( "NO" );
	}
}



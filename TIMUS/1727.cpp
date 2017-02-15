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
typedef vector< pii > vpii;
typedef vector< int > vi;

const int N = 100000;

int getDig( int x ){
	int ans = 0;
	while( x ){
		ans += (x % 10);
		x /= 10;
	}
	return ans;
}

int main(){
	vpii v;
	for( int i = 1 ; i < N ; ++i )	v.pb( mp( getDig( i ) , i ) );
	sort( all( v ) );
	reverse( all( v ) );
	int n;
	while( sc( n ) == 1 ){
		vi vec;
		for( auto p : v ){
			if( n >= p.fi ){
				n -= p.fi;
				vec.pb( p.se );
			}
		}
		if( n ){
			puts( "-1" );
			continue;
		}
		printf( "%d\n" , SZ( vec ) );
		REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
	}
}



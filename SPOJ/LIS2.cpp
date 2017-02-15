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

int lis( vi &v ){
    int n = SZ( v );
    vi mini;
    REP( i , n ){
        int j = lower_bound( all( mini ) , v[ i ] ) - mini.begin();
        if( j == SZ( mini ) ) mini.pb( 0 );
        mini[ j ] = v[ i ];
    }
    return SZ( mini );
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vpii v;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			v.pb( mp( x , -y ) );
		}
		sort( all( v ) );
		vi vec;
		REP( i , SZ( v ) ) vec.pb( -v[ i ].se );
		REP( i , n ) printf( "%d %d\n" , v[ i ].fi , v[ i ].se );
		//REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] , (i + 1 == SZ(vec)) ? 10 : 32 );
		printf( "%d\n" , lis( vec ) );	
	}
}




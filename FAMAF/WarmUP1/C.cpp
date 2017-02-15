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

int lis( vi &v ){
	if( !SZ(v) ) return 0;
    int n = SZ( v );
    vi sig( n , -1 ) , id( n ) , r( n );
    vi mini;
    REP( i , n ){
        int j = lower_bound( all( mini ) , v[ i ] ) - mini.begin();
        if( j == SZ( mini ) ) mini.pb( 0 );
        mini[ j ] = v[ i ];
        id[ j ] = i;
        if( j ) sig[ i ] = id[ j - 1 ];
    }
    return SZ( mini );
}
int main(){
	int n;
	while( cin >> n ){
		vi a( n );
		REP( i , n ) cin >> a[ i ];
		printf( "%d\n" , n - lis( a ) );
	}
}

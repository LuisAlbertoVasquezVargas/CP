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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 2000


typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< vvvi > vvvvi;
ll MOD = 1000000007LL;
int n;
bool used[ N + 5 ];
ll memo[ N + 5 ];
ll C[ N + 5 ][ N + 5 ];
int AC[ N + 5 ] , A[ N + 5 ];
ll dp( int pos ){
    if( pos >= n - 1 ) return 1;
    if( used[ pos ] ) return memo[ pos ];
    used[ pos ] = 1;
    ll &dev = memo[ pos ] = 0;
    int left = AC[ pos + 1 ];
    for( int k = 1 ; k <= A[ pos ] ; ++k )
        dev = (dev + C[ left - 1 + A[ pos ] - k ][ A[ pos ] - k ] * dp( pos + 1 ) )%MOD;
    return dev;
}

int main(){
    REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
    for( int i = 2 ; i <= N ; ++i )
         for( int j = 1 ; j <= i ; ++j )
            C[ i ][ j ] = ( C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] )%MOD;
            
    while( sc( n ) == 1 ){
        REP( i , n ) sc( A[ i ] );
        reverse( A , A + n ); 
        AC[ n - 1 ] = A[ n - 1 ];
        for( int i = n - 2 ; i >= 0 ; --i )
            AC[ i ] = AC[ i + 1 ] + A[ i ];
        clr( used , 0 );
        printf( "%d\n" , (int)dp( 0 ) );        
    }
}

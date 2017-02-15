#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define LOGN 20
#define N 200000

typedef long long ll;
typedef vector< int > vi;

int rmq[ LOGN + 1 ][ N + 5 ];
int query( int a , int b ){ 
    int r = 31 - __builtin_clz( b - a + 1 );
    return min( rmq[ r ][ a ] , rmq[ r ][ b - (1<<r) + 1 ] );
}
int A[ N + 5 ];
int right( int pos , int n ){
    int lo = pos , hi = n - 1;
    if( query( pos , hi ) == A[ pos ] ) return hi;
    while( hi - lo > 1 ){
        int med = (lo + hi) >> 1;
        if( query( pos , med ) == A[ pos ] ) lo = med;
        else hi = med;
    }
    return lo;
}
int left( int pos , int n ){
    int lo = 0 , hi = pos;
    if( query( lo , pos ) == A[ pos ] ) return lo;
    while( hi - lo > 1 ){
        int med = (lo + hi) >> 1;
        if( query( med , pos ) == A[ pos ] ) hi = med;
        else lo = med;
    }
    return hi;
}

int main(){
    int n;
    while( sc( n ) == 1 ){
        REP( i , n ){
            sc( A[ i ] );
            rmq[ 0 ][ i ] = A[ i ];
        }
        for( int k = 1 ; k <= LOGN ; ++k )
            for( int i = 0 ; i + (1 << k) <= n ; ++i )
                rmq[ k ][ i ] = min( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
                
        vi ans( n + 1 );
        REP( i , n ){
            int len = right( i , n ) - left( i , n ) + 1;
            ans[ len ] = max( ans[ len ] , A[ i ] );
        }
        for( int i = n - 1 ; i >= 0 ; --i )
            ans[ i ] = max( ans[ i ] , ans[ i + 1 ] );
        REP( i,  n ) printf( "%d%c" , ans[ i + 1 ] , ((i + 1 == n) ? 10 : 32) );
    }               
}

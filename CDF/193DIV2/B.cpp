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

#define N 200000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< pll > vpll;
typedef vector< int > vi;

ll get( int pos , int K , vll &AC ){
    return AC[ pos + K - 1 + 1 ] - AC[ pos ];
}
int main(){
    int n , K;
    while( sc( n ) == 1 ){
        sc( K );
        vi A( n );
        REP( i , n ) sc( A[ i ] );
        
        vll AC( n + 1 );
        REP( i , n ) AC[ i + 1 ] = AC[ i ] + A[ i ];
        
        vpll T( n - K + 1 );
        T[ n - K ] = mp( get( n - K , K , AC ) , -(n - K) );
        for( ll i = SZ( T ) - 2 ; i >= 0 ; --i )
            T[ i ] = max( T[ i + 1 ] , mp( get( i , K , AC ) , -i ) );

        pll ind( 0 , 0 );
        ll best = 0;
        for( ll i = 0 ; i + 2 * K <= n ; ++i ){
            pll l = T[ i + K ];
            ll cur = get( i , K , AC ) + l.fi;
            if( cur > best ){
                best = cur;
                ind = mp( i , -l.se );
            }
        }
        ind.fi ++ , ind.se ++;
        printf( "%d %d\n" , (int)ind.fi , (int)ind.se );
    }
}

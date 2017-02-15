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

typedef long long ll;
typedef vector< int > vi;

void doit( ll u , ll a , ll b , ll t , ll n , int &llega , int &i , int &j , int &k , int &cycle ){
    vi vis( n ) , dist( n , -1 );
    vis[ u ] = 1;
    dist[ u ] = 0;
    ll p = -1;
    while( 1 ){
        p = u;
        u = (a * u + b)%n;
        if( vis[ u ] ){
            i = dist[ u ];
            j = dist[ p ] - dist[ u ] + 1;
            k = dist[ t ];
            break;
        }
        dist[ u ] = dist[ p ] + 1;
        vis[ u ] = 1;
    }
    llega = vis[ t ];
    cycle = (dist[ t ] >= i);
}
int main(){
    int mod;
    vi h( 2 ) , a( 2 ) , x( 2 ) , y( 2 ) , llega( 2 ) , p( 2 ) , q( 2 ) , r( 2 ) , s( 2 );
    while( sc( mod ) == 1 ){
        REP( i , 2 ){
            sc( h[ i ] ) , sc( a[ i ] );
            sc( x[ i ] ) , sc( y[ i ] );
            llega[ i ] = 0;
        }
        REP( i , 2 ) doit( h[ i ] , x[ i ] , y[ i ] , a[ i ] , mod , llega[ i ] , p[ i ] , q[ i ] , r[ i ]  , s[ i ] );
        if( !llega[ 0 ] || !llega[ 1 ] ){
            puts( "-1" );
            continue;
        }

        bool possible = 0;
        for( ll t = 0 ; t <= 10000000 ; ++t ){
            ll X = (ll)r[ 0 ] + (ll)q[ 0 ] * t;
            ll Y = X - (ll)r[ 1 ];
            if( t > 0 && !s[ 0 ] ) continue;
            if( Y < 0 ) continue;
            if( Y > 0 && !s[ 1 ] ) continue;
            if( Y % q[ 1 ] == 0 ){
                cout << X << '\n';
                possible = 1;
                break;
            }
        }

        if( !possible ){
            puts( "-1" );
            continue;
        }
    }
}

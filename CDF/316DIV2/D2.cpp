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

#define N 500000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vi > vvvi;

char S[ N + 5 ];
vi G[ N + 5 ];
vi T[ N + 5 ][ 26 ];
int in[ N + 5 ] , out[ N + 5 ];
int timer;
void dfs( int u , int d ){
    T[ d ][ S[ u ] ].pb( timer );
    in[ u ] = timer;
    timer ++;
    
    for( auto v : G[ u ] )
        dfs( v , d + 1 );
    
    out[ u ] = timer;
    timer ++;
}
inline int f( vi &v , int lo , int hi ){
    return upper_bound( all( v ) , hi ) - lower_bound( all( v ) , lo );
}
int main(){
    int n , m;
    while( sc( n ) == 1 ){
        sc( m );
        REP( i , n ) G[ i ].clear();
        REP( i , n ) REP( j , 26 ) T[ i ][ j ].clear();
        for( int v = 1 ; v < n ; ++v ){
            int u;
            sc( u );
            u --;
            G[ u ].pb( v );         
        }
        scanf( "%s" , S );
        REP( i , n ) S[ i ] -= 'a';
        timer = 0;
        dfs( 0 , 0 );
        REP( it , m ){
            int u , h;
            sc( u ) , sc( h );
            u -- , h --;
            int lo = in[ u ] , hi = out[ u ];
            bool ok = 1 ;
            int impar = 0;
            REP( c , 26 ){
                int cnt = f( T[ h ][ c ] , lo , hi );
                if( cnt & 1 ) impar ++;
            }
            if( impar > 1 ) ok = 0;
            puts( ok ? "Yes" : "No" );
        }
    }
}

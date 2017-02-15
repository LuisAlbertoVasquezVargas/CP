#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 500000

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

vi G[ N + 5 ];
bool used[ N + 5 ][ 2 ];
int memo[ N + 5 ][ 2 ];
int dp( int u , int taked ){
    if( used[ u ][ taked ] ) return memo[ u ][ taked ];
    used[ u ][ taked ] = 1;
    int &dev = memo[ u ][ taked ] = 0;
    if( taked ){
        dev = 0;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            dev += dp( v , 0 );
        }
    }else{
        int sum = 0;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            sum += dp( v , 0 );
        }
        
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            dev = max( dev , sum - dp( v , 0 ) + dp( v , 1 ) + 1  );
        }
        
    }
    return dev;
}

vi vec;
void rec( int u , int taked ){
    if( taked ){
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            rec( v , 0 );
        }
    }else{
        int sum = 0;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            sum += dp( v , 0 );
        }
        int pos = -1;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            if( dp( u , taked ) == sum - dp( v , 0 ) + dp( v , 1 ) + 1 ){
                pos = i;
            }
        }
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            if( i == pos ) rec( v , 1 ) , vec.pb( v );
            else rec( v , 0 );
        }
    }
}
int main(){
    int cases;
    sc( cases );
    
    REP( tc , cases ){
        int n;
        sc( n );
		REP( i , N ) G[ i ].clear();
        for( int i = 2 ; i <= n ; ++i ){
            int p;
            sc( p );
            p --;
            int u = i - 1;
            G[ p ].pb( u );
        }
        clr( used , 0 );
        int ans = dp( 0 , 0 );
        printf( "%d\n" , ans * 1000 );
        
        vec.clear();
        rec( 0 , 0 );
        sort( all( vec ) );
        REP( i , SZ( vec ) ) printf( "%d%c" , vec[ i ] + 1 , i + 1 == SZ( vec ) ? 10 : 32 );
        
    }
}

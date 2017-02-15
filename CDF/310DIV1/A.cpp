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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

void safeErase( set< int > &SET , int x ){
    assert( SET.count( x ) );
    auto it = SET.lower_bound( x );
    SET.erase( it );
}
void solve( vi &v , vvi &T , int &ans ){
    int n = SZ(v) , cnt = 0;
    for( int i = 0 ; i < n ; ++i ){
        int ind;
        vi vec;
        for( int j = i ; j < n ; ++j )
            if( v[ i ] + (j - i) == v[ j ] ) ind = j , vec.pb( v[ j ] );
            else break;
        T.pb( vec );
        cnt ++;
        i = ind;
    }
    //DEBUG( cnt );
    ans += max( 0 , cnt - 1 );
}
int main(){
    int n , K;
    while( sc( n ) == 1 ){
        sc( K );
        int ans = 0;
        vvi T;
        REP( i , K ){
            int len;
            sc( len );
            vi vec;
            REP( j , len ){
                int x;
                sc( x );
                x --;
                vec.pb( x );
            }
            solve( vec , T , ans );
        }
        sort( all( T ) );
        //DEBUG( ans );
        REP( i , SZ( T ) ){
        	if( T[ i ][ 0 ] == 0 ) continue;
        	ans += max( 0 , SZ( T[ i ] ) - 1 );
        	ans += SZ( T[ i ] );
        }
        printf( "%d\n" , ans );
    }
}

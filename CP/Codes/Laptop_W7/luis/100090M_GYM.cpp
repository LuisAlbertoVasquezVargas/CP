#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define all( v ) v.begin() , v.end()
#define pb push_back

typedef vector< int > vi ;

#define N 200005

vi E[ N ];
int DP[ N ] , A[ N ];

int main()
{
    int n , x ;
    while( sc( n ) == 1 )
    {
        REP( i , N ) E[ i ].clear();
        REP( i , n )
        {
            sc( x );
            A[ i ] = x;
            E[ x ].pb( i );
        }
        DP[ n - 1 ] = 0;
        for( int pos = n - 2 ; pos >= 0 ; --pos )
        {
            int &dev = DP[ pos ] = 1 + DP[ pos + 1 ];
            int sz = E[ A[ pos ] ].size();
            int next = upper_bound( all( E[ A[ pos ] ] ) , pos ) - E[ A[ pos ] ].begin();
            if( next != sz ) dev = min( dev , 1 + DP[ E[ A[ pos ] ][ next ] ] );
        }
        printf( "%d\n" , DP[ 0 ] );
    }
}

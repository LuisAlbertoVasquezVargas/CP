#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define N 400008

int A[ N ] , L[ N ] , R[ N ];
int n , node , p , INI = 0 , FIN = N - 1;
char s[ 25 ];

void init(){
    for( int i = 1 ; i < n ; ++i )
        R[ i ] = i + 1 , L[ i + 1 ] = i;
    L[ 1 ] =  INI;
    R[ INI ] = 1;
    L[ FIN ] = n;
    R[ n ] = FIN;
    p = n + 1 ;
}
void InsertLeft( int x ){
    int q = L[ node ];
    R[ q ] = p;
    L[ p ] = q , R[ p ] = node;
    L[ node ] = p;
    A[ p ] = x;
    p++;
}
void InsertRight( int x ){
    int q = R[ node ];
    R[ node ] = p  ;
    L[ p ] = node , R[ p ] = q;
    L[ q ] = p;
    A[ p ] = x;
    p++;
}
int main()
{
    int Q;
    while( sc( n ) == 1 )
    {
        sc( node );
        for( int i = 1 ; i <= n ; ++i ) sc( A[ i ] );
        init();
        sc( Q );
        while( Q-- )
        {
            scanf( "%s" , s );
            //cout << s << endl;
            if( s[ 0 ] == 'p' )
            {
                printf( "%d\n" , A[ node ] );
            }
            else if( s[ 0 ] == 'm' )
            {
                if( s[ 4 ] == 'L' )
                {
                    if( L[ node ] != INI ) node = L[ node ];
                }
                else
                {
                    if( R[ node ] != FIN ) node = R[ node ];
                }
            }
            else
            {
                int x;
                sc( x );
                if( s[ 6 ] == 'L' )
                {
                    InsertLeft( x );
                }
                else
                {
                    InsertRight( x );
                }
            }
        }
    }
}

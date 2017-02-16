#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 300005

typedef long long ll;

int n;
char s[ N ];
ll AC[ N ];

ll get( char c )
{
    if( c >= 'a' && c <= 'z' ) return 1LL << ( c - 'a' );
    return 1LL << ( 26 + ( c - 'A' ) );
}

inline int search( ll x ){
    return upper_bound( AC , AC + n + 1 , x ) - lower_bound( AC , AC + n + 1 , x );
}
int main()
{
    freopen("hyperdrome.in", "r", stdin);
    freopen("hyperdrome.out", "w", stdout);
    while( scanf( "%d" , &n ) == 1 )
    {
        scanf( "%s" , s );
        AC[ 0 ] = 0; 
        REP( i , n ) AC[ i + 1 ] = AC[ i ] ^ get( s[ i ] );
        
        sort( AC , AC + n + 1 );
        ll cnt = 0;
        REP( i , n + 1 ){
            cnt += ( search( AC[ i ] ) - 1 );
            REP( k , 52 ) cnt += search( AC[ i ] ^ ( 1LL << k ) ) ;
        }
        cout << (cnt >> 1) << '\n'; 
    }
}

#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
 
#define N 200005
typedef long long ll;

ll A[ N ] , B[ N ];

int main()
{
    int n ;
    while( cin >> n )
    {
        REP( i , n ) cin >> A[ i ];
        B[ 0 ] = A[ 0 ];
        for( int i = 1 ; i < n ; ++i )
            B[ i ] = A[ i ] - A[ i - 1 ];
        REP( i , n )
            cout << B[ i ] << ( i + 1 == n ? "\n":" " );
    }   
}

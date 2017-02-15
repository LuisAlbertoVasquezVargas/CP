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

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;

int main(){
    ios_base :: sync_with_stdio( 0 );
    string s;
    while( cin >> s ){
        int m , n = SZ( s );
        vi A( SZ( s ) + 1 ) , AC( SZ( s ) + 1 );
        cin >> m;
        REP( i , m ){
            int len;
            cin >> len;
            A[ len - 1 ] ++;
            A[ n / 2 ]--;
        }
        REP( i , SZ( s ) ) AC[ i + 1 ] = (AC[ i ] + A[ i ])&1;
        REP( i , n / 2 )
            if( AC[ i + 1 ] & 1 ) swap( s[ i ] , s[ n - 1 - i ] );
        cout << s << '\n';
    }
}

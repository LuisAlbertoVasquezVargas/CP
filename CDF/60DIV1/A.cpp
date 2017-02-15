#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
ll LCM( ll a , ll b ){
    return a * (b / __gcd( a , b ));
}
int main(){
    int n = 6;
    ll a[ 6 ];
    while( cin >> a[ 0 ] ){
        REP( i , n ){
            if( !i ) continue;
            cin >> a[ i ];
        }
        
        if( !a[ 2 ] && a[ 3 ] ){
            cout << "Ron\n";
            continue;
        }
        if( !a[ 3 ] ){
            cout << "Hermione\n";
            continue;
        }
        if( !a[ 0 ] && a[ 1 ] ){
            cout << "Ron\n";
            continue;
        }
        if( !a[ 1 ] ){
            cout << "Hermione\n";
            continue;
        }
        if( !a[ 4 ] && a[ 5 ] ){
            cout << "Ron\n";
            continue;
        }
        if( !a[ 5 ] ){
            cout << "Hermione\n";
            continue;
        }
        
        ll lcm = 1;
        REP( i , n ) lcm = LCM( lcm , a[ i ] );
    
        ld x = lcm;
        for( int i = 0 ; i < n ; i += 2 ){
            x /= (ld)a[ i ];
            x *= (ld)a[ i + 1 ];
        }
        if( x > (ld)lcm ){
            cout << "Ron\n";
            continue;
        }
        cout << "Hermione\n";
    }
}

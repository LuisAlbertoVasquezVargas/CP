#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)v.size())

#define mp make_pair
#define fi first
#define se second

typedef vector< int > vi;

int get( vi &v ){
    int ans = 0;
    REP( i , SZ( v ) ) ans = ans * 10 + v[ i ];
    return ans;
}
int main(){
    int n;
    while( sc( n ) == 1 ){
        vi v( n );
        REP( i , n ) sc( v[ i ] );
        int last = 1000;
        vi ans;
        bool solve = 1;
        REP( i , n ){
            vi vec;
            int num = v[ i ];
            //cout << num << endl;
            while( num ){
                vec.pb( num % 10 );
                num /= 10;
            }
            
            reverse( all( vec ) );
            int mini = INT_MAX;
            for( int d = 0 ; d < 4 ; ++d ){
                for( int x = ((d == 0) ? 1 : 0) ; x <= 9 ; ++x ){
                    swap( x , vec[ d ] );
                    int val = get( vec );
                    //cout << val << endl;
                    if( val >= last && val <= 2011 )
                        mini = min( mini , val );
                    swap( x , vec[ d ] );
                }
            }
            if( mini == INT_MAX ){
                solve = 0;
                break;
            }
            //cout << last << endl;
            ans.pb( mini );
            last = mini;
        }
        if( !solve ){
            puts( "No solution" );
            continue;
        }
        REP( i , SZ( ans ) ) printf( "%d\n" , ans[ i ] );
    }
}

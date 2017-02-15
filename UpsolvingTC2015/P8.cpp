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
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< pii > vpii;

int main(){
    int n;
    while( sc( n ) == 1 ){
        vpii v;
        REP( i , n ){
            int x , y;
            sc( x ) , sc( y );
            v.pb( mp( x , y ) );
        }
        sort( all( v ) );
        pii last( INT_MIN , INT_MIN );
        for( auto p : v ){
            if( p.se >= last.se ) last.se = p.se;
            else last.se = p.fi;
            last.fi = p.fi;
        }
        printf( "%d\n" , last.se );
    }
}

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

#define N 3000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int A[ N + 5 ];
short NEXT[ N + 1 ][ N + 1 ];
short DP[ N + 1 ][ N + 1 ];
//short memo[ N + 1 ][ N + 1 ];
//bool used[ N + 1 ][ N + 1 ];
/*
short dp( int i , int j ){
    if( used[ i ][ j ] ) return memo[ i ][ j ];
    used[ i ][ j ] = 1;
    
    short &dev = memo[ i ][ j ] = 2;
    if( NEXT[ i ][ j ] != -1 ) dev = max( dev , (short)(1 + dp( j , NEXT[ i ][ j ] )) );
    return dev;
}
*/
vi w;
void rec( int i , int j ){
    if( NEXT[ i ][ j ] != -1 ){
        w.pb( A[ i ] );
        rec( j , NEXT[ i ][ j ] );
        return;
    }
    w.pb( A[ i ] );
    w.pb( A[ j ] );
}
int main(){
    freopen( "fibsubseq.in" , "r" , stdin );
    freopen( "fibsubseq.out" , "w" , stdout );
    int n;
    while( sc( n ) == 1 ){
        REP( i , n ) sc( A[ i ] );
        if( n == 1 ){
            puts( "1" );
            printf( "%d\n" , A[ 0 ] );
            continue;
        }
        vpii v;
        REP( i , n ) v.pb( mp( A[ i ] , i ) );
        sort( all( v ) );
        
        clr( NEXT , -1 );
        for( int i = 0, lo, hi, mi, target; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				target = A[ i ] + A[ j ];
				lo = 0;
				hi = n;
				while ( lo < hi ) {
					mi = ((lo+hi)>>1);
					if ( v[mi].first == target )
					{
						if ( v[mi].second <= j ) lo = mi+1;
						else hi = mi;
					}
					else
					{
						if ( v[mi].first < target ) lo = mi+1;
						else hi = mi;
					}
				}
				if( lo < SZ( v ) && v[ lo ].fi == target )  {
					NEXT[ i ][ j ] = v[ lo ].se;
				}
			}
        //clr( used , 0 );
        for( int i = n - 1 ; i >= 0 ; --i )
            for( int j = i + 1 ; j < n ; ++j ){
                DP[ i ][ j ] = 2;
                if( NEXT[ i ][ j ] != -1 ) 
                    DP[ i ][ j ] = max( DP[ i ][ j ] , (short)(1 + DP[ j ][ NEXT[ i ][ j ] ]) );
            }
        
        vi vec( 3 );
        for( int i = 0 ; i < n ; ++i )
            for( int j = i + 1 ; j < n ; ++j ){
            	if( DP[ i ][ j ] > vec[ 0 ] ){
            		vec[ 0 ] = DP[ i ][ j ];
            		vec[ 1 ] = i;
            		vec[ 2 ] = j;
            	}
            }
        printf( "%d\n" , vec[ 0 ] );
        w.clear();
        rec( vec[ 1 ] , vec[ 2 ] );
        REP( i , SZ(w) ) printf( "%d%c" , w[ i ] , (i + 1 == SZ(w)) ? 10 : 32 );
    }
}


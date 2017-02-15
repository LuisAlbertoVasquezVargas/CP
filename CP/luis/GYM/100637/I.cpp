#include<bits/stdc++.h>
using namespace std;

#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

typedef long double ld;
struct Point{
    ld x , y;
    Point(){}
    Point( ld x , ld y ) : x( x ) , y( y ) {}
    ld dist(){ return hypot( x , y ); }
    Point unit(){
        ld d = dist();
        return Point( x/d , y/d );
    }
};
Point operator -( const Point &A , const Point &B ){
    return Point( A.x - B.x , A.y - B.y );
}
Point operator +( const Point &A , const Point &B ){
    return Point( A.x + B.x , A.y + B.y );
}
Point operator *( const Point &A , const ld &k ){
    return Point( A.x * k , A.y * k );
}
ld dist( const Point &A , const Point &B ){
    return (B - A).dist();
}
vector< Point > V;
Point A , B , u;
ld f( ld x ){
    ld ans = 0;
    Point P = A + (u * x);
    for( int i = 0 ; i < SZ( V ) ; ++i )
        ans += dist( P , V[ i ] );
    return ans;
}
int main(){
    int x , y;
    while( scanf( "%d%d" , &x , &y ) == 2 ){
        A = Point( x , y );
        scanf( "%d%d" , &x , &y );
        B = Point( x , y );
        u = (B - A).unit();
        V.clear();
        int n;
        scanf( "%d" , &n );
        for( int i = 0 ; i < n ; ++i ){
            scanf( "%d%d" , &x , &y );
            V.pb( Point( x , y ) );
        }
        ld lo = -100000 , hi = 100000;
        for( int it = 0 ; it < 300 ; ++it ){
            ld med1 = ( 2.0 * lo + hi )/3.0;
            ld med2 = ( 2.0 * hi + lo )/3.0;
            if( f( med1 ) < f( med2 ) ) hi = med2;
            else lo = med1;
        }

        printf( "%.10f\n" , (double)f( lo ) );
        Point P = A + (u * lo);
        printf( "%.10f %.10f\n" , (double)P.x , (double)P.y );
    }
}

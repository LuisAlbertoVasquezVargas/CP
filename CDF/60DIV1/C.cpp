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

#define EPS (1e-8)
#define PI acos(-1.0)
 
#define Vector Point
 
typedef long double ld;

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }
struct Point{
    ld x , y , z;
    Point(){ x = y = 0; }
    Point( ld x , ld y , ld z ) : x( x ) , y( y ) , z( z ) {}
    ld mod(){
        return sqrt( (x * x) + (y * y) + (z * z) ); 
    }
    Point unit()  { ld k = mod(); return Point(x/k, y/k , z/k); }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y , A.z - B.z ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y , A.z + B.z ); }
Point operator * ( const Point &a , ld k ) { return Point( a.x * k , a.y * k , a.z * k ); }
bool operator == ( const Point A , const Point B ){ return equals( A.x , B.x ) && equals( A.y , B.y ) && equals( A.z , B.z ); }
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y + A.z * B.z ; }
ld dist( const Point &A, const Point &B ){ 
    ld dx = A.x - B.x;
    ld dy = A.y - B.y;
    ld dz = A.z - B.z;
    return sqrt( (dx * dx) + (dy * dy) + (dz * dz) ); 
}
 
void solve( Point A , Point B , Point P , ld vs , ld vp , ld ti , ld tf , bool &ok , ld &timer , Point &X ){
    if( P == A ){
        ok = 1;
        timer = ti;
        X = A;
        return;
    }
    
    ld dAP = dist( A , P );
    ld cost = dot( (B - A).unit() , (P - A).unit() );

    ld a = vp * vp - vs * vs;
    ld b = 2.0 * vp * vp * ti + 2.0 * dAP * vs * cost;
    ld c = ti * ti * vp * vp - dAP * dAP;
    
    if( equals( a , 0.0 ) ){
        if( equals( b , 0.0 ) ){
            ok = 0;
            return;
        }
        ld dt = -c/b;
	    if( LessOrEquals( 0.0 , dt ) && LessOrEquals( ti + dt , tf ) ){
            timer = ti + dt;
            X = A + ((B - A).unit() * dt * vs);
            ok = 1;
            return;
        }
        ok = 0;
        return;
    }
    ld disc = b * b - (4.0 * a * c);
    if( disc < -EPS ){
    	assert( 0 );
        ok = 0;
        return;
    }
    
    ld dt = (-b + sqrt( abs( disc ) ))/(2.0 * a);
    if( LessOrEquals( 0.0 , dt ) && LessOrEquals( ti + dt , tf ) ){
        timer = ti + dt;
        X = A + ((B - A).unit() * dt * vs);
        ok = 1;
        return;
    }
    
    dt = (-b - sqrt( abs( disc ) ))/(2.0 * a);
    if( LessOrEquals( 0.0 , dt ) && LessOrEquals( ti + dt , tf ) ){
        timer = ti + dt;
        X = A + ((B - A).unit() * dt * vs);
        ok = 1;
        return;
    }
    ok = 0;
}
int main(){
    int n;
    while( sc( n ) == 1 ){
        n ++;
        vector< Point > poly;
        REP( i , n ){
            int x , y , z;
            sc( x ) , sc( y ) , sc( z );
            poly.pb( Point( x , y , z ) );
        }
        
        int vp , vs;
        sc( vp ) , sc( vs );
        Point P;
        int x , y , z;
        sc( x ) , sc( y ) , sc( z );
        P = Point( x , y , z );
        vector< ld > T( n );
        for( int i = 1 ; i < n ; ++i )
            T[ i ] = T[ i - 1 ] + (dist( poly[ i ] , poly[ i - 1 ] ) / (ld) vs);
        ld mini = 1e100;
        Point Y;
        bool solved = 0;
        for( int i = 0 ; i < n - 1 ; ++i ){
            bool ok = 0;
            ld timer;
            Point X;
            solve( poly[ i ] , poly[ i + 1 ] , P , vs , vp , T[ i ] , T[ i + 1 ] , ok , timer , X );
            if( ok ) {
                solved = 1;
                if( timer < mini ){
                    mini = timer;
                    Y = X;
                }
            }
        }
        if( !solved ){
            puts( "NO" );
            continue;
        }
        puts( "YES" );
        printf( "%.10f\n" , (double)mini );
        printf( "%.10f %.10f %.10f\n" , (double) Y.x , (double)Y.y , (double)Y.z );
    }

}

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

#define EPS (1e-12)

typedef vector< int > vi;
typedef long double ld;
 
inline bool equals( const ld &x , const ld &y ){ return abs( x - y ) < EPS;}
inline bool Less( const ld &x , const ld &y ){ return x < y - EPS;}
inline bool LessEquals( const ld &x , const ld &y ){ return x < y + EPS;}

struct Point{
    ld x , y;
    Point(){ x = y = 0; }
    Point( ld x , ld y ) : x( x ) , y( y ) {}
    ld dist(){  return hypot( x , y ); }
    Point unit(){ ld k  = dist() ; return equals( k , 0 ) ? Point() : Point( x/k , y/k ); }
    Point ort(){ return Point( -y , x ); }
    void print(){ printf( "punto : %.4f %.4f\n" , (double)x , (double)y );}
};
typedef Point Vector;
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }
bool  operator <( const Point &A , const Point &B ){ return equals( A.x , B.x ) ? A.y < B.y : A.x < B.x ; }
 
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
 
bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
    return equals( cross(P2 - P1, P4 - P3) , 0 );
}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
    return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool between( const Point &A , const Point &B , const Point &P ){
    return  LessEquals( min( A.x , B.x ) , P.x ) && LessEquals( P.x , max( A.x , B.x ) ) && 
            LessEquals( min( A.y , B.y ) , P.y ) && LessEquals( P.y , max( A.y , B.y ) );
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
    return equals( area( A , B , P ) , 0 ) && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
    ld A1 = area( P3 , P4 , P1 );
    ld A2 = area( P3 , P4 , P2 );
    ld A3 = area( P1 , P2 , P3 );
    ld A4 = area( P1 , P2 , P4 );
    if( ( ( A1 > EPS && A2 < -EPS ) || ( A1 < -EPS && A2 > EPS ) ) && 
        ( ( A3 > EPS && A4 < -EPS ) || ( A3 < -EPS && A4 > EPS ) ) ) return 1;
    if( onSegment( P3 , P4 , P1 ) ) return 1;
    if( onSegment( P3 , P4 , P2 ) ) return 1;
    if( onSegment( P1 , P2 , P3 ) ) return 1;
    if( onSegment( P1 , P2 , P4 ) ) return 1;
    return 0;
}
inline int inc( int a , int b ){ return a + 1 == b ? 0 : (a + 1);}

typedef vector< Point > Polygon;

bool pointInPoly( const Polygon &P , const Point &A ){
    int n = SZ( P ) , cnt = 0;
    REP( i , n ){
        int inf = i , sup = inc( i , n );
        if( P[ inf ].y > P[ sup ].y ) swap( inf , sup );
        if( P[ inf ].y <= A.y && A.y < P[ sup ].y )
            if( area( A , P[ inf ] , P[ sup ] ) > EPS )
                cnt++;
    }
    return cnt & 1;
}

Polygon ConvexHull( Polygon P ){
    sort( all( P ) );
    int n = SZ( P ) , k = 0;
    Polygon H( n << 1 );
    REP( i , n ){
        while( k >= 2 && LessEquals( area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) , 0 ) ) k --;
        H[ k ++ ] = P[ i ];
    }
    for( int i = n - 2 , len = k ; i >= 0 ; --i ){
        while( k > len && LessEquals( area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) , 0 ) ) k --;
        H[ k ++ ] = P[ i ];
    }
    if( !SZ( H ) ) return Polygon();
    H.resize( k - 1 );
    return H;
}


ld area( const Polygon &P ){
    ld ans = 0; int n = SZ( P );
    REP( i , n ) ans += area( Point() , P[ i ] , P[ inc( i , n ) ] );
    return abs( ans );
}

bool allCollinear( const Polygon &P ){
    int n = SZ( P );
    if( n <= 2 ) return 1;
    for( int i = 2 ; i < n ; ++i )
        if( abs( area( P[ 0 ] , P[ 1 ] , P[ i ] ) ) > EPS ) return 0;
    return 1;
}

ld solve( const Polygon &P , const Polygon &Q ){
    Polygon I;
    int n = SZ( P ) , m = SZ( Q );
    REP( i , n ) if( pointInPoly( Q , P[ i ] ) ) I.pb( P[ i ] );
    REP( i , m ) if( pointInPoly( P , Q[ i ] ) ) I.pb( Q[ i ] );
    REP( i , n ) REP( j , m ) if( onSegment( P[ i ] , P[ inc( i , n ) ] , Q[ j ] ) ) I.pb( Q[ j ] );
    REP( i , m ) REP( j , n ) if( onSegment( Q[ i ] , Q[ inc( i , m ) ] , P[ j ] ) ) I.pb( P[ j ] ); 
    
    REP( i , n ) REP( j , m ) 
        if( !isParallel( P[ i ] , P[ inc( i , n ) ] , Q[ j ] , Q[ inc( j , m ) ] ) && 
            intersects( P[ i ] , P[ inc( i , n ) ] , Q[ j ] , Q[ inc( j , m ) ] ) ) 
                I.pb( lineIntersection( P[ i ] , P[ inc( i , n ) ] , Q[ j ] , Q[ inc( j , m ) ] ) );
    if( allCollinear( I ) ) return 0;
    I = ConvexHull( I );
    return area( I );
}

void impr( ld x ){ printf( "%.10f\n" , (double)x );}

int main(){
    int n;
    while( sc( n ) == 1 ){
        Polygon P;
        REP( i , n ){
            double x , y;
            scanf( "%lf%lf" , &x , &y );
            P.pb( Point( x , y ) );
        }
        double x , y , d , L = 1e8;
        scanf( "%lf%lf" , &x , &y );
        Point A( x , y );
        scanf( "%lf%lf" , &x , &y );
        Point B( x , y );
        scanf( "%lf" , &d );
        Vector V = (B - A).unit();
        Point C = A + ( V.ort() * d );
        Point D = A - ( V.ort() * d );
        Polygon rectangle;
        
        rectangle.pb( C - (V * L) );
        rectangle.pb( C + (V * L) );
        rectangle.pb( D - (V * L) );
        rectangle.pb( D + (V * L) );      
        ld S = area( P );
        ld I = 0;
        
        REP( i , n ) {
            Polygon triangle;
            triangle.pb( Point() ) , triangle.pb( P[ i ] ) , triangle.pb( P[ inc( i , n ) ] );
            ld sign = area( Point() , P[ i ] ,P[ inc( i , n ) ] );
            if( equals( sign , 0 ) ) continue;
            if( Less( 0 , sign ) ) I += solve( triangle , rectangle );
            else I -= solve( triangle , rectangle );
        }
        I = abs( I );
        impr( (S - I)/2.0 );
    }
}

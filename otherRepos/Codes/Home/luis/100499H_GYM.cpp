#include<bits/stdc++.h>
using namespace std ;
 
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
 
#define all( v ) v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)v.size())
 
#define EPS (1e-10)
#define PI (acos(-1.0))
 
typedef double ld;
 
inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }
struct Point
{
    ld x , y;
    Point(){ x = y = 0; }
    Point( ld x , ld y ) : x( x ) , y( y ) {}
    ld arg(){ return atan2( y , x ); }
    ld get_angle(){
        ld t = arg();
        if( abs( t - PI ) < EPS )return 0;
        if( t < -EPS ) return t + PI ;
        return t;
    }
    ld dist2(){ return x*x +y*y; }
    ld dist(){  return sqrt( dist2() ); }
    Point unit(){ ld k  = dist() ; return abs( k ) < EPS ? Point():Point( x/k , y/k ); }
    Point ort(){ return Point( -y , x ); }
    void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
typedef Point Vector;
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
bool operator <( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y : A.x < B.x ; }
bool operator ==(const Point &A, const Point &B){ return equals( A.x , B.x ) && equals( A.y , B.y );}
bool operator !=(const Point &A, const Point &B){ return !(A == B);}
ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
 
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
    return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool between( const Point &A , const Point &B , const Point &P ){
    return  min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
            min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
    return abs( area( A , B , P ) ) < EPS && between( A , B , P );
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
Point O;
 
bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4){
    return abs( cross(P2 - P1, P4 - P3) ) <= EPS;
}
bool sameLine(Point P1, Point P2, Point P3, Point P4)
{
	return area(P1, P2, P3) == 0 && area(P1, P2, P4) == 0;
}
bool valid( ld a , ld b ){
    return LessOrEquals( 0 , a ) && LessOrEquals( a , b );
}
bool inside( ld x , ld y , ld R , ld C ){
    return valid( x , R ) && valid( y , C );
}

vector< Point > lA , lB , lineA , lineB;
int IT = 10000000;
ld solve( ld xx , ld yy , ld R , ld C ){
    O = Point( xx , yy );
    //cout << "Origen : ";O.print();
    ld delta = (2.0 * PI) / IT , ans = 0;
    Point P;
    int it = IT;
    for( ld t = 0 ; it >= 0 ; t += delta , it -- ){
		Vector V( cos( t ) , sin( t ) );
		bool done = 0;
		REP( i , 4 ){
			if( sameLine( O , O + V , lA[ i ] , lB[ i ] ) ) continue;
			if( isParallel( O , O + V , lA[ i ] , lB[ i ] ) ) continue;
			Point I = lineIntersection( O , O + V , lA[ i ] , lB[ i ] );
			if( I == O ) continue;
			if( dot( V , (I - O) ) < EPS ) continue;
			if( inside( I.x , I.y , R , C ) ){
				P = I;
				done = 1;
				break;
			}
		}
		if( !done ) continue;
		//P.print();
		REP( i , SZ( lineA ) ){
			if( sameLine( O , O + V , lineA[ i ] , lineB[ i ] ) ) {
				//if( (lineA[ i ] - O).arg() < (P - O).arg() ) P = lineA[ i ];
				//if( (lineB[ i ] - O).arg() < (P - O).arg() ) P = lineB[ i ];
			}else{
				Point I = lineIntersection( O , O + V , lineA[ i ] , lineB[ i ] );
				if( I == lineA[ i ] || I == lineB[ i ] ) continue;
				if( onSegment( lineA[ i ] , lineB[ i ] , I ) ){
					if( (I - O).dist() < (P - O).dist() ) P = I;
				}
			}
		}
		//P.print();
		ans += (P - O).dist2();
	}
    return (ans * delta) / 2.0 ;
}
int main(){
    int cases;
    cin >> cases;
    for( int tc = 0 ; tc < cases ; ++tc ){
        int n;
        int R , C;
        cin >> R >> C;
        lA.clear() , lB.clear();
        lA.pb( Point( 0 , 0 ) ) , lB.pb( Point( R , 0 ) );
        lA.pb( Point( R , 0 ) ) , lB.pb( Point( R , C ) );
        lA.pb( Point( R , C ) ) , lB.pb( Point( 0 , C ) );
        lA.pb( Point( 0 , C ) ) , lB.pb( Point( 0 , 0 ) );
        cin >> n;
        lineA.clear() , lineB.clear();
        for( int i = 0 ; i < n ; ++ i ){
            int xlo , ylo , xhi , yhi;
            cin >> xlo >> ylo >> xhi >> yhi;

            lineA.pb( Point( xlo , ylo ) ) , lineB.pb( Point( Point( xhi , ylo ) ) );
            lineA.pb( Point( xhi , ylo ) ) , lineB.pb( Point( Point( xhi , yhi ) ) );
            lineA.pb( Point( xhi , yhi ) ) , lineB.pb( Point( Point( xlo , yhi ) ) );
            lineA.pb( Point( xlo , yhi ) ) , lineB.pb( Point( Point( xlo , ylo ) ) );
		}
        ld ans1 = solve( 0 , 0 , R , C );
        ld ans2 = solve( R , 0 , R , C );
        ld ans3 = solve( 0 , C , R , C );
        ld ans4 = solve( R , C , R , C );
        printf( "%.10f %.10f\n" , (double) ans3, (double)ans4 );
        printf( "%.10f %.10f\n" , (double) ans1 , (double)ans2 );
    }
}
 
 

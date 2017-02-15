#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define EPS (1e-8)
#define PI acos(-1.0)

#define Vector Point

typedef long double ld;
typedef long long ll;
typedef vector< int > vi;

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
	ld mod2(){ return x * x +y * y; }
	ld mod(){  return hypot( x , y ); }
	Point unit(){ ld k  = mod() ; return abs( k ) < EPS ? Point():Point( x/k , y/k ); }
	Point ort(){ return Point( -y , x ); }
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
Point operator /( const Point &A , const ld &k ){ return Point( A.x/k , A.y/k );}
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
			min( A.y , B.y ) < P.y + EPS && P.y < max( A.y , B.y ) + EPS;
}
vector< Point > lineCircleIntersection( Point A , Point B , Point O , ld R ){
	Vector V = ( B - A ).ort();
	Point H = lineIntersection( A , B , O , O + V );
	if( R < ( O - H ).mod() - EPS ) return vector< Point >();
	if( abs( R - ( O - H ).mod() ) < EPS ) return vector< Point >( 1 , H );
	vector< Point > ans;
	Point P , Q;
	Vector W = ( B - A ).unit();
	ld d = sqrt( R*R - ( O - H ).mod2() );
	P = H + W*d , Q = H - W*d;
	ans.pb( P ) , ans.pb( Q );
	return ans;
}
int main(){
	Point A , B;
	ld L;
	double x , y;
	while( scanf( "%lf%lf" , &x , &y ) == 2 ){
		A = Point( x , y );
		scanf( "%lf%lf" , &x , &y );
		B = Point( x , y );
		scanf( "%lf" , &x );
		L = x;
		if( A.x > B.x ) swap( A , B );
		//printf( "%.10lf %.10f\n" , (double)((B - A).mod()) , (double)L );
		if( LessOrEquals( L , (B - A).mod() ) ){
			if( A.y > B.y ) swap( A , B );
			printf( "%.10lf %.10lf\n" , (double)A.x , (double)A.y );
			continue;
		}
		vector< Point > vec = lineCircleIntersection( B , B + Vector( 0 , 1 ) , A , L );
		Point C( 0 , 1e50 );
		for( Point p : vec )
			if( p.y < C.y ) C = p;
		Point D = (B + C)/2.0;
		Point I = lineIntersection( A , C , D , D + Vector( 1 , 0 ) );
		//cout << I.x << " " << I.y << '\n';
		printf( "%.10lf %.10lf\n" , (double)I.x , (double)I.y );
	}
}



#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

#define EPS (1e-8)
#define PI acos(-1.0)

#define Vector Point

typedef long double ld;

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
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
bool operator <( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y : A.x < B.y ; }

ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }

Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) < P.x + EPS && P.x < max( A.x , B.x ) + EPS &&
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

vector< Point > lineCircleIntersection( Point A , Point B , Point O , ld R ){
	Vector V = ( B - A ).ort();
	Point H = lineIntersection( A , B , O , O + V );
	if( R < ( O - H ).dist() - EPS ) return vector< Point >();
	if( abs( R - ( O - H ).dist() ) < EPS ) return vector< Point >( 1 , H );
	vector< Point > ans;
	Point P , Q;
	Vector W = ( B - A ).unit();
	ld d = sqrt( R*R - ( O - H ).dist2() );
	P = H + W*d , Q = H - W*d;
	ans.pb( P ) , ans.pb( Q );
	return ans;
}
int main()
{
	int n , a , b , c;
	while( cin >> n >> a >> b >> c ){
		
	}
}



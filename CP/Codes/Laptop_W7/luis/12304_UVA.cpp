#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

using namespace std;

typedef long double ld;

#define Vector Point
#define PI (acos( -1.0 ))
#define EPS (1e-8)

struct Point
{
	ld x , y;
	Point(){};
	Point( ld x , ld y ):x( x ) , y( y ){}
	Point ort(){ return Point( -y , x ); }
	ld arg(){ return atan2( y , x ); }
	ld get_angle(){ 
		ld t = arg();
		if( abs( t - PI ) < EPS )return 0;
		if( t < -EPS ) return t + PI ; 
		return t;
	}
	ld norm(){ return sqrt( x*x + y*y ); }
	Point unit(){ ld k = norm() ; return Point( x/k , y/k );}
	void read(){ cin >> x >> y; }
};
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k );}
Point operator /( const Point &A , const ld &k ){ return Point( A.x/k , A.y/k );}
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
bool operator <( const Point &A , const Point &B ){ return mp( A.x , A.y ) < mp( B.x , B.y ); }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
ld dist( const Point &A , const Point &B ){ return sqrt( dot( B - A , B - A ) ); }
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
Vector Bis( const Point &A , const Point &B , const Point &C ){
	Vector V = ( B - A ) , W = ( C - A );
	Vector uV = V.unit() , uW = W.unit();
	return uV + uW;
}
ld distPointLine( const Point &A , const Point &B , const Point &P ){
	ld S = abs( area( A , B , P ) );
	ld L = dist( A , B );
	return S / L;
}

void CircumscribedCircle()
{
	Point X1 , X2 , X3;
	X1.read() , X2.read() , X3.read();
	Point N = ( X1 + X2 )/2.0 , M = ( X1 + X3 )/2.0;
	Point V = ( X2 - X1 ) , W = ( X3 - X1 );
	Point Inter = lineIntersection( N , N + V.ort() , M , M + W.ort() );
	printf( "(%.6f,%.6f,%.6f)\n" , double( Inter.x ) , double( Inter.y ) , double( dist( Inter , X1 ) ) );
}
void InscribedCircle()
{
	Point X1 , X2 , X3;
	X1.read() , X2.read() , X3.read();
	Vector V = Bis( X1 , X2 , X3 ) , W = Bis( X2 , X1 , X3 );
	Point Inter = lineIntersection( X1 , X1 + V , X2 , X2 + W );
	printf( "(%.6f,%.6f,%.6f)\n" , double( Inter.x ) , double( Inter.y ) , double( distPointLine( X1 , X2 , Inter ) ) );
}
void TangentLineThroughPoint()
{
	Point P , C;
	ld R;
	C.read() , cin >> R , P.read();
	Vector PC = C - P;
	ld dPC2 = dot( PC , PC );
	if( dPC2 >= R*R + EPS )
	{
		ld L = sqrt( dPC2 - R*R );
		ld ux , uy;
		ux = cross( PC , Point( -R , L ) )/dPC2;
		uy = cross( Point( L , R ) , PC )/dPC2;
		ld ang1 = Point( ux , uy ).get_angle()/PI*180.0;
		ux = cross( PC , Point( R , L ) )/dPC2;
		uy = cross( Point( L , -R ) , PC )/dPC2;
		ld ang2 = Point( ux , uy ).get_angle()/PI*180.0;
		if( ang1 > ang2 )swap( ang1 , ang2 );
		printf( "[%.6f,%.6f]\n" , double( ang1 ) , double( ang2 ) );
	}
	else if( abs( dPC2 - R*R ) <= EPS )
	{
		ld ang = PC.ort().get_angle()/PI*180.0;
		printf( "[%.6f]\n" , double( ang ) );
	}
	else puts( "[]" );
}
void CircleThroughAPointAndTangentToALineWithRadius()
{
	Point P , X1 , X2 ;
	ld R;
	P.read() , X1.read() , X2.read() , cin >> R;
	Vector w = ( X2 - X1 ).unit();
	Vector v = w.ort();
	if( distPointLine( X1 , X2 , P ) > 2*R + EPS ) puts( "[]" );
	else if( abs( area( X1 , X2 , P ) ) < EPS )
	{
		Point P1 = P - v*R , P2 = P + v*R;
		if( P2 < P1 )swap( P1 , P2 );
			printf( "[(%.6f,%.6f),(%.6f,%.6f)]\n" , double( P1.x ) , double( P1.y ) , double( P2.x ) , double( P2.y ) );
	}
	else
	{
		Point Q;
		if( area( X1 , X2 , P ) > 0 )
			Q = X1 + v*R;
		else Q = X1 - v*R;
		Point Inter = lineIntersection( Q , Q + w , P , P + v );
		ld H = dist( Inter , P );
		ld L = sqrt( R*R - H*H );
		if( L < EPS ) printf( "[(%.6f,%.6f)]\n" , double( Inter.x ) , double( Inter.y ) );
		else{
			Point P1 = Inter - w*L , P2 = Inter + w*L;
			if( P2 < P1 )swap( P1 , P2 );
			printf( "[(%.6f,%.6f),(%.6f,%.6f)]\n" , double( P1.x ) , double( P1.y ) , double( P2.x ) , double( P2.y ) );
		}
	}
}
void CircleTangentToTwoLinesWithRadius()
{
	Point X1 , X2 , X3 , X4;
	ld R;
	X1.read() , X2.read() , X3.read() , X4.read();
	cin >> R;
	Point Inter = lineIntersection( X1 , X2 , X3 , X4 );
	Vector v = ( X2 - X1 ).unit() , w = ( X4 - X3 ).unit();
	Vector u  = ( v + w ).unit();
	ld sent = abs( cross( v , u ) );
	Point P1 = Inter + u*(R/sent);
	Point P2 = Inter - u*(R/sent);
	u = u.ort();
	ld senp = sqrt( 1 - sent*sent );
	Point P3 = Inter + u*(R/senp);
	Point P4 = Inter - u*(R/senp);
	Point A[4] = { P1 , P2 , P3 , P4 };
	sort( A , A + 4 );
	REP( i , 4 )
		printf( "%s(%.6f,%.6f)%s" , (i==0?"[":"") , double( A[i].x ), double( A[i].y ) , (i+1==4?"]\n":",") );
}
void CircleTangentToTwoDisjointCirclesWithRadius()
{
	Point A , B;
	ld R1 , R2 , R;
	A.read() , cin >> R1;
	B.read() , cin >> R2;
	cin >> R;
	ld dAB = dist( A , B );
	if( 2*R < dAB - R1 - R2 - EPS )puts( "[]" );
	else
	{
		ld a = R + R1 , c = R + R2 , b = dAB;
		ld u = ( a*a + b*b - c*c )/(2*b);
		ld H = sqrt( a*a - u*u );
		Vector V = ( B - A ).unit();
		Vector W = V.ort();
		Point P = A + (V*u) + (W*H);
		Point Q = A + (V*u) - (W*H);
		if( Q < P )swap( P , Q );
		if( H < EPS )printf( "[(%.6f,%.6f)]\n" , double( P.x ) , double( P.y ) );
		else printf( "[(%.6f,%.6f),(%.6f,%.6f)]\n" , double( P.x ) , double( P.y ) ,double( Q.x ) , double( Q.y ) );
	}
}

int main()
{
	sync
	string s ;
	while( cin >> s )
	{
		if( s == "CircumscribedCircle" ) CircumscribedCircle();
		else if( s == "InscribedCircle" ) InscribedCircle();
		else if( s == "TangentLineThroughPoint" ) TangentLineThroughPoint();
		else if( s == "CircleThroughAPointAndTangentToALineWithRadius" ) CircleThroughAPointAndTangentToALineWithRadius();
		else if( s == "CircleTangentToTwoLinesWithRadius" ) CircleTangentToTwoLinesWithRadius();
		else if( s == "CircleTangentToTwoDisjointCirclesWithRadius" ) CircleTangentToTwoDisjointCirclesWithRadius();
	}
}




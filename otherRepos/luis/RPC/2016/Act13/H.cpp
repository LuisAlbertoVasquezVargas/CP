#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

const ld EPS = 1e-6;
const ld PI = acos(-1.0);

inline bool equals( ld x , ld y ){ return abs( x - y ) < EPS; }
inline bool Less( ld x , ld y ){ return x < y - EPS; }
inline bool LessOrEquals( ld x , ld y ){ return Less( x , y ) || equals( x , y ); }
struct Point{
	ld x , y;
	Point(){ x = y = 0; }
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return hypot( x , y );}
	Point ort(){ return Point( -y , x ); }
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
typedef Point Vector;
Point operator - ( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator + ( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator * ( const Point &A , const ld &k ){ return Point( A.x * k , A.y * k ); }
bool operator == ( const Point &A , const Point &B ){ return equals( A.x , B.x ) && equals( A.y , B.y ) ; }

ld dot( const Point &A , const Point &B ){ return A.x * B.x + A.y * B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x * B.y - A.y * B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
ld dist( const Point &A , const Point &B ){ return (B - A).dist();}
bool operator <( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y : A.x < B.x ; }

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

typedef vector< Point > Polygon;
vector< Point > cutPolygon( Point a , Point b , Polygon Q ) {
	vector< Point > P;
	REP( i , SZ(Q) ){
		ld left1 = cross( b - a , Q[ i ] - a ) , left2 = 0;
		if( i != SZ(Q) - 1 ) left2 = cross( b - a , Q[ i + 1 ] - a );
		if( left1 > -EPS ) P.push_back( Q[ i ] );
		if (left1 * left2 < -EPS)
		P.push_back( lineIntersection( Q[ i ] , Q[ i + 1 ] , a , b ) );
	}
	
	if( !P.empty() && !(P.back() == P.front()) )
		P.push_back( P.front() );
	
	// make P’s first point = P’s last point
	return P;
}
ld area( vector<Point> &Poly ){
	int nP = Poly.size();
	ld ans = 0;
	REP( i , nP - 1)ans += area( Point(0,0) , Poly[i] , Poly[(i+1)%nP] );
	return abs( ans )/2.0;
}
void impr(vector<Point> &Poly){
	int nP = Poly.size();
	REP( i , nP - 1)cout<<"("<<Poly[i].x<<","<<Poly[i].y<<") ";
	cout<<'\n';
}
int main(){
	int R=100;
	vector<Point>A,B;
	A.push_back(Point(+R,-0.5));B.push_back(Point(-R,-0.5));//1
	A.push_back(Point(-R,+0.5));B.push_back(Point(+R,+0.5));//6
	A.push_back(Point(+0.5,+R));B.push_back(Point(+0.5,-R));//3
	A.push_back(Point(-0.5,-R));B.push_back(Point(-0.5,+R));//4
	vector<ld>val={1,6,3,4};
	vector<Point>P(5);
	while(cin>>P[0].x>>P[0].y){
		for(int k=1;k<4;++k)cin>>P[k].x>>P[k].y;
		P[4]=P[0];
		
		ld sum=(4*5*5)*5;
		//DEBUG(area(P));
		//impr(P);
		REP(k,4){
			vector<Point>newP=cutPolygon(A[k],B[k],P);
			//impr(newP);
			//DEBUG(area(newP));
			sum+=area(newP)*val[k]*5.0;
		}
		sum/=(5*5*5-1);
		printf("%.17f\n",(double)sum);
	}
}



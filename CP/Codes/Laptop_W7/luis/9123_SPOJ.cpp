#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 65

typedef long double ld;

#define Vector Point
#define PI acos( -1.0 )
#define EPS 1e-6

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld norm() { return sqrt( x*x + y*y ); }
	ld arg(){ return atan2( y , x ); }
	Point unit(){ ld K = norm() ;return Point( x/K  , y/K ); }
	Point ort(){ return Point( -y , x );}
	ld get_angle(){ 
		ld t = arg();
		if( t < 0 )t += 2*PI;
		return t;
	}
	void read(){ cin >> x >> y; }
	void print(){ printf( "%.4f %.4f - " , double( x ) , double( y ) ); }
};
Point operator *( const Point &A , const ld K ){ return Point( A.x*K, A.y*K ); }
Point operator /( const Point &A , const ld K ){ return Point( A.x/K, A.y/K ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }

bool operator <(const Point &a, const Point &b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y;}

ld dist( const Point &A , const Point &B ){ return ( B - A ).norm(); }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
Vector rot( Vector V , ld senA , ld cosA )
{
	return Point( V.x*cosA - V.y*senA , V.x*senA + V.y*cosA );
}
Point Points[ N ];
ld Radius[ N ];

Point Poly[ N*N ];
Point CPoly[ N*N ];
int idCPoly[ N*N ];
int idCircle[ N*N ];
int T;

void Insert( Point P, int idp )
{
	Poly[ T ] = P;
	idCircle[ T ] = idp;
	T++;
}
void solve( Point P , Point Q , int RP , int RQ , int idP , int idQ )
{
	if( RP > RQ ) swap( P , Q ) , swap( RP , RQ ) , swap( idP , idQ );
	if( RP == RQ )
	{
		Vector u = ( Q - P ).unit().ort();
	
		Point P1 = P + u*( RP );
		Point Q1 = Q + u*( RQ );
		Point P2 = P - u*( RP );
		Point Q2 = Q - u*( RQ );
		
		Insert( P1 , idP );
		Insert( Q1 , idQ );
		Insert( P2 , idP );
		Insert( Q2 , idQ );

		return;
	}
	ld dPQ = dist( P , Q );
	ld senA = (RQ - RP)/dPQ;
	ld X = RP/senA;
	ld HP = sqrt( X*X - RP*RP );
	ld HQ = (RQ*HP)/RP;
	Vector u = ( Q - P ).unit();
	Vector v = rot( u , senA , sqrt( 1 - senA*senA ) );
	Vector w = rot( u , -senA , sqrt( 1 - senA*senA ) );
	
	Point A = Q - u*( X + dPQ );
	
	Point P1 = A + v*( HP );
	Point Q1 = A + v*( HQ );
	Point P2 = A + w*( HP );
	Point Q2 = A + w*( HQ );
	
	Insert( P1 , idP );
	Insert( Q1 , idQ );
	Insert( P2 , idP );
	Insert( Q2 , idQ );

}
int ind[ N*N ];
bool cmp( int i , int j ){ return Poly[ i ] < Poly[ j ]; }
void ConvexHull( )
{
	REP( i , T ) ind[ i ] = i;
    sort( ind , ind + T , cmp );
    int nP = T , k = 0;
    Point H[ 2*nP ];
    int G[ 2*nP ];
    for( int i = 0 ; i < nP ; ++i ){
        while( k >= 2 && area( H [ k - 2 ] , H[ k - 1 ] , Poly[ ind[ i ] ] ) <= EPS ) --k;
        H[ k ] = Poly[ ind[ i ] ] , G[ k++ ] = ind[ i ];
    }
    for( int i = nP - 2 , t = k ; i >= 0 ; --i ){
        while( k > t && area( H[ k - 2 ] , H[ k - 1 ] , Poly[ ind[ i ] ] ) <= EPS ) --k;
        H[ k ] = Poly[ ind[ i ] ] , G[ k++ ] = ind[ i ];
    }
	T = k - 1;
	REP( i , T ) CPoly[ i ] = H[ i ] , idCPoly[ i ] = G[ i ];
}
ld f( Point A , Point P , Point B )
{
	Vector V = ( A - P ).unit() , W = ( B - P ).unit();
	Vector VR = rot( W , -V.y , V.x );
	return VR.get_angle();
}
void solve()
{
	int n;
	cin >> n;
	REP( i , n ) Points[ i ].read() , cin >> Radius[ i ];
	if( n == 1 )
	{
		printf( "%.10f\n" , double( 2*PI*Radius[ 0 ] ) );
		return;
	}
	T = 0;
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++j )
		{
			Point P , Q ;
			int RP , RQ;
			P = Points[ i ] , RP = Radius[ i ];
			Q = Points[ j ] , RQ = Radius[ j ];
			
			solve( P , Q , RP , RQ , i , j );
		}
	ConvexHull();
	ld ans = 0;
	REP( i , T ) {
		int a = i , b = ( i + 1 )%T;
		int ida = idCircle[ idCPoly[ a ] ] , idb = idCircle[ idCPoly[ b ] ];
		if( ida != idb )
			ans += dist( CPoly[ a ] , CPoly[ b ] );
		else ans += f( CPoly[ a ] , Points[ ida ] , CPoly[ b ] )*Radius[ ida ];
	}
	printf( "%.10f\n" , double( ans ) );
}
int main()
{
	int tc;
	
	cin >> tc;
	while( tc-- )
		solve();	
}

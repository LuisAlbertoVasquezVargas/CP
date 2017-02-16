#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define EPS (1e-8)

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	void read(){ cin >> x >> y; }
};
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
ld cross( const Point &A , const Point &B ){ return  A.x*B.y - A.y*B.x ; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
bool pointInPoly(const vector <Point> &P, const Point &A)
{
    int nP = P.size(), cnt = 0;
    for(int i=0; i<nP; i++)
    {
        int inf = i, sup = (i+1)%nP;
        if(P[inf].y > P[sup].y) swap(inf, sup);
        if(P[inf].y <= A.y && A.y < P[sup].y)
            if(area(A, P[inf], P[sup]) > 0)
                cnt++;
    }
    return (cnt % 2) == 1;
}
bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}
bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}
int main()
{
	Point A , B , C;
	while( 1 )
	{
		A.read() , B.read() , C.read();
		if( A.x < EPS && A.y < EPS && B.x < EPS && B.y < EPS && C.x < EPS && C.y < EPS ) break;
		vector< Point >Poly;
		Poly.push_back( A );
		Poly.push_back( B );
		Poly.push_back( C );
		int ans = 0;
		int lox = floor( min( A.x , min( B.x , C.x ) ) );
		int hix = ceil( max( A.x , max( B.x , C.x ) ) );
		int loy = floor( min( A.y , min( B.y , C.y ) ) );
		int hiy = ceil( max( A.y , max( B.y , C.y ) ) );		
		ld S = abs( area( A , B , C ) );
		for( int i = lox ; i <= hix ; i++ )
			for( int j = loy ; j <= hiy ; ++j )
			{
				Point P = Point( i , j );
				if( abs( abs( area( A , B , P ) ) + abs( area( A , C , P ) ) + abs( area( B , C , P ) ) - S ) <= EPS )
					ans++;
				//if( pointInPoly( Poly , P ) || onSegment( A , B , P ) || onSegment( A , C , P ) || onSegment( B , C , P ) ) ans++;
			}
		printf( "%4d\n" , ans );
	}
}


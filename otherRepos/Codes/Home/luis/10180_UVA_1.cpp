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

#define Vector Point
#define EPS (1e-7)
#define PI acos( -1.0 )

struct Point
{
	double x , y;
	Point(){}
	Point( double x , double y ):x(x),y(y){}
	Point ort(){ return Point( -y , x ); }
	double norm(){ return sqrt(x*x+y*y);}
	double arg(){ return atan2( y , x ); }
};
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ) ; }
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ) ; }
Point operator *( const Point &A , const double k ){ return Point( A.x*k , A.y*k ) ; }
Point operator /( const Point &A , const double k ){ return Point( A.x/k , A.y/k ) ; }
double dot( const Vector &A , const Vector &B ){ return A.x*B.x + A.y*B.y ; }
double cross( const Vector &A , const Vector &B ){ return A.x*B.y - A.y*B.x ; }
double area( const Vector &A , const Vector &B , const Point &C ){ return cross( C - A , B - A );}
double dist( const Point &A , const Point &B ){ return sqrt( dot( A - B, A - B ) ); }
bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}

//### DETERMINA SI EL SEGMENTO P1Q1 SE INTERSECTA CON EL SEGMENTO P2Q2 #####################
bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);
    
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
            return true;
    
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}
double get_angle( Point A , Point P , Point B )
{
	double ang = (A-P).arg() - (B-P).arg(); 
	while(ang < 0) ang += 2*PI; 
	while(ang > 2*PI) ang -= 2*PI;
	return min(ang, 2*PI-ang);
}
Point O( 0 , 0 );
int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		double R;
		Point A, B;
		scanf( "%lf%lf" , &A.x , &A.y );
		scanf( "%lf%lf" , &B.x , &B.y );
		scanf( "%lf" , &R );
		Point I = lineIntersection( A , B , O , (B-A).ort() );
		double d = dist( A , B );
		//double H = abs(area(O,A,B)/(2*d));
		double H = dist( I , O );
		double ans ;
		if( H >= R - EPS )ans = d;
		else
		{
			
			if( !onSegment( A , B , I ) )
				ans = d;
			else
			{
				//double cost = dot( A , B )/(A.norm()*B.norm());
				//double t = acos( t );
				double t = get_angle( A , O , B );
				double PA = dist( O , A );
				double PB = dist( O , B );
				double t1 = acos( R/PA );
				double t2 = acos( R/PB );
				ans = sqrt( PB*PB - R*R ) + sqrt( PA*PA - R*R ) + R*( t - t1 - t2 ); 
			}
		}
		printf( "%.3lf\n" , ans );
	}
}




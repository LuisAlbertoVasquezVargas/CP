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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)

using namespace std;

int a , b , ns ;
string s;
int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };
string d = "UDLR";
map< char , int >M;

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
bool operator ==(const Point &a, const Point &b){ return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;}
bool operator !=(const Point &a, const Point &b){ return !(a==b);}
bool operator <(const Point &a, const Point &b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y;}
double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

double get_angle( Point A , Point P , Point B )
{
	double ang = (A-P).arg() - (B-P).arg(); 
	while(ang < 0) ang += 2*PI; 
	while(ang > 2*PI) ang -= 2*PI;
	return min(ang, 2*PI-ang);
}
bool isInt(double k){	return abs(k - int(k + 0.5)) < 1e-5;}
/////
//responde si un punto esta en un poligono convexo incluyendo la frontera
bool isIn( Point O , Point A , Point B , Point X )
{
	return abs( abs( area(O,A,B)) -( abs(area(O,A,X)) + abs(area(A,B,X)) + abs(area(O,B,X)) ) ) < EPS ;
}
// transforma el angulo de atan2 al rango 0 - 2PI
double f( double a )
{
	if( a < 0 )a += 2*PI;
	return a;
}
////////////////////////////////////////////////////////////////////////////////
// Heron triangulo y cuadrilatero ciclico
// http://mathworld.wolfram.com/CyclicQuadrilateral.html
// http://www.spoj.pl/problems/QUADAREA/
double areaHeron(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}

double circumradius(double a, double b, double c) { return a * b * c / (4 * areaHeron(a, b, c)); }

double areaHeron(double a, double b, double c, double d)
{
	double s = (a + b + c + d) / 2;
	return sqrt((s-a) * (s-b) * (s-c) * (s-d));
}

double circumradius(double a, double b, double c, double d) { return sqrt((a*b + c*d) * (a*c + b*d) * (a*d + b*c))  / (4 * areaHeron(a, b, c, d)); }

//### DETERMINA SI P PERTENECE AL SEGMENTO AB ###########################################
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

//### DETERMINA SI A, B, M, N PERTENECEN A LA MISMA RECTA ##############################
bool sameLine(Point P1, Point P2, Point P3, Point P4)
{
	return area(P1, P2, P3) == 0 && area(P1, P2, P4) == 0;
}
//### SI DOS SEGMENTOS O RECTAS SON PARALELOS ###################################################
bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
	return abs( cross(P2 - P1, P4 - P3) ) <= EPS;
}

int main()
{
	REP( i , 4 )M[d[i]] = i;
	while( cin >> a >>  b >> s )
	{
		ns = s.size();
		Point V = Point( 0 , 0 ), A = Point( a , b ) , O = V;
		vector< Point >T( ns + 1 );
		T[0] = O;
		bool solve = 0;
		REP( i , ns )
		{
			int ind = M[s[i]];
			V = V + Point( dx[ind] , dy[ind] );
			if( V == A )solve = 1;
			T[i + 1] = V;
		}
		if( A == O || solve )
		{
			puts("Yes");
			continue;
		}

		REP( i , ns + 1 )
		{
			Point Temp = A - T[i];
			if( Temp != O && V != O  &&isParallel( O , Temp , O , V ) )
			{
				double k;
				if( abs(V.x) <= EPS )k = Temp.y/V.y;
				else k = Temp.x/V.x;
				if( isInt(k) && k >= 0 ) solve = 1;
			}
		}
		puts( solve?"Yes":"No" );
	}
}



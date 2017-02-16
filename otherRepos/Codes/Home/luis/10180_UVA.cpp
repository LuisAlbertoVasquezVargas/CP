#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
 
 
using namespace std;
 
#define EPS 1e-5
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
bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}
 
bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}
 
int tc;
Point P,Q;
double R;
double f( Point A , Point B )
{
	double ang = A.arg() - B.arg(); 
        while(ang < 0) ang += 2*PI; 
        while(ang > 2*PI) ang -= 2*PI;
        return min(ang, 2*PI-ang);
}
int main()
{
        cin >> tc;
        while( tc-- )
        {
                cin >> P.x >> P.y >> Q.x >> Q.y >> R ;
                Point O (0,0);
                Point I = lineIntersection(P,Q,O,(P-Q).ort());
                if( I.mod() + EPS >= R )
                {
                        printf( "%.3lf\n" , dist(P,Q) );
                        continue;
                }
                else if( !onSegment(P,Q,I) )
                {
                        printf( "%.3lf\n" , dist(P,Q) );
                        continue;                       
                }
                double H1 = P.mod();
                double H2 = Q.mod();
                double ans = R*( f(P,Q) - acos(R/dist(O,P)) - acos(R/dist(O,Q)) );
                printf( "%.3lf\n" , ans + sqrt( H1*H1 - R*R ) + sqrt( H2*H2 -R*R ) );
        }
}

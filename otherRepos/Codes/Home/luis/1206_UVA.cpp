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

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

using namespace std;

string s;
double x,y;


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
vector< Point >P;
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
vector <Point> ConvexHull(vector <Point> Poly)
{
    sort(Poly.begin(),Poly.end());
    int n = Poly.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    
    return vector <Point> (H,H+k-1);
}
void doit()
{
	int ns = s.size();
	for( int i = 0 ; i < ns ; ++i )
		if( s[i] == ')'|| s[i] == '(' || s[i] == ',' )
			s[i] = ' ';
	istringstream in(s);
	while( in >> x >> y)
		P.push_back(Point(x,y));
}
int main()
{
     while( getline( cin , s) )
     {
		P.clear();
		doit();
		P = ConvexHull(P);
		int nv = P.size();
		for( int i = 0 ; i < nv ; ++i )
			cout << "(" << P[i].x << "," << P[i].y << ") ";
		if( nv != 0 )
			cout << "(" << P[0].x << "," << P[0].y << ")" << endl;
	}
}

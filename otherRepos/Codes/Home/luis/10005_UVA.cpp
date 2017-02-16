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

#define N 105
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point
#define INF 1e11

using namespace std;

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

Point P[N];
int n;
double R , Rmin;

double g( Point p , Vector v , double r )
{
	double maxi = 0;
	for( int i = 0 ; i < n ; ++i )
		maxi = max( maxi , dist( p + v*r , P[i] ) );
	return maxi;
}
double f( int i , int j )
{
	Point p = ( P[i] + P[j] )/2.0;
	Vector v = ( P[i] - P[j] ).ort();
	double rlo = -INF , rhi = INF ;
	int it = 100;
	while( it-- )
	{
		double rmed1 = ( 2.0*rlo + rhi )/3.0;
		double rmed2 = ( rlo + 2.0*rhi )/3.0;
		if( g(p,v,rmed2) > g(p,v,rmed1) )
			rhi = rmed2;
		else 	rlo = rmed1;
	}
	return g(p,v,rlo);
}
int main()
{
	while( cin >> n )
	{
		if( n == 0 )break;
		for( int i = 0 ; i < n ; ++i )
			cin >> P[i].x >> P[i].y;
		cin >> R;
		Rmin = INF;
		bool ok = 0;
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
			{
				if( i == j )continue;
				double temp = f( i , j );
				Rmin = min( Rmin , temp );
				if( R + EPS >= Rmin )
				{
					ok = 1;
					break;
				}

			}
		if( ok )
			puts("The polygon can be packed in the circle.");
		else 	puts("There is no way of packing that polygon.");
	}
}

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

#define N 10
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

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

int tc , n;
double v[N];
Point P[N];

double f()
{
	double ini = 1e100 , fin = 1e-100;
	P[0] = Point(v[0],v[0]);
	for( int i = 1 ; i < n ; ++i )
	{
		if( v[i] <= v[i-1] )
			P[i] = Point( P[i-1].x + 2.0*sqrt(v[i-1]*v[i]) , v[i] );
		else
		{
			double tam = 1e100;
			Point best;
			for( int j = 0 ; j < i ; ++j )
			{
				Point p = Point( P[j].x +2.0*sqrt(v[j]*v[i]) , v[i] );
				bool ok = 1;
				for( int k = 0 ; k < i ; ++k )
					if( k != j && dist( p , P[k] ) < v[i] + v[k] )
					{
						ok = 0;
						break;
					}
				if( ok && 2.0*sqrt(v[j]*v[i]) < tam )
					best = p;	
			}
			P[i] = best;
		}
	}
	for( int i = 0 ; i < n ; ++i )
		ini = min( ini , P[i].x - v[i] ),fin = max( fin , P[i].x + v[i] );
	return fin - ini;	
}
int main()
{
	cin >> tc;
	while( tc-- )
	{
		cin >> n;
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i];
		double mini = 1e100;
		sort( v , v + n );
		do
			mini = min( mini , f() );
		while( next_permutation( v, v + n ) );
		printf("%.3lf\n" , mini );
	}
}

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

#define MAXN 100000
#define EPS 1e-6
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

bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
	return cross(P2 - P1, P4 - P3) == 0;
}
int tc;
Point  P[4];
int main()
{
	cin >> tc;
	for( int i = 1 ; i <= tc ; ++i )
	{
		for( int j = 0  ; j < 4 ; ++j )
			cin >> P[j].x >> P[j].y;
		sort(P,P+4);
		do
		{
			bool ok = 1;
			for( int j = 0  ; j < 4 ; ++j )
				if( area(P[j],P[(j+1)%4],P[(j+2)%4]) <= 0 )
					ok = 0;
			if( ok )break;
			
		}while( next_permutation(P,P+4) );
		double dist[4];
		for( int j = 0  ; j < 4 ; ++j )
			dist[j] = (P[j]-P[(j+1)%4]).mod();//,cout<<"dist : "<<j<<" "<<P[j].x<<" "<<P[j].y<<" "<<dist[j] <<endl;	
		bool eqdist = 1;
		for( int j = 0  ; j < 4 ; ++j )
			if( dist[j] != dist[(j+1)%4] )
				eqdist = 0;		
		bool rect = 1;
		for( int j = 0  ; j < 4 ; ++j )
			if( dot(P[j]-P[(j+1)%4],P[(j+1)%4]-P[(j+2)%4]) != 0 ) 
				rect = 0;
		bool paral1 = isParallel(P[0],P[1],P[2],P[3]);
		bool paral2 = isParallel(P[1],P[2],P[0],P[3]);
		cout<<"Case "<<i<<": ";
		if( rect && eqdist )
			cout<<"Square"<<endl;
		else if ( rect )
			cout<<"Rectangle"<<endl;
		else if ( eqdist && paral1 && paral2 )
			cout<<"Rhombus"<<endl;	
		else if( paral1 && paral2 )
			cout<<"Parallelogram"<<endl;
		else if ( paral1 || paral2 )
			cout<<"Trapezium"<<endl;
		else cout<<"Ordinary Quadrilateral"<<endl;
	}
}

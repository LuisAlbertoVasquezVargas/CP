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

#define MAXN 1000
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

//### FUNCIONES BASICAS #############################################################

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

double area(const vector <Point> &P)
{
    int n = P.size();
    double A = 0;
    for(int i=1; i<=n-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return abs(A/2);
}

long long IntegerPointsOnSegment(const Point &P1, const Point &P2){
    Point P = P1-P2;
    P.x = abs(P.x); P.y = abs(P.y);
   
    if( (long long)P.x == 0) return (long long)P.y;
    if( (long long)P.y == 0) return (long long)P.x;
    return (__gcd((long long)P.x,(long long)P.y));
}

/*
A = I + B/2 - 1, donde:

A = Area de un poligono de coordenadas enteras
I = Numero de puntos enteros en su interior
B = Numero de puntos enteros sobre sus bordes

Haciendo un cambio en la formula : I=(2A-B+2)/2, tenemos una forma de calcular
el numero de puntos enteros en el interior del poligono
*/
int n,x,y;
vector<Point> P;

int main()
{
     while( cin >> n )
     {
		if( n == 0 )return 0;
		P.clear();
          for( int i = 0 ; i < n ; ++i )
          {
               cin >> x >> y ;
			P.push_back(Point(x,y));
		}
          long long B = 0;		
          for( int i = 0 ; i < n ; ++i )
			B += IntegerPointsOnSegment(P[i],P[(i+1)%n]);
		long long A = (long long)(area(P)+0.5);
          cout << (2*A-B+2)/2 << endl;
     }
}

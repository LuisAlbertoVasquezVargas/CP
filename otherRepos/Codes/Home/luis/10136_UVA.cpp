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

#define N 205
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

int n, tc ,ans ,cnt;
string dummy,s;
vector<Point>P;
bool ok = 1;

void toPoint()
{
	istringstream in(s);
	double x , y;
	in >> x >> y;	
	P.push_back( Point( x , y ) );
}

void doit()
{
	n = P.size();
	ans = 1;
	for( int i = 0 ; i < n ; ++i )
		for( int j = i + 1 ; j < n ; ++j )
		{
			double L = dist(P[i],P[j]);
			double sz = sqrt(2.5*2.5-(0.5*L)*(0.5*L));
			if( L <= 5.0 )
			{
				cnt = 2;
				Point O1 = ( P[i] + P[j] )*0.5 + ( P[j] - P[i] ).ort().unit()*sz;
				for( int k = 0 ; k < n ; ++k )
					if( k!=i && k != j && dist( P[k] , O1 ) <= 2.5 )
						cnt++;
				ans = max( ans , cnt );	
				cnt = 2;
				Point O2 = ( P[i] + P[j] )*0.5 - ( P[j] - P[i] ).ort().unit()*sz;
				for( int k = 0 ; k < n ; ++k )
					if( k!=i && k != j && dist( P[k] , O2 ) <= 2.5 )
						cnt++;
				ans = max( ans , cnt );						
			}
		}
	if( ok )
		ok = 0;
	else puts("");
	cout << ans << "\n";
}
int main()
{
	cin >> tc;
	getline( cin , dummy );
	getline( cin , dummy );
	while( tc-- )
	{
		P.clear();
		while( getline( cin , s ) )
			if( s != "" )
				toPoint();
			else break;				
		doit();
	}
}

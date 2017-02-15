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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
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
#define INF 1e4
#define IT 50

using namespace std;

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

int n;
double xa , xb , ya , yb;

double g( double x  , double y )
{
	Point A , B , C , D;
	A = Point( x , 0 ) , B = Point( 0 , y ) , C = Point( xa , xb ) , D = Point( ya , yb );
	if( xa > ya )swap( C , D );
	return dist( A , B ) + dist( B , C ) + dist( C , D ) + dist( D , A );
}
double f( double y )
{
	double lo = -INF , hi = INF;
	int it = IT;
	while( it-- )
	{
		double med1 = (lo*2 + hi)/3.0 , med2 = (lo + hi*2)/3.0;
		if( g( med1 , y ) < g( med2 , y ) )
			hi = med2;
		else lo = med1;
	}
	return g( lo , y );
}
int main()
{
	cin >> n;
	while( n-- )
	{
		cin >> xa >> xb >> ya >> yb;
		double lo = -INF , hi = INF;
		int it = IT;
		while( it-- )
		{
			double med1 = (lo*2 + hi)/3 , med2 = (lo + hi*2)/3;
			if( f( med1 ) < f( med2 ) )
				hi = med2;
			else lo = med1;
		}
		printf( "%.3lf\n" , f(lo) );
	}
}

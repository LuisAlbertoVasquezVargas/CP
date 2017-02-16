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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define MAXN 105

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
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }
int n;
int id[MAXN];
void init(){ for( int i = 0 ; i < n ; ++i )id[i] = i;}
int F(int x) {return x == id[x] ? x : (id[x] = F(id[x]));}
void U(int x, int y) {id[F(x)] = F(y);}
Point P[MAXN];
double R[MAXN];
int f[MAXN];

int main()
{
	while( scanf( "%d" , &n ) == 1 )
	{
		if( n == -1 )break;
		init();
		for( int i = 0 ; i < n ; ++i )
			scanf( "%lf%lf%lf" , &P[i].x , &P[i].y , &R[i] );
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
			{
				double u = dist( P[i] , P[j] ) , v = R[i] , w = R[j];
				if( w > v )swap( w , v );
				if( v > u )swap( u , v );
				if( i != j && u < v + w && F(i) != F(j) )
					U( i , j );
			}
		me( f , 0 );
		for( int i = 0 ; i < n ; ++i )
			f[F(i)]++;		
		int ans = *max_element( f , f + n );
		printf("The largest component contains %d ring%s.\n" , ans , ans == 1 ? "":"s" );
	}
}

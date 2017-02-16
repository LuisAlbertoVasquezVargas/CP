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

#define N 55
#define MOD 1000000007
#define INF (1<<30)
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point
#define IT 200

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

vector< vector< Vector > > PP;
Point Q;
int n;

bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}
bool pointInPoly(const vector <Point> &P, const Point &A)
{
    int nP = P.size(), cnt = 0;
    for( int i = 0 ; i < nP ; i++ )
    {
        int inf = i, sup = (i+1)%nP;
        if(P[inf].y > P[sup].y) swap(inf, sup);
        if(P[inf].y <= A.y && A.y < P[sup].y)
            if(area(A, P[inf], P[sup]) > 0)
                cnt++;
    }
    return (cnt % 2) == 1;
}
bool inbound( vector <Point> &P, Point &A)
{
    int nP = P.size();
    for( int i = 0 ; i < nP ; i++ )
    {
        Point p = P[i] , q = P[(i+1)%nP];
		if( onSegment( p , q , A ) )return 1;
    }
    return 0 ;
}
double F( Point x , Point y , Point z , double t )
{
	Point r = x + ((y-x)*t);
	return dist( r , z );
}
double g( Point z , Point x , Point y )
{
	double lo = 0 , hi = 1;
	int it = IT;
	while( it-- )
	{
		double med1 = (lo*2 + hi)/3 , med2 = (lo + hi*2)/3;
		if( F( x , y , z , med1 ) < F( x , y , z , med2 ) )
			hi = med2;
		else lo = med1;
	}
	return F( x , y , z , lo );
}
double f( int i )
{
	if( pointInPoly(PP[i],Q) )return 0.0;
	if( inbound(PP[i],Q) )return 0.0;
	double mini = 1e100;	
	for( int j = 0 ; j < 4 ; ++j )
		mini = min( mini , g( Q , PP[i][j] , PP[i][(j+1)%4]) );
	return mini;	
}
void doit()
{
	vector< pair< double , int > > v( n );
	for( int i = 0 ; i < n ; ++i )
		v[i] = mp( f(i) , i + 1 );
	/*for( int i = 0 ; i < n ; ++i )
		cout << v[i].fi << ( i == (n-1) ? "\n" : " " );		*/
	sort( all( v ) );
	for( int i = 0 ; i < n ; ++i )
		cout << v[i].se << ( i == (n-1) ? "\n" : " " );
}
int main()
{
	sync
	while( cin >> n )
	{
		PP = vector< vector< Vector > >( n , vector< Vector >( 4 ) );
		for( int i = 0 ; i < n ; ++i )
		{
			cin >> PP[i][0].x >> PP[i][0].y >> PP[i][2].x >> PP[i][2].y;
			Vector u = (PP[i][2] - PP[i][0])*0.5 ,w ;
			w = u.ort();
			PP[i][1] = PP[i][0] + u + w;
			PP[i][3] = PP[i][0] + u - w;
		}
		cin >> Q.x >> Q.y;
		doit();
	}
}

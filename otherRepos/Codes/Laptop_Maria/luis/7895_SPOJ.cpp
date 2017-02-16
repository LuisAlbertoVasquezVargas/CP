#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
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

#define N 18
#define MOD 1000000007
#define INF (1<<30)

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

int W , L , tc , x , y , allb , n ;
double memo[ 1<< N ][ N + 5 ];
bool done[ 1<< N ][ N + 5 ];
double D[ N + 5 ][ N + 5 ];
Point P[ N ] , R, C[ 4 ];

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

double g( int i )
{
	return min( min( P[i].x , W - P[i].x ) , min( P[i].y , L - P[i].y ) );
}
double f( int i , int j )
{
	double mini = INF;
	REP( k , 4 )
	{
		Point a = C[k] , b = C[(k+1)%4] , w = b - a;
		Point I = lineIntersection( a , b , P[i] , P[i] + w.ort() );
		Point Sim = P[i] + (I-P[i])*2;
		mini = min( mini , dist( P[j] , Sim ) );
	}
	return mini;
}
double dp( int mask , int last )
{
	if( ones(mask) == n - 1 )return g( last );
	if( done[ mask ][ last ] ) return memo[ mask ][ last ];
	double &dev = memo[ mask ][ last ];
	done[ mask ][ last ] = 1;
	dev = 1e100;
	REP( i , n )
		if( i!= last && ((1<<i)&mask) == 0 ) dev = min( dev , D[last][i] + dp( mask xor (1<<last) , i ) );
	return dev;
}
int main()
{
	//sc( tc );
	cin >> tc;
	while( tc -- )
	{
		//sc( W ) , sc( L ) , sc( n );
		cin >> W >> L >> n;
		C[ 0 ] = Point( 0 , 0 );
		C[ 1 ] = Point( 0 , L );
		C[ 2 ] = Point( W , L );
		C[ 3 ] = Point( W , 0 );
		allb = (1<<n) - 1;
		REP( i ,  n )
		{
			//sc( x ) , sc( y );
			cin >> x >> y;
			P[ i ] = Point( x , y );
		}
		cin >> x >> y;
		//sc( x ) , sc( y );
		R = Point( x , y );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				D[i][j] = D[j][i] = f( i , j );
		me( done , 0 );
		double mini = INF;
		REP( i , n ) mini = min( mini , dist( R , P[i] ) + dp( 0 , i ) );
		printf( "%.16lf\n" , mini );
	}
}


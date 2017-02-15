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
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-7)

using namespace std;

struct Point
{
	double x , y;
	Point(){}
	Point( double x , double y ):x( x ) , y( y ){}
	Point ort(){ return Point( -y , x );}
};
Point O( 0 , 0 );
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
double dot( const Point &A ,const Point &B ){ return A.x*B.x + A.y*B.y;}
double cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
Point operator*( const Point &A , const double k ){ return Point( A.x*k , A.y*k );}
bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
	return abs( cross(P2 - P1, P4 - P3) ) <= EPS;
}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}
struct Line
{
	int a , b , c;
	Line(){}
	Line( int a , int b , int c ):a(a),b(b),c(c){}
	void read(){ scanf( "%d%d%d", &a , &b , &c ); }
};

pair< Point , Point > transf( const Line &L )
{
	Point PO = Point( L.a , L.b );
	if( L.c == 0 )return mp( O , PO.ort() ) ;
	double cte = L.c/dot( PO , PO );
	return mp( PO*cte , PO.ort()*cte ) ;
}
int main()
{
	Line L1 , L2;
	while( 1 )
	{
		L1.read() , L2.read();
		if( L1.a == 0 && L1.b == 0 && L1.c == 0 )break;
		pair< Point , Point > P1 = transf( L1 ) , P2 = transf( L2 );
		if( isParallel( P1.fi , P1.fi + P1.se , P2.fi , P2.fi + P2.se ) )
			puts( "No fixed point exists." );
		else
		{
			Point Inter = lineIntersection( P1.fi , P1.fi + P1.se , P2.fi , P2.fi + P2.se );
			printf( "The fixed point is at %.2f %.2f.\n" , Inter.x , Inter.y );
		}
	}
}



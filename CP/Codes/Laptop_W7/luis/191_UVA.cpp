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
#define EPS (1e-5)

using namespace std;

struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ):x(x) , y(y) {}
	void read(){ scanf( "%d%d" , &x , &y );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
int operator ^( const Point &A , const Point &B ){ return ( A.x*B.y - A.y*B.x ); }
int area( const Point &A , const Point &B , const Point &C ){ return ( B - A )^( C - A );}
bool between( const Point &A ,const Point &B ,const Point &P )
{
	return 	P.x >= min( A.x , B.x ) && P.x <= max( A.x , B.x ) &&
			P.y >= min( A.y , B.y ) && P.y <= max( A.y , B.y );
}
bool onSegment( const Point &A ,const Point &B ,const Point &P )
{
	return area( A , B , P ) == 0 && between( A , B , P );
}
bool intersects( const Point & P1 , const Point &P2 , const Point &P3 , const Point &P4 )
{
	int A1 = area( P3 , P4 , P1 );
	int A2 = area( P3 , P4 , P2 );
	int A3 = area( P1 , P2 , P3 );
	int A4 = area( P1 , P2 , P4 );
	if( A1*A2 < 0 && A3*A4 < 0 )return 1;
	if( onSegment( P3 , P4 , P1 ) )return 1;
	if( onSegment( P3 , P4 , P2 ) )return 1;
	if( onSegment( P1 , P2 , P3 ) )return 1;
	if( onSegment( P1 , P2 , P4 ) )return 1;
	return 0;
}
int main()
{
	int tc;
	sc( tc );
	Point P , Q , Poly[ 4 ];
	while( tc -- )
	{
		P.read() , Q.read();
		int xlo , xhi , ylo , yhi;
		scanf( "%d%d%d%d" , &xlo , &yhi , &xhi , &ylo );
		bool ok = 0;
		Point A = Point( xlo , yhi ) , B = Point( xhi , ylo );
		Poly[ 0 ] = A ;
		Poly[ 1 ] = Point( xhi , yhi );
		Poly[ 2 ] = B;
		Poly[ 3 ] = Point( xlo , ylo );
		if( between( A , B , P ) || between( A , B , Q ) )ok = 1;
		REP( k , 4 )
			if( intersects( Poly[k] , Poly[(k+1)%4] , P , Q ) ) ok = 1;
		puts( ok ? "T":"F" );
	}
}



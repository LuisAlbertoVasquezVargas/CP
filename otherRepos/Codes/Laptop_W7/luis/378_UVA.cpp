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
using namespace std;

#define Vector Point
#define ld long double
#define EPS (1e-8)

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ):x(x) , y(y){}
	void read(){ cin >> x >> y; }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){return cross( A - B , C - B ); }


bool sameLine( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	return abs( area( P1 , P2 , P3 ) ) < EPS && abs( area( P1 , P2 , P4 ) ) < EPS;
}
bool isParallel( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	return abs( cross( P2 - P1 , P4 - P3 ) )< EPS;
}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*(cross( C - A , D - C ) / cross( B - A , D - C ) );
} 

int main()
{
	Point A, B , P ,Q;
	int tc;
	sc( tc );
	puts( "INTERSECTING LINES OUTPUT" );
	REP( cases , tc )
	{
		A.read() , B.read() , P.read() , Q.read();
		if( sameLine( A , B , P , Q ) )puts( "LINE" );
		else if( isParallel( A , B , P , Q ) )puts( "NONE" );
		else
		{
			Point Inter = lineIntersection( A , B , P , Q );
			printf( "POINT %.2f %.2f\n" , double( Inter.x ) , double( Inter.y ) );
		}
	}
	puts( "END OF OUTPUT" );
}



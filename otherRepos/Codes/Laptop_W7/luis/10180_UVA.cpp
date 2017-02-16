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

#define ld long double
#define EPS (1e-8)
#define PI acos(-1.0)

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ):x(x) , y(y){}
	Point ort(){ return Point( -y , x ); }
	ld arg(){ return atan2( y , x ); }
	void read(){ cin >> x >> y ; }
}O( 0 , 0 );
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k );}
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y; }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
ld dist( const Point &A , const Point &B ){ return sqrt( dot( B - A , B - A ) );}
bool between( const Point &A , const Point &B , const Point &P ){
	return 	P.x + EPS >= min( A.x , B.x ) && P.x <= max( A.x , B.x ) + EPS&& 
			P.y + EPS >= min( A.y , B.y ) && P.y <= max( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
Point lineIntersection( const Point &A , const Point &B ,const Point &C ,const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}

ld get_angle( Point A , Point P , Point B )
{
	ld ang = (A-P).arg() - (B-P).arg(); 
	while(ang < 0) ang += 2*PI; 
	while(ang > 2*PI) ang -= 2*PI;
	return min(ang, 2*PI-ang);
}
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		Point P , Q;
		P.read() , Q.read();
		ld R;
		cin >> R;
		Point v = (P-Q);
		Point Inter = lineIntersection( P , Q , O , O + v.ort() );
		ld dPQ = dist( P , Q ) , ans ,dPO = dist( P , O ) , dQO = dist( Q , O );
		ld H = dist( O , Inter );
		if( H + EPS >= R )ans = dPQ;
		else if( !onSegment( P , Q , Inter ) )ans = dPQ;
		else
		{
			ld t = get_angle( P , O , Q );
			ld t1 = acos( R/dPO ) , t2= acos( R/dQO );
			ans = R*( t - t1 - t2 ) + sqrt( dPO*dPO - R*R ) + sqrt( dQO*dQO - R*R );
		}
		printf( "%.3f\n" , double( ans ) );
	}
}



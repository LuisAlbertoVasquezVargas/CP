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

#define PI acos( -1.0 )
#define EPS (1e-8)
#define MOD1 1000000009
#define MOD2 1000000007

typedef long double ld;

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ):x(x) , y(y){}
}O( 0 ,0 );
Point operator *( const Point & A , const ld &K ){ return Point( A.x*K , A.y*K ) ;}
Point operator +( const Point & A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ) ;}
Point operator -( const Point & A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ) ;}
bool operator <(const Point &a, const Point &b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y;}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
bool between( const Point &A , const Point &B , const Point &P ){
	return 	P.x + EPS >= min( A.x , B.x ) && P.x <= min( A.x , B.x ) + EPS &&
			P.y + EPS >= min( A.y , B.y ) && P.y <= min( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	ld A1 = area( P3 , P4 , P1 );
	ld A2 = area( P3 , P4 , P2 );
	ld A3 = area( P1 , P2 , P3 );
	ld A4 = area( P1 , P2 , P4 );
	if( A1*A2 < EPS && A3*A4 < EPS )return 1;
	if( onSegment( P3 , P4 , P1 ) )return 1;
	if( onSegment( P3 , P4 , P2 ) )return 1;
	if( onSegment( P1 , P2 , P3 ) )return 1;
	if( onSegment( P1 , P2 , P4 ) )return 1;
	return 0;
}
bool pointInPoly( vector< Point > &Poly , Point P )
{
	int nP = Poly.size() , cnt = 0;
	REP( i , nP )
	{
		if( onSegment( Poly[i] , Poly[(i+1)%nP] , P ) )return 0;
		cnt += intersects( Poly[i] , Poly[(i+1)%nP] , P  , P + Point( MOD1 , MOD2 ) );
	}
	return cnt&1;
}
vector <Point> ConvexHull(vector <Point> Poly)
{
    sort(Poly.begin(),Poly.end());
    int nP = Poly.size(),k = 0;
    Point H[2*nP];
    
    for(int i=0;i<nP;++i){
        while(k>=2 && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    for(int i=nP-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    if( k == 0 )return vector <Point>();
    return vector <Point> (H,H+k-1);
}

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C ) );
}
ld area(const vector <Point> &P)
{
    int nP = P.size();
    ld A = 0;
    for(int i=1; i<=nP-2; i++)
        A += area(P[0], P[i], P[i+1]);
    return abs(A/2);
}


// angle in radians
Point rot( Point P , ld angle )
{
/*	| CO -SO | x |
	| SO  CO | y |*/
	//printf( "ang : %.10lf\n" , double( angle ) );
	ld X = P.x*cos( angle  ) - P.y*sin( angle );
	ld Y = P.x*sin( angle ) + P.y*cos( angle );
	return Point( X , Y );
}
int main()
{
	ld W , H , a;
	while( cin >> W >> H >> a )
	{
		vector< Point > A;
		W /= 2 , H /= 2;
		A.pb( Point( W , H ) );
		A.pb( Point( -W , H ) );
		A.pb( Point( -W , -H ) );
		A.pb( Point( W , -H ) );
		vector< Point > B( 4 );
		REP( i , 4 )B[i] = rot( A[i] , a*PI/180.0 );
		/*cout << "B" << endl;
		REP( i , B.size() )cout << B[i].x << " " << B[i].y << endl;
		test*/
		vector< Point >Poly;
		REP( i , 4 )if( pointInPoly( A , B[i] ) ) Poly.pb( B[i] );
		REP( i , 4 )if( pointInPoly( B , A[i] ) ) Poly.pb( A[i] );
		REP( i , 4 )REP( j , 4 )
			if( intersects( A[i] , A[(i+1)%4]  ,B[j] , B[(j+1)%4] ) && abs( cross( A[i] - A[(i+1)%4] , B[j] - B[(j+1)%4] ) ) > EPS )
			{
				Point Inter = lineIntersection( A[i] , A[(i+1)%4]  , B[j] , B[(j+1)%4] );
				Poly.pb( Inter );
			}
		REP( i , 4 )REP( j , 4 )
			if( onSegment( A[i] , A[(i+1)%4]  ,B[j] ) )
				Poly.pb( B[j] );
		REP( i , 4 )REP( j , 4 )
			if( onSegment( B[i] , B[(i+1)%4]  ,A[j] ) )
				Poly.pb( A[j] );
		Poly = ConvexHull( Poly );
		printf( "%.10f\n" , double( area( Poly ) ) );
	}
}



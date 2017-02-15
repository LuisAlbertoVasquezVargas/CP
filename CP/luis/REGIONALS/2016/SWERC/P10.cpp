#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Point{
	ll x , y;
	Point(){ x = y = 0; }
	Point( ll x , ll y ) : x( x ) , y( y ) {}
	void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
bool operator <( const Point &A , const Point &B ){ return (A.x==B.x)?(A.y<B.y):(A.x<B.x); }

ll dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ll cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ll area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }



bool between( const Point &A , const Point &B , const Point &P ){
	return 	min( A.x , B.x ) <= P.x && P.x <= max( A.x , B.x ) &&
			min( A.y , B.y ) <= P.y && P.y <= max( A.y , B.y );
}

/*
bool onSegment( const Point &A , const Point &B , const Point &P ){
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	ld A1 = area( P3 , P4 , P1 );
	ld A2 = area( P3 , P4 , P2 );
	ld A3 = area( P1 , P2 , P3 );
	ld A4 = area( P1 , P2 , P4 );
	if( ( ( A1 > EPS && A2 < -EPS ) || ( A1 < -EPS && A2 > EPS ) ) && 
		( ( A3 > EPS && A4 < -EPS ) || ( A3 < -EPS && A4 > EPS ) ) ) return 1;
	if( onSegment( P3 , P4 , P1 ) ) return 1;
	if( onSegment( P3 , P4 , P2 ) ) return 1;
	if( onSegment( P1 , P2 , P3 ) ) return 1;
	if( onSegment( P1 , P2 , P4 ) ) return 1;
	return 0;
}
*/
typedef vector< Point > Polygon;
/*
bool pointInPoly( const Polygon &Poly , const Point &A ){
    int nP = Poly.size() , cnt = 0;
    REP( i , nP ){
        int inf = i , sup = ( i + 1 )%nP;
        if( Poly[ inf ].y > Poly[ sup ].y ) swap( inf , sup );
        if( Poly[ inf ].y <= A.y && A.y < Poly[ sup ].y )
            if( area( A , Poly[ inf ] , Poly[ sup ] ) > EPS )
                cnt++;
    }
    return cnt&1;
}
*/
// revisar caso cuando la entrada es un punto o puntos colineales
Polygon convexHull( Polygon P ){
	sort( all( P ) );
	int nP = P.size() , k = 0;
	Point H[ nP << 1 ];
	REP( i , nP ){
		while( k >= 2 && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) <= 0 ) k--;
		H[ k++ ] = P[ i ];
	}
	for( int i = nP - 2 , sz = k; i >= 0 ; --i ){
		while( k > sz && area( H[ k - 2 ] , H[ k - 1 ] , P[ i ] ) <= 0 ) k--;
		H[ k++ ] = P[ i ];
	}
	if( k == 0 ) return Polygon();
	return Polygon( H , H + k - 1 );
}

bool isInConvex(vector <Point> &A, const Point &P)
{
	int n = A.size(), lo = 1, hi = A.size() - 1;
	
	if(area(A[0], A[1], P) < 0) return 0;
	if(area(A[n-1], A[0], P) < 0) return 0;
	if(area(A[0], A[n - 1], P) == 0)return between(A[0], A[n - 1], P);
	
	while(hi - lo > 1)
	{
		int mid = (lo + hi) / 2;
		
		if(area(A[0], A[mid], P) >= 0) lo = mid;
		else hi = mid;
	}
	
	return area(A[lo], A[hi], P) >= 0;
}

int main(){
	int n,m;
	while(scanf("%d",&n)==1){
		vector<Point>P;
		REP(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			P.pb(Point(x,y));
		}
		P=convexHull(P);
		scanf("%d",&m);
		int ans=0;
		REP(i,m){
			int x,y;
			scanf("%d%d",&x,&y);
			if(isInConvex(P,Point(x,y)))ans++;
		}
		printf("%d\n",ans);
	}
}


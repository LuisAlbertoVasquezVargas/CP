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
#define INF (1e100)

struct Point 
{
	ld x , y ;
	Point(){}
	Point( ld x ,  ld y ):x(x),y(y){}
	Point ort(){ return Point( -y , x ) ; }
	void read(){ cin >> x >> y; }
};
Point operator +(const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator -(const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator *(const Point &A , const ld K ){ return Point( A.x*K , A.y*K );}
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( C - A , C - B ); }
ld dist( const Point &A , const Point &B ){ return sqrt( dot( B - A , B - A ) ); }
bool between( const Point &A , const Point &B , const Point &P )
{
	return 	P.x + EPS >= min( A.x , B.x )&& P.x <= max( A.x , B.x ) + EPS && 
			P.y + EPS >= min( A.y , B.y )&& P.y <= max( A.y , B.y ) + EPS ;
}
bool onSegment( const Point &A , const Point &B , const Point &P )
{
	return abs( area( A , B , P ) ) < EPS && between( A , B , P );
}
bool intersects(const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 )
{
	ld A1 = area( P3 , P4 , P1 );
	ld A2 = area( P3 , P4 , P2 );
	ld A3 = area( P1 , P2 , P3 );
	ld A4 = area( P1 , P2 , P4 );
	if( A1*A2 < -EPS && A3*A4 < -EPS )return 1;
	if( abs( A1 ) < EPS && onSegment( P3 , P4 , P1 ) )return 1;
	if( abs( A2 ) < EPS && onSegment( P3 , P4 , P2 ) )return 1;
	if( abs( A3 ) < EPS && onSegment( P1 , P2 , P3 ) )return 1;
	if( abs( A4 ) < EPS && onSegment( P1 , P2 , P4 ) )return 1;
	return 0;
}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

int main()
{
	int n;
	Point Q , P;
	vector< Point >L;
	while( cin >> Q.x >> Q.y )
	{
		cin >> n;
		L.resize( n + 1 );
		REP( i , n + 1 ) L[i].read();
		ld mini = INF;
		REP( i , n )
		{
			Point Inter = lineIntersection( L[i] , L[i+1] , Q , Q + ( L[i] - L[i+1] ).ort() );
			if( onSegment( L[i] , L[i+1] , Inter ) )
			{
				ld distance = dist( Inter , Q );
				if( distance < mini )
				{
					mini = distance;
					P = Inter;
				}
			}
			else
			{
				if( dist( L[i] , Q ) < mini )
				{
					mini = dist( L[i] , Q );
					P = L[i];
				}
				if( dist( L[i+1] , Q ) < mini )
				{
					mini = dist( L[i+1] , Q );
					P = L[i+1];
				}
			}
		}
		printf( "%.4lf\n" , double( P.x ) );
		printf( "%.4lf\n" , double( P.y ) );
	}
}



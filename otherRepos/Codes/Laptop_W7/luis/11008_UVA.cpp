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

#define Vector Point
#define PI acos( -1.0 )
#define EPS (1e-7)

using namespace std;

int n , m;

struct Point
{
	double x , y;
	Point(){}
	Point( double x , double y ):x(x),y(y){}
	void read(){ scanf( "%lf%lf" , &x , &y ); }
	double arg(){ return atan2( y , x );}
};
Point operator *( const Point &A , const double &k ){ return Point( A.x*k , A.y*k ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
bool operator ==( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS && abs( A.y - B.y ) < EPS; }
double cross( const Vector &A , const Vector &B ){ return A.x*B.y - B.x*A.y ; }
double area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); }
bool between( const Point &A , const Point &B , const Point &P )
{
	return 	P.x + EPS >= min( A.x , B.x ) && P.x <= max( A.x , B.x ) + EPS && 
			P.y + EPS >= min( A.y , B.y ) && P.y <= max( A.y , B.y ) + EPS;
}
bool onSegment( const Point &A , const Point &B , const Point &P ){ return abs( area( A , B , P ) ) < EPS && between( A , B , P ); } 

bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
    double A1 = area(P3, P4, P1);
    double A2 = area(P3, P4, P2);
    double A3 = area(P1, P2, P3);
    double A4 = area(P1, P2, P4);
    
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && 
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) 
            return true;
    
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true;
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true;
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true;
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true;
    else return false;
}
bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{
	return abs( cross(P2 - P1, P4 - P3) ) <= EPS;
}
Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}
double f( double a )
{
	if( a < 0 )a += 2*PI;
	return a;
}
int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		scanf( "%d%d" , &n , &m );
		vector< Point >P( n ) , T ;
		REP( i , n )P[i].read();
		T = P;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				for( int I = j + 1 ; I < n ; ++I )
					for( int J = I + 1 ; J < n ; ++J )
					{
						if( !intersects( P[i] , P[j] , P[I] , P[J] ) || isParallel( P[i] , P[j] , P[I] , P[J] ) )continue;
						Point Inter = lineIntersection( P[i] , P[j] , P[I] , P[J] );
						T.pb( Inter );
					}
		int m = T.size() , ans = 1<<30;
		double ang[n];
		int F[n];
		REP( i , m )
			cout << T[i].x << " " << T[i].y << endl;
		REP( i , m )
		{
			REP( j , n )
				ang[j] = f( ( P[j] - T[i] ).arg() );
			sort( ang , ang + n );
			F[0] = 1;
			int ind = 0;
			for( int j = 1 ; j < n ; ++j )
				if( abs(ang[j] - ang[j-1]) < EPS )
					F[ind]++;
				else F[++ind] = 1;
			sort( F , F + ind + 1 );
			reverse( F , F + ind + 1 );
			int S = 0;
			for( int i = 0 ; i <= ind ; ++i )
				if( S >= m )
				{
					ans = min( ans , ind );
					break;
				}else S+=F[i];
		}
		printf( "Case #%d:\n" , cases + 1 );
		printf( "%d\n\n" , ans );
	}
}



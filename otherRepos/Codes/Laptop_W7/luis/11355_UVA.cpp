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

#define N 105
#define PI acos( -1.0 )
#define EPS (1e-8)
#define INF (1<<30)

using namespace std;

struct Point
{
	double x , y;
	Point(){}
	Point( double x , double y ):x( x ) , y( y ){}
	double arg(){ return atan2( y , x );}
	double get_angle(){
		double t = arg();
		if( t < EPS ) t += 2*PI;
		return t;
	}
	void read(){ scanf( "%lf%lf" , &x , &y );}
}O( 0 , 0 );
Point operator *( const Point &A , const double &k ){ return Point( A.x*k , A.y*k ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
double cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
double area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
bool between( const Point &A , const Point &B , const Point &P ){ 
	return	P.x >= min( A.x , B.x ) && P.x <= max( A.x , B.x ) && 
			P.y >= min( A.y , B.y ) && P.y <= max( A.y , B.y ); 
}
bool onSegment( const Point &A , const Point &B , const Point &P ){ return area( A , B , P ) == 0 && between( A , B , P );}
bool intersects( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	double A1 = area( P4 , P4 , P1 );
	double A2 = area( P4 , P4 , P2 );
	double A3 = area( P1 , P2 , P3 );
	double A4 = area( P1 , P2 , P4 );
	if( A1*A2 < 0 && A3*A4 < 0 )return 1;
	if( onSegment( P4 , P4 , P1 ) )return 1;
	if( onSegment( P4 , P4 , P2 ) )return 1;
	if( onSegment( P1 , P2 , P3 ) )return 1;
	if( onSegment( P1 , P2 , P4 ) )return 1;
	return 0;
}
bool isParallel( const Point &P1 , const Point &P2 , const Point &P3 , const Point &P4 ){
	return cross( P2- P1 , P4 - P3 ) == 0 ;
}
Point lineIntersection( const Point &A , const Point &B , const Point &C , const Point &D ){
	return A + ( B - A )*( cross( C - A , D - C ) / cross( B - A , D - C ) );
}
Point P[ N ] , Q[ N ];
double f( vector< pair< double , double > > &A )
{
	int m = A.size();
	if( m == 0 )return 0;
	sort( all( A ) );
	double S = A[0].se - A[0].fi , end = A[0].se;
	for( int i = 1 ; i < m ; ++i )
	{
		if( A[i].fi > end ) S += A[i].se - A[i].fi;
		else if( A[i].se > end ) S += A[i].se - end;
		end = max( end , A[i].se );
	}
	return S/(2*PI);
}
int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		int n , R;
		sc( n ) , sc( R );
		REP( i , n ) P[i].read() , Q[i].read();
		vector< pair< double , double > > A;
		REP( i , n )
		{
			if( Q[i].y > P[i].y )swap( P[i] , Q[i] );
			if( intersects( O , Point( INF , 0 ) , P[i] , Q[i] ) )
			{
				if( !isParallel( O , Point( INF , 0 ) , P[i] , Q[i] ) )
				{
					if( Q[i].y == 0 )
						A.pb( mp( 0 , P[i].get_angle() ) );
					else if( P[i].y == 0 )
						A.pb( mp( P[i].get_angle() , 2*PI ) );
					else
					{
						A.pb( mp( Q[i].get_angle() , 2*PI ) );
						A.pb( mp( 0 , P[i].get_angle() ) );
					}
				}
			}
			else
			{
				double ang1 = P[i].get_angle() , ang2 = Q[i].get_angle();
				if( ang1 > ang2 )swap( ang1 , ang2 );
				A.pb( mp( ang1 , ang2 ) );	
			}
		}
		REP( i , A.size() )
			cout << A[i].fi << " " << A[i].se << endl;
		double ans = f( A );
		printf( "Case %d: %.2lf" , cases + 1 ,  (1 - ans)*100 );
		puts( "%" );
	}
}



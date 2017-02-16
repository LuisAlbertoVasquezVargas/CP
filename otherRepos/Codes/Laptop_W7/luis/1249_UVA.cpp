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
#define Vector Point
#define EPS (1e-8)

struct Point
{
	ld x, y;
	Point(){}
	Point( ld x , ld y ):x(x),y(y){}
	void read(){ cin >> x >> y ; }
};
ld cross( const Vector &A , const Vector &B ){ return A.x*B.y - B.x*A.y ; }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y );}
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
bool operator ==( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS && abs( A.y - B.y ) < EPS; }

int main()
{
	Point O(0 ,0) , A , B , C , D , E , F;
	while( 1 )
	{
		A.read() , B.read() , C.read() , D.read() , E.read() , F.read();
		if( A == O && B == O && C == O )break;
		ld k = 0.5*cross( D - E , F - E )/cross( C - A , B - A );
		if( k < 0 ) k = -k;
		Point AC = C - A;
		Point G = A + AC*k;
		Point AG = G - A;
		Point H = B + AG;
		printf( "%.3f %.3f %.3f %.3f\n" , (double)H.x , (double)H.y , (double)G.x , (double)G.y );
	}
}



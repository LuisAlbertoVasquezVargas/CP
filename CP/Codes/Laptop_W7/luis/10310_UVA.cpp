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

#define ld long double
#define EPS (1e-6)

using namespace std;
struct Point
{
	ld x, y;
	Point(){}
	Point( ld x , ld y ):x(x) , y(y) {}
	void read() {
		cin >> x >> y;
	}
};
Point operator-( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y;}
ld dist2( const Point &A , const Point &B ){ return dot( B - A , B - A ) ; }

int main()
{
	Point P , Q , X;
	int n;
	while( cin >> n )
	{
		P.read() , Q.read();
		bool solve = 0;
		REP( i , n )
		{
			X.read();
			if( 4*dist2( P , X ) <= dist2( Q , X ) && !solve )
			{
				solve = 1;
				printf( "The gopher can escape through the hole at (%.3f,%.3f).\n" , double( X.x ) , double( X.y ) );
			}
		}
		if( !solve )puts( "The gopher cannot escape." );
	}
}



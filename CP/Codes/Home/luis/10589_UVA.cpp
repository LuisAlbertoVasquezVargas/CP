#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
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
#define EPS (1e-8)

typedef long double ld;
struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ) : x( x ) , y( y ) {}
	ld dist(){ return x*x + y*y ; }
	void read(){ cin >> x >> y ; }
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }

int main()
{
	ll n , A;
	while( cin >> n >> A && n )
	{
		Point Corners[ 4 ] = { Point( 0 , 0 ) , Point( 0 , A ) , Point( A , 0 ) , Point( A , A ) };
		Point P;
		int cnt = 0;
		REP( i,  n )
		{	
			P.read();
			bool ok = 1;
			REP( j , 4 )
				if( ( P - Corners[ j ] ).dist() > A*A )
					 ok = 0;
			cnt += ok;
		}
		printf( "%.5lf\n" , 1.0*cnt*(A*A)/n );
	}
}


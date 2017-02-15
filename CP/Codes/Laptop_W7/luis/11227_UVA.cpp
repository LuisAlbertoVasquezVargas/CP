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

#define N 102
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int X[ N ] , Y[ N ];
struct Point
{
	int x , y;
	Point(){}
	Point( int x ,  int y ):x(x) , y(y){}
};

Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
int operator ^( const Point &A , const Point &B ){ return A.x*B.y -A.y*B.x ; }

pii p[N];
Point P[N];

int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		int n;
		sc( n );
		REP( i , n )
		{
			double x , y;
			scanf( "%lf%lf" , &x , &y );
			p[ i ].fi = 100*x;
			p[ i ].se = 100*y;
		}
		sort( p , p + n );
		n = unique( p , p + n ) - p;
		int maxi = 1;
		REP( i , n ) P[i] = Point( p[i].fi , p[i].se );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
			{
				int cnt = 2;
				for( int k = j + 1 ; k < n ; ++k )
					if( (( P[i] - P[k] )^( P[j] - P[k] )) == 0 )cnt++;
				if( cnt > maxi ) maxi = cnt;
			}
		if( n == 1 ) printf( "Data set #%d contains a single gnu.\n"  , cases + 1 );
		else printf( "Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n" , cases + 1 , n , maxi );
	}
}



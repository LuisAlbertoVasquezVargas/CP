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
#define EPS (1e-8)
#define ld long double

struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ): x( x ) , y( y ) {}
	void read(){ scanf( "%d%d" , &x , &y ); }
};
ld cross( const Vector &A , const Vector &B ){ return A.x*B.y - B.x*A.y ;}
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }

int n;
Point P[ 305 ];

int main()
{
	while( 1 )
	{
		P[0].read();
		if( P[0].x == 0 && P[0].y == 0 )break;
		n = 1;
		while( 1 )
		{
			P[n].read();
			if( P[n].x == 0 && P[n].y == 0 )break;
			n++;
		}
		vector< vector< pii > >T;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				{
					int cnt = 0;
					for( int k = 0 ; k < n ; ++k )
						if( k != i && k != j && cross( P[j] - P[k] , P[i] - P[k] ) == 0 )cnt++;
					if( cnt )
					{
						vector< pii >Q;
						Q.pb( mp( P[i].x , P[i].y ) );
						Q.pb( mp( P[j].x , P[j].y ) );
						for( int k = 0 ; k < n ; ++k )
							if( k != i && k != j && cross( P[j] - P[k] , P[i] - P[k] ) == 0 )
								Q.pb( mp( P[k].x , P[k].y ) );
						sort( all( Q ) );
						T.pb( Q );
					}
				}
		sort( all( T ) );
		T.resize( unique( all( T ) ) - T.begin() );
		if( T.empty() )puts( "No lines were found" );
		else
		{
			puts( "The following lines were found:" );
			int nT = T.size();
			REP( i , nT )
			{
				int nQ = T[i].size();
				REP( j , nQ )
					printf( "(%4d,%4d)" , T[i][j].fi , T[i][j].se );
				puts( "" );
			}
		}
	}
}



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
#define INF 1e100
#define EPS (1e-8)

typedef long double ld;
typedef complex< ld > Point;
struct cmp_X
{
	bool operator()( const Point &A , const Point &B ) const{
		if( A.real() == B.real() ) return A.imag() < B.imag();
		return A.real() < B.real();
	}
};
struct cmp_Y
{
	bool operator()( const Point &A , const Point &B ) const{
		if( A.imag() == B.imag() ) return A.real() < B.real();
		return A.imag() < B.imag();
	}
};

int main()
{
	int n;
	while( scanf( "%d" , &n ) == 1 && n )
	{
		vector< Point >P( n );
		REP( i , n ) cin >> P[ i ].real() >> P[ i ].imag() ;
		sort( all( P ) , cmp_X() );
		set< Point , cmp_Y >S;
		int tail = 0;
		ld H = INF;
		REP( i , n )
		{
			while( P[ i ].real() - P[ tail ].real() > H + EPS )
			{
				S.erase( P[ tail ] );
				tail++;
			}
			set< Point , cmp_Y >::iterator y1 , y2 , y3;
			y1 = lower_bound( all( S ) , Point( -INF , P[ i ].imag() - H ) , cmp_Y() );
			y2 = upper_bound( all( S ) , Point( INF , P[ i ].imag() + H ) , cmp_Y() );
			for( y3 = y1 ; y3 != y2 ; ++y3 )
				H = min( H , abs( P[ i ] - *y3 ) );
			S.insert( P[ i ] );
		}
		if( H + EPS < 10000 )
			printf( "%.4lf\n" , double( H ) );
		else puts( "INFINITY" );
	}
}


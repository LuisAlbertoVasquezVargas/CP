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

#define N 35
#define EPS (1e-8)
/*
 - Swapping two rows multiplies the determinant by -1
 - Multiplying a row by a nonzero scalar multiplies the determinant by the same scalar
 - Adding to one row a scalar multiple of another does not change the determinant.
*/
double det;
bool invert( double A[ N ][ N ] , double B[ N ][ N ] , int n )
{
	det = 1;
	REP( i , n )
	{
		int jmax = i ;
		for( int j = i + 1 ; j < n ; ++j )
			if( abs( A[ j ][ i ] ) > abs( A[ jmax ][ i ] ) ) jmax = j;
		if( jmax > i ) det = -det;
		REP( j , n )
			swap( A[ i ][ j ] , A[ jmax ][ j ] ) , swap( B[ i ][ j ] , B[ jmax ][ j ] );
		if( abs( A[ i ][ i ] ) < EPS ) {
			det = 0;
			return 0;
		}
		double tmp = A[ i ][ i ];
		det *= tmp;
		REP( j , n ) A[ i ][ j ] /= tmp , B[ i ][ j ] /= tmp;
		REP( j , n )
		{
			if( i == j )continue;
			tmp = A[ j ][ i ];
			REP( k , n )
				A[ j ][ k ] -= A[ i ][ k ]*tmp , B[ j ][ k ] -= B[ i ][ k ]*tmp;
		}
	}
	return 1;
}
int main()
{
	int n;
	while( cin >> n && n )
	{
		double A[ N ][ N ] , B[ N ][ N ];
		REP( i , n )REP( j , n ) cin >> A[ i ][ j ] , B[ i ][ j ] = 0;
		REP( i , n ) B[ i ][ i ] = 1;
		invert( A , B , n );
		printf( "%d\n" , int( floor( det + 0.1 ) ) );
	}
	puts( "*" );
}

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
#define MOD 1000000007
#define INF (1<<28)
#define EPS (1e-5)


int main()
{
	ll M[ N ][ N ] , DP[ N ][ N ];
	int m , tc = 0 , x , y ;
	while( sc( m ) == 1 )
	{
		int n = 0;
		clr( M , 0 );
		REP( i , m ){
			sc( x ) , sc( y );
			M[ x ][ y ] = 1;
			n = max( n , x );
			n = max( n , y );
		}
		n++;
		printf( "matrix for city %d\n" , tc++ );
		REP( k , n )REP( i , n ) REP( j , n ) M[ i ][ j ] += M[ i ][ k ]*M[ k ][ j ];
		REP( i , n )REP( j , n ) DP[ i ][ j ] = M[ i ][ j ];
		REP( k , n )if( M[ k ][ k ] ){
			REP( i , n )REP( j , n )if( M[ i ][ k ] > 0 && M[ k ][ j ] > 0 ) DP[ i ][ j ] = -1;
		}
		REP( i , n )REP( j , n ) printf( "%d%s" , DP[ i ][ j ] , j + 1 == n ? "\n":" " );
	}
}


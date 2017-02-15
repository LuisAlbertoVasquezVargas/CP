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

#define N 100

ll C[ N + 5 ][ N + 5 ];
void init( int n ){
    clr( C, 0 );
	REP( i , n + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
    for( int i = 2 ; i <= n ; ++i )
         for( int j = 1 ; j <= i ; ++j )
            C[ i ][ j ] = ( C[ i - 1 ][ j ] + C[ i - 1 ][ j - 1 ] );
}
int main()
{
	int n , k;
	init( N);
	while( scanf( "%d%d" , &n , &k ) == 2 && n )
		cout << n << " things taken " << k << " at a time is " << C[ n ][ k ] << " exactly.\n";
}


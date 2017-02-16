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
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

bool M[ N ][ N ];
int n , ans;

bool valid()
{
	REP( i , n ) REP( j , n ) 
		if( M[ i ][ j ] )
		{
			REP( k , n )
				if( k != j && M[ i ][ k ] ) return 0;
			REP( k , n )
				if( k != i && M[ k ][ j ] ) return 0;				
			REP( k , n )
				if( k && i + k < n && j + k < n &&  M[ i + k ][ j + k ] ) return 0;
			REP( k , n )
				if( k && i - k >= 0 && j + k < n &&  M[ i - k ][ j + k ] ) return 0;
			REP( k , n )
				if( k && i + k < n && j - k >= 0 &&  M[ i + k ][ j - k ] ) return 0;
			REP( k , n )
				if( k && i - k >= 0 && j - k >= 0 &&  M[ i - k ][ j - k ] ) return 0;				
		}
	return 1;
}
void f()
{
	REP( i , n ) REP( j , n ) cout << M[ i ][ j ] << ( j + 1 == n ? "\n":" " );
	puts( "" );
}
void dfs( int x , int y )
{
	if( x == n )
	{
        int cnt = 0;
	    REP( i , n ) REP( j , n ) cnt += M[ i ][ j ];
		if( cnt == n && !ans )f();		
        if( cnt == n ) ans++;
		return;
	}
	dfs( x + (y == n - 1) , (y == n - 1?0:y + 1) );
	M[ x ][ y ] = 1;
	if( valid() )
        dfs( x + (y == n - 1) , (y == n - 1?0:y + 1) );
	M[ x ][ y ] = 0;	
}
int main()
{
	while( cin >> n )
	{
		ans = 0 , dfs( 0 , 0 ) , cout << ans << endl ;
		REP( i , n ) cout << "**********" << endl;
    }
}




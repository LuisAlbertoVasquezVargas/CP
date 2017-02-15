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
#define VAMP 1
#define ORD 2

using namespace std;

int M[ N ][ N ] , V[ N ][ N ];
char dir[ N ];

int main()
{
	int v , o , m ,x , y , tc  = 1;
	while( scanf( "%d%d%d" , &v , &o , &m ) == 3 )
	{
		if( v == 0 && o == 0 && m == 0 )break;
		clr( M , 0 );
		REP( i , v ) sc( x ) , sc( y ), M[ x ][ y ] = VAMP , V[ x ][ y ] = i;
		REP( i , o ) sc( x ) , sc( y ), M[ x ][ y ] = ORD;
		REP( i , m )
		{
			int x1 , y1 , x2 , y2;
			scanf( "%s%d%d%d%d" , dir , &x1  ,&y1 , &x2 , &y2 );
			if( x1 == x2 )
			{
				if( y1 > y2 ) swap( y1 , y2 );
				for( int j = y1 ; j <= y2 ; ++j )
					M[ x1 ][ j ] = dir[ 0 ];
			}
			else
			{
				if( x1 > x2 )swap( x1 , x2 );
				for( int j = x1 ; j <= x2 ; ++j )
					M[ j ][ y1 ] = dir[0];
			}
		}
		vector< vector< string > > Va( v );
		REP( i , 101 )REP( j , 101 )
		{
			if( M[ i ][ j ] >= 3 )
			{
				if( M[ i ][ j ] == 'W' )
				{
					for( int k = i - 1 ; k >= 0 ; --k )
						if( M[ k ][ j ] == VAMP )
							Va[ V[k][j] ].pb( "east" );
						else if( M[ k ][ j ] == 0 )continue;
						else break;
				}
				else if( M[ i ][ j ] == 'E' )
				{
					for( int k = i + 1 ; k <= 100 ; ++k )
						if( M[ k ][ j ] == VAMP )
							Va[ V[k][j] ].pb( "west" );
						else if( M[ k ][ j ] == 0 ) continue;
						else break;
				}
				else if( M[ i ][ j ] == 'N' )
				{
					for( int k = j + 1 ; k <= 100 ; ++k )
						if( M[ i ][ k ] == VAMP )
							Va[ V[i][k] ].pb( "south" );
						else if( M[ i ][ k ] == 0 ) continue;
						else break;
				}
				else
				{
					//W
					for( int k = j - 1 ; k >= 0 ; -- k )
						if( M[ i ][ k ] == VAMP )
							Va[ V[ i ][ k ] ].pb( "north" );
						else if( M[ i ][ k ] == 0 ) continue;
						else break;
				}
			}
		}
		REP( i , v ) sort( all( Va[ i ] ) );
		printf( "Case %d:\n" , tc++ );
		bool emp = 1;
		REP( i , v )
			if( !Va[i].empty() )
			{
				emp = 0;
				int sz = Va[ i ].size();
				printf( "vampire %d"  , i + 1 );
				REP( j , sz )
					printf( " %s" , Va[ i ][ j ].c_str() );
				puts( "" );
			}
		if( emp ) puts( "none" );
	}
}



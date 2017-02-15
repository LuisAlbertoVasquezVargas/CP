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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int isH[ N ] , dist[ N ] , pa[ N ] , ind[ N ];
vi E[ N ];
int main()
{
	int n;
	while( sc( n ) == 1 ) 
	{
		REP( i , n ) sc( isH[ i ] );
		REP( i , n ) E[ i ].clear();
		clr( ind , 0 );
		REP( i , n )
		{
			int y;
			sc( y );
			if( y )
			{
				y--;
				E[ i ].pb( y );
				ind[ y ]++;
			}
		}
		REP( i , n ) dist[ i ] = INF;
		queue< int > Q;
		REP( i , n ) 
			if( isH[ i ] ) Q.push( i ) , dist[ i ] = 0 , pa[ i ] = -1;
		int u;
		while( !Q.empty() )
		{
			u = Q.front() , Q.pop();
			FOR( v , E[ u ] )
				if( dist[*v] == INF && ind[ *v ] == 1 )
				{
					Q.push( *v );
					dist[ *v ] = dist[ u ] + 1;
					pa[ *v ] = u;
				}
		}
		printf( "%d\n" , dist[ u ] + 1 );
		while( u != -1 )
		{
			printf( "%d " , u + 1 );
			u = pa[ u ];
		}
		puts( "" );
	}
}



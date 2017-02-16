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

vi E[ 26 ];
int memo[ 21 ][ 1<<21 ];
int M[ 21 ][ 21 ];
int pa[ 21 ];
int sink , t;
void init()
{
	REP( i , 26 ) E[ i ].clear();
	t = 1;
	clr( pa , -1 );
}
int dp( int u , int mask )
{
	if( u == sink ) { 
		return 1;
	}
	int &dev = memo[ u ][ mask ];
	if( dev == -1 ){
		dev = 0;
		for( int i = 0 ; i < E[ u ].size() ; ++i )
		{
			int v = E[ u ][ i ];
			if( mask&( 1<<v ) ) continue;
			dev += dp( v , mask^(1<<v) );
		}
	}
	return dev;
}
int bfs()
{
	vi dist( 26 , INF );
	queue< int >Q;
	Q.push( 0 );
	dist[ 0 ] = 0;
	while( !Q.empty() )
	{
		int u = Q.front();
		Q.pop();
		for( int i = 0 ; i < E[ u ].size() ; ++i )
		{
			int v = E[ u ][ i ];
			if( dist[ v ] == INF )
			{
				dist[ v ] = dist[ u ] + 1;
				pa[ v ] = u;
				Q.push( v ); 
			}else if( dist[ v ] == dist[ u ] + 1 )
			{
				if( u < pa[ v ] ) pa[ v ] = u;
			}
		}
	}
	return dist[ sink ];
}
int main()
{
	string s , a , b ;
	while( cin >> s )
	{
		sink = s[ 0 ] - 'F';
		init();
		while( cin >> a >> b )
		{
			if( a == "A" )break;
			int x = a[ 0 ] - 'F' , y = b[ 0 ] - 'F';
			M[ x ][ y ] = M[ y ][ x ] = t++;
			E[ x ].pb( y ) , E[ y ].pb( x );
		}
		int dis = bfs();
		if( dis == INF )
		{
			printf( "No Route Available from F to %s" , s.c_str() );
			continue;
		}
		clr( memo , -1 );
		printf( "Total Routes: %d\n" , dp( 0 , 1 ) );
		printf( "Shortest Route Length: %d\n" , 1 + bfs() );
		printf( "Shortest Route after Sorting of Routes of length %d:" , 1 + bfs() );
		string s;
		while( sink != -1 )
			s = " " + string( 1 , 'F' + sink ) + s , sink = pa[ sink ];
		cout << s << endl;
	}
}



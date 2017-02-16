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

#define N 50
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

vi E[ N ];
int match[ N ] , vis[ N ];

bool dfs( int u ){
	if( vis[ u ] )return 0;
	vis[ u ] = 1;
	REP( i , E[ u ].size() )
	{
		int v = E[ u ][ i ];
		if( match[ v ] == -1 || dfs( match[ v ] ) )
		{
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}

int bpm(){
	clr( match , -1 );
	int cnt = 0;
	REP( i , N ){
		clr( vis , 0 );
		cnt += dfs( i );
	}
	return cnt;
}
int main()
{
	int n;
	cin >> n;
	vector< string > S( n );
	REP( i , n ) cin >> S[ i ];
	vector< string > T;
	string s , t ;
	while( cin >> s )
		T.pb( s );
	s = accumulate( all( S ) , string("") );
	sort( all( s ) );
	s.resize( unique( all( s ) ) - s.begin() );
	t = accumulate( all( T ) , string("") );
	sort( all( t ) );
	t.resize( unique( all( t ) ) - t.begin() );
	int ns = s.size() , nt = t.size();
	REP( i , ns )
		REP( j , nt )
			E[ s[ i ] - 'a' ].pb( t[ j ] - 'A' );
	bpm();
	string dec( 26 , '0' );
	REP( i , 26 )
		if( match[ i ] != -1 ) dec[ i ] = match[ i ] + 'A';
	int nT = T.size();
	REP( i , nT )
	{
		int len = T[ i ].size();
		REP( j , len )
			putchar( dec[ T[ i ][ j ] - 'A' ] );
		if( i == nT )puts( "" );
		else putchar( ' ' );
	}
}



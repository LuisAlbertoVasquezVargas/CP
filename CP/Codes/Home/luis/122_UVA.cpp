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
#define INF (1<<30)
#define EPS (1e-5)

void process( string s , int &num , string &p )
{
	int ns = s.size();
	REP( i , ns ) if( s[ i ] == '(' || s[ i ] == ')' || s[ i ] == ',' ) s[ i ] = ' ';
	istringstream in( s );
	p = "";
	in >> num >> p;
	//cout << num <<  "::" << p << endl;
}
string parent( string s )
{
	if( s.empty() ) return "";
	int ns = s.size();
	return s.substr( 0 , ns - 1 );
}

int main()
{
	string s , p;
	int num;
	while( cin >> s )
	{
		vi values ;
		vector< string > path;
		process( s , num , p );
		values.pb( num ) , path.pb( p );
		while( cin >> s )
		{
			if( s == "()" ) break;
			process( s , num , p );
			values.pb( num ) , path.pb( p ); 
		}
		int nP = path.size();
		//REP( i , nP ) cout << path[ i ] << endl; 
		set< string >S( all( path ) );
		if( S.size() != path.size() ){
			puts( "not complete" );
			continue;
		}
		bool complete = 1;
		REP( i , nP ) 
			if( !S.count( parent( path[ i ] ) ) )
			{
				complete = 0;
				break;
			}
		if( !complete ){
			puts( "not complete" );
			continue;
		}
		vector< pair< pair< int , string > , int > >V( nP );
		REP( i , nP ) V[ i ] = mp( mp( path[ i ].size() , path[ i ] ) , values[ i ] );
		//REP( i , nP ) cout << V[ i ].fi.fi << " " << V[ i ].fi.se << " " << V[ i ].se << endl;
		sort( all( V ) );
		REP( i , nP )
			printf( "%d%s" , V[ i ].se , i + 1 == nP ? "\n":" " );
	}
}


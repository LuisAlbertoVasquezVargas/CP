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

#define N ( 1 << 16 )
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

ll toi( string s ){
	transform( all( s ) , s.begin() , ::toupper );
	ll ans = 0;
	int ns = s.size();
	REP( i , ns )
		ans = ans*16 + ( isalpha( s[ i ] ) ? ( s[ i ] - 'A' + 10 ):( s[ i ] - '0' ) );
	if( ans >= N ) return N - 1;
	if( ans <= 0 ) return 0;
	return ans;
}
string tos( ll t ){
	if( t <= 0 ) return "0";
	if( t >= N ) return "FFFF";
	string s = "";
	while( t )
	{
		int r = t%16;
		if( r <= 9 ) s += '0' + r ;
		else s += 'A' + r - 10;
		t /= 16;
	}
	reverse( all( s ) );
	return s;
}
bool val( string s )
{
	if( s[ 0 ] == '+' ) return 0;
	if( s[ 0 ] == '-' ) return 0;
	if( s[ 0 ] == '&' ) return 0;
	if( s[ 0 ] == '|' ) return 0;
	if( s[ 0 ] == '~' ) return 0;
	if( s[ 0 ] == 'X' ) return 0;
	return 1;
}
string f( string a , string b , string op )
{
	ll A = toi( a ) , B = toi( b );
	if( op[ 0 ] == '+' ) return tos( A + B );
	if( op[ 0 ] == '-' ) return tos( A - B );
	if( op[ 0 ] == '&' ) return tos( A & B );
	if( op[ 0 ] == '|' ) return tos( A | B );
	if( op[ 0 ] == 'X' ) return tos( A ^ B );
}
string g( string s )
{
	ll A = toi( s );
	A = A^( N - 1 );
	//cout << A << endl;
	return tos( A );
}
string f( string cad )
{
	istringstream in( cad );
	stack< string >S;
	string s;
	while( in >> s )
	{
		if( val( s ) )
			S.push( s );
		else
		{
			if( s == "~"  )
			{
				if( S.empty() ) return "ERROR";
				string a = S.top() ;
				S.pop();
				S.push( g( a ) );
			}
			else
			{
				if( S.size() < 2 ) return "ERROR";
				string a = S.top() ; 
				S.pop();
				string b = S.top() ; 
				S.pop();
				S.push( f( b , a , s ) );
			}
		}
	}
	if( S.size() == 1 ) return S.top();
	return "ERROR";
}
int main()
{
	string s;
	while( getline( cin , s ) )
	{
		s = f( s ) ;
		if( s == "ERROR" ){
			cout << s << '\n';
			continue;
		}
		int ns = s.size();
		cout << string( 4 - ns , '0' ) + s << '\n';
	}
}



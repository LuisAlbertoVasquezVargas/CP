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

int n , m;
bool SOLVE = 0;
vi enc( 30 , -1 );
vi facil( 30 );
vector< string > V , W;
void f( int pos )
{
	if( SOLVE ) return;
	if( pos == m )
	{
		string s;
		REP( i , m )
		{
			if( i ) s += " ";
			REP( j , W[ i ].size() )
			{
				if( enc[ W[ i ][ j ] - 'A' ] == -1 )return;
				s += 'A' + enc[ W[ i ][ j ] - 'A' ] ;
			}
		}
		SOLVE = 1;
		cout << s << '\n';
		return;
	}
	facil[ pos ] = 0;
	f( pos + 1 );
	
	//facil[ pos ] = 1;
	//f( pos + 1 );
	int sz = W[ pos ].size();
	REP( i , n )
	{
		if( V[ i ].size() != W[ pos ].size() ) continue;
		int sz = V[ i ].size();
		bool ok = 1;
		REP( j , sz )
			if( enc[ W[ pos ][ j ] - 'A' ] != -1 && enc[ W[ pos ][ j ] - 'A' ] != V[ i ][ j ] - 'a' ){
				ok = 0;
				break;
			}
		if( ok == 0 )continue;
		//test
		vi temp = enc , temp2 = enc;
		REP( j , sz )
			temp2[ W[ pos ][ j ] - 'A' ] = V[ i ][ j ] - 'a' ;
		enc = temp2;
		facil[ pos ] = 1;
		f( pos + 1 );
		facil[ pos ] = 0;
		enc = temp;
	}
	
}
int main()
{
	cin >> n;
	V.resize( n );
	REP( i , n ) cin >> V[ i ];
	string s;
	while( cin >> s ) W.pb( s );
	m = W.size();
	f( 0 );
}



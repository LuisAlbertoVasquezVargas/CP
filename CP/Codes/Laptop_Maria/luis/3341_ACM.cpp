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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , tc ;
string dumm , s , t;

int main()
{
	cin >> tc;
	getline( cin , dumm );
	while( tc -- )
	{
		getline( cin , s );
		n = 0;
		istringstream in(s);
		vi v;
		while( in >> t ) n++ , v.pb( t[0] - '0' );
		int m = n/2;
		string P = string( m , '0' ) , string( n - m , '1' );
		int mini = INF;
		sort( all( v ) );
		do
		{
			int p = 0 , q = 0 ;
			bool val = 1;
			REP( i , n )
				if( P[i] == '0' )
				{
					if( p == 0 && v[i] == 0 )val = 0;
					p = p*10 + v[i];
				}
				else
				{
					if( q == 0 && v[i] == 0 )val = 0;
					q = q*10 + v[i];
				}
			if( val || ( !val && ( p == 0 || q == 0 ) ) )mini = min( mini , abs( p - q ) );
		}
		while( next_permutation( all( v ) ) );
		printf( "%d\n" , mini );
	}
}



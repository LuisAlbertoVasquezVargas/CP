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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
ll Pot[N];
string s;
vector< vector< pair< ll , ll > > > memo;
pair< ll , ll > dp( int n1 , int n2 )
{
	int pos = 2*n - n1 - n2;
	if( pos == 2*n )return mp( 0 , 0 );
	pair< ll ,ll > &dev = memo[ n1 ][ n2 ];
	if( dev.fi == -1 )
	{
		pair< ll , ll > op1 , op2;
		pair< ll , ll > t1 , t2 ;
		if( n1 )
		{
			t1 = dp( n1 - 1 , n2 );
			op1 = mp( Pot[n1-1]*(s[pos]-'0') + t1.fi , t1.se );
		}
		if( n2 ) 
		{
			t2 = dp( n1 , n2 - 1 );
			op2 = mp( t2.fi , Pot[n2-1]*(s[pos]-'0') + t2.se );
		}
		if( op1.fi + op1.se > op2.fi + op2.se )
			dev = op1;
		else dev = op2;
		if( n1 == 0 )dev = op2;
		if( n2 == 0 )dev = op1;
	}
	return dev;
}
string f( int n1 , int n2 )
{
	int pos = 2*n - n1 - n2;
	if( pos == 2*n )return "";
	pair< ll ,ll > &dev = memo[ n1 ][ n2 ];

	pair< ll , ll > op1 , op2;
	pair< ll , ll > t1 , t2 ;
	if( n1 )
	{
		t1 = dp( n1 - 1 , n2 );
		op1 = mp( Pot[n1-1]*(s[pos]-'0') + t1.fi , t1.se );
	}
	if( n2 ) 
	{
		t2 = dp( n1 , n2 - 1 );
		op2 = mp( t2.fi , Pot[n2-1]*(s[pos]-'0') + t2.se );
	}
	if( n1 == 0 )return "H" + f( n1 , n2 - 1 );
	if( n2 == 0 )return "M" + f( n1 - 1, n2 );
	if( op1.fi + op1.se > op2.fi + op2.se )
		return "M" + f( n1 - 1, n2 );
	return "H" + f( n1 , n2 - 1 );
}
int main()
{
	Pot[0] = 1;
	for( int i = 1 ; i <= 19 ; ++i ) Pot[i] = 10*Pot[i-1];
	while( cin >> n )
	{
		cin >> s;
		memo = vector< vector< pair< ll , ll > > >( n + 1 , vector< pair< ll , ll > >( n + 1 , mp( -1 , -1 ) ) );
		dp( n ,  n );
		cout << f( n , n ) << endl;
	}
}



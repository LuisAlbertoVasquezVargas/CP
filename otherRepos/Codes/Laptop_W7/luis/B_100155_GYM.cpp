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

#define N 450
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string s;
vector< string >V;
vi I,R,SZ;

int main()
{
	sync
	while( cin >> s )
	{
		V.clear();
		I.clear() , R.clear(),SZ.clear();
		int ns = s.size();
		for( int i = 0 ; i < ns ; i+=450 )
		{
			string temp = s.substr( i , min(450, ns - i ) );
			V.pb( temp );
			if( !I.empty() )
				I.pb( I.back() + SZ.back() );
			else I.pb( 0 );
			SZ.pb( temp.size() );
		}
		string op;
		int x , y;
		while( cin >> op )
		{
			if( op == "END" )break;
			if( op[0] == 'I' )
			{
				cin >> s >> x;
			}
			else
			{
				cin>> x >> y;
				int n  = V.size();
				vector< pair< int , string > >t;
				REP( i , n )
				{
					int a = I[i] , b = I[i] + SZ[i] - 1;
					if( x >= a && x <= b && y <= b )
						t.pb( mp( x , V[i].substr( x - a , y - x + 1 ) ) );
					else if( x >= a && x <= b )
						t.pb( mp( x , V[i].substr( x - a ) ) );
					else if( y >= a && y <= b )
						t.pb( mp( a , V[i].substr( 0 , y - a + 1 ) ) );
				}
				sort( all( t ) );
				string q ;
				int nt = t.size();
				REP( i , nt ) q += t[i].se ;
				cout << q << endl;
			}
		}
	}
}



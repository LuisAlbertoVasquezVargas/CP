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

int n;

int main()
{
	while( cin >> n )
	{
		vector< string >S( n );
		map< string , int >ID;
		REP( i ,  n ) cin >> S[i], ID[S[i]] = i;
		vector< pair< pii , pii > >V( n , mp( mp( 0 , 0 ) , mp( 0 , 0 ) ) );
		REP( i , n )V[i].se.se = i;
		string s;
		getline( cin , s );
		REP( i , (n*(n-1))/2 )
		{
			getline( cin , s );
			int ns = s.size();
			REP( i , ns ) if( !isalnum( s[i] ) )s[i] = ' ';
			istringstream in( s );
			string u , v ;
			int x , y ;
			in >> u >> v >> x >> y ;
			int p = ID[u] , q = ID[v];
			if( x == y )
			{
				V[p].fi.fi++ , V[q].fi.fi++;
				V[p].se.fi += x , V[q].se.fi += y;
			}
			else if( x > y )
			{
				V[p].fi.fi+=3;
				V[p].se.fi += x , V[q].se.fi += y;
				V[p].fi.se += x - y , V[q].fi.se += y - x;
			}
			else
			{
				V[q].fi.fi+=3;
				V[p].se.fi += x , V[q].se.fi += y;
				V[p].fi.se += x - y , V[q].fi.se += y - x;
			}
		}
		sort( rall( V ) );
		vector< string > A(n/2);
		REP( i , n/2 )
			A[i] = S[V[i].se.se];
		sort( all(A) );
		int m = n/2;
		REP( i , m ) cout << A[i] << (1?"\n":" ");
	}
}



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
vi parent , sz;

int Find( int p )
{
	if( p == parent[p] )return p;
	return parent[p] = Find( parent[p] );
}

void Union( int p , int q )
{
	p = Find( p ) , q = Find( q );
	if( p != q )
	{
		parent[ p ] = q;
		sz[q] += sz[p];
	}
}
int main()
{
	sync;
	int tc;
	cin >> tc;
	while( tc-- )
	{
		cin >> n;
		int id = 0;
		map< string , int >M;
		parent.clear();
		sz.clear();
		REP( i , n )
		{
			string s , t;
			cin >> s >> t;
			if( !M.count( s ) )M[s] = id , parent.pb(id++),sz.pb(1);
			if( !M.count( t ) )M[t] = id , parent.pb(id++),sz.pb(1);
			Union( M[s] , M[t] );
			printf( "%d\n" , sz[Find(M[s])] ); 
		}
	}
}



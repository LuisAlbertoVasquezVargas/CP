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

struct UF
{
	int SZ;
	vi parent , rank;
	UF(){}
	UF( int _n )
	{
		SZ = _n;
		parent.resize( _n ) , rank.resize( _n );
		init();
	}
	void init()
	{
		REP( i , SZ ) parent[i] = i , rank[i] = 1;
	}
	int Find(int a)
	{
		if(parent[a] == a) return a;
		return parent[a] = Find(parent[a]);
	}
	void Union(int a, int b)
	{
		int pa = Find(a);
		int pb = Find(b);
		if(pa != pb)
		{
			if(rank[pa] < rank[pb]) parent[pa] = pb;
			else if(rank[pa] > rank[pb]) parent[pb] = pa;
			else
			{
				parent[pb] = pa;
				rank[pa]++;
			}
		}
	}
};
int main()
{
	int n , m;
	while( cin >> n >> m )
	{
		UF uf = UF( n );
		int r = n;
		for( int i = 0 ; i < m ; ++i )
		{
			int x , y ;
			cin >> x >> y;
			x-- , y--;
			if( uf.Find( x ) != uf.Find(y) )
				uf.Union( x , y ) , n--;	
		}

		if( n == 1 && r == m )
			puts("FHTAGN!");
		else	puts("NO");
	}
}


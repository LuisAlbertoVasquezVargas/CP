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
#define MAXN 105

using namespace std;

int n , m ;
vector< int >V[N];

struct UF
{
	int SZ;
	vi id;
	UF(){}
	UF( int _n )
	{
		SZ = _n;
		id.resize( _n );
		init();
	}
	void init()
	{
		REP( i , SZ ) id[i] = i ;
	}
	int Find(int a)
	{
		if(id[a] == a) return a;
		return id[a] = Find(id[a]);
	}
	void Union(int a, int b)
	{
		if( Find( a ) != Find( b ) )
			id[ Find(a) ] = Find(b);
	}
};
int main()
{
	while( cin >> n >> m )
	{
		int t , u , v = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			int tam;
			cin >> tam;
			if( tam  == 0 ) v++;
			V[i].resize(tam);
			for( int j = 0 ; j < tam ; ++j )
				cin >> V[i][j];
			sort( all(V[i]) );
		}
		UF uf = UF( n );
		for( int i = 0 ; i < n ; ++i )
			for( int j = 0 ; j < n ; ++j )
				for( int k = 0 ; k < V[i].size() ; ++k )
					if( binary_search( all(V[j]) , V[i][k] ) && uf.Find(i) != uf.Find(j) )
						uf.Union( i , j );
		sort( all( uf.id ) );
		t = unique( all( uf.id ) ) - uf.id.begin();
		u = t - v;
		cout << max( 0 , u - 1 ) + v << endl;
	}
}

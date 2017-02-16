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

#define N 2505
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , m , t = 1;
int M[N][N];
int main()
{
	while( cin >> m >> n )
	{
		if( !m )break;

		me( M , 0 );
		REP( i , m )
		{
			vi v(n);
			REP( j , n ) sc( v[j] );
			for( int j = 0 ; j + 1 < n ; ++j ) M[v[j]][v[j+1]]--,M[v[j+1]][v[j]]++;
		}
		vvi adj( n );
		vi in( n ) , ord;
		//REP( i , n )REP( j , n ) cout << M[i][j] <<(j+1==n?"\n":" ");
		REP( i , n )REP( j , n ) 
			if( M[i][j] > 0 )
			{
				//cout << i << " " << j << endl;
				adj[i].pb(j); 
				in[j]++;
			}
		REP( i , n )
		{
			int k = adj[i].size();
			/*
			cout << i << " : ";
			if( !k )cout << endl;
			REP( j , k )cout << adj[i][j] << ((j+1==k)?"\n":" ");
			*/
		}
		int cmp = 0;
		priority_queue < int >Q;
		REP( i , n )
			if( in[i] == 0 )
				Q.push( -i ) , cmp++;
		while( !Q.empty() )
		{
			int u = Q.top();
			u = -u;
			Q.pop();
			ord.pb( u );
			int nG = adj[u].size();
			for( int i = 0 ; i < nG ; ++i )
			{
				int v = adj[u][i];
				in[v]--;
				if( in[v] == 0 )
				Q.push(-v);
			}
		}
		int tam = ord.size();
		cout << "Case " << t++ << ": ";
		if( tam == n && cmp == 1 )
			cout << ord.back() << endl;
		else cout << "Condorcet winner" << endl;
	}
}




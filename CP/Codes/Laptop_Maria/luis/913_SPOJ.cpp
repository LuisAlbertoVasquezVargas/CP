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

int n , tc , x , y , w , K;
vector< vector< pii > > E;
char s[ 8 ];
int D[ N ] , vis[ N ] , parent[ N ];
int P[ N ][ 21 ] , L[N];

void dfs( int u )
{
	vis[ u ] = 1;
	FOR( v , E[u] )
		if( !vis[(*v).fi] )
		{
			D[ (*v).fi ] = D[u] + (*v).se;
			L[ (*v).fi ] = L[u] + 1;
			parent[ (*v).fi ] = u;
			dfs( (*v).fi );
		}
}

void RMQ()
{
     for( int i = 0 ; i < n ; ++i )
          P[i][0] = parent[i];
     for( int j = 1 ; (1<<j) < n ; ++j )
          for( int i = 0 ; i < n ; ++i )
               if(P[i][j-1]!=-1)
                    P[i][j] = P[P[i][j-1]][j-1];
}
int LCA( int p,int q)
{
     if( L[p] > L[q] ) swap(p,q);
     int dif = L[q] - L[p];
     for( int j = 16 ; j >= 0 ; j-- )
          if( dif >= (1<<j) )
          {
               q = P[q][j];
               dif -= (1<<j);
          }

     if( p == q )return p;
     for( int j = 16 ; j >= 0 ; --j )
          if( P[p][j] != P[q][j])
          {
               p = P[p][j];
               q = P[q][j];     
          }
     return parent[p];
}
int kth( int p, int q ,int k)
{
     int lca = LCA(p,q);
     int d1 = L[p]-L[lca];
     int d2 = L[q]-L[lca];
     if( k == d1 ) return lca;
     if( k < d1 )
     {
          for( int j = 16 ; j >= 0 ; j-- )
               if( k >= (1<<j) )
               {
                    p = P[p][j];          
                    k-=(1<<j);
               }
          return p;
     }
     else
     {
          k = d1 + d2 - k;      
          for( int j = 16 ; j >= 0 ; j-- )
               if( k >= (1<<j) )
               {
                    q = P[q][j];          
                    k-=(1<<j);
               }
          return q;          
	}
}
int main()
{
	sc( tc );
	while( tc-- )
	{
		sc( n );
		E.clear();
		E.resize( n );
		REP( i , n - 1 )
		{
			sc( x ) , sc( y ) , sc( w );
			x-- , y--;
			E[ x ].pb( mp( y , w ) );
			E[ y ].pb( mp( x , w ) );
		}
		me( vis , 0 );
		me( P , -1 );
		parent[ 0 ] = -1;
		dfs( 0 );
		RMQ();
		while( 1 )
		{
			scanf( "%s" , s );
			if( s[0] == 'K' )
			{
				sc( x ) , sc( y ) , sc( K );
				x -- , y-- , K-- ;
				printf( "%d\n" , kth( x , y , K ) + 1 );	
			}
			else if( s[1] == 'I' )
			{
				sc( x ) , sc( y );
				x -- , y--;
				int lca = LCA( x , y );
				printf( "%d\n" , (D[x] - D[lca]) + (D[y]-D[lca]) );
			}
			else break;
		}
		puts("");
	}
}



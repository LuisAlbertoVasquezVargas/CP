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

#define N 105
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string s;
vi f( vi a , vi b )
{
	vi r = a;
	int nb = b.size();
	REP( i , nb )
		r.pb( -b[ nb - i - 1 ] );
	return r;
}
int main()
{
	sync
	int n , m , tc = 1;
	while( cin >> n >> m && n )
	{
		vi V[ N ][ N ];
		REP( i , n ) REP( j , m )
		{
			int x;
			cin >> x;
			V[ i ][ j ].clear();
			V[ i ][ j ].pb( x );
		}
		n-- , m--;
		int a =  0 , b = 0;
		getline( cin , s );
		getline( cin , s );
		int ns = s.size();
		REP( i , ns )
		{
			if( s[ i ] == 'T' )
			{
				for( int k = b ; k <= m ; ++k )
				{
					V[ a + 1 ][ k ] = f( V[ a + 1 ][ k ] , V[ a ][ k ] ) ; V[ a ][ k ].clear();
				}
				a++;
			}
			else if( s[ i ] == 'B' )
			{
				for( int k = b ; k <= m ; ++k )
				{
					V[ n - 1 ][ k ] = f( V[ n - 1 ][ k ] , V[ n ][ k ] ) ; V[ n ][ k ].clear();
				}
				n--;
			}
			else if( s[ i ] == 'L' )
			{
				for( int k = a ; k <= n ; ++k )
				{
					V[ k ][ b + 1 ] = f( V[ k ][ b + 1 ] , V[ k ][ b ] ) ; V[ k ][ b ].clear();
				}
				b++;
			}
			else 
			{
				for( int k = a ; k <= n ; k++ )
				{
					V[ k ][ m - 1 ] = f( V[ k ][ m - 1 ] , V[ k ][ m ] ) ; V[ k ][ m ].clear();
				}
				m--;
			}
		}
		int sz = V[ a ][ b ].size();
		printf( "Case %d:" , tc++ );
		REP( i , sz )
			if( V[ a ][ b ][ i ] > 0 )
				printf( " %d" , V[ a ][ b ][ i ] );
		puts( "" );
	}
}



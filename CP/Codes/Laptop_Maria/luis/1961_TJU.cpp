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

int t , n;
vi V( 12 );

int main()
{
	while( scanf( "%d%d" , &t , &n ) == 2 && n )
	{
		REP( i , n )sc( V[i] );
		vvi W;
		REP( mask , 1<<n )
		{
			int sum = 0;
			vi temp;
			REP( i , n )if( (1<<i)&mask ) sum += V[i] , temp.pb( V[i] );
			if( sum == t )
			{
				sort( rall(temp) );
				W.pb( temp );	
			}
		}
		sort( rall( W ) );
		n = unique( all( W ) ) - W.begin();
		printf( "Sums of %d:\n" , t ); 
		if( !n )puts( "NONE" );
		REP( i , n )
		{
			int m = W[i].size();
			REP( j , m ) printf( "%d%s" , W[i][j] , (j+1==m?"\n":"+") );
		}
	}
}


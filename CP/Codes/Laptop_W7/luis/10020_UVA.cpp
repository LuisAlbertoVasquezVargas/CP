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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int m;
pii P[ N ];
int Ind[ N ] , used[ N ];
bool cmp( int i , int j )
{
	if( P[ i ].fi == P[ j ].fi ) return P[ i ].se > P[ j ].se ;
	return P[ i ].fi < P[ j ].fi ;
}
int main()
{
	int tc;
	sc( tc );
	REP( cases , tc )
	{
		if( cases ) puts( "" );
		sc( m );
		int n = 0;
		while( 1 ){
			sc( P[ n ].fi ) , sc( P[ n ].se );
			n++;
			if( P[ n - 1 ].fi == 0 && P[ n - 1 ].se == 0 )break;
		}
		n--;
		REP( i , n ) Ind[ i ] = i;
		sort( Ind , Ind + n , cmp );
		int M = 0;
		vi V;
		REP( i , n )
		{
			int j = -1 , best = -INF;
			if( P[ Ind[ i ] ].fi > M ) break;
			while( i < n && P[ Ind[ i ] ].fi <= M )
			{
				if( P[ Ind[ i ] ].se > best ) best = P[ Ind[ i ] ].se , j = Ind[ i ];
				i++;
			}
			i--; 
			if( j != -1 && best > M ) M = best , V.pb( j );
			else break;
			if( M >= m ) break;
		}
		if( M >= m ){
			int nv = V.size();
			printf( "%d\n" , nv );
			REP( i , nv ) printf( "%d %d\n" , P[ V[i] ].fi , P[ V[i] ].se );
		}
		else puts( "0" );
	}
}



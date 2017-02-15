#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>

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

int n;
int DP[N][2] , lvl[N];
vvi E;
pii L[N];
/*
int dp( int u , int p , int take )
{
    int &dev = memo[u][take];
    if( dev == -1 )
    {
        dev = INF;
        int op1 = 0 , op2 = 0;
        FOR( v, E[u] )
            if( *v != p )
                op1 += dp( *v , u , 1 ), op2 += dp( *v , u , 0 );
        dev =  1 + op1;
        if( take )
            dev = min( dev  , op2 );
    }
    return dev;
}
*/

int main()
{
    sc( n );
    E.resize( n + 1 );
    REP( i , n - 1 )
    {
        int x , y;
        sc( x ) , sc( y );
        E[x].pb(y);
        E[y].pb(x);
    }
    E[1].pb(0);
    E[0].pb(1);
    int t = 0 , m = 0;
    clr( lvl , -1 );
    queue< int >Q;
    lvl[ 0 ] = 0;
    L[m++] = mp( 0 , 0 );
    Q.push( 0 );

	while( !Q.empty() )
	{
		int u = Q.front();
		Q.pop();
		FOR( v , E[u] )
			if( lvl[*v] == -1 )
			{
				lvl[*v] = lvl[u] + 1;
				t = max( t , lvl[*v] );
				L[ m++ ] = mp( lvl[*v] , *v );
				Q.push( *v );
			}
	}
	sort( L , L + m );
	int ind;
	for( int i = m - 1 ; i >= 0 ; i-- )
	{
		ind = i;
		if( L[i].fi != t )break;
		int v = L[i].se;
		DP[v][0] = 1 , DP[v][1] = 0;
	}
	for( int T = t - 1 ; T >= 0 ; T -- )
	{
		for( int k = ind ; k >= 0 ; --k )
		{
			ind = k;
			if( L[k].fi != T )break;
			REP( take , 2 )
			{
				int u = L[k].se;
				int op1 = 0 , op2 = 0;
				FOR( v , E[u] )
					op1 += DP[*v][1] , op2 += DP[*v][0];
				int &dev = DP[u][take] = 1 + op1;
				if( take )
					dev = min( dev , op2 );
			}
		}
	}
    printf( "%d\n" , DP[1][1] );
}



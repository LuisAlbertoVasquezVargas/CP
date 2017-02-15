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
int memo[N][2];
vvi E;

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

int main()
{
    sc( n );
    E.resize( n );
    REP( i , n - 1 )
    {
        int x , y;
        sc( x ) , sc( y );
        x-- , y--;
        E[x].pb(y);
        E[y].pb(x);
    }
    clr( memo , -1 );
    printf( "%d\n" , dp( 0 , -1 , 1 ) );
}



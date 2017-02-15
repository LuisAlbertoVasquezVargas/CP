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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int ns , n ;
char s[ N ];
int F[ 26 ];

bool f( int k )
{
    int cnt = 0;
    REP( i , 26 )   
        if( F[i] ) cnt += ( F[i] - 1 )/k + 1;
    return cnt <= n;
}

int main()
{
    while( scanf( "%s%d" , s , &n ) == 2 )
    {
        clr( F , 0 );
        ns = strlen( s );
        REP( i , ns )F[ s[i] - 'a' ]++;
        int ans = INF;
        int lo = 1 , hi = ns;
        if( !f(hi) )
        {
            puts( "-1" );
            continue;
        }
        while( hi - lo > 1 )
        {
        	int med = ( lo  + hi )>>1;
        	if( f( med ) )hi = med;
        	else lo = med;
        }
        ans = hi;
        if( f( 1 ) ) ans = 1;
        char t[n+5];
        t[n] = 0;
        int sz = 0;
        REP( i , 26 )   
            if( F[i] ) 
				REP( j , ( F[i] - 1 )/ans + 1 )
					t[sz++] = 'a' + i ;
		while( sz < n )t[sz++] = 'a' ;
        printf( "%d\n%s\n" , ans , t );
    }
}

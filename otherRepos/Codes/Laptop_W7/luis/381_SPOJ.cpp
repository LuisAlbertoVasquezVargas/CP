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

#define N 105
#define MOD 1000000007
#define INF (1e100)
#define EPS (1e-5)

using namespace std;
int n , m;
double d[N][N];
void init()
{
    for( int i = 0 ; i < n ; ++i )
        for( int j = 0 ; j < n ; ++j )
            d[i][j] = INF;
    REP( i , m )
    {
    	int x , y , p;
    	scanf( "%d%d%d" , &x , &y , &p );
    	x-- , y--;
    	d[x][y] = log10( 100.0/p );
    	d[y][x] = log10( 100.0/p );
    }
    REP( i , n ) d[i][i] = 1;
}

void floyd()
{
    for( int k = 0 ; k < n ; ++ k )
        for( int i = 0 ; i < n ; ++i )
            for( int j = 0 ; j < n ; ++j )
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);	
}

int main()
{
	while( scanf( "%d%d" , &n , &m ) == 2 )
	{
		if( n == 0 )break;
		init();
		floyd();
		double ans = 100.0/pow( 10.0 ,d[0][n-1] );
		printf( "%.6lf percent\n" , ans );
	}
}



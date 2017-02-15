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

struct RMQ
{
	int SZ;
	vvi M;
	RMQ(){}
	RMQ( vi &A )
	{
		SZ = A.size(); M = vvi( SZ , vi( 21 ) );
		REP( i , SZ ) M[i][0] = A[i];
	    for( int j = 1 ; (1<<j) <= SZ ; j++ )
	        for( int i = 0 ; i + (1<<j) - 1 < SZ ; i++ )
	            if( M[i][j-1] < M[i+(1<<(j-1))][j-1] ) 
	                M[i][j] = M[i][j-1];
	            else M[i][j] = M[i+(1<<(j-1))][j-1];
	}
	int query(int xx,int yy)
	{
	    if( yy < xx ) swap( xx , yy );
	    int r = yy - xx + 1;
	    int k = 0;
	    while( (1<<k) <= r ) k++;
	    k--;
	    if(  M[xx][k]  < M[yy - (1<<k) + 1 ][ k ]  ) 
	        return M[xx][k];
	    return M[yy - (1<<k) + 1 ][ k ];
	}
};
int n , q ;

int main()
{
	while( scanf( "%d" , &n ) == 1 )
	{
		if( !n )break;
		sc( q );
		vi v( n ) , L( n ) , R( n ) , F, Ind( n );
		REP( i , n ) sc( v[i] );
		int nF = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			int j = i;
			while( j < n && v[j] == v[i] )j++;
			j--;
			for( int k = i ; k <= j ; k++ )
				L[k] = i , R[k] = j , Ind[k] = nF;
			nF++;
			F.pb( -(j - i + 1) ); 
			i = j;
		}
		RMQ rmq = RMQ( F );
		while( q-- )
		{
			int x , y;
			sc( x ) , sc( y );
			x-- , y--;
			int i = Ind[x] + 1, j = Ind[y] - 1, ans = -INF;
			if( Ind[x] == Ind[y] ) ans = y - x + 1;
			else if( i <= j )
			{
				ans = max( ans , -rmq.query(i,j) );
				ans = max( ans , R[x] - x + 1 );
				ans = max( ans , y - L[y] + 1 );
			}else
			{
				ans = max( ans , R[x] - x + 1 );
				ans = max( ans , y - L[y] + 1 );
			}
			printf( "%d\n" , ans );
		}
	}
}



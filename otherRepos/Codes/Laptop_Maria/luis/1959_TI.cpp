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

int A[N] , B[N] , F[N];
pii T[ 4*N + 31 ];
int SZ = N;

void update( int node , int a , int b , int x , int val )
{
	if( a > x || x > b )return;
	int v1 = (node<<1) + 1 , v2 = v1 + 1 , med = ( a + b )>>1;
	if( a == b )
		T[ node ] = mp( val , x );
	else
	{
		update( v1 , a , med , x , val );
		update( v2 , med + 1 , b , x , val );
		T[ node ] = max( T[v1] , T[v2] );
	}
}
void update( int x , int val )
{
	update( 0 , 0 , SZ - 1 , x , val );
}
pii query( int node , int a , int b , int x , int y )
{
	int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/2;	
	if( x > b || a > y )return pii( 0 , 0 );
	if( a >= x && y >= b )
		return T[ node ];
	return max( query( v1 , a , med , x , y ) , query( v2 , med + 1 , b , x , y ) );
}
pii query( int x , int y )
{
	return query( 0 , 0 , SZ - 1 , x , y );
}

int main()
{
    int n , m ;
    sc( n );
    REP( i , n ) sc( A[i] );
    sc( m );
    REP( i , m ) sc( B[i] );
    bool op = 0 ;
    int ind ;
    REP( i ,  m )if( !B[i] )
    {
        op = 1 , ind = i;
        break;
    }           
    int sz = 1 + n - m;
    int maxf = 0;
    if( op )
    {
        for( int i = 0 ; i < n ; ++i )
        { 
            int valueI = -1 , valueF = -1 ;
            if( i - sz >= 0 ) valueI = A[i - sz];
			valueF = A[i];
            if( valueI != -1 )
            {
            	int freq = --F[ valueI ];
            	update( valueI  , freq );	
            }
            if( valueF != -1 )
			{
				int freq = ++F[ valueF ];
            	update( valueF  , freq );
	        }
            if( i - sz + 1 >= 0 && !B[i - sz + 1] )
            {
            	pii p = query( 0 , SZ - 1 );
                B[i - sz + 1] = p.se;
            }
		}
    }
    else
    {
        for( int i = 0 ; i < n ; ++i )
        {
            int valueI = -1 , valueF = -1;
            if( i - sz >= 0 ) valueI = B[ i - sz ];
            if( i < m ) valueF = B[i];
            if( valueF != -1 )
            {
	            int freq = ++F[ valueF ];
            	update( valueF  , freq );
        	}
            if( valueI != -1 )
            {
            	int freq = --F[ valueI ];
            	update( valueI  , freq );
			}
			if( !A[i] )
            {
            	pii p = query( 0 , SZ - 1 );
                A[i] = p.se;
            }
		}
    
    }
    REP( i , n )printf( "%d%s" , A[i] , i+1==n?"\n":" " );
    REP( i , m )printf( "%d%s" , B[i] , i+1==m?"\n":" " );
    return 0;
}

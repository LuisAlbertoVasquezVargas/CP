#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
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
int n;
//int memo[ N ][ 2 ] , A[ N ];
int DP[ N ][ 2 ] , A[ N ];
char target[ N ];
/*
int dp( int pos , int menor )
{
    if( pos == n ) return 0;
    int &dev = memo[ pos ][ menor ];
    if( dev == -1 )
    {
        if( menor )
            dev = A[ pos ] + dp( pos + 1 , 1 );
        else
        {
            if( target[ pos ] == '0' )
            {
                dev = dp( pos + 1 , 0 );
            }
            else
            {
                dev = max( dp( pos + 1 , 1 ) , A[ pos ] + dp( pos + 1 , 0 ) );
            }
        }
    }
    return dev;
}*/
int main()
{
    while( sc( n ) == 1 )
    {
        REP( i , n ) sc( A[ n - i - 1 ] );
        scanf( "%s" , target );
        reverse( target , target + n );
        //clr( memo , -1 );
        DP[ n ][ 0 ] = DP[ n ][ 1 ] = 0;
        for( int pos = n - 1 ; pos >= 0 ; --pos )
            for( int menor = 0 ; menor <= 1 ; menor ++ )
            {
                int &dev = DP[ pos ][ menor ];
                if( menor )
                    dev = A[ pos ] + DP[ pos + 1 ][ 1 ];
                else
                {
                    if( target[ pos ] == '0' )
                    {
                        dev = DP[ pos + 1 ][ 0 ];
                    }
                    else
                    {
                        dev = max( DP[ pos + 1 ][ 1 ] , A[ pos ] + DP[ pos + 1 ][ 0 ] );
                    }
                }
            }
        printf( "%d\n" , DP[0][0] );
    }
}

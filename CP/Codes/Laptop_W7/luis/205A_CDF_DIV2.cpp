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

int main()
{
    int n;
    while( sc( n ) == 1 )
    {
        int ok = 0 , A = 0, B = 0 , a , b;
        REP( i , n )
        {
            sc( a ) , sc( b );
            A = A^( a&1 );
            B = B^( b&1 );
            if( ( a&1 ) ^ ( b&1 ) == 1 ) ok = 1;
        }
        if( A == B && A == 0 ) puts( "0" );
        else if( A == B && A == 1 ) puts( ok ? "1":"-1" );
        else puts( "-1" );
    }
}

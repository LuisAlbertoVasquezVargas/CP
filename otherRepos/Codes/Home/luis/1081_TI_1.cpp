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

#define N 46
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n , k;
int F[ N ];

int main()
{
    F[0] = F[1] = 1;
    for( int i = 2 ; i < N ; ++i )
        F[i]  = F[i-1] + F[i-2] ;
    while( scanf( "%d%d" , &n , &k ) == 2 )
    {
        //k--;
        if( k > F[n+1] )
        {
            puts( "-1");
            continue;
        }
        string S( n , '0' );
        REP( i , n )
            if( k > F[ n - i ] )
            {
                S[i] = '1';
                k -= F[ n - i ];
            }
        cout << S << '\n';
    }
    
}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

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

int n;
map< int , int > M;
int T[4*N] , F[N] , V[N] , W[N] , op[N];
char s[3];
/// a <= b 
int gcd( int a , int b )
{
	if(a == 0) return b;
	return gcd(b%a, a);
}
void update( int node , int a , int b , int ind , int val )
{
    //test
    if( a > ind || ind > b )return;
    if( a == b )
    {
        T[ node ] = val;
        return;
    }
    int v1 = (node<<1) + 1 , v2 = v1 + 1 , med = ( a + b )>>1;
    update( v1 , a , med , ind , val );
    update( v2 , med + 1 , b , ind , val );
    int p = T[v1] , q = T[v2];
    if( p > q )swap( p , q );
    T[ node ] = gcd( p , q );
}
int main()
{
    sync
    int m;
    sc( m );
    REP( i , m ) 
	{
		scanf( "%s%d" , s , &V[i] );
		W[i] = V[i];
		if( s[0] == '+' )op[i] = 1;
	}
    sort( W , W + m );
    n = unique( W , W + m ) - W;
    REP( i , n )M[ W[i] ] = i ;
    REP( i , m )
    {
        int val = V[i] , ind = M[val];
        if( op[i] )
        {
            if( F[ind] == 0 )update( 0 , 0, n - 1 , ind , val );
            F[ind]++;
        }
        else
        {
            if( F[ind] == 1 )update( 0 , 0, n - 1 , ind , 0 );
            F[ind]--;
        }
        printf( "%d\n" , max( T[0] , 1) );   
    }
}

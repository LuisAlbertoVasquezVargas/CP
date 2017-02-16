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
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

struct EuclidReturn{
    int u,v,d;
  
    EuclidReturn(int _u, int _v, int _d){
        u = _u; v = _v; d = _d;
    }
};
    
EuclidReturn Extended_Euclid(int a, int b){
    if(b==0) return EuclidReturn(1,0,a);
    EuclidReturn aux = Extended_Euclid(b,a%b);
    int v = aux.u-(a/b)*aux.v;
    return EuclidReturn(aux.v,v,aux.d);
}

// ax = b (mod n)
int solveMod(int a,int b,int n){
    EuclidReturn aux = Extended_Euclid(a,n);
    if(b%aux.d==0) return ((aux.u * (b/aux.d))%n+n)%n;
    return -1;// no hay solucuion
}

// ax = 1(mod n)
int modular_inverse(int a, int n){
    EuclidReturn aux = Extended_Euclid(a,n);
    return ((aux.u/aux.d)%n+n)%n;
}
long long chinese_remainder(vector<int> rem, vector<int> mod){
    long long ans = rem[0],m = mod[0];
    int n = rem.size();
  
    for(int i=1;i<n;++i){
        int a = modular_inverse(m,mod[i]);
        int b = modular_inverse(mod[i],m);
        ans = (ans*b*mod[i]+rem[i]*a*m)%(m*mod[i]);
        m *= mod[i];
    }
  
    return ans;
}
int main()
{
	vi rem( 3 ) , mod;
	mod.pb( 23 );
	mod.pb( 28 );
	mod.pb( 33 );
	int T = 23*28*33 , tc = 0;
	int target;
	while( sc( rem[ 0 ] ) == 1 ){
		sc( rem[ 1 ] );
		sc( rem[ 2 ] );
		sc( target );
		if( target == -1 ) break;
		REP( i , 3 ) rem[ i ] %= mod[ i ];
		int p = chinese_remainder( rem , mod );
		while( p <= target ) p += T;
		
		printf( "Case %d: the next triple peak occurs in %d days.\n" , ++tc , p - target );
	}
}



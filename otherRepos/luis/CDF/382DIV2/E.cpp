#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;


const int MAXN=(int)1e6;

bool prime[MAXN + 1];
vi primes;
void sieve(){
	memset( prime , true , sizeof( prime ) );
	prime[ 0 ] = false;
	prime[ 1 ] = false;
	for( int i = 2 ; i * i <= MAXN ; i++ )
		if( prime[ i ] )
			for( int j = i * i ; j <= MAXN ; j += i )
				prime[ j ] = false;
	REP(i,MAXN+1)
		if(prime[i])primes.pb(i);
}
int main(){
	

}




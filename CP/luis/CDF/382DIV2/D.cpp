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


const int MAXN=(int)1e5;

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
bool isPrime( int n ){
	if( n <= 2 ) return n == 2;
	if( !( n&1 ) ) return 0;
	for( int i = 3 ; i*i <= n ; i += 2 )
		if( n%i == 0 ) return 0;
	return 1;
}
int main(){
	sieve();
	int n;
	while(scanf("%d",&n)==1){
		if(isPrime(n)){
			puts("1");
			continue;
		}
		bool found=0;
		for(auto p:primes){
			int q=n-p;
			if(q>=2){
				if(binary_search(all(primes),q)||isPrime(q)){
					found=1;
					break;
				}
			}else break;
		}
		puts(found?"2":"3");
	}
}




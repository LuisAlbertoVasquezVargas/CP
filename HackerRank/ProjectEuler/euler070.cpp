#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define MAXN 10000000

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;
typedef long double ld;


vi get( int x , vi &F ){
	while( x ){
		F[ x % 10 ] ++;
		x /= 10;
	}
	return F;
}
int phi[MAXN + 1], prime[MAXN/10], sz;
bitset <MAXN + 1> mark;
int main(){

	for (int i = 2; i <= MAXN; i++ ){
		if(!mark[i]){
			phi[i] = i-1;
			prime[sz++]= i;
		}
		for (int j=0; j<sz && prime[j]*i <= MAXN; j++ ){
			mark[prime[j]*i]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]] = phi[i]*(prime[j]-1 );
		}
	}
	int n;
	sc( n );
	ll a = 100000000LL , b = 1;
	int ind = 0;
	
	vi x( 10 ) , y( 10 );
	for( int i = 2 ; i < n ; ++i ){
		get( i , x );
		get( phi[ i ] , y );
		if( x == y ){
			if( a * (ll) phi[ i ] > (ll) i * b ){
				ind = i;
				a = i;
				b = phi[ i ];
			}
		}
		REP( i , 10 ) x[ i ] = y[ i ] = 0;
	}
	printf( "%d\n" , ind );
}



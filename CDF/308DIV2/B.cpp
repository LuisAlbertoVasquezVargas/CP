#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<29)
#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;

long long g(long long x,long long d){
	long long r=0;
    while(x>0){
		if(x%10==d)r++;
		x/=10;    
    }
	return r;
}
long long f(long long N, long long D){
	if(N <= 0 )return 0;
	long long U=N/10+(N%10>=D)-(D==0);
	long long O=10*f(N/10-1,D);
	    for(long long i=(N/10)*10;i<=N;i++)O+=g(i/10,D);    
	return U+O;    
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		ll ans = 0;
		REP( i , 10 ) ans += f( n , i );
		cout << ans << '\n';
	}
}



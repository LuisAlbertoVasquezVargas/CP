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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll ceil( ll a , ll b ){
	if( a == 0 ) return 0;
	return (a - 1)/b + 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		ll K;
		scanf( "%d%lld" , &n , &K );
		vll v;
		REP( i , n ){
			int x;
			sc( x );
			v.pb( x );
		}
		ll cur = 0;
		ll cap = 0;
		REP( i , n ){
			cap --;
			if( cap < 0 ){
				cap = K;
				cur ++;
			}
			if( cap >= v[ i ] ){
				cap -= v[ i ];
			}else{
				//(K * t + cap >= v[ i ])
				//(t >= (v[ i ] - cap)/K)
				ll t = ceil( v[ i ] - cap , K );
				cur += t;
				cap = K * t + cap - v[ i ];
			}
		}
		printf( "%lld\n" , cur );
	}
}





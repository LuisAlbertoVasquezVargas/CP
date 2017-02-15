#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 15

typedef long long ll;
typedef vector< int > vi;

ll A[ N + 5 ];
int main(){
	ll n , L , R , X;
	while( cin >> n >> L >> R >> X ){
		REP( i , n ) cin >> A[ i ];
		int cnt = 0;
		REP( mask , (1<<n) ){
			ll maxi = LLONG_MIN , mini = LLONG_MAX;
			ll sum = 0;
			REP( i , n )
				if( mask & (1<<i) ){
					sum += A[ i ];
					maxi = max( maxi , A[ i ] );
					mini = min( mini , A[ i ] );
				}
			if( sum >= L && sum <= R && __builtin_popcount( mask ) >= 2 ){
				if( maxi - mini >= X ){
					cnt ++;
				}
			}
		}
		cout << cnt << '\n';
	}
}



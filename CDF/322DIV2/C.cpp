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

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){
	int n , K;
	while( sc( n ) == 1 ){
		sc( K );
		vvi T( 11 );
		REP( i , n ){
			int x;
			sc( x );
			T[ (x%10) ].pb( x );
		}
		ll ans = 0;
		int tot = n;
		while( tot ){
			int ind = -1;
			for( int i = 9 ; i >= 0 ; --i )
				if( SZ( T[ i ] ) ){
					ind = i;
					break;
				}
			assert( ind != -1 );
			int mod = ind , x = T[ ind ].back();
			T[ ind ].pop_back();
			tot --;
			if( x == 100 ){
				ans += (x/10);
				continue;
			}
			if( !K ){
				ans += (x/10);
				continue;
			}
			x ++;
			tot ++;
			T[ (x%10) ].pb( x );
			K --;
		}
		cout << ans << '\n';
	}
}






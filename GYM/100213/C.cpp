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

#define test puts("************test************");
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 1000000004

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll dx[] = { 0 , 0  , 1 , -1 };
ll dy[] = { 1 , -1 , 0 , 0 };

vll f( ll a , ll b ){
	ll S = a * b;
	ll x = a * (b / 2LL);
	if( b & 1 ) x += (a - 1)/2LL + 1LL;
	vll v = { x , S - x };
	return v;
}
int main(){
	
	freopen( "bw.in" , "r" , stdin );
	freopen( "bw.out" , "w" , stdout );
	
	int n;
	while( sc( n ) == 1 ){
		vi X , Y;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			x += N , y += N;
			X.pb( x ) , Y.pb( y );
		}
		reverse( all( X ) );
		reverse( all( Y ) );
		ll S = 0 , Su = 0;
		REP( i , n ){
			int j = (i + 1);
			if( j == n ) j = 0;
			int ind = -1;
			ll x = X[ i ] , y = Y[ i ];
			ll nx = X[ j ] , ny = Y[ j ];
			ll t;
			REP( k , 4 ){
				if( dx[ k ] != 0 ) t = (nx - x)/dx[ k ];
				else t = (ny - y)/dy[ k ];
				if( t > 0 && x + t * dx[ k ] == nx && y + t * dy[ k ] == ny ){
					ind = k;
					break;
				}
			}
			assert( ind != -1 );
			//DEBUG2( x , y );
			//DEBUG2( nx , ny );
			if( ind <= 1 ) continue;
			if( ind == 2 ){
				S += y * t;
				vll v = f( y , t );
				Su += v[ (x + y) & 1 ];
				//DEBUG( Su );
			}else{
				S -= y * t;
				vll v = f( y , t );
				Su -= v[ (nx + ny) & 1 ];
				//DEBUG( Su );
			}
		}
		cout << S - Su << " " << Su << '\n';
	}
}



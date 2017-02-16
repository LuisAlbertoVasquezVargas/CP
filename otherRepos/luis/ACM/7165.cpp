#include <bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )
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
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

const int N = 50;
const int MAXVAL = 5000;
int n;
bool used[ N + 1 ][ MAXVAL + 5 ];
ll memo[ N + 1 ][ MAXVAL + 5 ];
int val[ N + 5 ] , cant[ N + 5 ];
ll dp( int pos , int target ){
	if( pos == n ) return (target == 0) ;
	if( used[ pos ][ target ] ) return memo[ pos ][ target ];
	used[ pos ][ target ] = 1;
	ll &dev = memo[ pos ][ target ] = dp( pos + 1 , target );
	if( target - val[ pos ] >= 0 )
		dev += dp( pos + 1 , target - val[ pos ] );
	return dev;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int S ;
		sc( S ) , sc( n );

		REP( i , n ) sc( val[ i ] ) , sc( cant[ i ] );
		
		//bubleSort  
		//EZ GAME :v
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j ){
				if( cant[ i ] > cant[ j ] ){
					swap( val[ i ] , val[ j ] );
					swap( cant[ i ] , cant[ j ] );
				}
			}
		ll ans = 0;
		clr( used , 0 );
		for( int i = 1 ; i <= S ; ++i )
			if( S % i == 0 ){
				int pos = lower_bound( cant , cant + n , i ) - cant;
				ans += dp( pos , S / i );
			}
				
		printf( "Case %d: %lld\n" , tc + 1 , ans );
	}
}



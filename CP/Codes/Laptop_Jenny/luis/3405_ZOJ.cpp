#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define all( v ) v.begin() , v.end()
#define pb push_back

#define N 67

typedef vector< int > vi;
typedef long long ll;
typedef unsigned long long ull;

void primefact( int n , vi &p , vi &e ){
	int exp = 0;
	while( n % 2 == 0 ) n /= 2 , exp ++;
	if( exp ) p.pb( 2 ) , e.pb( exp );
	for( int i = 3 ; i * i <= n ; i += 2 )
		if( n % i == 0 ){
			exp = 0;
			while( n % i == 0 ) n /= i , exp ++;
			p.pb( i ) , e.pb( exp ); 
		}
	if( n > 1 ) p.pb( n ) , e.pb( 1 );
}

ull C[ N + 5 ][ N + 5 ];
ull catalan( int n ){ 
	if( n == 0 ) return 1;
	return C[ 2*n ][ n ] - C[ 2*n ][ n - 1 ];
}
int main(){
	REP( i , N + 1 ) C[ i ][ i ] = C[ i ][ 0 ] = 1;
	for( int i = 2 ; i <= N ; ++ i )
		for( int j = 1 ; j < i ; ++j ) C[ i ][ j ] = C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ];
	int n;
	while( scanf( "%d" , &n ) == 1 ){
		vi p , e;
		primefact( n , p , e );
		int ne = e.size() , sum = 0;
		//cout << ne << endl;
		ull ans = 1;
		REP( i , ne ){
			//cout << e[ i ] << "-" << endl;
		 	sum += e[ i ];
			ans *= C[ sum ][ e[ i ] ];
		}
		//cout << ans << " " << catalan( sum - 1 ) << endl;
		ans *= catalan( sum - 1 );
		cout << ans << '\n';
	}
}

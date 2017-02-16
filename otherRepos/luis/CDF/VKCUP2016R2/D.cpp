#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;
typedef vector< ll > vll;

int main(){
	int n , Q;
	while( sc( n ) == 1 ){
		sc( Q );
		vi delta( 2 );
		REP( it , Q ){
			int type;
			sc( type );
			if( type == 1 ){
				int dx ;
				sc( dx );
				dx += n;
				
				REP( k , 2 ) delta[ k ] = (delta[ k ] + dx)%n;
			}else{
				int turn = delta[ 0 ] & 1;
				delta[ turn ] = (delta[ turn ] + 1)%n;
				delta[ turn ^ 1 ] = (delta[ turn ^ 1 ] - 1 + n)%n;
			}
		}
		//cout << turn << endl;
		//REP( i , 2 ) cout << delta[ i ] << endl;
		vi ans( n );
		REP( i , n ) ans[ (i + delta[ (i%2) ])%n ] = i;
		REP( i , n ) printf( "%d%c" , ans[ i ] + 1 , (i + 1 == n ? 10 : 32) );
	}
}



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

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s , t;
	while( cin >> s >> t ){
		vi ind;
		REP( i , SZ( s ) ) if( s[ i ] != t[ i ] ) ind.pb( i );
		
		if( SZ( ind ) & 1 ){
			cout << "impossible\n";
			continue;
		}
		
		string r = s;
		REP( i , SZ( ind ) )
			if( i & 1 ) r[ ind[ i ] ] = s[ ind[ i ] ];
			else r[ ind[ i ] ] = t[ ind[ i ] ];
		cout << r << '\n';
	}
}

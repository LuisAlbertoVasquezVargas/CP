#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vector< tuple< int , int , int > > V;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			V.pb( make_tuple( x + y , x , y ) );
		}
		sort( all( V ) );
		int last = INT_MIN , ans = 0;
		REP( i , n ){
			if( get< 1 >(V[ i ]) - get< 2 >(V[ i ]) < last ) continue;
			ans ++;
			last = get< 1 >(V[ i ]) + get< 2 >(V[ i ]);
		}
		printf( "%d\n" , ans );
	}
}



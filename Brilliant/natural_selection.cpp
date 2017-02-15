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

#define N 100
#define INF 1234567

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

int main(){

	int cnt = 0;
	for( int i = 1 ; i <= 100 ; ++i )
		if( i * i + 100 > 50 * i ) cnt ++;
	ll g = __gcd( cnt , 100 );
	cout << cnt / g << " " << 100 / g << endl;
}

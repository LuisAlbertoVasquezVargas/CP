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

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll comb( ll n ){
	return (n * (n - 1)) / 2LL;
}
int G[ N + 5 ][ N + 5 ];
void solve( int K ){
	int n = 2;
	G[ 0 ][ 1 ] = G[ 1 ][ 0 ] = 1;
	for( int i = 2 ; K ; ++i ){
		int m = n;
		while( K - comb(m) < 0 ) m --;
		K -= comb(m);
		REP( j , m ) G[ i ][ j ] = G[ j ][ i ] = 1;
		n ++;
	}
	printf( "%d\n" , n );
	REP( i , n ){
		REP( j , n ) printf( "%d" , G[ i ][ j ] );
		puts( "" );
	}
}

int main(){
	int K;
	while( cin >> K ) solve( K );
}




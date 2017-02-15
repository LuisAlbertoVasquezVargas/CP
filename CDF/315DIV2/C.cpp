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

#define N 2000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int P[ N + 5 ];
int A[ N + 5 ] , B[ N + 5 ];
int get( int x ){
	int ans = 0;
	while( x ){
		int r = x % 10;
		x /= 10;
		ans = ans * 10 + r;
	}
	return ans;
}
void init(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i*i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i*i ; j <= N ; j += i )
				P[ j ] = i;
	for( int i = 1 ; i <= N ; ++i ){
		A[ i ] = A[ i - 1 ] + (P[ i ] == -1);
		int rev = get( i );
		B[ i ] = B[ i - 1 ] + (rev == i);
	}
}
int main(){
	init();
	ll p , q;
	while( cin >> p >> q ){
		int maxi = 0;
		for( int i = 1 ; i <= N ; ++i )
			if( (ll)A[ i ] * q <= p * (ll)B[ i ] ) maxi = i;
		cout << maxi << '\n';
	}
}

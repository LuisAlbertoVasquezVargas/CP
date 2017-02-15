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

#define N 1000000

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;

struct Point{
	int x , y , id;
	Point(){}
	Point( int x , int y , int id ) : x( x ) , y( y ) , id( id ) {}
};
bool operator < ( const Point &A , const Point &B ){
	if( A.x != B.x ) return A.x < B.x;
	if( A.y != B.y ) return A.y < B.y;
	return A.id < B.id;
}
void impr( vi &vec ){
	for( auto x : vec ) cout << x << " ";
	cout << endl;
}
ll dist( const Point &A , const Point &B ){
	return abs( A.x - B.x ) + abs( A.y - B.y );
}
ll solve( vector< Point > &P , vi &p ){
	for( int i = 0 , r = 0 ; i < SZ(P) ; ++i , r ^= 1 ){
		int ind;
		for( int j = i ; j < SZ(P) ; ++j )
			if( P[ j ].x == P[ i ].x ) ind = j;
			else break;
		if( r ) reverse( P.begin() + i , P.begin() + ind + 1 );
		i = ind;
	}
	ll ans = 0;
	REP( i , SZ( P ) ) p.pb( P[ i ].id );
	REP( i , SZ( P ) - 1 ) ans += dist( P[ i ] , P[ i + 1 ] );
	return ans;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		n = N;
		vector< Point > A , B;
		REP( i , n ){
			int x , y;
			x = rand() % N;
			y = rand() % N;
			//sc( x ) , sc( y );
			A.pb( Point( x , y , i ) );
			B.pb( Point( y , x , i ) );
		}
		sort( all( A ) );
		sort( all( B ) );
		vi pa , pb;
		ll ansA = solve( A , pa );
		ll ansB = solve( B , pb );
		ll ans = min( ansA , ansB );
		DEBUG( ans );
		assert( ans <= 2500000000LL );
	}
}





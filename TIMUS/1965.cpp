#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 1000000
#define INF (1<<20)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

bool isSort( vi &a ){
	REP( i , SZ(a) - 1 )
		if( a[ i ] >= a[ i + 1 ] ) return 0;
	return 1;
}
bool isSorted( vi &a ){
	vi ra = a;
	reverse( all( ra ) ); 
	return isSort( a ) || isSort( ra );
}
void impr( vi &a ){
	REP( i , SZ( a ) ) printf( "%d%c" , a[ i ] , (i + 1 == SZ(a)) ? 10 : 32 );
}
bool particular( vi &a ){
	vi x( 1 , 0 ) , y( 1 , 0 );

	for( auto val : a ){
		if( val > x.back() && val > y.back() ){
			if( x.back() > y.back() ) x.pb( val );
			else y.pb( val );
		}else if( val > x.back() ){
			x.pb( val );
		}else if( val > y.back() ){
			y.pb( val );
		}else{
			return 0;
		}
	}
	x.erase( x.begin() );
	y.erase( y.begin() );
	printf( "%d %d\n" , SZ(x) , SZ(y) );
	impr( x );
	impr( y );
	return 1;
}
// 0 - starting with increasing sequence < < < return max < < < <
// 1 - starting with decreasing sequence > > > return min > > > >
int n;
bool used[ N + 5 ][ 2 ];
int memo[ N + 5 ][ 2 ];
int C[ N + 5 ];
int dp( int pos , int cur ){
	if( pos == n )
		return (cur == 0) ? INF : (-INF);
	if( used[ pos ][ cur ] ) return memo[ pos ][ cur ];
	used[ pos ][ cur ] = 1;
	int &dev = memo[ pos ][ cur ] = ((cur == 0) ? (-INF) : (INF) );
	if( cur == 0 ){
		int x = dp( pos + 1 , 0 );
		if( C[ pos ] < x ) dev = max( dev , C[ pos ] );
		int y = dp( pos + 1 , 1 );
		if( C[ pos ] > y ) dev = max( dev , x );
	}else{
		int x = dp( pos + 1 , 1 );
		if( C[ pos ] > x ) dev = min( dev , C[ pos ] );
		int y = dp( pos + 1 , 0 );
		if( C[ pos ] < y ) dev = min( dev , x );
	}
	return dev;
}
bool general( vi &a ){
	clr( used , 0 );
	REP( i , SZ( a ) ) C[ i ] = a[ i ];
	if( dp( 0 , 0 ) > 0 ){
		test();
		DEBUG( dp(n-1,0) );
		return 1;
	}
	if( dp( 0 , 1 ) <= n ){
		DEBUG( dp(n-1,1) );
		test();
		return 1;
	}	
	return 0;
}
int main(){
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		vi rA = A;
		reverse( all( rA ) );
		if( isSort( A ) || isSort( rA ) ){
			vi a = vi( 1 , A[ 0 ] ) , b = vi( A.begin() + 1 , A.end() );
			printf( "%d %d\n" , SZ(a) , SZ(b) );
			impr( a );
			impr( b );
			continue;
		}
		if( particular( A ) )
			continue;
		if( particular( rA ) )
			continue;
		if( general( A ) )
			continue;
		puts( "Fail" );
	}	
}



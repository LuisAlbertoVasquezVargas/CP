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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		vpii v;
		int S = 0;
		vi a( n ) , b( n );
		REP( i , n ) sc( a[ i ] );
		REP( i , n ) sc( b[ i ] );
		REP( i , n ){
			v.pb( mp( a[ i ] , b[ i ] ) );
			S += b[ i ];
		}
		sort( all( v ) );
		
		int best = INT_MIN;
		priority_queue< int > Q;
		for( int i = 0 ; i < n ; ++i ){
			int m = 0 , cur = 0;
			int ind;
			for( int j = i ; j < n ; ++j )
				if( v[ i ].fi == v[ j ].fi ) ind = j , m ++ , cur += v[ j ].se;
				else break;
			vi vec;
			REP( it , m - 1 ){
				if( !SZ(Q) ) break;
				int val = Q.top();
				Q.pop();
				vec.pb( val );
				cur += val;
			}
			best = max( best , cur );
			for( auto x : vec ) Q.push( x );
			for( int j = i ; j <= ind ; ++j ) Q.push( v[ j ].se );
			i = ind;
		}
		assert( best >= 0 );
		printf( "%d\n" , S - best );
	}
}


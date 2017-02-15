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

#define MAXVAL 200000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct data{
	int x , y , z;
	data( int x , int y , int z ) : x( x ) , y( y ) , z( z ) {}
};
bool operator < ( const data &a , const data &b ){
	return a.x < b.x;
}

int bit[ MAXVAL + 5 ];

void update( int pos , int val ){
	while( pos <= MAXVAL ){
		bit[ pos ] = min( bit[ pos ] , val );
		pos += (pos & -pos); 
	}
}
int query( int pos ){
	int mini = INT_MAX;
	while( pos ){
		mini = min( mini , bit[ pos ] );
		pos -= ( pos & -pos );
	}
	return mini;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vector< data > V;
		REP( i , n ){
			int x , y , z;
			sc( x ) , sc( y ) , sc( z );
			V.pb( data( x , y , z ) );
		}
		sort( all( V ) );
		int ans = 0;
		
		REP( i , MAXVAL + 1 ) bit[ i ] = INT_MAX;
		REP( i , n ){
			int x = V[ i ].y , y = V[ i ].z;
			if( query( y ) > x ) ans ++;
			update( y , x );
		}
		printf( "%d\n" , ans );
	}
}





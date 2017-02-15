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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

void solve( vi &X , vi &Y , int n ){
	int xlo = *min_element( all( X ) );
	int xhi = *max_element( all( X ) );
	int ylo = *min_element( all( Y ) );
	int yhi = *max_element( all( Y ) );
	
	REP( i , n ){
		int x = X[ i ] , y = Y[ i ];
		if( x == xlo && y == ylo ){
			puts( "1" );
			printf( "%d NE\n" , i + 1 );
			return;
		}
	}
	REP( i , n ){
		int x = X[ i ] , y = Y[ i ];
		if( x == xlo && y == yhi ){
			puts( "1" );
			printf( "%d SE\n" , i + 1 );
			return;
		}
	}
	REP( i , n ){
		int x = X[ i ] , y = Y[ i ];
		if( x == xhi && y == ylo ){
			puts( "1" );
			printf( "%d NW\n" , i + 1 );
			return;
		}
	}
	REP( i , n ){
		int x = X[ i ] , y = Y[ i ];
		if( x == xhi && y == yhi ){
			puts( "1" );
			printf( "%d SW\n" , i + 1 );
			return;
		}
	}
	
	int a , b;
	REP( i , n ){
		int x = X[ i ];
		if( x == xlo ) a = i;
		if( x == xhi ) b = i;
	}
	puts( "2" );
	if( Y[ a ] < Y[ b ] ){ 
		printf( "%d NE\n" , a + 1 );
		printf( "%d SW\n" , b + 1 );
	}else{
		printf( "%d SE\n" , a + 1 );
		printf( "%d NW\n" , b + 1 );
	}
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi X , Y;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			X.pb( x ) , Y.pb( y );
		}	
		solve( X , Y , n );		
	}
}



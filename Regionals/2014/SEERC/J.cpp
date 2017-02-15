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
 
#define N 30000
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
const int B = 32;
bitset< N + 5 > T[ N + 5 ];
int n;

void upd( int x , int pos ){
	while( pos <= n + 1 ){
		T[ x ].flip( pos );
		pos += (pos & -pos); 
	}
}
void update( int x , int pos ){
	upd( x , pos + 1 );
}
bool qry( int x , int pos ){
	bool sum = 0;
	while( pos ){
		sum ^= T[ x ][ pos ];
		pos -= ( pos & -pos );
	}
	return sum;
}
bool query( int x , int pos ){
	return qry( x , pos + 1 );
}
void update( int x , int ylo , int yhi ){
	if( ylo >= n ) return;
	ylo = max( ylo , 0 );
	yhi = min( yhi , n - 1 );
	if( ylo > yhi ) return;
	update( x , yhi + 1 );
	update( x , ylo );
}
int main(){
	//return 0;
	while( sc( n ) == 1 ){
		REP( i , n ) T[ i ].reset();
		int Q;
		sc( Q );
		REP( it , Q ){
			int x , y , p , ori;
			sc( x ) , sc( y ) , sc( p ) , sc( ori );
			//DEBUG2( x , y );
			//3 (0:SW, 1:SE, 2:NE, 3:NW).
			if( ori == 0 ){
				//***
				///**
				////*
				REP( i , p )
					if( x + i < n ) update( x + i , y - (p - 1) + i , y );
					else break;
			}else if( ori == 1 ){
				//***
				//**
				//*
				REP( i , p )
					if( x + i < n ) update( x + i , y , y + (p - 1) - i );
					else break;
			}else if( ori == 2 ){
				//*
				//**
				//***
				REP( i , p )
					if( x - i >= 0 ) update( x - i , y , y + (p - 1) - i );
					else break;
			}else{
				////*
				///**
				//***
				REP( i , p ) 
					if( x - i >= 0 ) update( x - i , y - (p - 1) + i , y );
					else break;
			}
			/*
			REP( i , n ) {
				REP( j , 10 ){
					bool ok = T[ i ][ 0 ] & (1LL << j );
					cout << ok ;
				}
				cout << endl;
			}
			*/
		}
		
		int ans = 0;
		REP( i , n ) REP( j , n ) ans += query( i , j );
		printf( "%d\n" , ans );
	}
}




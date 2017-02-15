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
const int B = 64;
ll T[ N + 1 ][ 500 ];
int n;
void update( int x , int ylo , int yhi ){
	if( ylo >= n ) return;
	ylo = max( ylo , 0 );
	yhi = min( yhi , n - 1 );
	if( ylo > yhi ) return;
	//DEBUG( x );
	//DEBUG2( ylo , yhi );
	for( int y = ylo ; y <= yhi ; ){
		int z = y / B;
		if( (y & (63)) == 0 ){
			if( y + B - 1 <= yhi ){
				T[ x ][ z ] ^= (-1LL);
			}else{
				for( int y2 = y ; y2 <= yhi ; ++y2 ){
					ll cur = (1LL << (y2 & 63) );
					T[ x ][ z ] ^= cur;
				}
			}
			y += B;
		}else{
			int maxi = -1;
			for( int y2 = y ; y2 <= yhi ; ++y2 ){
				if( (y2 & 63) == 0 )
					break;
				maxi = y2;
				ll cur = (1LL << (y2 & 63));
				T[ x ][ z ] ^= cur;
			}
			y = maxi + 1;
			continue;
		}
	}
}
unsigned int popcount64(unsigned long long x)
{
    x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FULL);
    return (x * 0x0101010101010101ULL) >> 56;
}
int main(){
	
	while( sc( n ) == 1 ){
		REP( i , n ) clr( T[ i ] , 0 );
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
					bool ok = T[ i ][ 0 ] & (1 << j);
					cout << ok ;
				}
				cout << endl;
			}
			*/
		}
		
		int ans = 0;
		REP( i , n ) REP( j , n/B + 2 ) ans += popcount64( T[ i ][ j ] );
		printf( "%d\n" , ans );
	}
}




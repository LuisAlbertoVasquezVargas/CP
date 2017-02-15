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

#define MAXVAL 1024

typedef long long ll;

int T[ MAXVAL + 1 ][ MAXVAL + 1 ];


int read( int posx , int posy ){
   int sum = 0;
   while( posx ){
      int y = posy;
      while( y ){
         sum += T[ posx ][ y ];
         y -= (y & -y);
      }
      posx -= (posx & -posx);
   }
   return sum;   
}
void update( int posx , int posy , int val ){
   while( posx <= MAXVAL ){
      int y = posy;
      while( y <= MAXVAL ){
         T[ posx ][ y ] += val;
         y += (y & -y);   
      }
      posx += (posx & -posx);
   }
}
int v[ MAXVAL + 1 ][ MAXVAL + 1 ];
char opc[ 100 ];
int main(){
	int cases ;
	sc( cases );
	REP( tc , cases ){
		int n;
      	sc( n );
		clr( T , 0 ) , clr( v , 0 );
      	while( 1 ){
        	scanf( "%s" , opc );
         	if( opc[ 1 ] == 'E' ){
         		int x , y , val;
				sc( x ) , sc( y ) , sc( val );
            	x++ , y++;
            	update( x , y , val - v[ x ][ y ] );   
            	v[ x ][ y ] = val;
         	}else if( opc[ 1 ] == 'U' ){
            	int a , b , x , y;
            	sc( a ) , sc( b ) , sc( x ) , sc( y );
            	a++ , b++ , x++ , y++;
            	printf( "%d\n" , read( x , y ) - read( x , b - 1 ) - read( a - 1 , y ) + read( a - 1 , b - 1 ) );
         	}
         	else break;
		}
	}
}




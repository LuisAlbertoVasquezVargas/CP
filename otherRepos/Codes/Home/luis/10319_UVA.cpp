#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) ) 

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define fi first
#define se second
#define mp make_pair

#define N 200

typedef long long ll;
typedef vector< int > vi;

int n , timer , top;
vi G[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , inpila[ N + 5 ] , comp[ N + 5 ];

int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	REP( i , SZ( G[ u ] ) ){
		int v = G[ u ][ i ];
		if( dfsn[ v ] == 0 ) low = min( low , dfs( v ) );
		else if( inpila[ v ] ) low = min( low , dfsn[ v ] );
	}
	if( low == dfsn[ u ] ){
		int fin;
		do
		{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}

void SCC(){
	clr( dfsn , 0 );
	timer = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
void add( int u , int v ){
	//u ^= 1 , v ^= 1;
	G[ v ^ 1 ].pb( u );
	G[ u ^ 1 ].pb( v );
}
void f( int x , int y , int a , int b ){
	add( x , a );
	add( b , x );
	add( a , y );
	add( y , b );
}
bool solve(){
	REP( i , n/2 ) if( comp[ 2 * i ] == comp[ 2 * i + 1 ] ) return 0;
	return 1;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		REP( i , N ) G[ i ].clear();
		int R , C , m;
		sc( R ) , sc( C ) , sc( m );
		n = R + C;
		n *= 2;
		REP( it , m ){
			int x1 , y1 , x2 , y2;
			sc( x1 ) , sc( y1 ) , sc( x2 ) , sc( y2 );
			x1 -- , y1 -- , x2 -- , y2 --;
			if( x1 == x2 && y1 == y2 ) continue;
			if( x1 == x2 ){
				if( y1 < y2 ) add( 2 * x1 , 2 * x1 );
				else add( 2 * x1 + 1 , 2 * x1 + 1 );
			}else if( y1 == y2 ){
				if( x1 < x2 ) add( 2 * ( R + y1 ) , 2 * ( R + y1 ) );
				else add( 2 * ( R + y1 ) + 1 , 2 * ( R + y1 ) + 1 );
			}else{
				if( x1 < x2 ){
					if( y1 < y2 ){
						f( 2 * x1 , 2 * (R + y2) , 2 * x2 , 2 * (R + y1) );
						//add( 2 * x1 , 2 * (R + y2) );
						//add( 2 * x2 , 2 * (R + y1) );
					}else{
						f( 2 * x1 + 1 , 2 * (R + y2) , 2 * x2 + 1 , 2 * (R + y1) );
						//add( 2 * x1 + 1 , 2 * (R + y2) );
						//add( 2 * x2 + 1 , 2 * (R + y1) );
					}
				}else{
					if( y1 < y2 ){
						f( 2 * x1 , 2 * (R + y2) + 1 , 2 * x2 , 2 * (R + y1) + 1 );
						//add( 2 * x1 , 2 * (R + y2) + 1 );
						//add( 2 * x2 , 2 * (R + y1) + 1 );
					}else{
						f( 2 * x1 + 1 , 2 * (R + y2) + 1 , 2 * x2 + 1 , 2 * (R + y1) + 1 );
						//add( 2 * x1 + 1 , 2 * (R + y2) + 1 );
						//add( 2 * x2 + 1 , 2 * (R + y1) + 1 );
					}					
				}
			}
		}
		SCC();
		puts( solve() ? "Yes" : "No" );
	}
}



#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it ++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 20000

typedef vector< int > vi;

int n;
vi E[ N + 5 ];
int dfsn[ N + 5 ] , pila[ N + 5 ] , comp[ N + 5 ];
bool inpila[ N + 5 ];
int timer , top = 0;
int ncomp;
int dfs( int u ){
	int low = dfsn[ u ] = ++timer;
	inpila[ pila[ top ++ ] = u ] = 1;
	FOR( v , E[ u ] )
		if( !dfsn[ *v ] ) low = min( low , dfs( *v ) );
		else if( inpila[ *v ] ) low = min( low , dfsn[ *v ] );
	if( low == dfsn[ u ] ){
		ncomp ++;
		int fin;
		do{
			fin = pila[ --top ];
			inpila[ fin ] = 0;
			comp[ fin ] = u;
		}while( fin != u );
	}
	return low;
}
void SCC(){
	clr( dfsn , 0 );
	clr( inpila , 0 );
	timer = 0;
	ncomp = 0;
	REP( i , n ) if( !dfsn[ i ] ) dfs( i );
}
//vi dag[ N + 5 ];
int ind[ N + 5 ] , out[ N + 5 ]; 
int main(){
	int cases , m , u , v;
	sc( cases );
	while( cases -- ){
		sc( n ) , sc( m );
		REP( i , n ) E[ i ].clear();
		//REP( i , n ) dag[ i ].clear();
		clr( ind , 0 ) , clr( out , 0 );
		REP( i , m ){
			sc( u ) , sc( v );
			u -- , v --;
			E[ u ].pb( v );
		}
		SCC();
		if( ncomp == 1 ){
			puts( "0" );
			continue;
		}
		REP( u , n ) FOR( v , E[ u ] )
			if( comp[ u ] != comp[ *v ] ) ind[ comp[ *v ] ]++ , out[ comp[ u ] ]++;
		int S = 0 , T = 0;
		//cout << "ncomp : " << ncomp << endl;
		REP( i , n ) if( i == comp[ i ] && out[ i ] == 0 ) T ++;
		REP( i , n ) if( i == comp[ i ] && ind[ i ] == 0 ) S ++;
		printf( "%d\n" , max( S , T ) );
	}
}

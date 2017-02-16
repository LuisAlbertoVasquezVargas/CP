#include<bits/stdc++.h>
#define INF 100000000000
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 2000000

typedef long long ll;
typedef vector< ll > vll;

int n;
int id[ N + 5 ] , last[ N + 5 ];
char op[ 5 ];

int Find( int x ){ return id[ x ] = ( x == id[ x ] ? x : Find( id[ x ] ) ); }
int main(){
	int u , v;
	while( sc( n ) == 1 ){
		REP( i , N ) id[ i ] = last[ i ] = i; 
		int F = 0 , T = 0;
		while( scanf( "%s" , op ) == 1 ){
			if( op[ 0 ] == 'e' ) break;
			if( op[ 0 ] == 'c' ){
				sc( u ) , sc( v );
				u-- , v--;
				u = last[ u ] , v = last[ v ];				
				u = Find( u ) , v = Find( v );
				if( u != v ) id[ u ] = v;
				continue;
			}
			if( op[ 0 ] == 'd' ){
				sc( u );
				u-- ;
				last[ u ] = n++;		
				continue;
			}
			if( op[ 0 ] == 'q' ){
				sc( u ) , sc( v );
				u-- , v--;
				u = last[ u ] , v = last[ v ];
				if( Find( u ) == Find( v ) ) T++;
				else F++;
				continue;
			}
		}
		printf( "%d , %d\n" , T , F );
	}
}

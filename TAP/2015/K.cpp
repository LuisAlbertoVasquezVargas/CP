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
typedef vector< int > vi;

#define N 100000
#define M 1000000
#define NEUTRAL (-1)
#define v1 ( ( node << 1 ) + 1 )
#define v2 ( v1 + 1 )
#define med ( (a + b) >> 1 )
#define LEFT v1 , a , med
#define RIGHT v2 , med + 1 , b
 
int A[ N + 5 ] , F[ N + 5 ] ;
int T[ 4 * N ];

void build_tree( int node , int a , int b ){
    if( a == b ){
        T[ node ] = F[ a ];
        return;
    }
    build_tree( LEFT );
	build_tree( RIGHT );
    T[ node ] = max( T[ v1 ] , T[ v2 ] );
}
void update( int node , int a , int b , int x , int val ){
    if( x > b || a > x ) return;
    if( a == b ){
        T[ node ] = val;
        return;
    }
    update( LEFT , x , val );
	update( RIGHT , x , val );
    T[ node ] = max( T[ v1 ] , T[ v2 ] );
}
int query( int node , int a ,  int b , int lo , int hi ){
    if( lo > b || a > hi ) return NEUTRAL;
    if( a >= lo && hi >= b ) return T[ node ];
    return max( query( LEFT , lo , hi ) , query( RIGHT , lo , hi ) ); 
}
set< int > SET[ M + 5 ]; 
char op[ 5 ];
int n;
bool f( int a , int b ){
	if( a == -1 ) return 1;
	return query( 0 , 0 , n - 1 , a , b ) >= a ;
}
int query( int pos ){
	int lo = -1 , hi = pos;
	while( hi - lo > 1 ){
		int mid = (lo + hi) >> 1;
		if( f( mid , pos ) ) lo = mid;
		else hi = mid;
	}
	return hi;
}
int getPrev( int pos ){
	set< int > :: iterator it = SET[ A[ pos ] ].lower_bound( pos );
	if( it == SET[ A[ pos ] ].begin() ) return -1;
	it --;
	return *it;
}
int getNext( int pos ){
	set< int > :: iterator it = SET[ A[ pos ] ].lower_bound( pos );
	it ++;
	if( it == SET[ A[ pos ] ].end() ) return n;
	return *it;
}
int main(){
	int m ;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , n ) sc( A[ i ] );
		REP( i , M + 1 ) SET[ i ].clear();
		
		REP( i , n ) SET[ A[ i ] ].insert( i );
		REP( i , n ) F[ i ] = getPrev( i );
		build_tree( 0 , 0 , n - 1 );
		REP( i , m ){
			scanf( "%s" , op );
			if( op[ 0 ] == 'C' ){
				int pos , val;
				sc( pos ) , sc( val );
				pos --;
				if( val == A[ pos ] ) continue;
				
				int u = getPrev( pos ) , v = getNext( pos );
				set< int > :: iterator it = SET[ A[ pos ] ].lower_bound( pos );
				SET[ A[ pos ] ].erase( it );
				if( v < n ) {
					F[ v ] = u;
					update( 0 , 0 , n - 1 , v , F[ v ] );
				}
				
				A[ pos ] = val;
				SET[ A[ pos ] ].insert( pos );
				u = getPrev( pos ) , v = getNext( pos );
				F[ pos ] = u;
				update( 0 , 0 , n - 1 , pos , F[ pos ] );
				
				if( v < n ) {
					F[ v ] = pos;
					update( 0 , 0 , n - 1 , v , F[ v ] );
				}
				
			}else{
				int pos;
				sc( pos );
				pos --;
				/*
				for( int k = 0 ; k <= pos ; ++k ) cout << f( k , pos ) << " ";
				cout << endl;
				*/
				int pos2 = query( pos );
				printf( "%d\n" , pos - pos2 + 1 );
			}
		}
	}
}



#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back

#define N 305

typedef vector< int > vi;
struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ) : x( x ) , y( y ) {}
	int dist2(){ return x*x + y*y;}
};
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y );}
int cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x;}
int area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A );}
int dist2( const Point &A , const Point &B ){ return ( B - A ).dist2() ;}

vi E[ N ];
int match[ N ] , vis[ N ];
int n1;
bool dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	FOR( v , E[ u ] )
		if( match[ *v ] == -1 || dfs( match[ *v ] ) )
		{
			match[ *v ] = u;
			return 1;
		}
	return 0;
}
int bpm(){ 
	clr( match , -1 ); int ans = 0;
	REP( i , n1 ) clr( vis , 0 ) , ans += dfs( i );
	return ans;
}


int X[ N ] , Y[ N ] , P[ N ];

int main()
{
	int n , a , b , R , x , y , p , tc = 0 , n2;
	while( sc( n ) == 1 )
	{
		if( n == 0 ) break;
		REP( i , n ) {
			sc( x ) , sc( y ) , sc( p );
			X[ i ] = x , Y[ i ] = y , P[ i ] = p;
		}
		sc( a ) , sc( b ) , sc( R );
		a -- , b--;
		Point A = Point( X[ a ] , Y[ a ] ) , B = Point( X[ b ] , Y[ b ] );
		vi ind1 , ind2;
		REP( i , n ){
			if( i == a || i == b )continue;
			if( P[ i ] == 0 ) continue;
			int S = area( A , B , Point( X[ i ] , Y[ i ]  ) );
			if( S > 0 ) ind1.pb( i );
			else if( S < 0 ) ind2.pb( i );
		}
		if( ind1.size() > ind2.size() ) swap( ind1 , ind2 );
		n1 = ind1.size() , n2 = ind2.size();
		REP( i , n1 ) E[ i ].clear();
		REP( i , n1 ){
			Point P1( X[ ind1[ i ] ] , Y[ ind1[ i ] ] );
			REP( j , n2 ){
				Point P2( X[ ind2[ j ] ] , Y[ ind2[ j ] ] );
				if( dist2( P1 , P2 ) <= R*R && P[ ind1[ i ] ] > P[ ind2[ j ] ]){
					E[ i ].pb( j );
					//cout << "inserting edge " << i << " " << j  << endl;
				}
			}
		}
		printf( "Case %d: %d\n" , ++tc , bpm() );
	}
}
